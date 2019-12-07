// Prolem: find levenshtein distance
// Dynamic programing approch
// Time comlexcity o(ab) scape complexcity o(ab)
// a, b is lenght of word a and word b

#include <bits/stdc++.h>
using namespace std;

int compute_dictance(string a, int a_in, string b, int b_in,vector<vector<int>> *c_distance) {
    vector<vector<int>>& distance = *c_distance;
    if(a_in < 0){
        return b_in + 1;
    }
    else if(b_in < 0){
        return a_in + 1;
    }
    if(distance[a_in][b_in] == -1){
        if(a[a_in] == b[b_in]){
            distance[a_in][b_in] = compute_dictance(a, a_in-1, b, b_in-1, c_distance);
        } else {
            int sub_last = compute_dictance(a, a_in-1, b, b_in-1, c_distance);
            int add_last = compute_dictance(a, a_in-1, b, b_in, c_distance);
            int del_last = compute_dictance(a, a_in, b, b_in-1, c_distance);
            distance[a_in][b_in] = 1 + min({sub_last, add_last, del_last});
        }
    }
    return distance[a_in][b_in];
}

int levenshtein_distance(string A, string B){
    vector<vector<int>> distance (A.size(), vector<int>(B.size(), -1));
    return compute_dictance(A, A.size()-1, B, B.size()-1, &distance);
}

int main(){
    string word1="carthorse", word2="orchestra";
    cout << levenshtein_distance(word1, word2) << endl;
    return 0;
}

/*
input: word1="carthorse", word2="orchestra"
output: 8
*/
