// problem
// Buy and sell stock problem
// Given an array which contain stock n day price. Find profit gain when stock share buy one day and sell another day

#include <bits/stdc++.h>
using namespace std;

// method - follow grade school algo
// In this method also using a bitwise add functions

double maxProfitTwice(const vector<double> prices, int n){
    double min_price_so_for = numeric_limits<double>::max(), max_total_profit = 0;
    std::vector<double> first_max_profit(n,0);
    for(int i=0;i<n;i++){
        min_price_so_for = min(min_price_so_for, prices[i]);
        max_total_profit = max(prices[i]-min_price_so_for, max_total_profit);
        first_max_profit[i] = max_total_profit;
    }
    double max_price_so_for = numeric_limits<double>::min();
    for(int i=n-1;i>0;i--){
        max_price_so_for = max(max_price_so_for, prices[i]);
        max_total_profit = max(max_total_profit, max_price_so_for-prices[i]+first_max_profit[i-1]);
    }
    return max_total_profit;
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
    cout << maxProfitTwice(prices,n)<<endl;
    return 0;
}

// Time complexity = O(n) where n is number of ements
// space complexity = O(1)
