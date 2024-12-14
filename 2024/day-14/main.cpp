#include <bits/stdc++.h>
#include <numeric>
#include <string>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

vector<tuple<int, int, int, int>> vec;
void pre(){
    string s;
    while(getline(cin, s) && !s.empty()){
        int sx, sy, vx, vy;
        sscanf(s.c_str(), "p=%d,%d v=%d,%d", &sx, &sy, &vx, &vy);
        vec.emplace_back(sx, sy, vx, vy);
    }
};

int partOne() {
    string s;
    int ans = 0;
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
    for(auto [sx, sy, vx, vy]: vec) {
        sx += vx * 100;
        sy += vy * 100;
        sx = (sx % 101 + 101) % 101;
        sy = (sy % 103 + 103) % 103;

        if(sx < 50 && sy < 51) ++d1;
        else if(sx > 50 && sy < 51) ++d2;
        else if(sx < 50 && sy > 51) ++d3;
        else if(sx > 50 && sy > 51) ++d4;
    }
    return d1 * d2 * d3 * d4;
}

int partTwo(int k) {
    vector tree(103, vector(101, 0));
    for(auto [sx, sy, vx, vy]: vec) {
        sx += vx * k;
        sy += vy * k;
        sx = (sx % 101 + 101) % 101;
        sy = (sy % 103 + 103) % 103;
        tree[sy][sx] = 1;
    }
    int ok = 0;
    for(auto arr: tree)
        if(accumulate(arr.begin(), arr.end(), 0) > 30){
            ok = 1;
            break;
        }
    if(ok) {
        debug(k);
        for(auto x: tree){
            for(auto y: x){
                cout << y;
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 42;
}


signed main(){
    pre();
    cout << "Part 1: " << partOne() << endl;
    // cout << "Part 2: " << partTwo() << endl;
    for(int i = 1; i < 10000; ++i){
        partTwo(i);
    }
}
