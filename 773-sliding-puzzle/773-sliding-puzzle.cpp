class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // time complexity = 6*(6!)\
        
        string s(6, ' ');
        int idxof0;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0) idxof0=i*3+j;
                s[i*3+j]='0'+board[i][j];
            }
        }
        
        vector<vector<int>> swapidx;
        swapidx.push_back({1,3});
        swapidx.push_back({0,2,4});
        swapidx.push_back({1,5});
        swapidx.push_back({0,4});
        swapidx.push_back({1,3,5});
        swapidx.push_back({2,4});
        
        set<string> vis;
        vis.insert(s);
        
        queue<pair<string, pair<int,int>>> q;   // string, lvl, index of 0
        q.push({s, {0, idxof0}});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            string str=t.first;
            int lvl=t.second.first;
            int idxof0=t.second.second;
            
            if(str=="123450") return lvl;
            
            for(int i:swapidx[idxof0]){
                string temp=str;
                swap(temp[i], temp[idxof0]);
                if(vis.find(temp)==vis.end()){
                    vis.insert(temp);
                    cout<<temp<<endl;
                    q.push({temp, {lvl+1, i}});
                }
            }
        }
        return -1;
    }
};


















