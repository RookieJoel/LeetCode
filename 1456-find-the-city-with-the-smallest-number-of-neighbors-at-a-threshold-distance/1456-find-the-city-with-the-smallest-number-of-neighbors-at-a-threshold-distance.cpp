class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i==j) dist[i][j] = 0;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int> col(n);
        int minimum = INT_MAX;
        for(int i=n-1;i>=0;i--){
            int count = 0;
                for(int j=0;j<n;j++){
                   if(dist[i][j] <= distanceThreshold && dist[i][j]!= 0)count++;
                }
            minimum = min(minimum,count);
            col[i] = count;
        }
         for(int i=n-1;i>=0;i--){
            if(col[i] == minimum) return i;
         }
         return -1;
    }   
};