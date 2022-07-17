class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> m;
        for(char c:p) m[c]++;
        int i=0, j=0, count=m.size();
        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0) count--;
            }
            
            if(j-i+1 == p.size()){
                cout<<count<<endl;
                if(count==0){
                    ans.push_back(i);
                }
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1) count++;
                }
                i++;
            }
            
            j++;
        }        
        return ans;
    }
};