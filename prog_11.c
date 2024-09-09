#include<stdio.h>
#include<time.h>

struct edge
{
int u,v,cost;
};
typedef struct edge edge;

int find(int v, int parent[]){
while(parent[v]!=v)
{
v=parent[v];
}
return v;
}

void union_ij(int i, int j, int parent[]){
if(i<j)
parent[j]=i;
else
parent[i]=j;
}

void kruskal(int n, edge e[], int m){
int count,k,i,sum,u,v,j,t[10][10],p,parent[10];
edge temp;
count=0;
k=0;
sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<m-1;j++){
if(e[j].cost>e[j+1].cost){
temp.u=e[j].u;
temp.v=e[j].v;
temp.cost=e[j].cost;
e[j].u=e[j+1].u;
e[j].v=e[j+1].v;
e[j].cost=e[j+1].cost;
e[j+1].u=temp.u;
e[j+1].cost=temp.cost;
}
}
}
for(i=0;i<n;i++)
parent[i]=i;
p=0;
while(count!=n-1)
{
u=e[p].u;
v=e[p].v;
i=find(u,parent);
j=find(v,parent);
if(i!=j)
{
t[k][0]=u;
t[k][1]=v;
k++;
count++;
sum+=e[p].cost;
union_ij(i,j,parent);
}
p++;
}
if(count==n-1){
printf("Spanning tree exist\n");
printf("\nThe spanning tree is as follows :\n");
for(i=0;i<n-1;i++){
printf("%d %d\t",t[i][0],t[i][1]);
}
printf("\nThe cost of the spanning tree is %d \n",sum);
}
else
printf("\nSpanning tree does not exist");
}

void main()
{
int n,m,a,b,i,cost;
double clk;
clock_t starttime, endtime;
edge e[20];
printf("Enter the number of vertices :\n");
scanf("%d",&n);
printf("Enter the number of edges :\n");
scanf("%d",&m);
printf("Enter the edge list(u v cost)\n");
for(i=0;i<m;i++){
scanf("%d %d %d",&a,&b,&cost);
e[i].u=a;
e[i].v=b;
e[i].cost=cost;
}
starttime=clock();
kruskal(n,e,m);
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
printf("The time taken is %f\n",clk);
}