// Prolem: cout way to get the score y. It score choise 2,3,7
// Dynamic programing approch
// Time comlexcity o(n*m) scape complexcity o(n*m)

#include <bits/stdc++.h>
using namespace std;

// cout_way function return number of way to achive scores.
int count_way(vector<int> values, int r_s) {
    vector<int> ways (r_s+1, 0);
    ways[0] = 1;
    for(int i=0; i<values.size(); i++){
        for(int j=values[i]; j<r_s+1; j++){
            ways[j] += ways[j-values[i]];
        }
    }
    return ways.back();
}

int main(){
    vector<int> values = {2,3,7};
    int required_score = 12;
    cout << count_way(values, required_score) << endl;
}

/* 
input 
12
output
4
*/