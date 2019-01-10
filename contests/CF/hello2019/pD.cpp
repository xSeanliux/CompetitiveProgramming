#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

unsigned long long int N, K;
map<unsigned ll int, vector<unsigned ll int> > divs;
map<unsigned ll int, unsigned ll int> amo, newAmo;

map<unsigned ll int, unsigned ll int> initamo(){
    map<unsigned ll int, unsigned ll int> res;
    for(map<unsigned ll int, vector<unsigned ll int> >::iterator i = divs.begin(); i != divs.end(); i++){
        unsigned ll int k = i->first;
        res.insert(pair<unsigned ll int, unsigned ll int>(k, 0));
    }
    return res;
}

int main(){
    cin >> N >> K;
    for(unsigned long long int i = 1; i * i <= N; i++){
        if(!(N % i)){
            vector<unsigned ll int> v;
            divs.insert(pair<int, vector<unsigned ll int> >(i, v));
            divs.insert(pair<int, vector<unsigned ll int> >(N/i, v));
        }
    }
    for(map<unsigned ll int, vector<unsigned ll int> >::iterator i = divs.begin(); i != divs.end(); i++){
        unsigned ll int k = i->first;
        amo.insert(pair<unsigned ll int, unsigned ll int>(k, 0));
        for(map<unsigned ll int, vector<unsigned ll int> >::iterator j = divs.begin(); j != divs.end(); j++){
            if(!(j->first % k)) i->second.push_back(j->first);
        }
    }
    amo[N]++;
    while(K--){
        newAmo = initamo();
        for(map<unsigned ll int, vector<unsigned ll int> >::iterator i = divs.begin(); i != divs.end(); i++){
            unsigned ll int k = i->first, l = i->second.size();
            for(int j = 0; j < l; j++){
                newAmo[k] += amo[i->second[j]];
            }
        }
        swap(amo, newAmo);
    }
    int sum = 0, total = 0;
    for(map<unsigned ll int, unsigned ll int>::iterator i = amo.begin(); i != amo.end(); i++){
        total += i->second;
        sum += i->first*i->second;
    }
    cout << total << ", " << sum << endl;
}

