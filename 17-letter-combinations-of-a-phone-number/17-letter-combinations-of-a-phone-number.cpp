class Solution {
public:
    string pad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    
    void helper(string q, string a, vector<string> &ans){
        if(q.size()==0){
            ans.push_back(a);
            return ;
        }
        int i=q[0]-'0';
        string code=pad[i];
        for(char c:code){
            helper(q.substr(1), a+c, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        helper(digits, "", ans);
        return ans;
    }
};