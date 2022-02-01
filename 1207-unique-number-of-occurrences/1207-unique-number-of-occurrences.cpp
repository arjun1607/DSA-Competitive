class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m; 
        set<int> s;
        for(int i:arr) m[i]++;
        for(auto i:m){
            if(s.find(i.second)==s.end()) s.insert(i.second);
            else return false;
        }
        return true;
    }
};