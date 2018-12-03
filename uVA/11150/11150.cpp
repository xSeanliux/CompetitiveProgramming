#include <iostream>
using namespace std;

bool hasBorrowed;
int full, emp;

int main(){
    while(cin >> full){
        emp = 0;
        int ans = 0;
        hasBorrowed = false;
        while(full){
            if((emp + full) % 3 == 2 && !hasBorrowed){
                hasBorrowed = true;
                emp++;
            }
            ans += full;
            //cout << "Drank " << full << endl;
            emp += full;
            full = 0;
            full = emp/3;
            emp %= 3;
        }
        cout << ans << endl;
    }
}
