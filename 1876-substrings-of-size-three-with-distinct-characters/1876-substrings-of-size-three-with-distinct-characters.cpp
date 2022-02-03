class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> m;
        int i=0, j=0;
        int count=0;
        while(j<s.size()){
            m[s[j]]++;
            if(j-i+1<3) j++;
            else if(j-i+1==3){
                if(m.size()==3){
                    count++;
                }
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++; j++;
            }
        }
        return count;
    }
};