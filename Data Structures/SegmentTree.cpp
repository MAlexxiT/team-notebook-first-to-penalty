//MAXN = 2^k, n = tam arreglo inicial
#define MAXN 262160
int stsize; long long int neut;int n;
long long int* st = new long long int[2*MAXN-1]();
long long int fst(long long int a, long long int b);
long long int build(int sti,int csize){
    if(csize == 1) return st[sti]; 
    return st[sti] = fst(build(sti*2+1,csize/2),build(sti*2+2,csize/2));
}
void innit(){
    for(int i = 0; i<stsize; i++) st[i] = neut;
    /*int d = 0;
    for(int i = stsize-n; i<stsize && d<n; i++){
        st[i] = arr[d];d++;
    }*/
    build(0,n);
}
void upd(int ind, long long int val){
    ind = stsize-n+ind;
    st[ind] = val;ind--;ind/=2;
    while(true){
        st[ind] = fst(st[ind*2+1],st[ind*2+2]);        
        ind--;
        if(ind<0) break;
        ind/=2;
    }
}
long long int rqu(int l, int r,int sti, int ls, int rs){
    if(l<=ls && rs<= r) return st[sti];
    if(r<ls || l>rs) return neut;
    int m = (rs+ls)/2;
    return fst(rqu(l,r,sti*2+1,ls,m),rqu(l,r,sti*2+2,m+1,rs));
}
long long int query(int l, int r){
    return rqu(l,r,0,0,n-1);
}
//uso, inicializa neut, n = primera potencia de 2 >= n del problema, stsize = 2*n-1
//llena arr de neutros hasta que su tam sea el nuevo n
//DEFINE LA FUNCION fst