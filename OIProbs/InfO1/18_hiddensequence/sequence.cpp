#include <vector>
#include <deque>
#include <iostream>
#include "grader.h"
using namespace std;

int sma, big, cnt;

vector <int> findSequence (int N){
	int LIM = (3 * N) / 4 + 1, cnt;
   	vector<int> que;
	sma = -1;
	for(int i = 1; i <= N / 2 + 1; i++){
		que.push_back(0);
		if(!isSubsequence(que)){
			sma = 0
			big = 1;
			cnt = i - 1;
			break;
		}
	}
	vector<int>().swap(que);
	if(sma == -1){
		for(int i = 1; i <= N / 2 + 1; i++){
			que.push_back(1);
			if(!isSubsequence(que)){
				sma = 1;
				big = 0;
				cnt = i - 1;
				break;
			}
		}
	}
	//cout << "Found smal = " << sma << ", cnt = " << cnt << endl;
	vector<int>().swap(que);
	if(!cnt){
		for(int i = 0; i < N; i++) que.push_back(big);
		return que;
	}
	for(int i = 0; i < cnt; i++) que.push_back(sma);
	vector<int> lens, bigs;
	lens.push_back(0);
	for(int i = 1; i < cnt; i++){
		que.insert(que.begin() + i, big);	
		if(isSubsequence(que)){
			lens.push_back(i);	
		}
		que.erase(que.begin() + i);
	}
	//cout << "Finished finding? " << endl;
	lens.push_back(cnt);
	bigs.resize(lens.size());
	int backInd = -1, used = 0;
	vector<int>().swap(que);
	for(int i = 0; i < cnt; i++) que.push_back(sma);
	for(int i = 0; i < lens.size(); i++){
		//cout<< "lens[" << i << "] = " << lens[i] << endl;
		int cnt = 0;
		while(que.size() < LIM && isSubsequence(que)){
			cnt++;	
			que.insert(que.begin() + lens[i], big);
		}
		if(isSubsequence(que)){
			backInd = i;
			//cout << "backind = " << backInd << endl;
		} else {
			bigs[i] = cnt - 1;
			used += bigs[i];
		}
		while(que.size() > lens[i] && que[lens[i]] == big){
			que.erase(que.begin() + lens[i]);
		}
	}
	//cout << "Finished finding big" << endl;
	if(backInd != -1){
		//cout << "bigs = " << N - cnt - used << endl;
		bigs[backInd] = N - cnt - used;
	}
	vector<int> ans;
	for(int i = 0; i < bigs.size(); i++){
		for(int j = 0; j < (!i ? lens[i] : lens[i] - lens[i - 1]); j++) ans.push_back(sma); 
		for(int j = 0; j < bigs[i]; j++) ans.push_back(big);	
	}
	return ans;
}

