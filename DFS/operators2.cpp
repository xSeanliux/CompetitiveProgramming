#include <iostream>

using namespace std;
char op[101];
int nums[101];
int N;

void DFS( int nth )
{
    cout << "Running DFS(" << nth << "). " << endl;

    if(nth >= N)
    {
        cout << nums[0];
		for( int i=1 ; i<N ; i++ )
			cout << " " << op[i] << nums[i];
		cout << endl;


    }
    else
    {
        op[nth] = '+'; //I've done my part, now the next one
        DFS(nth+1);
        op[nth] = '-'; //I've done my part, now the next one
        DFS(nth+1);
        op[nth] = '*'; //I've done my part, now the next one
        DFS(nth+1);



    }




    //run




}

int main()
{

    while(cin >> N)
    {
        for(int i = 0; i < N; i++)
        {
            cin >> nums[i];
        }
        //DFS Algorithm
        DFS(1);

    }
}
