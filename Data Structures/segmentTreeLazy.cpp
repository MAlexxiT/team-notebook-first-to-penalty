//MAXN = 2^k, n = tam arreglo inicial
#define MAXN 262160
vector<int> arr;
int stsize; long long int neut;int n;
long long int* st = new long long int[2*MAXN-1]();
long long int* pendientes = new long long int[2*MAXN-1]();
long long int fst(long long int a, long long int b){return a+b;}
long long int build(int sti,int csize){
    if(csize == 1) return st[sti]; 
    return st[sti] = fst(build(sti*2+1,csize/2),build(sti*2+2,csize/2));
}
bool hasChildren(int sti){sti*=2;sti++;sti++;return sti<stsize;}
void innit(){
    for(int i = 0; i<stsize; i++) st[i] = neut;
    int d = 0;
    for(int i = stsize-n; i<stsize && d<n; i++) {st[i] = arr[d];d++;}
    build(0,n);
}
void updrec(int l,int r, int sl, int sr,int sti, long long int val){
    if(sr<l || r< sl) return;
    if(l<= sl && sr <=r){
        st[sti] += val*(sr-sl+1);
        if(hasChildren(sti)){pendientes[sti*2+1]+=val;pendientes[sti*2+2]+=val;}
        return;
    }

    int sm = (sl+sr)/2;
    updrec(l,r,sl,sm,sti*2+1,val);
    updrec(l,r,sm+1,sr,sti*2+2,val);
    st[sti] = fst(st[sti*2+1]+pendientes[sti*2+1],st[sti*2+2]+pendientes[sti*2+2]);  
}
void upd(int l, int r, long long int val){updrec(l,r,0,n-1,0,val);}

long long int rqu(int l, int r,int sti, int ls, int rs){
    if(r<ls || l>rs) return neut;
    if(l<=ls && rs<= r){
        return st[sti]+pendientes[sti]*(rs-ls+1);
    } 
    
    st[sti] += pendientes[sti]*(rs-ls+1);
    if(hasChildren(sti)){pendientes[sti*2+1]+=pendientes[sti];pendientes[sti*2+2]+=pendientes[sti];}
    pendientes[sti] = 0;
    
    int m = (rs+ls)/2;
    return fst(rqu(l,r,sti*2+1,ls,m),rqu(l,r,sti*2+2,m+1,rs));
}
long long int query(int l, int r){
    return rqu(l,r,0,0,n-1);
}
//uso, inicializa neut, n = primera potencia de 2 >= n del problema, stsize = 2*n-1
//llena arr de neutros hasta que su tam sea el nuevo n
//DEFINE LA FUNCION fst