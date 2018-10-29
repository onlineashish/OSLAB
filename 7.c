#include<stdio.h>
#include<stdlib.h>
int *p, temp, mem1[100], mem2[100], m, n, process[100], alloc[100], flag[100];
void bf()
{
int i, j;
for(i=0;i<m;i++)
for(j=i+1;j<m;j++)
if(mem1[i]>mem1[j])
{
temp = mem1[i];
mem1[i] = mem1[j];
mem1[j] = temp;
}
}
void wf()
{
int i, j;
for(i=0;i<m;i++)
for(j=i+1;j<m;j++)
if(mem2[i]<mem2[j])
{
temp = mem2[i];
mem2[i] = mem2[j];
mem2[j] = temp;
}
}
int main()
{
int i, j, ch;
printf("\n E
switch(ch)
{
case 1: printf("\n --- First Fit Allocation--- \n");
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
if(process[i] <= *(p+j))
{
alloc[i] = *(p+j);
*(p+j) = *(p+j) - process[i];
flag[i]=0;
break;
}
if(j==m)
printf("\n P%d of %d must wait\n", i+1, process[i]);
else
printf("\n P%d of %d is allocated to %d\n",i+1, process[i],
alloc[i]);
}
break;
case 2: printf("\n --- Best Fit Allocation --- \n");
for(i=0;i<n;i++)
{
bf();
for(j=0; j<m;j++)
if(process[i] <= mem1[j])
{
alloc[i] = mem1[j];
mem1[j] = mem1[j] - process[i];
flag[i]=0;
break;
}
if(j==m)
printf("\n P%d of %d must wait \n", i+1, process[i]);
else printf("\n P%d of %d is allocated to %d", i+1,process[i],
alloc[i]);
}
break;
case 3: printf("\n --- Worst Fit Allocation --- \n");
for(i=0;i<n;i++)
{
wf();
for(j=0; j<m;j++)
if(process[i] <= mem2[j])
{
alloc[i] = mem2[j];
mem2[j] = mem2[j] - process[i];
flag[i]=0;
break;
}
if(j==m)
printf("\n P%d of %d must wait \n", i+1, process[i]);
else printf("\n P%d of %d is allocated to %d", i+1,process[i],
alloc[i]);
}
break;
case 4: exit(0);
}
}
}