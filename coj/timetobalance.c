#include <stdio.h>
int main(){
	int m, a, t, tm, y;
	scanf("%d%d", &m, &a);
	while(m != 0 && a != 0){
		t = a;
		y = 0;
		while(m < a){
			t = a / 2;
			//printf("\t%d %d\n", t, m);
			if((t * 2) == a && !(t < m)){
				a = t;
			} else {
				a = a -1;
			}
			y++;
		}
		printf("%d\n", y);
		scanf("%d%d", &m, &a);
	}
}