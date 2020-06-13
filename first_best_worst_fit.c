#include<stdio.h>
# define max 25
void bestfit()
{
int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
	static int barray[20],parray[20];
	
	printf("\n\t\t\tMemory Management Scheme - Best Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("Enter the number of processes:");
	scanf("%d",&np);
	
	printf("\nEnter the size of the blocks:-\n");
	for(i=1;i<=nb;i++)
    {
		printf("Block no.%d:",i);
        scanf("%d",&b[i]);
    }
	
	printf("\nEnter the size of the processes :-\n");
	for(i=1;i<=np;i++)
    {
        printf("Process no.%d:",i);
        scanf("%d",&p[i]);
    }
	
	for(i=1;i<=np;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(barray[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
					if(lowest>temp)
					{
						parray[i]=j;
						lowest=temp;
					}
			}
		}
		
		fragment[i]=lowest;
		barray[parray[i]]=1;
		lowest=10000;
	}
	
	printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
	for(i=1;i<=np && parray[i]!=0;i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);

}



void firstfit()
{
	int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
 
	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}
	
	printf("Enter no. of blocks: ");
	scanf("%d", &bno);
	
	printf("\nEnter size of each block: ");
	for(i = 0; i < bno; i++)
		scanf("%d", &bsize[i]);
 
	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	
	printf("\nEnter size of each process: ");
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	for(i = 0; i < pno; i++)         //allocation as per first fit
		for(j = 0; j < bno; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{

				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	
	//display allocation details
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < bno; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
}
void worstfit()
{

int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
 static int bf[max],ff[max];

 printf("\n\tMemory Management Scheme - Worst Fit");
 printf("\nEnter the number of blocks:");
 scanf("%d",&nb);
 printf("Enter the number of files:");
 scanf("%d",&nf);
 printf("\nEnter the size of the blocks:-\n");
 for(i=1;i<=nb;i++) {printf("Block %d:",i);scanf("%d",&b[i]);}
 printf("Enter the size of the files :-\n");
 for(i=1;i<=nf;i++) {printf("File %d:",i);scanf("%d",&f[i]);}

 for(i=1;i<=nf;i++)
 {
  for(j=1;j<=nb;j++)
  {
   if(bf[j]!=1)    //if bf[j] is not allocated
   {
    temp=b[j]-f[i];
    if(temp>=0)
    if(highest<temp)
    {
     ff[i]=j;
     highest=temp;
    }
   }
  }
  frag[i]=highest;
  bf[ff[i]]=1;
  highest=0;
 }
 printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
 for(i=1;i<=nf;i++)
 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
int main()
{
printf("-----------------------------------------\n");
printf("best fit\n");
bestfit();
printf("-----------------------------------------\n");
printf("first fit\n");
firstfit();
printf("-----------------------------------------\n");
printf("worst fit\n");
worstfit();

return 0;
}


