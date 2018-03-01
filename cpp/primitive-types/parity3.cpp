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

// method - using xor associative and commutative property

short parity(ull n){
    n ^= n>>32;
    n ^= n>>16;
    n ^= n>>8;
    n ^= n>>4;
    n ^= n>>2;
    n ^= n>>1;
    return n & 0x1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n;
    cin >> n;
    cout << parity(n) <<endl;
    return 0;
}

// Time complexity = O(log(n)) where n is Integer
