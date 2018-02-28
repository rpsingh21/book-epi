// Finding parity bit of integer .
// For example
//     7 (111) parity bit = 1
//     8 (1000) parity bit = 1
//     5 (101) parity bit = 0

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// method - Droping lowest set bit (LSB) of n
// droping lsb by n & (n-1)

short parity(ll n){
    short result =0;
    while(n){
        result ^= 1; // chage result value on each set bit
        n &= (n-1); // drop LSB and get new n
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    cout << parity(n) <<endl;
    return 0;
}

// Time complexity = O(k) where k is number of set bit in gitven integer
