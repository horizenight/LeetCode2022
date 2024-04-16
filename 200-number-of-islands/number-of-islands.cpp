class Solution {
public:
    void dfs(int row ,int col, vector<vector<char>>& grid , vector<vector<int>>&vis ,  vector<pair<int,int>> &vec ){
        vis[row][col] =1;
        int n = grid.size();
        int m = grid[0].size();
        vec.push_back({row,col});
        int d_row[] = {-1,0,1,0};
        int d_col[] = {0,1,0,-1};
        for(int i = 0 ; i<4;i++){
            int n_row = row + d_row[i];
            int n_col = col + d_col[i];
            if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && !vis[n_row][n_col] && grid[n_row][n_col] == '1'){
                dfs(n_row,n_col,grid,vis,vec);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    

        set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0; i <n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] =='1'){
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vis,vec);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};