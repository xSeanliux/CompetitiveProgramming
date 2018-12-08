#include<iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dl = 0;
string data[120000];
bool isDone[120000];
bool searchgo( string in )
{
    int low = 0, up = dl-1, mid, t;
    //cout << "test:" << in;
    while( low <= up )
    {

        if( in == data[mid] ) return true;
        t = strcmp( in.c_str(), data[mid].c_str() );

        if( t == 1 )
          low = mid;
        else
          up = mid;
        mid = (low+up)/2;
    }
    //cout << "   " << low << ' ' << up << endl;
    return false;
}

int main()
{
    int i, j, l;
    dl = 0;
    while( cin >> data[dl]){
        isDone[dl] = false;
        dl++;

        for( i = 0 ; i < dl ; i++ )
        {
            l = data[i].length();
            //cout << data[i] << " :";
            for( j = l-1 ; j >= 1 ; j--)
            {
                cout << data[i].substr(j) <<  "   " << data[i].substr( 0, j ) << endl;
                //cout << ' ' << j << endl;
                if( searchgo( data[i].substr(j) )  && !isDone[i]){
                        if( searchgo( data[i].substr( 0, j ) ) )
                  {
                     isDone[i] = true;
                     cout << data[i] << endl;
                     break;
                  }

                }

            }
        }
    }



    //cout << dl << endl;

    //system( "pause" );
    return 0;
}


