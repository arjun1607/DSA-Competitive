class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Converting the given data to adjacency representation of graph
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < times.size(); ++i)
	{
		graph[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
	}
    
    // Basic Dijkstra algorithm
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> distance(n, INT_MAX);
	vector<bool> visited(n , false);

	pq.push({0, k - 1});
	distance[k - 1] = 0;

	while (!pq.empty())
	{
		pair<int, int> curr = pq.top();
		int currNode = curr.second;
		int currDistance = curr.first;
		pq.pop();

		visited[currNode] = true;
		if (currDistance > distance[currNode]) continue;

		// Go through all the adjacent
		for (int i = 0; i < graph[currNode].size(); ++i)
		{
			int adjNode = graph[currNode][i].first;
			int adjWeight = graph[currNode][i].second;

			if (distance[currNode] + adjWeight < distance[adjNode])
			{
				distance[adjNode] = distance[currNode] + adjWeight;
				pq.push({distance[adjNode], adjNode});
			}
		}
	}

	// Finding out the max distance
	int result = -1;
	for (int i = 0; i < n; ++i)
	{
        // if distance is infinity, then return -1 as we cannot reach this node
		if (distance[i] == INT_MAX) return -1;
		result = max(distance[i], result);
	}

	return result;
}
};