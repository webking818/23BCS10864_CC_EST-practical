class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int s, int t, int k) {
        
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : f) {
            g[e[0]].push_back({e[1], e[2]});
        }
        
        queue<pair<int,int>> q;
        q.push({s, 0});
        
        vector<int> d(n, 1e9);
        d[s] = 0;
        
        int st = 0;
        
        while (!q.empty() && st <= k) {
            int sz = q.size();
            
            vector<int> tmp = d;  // Bellman-Ford style
            
            while (sz--) {
                auto [u, c] = q.front(); q.pop();
                
                for (auto &[v, w] : g[u]) {
                    if (c + w < tmp[v]) {
                        tmp[v] = c + w;
                        q.push({v, tmp[v]});
                    }
                }
            }
            
            d = tmp;
            st++;
        }
        
        return d[t] == 1e9 ? -1 : d[t];
    }
};