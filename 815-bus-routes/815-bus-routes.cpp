class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int target) {
        unordered_map<int, vector<int>> m;
        int n=routes.size();
        for(int i=0;i<n;i++){
            for(int j:routes[i]){
                m[j].push_back(i);
            }
        }
        vector<bool> visbus(n, false);
        unordered_map<int, bool> visroute;
        queue<pair<int,int>> q;
        q.push({src, 0});
        visroute[src]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto t = q.front();
                q.pop();
                int route = t.first;
                int lvl = t.second;
                if(route==target){
                    return lvl;
                }
                for(int i:m[route]){
                    if(!visbus[i]){
                        for(int j:routes[i]){
                            if(!visroute[j]){
                                q.push({j, lvl+1});
                                visroute[j]=true;
                            }
                        }
                        visbus[i]=true;
                    }
                }
            }
        }
        return -1;
    }
};