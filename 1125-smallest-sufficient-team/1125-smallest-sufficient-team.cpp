typedef long long int ll;
class Solution {
public:
    int countSetBits(ll bitmask){
        int c=0;
        while(bitmask){
            c += (bitmask%2);
            bitmask/=2;
        }
        return c;
    }
    
    ll recurse(int bitmask, int index, int &no_of_skills, vector<int> &v, vector<vector<ll>> &dp){
        if(dp[index][bitmask] != -1) return dp[index][bitmask];
        if(countSetBits(bitmask) == no_of_skills) return 0;
        if(index >= (int)v.size()) return dp[index][bitmask] = (((ll)1<<62) - 1);
        ll incl = (ll)1<<index | recurse(bitmask|v[index], index+1, no_of_skills, v, dp);
        ll excl = recurse(bitmask, index+1, no_of_skills, v, dp);
        return dp[index][bitmask] = ( countSetBits(incl) < countSetBits(excl) ? incl : excl);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> m;
        for(int i=0;i<(int)req_skills.size();i++){
            m[req_skills[i]] = i;
        }
        vector<int> v((int)people.size(), 0);
        for(int i=0;i<(int)people.size();i++){
            for(int j=0;j<(int)people[i].size();j++){
                v[i] = v[i]|(1<<m[people[i][j]]);
            }
            int temp=v[i];
        }
        
        int no_of_skills = m.size();
        vector<vector<ll>> dp(65, vector<ll> (1<<(no_of_skills+1), -1));
        ll pos = recurse(0, 0, no_of_skills, v, dp);
        vector<int> ans;
        int c=0;
        while(pos){
            if(pos%2 == 1) ans.push_back(c);
            c++;
            pos/=2;
        }
        return ans;
    }
};