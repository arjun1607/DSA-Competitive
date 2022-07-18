class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(char c:t) m[c]++;
        int i=0, j=0, count=m.size();
        
        int si=-1, len=INT_MAX;
        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0) count--;
            }
            while(count==0){
                if(j-i+1 < len){
                    si=i; 
                    len=j-i+1;
                }

                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1) count++;
                }
                i++;
            }
            j++;
        }
     
        return (len==INT_MAX)?"":s.substr(si, len);
    }
};