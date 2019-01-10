#include <iostream>
#include <string.h>
using namespace std;


char puzzle[6][6];
string scanner;
string command;
int bX, bY;
bool canGo;
int puzzles = 1;

void displayPuzzle(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << puzzle[i][j];
            if(j != 4) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    while(getline(cin, scanner)){
        if(scanner == "Z"){
            return 0;
        }

        canGo = true;
        for(int i = 0; i < 5; i++){
            puzzle[0][i] =  scanner[i];
            if(scanner[i] == ' '){
                    bX = i;
                    bY = 0;
            }
        }

        for(int i = 1; i <= 4; i++){
            getline(cin, scanner);

            for(int j = 0; j < 5; j++){
                puzzle[i][j] = scanner[j];
                if(scanner[j] == ' '){
                    bX = j;
                    bY = i;
                }
            }
        }
        //displayPuzzle();
        do{
            getline(cin, command);
            int l = command.length();
            for(int i = 0; i < l; i++){
                if(command[i] == 'A' && bY > 0){
                    swap(puzzle[bY - 1][bX], puzzle[bY][bX]);
                    bY--;
                } else if(command[i] == 'B' && bY < 4){
                    swap(puzzle[bY + 1][bX], puzzle[bY][bX]);
                    bY++;
                } else if(command[i] == 'L' && bX > 0){
                    swap(puzzle[bY][bX - 1], puzzle[bY][bX]);
                    bX--;
                } else if(command[i] == 'R' && bX < 4){
                    swap(puzzle[bY][bX + 1], puzzle[bY][bX]);
                    bX++;
                } else if(command[i] == '0'){
                    break;
                }else{
                    canGo = false;
                    break;
                }
                //displayPuzzle();
            }
        } while (command[command.length()-1] != '0');
        printf("Puzzle #%d:\n", puzzles);
        if(canGo){
            displayPuzzle();
        } else {
            printf("This puzzle has no final configuration.\n");
        }
        if(cin.peek() != 'Z') cout << endl;
        puzzles++;
    }

}
