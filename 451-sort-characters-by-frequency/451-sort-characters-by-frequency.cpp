class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(char ch:s) m[ch]++;
        vector<pair<int,char>> v;
        for(auto i:m){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), greater<pair<int,char>>());
        string ans = "";
        for(auto i:v){
            string temp(i.first, i.second);
            ans+=temp;
        }
        return ans;
    }
};