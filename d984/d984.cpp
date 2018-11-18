#include <iostream>
using namespace std;
struct Candidate{
    char name;
    int votes;

} candidates[5]; //max 3

int sortByScore(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(candidates[j].votes >= candidates[i].votes) swap(candidates[i], candidates[j]);
        }
    }
}

int main(){
    int A, B, C;
    long long int sum;
    while(cin >> A >> B >> C){
        candidates[0].votes = A;
        candidates[1].votes = B;
        candidates[2].votes = C;
        candidates[0].name = 'A';
        candidates[1].name = 'B';
        candidates[2].name = 'C';
        sortByScore();

        if(candidates[2].votes - candidates[1].votes - candidates[0].votes > 0) cout << candidates[2].name << endl;
        else cout << candidates[1].name << endl;


    }
}
