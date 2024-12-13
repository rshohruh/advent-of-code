#include <bits/stdc++.h>
#include <vector>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

int partOne() {
    vector<string> lines;
    string line;
    while(getline(cin, line) && !line.empty())
        lines.push_back(line);
    int n = lines.size();
    int m = lines[0].size();
    vector vis(n, vector(m, 0));
    int ans = 0;
    auto bfs = [&](int x, int y) {
        char st = lines[x][y];
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> b;
        int per = 0; // perimeter
        int area = 0; // area
        vector borders(4, set<pair<int, int>>());
        auto add = [&](int x, int y, int d) {
            if(x < 0 || x >= n || y < 0 || y >= m || lines[x][y] != st) {
                per ++;
                return;
            }
            if(vis[x][y]) return;
            vis[x][y] = 1;
            area++;
            b.push({x, y});
        };
        add(x, y, -1);
        while(!b.empty()) {
            auto [x, y] = b.front();
            b.pop();
            for(int i = 0; i < 4; i++) {
                add(x + dx[i], y + dy[i], i);
            }
        }
        ans += area * per;

    };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            bfs(i, j);
        }
    }
    return ans;
}

int partTwo() {
    vector<string> lines;
    string line;
    while(getline(cin, line) && !line.empty())
        lines.push_back(line);
    int n = lines.size();
    int m = lines[0].size();
    vector vis(n, vector(m, 0));
    int ans = 0;
    auto bfs = [&](int x, int y) {
        char st = lines[x][y];
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> b;
        int per = 0; // perimeter
        int area = 0; // area
        vector borders(4, set<pair<int, int>>());
        auto add = [&](int x, int y, int d) {
            if(x < 0 || x >= n || y < 0 || y >= m || lines[x][y] != st) {
                borders[d].insert({x, y});
                return;
            }
            if(vis[x][y]) return;
            vis[x][y] = 1;
            area++;
            b.push({x, y});
        };
        add(x, y, -1);
        while(!b.empty()) {
            auto [x, y] = b.front();
            b.pop();
            for(int i = 0; i < 4; i++) {
                add(x + dx[i], y + dy[i], i);
            }
        }
        // ans += area * per;
        int sides = 0;
        for(auto st: borders) {
            set<pair<int, int>> temp;
            for(auto [x, y]: st) {
                bool ok = 1;
                for(int q = 0; q < 4; ++q){
                    if(temp.count({x+dx[q], y+dy[q]})) ok = 0;
                }
                sides += ok;
                temp.insert({x, y});
            }
        }
        ans += area * sides;
    };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            bfs(i, j);
        }
    }
    return ans;
}


signed main(){
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
