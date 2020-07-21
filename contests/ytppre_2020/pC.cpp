#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

/*
1. a2+b2=c2
2. (a-b)*2=c
3. a*b=c
*/



string s;
int arr[3], mode, mis, cnt;

int main(){
	cin >> s;
	mode = s[0] - '0';
	string cur = "";
	for(int i = 2; i < s.length(); i++){
		if(s[i] == ','){
			if(cur == ""){
				arr[cnt++] = -1;
			} else {
				arr[cnt++] = stoi(cur);
			}
			cur = "";
			continue;
		} else {
			cur += s[i];
		}
	}
	if(cur == ""){
		arr[cnt++] = -1;	
	} else {
		arr[cnt++] = stoi(cur);
	}
	//for(int i = 0; i < 3; i++) cout << arr[i] << " ";
	if(mode == 1){
		if(arr[0] == -1){
			cout << (int)(round(sqrt(arr[2] * arr[2] - arr[1] * arr[1]))) << endl;	
		} else if(arr[1] == -1){
			cout << (int)(round(sqrt(arr[2] * arr[2] - arr[0] * arr[0]))) << endl;	
		} else if(arr[2] == -1){
			cout << (int)(round(sqrt(arr[0] * arr[0] + arr[1] * arr[1]))) << endl;	
		}
	} 
	if(mode == 2){
		if(arr[0] == -1){
			cout << arr[2] / 2 + arr[1] << endl;	
		} else if(arr[1] == -1){
			cout << arr[0] - arr[2] / 2 << endl;
		} else if(arr[2] == -1){
			cout << (arr[0] - arr[1]) / 2 << endl;	
		}
	} 
	if(mode == 3){
		if(arr[0] == -1){
			cout << arr[2] / arr[1] << endl;	
		} else if(arr[1] == -1){
			cout << arr[2] / arr[0] << endl;	
		} else if(arr[2] == -1){
			cout << arr[0] * arr[1] << endl;
		}
	} 


}
