int minEdgesToReverse(int N, vector<pair<int, int>>& edges, int source, int destination) {
    unordered_map<int, vector<int>> adjList;
    for (auto& edge : edges) {
        adjList[edge.first].push_back(edge.second);
    }

    queue<int> q;
    unordered_map<int, int> visited;

    q.push(source);
    visited[source] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == destination) {
            return visited[node];
        }

        for (int neighbor : adjList[node]) {
            if (!visited.count(neighbor) || visited[neighbor] > visited[node]) {
                visited[neighbor] = visited[node];
                q.push(neighbor);
            }
        }

        for (int neighbor : adjList[node]) {
            if (!visited.count(neighbor) || visited[neighbor] > visited[node] + 1) {
                visited[neighbor] = visited[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1;
}
