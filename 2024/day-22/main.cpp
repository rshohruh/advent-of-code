#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;
using ll = long long;
vector<int> nums;
void readInput(){
    int num;
    while(cin >> num)
        nums.push_back(num);
}

int f(ll num) {
    ll original_num = num;

    num *= 64;
    num ^= original_num;
    num %= 16777216;

    original_num = num;
    num /= 32;
    num ^= original_num;
    num %= 16777216;

    original_num = num;
    num *= 2048;
    num ^= original_num;
    num %= 16777216;

    return num;
}

ll partOne() {
    ll ans = 0;
    for(int num: nums) {
        for(int i = 0; i < 2000; ++i)
            num = f(num);
        ans += num;
    }
    return ans;
}

int partTwo() {
    map<vector<int>, int> mp;

    for (int num : nums) {
        map<vector<int>, int> dic;
        vector<int> temp;

        for (int i = 0; i < 2000; ++i) {
            int x = num;
            num = f(num);

            temp.push_back(num % 10 - x % 10);

            if (temp.size() > 4) 
                temp.erase(temp.begin());

            if (temp.size() == 4 && dic.find(temp) == dic.end()) 
                dic[temp] = num % 10;
        }

        for (const auto& [key, value] : dic) {
            mp[key] += value;
        }
    }

    int result = 0;
    for (const auto& [key, value] : mp) {
        result = max(result, value);
    }
    return result;
}


signed main(){
    readInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
