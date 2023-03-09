#define GS 2010
vector<int> graph[GS];
vector<int> graphI[GS];
vector<int> orden;
bitset<GS> vis;

void invertirGrafo(int n){
    for(int p = 1;p<= n; p++)
        for(int h: graph[p])graphI[h].push_back(p);  
}
void obtOrd(int p,int n){
    vis[p] = 1;
    for(int h: graph[p]){
        if(!vis[h] && h<=n) obtOrd(h,n);
    }
    orden.push_back(p);
}
int findSCC(int n){
    int res = 0;
    invertirGrafo(n);
    orden.clear();
    for(int i = 1; i<=n; i++) vis[i] =0;
    for(int i = 1; i<=n; i++) if(!vis[i]) obtOrd(i,n);
    reverse(orden.begin(),orden.end());
    //cuenta los connected components
    //vector<int> lscc;
    stack<int> fringe;
    int curr;
    for(int i = 1; i<=n; i++) vis[i] =0;
    for(int i: orden){
        //lscc.clear();
        if(!vis[i]){
            fringe.push(i);
            while (fringe.size()){
                curr = fringe.top();fringe.pop();
                //lscc.push_back(curr);
                if (!vis[curr]) {
                    vis[curr] = 1;
                    for (int h : graphI[curr]) fringe.push(h);
                }
            }
            res++;
        }
        //hacer lo que sea con lcss
    }
    return res;
}

//OJO esto solo jala con directed graphs
//por definicion todas las undirected graphs tienen un solo SCC
//NOTAR QUE LOS GRAFOS QUE USA CUMPLEN CON: 0<=VERTICE<=n