#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll MOD = 1000000000 + 7;

int* hello(){
    int y = 10;
    int* a = &y;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int* b = hello;

    cout << b << '\n';

    return 0;
}
