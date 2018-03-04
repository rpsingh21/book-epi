// problem
// Buy and sell stock problem
// Given an array which contain stock n day price. Find profit gain when stock share buy one day and sell another day

#include <bits/stdc++.h>
using namespace std;

// method - follow grade school algo
// In this method also using a bitwise add functions

double maxProfit(const vector<double> prices, int n){
    double minPrice = numeric_limits<double>::max(), max_profit = 0;
    for(int i=0;i<n;i++){
        max_profit = max(prices[i]-minPrice, max_profit);
        minPrice = min(minPrice, prices[i]);
    }
    return max_profit;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<double> prices;
    double temp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        prices.push_back(temp);
    }
    cout << maxProfit(prices,n)<<endl;
    return 0;
}

// Time complexity = O(n) where n is number of ements
// space complexity = O(1)
