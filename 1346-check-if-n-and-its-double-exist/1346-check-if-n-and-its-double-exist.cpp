class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int count=0;
        set<int> s; for(int i:arr) { if(i==0) count++; s.insert(i); }
        for(int i:arr){
            if(i==0 && count>1) return true;
            else if(i!=0 && s.find(i*2)!=s.end()) return true;
        }
        return false;
    }
};