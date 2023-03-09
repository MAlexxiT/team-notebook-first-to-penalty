#define GS 50
vector<int> graph[GS];
bitset<GS> vis, isArtic;
vector<int> padre;
//id por tiempo, menor id accesible
//ya sea por descendientes o por back edges
vector<int> tId,lId;
//cantidad de hijos que tiene en el bfs spanning tree
int rootChildren;
int cnt;
int dfsRoot;
void findAP_B(int p){
    cnt++;vis[p] = 1;tId[p] = cnt;lId[p] = tId[p];

    for(int hijo: graph[p]){
        if(!vis[hijo]){
            padre[hijo] = p;
            if(p == dfsRoot) rootChildren++;

            findAP_B(hijo);

            //esto significa que ni por un back edge el hijo accede al padre
            //por lo que si el padre fuese eliminado el hijo quedaria aislado
            if(lId[hijo] >= tId[p]) isArtic[p] = 1;
            if(lId[hijo] > tId[p]){
                //esto significa que si se eliminase el camino de padre->hijo 
                //se lograria desconectar el grafo, aka bridge
            }
            lId[p] = min(lId[p],lId[hijo]);
        }else{
            //si hay un ciclo indirecto, actualiza el valor para el padre
            if(hijo != padre[p]) lId[p] = min(lId[p],tId[hijo]);
        }
    }
}
//OJO esto solo jala con Undirected graphs
/*
    MAIN
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            rootChildren = 0;
            dfsRoot = i;
            findAP_B(i);
            //el algoritmo no puede detectar si el nodo que lo origino
            //es un articulation point, por lo que queda checar si
            //en el spanning tree que genero tiene mas de un solo hijo
            isArtic[i] = (rootChildren>1?1:0);
        }
    }
*/
