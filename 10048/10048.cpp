#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool hasRoad[100 + 5][100 + 5];
int roadLength[100 + 5][100 + 5];
int minDec[100 + 5][100 + 5];
int C, S, Q, s, e, d, c = 0;

int main()
{
    while(cin >> C >> S >> Q)
    {
        if(!C && !S && !Q) return 0;
        for(int i = 0 ; i < 105; i++)
        {
            for(int j = 0; j < 105; j++)
            {
                hasRoad[i][j] = false;
                roadLength[i][j] = 0;
                minDec[i][j] = 100000;
            }
        }
        for(int i = 0 ; i < S; i++)
        {
            cin >> s >> e >> d;
            hasRoad[s][e] = true;
            hasRoad[e][s] = true;
            roadLength[s][e] = d;
            roadLength[e][s] = d;
            minDec[e][s] = d;
            minDec[s][e] = d;
        }
        for(int i = 0 ; i < C ; i++)
        {
            minDec[i][i] = 0;
        }
        //Floyd-Warshall
        for(int k = 1; k <= C; k++)
        {
            for(int i = 1; i <= C; i++)
            {
                for(int j = 1; j <= C; j++)
                {
                    minDec[i][j] = min(max(minDec[i][k], minDec[j][k]), minDec[i][j]);
                    //cout << "minDec[" << i << "][" << j << "] = " << minDec[i][j] << endl;
                }
            }
        }
        if(c)
        {
            cout << endl;
        }
        printf("Case #%d\n", ++c);
        for(int i = 0 ; i< Q; i++)
        {
            cin >> s >> e;
            if(minDec[s][e] > 50000)
            {
                cout << "no path" << endl;
            }
            else
            {
                cout << minDec[s][e] << endl;
            }
        }

    }
}
