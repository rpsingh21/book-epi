// Finding parity bit of integer .
// For example
//     7 (111) parity bit = 1
//     8 (1000) parity bit = 1
//     5 (101) parity bit = 0

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

short parity(ll n){
    short result =0;
    while(n){
        result ^= (n & 1); // result XOR last bit of number
        n = n>>1; // right sift
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

// Time complexity = O(n)
