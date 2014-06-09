#include <cstdio>
#include <cstring>
#define MAXF 1002

int main(){
	long long int R = 0, res;
	int	L = 0, V = 0, l = 0, v = 0, ll = 0, vv = 0;
	char LT[MAXF], VT[MAXF];
	scanf("%d", &R); 
	scanf("%s %s", LT, VT);
	l = strlen(LT); v = strlen(VT);
	int max =  v * l;
	for(int i  = 0; i < R && i < max;  i++){
		//printf("%d: %c %c\n", i, LT[i % l], VT[i % v]);
		switch(LT[i % l]){
			case 'R':
				if(VT[i % v] == 'P')
					V++;
				else if(VT[i % v] != 'R')	
					L++;
			break;
			case 'P':
				if(VT[i % v] == 'S')
					V++;
				else if(VT[i % v] != 'P')	
					L++;
			break;
			case 'S':
				if(VT[i % v] == 'R')
					V++;
				else if(VT[i % v] != 'S')	
					L++;
			break;
		}
	}
	res = R / max;
	if(res){
		V *= res;
		L *= res;
		for(long long int i = res*max; i < R; i++){
			switch(LT[i % l]){
				case 'R':
					if(VT[i % v] == 'P')
						V++;
					else if(VT[i % v] != 'R')	
						L++;
				break;
				case 'P':
					if(VT[i % v] == 'S')
						V++;
					else if(VT[i % v] != 'P')	
						L++;
				break;
				case 'S':
					if(VT[i % v] == 'R')
						V++;
					else if(VT[i % v] != 'S')	
						L++;
				break;
			}
		}
	}
	printf("%d %d\n", V, L);
	return 0;
}	