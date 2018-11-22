#include <iostream>
using namespace std;





int asciichart[1000];
char usedChars[1000];
int j = 0;
void sortChars(){
    for(int i = 0 ; i < 1000; i++){
        for(int j = i + 1 ; j < 1000; j++){ //big to small
            if(usedChars[i] > usedChars[j]){
                char tmp = usedChars[i];
                usedChars[i] = usedChars[j];
                usedChars[j] = tmp;
            }
        }
    }
}

int main()
{
    char c;

    j = 0;
    while(scanf("%c", &c) != EOF)
    {


        if(c != '\n')
        {
            printf("j: %d, c: %c \n", j , c);
            usedChars[j] = c;
            j++;
            cout <<"J++" << endl;


        }
        else
        {
            j = 0;
            sortChars();
            for(int i = 0 ; i < 1000; i++){
                asciichart[usedChars[i]]+=1;
            }
            //cout << "Hi" << endl;
            for(int i = 1 ; i < 1000; i++)
            {
                if(asciichart[i])
                {
                    printf("%d %d \n",i,asciichart[i]);
                }
            }
            for(int i = 0 ; i < 1000; i++){
                asciichart[i] = 0;
                usedChars[i] = 0;
            }
            cout << endl;
        }
    }



}
