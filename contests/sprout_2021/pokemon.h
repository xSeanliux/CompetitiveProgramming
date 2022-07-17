#include <cassert>
#include <iostream>
#include <random>
#include <utility>
#include <ctime>
using namespace std;

pair<int,int> battle(bool A_alive, int A_protect, bool B_alive, int B_protect, bool C_alive, int C_protect, bool D_alive, int D_protect);

int main() {
    srand(time(0));
    int p[4] = {0,0,0,0};
    bool a[4] = {true,true,true,true};
    char id[4] = {'A', 'B', 'C', 'D'};
    for (long long i=1; ; i++) {
        cout << "Round #" << i << '\n';
        auto player=battle(a[0],p[0], a[1], p[1], a[2], p[2], a[3], p[3]);
        if (player.first < 0 || player.first > 2 || player.second < 0 || player.second > 2){
            cout << "Wrong Format\n";
            break;
        }
        int op[4]={player.first, 0, 0, player.second};
        for (int i = 0; i < 4; i++) {
            if (a[i] && op[i] == 0) {
                bool fail = false;
                for(int j = 0; j < p[i]; j++){
                    int tmp = rand() % 3;
                    if (tmp) {
                        fail = true;
                        break;
                    }
                }
                if (fail) {
                    cout << "Pokemon " << id[i] << " uses protect, but it fails!\n";
                    p[i] = 0;
                    op[i] = 3;
                }
                else {
                    cout << "Pokemon " << id[i] << " uses protect, it protects iself!\n";
                    op[i] = 4;
                    p[i]++;
                }
            }
            else {
                p[i]=0;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (op[i] > 0 && op[i] < 3 && a[i]){
                if (i == 1 || i == 2) {
                    op[i] --;
                    op[i] *= 3;
                }
                if (!a[op[i]]) {
                    op[i] = 3 - op[i];
                }
                if (op[op[i]] != 4) {
                    a[op[i]] = false;
                    cout << "Pokemon " << id[i] << " attack Pokemon " << id[op[i]] << ", Pokemon " << id[op[i]] << " faints!\n";
                    if (!a[3 - op[i]]) {
                        if (i == 1 || i == 2) {
                            cout<<"You Lose!\n";
                        }
                        else {
                            cout<<"You Win\n";
                        }
                        return 0;
                    }
                }
                else {
                    cout << "Pokemon " << id[i] << " attack Pokemon " << id[op[i]] << ", Pokemon " << id[op[i]] << " protects iself!\n";
                }
            }
        }
    }
}
