#include <iostream>
#include <map>
using namespace std;


struct Data{
    int seq, ind;
};


map <long long int , Data> stuff;

bool hasSolution = false;
int nSeries, len;
int main(){
    cin >> nSeries;
    for(int i = 0 ; i < nSeries; i++){
        //cout << "i = " << i << endl;
        cin >> len;
        long long int s = 0;
        int arr[len + 1];
        for(int j = 0; j < len; j++){
            cin >> arr[j];
            //cout << "arr[" << j << "] = " << arr[j] << endl;
            s += arr[j];
        }
        //cout << "sum = " << s << endl;
        //cout << "Hey" << endl;
        for(int j = 0 ; j < len && !hasSolution; j++){
            long long int _t = s - arr[j];
            if(!hasSolution){
                if(stuff.count(_t)){
                    if(stuff[_t].seq != i){ //oh yeah there's a asolution
                        cout << "YES" << endl;
                        //cout << stuff[_t].ind + 1 << " " << j + 1 << endl;
                        //cout << stuff[_t].seq + 1 << " " << i + 1 << endl;
                        cout << stuff[_t].seq + 1 << " " << stuff[_t].ind + 1 << endl;
                        cout << i + 1 << " " << j + 1 << endl;
                         return 0;

                    }
                } else {
                    Data d;
                    d.ind = j;
                    d.seq = i;
                    stuff.insert(pair<long long int, Data>(_t, d));
                }
            }
        }
    }
    if(!hasSolution){
        cout << "NO" << endl;
    }
}
