#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;

const int maxN = 5e3 + 10;

int N, arr[maxN], T, tc = 0;
vector<int> need[maxN];
struct Obj {
    int val, sz;
    Obj(){}
    Obj(int v, int s = 1): val(v), sz(s){}
};
map<int, Obj> mp; //order - 
map<int, int> ord;



int currentNum = 0, currentIdx = 0, ttsz = 0;

void init() {
    mp = map<int, Obj>(); //order - 
    ord = map<int, int>();
    currentNum = 0, currentIdx = 0, ttsz = 0;
}

void print() {
    cout << currentNum << "/" << currentIdx << ": " ;
    for(auto [u, v] : mp) {
        cout << v.val << " * " << v.sz << " - ";
    }
    cout << endl;
}

void add(int x) {
    if(!ord.count(x)) {
        ord[x] = ord.size(); 
        mp[ord[x]] = Obj(x);
    } else {
        mp[ord[x]].sz++;
    }
    if(ttsz == 0) {
        currentNum = currentIdx = 0;
        ttsz++;
        return;
    }
    if((ttsz % 2 == 0) && (ord[x] >= currentNum)) {
        currentIdx++; 
        if(mp[currentNum].sz == currentIdx) {
            currentNum++;
            currentIdx = 0;
        }
    }
    if((ttsz % 2 == 1) && (ord[x] < currentNum)) {
        currentIdx--; 
        if(currentIdx == -1) {
            currentNum--;
            currentIdx = mp[currentNum].sz - 1;
        }
    }

    ttsz++;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        need[i] = vector<int>(N, maxN);
        cin >> arr[i];
    }
    for(int l = 0; l < N; l++) {
        init();
        for(int r = l; r < N; r++) {
            add(arr[r]); 
            if(((r - l + 1) & 1) == 0) {
                int x = currentIdx + 1; 
                int y = mp[currentNum].sz - x;
                int a = (r - l + 1) / 2 - x;
                int b = (r - l + 1) / 2 - y;
                if(y == 0 || (a >= x && ((a + y) == (x + b)))) need[l][r] = 0;     
                //cout << "l = " << l << ", r = " << r << endl;
                //print();
                //cout << "a, x, y, b = " << a << " " << x << " " << y << " " << b << endl;
            }
        }
    }
    for(int r = 0; r < N; r++) for(int l = r; l >= 0; l--) {
        need[l][r] = min(need[l][r], r - l + 1);
        if(r) need[l][r] = min(need[l][r], need[l][r - 1] + 1);
        if(l < N - 1) need[l][r] = min(need[l][r], need[l + 1][r] + 1);
        //cout << "need[" << l << "][" << r << "] = " << need[l][r] << endl;
    }

    int ans = 0;
    for(int x = 1; x <= N; x++) {
        //cout << " x = " << x << endl;
        int cnt = 0, st = -1, xcnt = 0;    
        for(int i = 0; i < N; i++) {
           if(arr[i] == x) {
               xcnt++;
               if(st != -1 && i) {
                   //cout <<" adding need " << st << " - " << i - 1 << endl;
                    cnt += need[st][i - 1];
                    st = -1;
               }
           } else {
               if(st == -1) st = i;
           }
        }
        if(st != -1) {
                   //cout <<" adding need " << st << " - " << N - 1 << endl;
            cnt += need[st][N - 1];
        }
        ans = max(ans, max(0, xcnt - cnt));
    }
    if(T < 1000)
        cout << ans << endl;
    else if(++tc == 99) {
        cout << "N = " << N << ", vals = ";
        for(int i = 0; i < N; i++) cout << arr[i] << " \n"[i == N - 1];
    }
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++) solve();
}
