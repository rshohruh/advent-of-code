#include <bits/stdc++.h>

#ifdef LOCAL
    #include "/home/rshohruh/debug.hpp"
#else
    #define debug(...) 42
#endif
using namespace std;
long long partOne() {
    string line;
    vector<string> lines;
    while (getline(cin, line)) {
        lines.push_back(line);
    }
    long long ans = 0;
    for(int i = 0; i < lines.size(); i += 4){
        long long ax, ay, bx, by, x, y;
        sscanf(lines[i].c_str(), "Button A: X+%lld, Y+%lld", &ax, &ay);
        sscanf(lines[i+1].c_str(), "Button B: X+%lld, Y+%lld", &bx, &by);
        sscanf(lines[i+2].c_str(), "Prize: X=%lld, Y=%lld", &x, &y);
        // x += 10000000000000;
        // y += 10000000000000;
        // debug(ax, ay, bx, by, x, y);
        if((x * ay - y * ax) % (bx * ay - by * ax)) continue;
        long long b = (x * ay - y * ax) / (bx * ay - by * ax);
        if(b < 0) continue;
        if((x - b * bx) % ax) continue;
        long long a = (x - b * bx) / ax;
        if(a < 0) continue;
        ans += a * 3 + b;
    }
    return ans;
}

long long partTwo() {
    string line;
    vector<string> lines;
    while (getline(cin, line)) {
        lines.push_back(line);
    }
    long long ans = 0;
    for(int i = 0; i < lines.size(); i += 4){
        long long ax, ay, bx, by, x, y;
        sscanf(lines[i].c_str(), "Button A: X+%lld, Y+%lld", &ax, &ay);
        sscanf(lines[i+1].c_str(), "Button B: X+%lld, Y+%lld", &bx, &by);
        sscanf(lines[i+2].c_str(), "Prize: X=%lld, Y=%lld", &x, &y);
        x += 10000000000000;
        y += 10000000000000;
        // debug(ax, ay, bx, by, x, y);
        if((x * ay - y * ax) % (bx * ay - by * ax)) continue;
        long long b = (x * ay - y * ax) / (bx * ay - by * ax);
        if(b < 0) continue;
        if((x - b * bx) % ax) continue;
        long long a = (x - b * bx) / ax;
        if(a < 0) continue;
        ans += a * 3 + b;
    }
    return ans;
}


signed main(){
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
}


/*
a * ax + b * bx = x
a * ay + b * by = y

a * ax * ay + b * bx * ay = x * ay
a * ay * ax + b * by * ax = y * ax

b * bx * ay - b * by * ax = x * ay - y * ax
b * (bx * ay - by * ax) = x * ay - y * ax

b = (x * ay - y * ax) / (bx * ay - by * ax)
*/
