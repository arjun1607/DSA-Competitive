// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> sieve(int N) {
        vector<bool> isPrime(N+1, true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<=sqrt(N);i++){
            if(isPrime[i]){
                for(int j=i*i;j<=N;j+=i) isPrime[j]=false;
            }
        }
        vector<int> ans;
        for(int i=2;i<=N;i++){
            if(isPrime[i]) ans.push_back(i);
        }
        return ans;
    }
    long long primeProduct(long long L, long long R){
        vector<int> primes = sieve(pow(R, 0.5));
        vector<bool> seg_sieve(R-L+1, true);
        for(int i:primes){
            int multiple = ceil(L*1.0/i);
            if(multiple==1) multiple++; // otherwise we will lose that prime
       
            int firstidx = (multiple*i)-L;
            
            for(int j=firstidx; j<seg_sieve.size(); j+=i){
                seg_sieve[j]=false;
            }
        }

        long long ans=1;
        int m = 1e9 + 7;
        for(int i=0; i<seg_sieve.size(); i++){
            if(seg_sieve[i]){
                ans=((ans%m)*((L+i)%m))%m;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends