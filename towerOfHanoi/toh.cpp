#include <iostream>
using namespace std;


double steps = 0;
int hanoi(int n, char from, char buffer, char to){
    if(n == 1){
        //cout << "Moving disc " << n << " from " << from << " to " << to << endl;
        steps++;

    } else {
        hanoi(n-1, from, to, buffer);
        //cout << "Moving disc " << n << " from " << from << " to " << to << endl;
        steps++;
        hanoi(n-1, buffer, to, from);

    }

}

int main(){
    int n;

    while(cin >> n){
        hanoi(n, 'A', 'B', 'C');
        cout << "Steps taken: " << steps << endl;
    }

}
