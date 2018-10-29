#include<stdio.h>
#include<stdlib.h>
int max[100][100], need[100][100], alloc[100][100], avail[100], rsize, psize;
int safety()
{
int work[rsize], safe[psize], m=0, i, j, F[100], flag=0;
for(i=0;i<rsize;i++)
work[i] = avail[i];
for(i=0;i<psize;i++)
F[i]=0;
while(m<psize)
{
flag=0;
for(i=0;i<psize;i++)
{
if(F[i]==0)
{
for(j=0;j<rsize;j++)
if(need[i][j]>work[j])
break;
if(j==rsize)
{
safe[m++] = i;
for(j=0;j<rsize;j++)
work[j]+= need[i][j];
flag=1;
F[i]=1;
}
}
}
}
if(flag)
{
printf("\n The system is in safe state");
printf("\n Safe state sequence is:\n");
for(i=0;i<psize;i++)
printf("\t %d ",safe[i]);
return 1;
}
else{
 printf("\n System is not in safe state \n");
 return 0;
}
}
void resource()
{
int i, j, req[psize][rsize], k;
printf("\n Enter the process number\t");
scanf(" %d", &j);
printf("\n Enter the resource request\t");
for(i=0;i<rsize;i++)
scanf(" %d", &req[j][i]);
for(i=0;i<rsize;i++)
{
if(req[j][i]>need[j][i])
{
printf("\n Request can't be granted \t");
return;
}
}
for(i=0;i<rsize;i++)
{
if(req[j][i]>avail[i])
{
printf("\n Request can't be granted \t");
return;
}
}
k = safety();
if(k==0)
{
printf("\n Request can't be granted immediately\t");
}
else{
printf("\n Request can be granted immediately\n");
for(i=0;i<rsize;i++)
{
alloc[j][i] += req[j][i];
avail[i]-= req[j][i];
need[j][i] = max[j][i] - alloc[j][i];
}
}
}
void main()
{
int i,j;
char ch='y';
printf("\n Enter the number of processes\t");
scanf(" %d", &psize);
printf("\n Enter the number of resources\t");
scanf(" %d", &rsize);
printf("\n Enter the max matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &max[i][j]);
printf("\n Enter the allocation matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &alloc[i][j]);
printf("\n Enter the available resources\n");
for(i=0;i<rsize;i++)
scanf(" %d", &avail[i]);
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
need[i][j] = max[i][j]-alloc[i][j];
printf("\n The need matrix is: \n");
for(i=0;i<psize;i++)
{ printf("\n");
for(j=0; j<rsize;j++)
printf("\t%d",need[i][j]);
}
safety();
while(1)
{
printf("\n Want to request resource?? ");
scanf(" %c",&ch);
if(ch=='y' || ch=='Y')
resource();
else break;
}
}#include<stdio.h>
#include<stdlib.h>
int max[100][100], need[100][100], alloc[100][100], avail[100], rsize, psize;
int safety()
{
int work[rsize], safe[psize], m=0, i, j, F[100], flag=0;
for(i=0;i<rsize;i++)
work[i] = avail[i];
for(i=0;i<psize;i++)
F[i]=0;
while(m<psize)
{
flag=0;
for(i=0;i<psize;i++)
{
if(F[i]==0)
{
for(j=0;j<rsize;j++)
if(need[i][j]>work[j])
break;
if(j==rsize)
{
safe[m++] = i;
for(j=0;j<rsize;j++)
work[j]+= need[i][j];
flag=1;
F[i]=1;
}
}
}
}
if(flag)
{
printf("\n The system is in safe state");
printf("\n Safe state sequence is:\n");
for(i=0;i<psize;i++)
printf("\t %d ",safe[i]);
return 1;
}
else{
 printf("\n System is not in safe state \n");
 return 0;
}
}
void resource()
{
int i, j, req[psize][rsize], k;
printf("\n Enter the process number\t");
scanf(" %d", &j);
printf("\n Enter the resource request\t");
for(i=0;i<rsize;i++)
scanf(" %d", &req[j][i]);
for(i=0;i<rsize;i++)
{
if(req[j][i]>need[j][i])
{
printf("\n Request can't be granted \t");
return;
}
}
for(i=0;i<rsize;i++)
{
if(req[j][i]>avail[i])
{
printf("\n Request can't be granted \t");
return;
}
}
k = safety();
if(k==0)
{
printf("\n Request can't be granted immediately\t");
}
else{
printf("\n Request can be granted immediately\n");
for(i=0;i<rsize;i++)
{
alloc[j][i] += req[j][i];
avail[i]-= req[j][i];
need[j][i] = max[j][i] - alloc[j][i];
}
}
}
void main()
{
int i,j;
char ch='y';
printf("\n Enter the number of processes\t");
scanf(" %d", &psize);
printf("\n Enter the number of resources\t");
scanf(" %d", &rsize);
printf("\n Enter the max matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &max[i][j]);
printf("\n Enter the allocation matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &alloc[i][j]);
printf("\n Enter the available resources\n");
for(i=0;i<rsize;i++)
scanf(" %d", &avail[i]);
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
need[i][j] = max[i][j]-alloc[i][j];
printf("\n The need matrix is: \n");
for(i=0;i<psize;i++)
{ printf("\n");
for(j=0; j<rsize;j++)
printf("\t%d",need[i][j]);
}
safety();
while(1)
{
printf("\n Want to request resource?? ");
scanf(" %c",&ch);
if(ch=='y' || ch=='Y')
resource();
else break;
}
}#include<stdio.h>
#include<stdlib.h>
int max[100][100], need[100][100], alloc[100][100], avail[100], rsize, psize;
int safety()
{
int work[rsize], safe[psize], m=0, i, j, F[100], flag=0;
for(i=0;i<rsize;i++)
work[i] = avail[i];
for(i=0;i<psize;i++)
F[i]=0;
while(m<psize)
{
flag=0;
for(i=0;i<psize;i++)
{
if(F[i]==0)
{
for(j=0;j<rsize;j++)
if(need[i][j]>work[j])
break;
if(j==rsize)
{
safe[m++] = i;
for(j=0;j<rsize;j++)
work[j]+= need[i][j];
flag=1;
F[i]=1;
}
}
}
}
if(flag)
{
printf("\n The system is in safe state");
printf("\n Safe state sequence is:\n");
for(i=0;i<psize;i++)
printf("\t %d ",safe[i]);
return 1;
}
else{
 printf("\n System is not in safe state \n");
 return 0;
}
}
void resource()
{
int i, j, req[psize][rsize], k;
printf("\n Enter the process number\t");
scanf(" %d", &j);
printf("\n Enter the resource request\t");
for(i=0;i<rsize;i++)
scanf(" %d", &req[j][i]);
for(i=0;i<rsize;i++)
{
if(req[j][i]>need[j][i])
{
printf("\n Request can't be granted \t");
return;
}
}
for(i=0;i<rsize;i++)
{
if(req[j][i]>avail[i])
{
printf("\n Request can't be granted \t");
return;
}
}
k = safety();
if(k==0)
{
printf("\n Request can't be granted immediately\t");
}
else{
printf("\n Request can be granted immediately\n");
for(i=0;i<rsize;i++)
{
alloc[j][i] += req[j][i];
avail[i]-= req[j][i];
need[j][i] = max[j][i] - alloc[j][i];
}
}
}
void main()
{
int i,j;
char ch='y';
printf("\n Enter the number of processes\t");
scanf(" %d", &psize);
printf("\n Enter the number of resources\t");
scanf(" %d", &rsize);
printf("\n Enter the max matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &max[i][j]);
printf("\n Enter the allocation matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &alloc[i][j]);
printf("\n Enter the available resources\n");
for(i=0;i<rsize;i++)
scanf(" %d", &avail[i]);
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
need[i][j] = max[i][j]-alloc[i][j];
printf("\n The need matrix is: \n");
for(i=0;i<psize;i++)
{ printf("\n");
for(j=0; j<rsize;j++)
printf("\t%d",need[i][j]);
}
safety();
while(1)
{
printf("\n Want to request resource?? ");
scanf(" %c",&ch);
if(ch=='y' || ch=='Y')
resource();
else break;
}
}#include<stdio.h>
#include<stdlib.h>
int max[100][100], need[100][100], alloc[100][100], avail[100], rsize, psize;
int safety()
{
int work[rsize], safe[psize], m=0, i, j, F[100], flag=0;
for(i=0;i<rsize;i++)
work[i] = avail[i];
for(i=0;i<psize;i++)
F[i]=0;
while(m<psize)
{
flag=0;
for(i=0;i<psize;i++)
{
if(F[i]==0)
{
for(j=0;j<rsize;j++)
if(need[i][j]>work[j])
break;
if(j==rsize)
{
safe[m++] = i;
for(j=0;j<rsize;j++)
work[j]+= need[i][j];
flag=1;
F[i]=1;
}
}
}
}
if(flag)
{
printf("\n The system is in safe state");
printf("\n Safe state sequence is:\n");
for(i=0;i<psize;i++)
printf("\t %d ",safe[i]);
return 1;
}
else{
 printf("\n System is not in safe state \n");
 return 0;
}
}
void resource()
{
int i, j, req[psize][rsize], k;
printf("\n Enter the process number\t");
scanf(" %d", &j);
printf("\n Enter the resource request\t");
for(i=0;i<rsize;i++)
scanf(" %d", &req[j][i]);
for(i=0;i<rsize;i++)
{
if(req[j][i]>need[j][i])
{
printf("\n Request can't be granted \t");
return;
}
}
for(i=0;i<rsize;i++)
{
if(req[j][i]>avail[i])
{
printf("\n Request can't be granted \t");
return;
}
}
k = safety();
if(k==0)
{
printf("\n Request can't be granted immediately\t");
}
else{
printf("\n Request can be granted immediately\n");
for(i=0;i<rsize;i++)
{
alloc[j][i] += req[j][i];
avail[i]-= req[j][i];
need[j][i] = max[j][i] - alloc[j][i];
}
}
}
void main()
{
int i,j;
char ch='y';
printf("\n Enter the number of processes\t");
scanf(" %d", &psize);
printf("\n Enter the number of resources\t");
scanf(" %d", &rsize);
printf("\n Enter the max matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &max[i][j]);
printf("\n Enter the allocation matrix\n");
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
scanf(" %d", &alloc[i][j]);
printf("\n Enter the available resources\n");
for(i=0;i<rsize;i++)
scanf(" %d", &avail[i]);
for(i=0;i<psize;i++)
for(j=0; j<rsize;j++)
need[i][j] = max[i][j]-alloc[i][j];
printf("\n The need matrix is: \n");
for(i=0;i<psize;i++)
{ printf("\n");
for(j=0; j<rsize;j++)
printf("\t%d",need[i][j]);
}
safety();
while(1)
{
printf("\n Want to request resource?? ");
scanf(" %c",&ch);
if(ch=='y' || ch=='Y')
resource();
else break;
}
}