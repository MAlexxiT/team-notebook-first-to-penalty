#define GS 100
//>log2(GS)
#define MAXANC 8
vector<int> graph[GS];
//NODO, 2**i ancestro
//inicializar todo en -1
int ancestro[GS][MAXANC];

//preprocesamiento, asume que graph es direccionado y rooteado
//agregar un bitset vis en caso de que falte
void buildAncestry(int curr,int h){
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