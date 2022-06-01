class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> m;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                m[routes[i][j]].push_back(i);
            }
        }
        vector<int> vis_bus(m.size(), false);
        unordered_map<int, bool> vis_stop;
        for(auto i:m){
            vis_stop[i.first]=false;
        }
        queue<pair<int, int>> q;
        q.push({source, 0});
        vis_stop[source]=true;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int curr_stop = node.first;
            int count = node.second;
            if(curr_stop==target) return count;
            auto busvector = m[curr_stop];
            for(int available_bus : busvector){
                if(vis_bus[available_bus]==true) continue;
                else{
                    for(int stopno : routes[available_bus]){
                        if(vis_stop[stopno]==true) continue;
                        else{
                            q.push({stopno, count+1});
                            vis_stop[stopno]=true;
                        }
                    }
                    vis_bus[available_bus]=true;
                }
            }
        }
        return -1;
    }
};