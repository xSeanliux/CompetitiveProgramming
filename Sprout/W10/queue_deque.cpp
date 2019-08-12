#include <iostream>
#include <string.h>
#include <deque>
#define ericxiao ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int block_size = 350;
deque<int> dx[1005];

void Add(int pos, int val){
    int block_id = (pos - 1) / block_size;
    int kth_num = (pos - 1) % block_size;
    dx[block_id].insert(dx[block_id].begin() + kth_num, val);
    int k;
    while(dx[block_id].size() == block_size  + 1){
        k = dx[block_id].back();
        dx[block_id].pop_back();
        dx[block_id + 1].push_front(k);
        block_id++;
    }
}

void Delete(int pos){
    int block_id = (pos - 1) / block_size;
    int kth_num = (pos - 1) % block_size;
    dx[block_id].erase(dx[block_id].begin() + kth_num);
    int k;
    while(dx[block_id].size() < block_size && dx[block_id + 1].size()){
        k = dx[block_id + 1].front();
        dx[block_id].push_back(k);
        dx[block_id + 1].pop_front();
        block_id++;
    }
}

int Query(int pos){
    int block_id = (pos - 1) / block_size;
    int kth_num = (pos - 1) % block_size;
    return dx[block_id].at(kth_num);
}

int N, M, k, x;
string com;

int main(){
    ericxiao
    cin >> N >> M;
    for(int i = 0; i <= max(N, M)/block_size + 2; i++){
        dx[i] = deque<int>();
    }
    for(int i = 1; i <= N; i++){
        cin >> x;
        Add(i, x);
    }
    for(int i = 0; i < M; i++){
        cin >> com;
        if(com == "ADD"){
            cin >> k >> x;
            Add(k, x);
        } else if(com == "LEAVE"){
            cin >> k;
            Delete(k);
        } else if(com == "QUERY"){
            cin >> k;
            cout << Query(k) << endl;
        }
    }
}
