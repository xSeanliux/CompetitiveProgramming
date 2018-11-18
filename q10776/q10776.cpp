#include <iostream>
using namespace std;
    char str[40]; //max 30
    int len;
    char ans[40]; //max 30
bool visited[40];

bool hasrepeats(string str){


}

void run(string str, int len, int iteration){
    if(iteration >= len){ //output

        for(int i = 0 ; i < len ; i++){
            cout << ans[i] << " ";
        }
        for(int i = 0 ; i < 40 ; i++){
            visited[i] = false;
        }
        cout << endl;
        return;
    } else {
        for(int i = iteration; i < str.length(); i++){

                ans[iteration] = str[i];
                run(str, len, iteration+1);
                visited[i] = true;





        }
    }

}


void qs(char str[], int left, int right){
    int pivot = str[left];



}

int main(){


    while(cin >> str >> len){
        for(int i = 0 ; i < len; i++){
            visited[i] = false;
        }


        run(str, len, 0);
    }

}
