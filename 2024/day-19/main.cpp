#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;
set<string> pattern;
vector<string> words;
#define int long long
void readInput(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    string p;
    while(ss >> p) {
        if(p.back() == ',') p.pop_back();
        pattern.insert(p);
    }
    cin.ignore();
    while(getline(cin, line) && !line.empty()) 
        words.push_back(line);
    
}

int partOne() {
    int n = words.size();
    int ans = 0;

    auto f = [](string word, int l, int r) {
        return word.substr(l, r - l);
    };

    for(auto word: words) {
        int n = word.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            vector<int> t;
            for(int j = i-1; j >= 0; --j) {
                auto k = f(word, j, i);
                if(pattern.count(k))
                    dp[i] |= dp[j];
            }
        }
        ans += dp[n];
    }
    return ans;
}

int partTwo() {
    int n = words.size();
    int ans = 0;

    auto f = [](string word, int l, int r) {
        return word.substr(l, r - l);
    };

    for(auto word: words) {
        int n = word.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            vector<int> t;
            for(int j = i-1; j >= 0; --j) {
                auto k = f(word, j, i);
                if(pattern.count(k))
                    dp[i] += dp[j];
            }
        }
        ans += dp[n];
    }
    return ans;
}


signed main(){
    readInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
