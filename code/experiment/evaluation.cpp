#include <bits/stdc++.h>
#include <greedy_dual_policy.h>
#include <ttl.h>
#include <lru.h>
#include <reuse_distance.h>

using namespace std;

int main() {
    vector<int> server_sizes{20,40,60,80,100, 120};
    vector<int> seeds{1, 1000};
    int batches = 7;    
    vector<int> sequence;
    vector<int> ttl_results, lru_results, gdsp;
    for(auto size : server_sizes) {
        for(auto seed : seeds) {
            ttl_results.push_back(run_ttl(size, seed));
            gdsp_results.push_back(run_gdsp(size, seed));
            lru_results.push_back(run_lru(size, seed));
        }

        
    }
    for(int i = 0; i < sequence_size; i++) {
        cin>>sequence[i];
    }

    int dist = calc_reuse_distance(sequence);

    /*
    Output results for plotting
    */
    for(int i = 0; i < batches; i++) {
        cout<<ttl_results[i] << " " << dist[i]<< " " << server_sizes[i];
        cout<<lru_results[i] << " " << dist[i]<< " " << server_sizes[i];
        cout<<gdsp_results[i] << " " << dist[i]<< " " << server_sizes[i];
    }
}