class Solution {
public:
    bool backtrack(vector<int> &ms,int i,vector<int> &temp,int side){
        //if we have reached till the last index that means we have got the required square
        if(i==ms.size())
        {
            return true;
        }
        for(int index=0;index<4;index++)
        {
          if(temp[index]+ms[i]<=side)
          {
              //try to include the current matchstick in one of the sides and check the answer by calling the recursion
              temp[index]=temp[index]+ms[i];
              if(backtrack(ms,i+1,temp,side))
              {
                  return true;
              }
              //if we came here that means we have placed the matchstick at the wrong place 
              //so remove it
              temp[index]=temp[index]-ms[i];//backtracking step
          }    
        }
        return false;
    }
    bool makesquare(vector<int>& ms) {
        int n=ms.size();
        if(n<4)
        {
          return false;
        }
        //calculate the perimeter
        int sum=accumulate(ms.begin(),ms.end(),0);
        //if perimeter is not divisible by 4 that means we cannot form a square
        if(sum%4!=0)
        {
            return false;
        }
        vector<int> temp(4,0);
        int x=sum/4;
        sort(ms.begin(),ms.end(),greater<int>());//optimsation for the backtracking
//if we encounter a matchstick such that after placing it the side is greater than the required side we can reject it 
//and call the backtracking for the other matchstick
        return backtrack(ms,0,temp,x);   
    }
};