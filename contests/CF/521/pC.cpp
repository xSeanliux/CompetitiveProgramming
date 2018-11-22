#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, k;

struct Pair{
    int val;
    int ind;
};

bool cmp(const Pair &a, const Pair &b){
    return a.val < b.val;
}

int main(){
    cin >> N;
    //cout << "N = " << N << endl;
    Pair arr[N];
    map<int, int> cnt;
    long long int sum = 0;
    for(int i = 0 ; i < N; i++){
        cin >> arr[i].val;
        arr[i].ind = i;
        //printf("arr[%d] = %d\n", i, arr[i]);
        sum += arr[i].val;
        if(cnt.count(arr[i].val)){
            cnt[arr[i].val]++;
        } else {
            cnt.insert(pair<int, int>(arr[i].val, 1));
        }
    }
    int ansC = 0;
    vector <int> answers;
    sort(arr, arr + N, cmp);
    for(int i = 0 ; i < N; i++){
        long long int newS = sum - arr[i].val;
        cnt[arr[i].val]--;
        //printf("cnt[%d]--\n", arr[i].val);
        if(!(newS % 2)){
            int U = N, L = 0, M = (U + L)/2;
            //printf("U = %d, L = %d, M = %d, arr[M].val = %d\n",U, L, M, arr[M].val);
            while(U > L && arr[M].val != newS/2){
                //printf("U = %d, L = %d, M = %d, arr[M].val = %d\n",U, L, M, arr[M].val);
                if(arr[M].val > newS/2){
                    U = M;
                } else {
                    L = M;
                }
                if((U + L)/2 == M) break;
                M = (U + L)/2;
                //printf("U = %d, L = %d, M = %d, arr[M].val = %d\n",U, L, M, arr[M].val);
            }
            //printf("cnt[%d] = %d\n",arr[M].val, cnt[arr[M].val]);
            if(arr[M].val == newS/2 && cnt[arr[M].val] > 0){
                ansC++;
                answers.push_back(arr[i].ind + 1);
            }
        }
        cnt[arr[i].val]++;
    }
    //cout << ansC << endl;
    if(!ansC){
        cout << 0 << endl;
    } else {
        int L = answers.size();
        cout << L << endl;
        cout << answers[0];
        for(int i = 1 ; i < L; i++){
            cout << " " << answers[i];
        }
        cout << endl;
    }
}
