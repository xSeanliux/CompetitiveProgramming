#include <iostream>
#include <string>
using namespace std;

int cases, maxnum;
string s, c, t;
int main()
{
    cin >> cases;
    getline(cin, t);
    for(int ias = 1; ias <= cases; ias++)
    {
        getline(cin, s);
        maxnum = 0;
        c = "";
        int l = s.length();
        for(int i = 0; i < l; i++)
        {
            if(s[i] == ' ')
            {
                if(c != "")
                {
                    int temp = stoi(c);
                    if(temp > maxnum) maxnum = temp;
                }

                c = "";

            }
            else
            {
                c += s[i];
                if(i == l-1)
                {
                    int temp = stoi(c);

                    if(temp > maxnum) maxnum = temp;
                }


            }
        }
        printf("Case %d: %d\n", ias, maxnum);

    }

}


