class Solution {
public:
    bool judgeCircle(string m) {
        int x=0, y=0;
        for(char c:m){
            if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='R') x++;
            else if(c=='L') x--;
            //if(x==0 && y==0) return true;
        }
        return (x==0 && y==0)?true:false;
    }
};