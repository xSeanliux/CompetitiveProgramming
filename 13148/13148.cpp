#include <iostream>
using namespace std;

long long int N;
int main(){
    while(scanf("%d", &N) && N){
        bool flag;
        if(!N) return 0;
        switch(N){
        case 1:
        case 64:
        case 729:
        case 4096:
        case 15625:
        case 46656:
        case 117649:
        case 262144:
        case 531441:
        case 1000000:
        case 1771561:
        case 2985984:
        case 4826809:
        case 7529536:
        case 11390625:
        case 16777216:
        case 24137569:
        case 34012224:
        case 47045881:
        case 64000000:
        case 85766121:
            flag = true;
            break;
        default:
            flag = false;
        }
        if(flag){
            cout << "Special" << endl;
        } else {
            cout << "Ordinary" << endl;
        }

    }
}
