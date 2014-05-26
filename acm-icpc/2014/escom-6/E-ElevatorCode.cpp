#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define NN 500
using namespace std;
struct Seg{
	int o,  v,  d,  s;
	void c(){
		o = 0; v = 0; d = 0; s =0;
	}
	int val(){
		return s * v;
	}
};


bool cmp1(const Seg& a, const Seg& b)
{
	return (a.s == b.s) ? a.d > b.d : a.s > b.s;
}
bool cmp2(const Seg& a, const Seg& b)
{
	return a.o < b.o;
}

bool icmp(const int& a, const int& b)
{
	return a > b;
}

Seg sg[NN];
char expr[NN];
char num[NN];
int nums[NN];

int main(){
	int T;
	scanf("%d", &T);
	T++;
	while(--T){
		scanf("%s %s", expr, num);
		int exl = strlen(expr);
		int k = 0, i = 0, p = 0;
		for(i = 0; i < NN; i++) sg[i].c();
		while(num[k]){
			nums[k] = num[k] - '0';
			k++;
		}
		i = 0;
		sort(nums, nums+k,icmp);
		if(expr[i] == '#'){
			sg[p].s = 1;
			// YOLO
		}else{
			sg[p].s = (expr[i] == '-') ? -1 : 1;
			i++;
		}
		sg[p].o = p;
		for(; i < exl; i++){
			if(expr[i] == '#'){
				sg[p].d++;
			}else{
				p++;
				sg[p].o = p;
				sg[p].s = (expr[i] == '-') ? -1 : 1;
			}
		}
		sort(sg, sg+p+1, cmp1);
		int n = -1;
		int neg;
		int ii = 0;
		int ix = 0;
		n = sg[0].d;
		while(n && sg[0].s > 0){
			for(ix = 0; sg[ix].d == n && ix <= p; ix++){
				if(sg[ix].s < 0) { break; }
				sg[ix].d--;
				sg[ix].v = (nums[ii] * pow(10,n-1)) + sg[ix].v;
				ii++;
			}
			n = sg[0].d;
		}
		if(ix != p+1){
			reverse(nums+ii, nums+k);
			neg = ix;
			n = sg[neg].d;
			while(n){
				for(int ix = neg; sg[ix].d == n && ix <= p; ix++){
					sg[ix].d--;
					sg[ix].v = (nums[ii] * pow(10,n-1)) + sg[ix].v;
					ii++;
				}
				n = sg[neg].d;
			}
		}
		sort(sg, sg+p+1, cmp2);
		int res = 0;
		for(i = 0; i <= p; i++){
			res += sg[i].val();
		}
		printf("%d\n", res);
		fflush(stdin);
	}
	return 0;
}
