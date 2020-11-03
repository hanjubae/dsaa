class Solution {
public:
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bfs(vector<vector<int>>& heights, int limit) {
    int R = heights.size();
    int C = heights[0].size();
    queue<int> q;
    vector<vector<bool>> visited;
    visited.clear();
    visited.resize(R, vector<bool>(C, 0));
    visited[0][0] = true;
    q.push(0);
    q.push(0);

    while (q.size() > 0) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();

        if (x == R - 1 && y == C - 1) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= R || nx < 0 || ny >= C || ny < 0) continue;
            if (visited[nx][ny]) continue;
            if (abs(heights[x][y] - heights[nx][ny]) <= limit) {
                q.push(nx);
                q.push(ny);
                visited[nx][ny] = true;
            }
        }
    }
    return false;
}

int minimumEffortPath(vector<vector<int>>& heights) {
    int l = 0, r = 1000001;

    while (l < r) {
        int limit = (l + r) / 2;
        if (bfs(heights, limit)) {
            r = limit;
        }
        else {
            l = limit + 1;
        }
    }

    return r;
}
};
