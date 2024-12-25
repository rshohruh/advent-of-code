#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;

map<string, int> variables;
queue<tuple<string, string, string, string>> operations;

void readInput() {
    string line;
    while (getline(cin, line) && !line.empty()) {
        int value = line.back() - '0';
        string key = line.substr(0, 3);
        variables[key] = value;
    }
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string op1, op, op2, arrow, result;

        ss >> op1 >> op >> op2 >> arrow >> result;
        operations.push({op1, op, op2, result});
    }

    while(!operations.empty()) {
        auto [op1, op, op2, result] = operations.front();
        operations.pop();
        if(variables.count(op1) && variables.count(op2)) {
            if(op == "OR") variables[result] = variables[op1] | variables[op2];
            else if(op == "AND") variables[result] = variables[op1] & variables[op2];
            else if(op == "XOR") variables[result] = variables[op1] ^ variables[op2];
            // debug(result, variables[result]);
        } else {
            operations.push({op1, op, op2, result});
        }
    }

}

long long partOne() {
    
    long long ans = 0;
    vector<long long> t;
    for(auto [variable, result]: variables)
        if(variable[0] == 'z') 
            t.push_back(result);
    debug(t);
    for(int i = 0; i < t.size(); ++i) {
        ans += t[i] * (1ll<<i);
        debug(ans);
    }
    
    return ans;
}

int partTwo() {
    return 42;
}

signed main() {
    readInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}
