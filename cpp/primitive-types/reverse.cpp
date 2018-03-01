// problem
// taking 64 bit Integer and reverse Integer bits

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int

using namespace std;
const int kWordSize = 16;
const int bitMask = 0xFFFF;

// method - using cache
// we save 16bits number reverse value in array
// divide given number in form of 16 bit
// compair and replace its reverse value

// define vector for storing cache value
std::vector<long> v;

ll swapBits(ll n, int i, int j){
    if( ((n>>i) & 1) != ((n>>j)&1) ){
        ll bitMask = (1L<<i)|(1L<<j);
        n ^= bitMask;
    }
    return n;
}

ll reverse(ll n){
    for(int i=0,j=15;i<j;i++,j--){
        n =swapBits(n,i,j);
    }
    return n;
}

void preComput(){
    for(int i=0;i<(1<<16);i++){
        v.push_back(reverse(i));
    }
}

ll reverse_bits(ll n){
    return v[n&bitMask] <<(3*kWordSize) |
        v[(n>>(kWordSize)) & bitMask] <<(2*kWordSize) |
        v[(n>>(2*kWordSize)) & bitMask] <<kWordSize |
        v[(n>>(3*kWordSize)) & bitMask];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    preComput();
    cin >> n;
    cout << reverse_bits(n) <<endl;
    return 0;
}

// Time complexity = O(n/l) where n is number of bits in Integer and l in length of bitMask
