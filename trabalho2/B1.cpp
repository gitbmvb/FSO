#include <bits/stdc++.h>
using namespace std;

int main(void){
    int q, n, aux, indexPointer = 0, pageFaults = 0;
    cin >> q >> n;
    vector<int> memory (q, -1);
    vector<bool> isInMemory(q + 1, false);
    while(n--){
        cin >> aux;
        if(!isInMemory[aux]){
            if(memory[indexPointer] != -1) isInMemory[memory[indexPointer]] = false;
            memory[indexPointer] = aux;
            isInMemory[aux] = true;
            pageFaults++;
            indexPointer = (indexPointer + 1) % q;
        }
    }
    cout << pageFaults << '\n';
}