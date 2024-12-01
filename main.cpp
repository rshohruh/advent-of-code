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
    vector<int> nums_l;
    map<int, int> nums_r;
    int l_next, r_next;
    while(!cin.eof()){
        cin >> l_next >> r_next;
        nums_l.push_back(l_next);
        nums_r[r_next] ++;
    }
    ll similarity = 0;
    for(int num: nums_l){
        similarity += num * nums_r[num];
    }
    cout << similarity;
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
