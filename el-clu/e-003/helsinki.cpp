#include <cstdio>
#include <vector>
using namespace std;
vector<int> con;
vector<int> rep;

int f(int x){
	for(int i = 0; i < con.size(); i++){
		if(con[i] == x){
			return i;
		}
	}
	return -1;
}
int main(){
	int n, c;
	scanf("%d", &n); n++;
	while(--n){
		scanf("%d", &c);
		int find = f(c);
		if(find != -1){
			rep[find]++;
		}
		else{
			con.push_back(c);
			rep.push_back(1);
		}
	}
	int cc = 0;
	for(int i = 0; i < con.size(); i++){
		if(rep[i] == 1){
			cc += (con[i] + 1);
		}else{
			int nn = con[i] +1;
			int res = rep[i] / nn;
			cc += res * nn;
			if(rep[i] % nn != 0){
				cc += nn;
			}
		}
		//printf("%d %d\n", con[i], rep[i]);
	}
	printf("%d\n", cc);
	return 0;
}
