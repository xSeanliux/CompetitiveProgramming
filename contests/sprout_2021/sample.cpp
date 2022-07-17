#include "pokemon.h"

int now = 0;
pair<int,int> battle(bool A_alive, int A_protect, bool B_alive, int B_protect, bool C_alive, int C_protect, bool D_alive, int D_protect){
    if(!now){
        now = 1;
        return make_pair(1, 0);
    }
    int F = (A_protect == 0 ? 0 : (C_protect == 0 ? 2 : 1));
    int S = (B_protect == 0 ? 0 : (D_protect == 0 ? 1 : 2));
    return make_pair(F, S);
}
