#include <bits/stdc++.h>
#include <sstream>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

int partOne() {
    string line;
    int ans = 0;
    while(getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        debug(line);
        long long res; cin >> res;
        char c; cin >> c;
        vector<int> nums;
        int num;
        while(ss >> num) {
            nums.push_back(num);
        }

        auto calc = [&](int bit) {
            long long ans = nums[0];
            for(int i = 1; i < nums.size(); ++i, bit >>= 1) {
                if(bit & 1) {
                    ans += nums[i];
                } else {
                    ans *= nums[i];
                }
            }
            return ans;
        };
        for(int bit = 0; bit < (1<<(nums.size()-1)); ++bit){
            if(calc(bit) == res) {
                ans += res;
                // debug(line);
                break;
            }
        }
    }
    return ans;
}

int partTwo() {

    return 42;
}


signed main(){
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
