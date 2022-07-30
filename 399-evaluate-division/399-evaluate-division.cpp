class Solution {
public:
    vector<double> ans;
    void dfs(unordered_map<string, unordered_map<string, double>> &m, 
             unordered_set<string> &vis, string src, string des, double cost, bool &found){
        if(src==des && found==false){
            found=true;
            ans.push_back(cost);
            return;
        }
        vis.insert(src);
        for(auto i : m[src]){
            if(vis.find(i.first)==vis.end()){
                dfs(m, vis, i.first, des, cost * i.second, found);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& vals, vector<vector<string>>& q) {
        unordered_map<string, unordered_map<string, double>> m;
        set<string> s;
        int n=eq.size();
        for(int i=0;i<n;i++){
            string u = eq[i][0];
            string v = eq[i][1];
            s.insert(u);
            s.insert(v);
            m[u][v] = vals[i];
            m[v][u] = 1.0/vals[i];
        }

        for(auto i:q){
            string src = i[0];
            string des = i[1];
            if(s.find(src)==s.end() || s.find(des)==s.end()){
                ans.push_back(-1.0);
            }
            else{
                unordered_set<string> vis;
                bool found=false;
                dfs(m, vis, src, des, 1.0, found);
                if(!found) ans.push_back(-1.0);
            }
        }
        return ans;
    }
};