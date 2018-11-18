#include <iostream>
#include <string.h>
using namespace std;
string query;
int N;

int main(){
    N = 0;
    while(getline(cin, query)){

        for(int i = 0; i < query.length(); i++){
            if(query[i] == '"'){
                string b = query.substr(0, i);
                string k = query.substr(i+1);
                if(N % 2 == 0){
                    query = b + "``" + k;
                    i++;
                } else {
                    query = b + "''" + k;
                    i++;
                }
                N++;
                //cout << N << endl;
            }
        }
        cout << query << endl;
    }
}
