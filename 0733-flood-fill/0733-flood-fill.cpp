class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int tempColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            auto [r,c] = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nr = r +dx[i];
                int nc = c +dy[i];
                if(nr >=0 && nr < m && nc >=0 && nc < n && image[nr][nc] == tempColor){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
        image[sr][sc] = color;
        return image;    
    }
};