#include <iostream>
#include <string.h>
using namespace std;

string s;
const int MAXN = 1e3;
int a, b, N, M;

struct Person{
    int val;
    Person *nPer;
    Person(int x): val(x), nPer(NULL){}
};

Person *cp;

struct Head{
    Person *sPer, *ePer;
    Head(): sPer(NULL), ePer(NULL){}
};

Head heads[MAXN + 10];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N + 5; i++){
        heads[i] = Head();
    }
    while(M--){
        cin >> s;
        if(s == "ADD"){
            cin >> a >> b;
            cp = new Person(b);
            if(!heads[a].sPer) heads[a].sPer = cp;
            if(!heads[a].ePer) heads[a].ePer = cp;
            else {
                heads[a].ePer->nPer = cp;
                heads[a].ePer = cp;
            }

        } else if(s == "LEAVE"){
            cin >> a;
            if(!heads[a].sPer){
                cout << "queue " << a << " is empty!" << endl;
            } else {
                cp = heads[a].sPer->nPer;
                delete heads[a].sPer;
                heads[a].sPer = cp;
                if(!heads[a].sPer) heads[a].ePer = NULL;
            }
        } else if(s == "JOIN"){
            cin >> a >> b;
            if(a == b) continue;
            if(!heads[b].sPer){
                heads[b].sPer = heads[a].sPer;
            } else {
                heads[b].ePer->nPer = heads[a].sPer;
            }
            if(heads[a].ePer) heads[b].ePer = heads[a].ePer;
            heads[a].sPer = NULL;
            heads[a].ePer = NULL;
            //printf("heads[%d].ePer: %d, heads[%d].sPer: %d\n", a, (heads[a].sPer) ? heads[a].sPer->val : -1, b, (heads[b].sPer) ? heads[b].sPer->val : -1);
        }
        /*
        for(int i = 1; i <= N; i++){
            printf("queue %d:", i);
            if(heads[i].sPer){
                cp = heads[i].sPer;
                while(cp){
                    printf(" %d", cp->val);
                    cp = cp->nPer;
                }
            } else {
                printf(" empty");
            }
            printf("\n");
        }
        printf("\n");
        */
    }

    for(int i = 1; i <= N; i++){
        cout << "queue " << i << ":";
        if(heads[i].sPer){
            cp = heads[i].sPer;

            while(cp){
                cout << " " << cp->val;
                cp = cp->nPer;
            }

        } else {
            cout << " empty";
        }
        cout << endl;
    }
}
