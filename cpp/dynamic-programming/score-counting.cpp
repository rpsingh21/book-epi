// Prolem: cout way to get the score y. It score choise 2,3,7
// Dynamic programing approch
// Time comlexcity o(n*m) scape complexcity o(n*m)

#include <bits/stdc++.h>
using namespace std;

// cout_way function return number of way to achive scores.
int count_way(vector<int> values, int r_s) {
    vector<vector<int>> num_combinations (values.size(), vector<int>(r_s+1, 0));
    for(int i=0;i<values.size(); ++i){
        num_combinations[i][0] = 1;
        for(int j=1; j<=r_s+1; ++j ){
            int without_play = i >= 1 ? num_combinations[i-1][j] : 0;
            int with_play = j >= values[i] ? num_combinations[i][j - values[i]] : 0;
            num_combinations[i][j] = with_play + without_play;
        }
    }
    return num_combinations.back().back();
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