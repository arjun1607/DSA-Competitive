class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;
        for(auto i:ing){
            for(string j:i) indegree[j]=0;
        }
        
        unordered_map<string, vector<string>> ting;
        for(int i=0;i<rec.size();i++){
            for(string j:ing[i]){
                ting[rec[i]].push_back(j);
                adj[j].push_back(rec[i]);
                indegree[rec[i]]++;
            }
        }
        
        vector<string> order;
        queue<string> q;
        for(auto i:indegree){
            if(i.second==0) q.push(i.first);
        }
   
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            order.push_back(curr);
            for(string i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        
        vector<string> ans;
        unordered_set<string> s;
        for(string i:sup) s.insert(i);
        for(string i:order){
            bool ok;
            for(string j:ting[i]){
                if(s.find(j)==s.end()){
                    ok=false;
                    break;
                }else ok=true;
            }
            if(ok){
                s.insert(i);
                ans.push_back(i);
            }
        }
        return ans;
    }
};






