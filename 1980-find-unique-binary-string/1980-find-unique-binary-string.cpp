class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<string> s;
        for(auto i:nums) s.insert(i);
        for(int i=0;i<=(1<<n)-1;i++){
            string t="";
            for(int j=n-1; j>=0; j--){
                if(i&(1<<j)) t+='1';
                else t+='0';
            }
            if(s.find(t)==s.end()) return t;
        }
        return "";
    }
};