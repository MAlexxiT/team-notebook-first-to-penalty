#define GS 400040
vector<int> graph[GS];
bitset <GS> vis;
vector<int> topsort;
int e,n;
//profundidad
//O(N+E)
//Solo funciona con DAG's, no existe un top sort de un grafo Non-DAG
void todfs(int pa) {
	vis[pa]=1;
	for(int h: graph[pa]){if(!vis[h]){todfs(h);}}
	topsort.push_back(pa);
}
void topologicalSort(){
	vis.reset();
	topsort.clear();
	for(int i = 0; i<n; i++){if(!vis[i]){dfs(i);}}
	reverse(topsort.begin(),topsort.end());
}