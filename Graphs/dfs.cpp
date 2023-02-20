#define GS 400040
vector<int> graph[GS];
bitset <GS> vis;
//profundidad O(V+E)
void dfs(int curr) {
	stack<int> fringe;
	fringe.push(curr);
	while (fringe.size()){
		curr = fringe.top(); fringe.pop();
		if (!vis[curr]) {
			vis[curr] = 1;
			for (int h : graph[curr]) fringe.push(h);
		}
	}
}