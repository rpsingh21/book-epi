// problem
// Multiply two number without using arithmetical operator

#include <bits/stdc++.h>

using namespace std;

// method - follow grade school algo
// In this method also using a bitwise add functions

unsigned ADD(unsigned x, unsigned y){
    unsigned sum = 0, c_in = 0, k = 1, temp_x = x, temp_y = y;
    while (temp_x || temp_y) {
        unsigned ak = x & k, bk = y &k;
        unsigned c_out = (ak & bk) | (ak & c_in) | (bk & c_in);
        sum |= (ak^ bk^ c_in);
        c_in = c_out<<1, k<<=1,temp_x >>= 1,temp_y >>= 1;
    }
    return sum | c_in;
}

unsigned Multiply(unsigned x, unsigned y){
    unsigned sum = 0;
    while(x){
        if(x & 1){
            sum = ADD(sum, y);
        }
        x >>= 1,y <<= 1;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int n,m;
    cin >> n >> m;
    cout << Multiply(n,m)<<endl;
    return 0;
}

// Time complexity = O(n*n) where n is number of bit in Integer
