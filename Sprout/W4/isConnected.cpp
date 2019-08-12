int N, times[1505], R = 10210312, cnt = 0, X;
bool isOk[1505];

void initialize(int n){
    N = n;
    X = N - 1;
    for(int i = 0; i < N; i++){
        times[i] = 0; isOk[i] = true;
    }
}

int hasEdge(int a, int b){
    if(!(isOk[a] & isOk[b])) return false;
    bool toRet = false;
    times[a]++; times[b]++;
    if(times[a] == X){
        X--;
        toRet = true;
        isOk[a] = false;
    } else if(times[b] == X){
        X--;
        toRet = true;
        isOk[b] = false;
    }
    return toRet;
}


