#include <iostream>
#include <string.h>
#include <map>
using namespace std;

string header, enc;
 //0s and 1s - char
map<string, char> dict;

int toDec(string s){
    int ans = 0, l = s.length();
    for(int i = 0; i < l; i++){
        ans += (s[i] - '0');
        ans *= 2;
    }
    return ans / 2;
}

bool isAllOnes(string s){
    int l = s.length();
    for(int i = 0; i < l; i++){
        if(s[i] == '0') return false;
    }
    return true;
}

string toBinary(int K, int L){
    string s = "";
    int oriK = K;
    while(K > 0){
        s = (char)((K % 2) + '0') + s;
        K /= 2;
        //cout <<s << endl;
    }
    while(s.length() < L){
        s = '0' + s;
    }
    return s;
}

int main(){
    while(getline(cin, header)){
        dict = map<string, char>();
        int maxIndex = 1, currentIndex = 0, currentLen = 1, lH = header.length();
        dict.insert(pair<string, char>("0", header[0]));
        for(int i = 1; i < lH; i++){
            if(currentIndex >=  maxIndex - 1){
                currentIndex = 0;
                maxIndex *= 2;
                if(maxIndex == 2) maxIndex *= 2;
                currentLen++;
                dict.insert(pair<string, char>(toBinary(currentIndex, currentLen), header[i]));
                //cout << header[i] << ":" << toBinary(currentIndex, currentLen) << endl;
            } else {
                dict.insert(pair<string, char>(toBinary(currentIndex, currentLen), header[i]));
                //cout << header[i] << ": " << toBinary(currentIndex, currentLen) << endl;
            }
            currentIndex++;
            //cout << "CI: " << currentIndex << endl;
        }
        //I need to decode the header lol
        string totalMsg = "";
        int l = totalMsg.length();
        cin >> totalMsg;
        for(int i = 0; ; i++){
            //cout << "i = " << i << ", substr: " << totalMsg.substr(i, 3) << endl;
            if(i + 2 >= totalMsg.length()){
                cin >> enc;
                totalMsg += enc;
            }
            int len = toDec(totalMsg.substr(i, 3));
            if(!len) break;
            //cout << "len = " << len << endl;
            i += 3;
            if(i + len - 1 >= totalMsg.length()){
                cin >> enc;
                totalMsg += enc;
            }
            string s = totalMsg.substr(i, len);
            //cout << "s = " << s << endl;
            while(!isAllOnes(s)){
                cout << dict[s];
                i += len;
                //cout << "BF" << endl;
                if(i + len - 1 >= totalMsg.length()){
                    cin >> enc;
                    totalMsg += enc;
                }
                s = totalMsg.substr(i, len);
                //cout << "s = " << s << endl;
                //cout << "i = " << i << endl;
            }
            i += len-1;
            //cout << "end of len, starting new one, i = " << i << endl;
        }
        cout << endl;
        getline(cin, header);
        getline(cin, header);

    }
}
