#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <stdlib.h>
using namespace std;

class Uri;
int N, Q, com, arg;

struct Man{
    Uri *left, *right;
} arr[10000];

class Uri{
    public:
        int len, left, right;
        bool isValid;
        Uri(int left, int right){
            this->left  = left;
            this->right = right;
            this->len = right - left + 1;
            this->isValid = true;
            if(left > 1)
                arr[left - 1].right = this;
            if(right < N)
                arr[right + 1].left = this;//damn boi
            //cout << "the guy at " << left-1 << " and " << right+1 << " has been updtaed" << endl;
        }
        Uri(){

        }
};

int comfort(const Uri* const a){
    if(a->left == 0 || a->right == N){
        return (a->len-1);
    } else {
        return (a->len - 1)/2;
    }
}

class Compare{
    public:
        bool operator()(const Uri * const a, const Uri * const b) const {
            if(comfort(a) == comfort(b)){
                return a->left > b->left;
            }
            return comfort(a) < comfort(b);
        }
};



priority_queue<Uri*, vector<Uri*>, Compare> que;
bool isOccupied;
int main(){
    cin >> N >> Q;
    int zStart = 1;
    for(int i = 1; i <= N; i++){
        arr[i].left = NULL;
        arr[i].right = NULL;
    }
    for(int i = 1; i <= N; i++){
        cin >> isOccupied;
        if(isOccupied){
            if(zStart >= 0 && i > 1){
                Uri *u = new Uri(zStart, i-1);
                cout << "New segment: " << zStart << " to " << i-1 << endl;
                cout << "comfort : " << comfort(u) << endl;
                que.push(u);
            }
            zStart = -1;
        } else {
            if(zStart == -1){
                zStart = i;
            }
        }
        if(i == N && !isOccupied){
            if(zStart >= 0){
                Uri *u = new Uri(zStart, i);
                que.push(u);
                cout << "end " << endl;
                cout << "New segment: " << zStart << " to " << i << endl;
                cout << "comfort : " << comfort(u) << endl;
                //cout << "New segment: " << zStart << " to " << i << endl;
            }
        }
    }
    for(int i = 0; i < Q; i++){
        cout << "size: " << que.size() << endl;
        cin >> com;
        if(com == 1){ //in
            cout << "HEY" <<endl;
            while(!que.top()->isValid){
                que.pop();
                cout << que.size() << endl;

            }
            Uri* u = que.top();
            u->isValid = false;
            if(u->left == 1){
                cout << "1 goes in" << endl;
                if(u->right > 1){
                    Uri *n = new Uri(2, u->right);
                    cout << "new seg: " << 2 << " to " << u->right << endl;
                    arr[1].right = n;
                    que.push(n);
                } else {
                    cout << "seg too small" << endl;
                    arr[1].right = NULL;
                }
            } else if(u -> right == N){
                cout << N << " goes in " << endl;
                if(u-> left < N){
                    Uri *n = new Uri(u->left, N-1);
                    cout << "new seg: "<< u->left << "to " << N-1 << endl;
                    arr[N].left = n;
                    que.push(n);
                } else {
                    cout << "seg too small" << endl;
                    arr[N].left = NULL;
                }
            } else {
                if(u -> len % 2){
                    cout << u->left + u->len /2<< " goes in " << endl;
                    if(u->len > 1){
                        Uri *left = new Uri(u->left, u->left + u->len /2 - 1);
                        arr[u->left + u->len /2].left = left;
                        que.push(left);
                        cout << "seg: " << u->left << " to " << u->left + u->len /2 - 1 << endl;
                    } else {
                        cout << "left seg too small " << endl;
                        arr[u->left + u->len /2].left = NULL;
                    }
                    if(u->right - u->left - u->len/2 > 0){
                        Uri *right = new Uri(u->left + u->len/2 + 1, u->right);
                        arr[u->left + u->len /2].right = right;
                        que.push(right);
                        cout << "seg: " << u->left + u->len/2 + 1 << " to " << u->right << endl;
                    } else {
                        cout << "right seg too small " << endl;
                        arr[u->left + u->len /2].right = NULL;
                    }

                } else {
                    cout << u->left + u->len/2 - 1 << "goes in " << endl;
                    if(u->len/2 > 1){
                        Uri *left = new Uri(u->left, u->left + u->len/2 - 2);
                        cout << "new seg: "<< u->left << "to " << u->left + u->len/2 - 2 << endl;
                        arr[u->left + u->len/2-1].left = left;
                        que.push(left);
                    } else {
                        arr[u->left + u->len/2-1].left = NULL;
                        cout << "left seg too small" << endl;
                    }
                    if(u->right - u->len/2 > 0){
                        Uri *right = new Uri(u-> left + u->len/2, u->right);
                        cout << "new seg: "<< u->left + u->len/2 << "to " <<u->right << endl;
                        arr[u->left + u->len/2-1].right = right;
                        que.push(right);
                    } else {
                        cout << "right seg too smal" << endl;
                        arr[u->left + u->len/2-1].right = NULL;
                    }
                }
            }
            que.pop();
        } else { // out
            cin >> arg;
            Uri *left, *right, *res;
            if(arr[arg].left != NULL && arr[arg].left->isValid){
                left = arr[arg].left;
                left->isValid = false;
            } else {
                left = NULL;
            }
            if(arr[arg].right != NULL && arr[arg].right->isValid){
                right = arr[arg].right;
                right->isValid = false;
            } else{
                right = NULL;
            }
            if(left == NULL && right == NULL){
                res = new Uri(arg, arg);
            } else if(left == NULL){
                cout << "a!" << endl;
                res = new Uri(arg, right->right);
            } else if(right == NULL){
                cout << "b!" << endl;
                res = new Uri(left -> left, arg);
            } else {
                cout << "c!" << endl;
                res = new Uri(left -> left, right -> right);
            }
            que.push(res);
            arr[arg].left = arr[arg].right = NULL;
            cout << "res: " << res->left << " to " << res->right << endl;
        }
    }




}
