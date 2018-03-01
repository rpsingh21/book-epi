// problem
// Finding closest Integer which have same number of 1
// example 9 = [1001] and 10 = [1010]

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int

using namespace std;

// method - swaping nearest
// i is swap by i+1 IF i and (i+1) not equal

ll closestInteger(ll n){
    int kWordSize = 64;
    for(int i=0; i<(kWordSize-1); i++){
        if( ((n>>i)&1) != ((n>>(i+1))&1) ){
            ll bitMask = (1L<<i)|(1L<<(i+1));
            return n^bitMask;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    cout << closestInteger(n)<<endl;
    return 0;
}

// Time complexity = O(n) where n is number of bit in Integer
