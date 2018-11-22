#include <iostream>
#include <string.h>
using namespace std;
string pre, in;
string recon;



void run(string pre, string in){
    //cout << "Running : pre: " << pre << ", in: " << in << endl << endl;
    if(in.length() == 0 || pre.length() == 0){
        return;
    }else {
        //cout << pre[0];
        //if(in[0] == pre[0]){
            //run(pre.substr(1), in.substr(1));
        //} else {

            int i, j, li = in.length();
            for(i = 0 ; i < li; i++){
                //cout << "in[" << i << "] = " << in[i] << endl;
                if(pre[0] == in[i]) break;
            }
            string i1 = in.substr(0, i);
            //cout << "a, i1:" << i1 << ", i = " << i <<endl;
            string i2 = in.substr(i+1, li);
            //cout << "a, i2: " << i2 << endl;
            string pre1, pre2;
            char c = i1[0];
            pre1 = pre.substr(1, i1.length());
                    //cout << "a" << endl;
            pre2 = pre.substr(i1.length() + 1);
            /*
            for(j = 1 ; j <= i1.length(); j++){
                if(c == pre[j]){
                    pre1 = pre.substr(1, i1.length());
                    //cout << "a" << endl;
                    pre2 = pre.substr(i1.length() + 1);
                    //cout << "a" << endl;
                }
            }
            if(pre1 == ""){
                pre2 = pre.substr(1, i1.length());
                //cout << "a" << endl;
                pre1 = pre.substr(i1.length() + 1);
                //cout << "a" << endl;
            }
            *//*
            cout << "i1: " << i1 << endl;
            cout << "i2: " << i2 << endl;
            cout << "pre1: " << pre1 << endl;
            cout << "pre2: " << pre2 << endl;
            */
            run(pre1, i1);
            run(pre2, i2);
            cout << pre[0];
        //}
    }
}

int c, n;
int main(){
    cin >> c;
    for(int a = 0; a < c; a++){
        cin >> n >> pre >> in;
        run(pre, in);
        cout << endl;
        //cout << pre[0];
    }
}
