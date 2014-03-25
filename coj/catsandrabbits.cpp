#include <stdio.h>
#include <cstring>
using namespace std;
char game[55];
int n;
int main() {
	while(scanf("%s",game) != EOF){
		n = strlen(game);
		int t = 0, j = 0;
		char ex = 1;
		char z = 0;
		for(int i = 0; i < n;){
			while(game[i] == '#' && i < n)
			{
				z = 1;
				i++;		
			}
			while(game[i] == '.' && i < n)
			{
				t++;
				i++;		
			}
			if(ex){
				j = t;
				t = 0;
				ex = 0;
			}
			else{
				j = j ^ t;
				t = 0;
			}
 
		}
		if(j && z)
			printf("Cat\n");
		else
			printf("Rabbit\n");
	}
	return 0;
}