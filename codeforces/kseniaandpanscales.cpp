#include <stdio.h>
#include <deque>

using namespace std;

int main(){
	deque<char> pan;
	char c;
	int izq = 0, der = 0;
	char flag = 0;
	scanf("%c",&c);
	
	while(c != '\n'){
		
		if(c == '|'){
			flag = 1;
		}else{
			if(flag){
				der++;
			}else{
				izq++;
			}
		}
		pan.push_back(c);
		scanf("%c",&c);
	}
	
	scanf("%c",&c);
	while(c != '\n'){
		if(izq  < der){
			izq++;
			pan.push_front(c);
		}else{
			der++;
			pan.push_back(c);
		}
		scanf("%c", &c);
	}
	
	if(der != izq)
		printf("Impossible\n");
	else{
		for(int i = 0; i < pan.size(); i++){
			printf("%c", pan.at(i));
		}
		printf("\n");
	}
	
	return 0;
}