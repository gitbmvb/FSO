#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main(){
    int N, T, i = 0;
    ull clock = 0;
    cin >> N >> T;
    vector<pair<int, int>> threads (N);
    for(auto& [pid, time]: threads){
        cin >> pid >> time;
        time *= 1000;
    }
    while(!threads.empty()){
        clock += (ull) T;
        if(threads[i].second - T <= 0){
            cout << threads[i].first << " (" << clock << ")\n";
            threads.erase(threads.begin() + i--);
        } else threads[i].second -= T;
        i = (i + 1) % threads.size();
    }
}