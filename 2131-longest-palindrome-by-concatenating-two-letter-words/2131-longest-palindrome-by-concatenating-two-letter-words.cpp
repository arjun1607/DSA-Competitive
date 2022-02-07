class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        /*
        multiset<string> s; 
        int ans=0;
        for(auto i:words){        
            // finding reversed string
            string t=i; reverse(t.begin(), t.end());
            if(s.find(t)!=s.end()){
                ans+=4;
                s.erase(s.find(t));
            }else s.insert(i);
        }
        
        // "aa" occur only one which can be in middle of palindrome
        for(auto i:s){
            if(i[0]==i[1]){
                ans+=2; break;
            }
        }
        return ans;
        */
        
        unordered_map<string, int> m;
        for(auto i:words) m[i]++;
        int ans=0;
        for(auto i:words){
            string t=i; reverse(t.begin(), t.end());
            if(i!=t && m.find(t)!=m.end()){
                ans = ans + 4*min(m[i], m[t]);
                m.erase(i); m.erase(t);           
            }else if(i==t){
                if(m[i]%2==0){
                    ans+=(2*m[i]);
                    m.erase(i);
                }else{
                    ans+=(2*(m[i]-1));
                    m[i]=1;
                }
            }
        }
        for(auto i:m){
            if(i.second==1 && i.first[0]==i.first[1]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};



























