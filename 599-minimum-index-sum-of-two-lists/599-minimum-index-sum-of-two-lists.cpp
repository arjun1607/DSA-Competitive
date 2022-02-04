class Solution {
public:
    vector<string> findRestaurant(vector<string>& a, vector<string>& b) {
        unordered_map<string,int> m;
        for(int i=0;i<a.size();i++) m[a[i]]=i;
        int idx=INT_MAX;
        vector<string> ans;
        for(int i=0;i<b.size();i++){
            if(m.find(b[i])!=m.end()){
                if(i+m[b[i]]<idx){
                    ans.clear();
                    ans.push_back(b[i]);
                    idx=i+m[b[i]];
                }else if(i+m[b[i]]==idx){
                    ans.push_back(b[i]);
                } 
            }
        }
        return ans;
    }
};