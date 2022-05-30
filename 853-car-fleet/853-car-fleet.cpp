class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n=pos.size();
        vector<pair<int, double>> time;
        for(int i=0;i<n;i++){
            time.push_back({pos[i], (double)(target - pos[i])/speed[i]});
        }
        sort(time.begin(), time.end());
        
        stack<double> s;
        // finding next greater on right
        for(int i=0;i<n;i++){
            while(!s.empty() && time[i].second >= time[s.top()].second) s.pop();
            s.push(i);
        }
        return s.size();
        
        /*
        int count=1;
        double timetaken_leader=time[n-1].second;
        for(int i=n-2; i>=0; i--){
            double timetaken_currcar = time[i].second;
            cout<<timetaken_currcar<<" "<<timetaken_leader;
            
            // if currcar does not collide with any car in front of it
            if(timetaken_currcar > timetaken_leader){
                timetaken_leader = timetaken_currcar;
                count++;
            }
        }
        return count;
        */
    }
};