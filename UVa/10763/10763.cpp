#include <iostream>
#include <map>
using namespace std;

struct Student{
    int from;
    int to;
    bool operator== (const Student &a) const{
     return a.to == this->to && a.from == this->from;
    }
    bool operator() (const Student &a, const Student &b) const{
         if(a.from == b.from){
            return a.to < b.to;
         }
         return a.from < b.from;
    }
};

int K, a, b;

int main(){
    while(cin >> K){
        if(!K) return 0;
        map <Student, int, Student> prog;
        for(int i = 0 ; i < K; i++){
            cin >> a >> b;
            Student ori, wantMatch;
            ori.from = a;
            ori.to = b;
            wantMatch.from = b;
            wantMatch.to = a;
            if(!prog.count(wantMatch)){
                //cout << "No match found for from " << b << " to " << a << endl;
                if(!prog.count(ori)){
                    //cout << "insert: from " << ori.from << ", to " << ori.to << endl;
                    prog.insert(pair<Student, int>(ori, 1));
                    //cout << "Prog now has " << prog.size() << " elements" << endl;
                } else {
                    //cout << "add: from" << ori.from << ", to " << ori.to << " now has " << prog[ori] + 1 << " people." << endl;
                    prog[ori]++;
                }
            } else {
                //cout << "Match found, matched with s: " << b << ", e: " << a << endl;
                prog[wantMatch]--;
                if(!prog[wantMatch])
                    prog.erase(wantMatch);
            }
        }
        if(prog.empty()){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
