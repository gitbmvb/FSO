#include <bits/stdc++.h>
using namespace std;
using item = pair<int, int>;
using ull = unsigned long long;
int main(void){
    int N, T, clock = 0;
    cin >> N >> T;
    vector<item> threads (N);
    for(auto& [pid, time]: threads){
        cin >> pid >> time;
        time = (time * 1000)/T;
    }
    sort(threads.begin(), threads.end(), [](item& A, item& B){
        return A.second < B.second;
    });
    for(auto& [tpid, ttime]: threads){
        clock += ttime * T;
        cout << tpid << " " << clock << endl;
    }
}