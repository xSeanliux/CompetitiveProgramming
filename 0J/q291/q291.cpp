#include <iostream>
using namespace std;
int adjacent[6][6] = {{},{0,0,1,1,0,1},
                         {0,1,0,1,0,1},
                         {0,1,1,0,1,1},
                         {0,0,0,1,0,1},
                         {0,1,1,1,1,0}};

int numList[9]; //the actual output




void DFS(int currentNode, int iteration)
{
        numList[iteration] = currentNode;

        if(iteration == 8){ //went to all nodes
            for(int i = 0; i < 9; i++){
                cout << numList[i];
            }
            cout << endl;
        }
        for(int i = 1; i <= 5; i++)
        {
            if(adjacent[currentNode][i] == 1)  //if there is a road and we haven't went there yet.
            {
                adjacent[currentNode][i] = 2;
                adjacent[i][currentNode] = 2; //set it to visited to make sure we don't go backwards


                DFS(i, iteration+1);

                adjacent[currentNode][i] = 1; //set it back so that later callbacks can use this path
                adjacent[i][currentNode] = 1;

            }
        }
}


int main()
{
    DFS(1,0);
}
