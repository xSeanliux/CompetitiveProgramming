#include <iostream>
using namespace std;

int c, pi, qi, xi, yi;
bool blob[100][100]; //true if there's a blob

bool cut(int xi, int yi){
    blob[yi][xi] = 0;
    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            cout << blob[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    return true;
}

bool inflate(int pi, int  qi){ //return false if invalid move
    if(!blob[pi][qi]) return false;
    for(int i = 50; i > pi + 2; i--){
        //swap the arrays of i and i+1
        for(int j = 0; j < 100; j++){
            blob[j][i+1] = blob[j][i];
        }

    }

    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            cout << blob[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    for(int i = 0; i < 100; i++){
        blob[pi+1][i] = blob[pi][i];
    }


    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            cout << blob[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    for(int i = 50; i > qi + 1; i--){
        //swap the arrays of i and i+1
        for(int j = 0; j < 100; j++){
            blob[i][j] = blob[i][j+1];
        }

    }


    for(int i = 0; i < 100; i++){
        blob[i][qi + 1] = blob[i][qi];
    }



    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            cout << blob[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    return true;
}


int main(){
    for(int i = 0 ; i < 100; i++){
        for(int j = 0 ; j < 100; j++){
            blob[i][j] = false;
        }
    }
    blob[0][0] = true;

    while(cin >> pi >> qi >> xi >> yi){
        bool q = inflate(qi, pi);
        bool p = cut(xi, yi);
        //cout << q << endl;
        //inflate(pi, qi) then cut(xi, yi)
    }
}
