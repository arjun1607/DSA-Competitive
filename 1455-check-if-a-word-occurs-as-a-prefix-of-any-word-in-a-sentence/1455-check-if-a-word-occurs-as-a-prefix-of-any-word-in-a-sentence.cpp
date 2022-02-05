class Solution {
public:
    int isPrefixOfWord(string s, string t) {
        /* TWO POINTERS
        
        int j=0, count=0;
        for(int i=0;i<s.size();){
            if(s[i]!=' '){
                if(s[i]==t[j]) { 
                    i++; j++; 
                }else{
                    while(i<s.size() && s[i]!=' ') i++;
                }
                if(j==t.size()) return count+1;
            }else {
                
                    Input: "b bu bur burg burger" , "burg"
                    Expected: 4
                
                count++;
                i++;
                j=0;
            }
        }
        return -1;
        */     
        
           // ADDING LEADING SPACES TRICK
           s=" "+s; t=" "+t;
           auto pos=s.find(t);
           if(pos!=string::npos) return count(s.begin(), s.begin()+pos+1, ' ');
           return -1;
    }
};

















