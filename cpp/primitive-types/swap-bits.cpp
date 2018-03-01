// problem
// swap i and j th bit in Integer n

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int

using namespace std;

// method - compair i and j bit in Integer
//      if both are same no need to chane
//      else n XOR with bitMask which is created by bit positions
//      i bit = (n>>i)&1 -- keypoint

ll swapBits(ll n, int i, int j){
    if( ((n>>i) & 1) != ((n>>j)&1) ){
        ull bitMask = (1L<<i)|(1L<<j);
        n ^= bitMask;
    }
    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    int i,j;
    cin >> n>>i>>j;
    cout << swapBits(n,i,j) <<endl;
    return 0;
}

// Time complexity = O(1)
