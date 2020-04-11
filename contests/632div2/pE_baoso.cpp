#include <iostream>
#include <algorithm>
using namespace std;

int board[3][3], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, perm[9];
bool visited[3][3];

bool isValid(int y, int x){
	if(y >= 0 && x >= 0 && x < 3 && y < 3 && !visited[y][x]) return true;
	return false;
}
int rook(){
	int x = 0, y = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			visited[i][j] = false;
		}
	}
	int res = 0;
	for(int s = 0; s < 9; s++){
		int yy = -1, xx = -1, minVal = 100000;
		visited[y][x] = true;
		for(int i = 0; i < 3; i++){
			if(isValid(i, x) && board[i][x] < minVal){
				minVal = board[i][x];
				yy = i;
				xx = x;
			} 
			if(isValid(y, i) && board[y][i] < minVal){
				minVal = board[y][i];
				yy = y;
				xx = i;
			} 

		}
		if(yy != -1){
			x = xx;
			y = yy;
		} else {
			minVal = 10000;
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if(isValid(i, j) && board[i][j] < minVal){
						y = i;
						x = j;
						minVal = board[i][j];
					}
				}
			}
			res++;
		}
	}
	return res;
}

int queen(){
	int x = 0, y = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			visited[i][j] = false;
		}
	}
	int res = 0;
	for(int s = 0; s < 9; s++){
		int yy = -1, xx = -1, minVal = 100000;
		visited[y][x] = true;
		for(int i = 0; i < 3; i++){
			if(isValid(i, x) && board[i][x] < minVal){
				minVal = board[i][x];
				yy = i;
				xx = x;
			} 
			if(isValid(y, i) && board[y][i] < minVal){
				minVal = board[y][i];
				yy = y;
				xx = i;
			} 
			if(isValid(y + i, x + i) && board[y + i][x + i] < minVal){
				minVal = board[y + i][x + i];
				yy = y + i;
				xx = x + i;
			} 
			if(isValid(y + i, x - i) && board[y + i][x - i] < minVal){
				minVal = board[y + i][x - i];
				yy = y + i;
				xx = x - i;
			} 
			if(isValid(y - i, x + i) && board[y - i][x + i] < minVal){
				minVal = board[y - i][x + i];
				yy = y - i;
				xx = x + i;
			} 
			if(isValid(y - i, x - i) && board[y - i][x - i] < minVal){
				minVal = board[y - i][x - i];
				yy = y - i;
				xx = x - i;
			} 
		}
		if(yy != -1){
			x = xx;
			y = yy;
		} else {
			minVal = 10000;
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if(isValid(i, j) && board[i][j] < minVal){
						y = i;
						x = j;
						minVal = board[i][j];
					}
				}
			}
			res++;
		}
	}
	return res;
}

int main(){
	for(int i = 0; i < 9; i++){
		perm[i] = i + 1;
	}
	do{
		for(int i = 0; i < 9; i++){
			board[i / 3][i % 3] = perm[i];
		}
		if(rook() < queen()){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
			return 0;
		} 
	}while(next_permutation(perm, perm + 9));

}
