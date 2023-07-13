//se asume que la longitud de la cadena sera menor a 10**6, modificar el ub a discrecion
#define ub 1000000LL
//pot de ub times two
#define ccd 12

//metodos y structs auxiliares para el suffix array
struct sufd{int id;long long int t;
    bool operator<(const sufd b) const{return t<b.t;}
};
int getndigit(long long int num, int d){
    while(d--) num/=10LL;
    return (int) (num%10LL);
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
    for(int i= 0; i<n; i++){
        if(rank[i]==0) continue;
        for(int j = max(curr-1,0); j+max(i,sa[rank[i]-1])<n; j++){
            if(T[i+j] == T[sa[rank[i]-1]+j]) curr = j;
            if(T[i+j]!=T[sa[rank[i]-1]+j]){curr = j-1; break;}
        }
        curr++;lce[i] = curr; 
    }
    
    int p = 1; while(p<=n) p*=2; stsize = 2*p-1;
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
int getlce(int l, int r){
    if(l>r) return 0;
    return recque(l,r,0,0,stsize/2);
}
int buscarRec(int l, int r,int lcp,int eas){
    int m = (l+r)/2;
    //string curr = T.substr(sa[m],T.size()-sa[m]);
    int lce = (eas>m?getlce(m+1,eas):getlce(eas+1,m));
    if(r-l<=1){
        lce = (eas>l?getlce(l+1,eas):getlce(eas+1,l));
        bool f = (lce==lcp);
        for(int i = lcp,n= T.size(); f && sa[l]+i<n && i<P.size(); i++){
            if(P[i]!=T[sa[l]+i]) f = false;
        }
        
        if(f) return l;
        lce = (eas>r?getlce(r+1,eas):getlce(eas+1,r));
        f = (lce==lcp);
        for(int i = lcp,n= T.size(); f && sa[r]+i<n && i<P.size(); i++){
            if(P[i]!=T[sa[r]+i]) f = false;
        }
        if(f) return r;
        return -1;
    }
    
    if(lce>lcp){
        if(eas<m) return buscarRec(m+1,r,lcp,eas);
        if(eas>m) return buscarRec(l,m-1,lcp,eas);
    }
    if(lce<lcp){
        if(eas>m) return buscarRec(m+1,r,lcp,eas);
        if(eas<m) return buscarRec(l,m-1,lcp,eas);
    }

    for(int i = lcp,n = T.size(); sa[m]+i<n && i<P.size(); i++){if(P[i]!=T[sa[m]+i]) break; lcp++;}
    if(lcp == P.size()) return m;
    if(l==r) return -1;
    return (P[lcp]>T[sa[m]+lcp]?buscarRec(m+1,r,lcp,m):buscarRec(l,m-1,lcp,m));
}
int buscar(){
    int n = T.size();
    if(P.size()>n) return -1;
    return buscarRec(1,n-1,0,0);
}
//CODIGO DE 100 LINEAS, TE HE FALLADO MarcosK
//Uso: lee T, agregar signo dolar, llama makesa(); makelce(); lee P para despues buscar()
//delete[] sa; delete[] lcest; cuando leas de nuevo T
//O(|T| log(|T|)) preprocesamiento, O(|P|+log**2(|T|)) cada busqueda
//Buscar devuelve un indice cualquiera de sa tal que el sufijo denotado tenga P como prefijo 
//Se puede hacer mas corto?