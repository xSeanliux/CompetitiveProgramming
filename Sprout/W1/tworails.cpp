


void solve(int N, int order[]){
    int r1[5005], r2[5005], head1 = 0, head2 = 0;
    int k;
    for(int i = 1; i <= N; i++){
        r1[head1++] = i;
        push_train();
    }
    for(int i = 0; i < N; i++){
        k = order[i];
        while(r1[head1 - 1] != k){
            r2[head2++] = r1[--head1];
            move_station_1_to_2();
        }
        move_station_1_to_2();
        pop_train();
        head1--;
        while(head2 > 0){
            r1[head1++] = r2[--head2];
            move_station_2_to_1();
        }
    }
}
