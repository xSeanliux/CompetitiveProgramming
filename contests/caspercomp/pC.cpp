#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 2e5;

int N, frq[maxN + 10], t;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t;
        frq[t]++;
    }
    vector<int> ones;
    for(int i = 1; i <= maxN; i++){
        if(frq[i] == 1) ones.push_back(i);
    }


    int l = -1, r = -1, maxL = 0;

    for(int i = 1; i <= maxN; i++){
        if(frq[i]){
            int cl = i, ri, len = 0;
            ones.clear();
            while(frq[i]){
                ri = i;
                len += frq[i];
                if(frq[i] == 1) ones.push_back(i);
                i++;
            }
            i--;
            if(!ones.size()){
                if(maxL < len){
                    r = ri;
                    l = cl;
                    maxL = len;
                }
            } else {
                len = 0;
                for(int j = cl ; j <= ones[0]; j++) len += frq[j];
                ri = ones[0];
                for(int j = 1; j < ones.size(); j++){
                    int clen = 0;
                    for(int k = ones[j - 1]; k <= ones[j]; k++){
                        clen += frq[k];
                    }
                    if(len < clen){
                        len = clen;
                        cl = ones[j - 1];
                        ri = ones[j];
                    }
                }
                if(ones.size()){
                    int clen = 0;
                    for(int j = ones[ones.size() - 1]; j <= i; j++){
                        clen += frq[j];
                    }
                    if(len < clen){
                        len = clen;
                        cl = ones[ones.size() - 1];
                        ri = i;
                    }
                }

                if(maxL < len){
                    r = ri;
                    l = cl;
                    maxL = len;
                }
            }
        }
    }


    cout << maxL << endl;
    for(int i = l; i <= r; i++){
        cout << i << " ";
        frq[i]--;
    }
    for(int i = r; i >= l; i--){
        while(frq[i]){
            cout << i << " ";
            frq[i]--;
        }
    }
}
