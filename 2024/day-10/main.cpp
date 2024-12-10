#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

int partOne() {
    vector<string> lines;
    string line;
    while (getline(cin, line) && !line.empty()) {
        lines.push_back(line);
    }
    int n = lines.size();
    int m = lines[0].size();
    // vector dp(n, vector(m, 0));
    int ans = 0;
    auto bfs = [&](int x, int y) {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        q.push({x, y});
        int cnt = 0;
        set<pair<int, int>> st;
        st.insert({x, y});
        while(!q.empty()) {
            auto [x, y] = q.front();
            if(lines[x][y] == '9') ++ cnt;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (lines[nx][ny] != lines[x][y] + 1) continue;
                if(st.count({nx, ny})) continue;
                st.insert({nx, ny});
                q.push({nx, ny});
            }
        }
        ans += cnt;
        // debug(x, y, cnt);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lines[i][j] == '0') {
                bfs(i, j);
            }
        }
    }
    return ans;
}

int partTwo() {
    vector<string> lines;
    string line;
    while (getline(cin, line) && !line.empty()) {
        lines.push_back(line);
    }
    int n = lines.size();
    int m = lines[0].size();
    // vector dp(n, vector(m, 0));
    int ans = 0;
    auto bfs = [&](int x, int y) {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        q.push({x, y});
        int cnt = 0;
        while(!q.empty()) {
            auto [x, y] = q.front();
            if(lines[x][y] == '9') ++ cnt;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (lines[nx][ny] != lines[x][y] + 1) continue;
                q.push({nx, ny});
            }
        }
        ans += cnt;
        // debug(x, y, cnt);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lines[i][j] == '0') {
                bfs(i, j);
            }
        }
    }
    return ans;
    return 42;
}


signed main(){
    // cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
