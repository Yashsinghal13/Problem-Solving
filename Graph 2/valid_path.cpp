#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isOverlapping(int x, int y, int n, int r, vector<int>& aPoints, vector<int>& bPoints) {
        for (int i = 0; i < n; i++) {
            int distanceX = abs(x - aPoints[i]);
            int distanceY = abs(y - bPoints[i]);
            double calculatedDistance = sqrt(distanceX * distanceX + distanceY * distanceY);
            if (calculatedDistance <= (double)r) {
                return true;
            }
        }
        return false;
    }

    bool isReachable(int x, int y, int targetX, int targetY, int n, int r, vector<int>& aPoints, vector<int>& bPoints, bool visited[][101]) {
        if (x == targetX && y == targetY) {
            return true;
        }
        if (visited[x][y]) {
            return false;
        }
        visited[x][y] = true;

        int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int d = 0; d < 8; d++) {
            int newX = x + dx[d];
            int newY = y + dy[d];

            if (newX < 0 || newY < 0 || newX > targetX || newY > targetY || visited[newX][newY] || isOverlapping(newX, newY, n, r, aPoints, bPoints)) {
                continue;
            }

            if (isReachable(newX, newY, targetX, targetY, n, r, aPoints, bPoints, visited)) {
                return true;
            }
        }
        return false;
    }
};