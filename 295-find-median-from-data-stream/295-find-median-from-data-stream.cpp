class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max.empty() || max.top()>num) max.push(num);
        else min.push(num);
        int diff=max.size()-min.size();
        if(abs(diff) > 1){
            if(max.size()>min.size()){
                min.push(max.top());
                max.pop();
            }else{
                max.push(min.top());
                min.pop();
            }
        }
    }
    
    double findMedian() {
        double ans;
        if(max.size()==min.size()){
            ans=(max.top()+min.top())/2.0;
        }else{
            if(max.size()>min.size()) ans=max.top();
            else ans=min.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */