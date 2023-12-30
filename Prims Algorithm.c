#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#define V 5
#define INF 9999999
int G[V][V] = {
				{0, 4, 6, 0},
				{4, 0, 1, 2},
				{6, 1, 0, 4},
				{0, 2, 4, 0}
			  };
void main()
{
	int i,j,edges;
	int selected[V];
	memset(selected, false, sizeof(selected));
	
	selected[0] = false;
	int x,y;
	while(edges<V-1)
	{
		int min = INF;
	    x = 0;
	    y = 0;
	    for(i=0;i<V;i++)
	    {
	    	if(selected[i])
	    	{
	    		for(j=0;j<V;j++)
	    		{
	    			if(!selected[j] && G[i][j])
	    			{
	    				if(min>G[i][j]){
	    					min = G[i][j];
	    					x = i;
	    					y = j;
						}
					}
				}
			}
		}
		printf("%d --- %d : %d\n", x, y, G[x][y]);
    	selected[y] = true;
    	edges++;
	}
	return;
}
