int arr[N], cur[N];
bool vis[N];

void dfs(int currentIndex = 0){
    if(currentIndex == N){
        //output cur
        return;
    }
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            vis[i] = true;
            cur[currentIndex] = arr[i];
            dfs(currentIndex + 1);
            vis[i] = false;
        }
    }
}
