#include <cstring>
#include <cstdio>
using namespace std;
int T;
long long int ip[3][4];
char ips[3][20];
void clear(){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			ip[i][j] = 0;
}
void parse(){
	int len, n;
	for(int i = 0; i < 3; i++){
		len = strlen(ips[i]);
		n = 0;
		for(int j = 0; j < len; j++){
			if(ips[i][j] == '.'){ n++; }
			else{
				ip[i][n] = ((ip[i][n] * 10) + (ips[i][j] - '0'));
			}
		}
	}
}

int main(){
	scanf("%d",&T);
	long long int val[3];
	while(T--){
		for(int i = 0; i < 3; i++)
			scanf("%s",ips[i]);
		clear();
		parse();
		val[0] = val[1] = val[2] = 0;
		for(int i = 0; i < 3; i++){
			val[i] = (ip[i][0] << 24) + (ip[i][1] << 16 )+ (ip[i][2]  << 8) + ip[i][3];
		}
		val[2] <= val[1] && val[2] >= val[0] || val[2] >= val[1] && val[2] <= val[0] ? printf("YES\n") : printf("NO\n");
	}
}