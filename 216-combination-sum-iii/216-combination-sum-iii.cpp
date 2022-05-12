class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i, int nosleft, int target, vector<int> &temp, int currsum){
        if(nosleft==0){
            if(currsum==target){
                ans.push_back(temp);
            }
            return;
        }  
        if(i==10) return ;
        
        // include
        if(i<=target){
            temp.push_back(i);
            helper(i+1, nosleft-1, target, temp, currsum+i);
            temp.pop_back();
        }
        
        // not include
        helper(i+1, nosleft, target, temp, currsum);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        helper(1, k, n, temp, 0);
        return ans;
    }
};