#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

string ans;

void printque(deque <int> que){
    for(int i : que){
        printf("%d ", i);
    }
    cout << endl;
}


int go(int N, deque<int> que){
    int cnt = 0, a, b;
    ans = "";
    if(!N) return 0;
    for(int i = N-1; i >= 1; i--){
        while(que.front() != i){
            ans = ans + "2";
            cnt++;
            que.push_back(que.front());
            que.pop_front();
        }
        //printf("\n");
        //printque(que);
        //cout << ans << endl;
        a = que.front();
        que.pop_front();
        b = que.front();
        que.push_front(a);
        while(b != i + 1){
            ans = ans + "12";
            cnt += 2;
            que.push_back(b);
            //printque(que);
            que.pop_front();
            que.pop_front();
            que.push_front(a);
            //printque(que);
            a = que.front();
            que.pop_front();
            b = que.front();
            que.push_front(a);
            //printque(que);
            //cout << ans << endl;

        }
    }
    //printf("\n");
    //cout << "cnt: " << cnt << " limit: " << 2*N*N << endl;
    return cnt;
}

void run(string s){ //takes a string and runs it on the string ans
    string oriS = s;
    int l = ans.length();
    for(int i = 0; i < l; i++){
        if(ans[i] - '1'){
            char c = oriS[0];
            oriS = oriS.substr(1) + c;
        } else {
            swap(oriS[0], oriS[1]);
        }
    }
    //cout << oriS << endl;

}


int main(){
    int LEN = 300;
    for(int i = 0; i <= 5000; i++){
        deque <int> q;
        for(int i = 1; i <= LEN; i++){
            q.push_back(i);
        }
        random_shuffle(q.begin(), q.end());
        int res = go(LEN, q);
        cout << res << endl;
        if(res > 2*LEN*LEN){
            cout << "FOUND" << endl;
            return 0;
        }
    }
}
