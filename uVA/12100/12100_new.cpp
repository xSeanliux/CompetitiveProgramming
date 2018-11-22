
#include <iostream>
#define SIZE 55
using namespace std;
int queue[SIZE], queue_front = 0, queue_back = 0, nums = 0;
int N;
int queue_push(int n)
{
    if(nums < SIZE)
    {
        nums++;
        queue_front++;
        queue[queue_front % SIZE] = n;
        return queue[queue_front % SIZE];
    }
    else
    {
        return -1;
    }

}

int queue_pop()
{
    if(nums > 0)
    {
        nums--;
        queue_back++;
        return queue[(queue_back)%SIZE];
    }
    else
    {
        return -1;
    }
}

int jobs, myJob, minutes;
int main(){
    while(cin >> N){

        for(int il = 0; il < N; il++){
            cin >> jobs >> myJob;
            minutes = 0;
            for(int i = 0; i < jobs; i++){ //input
                int k;
                cin >> k;
                queue_push(k);

            }
            bool flag = true;
            while(flag){
                for(int i = queue_back; i < queue_front; i++){ //find largest
                    if(queue[i] > queue[queue_back]){
                        cout << queue_back << " " << queue_front << endl;
                        cout << "Found " << queue[i] << " larger than " << queue[queue_back] << endl;
                        int t = queue_pop();
                        queue_push(t);

                        if(queue_back == myJob){
                            myJob = queue_front;
                        }
                    } else if(i == queue_front - 1){ //last thing
                        int k = queue_pop();
                        cout << "PRINTING : " << k << endl;
                        minutes++;
                        if(i == myJob){
                            flag = false;

                        }
                    }
                }
            }
            cout << "Minutes: " << minutes << endl;
        }
    }

}
