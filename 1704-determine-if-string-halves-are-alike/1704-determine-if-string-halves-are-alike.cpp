class Solution {
public:
    bool halvesAreAlike(string s) {
        string a=s.substr(0, s.size()/2);
        string b=s.substr(s.size()/2);
        int c1=0, c2=0;
        for(char c:a){
            if(c=='a' || c== 'e'|| c== 'i'|| c=='o'|| c== 'u'|| c=='A'|| c=='E'|| c== 'I'|| c== 'O'|| c== 'U') c1++;
        }
        for(char c:b){
            if(c=='a' || c== 'e'|| c== 'i'|| c=='o'|| c== 'u'|| c=='A'|| c=='E'|| c== 'I'|| c== 'O'|| c== 'U') c2++;
        }
        return c1==c2;
    }
};