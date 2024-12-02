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
    int ans = 0;
    string line;
    while(getline(cin, line) && !line.empty()){
        stringstream ss(line);
        vector<int> v;
        int num;
        int mn_dif = INT_MAX, mx_dif = INT_MIN;
        while(ss >> num){
            v.push_back(num);
        }
        for(int i = 1; i < v.size(); ++i){
            mn_dif = min(mn_dif, v[i] - v[i-1]);
            mx_dif = max(mx_dif, v[i] - v[i-1]);
        }
        if(mn_dif < 0) {
            swap(mn_dif, mx_dif);
            mn_dif = mn_dif;
            mx_dif = mx_dif;
        }
        if(mn_dif >= 1 && mx_dif <= 3 && mn_dif <= mx_dif) ans++;
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
