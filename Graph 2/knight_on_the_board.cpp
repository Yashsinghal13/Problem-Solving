bool isValidMove(int row, int col, int n, int m) {
    if (row < 0 || row > n || col < 0 || col > m || visited[row][col] == 1) {
        return false;
    }
    return true;
}

void BFS(int boardSizeRow, int boardSizeCol, int startRow, int startCol) {
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = 1;
    dist[startRow][startCol] = 0;
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int currX = node.first;
        int currY = node.second;
        
        for (int i = 0; i < 8; i++) {
            if (isValidMove(currX + dx[i], currY + dy[i], boardSizeRow, boardSizeCol)) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                q.push({newX, newY});
                visited[newX][newY] = 1;
                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }
}

int minMoves(int boardSizeRow, int boardSizeCol, int startRow, int startCol, int endRow, int endCol) {
    for (int i = 1; i <= boardSizeRow; i++) {
        for (int j = 1; j <= boardSizeCol; j++) {
            visited[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    BFS(boardSizeRow, boardSizeCol, startRow, startCol);
    
    if (dist[endRow][endCol] == 0 && endRow == startRow && endCol == startCol) {
        return 0;
    }
    if (dist[endRow][endCol] != 0) {
        return dist[endRow][endCol];
    }
    return -1;
}