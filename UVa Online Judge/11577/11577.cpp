#include <iostream>
#include <string.h>
using namespace std;

int freq[27];
int cases;
char str[200+5];
char s[100];
int main()
{
    while(cin >> cases)
    {
        cin.getline(s, 1000);
        //cout << cases << endl;

        for(int ij = 0; ij < cases; ij++)
        {

            cin.getline(str, 1000);
            for(int i = 0; i < 27; i++){
                freq[i] = 0;
            }

            for(int i = 0; i < strlen(str); i++)
            {

                if('A' <= str[i] && str[i] <= 'Z'){
                    //cout << str[i] << " " << str[i]-'A' << endl;
                    freq[str[i]-'A']++;
                } else if('a' <= str[i] && str[i] <= 'z'){
                    //cout << str[i] << " " << str[i]-'a' << endl;
                    freq[str[i]-'a']++;
                }
            }
            int maxi = 0;
            for(int i = 0; i < 26; i++){
                if(freq[i] >= maxi) maxi = freq[i];
            }

            for(int i = 0; i < 26; i++){
                //cout << i << endl;
                if(freq[i] == maxi) cout << (char)(i+'a');
            }
            cout << endl;
        }

    }
}
