class Solution {
public:
    vector<vector<string>> ans;
    void helper(vector<vector<int>> &chess, int row, vector<bool> &col, vector<bool> &nd, 
                              vector<bool> &rd){
        if(row==chess.size()){
            vector<string> temp;
            for(int i=0;i<chess.size();i++){
                string s=""; 
                for(int j=0;j<chess[0].size();j++){
                    if(chess[i][j]==0) s+='.';
                    else s+='Q';
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<chess[0].size();i++){
            if(col[i]==false && nd[i+row]==false && rd[row-i+chess.size()-1]==false){
                chess[row][i]=1;
                col[i]=true;
                nd[row+i]=true;
                rd[row-i+chess.size()-1]=true;
                
                helper(chess, row+1, col, nd, rd);
                
                chess[row][i]=0;
                col[i]=false;
                nd[row+i]=false;
                rd[row-i+chess.size()-1]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> chess(n, vector<int>(n,0));
        vector<bool> col(n, false), nd(2*n-1, false), rd(2*n-1, false);
        helper(chess, 0, col, nd, rd);
        return ans;
    }
};