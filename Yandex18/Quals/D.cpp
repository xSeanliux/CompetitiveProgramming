#include <iostream>
#include <algorithm>
using namespace std;

struct Stick{
    long long int len;
    int ind;
};


Stick arr[300000 + 10];
Stick nA[300000 + 10];
long long int l, r;
int sticks, queries;

bool comp(Stick a, Stick b){
    return a.len < b.len;
}

int main(){
    cin >> sticks >> queries;
    for(int i = 0 ; i < sticks; i++){
        cin >> arr[i].len;
        arr[i].ind = i + 1;
    }
    for(int k = 0; k < queries; k++){
        cin >> l >> r;
        if(r - l <= 1){
            printf("-1\n");
            continue;
        }
        int length = r - l + 1;

        for(int i = l - 1; i < r; i++){
            nA[i - l + 1] = arr[i];
            //cout <<"Reading " << i << "th with value " << arr[i].len << endl;
        }

        Stick m1, m2, m3;
        m1.len = 0;
        m2.len = 0;
        m3.len = 0;
        for(int i = 0 ; i < length; i++){
            if(nA[i].len > m1.len){
                swap(m1, m2);
                m1.len = nA[i].len;
                m1.ind = nA[i].ind;
            }
        }
        for(int i = 0 ; i < length; i++){
            if(nA[i].ind != m1.ind && nA[i].ind != m2.ind){
                m3.len = nA[i].len;
                m3.ind = nA[i].ind;
                if(m1.len < m2.len + m3.len){
                    break;
                }
            }
        }
        if(m1.len < m2.len + m3.len){
            printf("%d %d %d\n", m1.ind, m2.ind, m3.ind);
        } else {
            printf("-1\n");
        }

        /*
        for(int i = 0; i < length; i++){
            cout << "na[" << i << "] = " << nA[i].len <<endl;
        }
        */


    }
}
