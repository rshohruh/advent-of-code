// author: rshohruh

#include <algorithm>
#include <cstdio>
#include <sstream>
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

int mat[100][100];
void t_main(){
    string line;
    while(getline(cin, line) && !line.empty()){
        int a, b;
        sscanf(line.c_str(), "%d|%d", &a, &b);
        mat[a][b] = 1;
    }
    int ans = 0;
    while(getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int x;
        vector<int> nums;
        char ignore;
        while(ss >> x) {
            ss >> ignore;
            nums.push_back(x);
        }

        int count_swap = 0;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(mat[nums[i]][nums[j]]){
                    count_swap ++;
                    swap(nums[i], nums[j]);
                }
            }
        }
        if(count_swap == 0) ans += nums[nums.size()/2];
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
