#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;

int mod_add(int a, int b, int m) {
    return (a % m + b % m) % m;
}

int mod_sub(int a, int b, int m) {
    return (a % m - b % m + m) % m;
}

int mod_mul(int a, int b, int m) {
    return (1LL * (a % m) * (b % m)) % m; // Using 1LL to prevent overflow
}

int mod_expo(int a, int b, int m) {
    if (b == 0) return 1;
    int res = mod_expo(a, b / 2, m);
    res = mod_mul(res, res, m);
    if (b & 1) res = mod_mul(res, a, m);
    return res;
}

int mod_inv(int a, int m) {
    return mod_expo(a, m - 2, m); // Using Fermat's Little Theorem
}

int mod_div(int a, int b, int m) {
    return mod_mul(a, mod_inv(b, m), m); // Divide a by b under modulo m
}

int fact[101];

int ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    int denominator = mod_mul(fact[r], fact[n - r], m);
    return mod_div(fact[n], denominator, m); 
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 100; i++) 
        fact[i] = mod_mul(i, fact[i - 1], m);
    
    cout << ncr(5, 2); // Should output 10
    
    return 0;
}
