#include <cstdio>

int main(){
	int q, x1, y1, x, y, xd, yd;
	scanf("%d", &q);
	while(q){
		q++;
		scanf("%d %d", &x1, &y1);
		while(--q){
			scanf("%d %d", &x, &y);
			xd = x - x1;
			yd = y - y1;
			if(yd && xd){
				yd < 0 ? printf("S") : printf("N");
				xd < 0 ? printf("O") : printf("E");
			}else{
				printf("divisa");
			}
			printf("\n");
		}
		scanf("%d", &q); 
	}
	return 0;
}
