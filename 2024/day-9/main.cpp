#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

long long partOne() {
    vector<int> spaces(1e6, -1);
    queue<int> free;
    string line; cin >> line;
    for(int i = 0, j = 0; i < line.size(); ++i){
        int num = line[i] - '0';
        for(int k = 0; k < num; ++k){
            if(i & 1) free.push(j++);
            else spaces[j++] = i / 2;
        }
    }
    for(int i = spaces.size()-1; i >= 0; --i){
        if(spaces[i] != -1 && !free.empty() && free.front() < i){
            spaces[free.front()] = spaces[i];
            free.pop();
            spaces[i] = -1;
        }
    }
    long long ans = 0;
    for(int i = 0; i < spaces.size(); ++i){
        if(spaces[i] != -1) ans += spaces[i] * i;
    }
    return ans;
}

long long partTwo() {
    string line; cin >> line;
    vector free(10, priority_queue<int, vector<int>, greater<>>());
    vector<pair<int, int>> blocks(1e6, {-1, -1});
    for(int i = 0, j = 0; i < line.size(); ++i){
        int num = line[i] - '0';
        if(i & 1){
            free[num].push(j);
        } else {
            blocks[j] = {num, i/2};
        }
        j += num;
    }
    for(int i = blocks.size()-1; i >= 0;  --i){
        if(blocks[i] == make_pair(-1, -1)) continue;
        auto [num, id] = blocks[i];
        // debug(i, blocks[i]);
        int start_id = 1e9, cnt_free = 0;
        for(int k = num; k <= 9; ++k){
            if(!free[k].empty() && free[k].top() < start_id){
                start_id = free[k].top();
                cnt_free = k;
            }
        }
        // debug(cnt_free, start_id);
        if(start_id < i) {
            blocks[start_id] = blocks[i];
            // debug(start_id, blocks[start_id]);
            blocks[i] = {-1, -1};
            free[cnt_free].pop();
            free[cnt_free - num].push(start_id + num);
            // debug(cnt_free - num, free[cnt_free-num].top());
        }
    }
    long long ans = 0;
    for(int i = 0; i < blocks.size(); ++i){
        if(blocks[i] == make_pair(-1, -1)) continue;
        // debug(i, blocks[i]);
        auto [num, id] = blocks[i];
        for(int k = 0; k < num; ++k) ans += (i+k) * id;
    }
    return ans;
    // return 42;
}


signed main(){
    // cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
