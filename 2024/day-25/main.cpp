#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

vector<vector<int>> keys, locks;

void readInput(){
    string line;
    vector<string> temp;
    auto count = [&](vector<string> item) {
        vector<int> t(5);
        for(int j = 0; j < 5; ++j) {
            for(int i = 0; i < 6; ++i) {
                t[j] += item[i][j] == '#';
            }
        }
        return t;
    };
    while(getline(cin, line)) {
        if(!line.empty()) {
            temp.push_back(line);
        } else {
            vector t = count(temp);
            if(temp[0] == ".....")
                locks.push_back(t);
            else
                keys.push_back(t);
            
            temp.clear();
        }
    }
    debug(keys);
    debug(locks);
}

int partOne() {
    int ans = 0;
    for(auto key: keys) {
        for(auto lock: locks) {
            int ok = 1;
            for(int i = 0; i < 5; ++i){
                ok &= (key[i] + lock[i] <= 6);
            }
            ans += ok;
        }
    }
    return ans;
}

int partTwo() {

    return 42;
}


signed main(){
    readInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
