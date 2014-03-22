#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	int k, T, s, m, t, i , j;
	char c;
	scanf("%d",&T);
	while(T--){
		s = 0;
		m = 0;
		t = 0;
		i = 0;
		j = 0;
		std::vector<char> a;
		scanf("%d",&k);
		scanf("%c",&c);
		scanf("%c",&c);
		while(c != '\n'){
			s++;
			a.insert(a.end(), c);
			scanf("%c",&c);
		}
		/*
		for(int x = 0; x < s; x++)
			printf("%c",a[x]);
		printf("\n");
		*/
		while(j < s - 1){
			while(k){
				//cout << a[j] << ":";
				printf("%c", a[j]);
				if(a[j++] == '<')
					k--;
				t++;
			}
			m = (m < t) ? t : m;
			j++;
		}
		
		printf("%d\n", m);
	}
	return 0;
}
	
	