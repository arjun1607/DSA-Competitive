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
                    //if yes, add the new course and update the time
                    time+=course[0];
                    pq.push(course[0]);
                }else{
                    // if exceeds deadline, swap it with the biggest duration from the ones taken up
					// swap should reduce the time taken till now
                    if(pq.top() > course[0]){
                        time -= pq.top();
                        pq.pop();
                        time += course[0];
                        pq.push(course[0]);
                    }
                }
            }
        }
		
		// all taken up courses present in priority queue
        return pq.size();
    }
};