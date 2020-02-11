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

int A, B;

string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/IOJ/IOJ1/tests";

signed main(){
    ericxiao;
    ofstream outfile;
    ifstream infile;
    for(int t = 1; t <= 10; t++){
        infile.open(s + "/" + to_string(t) + ".in");
        outfile.open(s + "/" + to_string(t) + ".out");
        cout << "Running test" << endl;
        infile >> A >> B;
        outfile << A + B << endl;
        infile.close();
        outfile.close();
    }

}
