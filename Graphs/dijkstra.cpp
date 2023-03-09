#define GS 1000
#define INF 100000000
//destino, costo
vector<pair<int,int>> graph[GS];
int dist[GS];
void dijkstra(int origen,int tam){
    for(int i = 0; i<=tam; i++){
        dist[i] = INF;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pair<int,int> curr;

    pq.push(make_pair(0,origen));

    while(pq.size()){
        curr = pq.top();pq.pop();
        if(curr.first >= dist[curr.second]) continue;

        dist[curr.second] = curr.first;
        for(pair<int,int> h: graph[curr.second]){
            if((h.second+curr.first)<dist[h.first]) pq.push({h.second+curr.first,h.first});
        }
    }
}
//Esta es la implementacion huevona
//Resuelve Single Source Shortest Paths con aristas positivas
//Como es la lazy implementation, si funciona con edges negativos siempre y cuando no hayan ciclos negativos
//Si hay ciclos negativos se va atascar en un ciclo infinito
//Si no los hay puede que funcione en O((V+E)log(V)) o puede que se exponencial, si no jala prueba BellmanFord