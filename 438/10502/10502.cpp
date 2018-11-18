#include <iostream>
#include <string.h>
using namespace std;
string s;
bool arr[100 + 5][100 + 5];
int c, w, h;
long long int ans;
int main(){
    while(cin >> h){
        ans = 0;
        if(!h) return 0;
        cin >> w;
        for(int i = 0 ; i < h; i++){
            cin>> s;
            for(int k = 0 ; k < w; k++){
                arr[i][k] = (s[k]=='1')?1:0;
            }
            //cin >> arr[i][j];
        }
        int currentW = 0;
        int currentH = 0;
        for(int i = 0 ; i < h; i++){
            for(int j = 0 ; j < w; j++){
                if(arr[i][j]){
                    //cout << "Checking: (" << i << ", " << j << ")" << endl;
                    long long int maxL, maxD;
                    bool flag = true;
                    for(maxL = j; maxL < w && arr[i][maxL]; maxL++)
                    //cout << "maxL: " << maxL << endl;
                    for(maxD = i+1; maxD < h && flag; maxD++){
                        for(int k = j; k <= maxL; k++){
                            if(!arr[maxD][k]){
                                flag = false;
                                maxD--;
                                break;
                            }
                        }
                    }
                    //cout << "maxL:" << maxL << " maxD: " << maxD << endl;
                    ans += (maxL - j) * (maxD - i);
                    //cout << "ans += " << maxL-j << "*" << maxD-i << " = " << (maxL - j) * (maxD - i) << endl;


                    /*long long int minW = maxL;
                    long long int r, l;
                    for(r = maxD; r < h; r++){
                        for(l = j; l < minW; l++){
                            if(!arr[r][l]){
                                minW = min(minW, l);
                            }
                        }
                        if(arr[r][j] == 0) break;
                    }
                    */
                    int Z = maxL;
                    for(int k = maxD; k < h; k++){
                        for(int l = j; l <= Z; l++){
                            if(arr[k][l] == 0 || l == Z){
                                Z = l;
                                ans += l-j;
                                //cout << "ans += " << l-j << endl;
                            }
                        }
                    }
                    //cout << "r, minW = " << r << ", " << minW << endl;
                    //ans +=(r-maxD) * (minW-j+1);
                    //cout << "ans += " << r-maxD << "*" << minW-j+1 << " = " << (r-maxD) * (minW-j+1) << endl;


                }
            }
        }
        cout << ans <<endl;

    }
}
