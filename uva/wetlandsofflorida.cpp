#include <algorithm> 
#include <stdio.h> 
#include <cstring> 
#define MAX 109
using namespace std; 
char mapa[MAX][MAX]; 
int visita[MAX][MAX]; 
int n, m, T, i, j, c; 
void cuenta(int x, int y, int v){ 
	if(x < 0 || y < 0 || x >= n || y >= m) 
		return; 
	if(visita[x][y] == v || mapa[x][y] == 'L') 
		return;
	visita[x][y] = v;
	c++;
	cuenta(x-1,y-1,v);
	cuenta(x,y-1,v);
	cuenta(x+1,y-1,v);
	cuenta(x-1,y,v);
	cuenta(x+1,y,v);
	cuenta(x-1,y+1,v);
	cuenta(x,y+1,v);
	cuenta(x+1,y+1,v);
} 
  
int main(){ 
    scanf("%d",&T); 
    getchar(); 
    getchar();
    int lin = 0;
    int gpo = 1; 
    bool primero = true;
    while(T--){
        for(int ix =0; ix < MAX; ix++)
			for(int jx =0; jx < MAX; jx++)
				visita[ix][jx] = 0;
		primero ? 0 : printf("\n");
		primero = false;
        while(fgets(mapa[lin],MAX,stdin) != NULL){ 
			int len = strlen(mapa[lin]);
			if(len == 1) break;
			mapa[lin][len-1] = '\0';
            if(mapa[lin][0] == 'L' || mapa[lin][0] == 'W'){ 
                m = strlen(mapa[lin]); 
                n++; 
                lin++; 
            }else{ 
                sscanf(mapa[lin],"%d %d",&i,&j);
                c = 0;
                cuenta(i-1,j-1,gpo++);
                printf("%d\n",c);
            } 
        }
        m = 0; 
        n = 0;
        lin = 0;
    } 
    return 0; 
}