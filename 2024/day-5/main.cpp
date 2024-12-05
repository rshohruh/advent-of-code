#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

int mat[100][100];
int partOne(){
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
    return ans;
}

int partTwo(){
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
        if(count_swap > 0) ans += nums[nums.size()/2];
    }
    return ans;
}

int main() {
    cout << "Part One: " << partOne() << endl;
    // cout << "Part Two: " << partTwo() << endl;
}
