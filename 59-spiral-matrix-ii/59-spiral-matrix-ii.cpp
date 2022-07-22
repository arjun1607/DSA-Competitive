class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top=0, down=matrix.size()-1, left=0, right=matrix[0].size()-1;
        int dir=0;
        int k=1;
        while(top<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++) matrix[top][i]=k++;
                top++;
            }else if(dir==1){
                for(int i=top;i<=down;i++) matrix[i][right]=k++;
                right--;
            }else if(dir==2){
                for(int i=right;i>=left;i--) matrix[down][i]=k++;
                down--;
            }else{
                for(int i=down;i>=top;i--) matrix[i][left]=k++;
                left++;
            }
            dir=(dir+1)%4;
        }
        return matrix;
    }
};