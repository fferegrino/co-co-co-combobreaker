#include <cstdio>
#define L 50

int main(){	
	char cst[L];
	int oc[L];
	int beds, left, i;
	scanf("%d", &beds);
	while(beds > 0){
		scanf("%s", cst);
		left = 0;
		for(i = 0; i < L; i++){
			oc[i] = 0;
		}
		i = 0;
		while(cst[i]){
			if(oc[cst[i] - 'A'] == 1){
				oc[cst[i] - 'A'] = 0;
				beds++;
			}
			else{ // New customer
				if(beds){
					oc[cst[i] - 'A'] = 1;
					beds--;
				}
				else if(oc[cst[i] - 'A'] != -1){
					oc[cst[i] - 'A'] = -1;
					left++;
				}
			}
			i++;
		}
		left ? printf("%d customer(s) walked away.\n", left) : printf("All customers tanned successfully.\n");
		scanf("%d", &beds);
	}
}
