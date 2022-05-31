class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:rooms[node]){
                if(vis[i]==false){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
        for(auto i:vis) if(i==false) return false;
        return true;
    }
};