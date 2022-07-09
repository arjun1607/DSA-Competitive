class Solution {
public:

    int helper(int i, vector<int> &nums, int k, vector<int> &dp){
        if(i==nums.size()-1) return nums[i];
        
        if(dp[i]!=-1) return dp[i];
        
        int temp = INT_MIN;
        for(int j=1; j<=k; j++){
            if(i+j < nums.size())
                temp = max(temp, helper(j+i, nums, k, dp));
        }
        
        return dp[i] = temp + nums[i];
    }
#define pii pair<int, int>

    int maxResult(vector<int>& nums, int k)
    {
        int n=nums.size();
        int score[n];
        priority_queue<pii> pq;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(pq.size() && pq.top().second>i+k)
                pq.pop();
            
            score[i]=nums[i];
            score[i]+=(pq.size() ? pq.top().first : 0);
            pq.push({score[i], i});
        }
        
        return score[0];
    }
};
