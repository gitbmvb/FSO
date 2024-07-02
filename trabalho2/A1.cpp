#include <bits/stdc++.h>
using namespace std;
struct process {
    vector<int> inst;
    int i = 0;
    int number;
};

int main(void){
    unsigned int clock = 0;
    int N, aux;
    cin >> N;
    vector<int> qtd_inst (N);
    list<process> ps;
    for(auto& x: qtd_inst) cin >> x;
    for(int i = 0; i < N; i++){
        process p;
        p.number = i;
        for(int j = 0; j < qtd_inst[i]; j++){
            cin >> aux;
            p.inst.push_back(aux);
        }
        ps.push_back(p);
    }
    while(ps.size()){
        for(auto it = ps.begin(); it != ps.end(); it++){
            for(int i = it->i; i < it->inst.size(); i++){
                int& temp = it->inst[it->i];
                if(temp == 0){
                    it->i++;
                    clock += 10;
                } else {
                    temp = 0;
                    break;
                }
            }
            if(it->i == it->inst.size()){
                cout << it->number + 1 << " (" << clock << ")\n";
                it = ps.erase(it);
                it--;
            }
        }
    }
}