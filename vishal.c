#include<stdio.h>
#include<conio.h>
#define INFINITY 99
#define MAX 10

void dijikstra(int G[MAX][MAX], int n, int startnode);

void main(){
	int G[MAX][MAX], i, j, n, u,d;
	clrscr();
	printf("*************TRAFFIC MANAGEMENT*****************\n");
	printf("\n location code list \n 0=New Delhi \t 1=Noida Expressway \t 2=Noida Extension \t 3=Greater Noida \t 99= for no direct connection");
	printf("\n\nEnter the start location code:");
	scanf("%d", &u);
	printf("\nEnter the end location code:");
	scanf("%d", &d);
	printf("\nEnter the no. of possible via routes  directly connected:");//nodes
	scanf("%d", &n);
	printf("\nEnter the distance of the direct connected routes:\n");//matrix
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d", &G[i][j]);
	dijikstra(G,n,u);

	getch();
}

void dijikstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
}
