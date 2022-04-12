class Solution {
public:
    int myAtoi(string str) {
        long val=0;
        string s="";
        bool neg=false, num=false, pos=false;
        for(char c:str){
            if(c=='-' && (num==true || pos==true || neg==true)) break;
            if(c=='+' && (num==true || pos==true || neg==true)) break;
            if(c=='.') break;            
            if(c>='a' && c<='z') break;
            if(c==' ' && (num==true || pos==true || neg==true)) break;

            if(c=='-') neg=true;
            if(c=='+') pos=true;
            if(c>='0' && c<='9') num=true;
            if(c!='-' && c!=' ' && c!='+') s+=c;
        }
        cout<<"string is "<<s;
         for(char c:s){
             cout<<val<<" ";
                if(val>INT_MAX){
                    if(neg==true) return INT_MIN;
                    else return INT_MAX;
                }
             val*=10;
             val+=(c-'0');
             cout<<val<<endl;
         }
        
        if(neg==true && pos==true) return 0;
        if(val>INT_MAX){
            if(neg==true) return INT_MIN;
            else return INT_MAX;
        }
        if(neg==true) val*=-1;
        return val;
    }
};