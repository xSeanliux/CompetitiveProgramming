#include <iostream>
using namespace std;

int a, b, c, d;

int main(){
    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> a;

    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> b;

    cout << "? 4 5" << endl;
    fflush(stdout);
    cin >> c;

    cout << "? 5 6" << endl;
    fflush(stdout);
    cin >> d;

    int answers[6], divs[3] = {5, 23, 7};

    if(a * b == 2048 || a * b == 4096 || a * b == 8192){
        answers[1] = a * b / 512;
        answers[0] = a / answers[1];
        answers[2] = b / answers[1];
    } else {
        //? X ?
        bool flag = true;
        for(int i = 0; i < 3; i++){
            if(!(a % divs[i]) && !(b % divs[i])){
                if(i == 0){ //the middle one is 15
                    answers[1] = 15;
                } else if(i == 1){ //the middle one is 23
                    answers[1] = 23;
                } else { //the middle one is 42
                    answers[1] = 42;
                }
                answers[0] = a / answers[1];
                answers[2] = b / answers[1];
                flag = false;
            }
        }
        if(flag){ //means that the middle is a power of 2
            bool flag2 = true;
            for(int i = 0; i < 3; i++){
                if(!(a % divs[i])){
                    if(i == 0){ //ans[0] = 15!
                        answers[0] = 15;
                    } else if(i == 1){ //23
                        answers[0] = 23;
                    } else { //42
                        answers[0] = 42;
                    }
                    answers[1] = a / answers[0];
                    answers[2] = b / answers[1];
                    flag2 = false;
                }
            }
            if(flag2){
                for(int i = 0; i < 3; i++){
                    if(!(b % divs[i])){
                        if(i == 0){ //ans[0] = 15!
                            answers[2] = 15;
                        } else if(i == 1){ //23
                            answers[2] = 23;
                        } else { //42
                            answers[2] = 42;
                        }
                        answers[1] = b / answers[2];
                        answers[0] = a / answers[1];
                    }
                }
            }
        }
    }
    if(c * d == 2048 || c * d == 4096 || c * d == 8192){
        answers[4] = c * d / 512;
        answers[3] = c / answers[4];
        answers[5] = d / answers[4];
    } else {
        //? X ?
        bool flag = true;
        for(int i = 0; i < 3; i++){
            if(!(c % divs[i]) && !(d % divs[i])){
                if(i == 0){ //the middle one is 15
                    answers[4] = 15;
                } else if(i == 1){ //the middle one is 23
                    answers[4] = 23;
                } else { //the middle one is 42
                    answers[4] = 42;
                }
                answers[3] = c / answers[4];
                answers[5] = d / answers[4];
                flag = false;
            }
        }
        if(flag){ //means that the middle is a power of 2
            bool flag2 = true;
            for(int i = 0; i < 3; i++){
                if(!(c % divs[i])){
                    if(i == 0){ //ans[0] = 15!
                        answers[3] = 15;
                    } else if(i == 1){ //23
                        answers[3] = 23;
                    } else { //42
                        answers[3] = 42;
                    }
                    answers[4] = c / answers[3];
                    answers[5] = d / answers[4];
                    flag2 = false;
                }
            }
            if(flag2){
                for(int i = 0; i < 3; i++){
                    if(!(d % divs[i])){
                        if(i == 0){ //ans[0] = 15!
                            answers[5] = 15;
                        } else if(i == 1){ //23
                            answers[5] = 23;
                        } else { //42
                            answers[5] = 42;
                        }
                        answers[4] = d / answers[5];
                        answers[3] = c / answers[4];
                    }
                }
            }
        }
    }
    cout << "!";
    for(int i = 0; i < 6; i++){
        cout << " " << answers[i];
    }
    fflush(stdout);
    return 0;
}
