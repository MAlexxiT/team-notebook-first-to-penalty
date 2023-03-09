#define GS 1000
#define INF 100000000
//destino, costo
int graph[GS][GS];
//All Pairs Dist
int dist[GS][GS];
//Toma en cuenta nodos [0-tam] inclusivo, modificar de acuerdo a las necesidades
//Ten cuidado con el valor que le pones a INF, puede provocar overflows o puede no ser lo suficientemente grande.
void Floyd_Warshall(int tam){
    for(int i = 0; i<=tam; i++)
        for(int f = 0; f<=tam; f++)
            dist[i][f] = INF;
    
    for(int i = 0; i<=tam; i++)
        for(int f = 0; f<=tam; f++)
            dist[i][f] = graph[i][f];

    //para reconstruir el camino solo basta con guardar intermedio como el padre de ini si el cambio se hizo, -1 otherwise
    for(int intermedio = 0; intermedio<=tam; intermedio++)
        for(int ini = 0;  ini<=tam; ini++)
            for(int fin = 0; fin<=tam; fin++)
                dist[ini][fin] = min(dist[ini][fin],dist[ini][intermedio]+dist[intermedio][fin]);
}