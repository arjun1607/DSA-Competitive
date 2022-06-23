class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        int time=0;
        for(auto course : courses){
            // chekc if we consider the curr course
            if(course[0] <= course[1]){
                // curr course can be completed within last day
                if(course[0] + time <=  course[1]){
                    time+=course[0];
                    pq.push(course[0]);
                }else{
                    // check if we can swap
                    if(pq.top() > course[0]){
                        time -= pq.top();
                        pq.pop();
                        time += course[0];
                        pq.push(course[0]);
                    }
                }
            }
        }
        return pq.size();
    }
};

/*
Input : [[5,5],[4,6],[2,6]]
Output : 1
Expected : 2
*/