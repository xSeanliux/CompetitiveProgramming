#include <iostream>
#include <string.h>
#define maxW 32
using namespace std;
bool pic[maxW][maxW];

int C, ans, ite;
string tree1, tree2;

//2 1
//3 4
void f(string s, int &ite, int x, int y, int width){
    //printf("Drawing x = %d, y = %d, width = %d, char: %c\n", x, y, width, s[ite]);
    char c = s[ite++];
    if(c == 'p'){ //recursion down
        f(s, ite, x + width/2, y, width/2); // 1
        f(s, ite, x, y, width/2); // 2
        f(s, ite, x, y + width/2, width/2); // 3
        f(s, ite, x + width/2, y + width/2, width/2); // 2
    } else if(c == 'f') { //if black draw
        //cout << "Yes." << endl;
        for(int i = y; i < y + width; i++){
            for(int j = x; j < x + width; j++){
                if(!pic[i][j]){
                    pic[i][j] = 1;
                    ans++;
                }
            }
        }
        //cout << "Ans now " << ans << endl;

    } //if white do nothing lol

}


int main(){
    cin >> C;
    while(C--){
        for(int i = 0 ; i < maxW; i++)
            for(int j = 0; j < maxW; j++)
                pic[i][j] = 0;
        ans = 0;
        cin >> tree1;
        int p = 0;
        f(tree1, p, 0, 0, maxW);

        cin >> tree2;
        p = 0;
        f(tree2, p, 0, 0, maxW);
        printf("There are %d black pixels.\n", ans);
    }
}
