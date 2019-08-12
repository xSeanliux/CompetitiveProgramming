#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N;
string a, b, s;
vector<int> nA, nB, added;
/*
vector<int> add(vector<int> A, vector<int> B){
    bool carry = 0;
    vector<int> res;
    res.clear();
    for(int i = 0; i < A.size(); i++){
        //cout << "i = " << i << ", carry = " << carry << endl;
        int val = A[i] + B[i];
        if(A[i] > B[i]) val += 26;
        res.push_back((A[i] + B[i] + carry) % 26);
        carry = (A[i] + B[i] + carry)/26;
    }
    if(carry) res.push_back(1);
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << (char)(('i' + 'k')/2 + 13) << endl;
    cin >> N >> a >> b;
    for(int i = N - 1; i >= 0; i--){
        nA.push_back(a[i] - 'a' );
        nB.push_back(b[i] - 'a');
    }
    added = add(nA, nB);
    for(int i : added){
        cout << i << endl;
    }
    //now divide by two
    string divided = "";
    int currentLeft = 0;
    for(int i = 0; i < added.size(); i++){
        if(currentLeft + added[i] % 2){
            divided += ((currentLeft + added[i] - 1) / 2 + 'a');
            currentLeft = 1;
        } else {
            divided += (currentLeft + added[i]) / 2 + 'a';
            currentLeft = 0;
        }
    }
    cout << divided << endl;

}
*/
int main(){
    cin >> N >> a >> b;
    int carry = 0, val;
    s = "";
    for(int i = N-1; i; i--){
        if(a[i] > b[i]){
            val = (a[i] + b[i] + 26)/2 + carry;
        } else {
            val = (a[i] + b[i])/2 + carry;
        }
        s = (char)(val) + s;
        carry = val/26;
    }
    cout << s << endl;
}
