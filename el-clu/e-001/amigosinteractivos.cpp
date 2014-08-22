#include<stdio.h>
#include<algorithm>
#define MAXI 100005
using namespace std;

int padre[MAXI];

int root(int a){
 if(padre[a]==a)
    return a;
 return padre[a] = root(padre[a]);

}

void init(int N){

 for(int i=1;i<=N;i++)
    padre[i] = i; 
}

void unir(int a,int b){
 int raizA = root(a);
 int raizB = root(b);
 padre[raizA] = raizB;
}

bool mismo(int a, int b){
 if(root(a) == root(b))
    return true;
 return false;
}

int N,M,x,y;
char l;

int main(){
 scanf("%d %d",&N,&M);
 init(N);
 while(M--){
    scanf(" %c %d %d",&l,&x,&y);
    if(l=='S')
       unir(x,y);
    else if(l=='P'){
    			(mismo(x,y)) ? printf("1\n"):printf("0\n");
    }
 
  }
 return 0;
}