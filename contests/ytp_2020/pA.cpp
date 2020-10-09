#include <iostream>
#include<algorithm>
#include <utility>
#include<vector>
#define ll long long int
#define pll pair<long long,long long>
#define F first
#define S second

using namespace std;
struct Seg{
    ll L,R,wh;
};

const int maxN = 1e5 + 10;
vector<ll> c[1000009],r[1000009];
vector<Seg> tc,tr;

int main(){
	ll R,C,i,j,k,N,a,b;
	cin >> R >> C;
	cin >> N;
	for(i = 0;i < N;i++)
    {
        cin >> a >> b;
        c[a].push_back(b);
        r[b].push_back(a);
    }
    for(i = 1;i <= 1000000;i++)
    {
        if(c[i].size() > 0)
        {
            sort(c[i].begin(),c[i].end());
            for(j = 0;j < c[i].size()-1;j++)
            {
                tc.push_back({c[i][j],c[i][j+1],i});
            }
        }
        if(r[i].size() > 0)
        {
            sort(r[i].begin(),r[i].end());
            for(j = 0;j < r[i].size()-1;j++)
            {
                tr.push_back({r[i][j],r[i][j+1],i});
            }
        }


    }
    ll ans = 0;
    for(auto x : tc)
    {
        for(auto y : tr)
        {
            if(x.wh > y.L && x.wh < y.R && y.wh > x.L && y.wh < x.R)
                ans = 1;
        }
    }
    if(ans == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

}
