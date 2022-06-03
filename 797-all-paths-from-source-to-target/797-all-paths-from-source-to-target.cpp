class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, int src, int des, vector<bool> &vis, vector<int> &temp){
        if(src==des){
            ans.push_back(temp);
            return;
        }
        vis[src]==true;
        for(int i:graph[src]){
            if(!vis[i]){
                temp.push_back(i);
                dfs(graph, i, des, vis, temp);
                temp.pop_back();
            }
        }
        vis[src]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> temp;
        vector<bool> vis(n, false);
        temp.push_back(0);
        dfs(graph, 0, n-1, vis, temp);
        return ans;
    }
};