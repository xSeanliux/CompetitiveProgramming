#pragma gcc optimize ("Ofast")
#include <iostream>                                                    
#include <bitset>
using namespace std;                                                            
const int maxN = 256;                                                           
                                                                        int N, M, K, u, v, imp[maxN]; 
struct Mat{                                                                    
    bitset<maxN> arr[maxN];                                                     
    inline void set(int a, int b){                                              
        arr[a][b] = 1;                                                          
    }                                                                           
    inline void T(){                                                            
        for(int i = 0; i < N; i++){                                             
            for(int j = i + 1; j < N; j++){                                     
                bool A = arr[i][j], B = arr[j][i];                              
                arr[i][j] = B;                                                  
                arr[j][i] = A;                                                  
            }                                                                   
        }                                                                       
    }                                                                           
    void disp(){                                                                
        for(int i = 0; i < N; i++){                                             
            for(int j = 0; j < N; j++) cout << arr[i][j] << " \n"[j == N - 1];  
        }                                                                       
    }                                                                           
} adj;                                                                   
                                                                                
Mat operator*(Mat a, Mat b){                                                    

    b.T();                                                                      
    Mat res;                                                                    
    bitset<maxN> tmp;                                                           
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){                      

	tmp = a.arr[i] & b.arr[j];                                              
	res.arr[i][j] = tmp.any();                                              
    }                                                                           

    return res;                                                                 
}                                                                               
	                                                                        
Mat operator^(Mat b, long long int e){                                                    
    Mat res;                                                                    
    for(int i = 0; i < N; i++) res.set(i, i);                                   
	while(e){
		if(e & 1) res = res * b;
		b = b * b;
		e /= 2;
	}
	return res;
}                                                                               
	                                                                        
inline bool can(long long int stp){                                                       
    Mat m = adj ^ stp;                                                          
    for(int c = 0; c < N; c++){                                                 
	bool f = true;                                                          
	for(int i = 0; i < K; i++) f &= m.arr[imp[i]][c];                       
	if(f) return true;                                                      
    }                                                                           
    return false;                                                               
}                                                                               
	                                                                        
int main(){                                                                     

    cin >> N >> M >> K;                                                         
    for(int i = 0; i < K; i++){                                                 
	cin >> imp[i];                                                          
	--imp[i];                                                               
    }                                                                           
    for(int i = 0; i < M; i++){                                                 
	cin >> u >> v;                                                          
	--u, --v;                                                               
	adj.set(u, v);                                                          
    }                                                                           
    if(!can(1LL << 60)){                                                          

	cout << "NIE" << endl;                                                  
	return 0;                                                               
    }                                                                           
    long long int ans = 0;                                                                

    for(int i = 60; i >= 0; i--){                                               
	if(!can(ans + (1LL << i))) ans += (1LL << i);                               

    }                                                                           
    cout << "TAK" << endl;                                                      
    cout << ans + 1 << endl;                                                    
}                                                                               

