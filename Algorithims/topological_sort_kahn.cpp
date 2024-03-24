vector<int> order;
bool toposort(vector<vector<int>>& g) {//Returns 1 if there exists a toposort, 0 if there is a cycle
    order.clear();
    int n = (int)g.size();
    queue<int> q;
    vector<int> indeg(n, 0);
    for(int i = 0; i < n; i++)
        for(auto &it:g[i])
            indeg[it]++;
    for(int i = 0; i < n; i++) {
        if(!indeg[i])
            q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(auto &v:g[u]) {
            indeg[v]--;
            if(!indeg[v])
                q.push(v);
        }
    }
    return (order.size() == n);	
}