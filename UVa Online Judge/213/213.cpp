#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;

string com, lenCom, keyCom, fin;
map <string, char> dict;
int len, g = 0;
char c;

string toBinStr(int n){
    return bitset< 64 >( n ).to_string(); // string conversion

}
//bitset< 64 >( 12345 ).to_string(); // string conversion


bool isValid(string s){
    int l = s.length();
    if(!l) return true;
    for(int i = 0 ; i < l; i++){
        if(s[i] != '1') return true;
    }
    return false;
}

int main(){
    while(getline(cin, com)){
        fin = "";
        dict.clear();
        int currentPower = 0;
        int l = com.length();
        int val = 0;
        //cout <<pow(2, currentPower) << endl;
        for(int i = 0 ; i < l; i++){
            string s = toBinStr(val);
            while(s.length() <= currentPower+1){
                //cout << "h" << endl;
                s = '0' + s;
            }
            while(s.length() > currentPower+1){
                //cout << "j" << endl;
                s = s.substr(1);
            }
            //cout << "proper length: " << s.length() << " ";
            //cout << s << endl;
            val++;
            if(val == pow(2, currentPower+1)-1){
                currentPower++;
                val = 0;
            }
            dict.insert(pair<string, char>(s, com[i]));
            cout << s << " : " << com[i] << endl;
        }
        while(cin.get(c)){
            keyCom = "";
            while(c == '\n') cin.get(c);
            //cout << c << endl;
            //printf("len += %d * %d\n", (c - '0'), 4);
            len = (c - '0')*4;
            //cout << "hey " << len << endl;
            int k = 2;
            while(k--){
                //cout << " K : " << k << endl;
                cin.get(c);
                while(c == '\n') {cin.get(c);};
                //cout << c << endl;
                len += (c - '0')*pow(2, k);
                //printf("len += %d * pow(2, %d) = %d\n", (c - '0'), k, (c - '0')*pow(2, k));
            }
            if(!len || (cin.peek() != '0' || cin.peek() != '1' || cin.peek() != '\n')){
                cout << fin;
                if(g)
                    cout << endl;
                else
                    g++;
                getline(cin, com);
                break;
            }
            //cout << "len: " << len << endl;
            while(isValid(keyCom)){
                keyCom = "";
                int currentCount = 0;
                while(currentCount < len){
                    cin.get(c);
                    if(c != '\n'){
                        keyCom += c;
                        currentCount++;
                    }
                }
                //cout << "key: " << keyCom << endl;
                map<string, char>::iterator ans = dict.find(keyCom);
                fin += ans -> second;
            }


        }

    }
}

/*

TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
0100000101101100011100101000
TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
0100000101101100011100101000
*/
