#include <iostream>
#include <string>
#include <cmath>
using namespace std;


double getValue(char note){
    switch(note){
        case 'W':
            return 1;
        case 'H':
            //cout << "H" << endl;
            return (0.5);
        case 'Q':
            return (0.5/2);
        case 'E':
            return (0.5/4);
        case 'S':
            return (0.5/8);
        case 'T':
            return (0.5/16);
        case 'X':
            return (0.5/32);
    }
}

bool isCorrect(string sect){
    double ans = 0;
    for(int i = 0; i < sect.length(); i++){
        //cout << sect[i] << "  : " << getValue(sect[i]) << endl;
        ans += getValue(sect[i]);
    }
    //cout << "Sum: " <<  ans << endl;
    //cout << "-------------------" << endl;

    return (abs(ans-1)<0.001);
}

int main(){

    string input;
    while(cin >> input){

        if(input == "*") return 0;
        string currentStr = "";
        int counter = 0;
        string sections[1000];
        for(int i = 0; i < input.length(); i++){ //this part is to process the input as things we can read.
            if(input[i] == '/'){
                sections[counter] = currentStr;
                currentStr = "";
                counter++;

            } else {
                currentStr += input[i];
            }

            if(input[i] == '/'){
                sections[counter] = currentStr;
                currentStr = "";
                counter++;

            }
        }
        int correctCounter = 0;
        for(int i = 0; i <= counter; i++){
            //cout << sections[i] << ", ";
            if(isCorrect(sections[i])) correctCounter++;
        }
        cout << correctCounter << endl;

    }
}
