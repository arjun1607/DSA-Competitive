class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& p) {
        unordered_map<int,int> m;
        for(int v:arr){
            for(int i=0;i<p.size();i++){
                if(p[i][0]==v) {
                    m[v]=i; break;
                }
            }
        }
        vector<int> v; 
        for(int i:arr){
            if(m.find(i)!=m.end()){
               for(int j:p[m[i]]) v.push_back(j);
            }
        }
        return v==arr;
    }
};