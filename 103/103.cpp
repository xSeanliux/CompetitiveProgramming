#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N, D, head, mi, ma;
int lcs[30], stuff[30], prev[30];

struct Box{
    int index;
    int dims[11];
} boxes[30];



bool boxComp(Box a, Box b){
    for(int i = 0 ; i < D; i++){
        if(a.dims[i] != b.dims[i])
            return a.dims[i] < b.dims[i];
    }
}

bool canFit(Box a, Box b){
    for(int i = 0 ; i < D; i++){
        if(a.dims[i] > b.dims[i])
            return false;
    }
    return true;
}

void flcs(){
    lcs[0] = 1;
    for(int i = 1 ; i < N; i++){
        lcs[i] = 0;
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(canFit(boxes[j], boxes[i]) && lcs[j]+1 > lcs[i]){
                lcs[i] = lcs[j] + 1;
                //prev[i]
            }
            if(ma < lcs[i]) ma = lcs[i];
            if(mi > lcs[i]) mi = lcs[i];
        }
        //cout << "lcs[" << i << "] = " << lcs[i] <<endl;
    }
}

int main()
{
    while(cin >> N >> D){
        ma = 0;
        mi = 1;
        for(int i = 0 ; i < N; i++){
            Box b;
            b.index = i;
            for(int j = 0 ; j < D; j++){
                cin >> b.dims[j];
            }
            sort(b.dims, b.dims + D);
            boxes[i] = b;
        }
        /*
        cout << endl;
        for(int i = 0 ; i < N; i++){
            cout << boxes[i].index << ": ";
            for(int j = 0 ; j < D; j++){
                cout  << boxes[i].dims[j] << " ";
            }
            cout << endl;
        }
        cout <<endl;
        */
        sort(boxes, boxes + N, boxComp);
        /*
        cout << endl;
        for(int i = 0 ; i < N; i++){
            cout << boxes[i].index << ": ";
            for(int j = 0 ; j < D; j++){
                cout  << boxes[i].dims[j] << " ";
            }
            cout << endl;
        }
        */

        flcs();
        //cout << "ma = " << ma << ", mi = " << mi << endl;
        cout << ma - mi + 1 << endl;
        int current = ma, ind = N-1;
        while(current >= mi && ind >= 0){
            if(lcs[ind] == current){
                //cout<< boxes[ind].index + 1 << " has lcs " << lcs[ind] << endl;;
                stuff[current] = boxes[ind].index + 1;
                if(current > 0){
                    //cout << " ";
                }
                current--;
            }
            ind--;
        }
        for(int i = mi; i <= ma; i++){
            cout << stuff[i];
            if(i < ma - mi + 1) cout << " ";
        }
        cout << endl;
    }
}
