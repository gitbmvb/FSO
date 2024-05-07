#include <bits/stdc++.h>
using namespace std;
using item = pair<int, int>;
int main(void){
    int N, T;
    cin >> N >> T;
    unsigned long long clock = 0, amount = (unsigned long long) T;
    vector<item> threads (N);
    for(auto& [pid, time]: threads){
        cin >> pid >> time;
        time *= 1000;
    }
    while(!threads.empty()){
        clock += amount;
        auto& [threadpid, threadtime] = threads[0];
        if(threadtime > T) threads.emplace_back((item){threadpid, threadtime - T});
        else cout << threadpid << " (" << clock << ")\n";
        threads.erase(threads.begin());
    }
}