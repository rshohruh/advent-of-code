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
    vector<int> nums_l, nums_r;
    int l_next, r_next;
    while(!cin.eof()){
        cin >> l_next >> r_next;
        nums_l.push_back(l_next);
        nums_r.push_back(r_next);
    }
    sort(nums_l.begin(), nums_l.end());
    sort(nums_r.begin(), nums_r.end());
    int n = nums_l.size();
    ll diff = 0;
    for(int i = 0; i < n; ++i){
        diff += abs(nums_l[i] - nums_r[i]);
    }
    cout << diff;
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
