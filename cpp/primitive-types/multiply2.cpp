// problem
// Multiply two number without using * operator

#include <bits/stdc++.h>

using namespace std;

unsigned long Multiply(unsigned long x, unsigned long y){
    unsigned long res = 0;
    while(y > 0){
        if(y & 1)
            res += x;
        x <<= 1,y >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long n,m;
    cin >> n >> m;
    cout << Multiply(n,m)<<endl;
    return 0;
}

// Time complexity = O(n*n) where n is number of bit in Integer
