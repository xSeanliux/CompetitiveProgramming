#include <iostream>
#include <string.h>
using namespace std;



bool adj[26][26], hasThis[26];
int conns[26];
int order[26];
string prevS, currentS;


int main(){
    for(int i = 0 ; i < 26; i++){
        conns[i] = hasThis[i] = 0;
        for(int j = 0 ; j < 26; j++){
            adj[i][j] = 0;
        }
    }
    while(cin >> prevS){
     for(int i = 0 ; i < prevS.length(); i++){
        hasThis[prevS[i] - 'A'] = true;
        }
        while(cin >> currentS){
            if(currentS == "#"){
                bool canFind = true, hasFound;
                int head = 0;
                while(canFind){
                    hasFound = false;
                    for(int i = 0 ; i < 26; i++){
                        if(!conns[i] && hasThis[i]){
                            cout << (char)(i + 'A');
                            order[head] = i;
                            head++;
                            for(int j = 0; j < 26; j++){
                                conns[j] -= adj[i][j];
                                //if(adj[i][j])
                                //   cout << (char)(j + 'A') << " has now " << conns[j] << " connections" << endl;
                            }
                            hasFound = true;
                            hasThis[i] = false;
                        } else if(i == 25 && !hasFound){
                            canFind = false;
                        }
                    }
                }
                cout << endl;
                //output;
                for(int i = 0 ; i < 26; i++){
                    conns[i] = hasThis[i] = 0;
                    for(int j = 0 ; j < 26; j++){
                        adj[i][j] = 0;
                    }
                }
                break;
            } else {
                for(int i = 0 ; i < currentS.length(); i++){
                    hasThis[currentS[i] - 'A'] = true;
                }
                //cout << "a" << endl;
                //cout << "Prev: " << prevS << ", current: " << currentS << endl;
                int l = min(prevS.length(), currentS.length());
                for(int i = 0 ; i < l; i++){
                    if(currentS[i] != prevS[i]){
                        if(!adj[ prevS[i] - 'A' ][ currentS[i] - 'A' ])
                            conns[ currentS[i] - 'A' ]++;
                        adj[ prevS[i] - 'A' ][ currentS[i] - 'A' ] = true;

                        //cout << prevS[i] << " before " << currentS[i] << endl;
                        break;
                    }
                }
                prevS = currentS;
            }

        }
    }
}
