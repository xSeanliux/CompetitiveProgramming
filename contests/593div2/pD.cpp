#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#include <set>
using namespace std;

int n, m, cx, cy, k, x, y;

struct Seg{
    int dir, gt, a, b;
    Seg(){}
    Seg(int dir, int gt, int a, int b): dir(dir), gt(gt), a(a), b(b){}
};

vector<Seg> segs;

int main(){
    cin >> n >> m >> k;

    set<pii> obs;
    for(int i = 0; i < k; i++){
        cin >> y >> x;
        obs.insert({y, x});
    }
    int l = 0, r = m + 1, u = 0, d = n + 1;
    bool f= true;
    for(int i = m; i >= 1 && f; i--){
        for(int j = 1; j <= n; j++){
            if(!obs.count({j, i})){
                r = i + 1;
                //k -= n * (m - i);
                f = false;
                break;
            }
        }
        if(f){
            //cout << "m can now be" << i - 1 << endl;
            k -= n;
        }
    }

    f = true;
    for(int j = n; j >= 1 && f; j--){
        for(int i = 1; i <= m; i++){
            if(!obs.count({j, i})){
                d = j + 1;
                //k -= m * (n - j);
                f = false;
                break;
            }
        }
        if(f){
            //cout << "n can now be" << j - 1 << endl;
            k -= r - 1;
        }
    }
    //cout << "D = " << d << endl;
    f = true;
    for(int i = 1; i < r && f; i++){
        for(int j = 2; j <= n; j++){
            if(!obs.count({j, i})){
                l = i - 1;
                f = false;
                break;
            }
        }
        if(f){
            //cout << "l can now be" << i - 1 << endl;
            k -= d - 2;
        }
    }
    if(!k){
        cout << "Yes" << endl;
        return 0;
    }
    //cout << "n = " << n << ", m = " << m << ", k = " << k << endl;

    int posX = 1, posY = 1, dir = 0; //0: right, 1: down, 2: left, 3: up
    while(true){
        if(dir == 0){
            if(posX < r - 1){
                segs.push_back(Seg(dir, posY, posX, r - 2));
                posX = r - 1;
                u++;
            } else {
                break;
            }
        }
        if(dir == 1){
            if(posY < d - 1){
                segs.push_back(Seg(dir, posX, posY, d - 2));
                posY = d - 1;
                r--;
            } else {
                break;
            }
        }
        if(dir == 2){
            if(posX > l + 1){
                segs.push_back(Seg(dir, posY, posX, l + 2));
                posX = l + 1;
                d--;
            } else {
                break;
            }
        }
        if(dir == 3){
            if(posY > u + 1){
                segs.push_back(Seg(dir, posX, posY, u + 2));
                posY = u + 1;
                l++;
            } else {
                break;
            }
        }
        //cout << (*segs.rbegin()).dir << ", " << (*segs.rbegin()).a << ", " << (*segs.rbegin()).b << ", gt = " << (*segs.rbegin()).gt << endl;
        //cout << "Now aat" << posX << " " << posY << endl;
        dir = (dir + 1) % 4;
    }
    //cout << posY << " " << posX << endl;
    //cout << "u = " << u << ", d = " << d << ", l = " << l << ", r= " << r << ", dir = " << dir << endl;

    if(!obs.count({posY, posX})){
        cout << "No" << endl;
        return 0;
    }
    reverse(segs.begin(), segs.end());
    int cnt = 1;
    Seg s;
    for(Seg s : segs){
        //cout << "Looking at dir = " << s.dir << ", gt = " << s.gt << ", a = " << s.a << ", b = " << s.b << endl;
        if(cnt >= k) break;
        if(s.dir == 0){
            for(int i = s.b; i >= s.a && cnt < k; i--){
                //cout << "Checking " << s.gt << ", " << i << endl;
                if(!obs.count({s.gt, i})){
                    cout << "No" << endl;
                    return 0;
                }
                cnt++;
            }
        }
        if(s.dir == 1){
            for(int i = s.b; i >= s.a && cnt < k; i--){
                //cout << "Checking " << i << ", " << s.gt << endl;
                if(!obs.count({i, s.gt})){
                    cout << "No" << endl;
                    return 0;
                }
                cnt++;
            }
        }
        if(s.dir == 2){
            //cout << "H" << endl;
            for(int i = s.b; i <= s.a && cnt < k; i++){
                //cout << "Checking " << s.gt << ", " << i << endl;
                if(!obs.count({s.gt, i})){
                    cout << "No" << endl;
                    return 0;
                }
                cnt++;
            }
        }
        if(s.dir == 3){
            for(int i = s.b; i <= s.a && cnt < k; i++){
                //cout << "Checking " << i << ", " << s.gt << endl;
                if(!obs.count({i, s.gt})){
                    cout << "No" << endl;
                    return 0;
                }
                cnt++;
            }
        }
    }
    cout << "Yes" << endl;

}
