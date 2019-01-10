#include <iostream>
#define SIZE 1000
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

void print_queue(){
    //cout << "q_start: " << queue_front << ", q_back: " << queue_back << endl;
    for(int i = queue_back+1; i < queue_front; i++){
        cout << queue[i] << "  ";

    }
    cout << endl;
}

int main()
{
    int myJob;
    int numOfJobs;
    while(cin >> N){


        for(int il = 0; il < N; il++)
        {
            //cout << "Order: " << il << endl;
            queue_front = 0, queue_back = 0, nums = 0;
            cin >> numOfJobs >> myJob;
            //cout << "Jobs: " << numOfJobs << ", Job: " << myJob << endl;
            myJob++; //starts at one, so 0 -> 1
            //cout << "JH" << endl;
            for(int i = 0; i < numOfJobs; i++)
            {
                int t;
                cin >> t;
                //cout << t << endl;
                queue_push(t);
            }


            int minutes = 0;
            int currentIndex = queue_back;
            bool flag = true;

            if(numOfJobs == 1){
                minutes++;
                flag = false;
            }

            while(flag)
            {
                currentIndex++;
                //currentIndex = ;
                for(int j = queue_back + 1; j <= queue_front; j++)
                {
                    //cout << "Job index: " << myJob << "  cI: " <<currentIndex<< endl;
                    if(queue[currentIndex] < queue[j]){ //found a bigger one
                        //cout << "Found " << queue[j] << " bigger than " << queue[currentIndex] << endl;


                        //cout << "Moving " << t << " to end" << endl;
                        int t = queue_pop();

                        queue_push(t);
                        if(currentIndex == myJob){
                            myJob = queue_front;
                        }
                        //currentIndex++;
                        break;

                    } else if(j == queue_front-1){
                        //cout << "q_start: " << queue_front << ", q_back: " << queue_back << endl;
                        int l = queue_pop();
                        //cout << "q_start: " << queue_front << ", q_back: " << queue_back << endl;
                        //cout << "PRINTING " << l << endl;
                        //queue_pop();
                        minutes++;
                        if(myJob == currentIndex){
                            flag = false;


                        }


                    }

                }
                if(queue_back - queue_front >= 0){
                    flag = false;
                }

                print_queue();
                numOfJobs--;



            }
            cout << minutes << endl;


        }
        return 0;
    }

}
