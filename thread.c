#include<stdio.h>
struct Thread
{
	int st; //service time
	int ft; //finish time
	int status; //thread completed 1 not completed 0
};
struct process
{
	int at; //arrival time
	int nt; //number of threads
	int status; //process completed 1 not completed 0
	int ft; //finish time
	int ntc; //number of threads completed 
        
	struct Thread t[5];
}plist[10];
struct processor
{
	int cur_time; //current time of the processor
	int status; //status of the processor but useless
}proc[5];
int n,np; //n=number 0f processes; np=number of processors
int dispatch(int*,int*,int);int find_max(int a[],int z);
int mini()  //finds the processor with least current time
{
	int min=1,i;
	for(i=1;i<=np;i++)
	{
		if(proc[i].cur_time<proc[min].cur_time)
		{
			min=i;
		}
	}
	return min;
}
void main()
{
	int i,j,k,pid,tid;
	printf("\Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the number of processors: ");
	scanf("%d",&np);
	for(i=0;i<n;i++)
	{
		printf("Enter the arrival time of %d process: ",i+1);
		scanf("%d",&plist[i].at);
		printf("Enter the no. of threads: ");
		scanf("%d",&plist[i].nt);
		for(j=0;j<plist[i].nt;j++)
		{
			printf("Enter the service time of thread %d: ",j);
			scanf("%d",&plist[i].t[j].st);
			plist[i].t[j].status=0;
		}
		plist[i].status=0;
		plist[i].ntc=0;
	}
	for(j=1;j<=np;j++)
	{
		proc[j].status=0;
		proc[j].cur_time=0;
	}
	i=0;
	while(i<n) //until all processes are completed
	{
		k=mini();
		pid=dispatch(&pid,&tid,k); //chooses the next process and thread to be executed
			if(pid==-1) //if no process is available at this time
			{
				proc[k].cur_time++;
			}
			else 
			{
				int j;
				proc[k].cur_time+=plist[pid].t[tid].st; //update clock of the current processor
				plist[pid].t[tid].ft=proc[k].cur_time; //update the finish time of thread w.r.t cur_time of processor
				plist[pid].ntc++; //Incrementing the number of completed threads within the process
				plist[pid].t[tid].status=1;//this thread is done
				if(plist[pid].ntc==plist[pid].nt)//Verifying if the process is done
				{
                                   if(plist[pid].t[tid-1].ft>plist[pid].t[tid].ft)
                                         {
                                          plist[pid].ft=plist[pid].t[tid-1].ft;
                                         }
				    else
                                         {
                                          plist[pid].ft=proc[k].cur_time;
                                         }//Update finish time of process
					plist[pid].status=1;//Execution of this process completed
					i++; //moving to the next process
				}
			}
	}
for(i=0;i<n;i++)
{
int z=plist[i].nt;
int ftarr[z];
for(j=0;j<z;j++)
{
ftarr[j]=plist[i].t[j].ft;
}
int maxft=find_max(ftarr,z);
plist[i].ft=maxft;
}


	for(i=0;i<n;i++) //Displaying
	{
		printf("\nPID\tAT\tFT");
		printf("\n%d\t",i);
		printf("%d\t",plist[i].at);
		printf("%d\t",plist[i].ft);
		printf("\nThreads of process %d\n",i);
		printf("TID\tST\tFT");
		for(j=0;j<plist[i].nt;j++)
		{
			printf("\n%d \t",j+1);
			printf("%d \t",plist[i].t[j].st);
			printf("%d \t",plist[i].t[j].ft);
			printf("\n");
		}
	}
	
}
int find_max(int a[],int z)
{
int largest = a[0];
int i;
for(i=1;i<z;i++) 
{
if(largest<a[i])
{
largest=a[i];
}
}
return largest;
}



int dispatch(int *pid,int *tid,int i)
{

int j,k;
for(j=0;j<n;j++)
{
  if(plist[j].status!=1) 
    {
    if(plist[j].at<=proc[i].cur_time) 
     {
      for(k=0;k<plist[j].nt;k++) 
       {
        if(plist[j].t[k].status==0) 
           {
            *tid=k;
            return j;
           }
        }
      }
     else 
       {
	return -1;
       }
}
}
}


