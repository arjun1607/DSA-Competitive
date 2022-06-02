typedef unordered_map<string, unordered_map<string, double>> graph;
typedef unordered_map<string, bool> visited;
class Solution {
public:
    vector<double> ans;
    void dfs(graph &adj, string src, string des, visited &vis, double cost, bool &found){
        if(src==des && found==false){
            found=true;
            ans.push_back(cost);
            return;
        }
        vis[src]=true;
        for(auto i:adj[src]){
            if(!vis[i.first]){
                dfs(adj, i.first, des, vis, cost*i.second, found);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, 
                                vector<double>& val, vector<vector<string>>& q) {
        graph adj;
        for(int i=0;i<eq.size();i++){
            auto var=eq[i];
            adj[var[0]][var[1]]=val[i];
            adj[var[1]][var[0]]=(1/val[i]);
        }
        for(auto i:q){
            string var1=i[0], var2=i[1];
            visited vis;
            if(adj.find(var1)==adj.end() || adj.find(var2)==adj.end()){
                ans.push_back(-1.0);
            }else{
                bool found=false;
                dfs(adj, var1, var2, vis, 1, found);
                if(!found) ans.push_back(-1.0);
                
            }
        }
        return ans;
    }
};