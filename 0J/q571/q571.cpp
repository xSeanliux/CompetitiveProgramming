#include <iostream>
#include <string.h>
using namespace std;
int maxa, maxb;
bool visited[1005][1005];
string path[10005];
string solutionPath[10005];
int minLen;
void dfs(int A, int B, int N, int iteration){
    //cout << A << ", " << B <<endl;
    /*
    if(visited[A][B] == true){
        return;
    } else {

        visited[A][B] = true;

    }
    if(A == N || B == N){
        //cout << "Found solution with length " << iteration << endl;
        if(iteration <= minLen){

            minLen = iteration;
            for(int i = 0; i < iteration; i++){
                solutionPath[i] = path[i];
            }
        }
        //return; //keep to make faster, remove to give optimal solution

    }

    path[iteration] = "fill A " + to_string(maxa) + ", " + to_string(B);
    dfs(maxa, B, N, iteration+1);
    path[iteration] = "fill B "  + to_string(A) + ", " + to_string(maxb);
    dfs(A, maxb, N, iteration+1);
    path[iteration] = "empty A "  + to_string(0) + ", " + to_string(B);
    dfs(0, B, N, iteration+1);
    path[iteration] = "empty B " + to_string(A) + ", " + to_string(0);
    dfs(A, 0, N, iteration+1);
    //pour a into b
    path[iteration] = "pour A B " + to_string(0) + ", " + to_string(A + B);
    if(A + B <= maxb){
        path[iteration] = "pour A B " + to_string(0) + ", " + to_string(A + B);
        dfs(0, A + B, N, iteration+1);
    } else{
        path[iteration] = "pour A B " + to_string(A + B - maxb) + ", " + to_string(maxb);
        dfs(A + B - maxb, maxb, N, iteration+1);
    }
    //pour b into a

    if(A + B <= maxa){
        path[iteration] = "pour B A " + to_string(A + B) + ", " + to_string(0);
        dfs( A + B, 0, N, iteration+1);
    } else{
        path[iteration] = "pour B A " + to_string(maxa) + ", " + to_string(A + B - maxa);
        dfs(maxa, A + B - maxa, N, iteration+1);
    }
    visited[A][B] = false;
    */
    /*
    // Actual Code to be used in submit - the above is debug code
    path[iteration] = "fill A";
    dfs(maxa, B, N, iteration+1);
    path[iteration] = "fill B";
    dfs(A, maxb, N, iteration+1);
    path[iteration] = "empty A";
    dfs(0, B, N, iteration+1);
    path[iteration] = "empty B";
    dfs(A, 0, N, iteration+1);
    //pour a into b
    path[iteration] = "pour A B" ;
    if(A + B <= maxb){
        dfs(0, A + B, N, iteration+1);
    } else{
        dfs(A + B - maxb, maxb, N, iteration+1);
    }
    //pour b into a
    path[iteration] = "pour B A";
    if(A + B <= maxa){
        dfs( A + B, 0, N, iteration+1);
    } else{
        dfs(maxa, A + B - maxa, N, iteration+1);
    }
    visited[A][B] = false;
    */
}

int main(){
    int A, B, N;
    while(cin >> A >> B >> N){
        maxa = A;
        maxb = B;
        minLen = 1000000;
        for(int i = 0; i < 1005; i++){
            for(int j = 0; j < 1005; j++){
               visited[i][j] = false;
            }
        }

        dfs(0, 0, N, 0);
        for(int i = 0 ; i < minLen; i++){
            cout << solutionPath[i] << endl;
        }
        cout << "success, with " << minLen << " steps "<< endl;


    }
}
