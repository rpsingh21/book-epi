// problem
// Finding parity bit of integer .
// For example
//     7 (111) parity bit = 1
//     8 (1000) parity bit = 1
//     5 (101) parity bit = 0

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int

using namespace std;

// method - using precomputed chache
// precomputed parity

short pp[65536]; // precomputed parity array to store value
const int kWordSize = 16;
const int bitMask = 0xffff;

void precomputed(){
    for(ll i = 0;i<=bitMask; i++){
        pp[i] = 0;
        ll n = i;
        while(n){
            pp[i] ^= 1;
            n &= (n-1); // droping lsb
        }
    }
}

short parity(ull n){
    return pp[n >> (3*kWordSize)] ^ pp[(n>>(2*kWordSize)) & bitMask] ^ pp[(n>>(3*kWordSize)&bitMask)] ^ pp[n&bitMask];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputed();
    ull n;
    cin >> n;
    cout << parity(n) <<endl;
    return 0;
}

// Time complexity = O(n/L) where n is number L is bitMask size
