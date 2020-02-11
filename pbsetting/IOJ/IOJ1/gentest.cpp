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

int A[10] = {0, -2147483648, 2147483646, 123131, 0, 22600, 19, 101010100, -100000, 1}, B[10] = {-5312, 100, 1, 999999, -0, 25, 11, 999999, 100000, 9};

string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/IOJ/IOJ1/tests";


signed main(){
    ericxiao;
    ofstream infile;
    for(int t = 1; t <= 10; t++){
        infile.open(s + "/" + to_string(t) + ".in");
        infile << A[t - 1] << " " << B[t - 1] << endl;
        infile.close();
    }

}

