class Solution {
public:
    void selectionSort(vector<int> &nums){
        for(int i=0;i<nums.size()-1;i++){
            int idx = min_element(nums.begin()+i, nums.end())-nums.begin();
            swap(nums[i], nums[idx]);
        }
    }
    void bubbleSort(vector<int> &nums){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(nums[j]>nums[j+1]) swap(nums[j], nums[j+1]);
            }
        }
    }
    void insertionSort(vector<int> &nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            int j=i, curr=nums[i];
            while(j>0){
                if(nums[j-1]>curr){
                    nums[j]=nums[j-1];
                    j--;
                }else break;
            }
            nums[j]=curr;
        }
    }
    
    void merge(vector<int> &nums, int s, int e, int m){
        vector<int> temp(e-s+1);
        int i=s, j=m+1, k=0;
        while(i<=m && j<=e){
            if(nums[i]<=nums[j]) temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }
        while(i<=m) temp[k++]=nums[i++];
        while(j<=e) temp[k++]=nums[j++];
        for(int i=s,k=0;i<=e;i++) nums[i]=temp[k++];
    }    
    void mergeSort(vector<int> &nums, int s, int e){
        if(s>=e) return ;
        int mid = (s+e)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        merge(nums, s, e, mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        // selectionSort(nums);
        // bubbleSort(nums);
        // insertionSort(nums);
        int n=nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
    
};

















