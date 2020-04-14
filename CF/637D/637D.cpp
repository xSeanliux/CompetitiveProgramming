#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct Data{
    int loc;
    bool canDo;
    int from;
};

int N, M, S, D;
vector <string> vec;

int main(){
    scanf("%d%d%d%d", &N, &M, &S, &D);
    Data arr[N + 2];
    for(int i = 1; i <= N; i++){
        cin >> arr[i].loc;
        arr[i].canDo = false;
        arr[i].from = -1;
    }
    arr[0].loc = -1;
    arr[0].from = -1;
    arr[0].canDo = true;
    bool flag = true;
    arr[N+1].loc = M+1;
    for(int i = 1; i <= N; i++){
        //cout << "Checking segment from " << arr[i-1].loc << " to " << arr[i].loc << endl;
        int target = arr[i].loc + 1;
        int j = i-1;
        while(j >= 0 && target - arr[j+1].loc + 1 <= D){
            //cout << "Current segment: from" << arr[j].loc << " to " << arr[j+1].loc << endl;
            if(arr[j].canDo && arr[j+1].loc - arr[j].loc - 1 >= S){
                arr[i].canDo = true;
                arr[i].from = j;
                //cout << "The segment from " << arr[i-1].loc << " to " << arr[i].loc << " is reachable" << endl;
                break;
            }
            j--;
        }
    }
    if(arr[N].canDo){
        vec.clear();
        string s;
        int currentIndex = N, currentLoc = M;
        while(currentIndex > 0 && currentLoc > 0){
            cout << "Nearest obstacle at " << arr[currentIndex].loc << ", at " << currentLoc << endl;
            if(M > arr[N].loc + 1){
                //cout << currentLoc - arr[currentIndex].loc-1 << endl;
                s = ("RUN " + to_string(currentLoc - arr[currentIndex].loc-1));
                cout << s << endl;
                vec.push_back(s);
            }
            currentLoc = arr[currentIndex].loc + 1;
            cout << "am now at" << currentLoc << endl;
            int f = arr[currentIndex].from;

            cout << "will be jumping to the segment starting at " << arr[f].loc << " to " << arr[f+1].loc << endl;
            s = ("JUMP " + to_string(currentLoc - arr[f + 1].loc + 1 ));
            cout << s << endl;
            vec.push_back(s);
            if(f == 0) {
                s = ("RUN " + to_string(currentIndex));
                vec.push_back(s);
                break;
            }
            currentIndex = f;
            currentLoc -= currentLoc - arr[f + 1].loc + 1;


            cout << "am now at" << currentLoc << endl;


        }
        if(flag){
            or(int i = vec.size() - 1; i >= 0; i--){
            cout << vec[i] << endl;
        }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
        cout << endl << endl;
        for(int i = vec.size() - 1; i >= 0; i--){
            cout << vec[i] << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
