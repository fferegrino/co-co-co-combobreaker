#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define NN 500
using namespace std;
int a[11];
int d[11];
char in[11];
map<int, int> m;

int ai(char * s){
	int res = 0;
	int i = 0;
	while(s[i]){
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return res;
}

int ari(int * in, int len){	
	int res = 0;
	int i = 0;
	while(i < len){
		res = (res * 10) + (in[i] );
		i++;
	}
	return res;
}

int main(){
	while(1){
		m.clear();
		scanf("%s", in);
		if(in[0] == '0' && strlen(in) == 1)
			break;
		int n = ai(in);
		int cont = 0;
		while(!m[n]){
			int i = 0;
			int l = strlen(in);
			while(in[i]){
				d[i] = a[i] = in[i] - '0';
				i++;
			}
			sort(a,a+l);
			sort(d,d+l);
			reverse(d,d+l);
			m[n] = 1;
			n = ari(d,l) - ari(a,l);
			sprintf(in, "%d\0", n);
			cont++;
		}
		printf("Chain length %d\n", cont);
	}
	return 0;
}