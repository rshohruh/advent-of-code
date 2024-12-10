#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

int partOne() {
    string line;
    vector<string> mat;
    while (getline(cin, line) && !line.empty()) {
        mat.push_back(line);
    }
    int n = mat.size();
    int m = mat[0].size();

    auto find_guard = [&](){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == '^'){
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    };
    auto [x, y] = find_guard();
    int dx = -1, dy = 0;
    while(true) {
        // cout << x << ' ' << y << endl;
        if(x < 0 || x >= n || y < 0 || y >= m) break;
        if(mat[x][y] == '#'){
            x -= dx;
            y -= dy;
            dx *= -1;
            swap(dx, dy);
        } else {
            mat[x][y] = 'X';
        }
        x += dx;
        y += dy;
    }
    int ans = 0;
    for(string line: mat){
        ans += count(line.begin(), line.end(), 'X');
        // cout << line << '\n';
    }
    cout << n << ' ' << m << endl;
    return ans;
}

int partTwo() {
    string line;
    vector<string> mat;
    while (getline(cin, line) && !line.empty()) {
        mat.push_back(line);
    }
    int n = mat.size();
    int m = mat[0].size();

    auto find_guard = [&](){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == '^'){
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    };
    auto [x, y] = find_guard();
    int dx = -1, dy = 0;
    int sx = x, sy = y;
    auto has_circle = [&](int x, int y, int dx, int dy) {
        if(x + dx >= n || x + dx < 0 || y + dy >= m || y + dy < 0) return false;
        if(x + dx == sx && y + dy == sy) return false;
        if(mat[x + dx][y + dy] == '#') return false;
        char t = mat[x + dx][y + dy];
        mat[x + dx][y + dy] = '#';
        int X = x + dx, Y = y + dy;
        int cnt = 0;
        while(cnt < 4) {
            if(x < 0 || x >= n || y < 0 || y >= m){
                mat[X][Y] = t;
                return false;
            }
            if(mat[x][y] == '#'){
                x -= dx;
                y -= dy;
                dx *= -1;
                swap(dx, dy);
                ++cnt;
            } else {
                mat[x][y] = 'X';
            }
            x += dx;
            y += dy;
        }

    };

    while(true) {
        // cout << x << ' ' << y << endl;
        if(x < 0 || x >= n || y < 0 || y >= m) break;
        if(mat[x][y] == '#'){
            x -= dx;
            y -= dy;
            dx *= -1;
            swap(dx, dy);
        } else {
            mat[x][y] = 'X';
        }
        x += dx;
        y += dy;
    }
}


signed main(){
    // cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
