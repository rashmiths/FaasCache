#include<bits/stdc++.h>

using namespace std;

int calc_reuse_distance(vector<int> sequence) {
    map<int, bool> functions;
    for(auto function : sequence) {
        functions[function] = true;
    }

    int dist = 0;

    for(auto function : functions) {
        int prev = 0;
        for(auto it : sequence) {
            if(it == function.first) {
                dist += it - prev;
                prev = it;
            }
        }
    }
    return dist;
}