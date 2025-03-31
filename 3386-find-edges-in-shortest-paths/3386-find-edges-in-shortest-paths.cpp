#define ll long long
class Solution {
public:
    vector<int> getShortestPath(vector<vector<pair<int,ll>>>& graph, int src, int n) {
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> bfs;
        vector<int> dist(n, INT_MAX);
        vector<int> visited(n, 0);
        dist[src] = 0;
        bfs.push({0, src});
        
        while(!bfs.empty()) {
            int size = bfs.size();
            while(size--) {
                ll currWt = bfs.top().first;
                int currNode = bfs.top().second;
                bfs.pop();
                
                if(visited[currNode])
                    continue;
                
                for(auto adj: graph[currNode]) {
                    int nextNode = adj.first;
                    ll nextWt = adj.second;
                    
                    if(dist[nextNode] > currWt + nextWt) {
                        dist[nextNode] = currWt + nextWt;
                        bfs.push({currWt + nextWt, nextNode});
                    }
                }
                
                visited[currNode] = 1;
            }
        }
        
        return dist;
    }
    vector<vector<pair<int,ll>>> getGraph(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,ll>>> graph(n);
        
        for(auto edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        return graph;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,ll>>> graph = getGraph(n, edges);
        
        vector<int> fromStart = getShortestPath(graph, 0, n);
        vector<int> fromEnd = getShortestPath(graph, n - 1, n);         
           
        
        vector<bool> res(edges.size(), false);
        for(int i = 0 ; i < edges.size() ; i++) {  
            //          a         w         b
            //    src ----- (x) ----- (y) ----- dest

            // the edges are undirected, hence try both ways            
            // considering edges[i][0] to be x and edges[i][1] to be y
            ll distFromStart = fromStart[edges[i][0]];
            ll distFromEnd = fromEnd[edges[i][1]];
            ll midDist = edges[i][2];
            
            if(distFromStart + distFromEnd + midDist == fromStart[n - 1])
                res[i] = true;
            
            // considering edges[i][0] to be y and edges[i][1] to be x
            distFromStart = fromStart[edges[i][1]];
            distFromEnd = fromEnd[edges[i][0]];
            
            if(distFromStart + distFromEnd + midDist == fromStart[n - 1])
                res[i] = true;
        }
        
        return res;
    }
};