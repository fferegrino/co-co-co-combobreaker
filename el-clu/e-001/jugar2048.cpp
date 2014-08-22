#include <cstdio>
#include <stack>
using namespace std;
stack<int> torre;

void join(){
	if(torre.size() > 1){
		int top = torre.top();
		torre.pop();
		int top1 = torre.top();
		if(top == top1){
			torre.pop();
			torre.push(top+top1);
			join();
		}else{
			torre.push(top);
		}
	}
}

int main(){
	int N, n;
	scanf("%d", &N); N++;
	while(--N){
		scanf("%d", &n);
		torre.push(n);
		join();
	}
	printf("%d\n", torre.size());
	while(!torre.empty())	{
		printf("%d\n", torre.top());
		torre.pop();
	}
}