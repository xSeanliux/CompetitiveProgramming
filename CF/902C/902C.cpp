#include <iostream>
#include <vector>
using namespace std;

int h, n;
vector<int> a, tre1, tre2;

int main(){
    cin >> h;
    a.resize(h + 1);
    n = 0;
    for(int i = 0; i <= h; i++){
        cin >> a[i];
        n += a[i];
    }
    int top = 0, ind = 0;
    for(int i = 0; i <= h; i++){
        for(int j = 0; j < a[i]; j++){
            tre1.push_back(top);
            if(!j) ind = tre1.size();
        }
        top = ind;
    }
    //for(int i : tre1) cout << i << " ";
    int top1 = 0, top2 = 0, ind1 = 0, ind2;
    for(int i = 0; i <= h; i++){
        //cout << "i = " << i << endl;        cout << "top1 = " << top1 << ", top2" << " = " << top2 << endl;

        if(i && a[i - 1] > 1 && a[i] > 1){
            //cout << "X" << endl;
            tre2.push_back(top2);
            ind1 = tre2.size();
            for(int j = 1; j < a[i]; j++){
                tre2.push_back(top1);
                if(j == 1) ind2 = tre2.size();
            }
        } else {
            for(int j = 0; j < a[i]; j++){
                tre2.push_back(top1);
                if(!j) ind1 = tre2.size();
                if(j == 1) ind2 = tre2.size();
            }
        }
        top1 = ind1;
        top2 = ind2;
    }
    //cout << endl;
    //for(int i : tre2) cout << i << " ";
    for(int i = 0; i < n; i++){
        if(tre1[i] != tre2[i]){
            cout << "ambiguous" << endl;
            for(int i : tre1) cout << i << " ";
            cout << endl;
            for(int i : tre2) cout << i << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "perfect" << endl;
}
