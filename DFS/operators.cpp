#include<iostream>
using namespace std;

int N;
int num[100]; //0~N-1
char op[100];  //1~N-1

void dfs( int now )
{
    cout << "Now running dfs(" << now << ")" << endl;
	if( now >= N )
	{
	    cout << "dfs(" << now << ") is larger than " << N << "." << endl;
		int i;
		cout << num[0];
		for( i=1 ; i<N ; i++ )
		//	cout << " " << op[i] << num[i];
		cout << endl;
	}
	else
	{
		op[now] = '+';
		cout << "op[" << now << "] is now the + sign. Running dfs(" << now+1 << "). " << endl;
		dfs( now+1 ); //C++ will do this first before moving on to the next one
		cout <<"+: now :" << now << endl;


		op[now] = '-';
		cout << "op[" << now << "] is now the - sign. Running dfs(" << now+1 << "). " << endl;
		dfs( now+1 );
		cout <<"-: now :" << now << endl;


		op[now] = '*';
		cout << "op[" << now << "] is now the * sign. Running dfs(" << now+1 << "). " << endl;
		dfs( now+1 );
		cout <<"*: now :" << now << endl;

	}
}

int main()
{
	int i;

	cin >> N;
	for( i=0 ; i<N ; i++ )
		cin >> num[i];

	dfs( 1 );

	return 0;
}
