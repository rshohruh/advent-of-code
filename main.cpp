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
        vector<int> nums;
        int num;
        while(ss >> num){
            nums.push_back(num);
        }
        int ok = 0;
        for(int t = 0; t < nums.size(); ++t){
            int mn_dif = INT_MAX, mx_dif = INT_MIN;
            int elem = nums[t];
            nums.erase(nums.begin() + t);
            for(int i = 1; i < nums.size(); ++i){
                mn_dif = min(mn_dif, nums[i] - nums[i-1]);
                mx_dif = max(mx_dif, nums[i] - nums[i-1]);
            }
            if(mn_dif < 0) {
                swap(mn_dif, mx_dif);
                mn_dif = -mn_dif;
                mx_dif = -mx_dif;
            }
            if(mn_dif >= 1 && mx_dif <= 3 && mn_dif <= mx_dif) ok |= 1;

            nums.insert(nums.begin() + t, elem);
        }
        ans += ok;
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
