#include <iostream>
#include <vector>
#define lli long long int
#define lld long long int
using namespace std;

const int LEN = 2e5, BITS = 30;
lli arr[LEN * 3], toXor;
int n, q, com, a1, a2;

bool hasBit(lli x, int bit){
    return (x & ((lli)1 << bit));
}

inline int scan_d() {
	int ip=getchar_unlocked(),ret=0,flag=1;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())
	if(ip=='-'){
		flag=-1;
		ip=getchar_unlocked();
		break;
	}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';
	return flag*ret;
}

inline lld scan_lld() {
	int ip=getchar_unlocked(),flag=1;
	lld ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())
		if(ip=='-'){
			flag=-1;
			ip=getchar_unlocked();
			break;
		}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';
	return flag*ret;
}

template<typename T>
	inline void print(T n)
	{
		if (n == 0)
		{
			putchar_unlocked('0');
			putchar_unlocked('\n');
		}
		else if (n == -1)
		{
			putchar_unlocked('-');
			putchar_unlocked('1');
			putchar_unlocked('\n');
		}
		else
		{
			char buf[11];
			buf[10] = '\n';
			int i = 9;
			while (n)
			{
				buf[i--] = n % 10 + '0';
				n /= 10;
			}
			while (buf[i] != '\n')
				putchar_unlocked(buf[++i]);
		}
	}

struct Node{
    int bits[BITS];
    bool lazy[BITS];
    Node(lli k){
        for(int i = 0; i < BITS; i++){
            bits[i] = hasBit(k, i);
            lazy[i] = false;
        }
    }

    Node(Node l, Node r){
        for(int i = 0; i < BITS; i++){
            bits[i] = l.bits[i] + r.bits[i];
            lazy[i] = false;
        }
    }

    Node(){}

    lli getVal(){
        lli res = 0;
        for(int i = 0; i < BITS; i++){
            res += bits[i] * ((lli) 1<< i);
        }
        return res;
    }

};

vector<Node> segTree;


void build(int id, int l, int r){
    if(l + 1 == r){
        segTree[id] = Node(arr[l]);
    } else {
        build(2 * id + 1, l, l + r >> 1);
        build(2 * id + 2, l + r >> 1, r);
        segTree[id] = Node(segTree[2 * id + 1], segTree[2 * id + 2]);
    }
}

void modify(int id, int ql, int qr, int l, int r, lli toXor){
    for(int i = 0; i < BITS; i++){
        if(segTree[id].lazy[i]){
            segTree[id].lazy[i] = false;
            segTree[id].bits[i] = (r - l) - segTree[id].bits[i];
            if(r - l > 1){
                segTree[2 * id + 1].lazy[i] ^= 1;
                segTree[2 * id + 2].lazy[i] ^= 1;
            }
        }
    }
    if(ql >= r || qr <= l) return;
    if(ql <= l && r <= qr){
        for(int i = 0; i < BITS; i++){
            if(hasBit(toXor, i)){
                segTree[id].lazy[i] = false;
                segTree[id].bits[i] = (r - l) - segTree[id].bits[i];
                if(r - l > 1){
                    segTree[2 * id + 1].lazy[i] ^= 1;
                    segTree[2 * id + 2].lazy[i] ^= 1;
                }
            }
        }
        return;
    }
    modify(2 * id + 1, ql, qr, l, l + r >> 1, toXor);
    modify(2 * id + 2, ql, qr, l + r >> 1, r, toXor);
    for(int i = 0; i < BITS; i++){
        segTree[id].bits[i] = segTree[2 * id + 1].bits[i] + segTree[2 * id + 2].bits[i];
    }
}

lli query(int id, int ql, int qr, int l, int r){
    for(int i = 0; i < BITS; i++){
        if(segTree[id].lazy[i]){
            segTree[id].lazy[i] = false;
            segTree[id].bits[i] = (r - l) - segTree[id].bits[i];
            if(r - l > 1){
                segTree[2 * id + 1].lazy[i] ^= 1;
                segTree[2 * id + 2].lazy[i] ^= 1;
            }
        }
    }
    //printf("Running query(%d, %d), current segment : (%d, %d)\n", ql, qr, l, r);
    if(ql >= r || qr <= l) return 0;
    if(ql <= l && r <= qr) return segTree[id].getVal();
    return query(2 * id + 1, ql, qr, l, l + r >> 1) + query(2 * id + 2, ql, qr, l + r >> 1, r);
}


int main(){
    n = scan_d();
    q = scan_d();
    segTree.reserve(4 * n);
    for(int i = 0; i < n; i++) arr[i] = scan_lld();
    build(0, 0, n);
    while(q--){
        com = scan_d();
        a1 = scan_d();
        a2 = scan_d();
        if(com == 1){ //modify
            toXor = scan_lld();
            modify(0, a1 - 1, a2, 0, n, toXor);
        } else { //query
            print(query(0, a1 - 1, a2, 0, n));
        }
    }
}
