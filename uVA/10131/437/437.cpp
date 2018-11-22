#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int nBoxes, a, b, c, k = 0;

struct Box{
    int a, b, c;
};

Box boxes[1000];

int lis[1000];

bool boxSort(const Box a, const Box b){
    if(a.b == b.b){
        return a.c > b.c;
    }
    return a.b > b.b;
}

void f(){
    lis[0] = boxes[0].a;
    int _ans;
    for(int i = 1; i < 3 * nBoxes; i++){
        _ans = boxes[i].a;
        for(int j = 0; j < i; j++){
            if(boxes[i].b < boxes[j].b && boxes[i].c < boxes[j].c && _ans < boxes[i].a  + lis[j]){
                _ans = boxes[i].a + lis[j];
            }
        }
        lis[i] = _ans;
    }
}
int main(){
    while(cin >> nBoxes){
        if(!nBoxes) return 0;
        for(int i = 0 ; i < 3 * nBoxes; i+=3){
            cin >> a >> b >> c;
            boxes[i].a = a;
            boxes[i].b = max(b, c);
            boxes[i].c = min(b, c);

            boxes[i+1].a = b;
            boxes[i+1].b = max(a, c);
            boxes[i+1].c = min(a, c);

            boxes[i+2].a = c;
            boxes[i+2].b = max(b, a);
            boxes[i+2].c = min(b, a);
        }
        sort(boxes, boxes + 3 * nBoxes, boxSort);
        /*
        for(int i = 0 ; i < 3 * nBoxes; i++){
            cout << "box #" << i << ": " << boxes[i].a << ", " << boxes[i].b <<", "<< boxes[i].c << endl;
        }
        */
        f();
        int m = 0;
        for(int i = 0; i < 3 * nBoxes; i++){
            if(lis[i] > m) m = lis[i];
        }
        printf("Case %d: maximum height = %d\n", ++k, m);
    }
}
