#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;
int n, k;
vector<pair<int, int>> points;

void readInput(){
    n = 71;
    k = 1024;
    string line;
    while(getline(cin, line) && !line.empty()) {
        int x, y;
        sscanf(line.c_str() ,"%d,%d", &x, &y);
        points.emplace_back(y, x);
    }
}

int partOne() {
    vector grid(n, vector(n, 0));
    for(int i = 0; i < k; ++i)
        grid[points[i].first][points[i].second] = 1;
    
    queue<pair<int, int>> b;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    vector vis(n, vector(n, (int) 1e9));
    auto add = [&](int x, int y, int z) {
        if(max(x, y) >= n || min(x, y) < 0 || vis[x][y] <= z || grid[x][y]) return;
        vis[x][y] = z;
        b.emplace(x, y);
    };
    add(0, 0, 0);
    while(!b.empty()) {
        auto [x, y] = b.front();
        b.pop();
        int w = vis[x][y];
        for(int i = 0; i < 4; ++i) {
            add(x + dx[i], y + dy[i], w + 1);
        }
    }
    return vis[n-1][n-1];
}

string partTwo() {
    int l = 0, r = points.size()-1;
    while(l < r) {
        int m = (l + r + 1) / 2;
        vector grid(n, vector(n, 0));
        for(int i = 0; i <= m; ++i)
            grid[points[i].first][points[i].second] = 1;
    
        queue<pair<int, int>> b;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        vector vis(n, vector(n, (int) 1e9));
        int q = 0;
        auto add = [&](int x, int y, int z) {
            if(max(x, y) >= n || min(x, y) < 0 || vis[x][y] <= z || grid[x][y]) return;
            vis[x][y] = z;
            b.emplace(x, y);
        };
        add(0, 0, 0);
        while(!b.empty()) {
            auto [x, y] = b.front();
            b.pop();
            int w = vis[x][y];
            for(int i = 0; i < 4; ++i) {
                add(x + dx[i], y + dy[i], w + 1);
            }
        }
        if(vis[n-1][n-1] < 1e9) l = m;
        else r = m-1;
    }
    return to_string(points[l+1].second) + "," + to_string(points[l+1].first);
}


signed main(){
    readInput();
    // cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
