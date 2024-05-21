#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned int n, t, clock = 0, aux = 0;
    cin >> n >> t;
    vector<pair<int, int>> threads (n);
    for(auto& [pid, time]: threads){
        cin >> pid >> time;
        time *= 1000;
    }
    while(n){
        auto& [pid, time] = threads[aux];
        time -= t;
        clock += t;
        if(time <= 0){
            clock += time;
            cout << pid << " (" << clock << ")\n";
            threads.erase(threads.begin() + aux);
            n--;
            if(aux >= n) aux = 0;
        } else if(++aux == n){
            aux = 0;
        } 
    }
    return 0;
}