#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
char dname[10];
char sdname[10][10];
char fname[10][10][10];
int ds,sds[10];
}dir[10];
void main()
{
int i,j,k,n;

int dflag[10] = {0} , sflag[10][10] ={0} , fflag[10][10][10]={0};

printf("enter number of directories:");
scanf("%d",&n);


for(i=0;i<n;i++)
{
printf("enter directory %d names:",i+1);
scanf("%s",&dir[i].dname);
printf("enter size of directories:");
scanf("%d",&dir[i].ds);
dflag[i]=1;
for(j=0;j<dir[i].ds;j++)
{
printf("enter subdirectory name and size:");
scanf("%s",&dir[i].sdname[j]);
scanf("%d",&dir[i].sds[j]);
sflag[i][j]=1;
for(k=0;k<dir[i].sds[j];k++)
{
printf("enter file name:");
scanf("%s",&dir[i].fname[j][k]);
fflag[i][j][k]=1;
}
}
}


display:
printf("\ndirname\t\tsize\tsubdirname\tsize\tfiles");
printf("\n******************************************************\n");
for(i=0;i<n;i++)
{
	if(dflag[i]==1)  {printf("%s\t\t%d",dir[i].dname,dir[i].ds);
		for(j=0;j<dir[i].ds;j++)
			{
				if(sflag[i][j]==1)  {printf("\t%s\t\t%d\t",dir[i].sdname[j],dir[i].sds[j]);
				for(k=0;k<dir[i].sds[j];k++)
					if(fflag[i][j][k]==1)  {printf("%s\t",dir[i].fname[j][k]);
						printf("\n\t\t");
					}
				}
			}
			printf("\n");    
	}
}


int ch;
char str[10];

{
	printf("1. Delete a directory \t 2. Delete a subdirectory \t 3. Delete a file  \t Any other key to Exit\n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1: {

			printf("Enter directory name:\n");
			scanf("%s",&str);

			for(i=0;i<n;i++)
				if(strcmp(str,dir[i].dname)==0)
					dflag[i]=0;

			printf("Directory Deleted\n\n");
			goto display;

				}
				break;

		case 2: {

			printf("Enter sub-directory name:\n");
			scanf("%s",&str);

			for(i=0;i<n;i++)
				for(j=0;j<dir[i].ds;j++)
					if(strcmp(str,dir[i].sdname[j])==0)
						sflag[i][j]=0;

			printf("Sub-Directory Deleted\n\n");
			goto display;

				}
				break;

		case 3: {

			printf("Enter file name:\n");
			scanf("%s",&str);

			for(i=0;i<n;i++)
				for(j=0;j<dir[i].ds;j++)
					for(k=0;k<dir[i].sds[j];k++)
						if(strcmp(str,dir[i].fname[j][k])==0)
							fflag[i][j][k]=0;

			printf("File Deleted\n\n");
			goto display;

				}
				break;

			default: exit(0);



	}

}


}

