#pragma gcc optimize ("O3")
#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#define lli long long int
#define lld long long int
using namespace std;

const int MAX = 2e5, BL = 30, LEN = 8e5;
lli x, k;
int n, q;
lli num_arr[MAX];
int arr[MAX];

bool hasBit(lli x, int j){
    return (x & ((lli)1 << j));
}

int scan_d() {
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

lld scan_lld() {
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

class BIT{
public:
    vector<int> bit;
    bool lazy[LEN];
    void build(int id, int l, int r, int bitnum){
        //cout << "Building id = " << id << ", (l, r) = " << l << ", " << r << endl;
        if(l + 1 == r){
            bit[id] = hasBit(num_arr[l], bitnum);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id + 1, l, mid, bitnum);
        build(2 * id + 2, mid, r, bitnum);
        bit[id] = bit[2 * id + 1] + bit[2 * id + 2];
    }

    int query(int id, int ql, int qr, int l, int r){
        if(lazy[id]){
            bit[id] = (r - l) - bit[id];
            lazy[id] = false;
            if(r - l > 1){
                lazy[2 * id + 1] = !lazy[2 * id + 1];
                lazy[2 * id + 2] = !lazy[2 * id + 2];
            }
        }
        if(ql >= r || qr <= l) return 0;
        if(ql <= l && r <= qr) return bit[id];
        int mid = (l + r) / 2;
        //if(qr < l + r >> 1) return query(2 * id + 1, ql, qr, l, (l + r)/2);
        //if(ql >= l + r >> 1) return query(2 * id + 2, ql, qr, (l + r)/2, r);
        return query(2 * id + 1, ql, qr, l, mid) + query(2 * id + 2, ql, qr, mid, r);
        //return
    }

    void modify(int ql, int qr, int id, int l, int r){
        //printf("query: (%lld, %lld), curren tseg: (%lld, %lld), id = %lld\n", ql, qr, l, r, id);
        if(lazy[id]){
            bit[id] = (r - l) - bit[id];
            lazy[id] = false;
            if(r - l > 1){
                lazy[2 * id + 1] = !lazy[2 * id + 1];
                lazy[2 * id + 2] = !lazy[2 * id + 2];
            }
        }
        if(ql >= r || qr <= l) return; //out of range
        if(ql <= l && r <= qr){
            //printf("bit[%lld] was %lld ", id, bit[id]);
            bit[id] = (r - l) - bit[id];
            //printf("but is now %lld\n", bit[id]);
            if(r - l > 1){
                lazy[2 * id + 1] = !lazy[2 * id + 1];
                lazy[2 * id + 2] = !lazy[2 * id + 2];
            }
            return;
        }
        int mid = (l + r)/2;
        modify(ql, qr, 2 * id + 1,l, mid);
        modify(ql, qr, 2* id + 2, mid, r);
        //printf("bit[%lld] was %lld ", id, bit[id]);
        bit[id] = bit[2 * id + 1] + bit[2 * id + 2];
        //printf("but is now %lld\n", bit[id]);
    }

    BIT(){
        bit.reserve(4*n);
    }

};




BIT bits[BL];

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //scanf("%d %d", &n, &q);
    unsigned long long int start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    n = scan_d();
    q = scan_d();
    //cout << n << " " << q << endl;
    //cout << "H" << endl;
    //num_arr.reserve(n + 1);
    //cout << sizeof(BIT) << endl;

    for(int i = 0; i < n; i++){
        //scanf("%lld", &x);
        num_arr[i] = scan_lld();
    }

    for(int i = 0; i < BL; i++){
        bits[i] = BIT();
        bits[i].build(0, 0, n, i);
    }
    //cout << "Finished building" << endl;
    lli com, arg1, arg2, toXor, res;
    for(int i = 0; i < q; i++){
        com = scan_lld();
        arg1 = scan_lld();
        arg2 = scan_lld();
        //scanf("%lld %lld %lld", &com, &arg1, &arg2);
        //printf("%d %d %d\n", com, arg1, arg2);
        if(com == 1){
            //scanf("%lld", &toXor);
            toXor = scan_lld();
            for(int i = 0; i < BL; i++){
                if(hasBit(toXor, i)){
                    //printf("Modifying (%llu to %llu) of the %llu th bit\n", arg1-1, arg2, i);
                    bits[i].modify(arg1 - 1, arg2, 0, 0, n);
                }
            }
        } else {
            k = 1;
            res = 0;
            for(int i = 0; i < BL; i++){
                res += (k * bits[i].query(0, arg1 - 1, arg2, 0, n));
                k <<= 1;
            }
            //cout << res << '\n';
            print(res);
            //printf("%lld\n", res);
        }
    }
    unsigned long long int endt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    printf("%lldms\n", endt - start);
    //cout << "Done" << endl;
}
