#include <iostream>
using namespace std;

int N, val[(int)1e9 + 10];

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

int main(){
    cin >> N;
    val[0] = 0;
    for(int i = 1; i <= N; i++){
        cin >> val[i];
        val[i] += val[i-1];
    }
    int maxVal = 0, maxLen;
    double maxAvg = 0;
    for(int i = 2; i < 4 && N >= i; i++){
        for(int j = i; j <= N - i; j++){
            if((val[j] - val[j-i] + 1.0)/(i) > maxAvg){
                maxAvg = (val[j] - val[j-i] + 1.0)/(i);
                maxVal = (val[j] - val[j-i] + 1.0);
                maxLen = i;
            }
        }
    }
    //int g = gcd(maxVal, maxLen);
    cout << maxVal << "/" << maxLen << endl;
}
