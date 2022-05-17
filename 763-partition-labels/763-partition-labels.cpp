class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> pos(26);
        for(int i=0;i<s.size();i++) pos[s[i]-'a']=i;
        vector<int> ans;
        int partition=0;
        for(int i=0, j=0; j<s.size(); j++){
            partition = max(partition, pos[s[j]-'a']);
            if(j==partition){
                ans.push_back(j-i+1);
                i=j+1;
            }
        }
        return ans;
    }
};