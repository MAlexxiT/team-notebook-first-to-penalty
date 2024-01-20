//https://judge.yosupo.jp/problem/lca
#define GS 500000
//>log2(GS)
#define MAXANC 19
vector<int> graph[GS];
//NODO, 2**i ancestro
int ancestro[GS][MAXANC];
int dist[GS];
//preprocesamiento, asume que graph es direccionado y rooteado
//agregar un bitset vis en caso de que falte
void buildAncestry(int curr,int h){
    dist[curr] = h;
    int ub = 31-__builtin_clz(h|0);
    if(h==0) ub = 0; 
    for(int i = 1; i<=ub; i++) 
        ancestro[curr][i] = ancestro[ancestro[curr][i-1]][i-1];
    
    for(int hijo: graph[curr]){
        ancestro[hijo][0] = curr; 
        buildAncestry(hijo,h+1);
    } 
}   

int kthAncestor(int curr, int k){
    if(k==0) return curr;
    int ub = 31-__builtin_clz(k);
    if(ancestro[curr][ub] == -1) return -1;
    return kthAncestor(ancestro[curr][ub],((1<<ub)^k));
}

int lca(int a,int b){
    int d = min(dist[a],dist[b]);
    a = kthAncestor(a,dist[a]-d);
    b = kthAncestor(b,dist[b]-d);
    //encuentra el primer true
    int l = 0,r = d,m;
    while(l<r){
        m = l+r; m/=2;
        if(kthAncestor(a,m) == kthAncestor(b,m)) r = m;
        else l = m+1;
    }
    return kthAncestor(a,l); 
}