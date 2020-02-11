#include "Land.h"

namespace{
	constexpr int _MAX_C = 1000000000;
	constexpr int _MAX_NUM_QUERY = 128;
	int _count=0,_a,_b,_c,_d;
	bool _valid(int x){
		if(x<0||x>_MAX_C) return 0;
		return 1;
	}
	int _max(int a,int b){
		if(a>b) return a;
		return b;
	}
	int _min(int a,int b){
		if(a<b) return a;
		return b;
	}
	void _input(int *x){
		scanf("%d",x);
	}
	void _wrong_answer(const char *MSG) {
		printf("Wrong Answer: %s\n", MSG);
		exit(0);
	}
	void _Accepted(const int c){
		printf("Accepted: %d\n",c);
	}
}

long long area(int x1, int y1, int x2, int y2){
	++_count;
	if(_count>_MAX_NUM_QUERY)
		_wrong_answer("too many queries");
	if(!_valid(x1)||!_valid(x2)||!_valid(y1)||!_valid(y2))
		_wrong_answer("invalid query");
	if(!(x1<x2&&y1<y2))
		_wrong_answer("invalid query");
	int ml=_max(x1,_a),mr=_min(x2,_c);
	int md=_max(y1,_b),mu=_min(y2,_d);
	if(ml>=mr||md>=mu) return 0;
	return (long long)(mr-ml)*(long long)(mu-md);
}

int main() {
	int t,mx=0,subtask=0;
	rectangle tmp;
	_input(&t),_input(&subtask);
	while(t--){
		_count=0;
		_input(&_a),_input(&_b),_input(&_c),_input(&_d);
		tmp=find_rectangle(subtask);
		if(tmp.a!=_a||tmp.b!=_b||tmp.c!=_c||tmp.d!=_d)
			_wrong_answer("incorrect place");
		else
			mx=_max(mx,_count);
	}
	_Accepted(mx);
}
