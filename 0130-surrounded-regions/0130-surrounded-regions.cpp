class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int R = board.size();
        int C = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<C;i++){
            if(board[0][i] == 'O') q.push({0,i});
            if(board[R-1][i]=='O') q.push({R-1,i});
        }
        for(int i=0;i<R;i++){
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][C-1]=='O') q.push({i,C-1});
        }
        while(!q.empty()){
            auto [r,c] = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nr = r +dx[i];
                int nc = c +dy[i];
                if(nr> 0 && nr < R-1 && nc >0 && nc < C-1 && board[nr][nc] == 'O'){
                    board[nr][nc] = '#';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=1;i<R-1;i++){
            for(int j=1;j<C-1;j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }

    }
};