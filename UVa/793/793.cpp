#include <iostream>
#include <string.h>
using namespace std;

int T, N, a, b, disjoint[10000], yes, no;
string _c;
char com;
bool flag = false;
void sortOut(int n){
    if(disjoint[n] == n) return;
    sortOut(disjoint[n]);
    disjoint[n] = disjoint[disjoint[n]];
}

int main(){
    cin >> T;
    yes = no = 0;
    while(T--){
        while(getline(cin, _c)){
            if(_c[0] != 'c' && _c[0] != 'q'){
                if(flag)
                    cout << yes << "," << no << endl << endl;
                else flag = true;
                yes = no = 0;
                cin >> N;
                for(int i = 1; i <= N; i++)
                    disjoint[i] = i;
                getline(cin, _c); //extra \n
            } else {
                com = _c[0];
                int l = _c.length(), i;;
                for(i = 2; i < l; i++){
                    if(_c[i] == ' ') break;
                }
                a = stoi(_c.substr(2, i - 2));
                b = stoi(_c.substr(i + 1, l));
                sortOut(a);
                sortOut(b);
                if(com == 'c'){
                    disjoint[disjoint[a]] = disjoint[b];
                    //cout << a << " has ancestor " << disjoint[a] << " and " << b << " has ancestor " << disjoint[b] << endl;
                    //for(int i = 1; i <= N; i++){
                    //    cout << disjoint[i] << " ";
                    //}
                    //cout << endl;
                } else { //query
                    if(disjoint[a] == disjoint[b]){
                        yes++;
                    } else {
                        no++;
                    }
                    //cout << "in here" << endl;
                }
            }

        }
    }
    cout << yes << "," << no << endl;
}
