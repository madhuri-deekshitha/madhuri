#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bfs(int a[10][10], int n, int source)
{
    int s[10], q[10], f=0, r=-1, t, v;
    for(v=0;v<n;v++)
    {
        s[v]=0;
    }
    q[++r]=source;
    s[source]=1;
    while(f<=r)
    {
        t=q[f++];
        for(v=0;v<n;v++)
        if(a[t][v]==1 && s[v]==0)
        {
            q[++r]=v;
            printf("THE BSF TRAVERSAL IS  %d %d\n",t,v);
            s[v]=1;
        }
    }
}
int main()
{
    int a[10][10],i,n,j,s;
    double clk;
    clock_t starttime,endtime;
    printf("\nEnter the number of cities:");
    scanf("%d",&n);
    printf("\nEnter the matrix representation:");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("Enter the source city:");
    scanf("%d",&s);
    starttime=clock();
    bfs(a,n,s);
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("The run time is %f",clk);
}