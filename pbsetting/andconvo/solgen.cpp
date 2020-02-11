#include <iostream>
#include <vector>
#include <fstream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;


/*
0 1
1 1
*/

/*
-1 1
 1 0
*/

int n, k, x;


vector<int> A, B;

inline void fmt(vector<int> &f, bool inv = false){
    int s, t;
    for(int stp = 2; stp <= f.size(); stp *= 2){
        for(int i = 0; i < f.size(); i += stp){
            for(int j = 0; j < stp/2; j++){
                s = f[i + j];
                t = f[i + j + stp/2];
                if(inv){
                    f[i + j] = -s + t;
                    f[i + j + stp/2] = s;
                } else {
                    f[i + j] = t;
                    f[i + j + stp/2] = s + t;
                }
            }
        }
    }
}

string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/andconvo/test_5";


signed main(){
    ericxiao;
    ofstream outfile;
    ifstream infile;
    for(int t = 25; t <= 34; t++){
        infile.open(s + "/" + to_string(t) + ".in");
        outfile.open(s + "/" + to_string(t) + ".out");
        cout << "Running test" << endl;
        infile >> n >> k;
        A.resize((1 << k));
        B.resize((1 << k));
        fill(A.begin(), A.end(), 0);
        fill(B.begin(), B.end(), 0);
        for(int i = 0; i < n; i++){
            infile >> x;
            A[x]++;
        }
        for(int i = 0; i < n; i++){
            infile >> x;
            B[x]++;
        }
        fmt(A);
        fmt(B);
        for(int i = 0; i < (1<<k); i++) A[i] *= B[i];
        fmt(A, 1);
        for(int i = 0; i < (1<<k); i++){
            outfile << A[i] << " ";
            cout << A[i] << " ";
        }
        cout << endl;
        infile.close();
        outfile.close();
    }

}
