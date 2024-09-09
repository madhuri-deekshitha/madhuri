#include <stdio.h>
#include <time.h>
double clk;
clock_t starttime, endtime;

int min(int a, int b)
{
if(a<b)
return a;
else
return b;
}

void floyd(int n, int w[10][10], int d[10][10])
{
int i, j, k;
for(i=0; i<n; i++)
for(j=0; j<n;j++)
d[i][j]=w[i][j];

for(k=0; k<n; k++)
{
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}
}
}
}

void main()
{
int i,j,n,d[10][10],w[10][10];
printf("Enter no of vertices :\n");
scanf("%d",&n);
printf("Enter the cost matrix :\n");
for(i=0; i<n; i++)
for(j=0; j<n; j++)
scanf("%d",&w[i][j]);
starttime=clock();
floyd(n,w,d);
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
printf("all pair shortest path matrix is\n");

for(i=0; i<n; i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",d[i][j]);
}
printf("\nThe run time is %f\n",clk);
}
}