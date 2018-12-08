#include <iostream>
using namespace std;


double bins[3][3]; //bins[a][b] a: ast bin, b: 0 Clear 1 Green 2 Brown

bool lex(char a[], char b[]){
    for(int i = 0; i < 3; i++){
        if(a[i] < b[i]){
            return true;
        } else if(a[i] == b[i]){
        } else {
            return false;
        }
    }
    return true;

}

char t(int n){
    if(n == 0){
        return 'C';
    } else if(n == 1){
        return 'G';
    } else {
        return 'B';
    }
}

int main(){
    int total, mintotal;
    char optimal[3] = {'Z','Z','Z'} , c[3];
    while(cin >> bins[0][2] >> bins[0][1] >> bins[0][0] >> bins[1][2] >> bins[1][1] >> bins[1][0] >> bins[2][2] >> bins[2][1] >> bins[2][0]){
        mintotal = -1;
        for(int i = 0 ; i < 3; i++){
            optimal[i] = 'Z';
            c[i] = 'Z';
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == j) continue;
                total = 0;
                for(int k = 0; k < 3; k++){
                    if(i != k) total += bins[0][k];
                    if(j != k) total += bins[1][k];
                    if(i == k || j == k) total += bins[2][k];
                    //cout << total <<  endl;
                }
                c[0] = t(i);
                c[1] = t(j);
                c[2] = t(3-i-j);
                                                    //cout << total << " " << c[0] << " " << c[1] << " " << c[2] << endl;

                if(total <= mintotal || mintotal == -1){
                    if(lex(c, optimal) && mintotal == total) {
                        for(int ii = 0; ii < 3; ii++){
                            optimal[ii] = c[ii];
                        }
                    } else if(mintotal > total || mintotal == -1){
                        for(int ii = 0; ii < 3; ii++){
                            optimal[ii] = c[ii];
                        }
                    }
                    mintotal = total;




                }
                total = 0;
            }
        }
        cout << optimal[0] << "" << optimal[1] << "" << optimal[2] << " " << mintotal << endl;
    }

}
