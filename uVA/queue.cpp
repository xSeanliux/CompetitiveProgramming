
#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 5
int queue[SIZE], queue_front, queue_back, nums = 0;

void queue_push( int n )
{
    if(nums < SIZE){
        queue_front++;
        queue[queue_front % SIZE] = n;
        nums++;
        cout <<  "push: " << queue[(queue_front) % SIZE] << endl;;
    } else {
        cout << "queue full" << endl;
    }


}

int queue_pop()
{

    if(nums > 0){
        queue_back++;
        nums--;
        return queue[(queue_back) % SIZE];
    } else {
        cout << " nothing in queue " << endl;
        return -1;
    }
}

int main ()
{
    string cmd;
    int i;
    queue_front = 0;
    queue_back = 0;

    while( cin >> cmd )
    {
        if( cmd == "push" )
        {
            cin >> i;
            queue_push( i );
        }
        else if( cmd == "pop" )
        {
            cout << " pop:" << queue_pop() << endl;
        }
    }

    return 0;
}
