//se asume que la longitud de la cadena sera menor a 10**6, modificar el ub a discrecion
#define ub 1000000LL
//pot de ub times two
#define ccd 12

//metodos y structs auxiliares para el suffix array
int techo(int n, int d){return (n+d-1)/d;}
struct sufd{int id;long long int t;};
int getndigit(long long int num, int d){
    long long int p = 1;while(d--) p*=10LL;
    num/=p;
    return (int) num%10LL;
}
void radixSort(vector<sufd>& arr){
    int count[10]; int n = arr.size();
    vector<sufd> aux(n);
    for(int d = 0; d<ccd; d++){
        for(int i = 0; i<10; i++) count[i] = 0;
        for(int i = 0; i<n; i++) count[getndigit(arr[i].t,d)]++;
        for(int i = 1; i<10; i++) count[i]+=count[i-1];
        for(int i = n-1; i>=0; i--){
            count[getndigit(arr[i].t,d)]--;
            aux[count[getndigit(arr[i].t,d)]] = arr[i];
        }
        for(int i = 0; i<n; i++) arr[i] = aux[i];
    }
}
//El suffix array mismo, agregar caracter menor al alfabeto al final de T
string T,P;
int* sa,*lcest;
int stsize;
void makesa(){
    int n = T.size();
    sa = new int[n+1](); int* ra = new int[2*n+2]();
    for(int i = 0; i<n; i++){sa[i] = i; ra[i] = T[i];}

    sufd aux;vector<sufd> arr(n); 
    for(int k = 1; k<n;k*=2){
        arr.clear();
        for(int i = 0; i<n; i++){
            aux.id = sa[i]; aux.t = ra[sa[i]];aux.t*=ub;aux.t += ra[sa[i]+k];
            arr.push_back(aux);
        }
        //en caso de TLE calar con STL sort
        radixSort(arr);
        sa[0] = arr[0].id; ra[sa[0]] = 0;
        for(int i = 1; i<n; i++){
            sa[i] = arr[i].id; 
            ra[sa[i]] = ra[sa[i-1]]+1;
            if(arr[i].t == arr[i-1].t) ra[sa[i]]--;
        }
        if(ra[sa[n-1]]==n-1) break;
    }
    delete[]ra;    
}
void makelce(){
    int n = T.size();
    int* lce = new int[n+2]();
    int* rank = new int[n+2]();
    for(int i = 0; i<n; i++) rank[sa[i]] = i;

    int curr = 0;
    for(int i= 0; i<n-1; i++){
        for(int j = max(curr-1,0); j+max(i,sa[rank[i]-1])<n; j++){
            if(T[i+j] == T[sa[rank[i]-1]+j]) curr = j;
            if(T[i+j]!=T[sa[rank[i]-1]+j]){curr = j-1; break;}
        }
        curr++;lce[i] = curr; 
    }
    
    int p = 1; while(p<n) p*=2; stsize = 2*p-1;
    lcest = new int[stsize+2]();
    for(int i= p-1; i-(p-1)<n; i++) lcest[i] = lce[sa[i-(p-1)]];
    for(int i = p-2; i>=0; i--) lcest[i] = min(lcest[2*i+1],lcest[2*i + 2]);
    delete[] lce; delete[] rank;  
}
int recque(int l, int r, int sti, int stil, int stir){
    if(stir<l || stil>r) return ub;
    if(l<=stil && stir<=r) return lcest[sti];
    int stim = stil+stir; stim/=2;
    return min(recque(l,r,sti*2+1,stil,stim),recque(l,r,sti*2+2,stim+1,stir));
}
int getlce(int l, int r){return recque(l,r,0,0,stsize/2);}
int sfor(int l, int r, int lcpl, int lcpr){
    int lcpm = min(lcpl,lcpr); int m = (l+r)/2; int n = T.size();
    int lce =  getlce(m,r);
    if(l>r) return -1;
    if(lcpm>lce && l!=r && (T[sa[m]+lcpm]!=P[lcpm])) return sfor(m+1,r,lcpm,lcpr);
    if(lcpm<lce && l!=r && (T[sa[m]+lcpm]!=P[lcpm])) return sfor(l,m,lcpl,lcpm);
    for(int i = lcpm; sa[m]+i<n && i<P.size();  i++){lcpm = i;if(T[sa[m]+i]!=P[i]) break;}
    if(l==r && lcpm+1 != P.size()) return -1;
    if(l==r && lcpm+1 == P.size()) return l;
    if(lcpm == P.size()) return sfor(l,m,lcpl,lcpm);
    if(lcpm+sa[m] == n) return sfor(m+1,r,lcpm,lcpr);
    return (T[lcpm+sa[m]]<P[lcpm]? sfor(m+1,r,lcpm,lcpr):sfor(l,m,lcpl,lcpm));
}
int searchfo(){
    int r = 0;
    for(int i = 0; i<P.size() && i+sa[T.size()-1]<T.size(); i++){
        if(T[i+sa[T.size()-1]] != P[i]) break;
        r++;
    }
    return sfor(0,T.size()-1,0,r);
}
int slor(int l, int r, int lcpl, int lcpr){
    int lcpm = min(lcpl,lcpr); int m = techo(l+r,2); int n = T.size();
    int lce =  getlce(m,r);
    if(l==r) return l;
    if(l>r) return -1;
    if(lcpm>lce && l!=r && (T[sa[m]+lcpm]!=P[lcpm])) return slor(m,r,lcpm,lcpr);
    if(lcpm<lce && l!=r && (T[sa[m]+lcpm]!=P[lcpm])) return slor(l,m,lcpl,lcpm);
    for(int i = lcpm; sa[m]+i<n && i<P.size();  i++){lcpm = i;if(T[sa[m]+i]!=P[i]) break;}
    if(l==r && lcpm+1 != P.size()) return -1;
    if(l==r && lcpm+1 == P.size()) return l;
    if(lcpm == P.size() || lcpm+sa[m] == n) return slor(m,r,lcpm,lcpr);
    
    return (T[lcpm+sa[m]]<=P[lcpm]? slor(m,r,lcpm,lcpr):slor(l,m-1,lcpl,lcpm));
}
int searchlo(){
    int r = 0;
    for(int i = 0; i<P.size() && i+sa[T.size()-1]<T.size(); i++){
        if(T[i+sa[T.size()-1]] != P[i]) break;
        r++;
    }
    return slor(0,T.size()-1,0,r);
}
//CODIGO DE 130 LINEAS, TE HE FALLADO MarcosK
//Uso: lee T, agregar signo dolar, llama makesa(); makelce(); lee P search last/first ocurr
//delete[] sa; delete[] lcest; cuando leas de nuevo T
//O(|T|) preprocesamiento, O(|P|+log**2(|T|)) cada busqueda
