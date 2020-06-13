#include<stdio.h>

struct process
{
int at;
int bt;
int ft;
int pri;
int tat;
int wt;
int status;
}p[10];
int n;
int dispatcher(int time)
{
int i,high_pr=99999,index=-1;
for(i=0;i<n;i++)
{
if(p[i].status!=1)
{
if(p[i].at<=time)
{
if(p[i].pri<high_pr)
{
high_pr=p[i].pri;
index=i;
}
}
}
}
return index;
}

int main()
{
printf("enter number of processes");
scanf("%d",&n);
int i;
for(i=0;i<n;i++)
{
printf("process : %d",i+1);

printf("enter arrival time");
scanf("%d",&p[i].at);

printf("enter burst time");
scanf("%d",&p[i].bt);

printf("enter priority");
scanf("%d",&p[i].pri);

p[i].status=0;
}
int pid,cur_time=0;
i=0;
while(i<n)
{
pid=dispatcher(cur_time);
p[pid].ft=cur_time+p[pid].bt;
cur_time=cur_time+p[pid].bt;
p[pid].status=1;
i++;
}
float avgtat,avgwt;
float tot_tat=0.0,tot_wt=0.0;
printf("process\tarrival time\tburst time\tfinish time\t turn around time\t waiting time\n");
for(i=0;i<n;i++)
{
p[i].tat=p[i].ft-p[i].at;
p[i].wt=p[i].tat-p[i].bt;

printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
}

for(i=0;i<n;i++)
{
tot_tat=tot_tat+p[i].tat;
tot_wt=tot_wt+p[i].wt;
}
avgtat=tot_tat/n;
avgwt=tot_wt/n;
printf("average turn around time: %f",avgtat);
printf("average waiting time :%f",avgwt);
}




