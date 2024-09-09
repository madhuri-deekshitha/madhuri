#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int i,a[1000],j,bottom,top,temp,mid,n,key;
double clk;
clock_t starttime,endtime;
printf("Enter the number of production:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    a[i]=rand()%100;
    printf("the product id list are :%d\n",a[i]);
}
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(a[j]>a[j+1]){
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("\nSorted product list:");
for(i=0;i<n;i++)
printf("\t %d",a[i]);

printf("\nEnter the product id to be searched:");
scanf("%d",&key);
starttime=clock();
top=n;
bottom=0;
do
{
    mid=(bottom+top)/2;
    if(key<a[mid])
    top=mid-1;
    else if(key>a[mid])
    bottom=mid+1;
}
while(key!=a[mid] && bottom<=top);
if(key==a[mid]){
    printf("Found!\n");
    printf("Found the key %d at postion %d",mid+1,key);
}
else{
    printf("Not found");
}
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
printf("\nThe run time is %f",clk);
}