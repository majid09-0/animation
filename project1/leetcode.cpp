class Solution {
private:
    bool f(int row , int col , vector<int>& target , int cnt , int dx[] , int dy[] , vector<vector<int>>& vis) {
        if(row == target[0] && col == target[1]) return cnt % 2 == 0;
        vis[row][col] = 1;
        for(int i = 0; i < 8; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0  && ncol >= 0 && nrow < 8 && ncol < 8 && !vis[nrow][ncol]) {
                if(f(nrow , ncol , target , cnt + 1 , dx , dy , vis)) return true;
            }
        }
        vis[row][col] = 0;
        return false;
    }
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dx[8] = {-1,-2,-2,-1,+1,+2,+2,+1};
        int dy[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
        vector<vector<int>> vis(8 , vector<int>(8 , 0));
        return f(start[0] , start[1] , target , 0 , dx , dy , vis);
    }