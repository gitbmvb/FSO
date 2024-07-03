#include <bits/stdc++.h>
using namespace std;

int find_min_counter(vector<int>& memory, vector<int>& time, int present_time){
    int ref = 0;
    for(int i = 1; i < memory.size(); i++)
        if ((present_time - time[memory[i]]) > (present_time - time[memory[ref]])) ref = i;
    return ref;
}

int main(void){
    int q, n, aux, page_faults = 0, used = 0;
    int clock = 0;
    cin >> q >> n;
    vector<int> memory (q, -1), time (1000001, 0);
    bitset<100001> isInMemory;
    isInMemory.reset();
    while(n--){
        cin >> aux;
        time[aux] = clock;
        if(not isInMemory[aux]){
            page_faults++;
            if(used < q){
                memory[used++] = aux;
                isInMemory[aux] = true;
            }
            else{
                int index = find_min_counter(memory, time, clock);
                isInMemory[memory[index]] = false;
                isInMemory[aux] = true;
                memory[index] = aux;
            }
        }
        clock++;
    }
    cout << page_faults << '\n';
}