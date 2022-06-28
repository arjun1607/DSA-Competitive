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
                // Keep decrementing the frequency until it is unique
                while(v[i] && st.find(v[i])!=st.end()){
                    v[i]--;
                    ans++;
                }
                st.insert(v[i]);
        }
        return ans;        
    }
};