#include <iostream>
using namespace std;

long long int N, x, y, k;

int main(){
    cin >> N;
    while(N--){
        cin >> x >> y >> k;
        int diags = 0, orix = x, oriy = y;
        if(x > y) swap(x, y); //x <= y;
        if(max(x, y) > k){
            cout << -1 << endl;
            continue;
        }
        if(x == y){
            cout << "C" << endl;
            diags = x-1;
            y = 1; x = 1;
            int left = k - diags - 1;
            diags += left/2 * 2;
            left %= 2;
            diags -= left;
            cout << diags << endl;
            continue;
        }
        diags += x;
        //cout << "Going diag " << x << " units" << endl;
        y -= x;
        x = 0;
        diags += y/2 * 2;
        //cout << "diag up " << y/2 * 2 << " units " << endl;
        y %= 2;
        //cout << "must now go up " << y << " units " << endl;
        int left = k - diags - y;
        if(left > 0){
            diags += left/2 * 2;
            left %= 2;
            if(y){
                diags++;
            } else diags--;
        }

        cout << diags << endl;
        //diags = (diags + (x % 2) + (y % 2) - k)
        //if(k == diags + (x % 2) + (y % 2)){

        //}
    }
}
