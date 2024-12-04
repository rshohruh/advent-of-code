// author: rshohruh

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;
#define ll long long

// #define with_testcases

void t_main(){

    string line;
    vector<string> lines;
    while(getline(cin, line) && !line.empty()){
        lines.push_back(line);
    }
    int ans = 0;

    auto ind = [&](int i, int j){
        if(i >= lines.size() || j >= lines[0].size() || i < 0 || j < 0) return ' ';
        return lines[i][j];
    };
    auto run = [&](int x, int y) -> void {
        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

        for(int q = 0; q < 8; ++q){
            string s;
            int xx = x, yy = y;
            for(int i = 0; i < 4; ++i){
                s += lines[xx][yy];
                xx += dx[q];
                yy += dy[q];
                if(xx >= lines.size() || yy >= lines[0].size() || xx < 0 || yy < 0){
                    break;
                }
            }
            if(s == "XMAS") ++ ans;
        }
    };
    for(int i = 0; i < lines.size(); ++i){
        for(int j = 0; j < lines[i].size(); ++j){
            if(lines[i][j] == 'X'){
                run(i, j);
            }
        }
    }

    cout << ans;
}

signed main(){
    signed t = 1;
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef with_testcases
        cin >> t;
    #endif
    while(t--){
        t_main();
        cout << '\n';
    }
    return 0;
}
