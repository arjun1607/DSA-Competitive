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
    
    ll solve(int mask, int index, int n, vector<int> &v, vector<vector<ll>> &dp){
        if(mask == (1<<n)-1) return 0;
        if(index >= (int)v.size()) return dp[index][mask] = (1l<<61)-1;
        
        if(dp[index][mask] != -1) return dp[index][mask];
        
        ll incl = 1l<<index | solve(mask|v[index], index+1, n, v, dp);
        ll excl = solve(mask, index+1, n, v, dp);
        
        return dp[index][mask] = countSetBits(incl) < countSetBits(excl) ? incl : excl;
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
        ll pos = solve(0, 0, no_of_skills, v, dp);
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