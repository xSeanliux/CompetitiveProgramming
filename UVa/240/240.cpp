#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
using namespace std;

struct Obj{
    map<char, string> stuff;
    int freq;
    bool operator()(const Obj a, const Obj b){
        return a.freq < b.freq;
    }
    bool operator<(const Obj a) const {
        return this->freq < a.freq;
    }
};


string s;
int main(){
    while(getline(cin, s)){
        stringstream stream(s);
        priority_queue<Obj> pq;
        char currentChar = 'A' - 1;
        for(int n; stream >> n;){
            Obj o;
            o.stuff.insert({++currentChar, ""});
            o.freq = n;
            pq.push(o);
        }
        while(pq.size() > 1){
            cout << pq.size() << endl;
            Obj a = pq.top(); pq.pop(); Obj b = pq.top(); pq.pop();
            Obj newObj;
            for(auto o : a.stuff){
                newObj.stuff.insert({o.first, o.second + '0'});
            }
            for(auto o : b.stuff){
                newObj.stuff.insert({o.first, o.second + '1'});
            }
            newObj.freq = a.freq + b.freq;
            pq.push(newObj);
        }
        for(auto i : pq.top().stuff){
            cout << i.first << " " << i.second << endl;
        }
    }
}
