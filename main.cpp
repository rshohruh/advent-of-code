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
        string str1;
        str1 += ind(x-1, y-1);
        str1 += ind(x, y);
        str1 += ind(x+1, y+1);

        string str2;
        str2 += ind(x-1, y+1);
        str2 += ind(x, y);
        str2 += ind(x+1, y-1);

        if ((str1 == "MAS" || str1 == "SAM") && (str2 == "MAS" || str2 == "SAM")) ans++;
    };
    for(int i = 0; i < lines.size(); ++i){
        for(int j = 0; j < lines[i].size(); ++j){
            if(lines[i][j] == 'A'){
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
