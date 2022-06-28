class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(char c:s){
            v[c-'a']++;
        }
        unordered_set<int> st;
        st.insert(v[0]);

        int ans=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==0) continue;
            if(st.find(v[i])==st.end()) st.insert(v[i]);
            else{
                while(st.find(v[i])!=st.end()){
                    ans++;
                    v[i]--;
                    if(v[i]==0) break;
                }
                if(v[i]) st.insert(v[i]);
            }
        }
        return ans;        
    }
};