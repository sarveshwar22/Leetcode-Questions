class UnionFind {
public:
    vector<int> root, rank;
    
    UnionFind(int sz) : root(sz), rank(sz, 1) {
        iota(root.begin(), root.end(), 0);
    }
    
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int manhattan(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    int kruskal(vector<vector<int>>& points) {
        int V = points.size();
        vector<tuple<int, int, int>> edges;
        
        for (int i = 0; i < V - 1; i++) {
            for (int j = i + 1; j < V; j++) {
                edges.push_back({manhattan(points[i], points[j]), i, j});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        UnionFind uf(V);
        
        int cost = 0;
        int E = 0;
        for (auto& edge : edges) {
            if (not uf.isConnected(get<1>(edge), get<2>(edge))) {
                uf.unite(get<1>(edge), get<2>(edge));
                cost += get<0>(edge);
                E++;
                if (E == V - 1) {
                    break;
                }
            }
        }
        
        return cost;
    }
    
    int prim(vector<vector<int>>& points) {
        int V = points.size();
        vector<bool> used(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        int cost = 0;
        int E = 0;
        while (E < V) {
            auto [weight, node] = pq.top();
            pq.pop();
            
            if (used[node]) {
                continue;
            }
            
            used[node] = true;
            cost += weight;
            E++;
            
            for (int i = 0; i < V; i++) {
                if (used[i]) {
                    continue;
                }
                pq.push({manhattan(points[i], points[node]), i});
            }
        }
        
        return cost;
    }
    
    int primOpt(vector<vector<int>>& points) {
        int V = points.size();
        vector<bool> used(V, false);
        vector<int> minDist(V, INT_MAX);
        minDist[0] = 0;
        
        int cost = 0;
        int E = 0;
        
        while (E < V) {
            int minWeight = INT_MAX;
            int minNode = -1;
            
            for (int i = 0; i < V; i++) {
                if (not used[i] and minDist[i] < minWeight) {
                    minWeight = minDist[i];
                    minNode = i;
                }
            }
            
            used[minNode] = true;
            cost += minWeight;
            E++;
            
            for (int i = 0; i < V; i++) {
                if (not used[i]) {
                    minDist[i] = min(minDist[i], manhattan(points[i], points[minNode]));
                }
            }
        }
        
        return cost;
    }
    
    int primOptList(vector<vector<int>>& points) {
        int V = points.size();
        list<pair<int, int>> minDist;
        for (int i = 1; i < V; i++) {
            minDist.push_back({i, INT_MAX});
        }
        minDist.push_front({0, 0});
        
        int cost = 0;
        int E = 0;
        
        while (E < V) {
            auto minIt = minDist.end();
            int minWeight = INT_MAX;
            
            for (auto it = minDist.begin(); it != minDist.end(); it++) {
                if (it->second < minWeight) {
                    minWeight = it->second;
                    minIt = it;
                }
            }
            
            int minNode = minIt->first;
            cost += minIt->second;
            E++;
            minDist.erase(minIt);
            
            for (auto it = minDist.begin(); it != minDist.end(); it++) {
                it->second = min(it->second, manhattan(points[it->first], points[minNode]));
            }
        }
        
        return cost;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // return kruskal(points);
        // return prim(points);
        // return primOpt(points);
        return primOptList(points);
    }
};