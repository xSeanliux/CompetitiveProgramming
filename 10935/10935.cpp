#include <iostream>
using namespace std;
#define SIZE 55
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

int main()
{

    while(cin >> N)
    {
        if(N == 0)
        {
            return 0;
        } else if(N == 1){
            cout << "Discarded cards:" << endl;
        cout << "Remaining card: 1" << endl;

        }
        else
        {
            int t;
            queue_front = 0;
            queue_back = 0;
            nums = 0;
            for(int i = 1; i <= N; i++)
            {
                queue_push(i); //init cards
            }
            cout << "Discarded cards: ";
            while(N >= 2)
            {

                if(N == 2)//last one
                {
                    cout <<queue_pop() << endl;
                }
                else
                {
                    cout <<queue_pop() << ", ";
                }

                t = queue_pop();

                N--;
                queue_push(t);
            }
            cout << "Remaining card: " << t << endl;

        }
    }


}
