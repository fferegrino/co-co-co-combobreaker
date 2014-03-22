#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int n, i;
    int first, second, winner;
    int * bids;
    scanf("%d",&n);
    bids = (int *) malloc(sizeof(int) * n);
    for(i = 0; i < n; ++i){
        scanf("%d",&bids[i]);
    }
    if(bids[0] < bids[1]){
        winner = 1;
        first = bids[1];
        second = bids[0];
    }else
    {
        winner = 0;
        first = bids[0];
        second = bids[1];
    }
    for(i = 2; i < n; ++i){
        if(bids[i] > first){
            winner = i;
            second = first;
            first =  bids[i];
        }else if(bids[i] > second){
            second = bids[i];
        }
    }
    printf("%d %d\n",winner +1, second);
    return 0;
}