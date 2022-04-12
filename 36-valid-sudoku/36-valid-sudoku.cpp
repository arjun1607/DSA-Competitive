class Solution {
public:
   bool valid(vector<vector<char>> &cube, int x, int y){
       int val=cube[x][y]-'0';
    int i=(x/3)*3, j=(y/3)*3;
    for(int p=i;p<i+3;p++){
        for(int q=j;q<j+3;q++){
            if(p==x && q==y) continue;
            if(cube[p][q]-'0'==val) return false;
        }
    }

    for(int j=0;j<9;j++){
        if(j==y) continue;
        if(cube[x][j]-'0'==val) return false;
    }

    for(int i=0;i<9;i++){
        if(i==x) continue;
        if(cube[i][y]-'0'==val) return false;
    }

    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.' && !valid(board, i, j)){
                    cout<<i<<" "<<j;
                    return false;
                }
            }
        }
        return true;
    }
};

/*
["5","3",".",".","7",".",".",".","."]
["6",".",".","1","9","5",".",".","."]
[".","9","8",".",".",".",".","6","."]
["8",".",".",".","6",".",".",".","3"]
["4",".",".","8",".","3",".",".","1"]
["7",".",".",".","2",".",".",".","6"]
[".","6",".",".",".",".","2","8","."]
[".",".",".","4","1","9",".",".","5"]
[".",".",".",".","8",".",".","7","9"]


*/




