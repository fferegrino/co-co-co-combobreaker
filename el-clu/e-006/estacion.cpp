#include <cstdio>
#include <algorithm>
using namespace std;
int est[] = {540, 580, 980, 1190, 1250, 1420, 1520 };
int main(){
	int N;
	scanf("%d", &N);
	bool found = false;
	for(int i = 0; i < 6 && !found; i++){
		if(est[i] <= N && N <= est[i + 1]){
			found = true;
			if(i == 0)
				N = est[i+1] - N;
			else if(i == 5)
				N = est[i] - N;
			else if( abs(est[i] - N) < abs(est[i +1] - N) )
					N = est[i] - N;
			else
					N = est[i + 1] - N;
		}
	}
	if(!found)
		printf("error\n");
	else{
		N < 0 ? printf("atras") : printf("adelante");
		printf(" %d\n", abs(N));
	}
}
