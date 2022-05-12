#include <iostream>
using namespace std;
int CoinChangeDynamic(int amount, int d[], int size, int C[]){
	C[0] =  0;
	for(int j = 1;j<= amount;j++){
		C[j] = INT_MAX;
		for(int i =0; i<size;i++){
			if(j >= d[i] && 1 + C[j - d[i]] < C[j]){
				C[j] = 1 + C[j - d[i]];
			}
		}
	}
	return C[amount];
}


int main(){
	int d[] = {1, 5, 10, 25};
	int amount = 67;
	int size = sizeof(d) / sizeof(d[0]);
	int *C = new int[amount + 1];
	int ans = CoinChangeDynamic(amount,d,size,C);
	
	delete[] C;
	
	return 0;
}
