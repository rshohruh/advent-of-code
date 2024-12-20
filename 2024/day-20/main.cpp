#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;
vector<vector<int>> grid;
int n, m;
int sx, sy;
int fx, fy;
void readInput(){
    string line;
    int i = 0;
    while(getline(cin, line) && !line.empty()) {
        vector<int> t;
        int j = 0;
        for(char c: line) {
            if(c == 'S'){
                sx = i;
                sy = j;
            } else if(c == 'E') {
                fx = i;
                fy = j;
            }
            t.push_back((c == '#' ? 1 : 0));
            ++j;
        }
        ++i;
        grid.push_back(t);
    }
    n = grid.size();
    m = n;
}

int partOne() {
    map<pair<int, int>, int> mp;
    queue<pair<int, int>> b;
    auto add = [&](int x, int y, int k) {
        if(min(x, y) < 0 || max(x,y) >= n || grid[x][y] || mp.count({x, y})) return;
        mp[{x, y}] = k;
        b.emplace(x, y);
    };
    add(sx, sy, 0);
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    while(!b.empty()) {
        auto [x, y] = b.front();
        b.pop();
        int k = mp[{x, y}];
        for(int q = 0; q < 4; ++q) {
            add(x+dx[q], y+dy[q], k+1);
        }
    }
    int ans = 0;
    for(auto [point, k]: mp) {
        auto [x, y] = point;
        for(int q = 0; q < 4; ++q){
            if(!mp.count({x + dx[q], y + dy[q]}) 
                && mp.count({x + 2*dx[q], y + 2*dy[q]}) 
                && mp[{x + 2*dx[q], y + 2*dy[q]}] - mp[{x, y}] >= 102) ++ans;
        }
    }
    return ans;
}

int partTwo() {
    map<pair<int, int>, int> mp;
    queue<pair<int, int>> b;
    auto add = [&](int x, int y, int k) {
        if(min(x, y) < 0 || max(x,y) >= n || grid[x][y] || mp.count({x, y})) return;
        mp[{x, y}] = k;
        b.emplace(x, y);
    };
    add(sx, sy, 0);
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    while(!b.empty()) {
        auto [x, y] = b.front();
        b.pop();
        int k = mp[{x, y}];
        for(int q = 0; q < 4; ++q) {
            add(x+dx[q], y+dy[q], k+1);
        }
    }

    auto points = [&](int x, int y){
        set<pair<int, int>> st;
        for(int i = -20; i <= 20; ++i){
            for(int j = -20; j <= 20; ++j) {
                if(abs(i) + abs(j) > 20) continue;
                if(mp.count({x+i, y+j})) 
                    st.insert({x+i, y+j});
            }
        }
        return st;
    };
    int ans = 0;
    for(auto [point, k]: mp) {
        auto [x, y] = point;
        auto p = points(x, y);
        for(auto [newx, newy]: p) {
            auto k = abs(newx - x) + abs(newy - y);
            if(mp[{newx, newy}] - mp[{x, y}] - k >= 100) ++ans;
        }
    }
    return ans;
}


signed main(){
    readInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
