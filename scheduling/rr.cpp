#include<iostream>
using namespace std;
struct process
{
	int at;
	int st;
	int ft;
	int wt;
	int tt;
	int already;
	int status;
}p[10];
int n;
int cur_time;
int a[1000];
int rear=-1,front=-1;
int tq=3;
void enq(int x)
{
	if(front==-1)
	{
		front=rear=1;
		a[front]=x;
	}
	else
	{
		rear++;
		a[rear]=x;
	}	
	p[x].already=1;
}
int deque()
{
	int x;
	if(front==-1)
	{
		return -1;
	}
	else if(front==rear)
	{
		int v;
		v=a[front];
		front=rear=-1;
		return v;
		
	}
	else
		return a[front++];
}
int execute()
{
	int i;
	i=deque();
	if(i==-1)
		return 0;
	else
	{
		if(p[i].st<=tq)
		{
			cur_time+=p[i].st;
			p[i].st=0;
			p[i].status=1;
			p[i].ft=cur_time;
		}
		else
		{
			p[i].st=p[i].st-tq;
			cur_time+=tq;
		}
		for(int k=0;k<n;k++)
		{
			if(p[k].already!=1)
			{
				if(p[k].at<=cur_time)
				{
						enq(k);
				}
			}
		}
		if(p[i].status!=1)
			enq(i);
		return 1;
	}
}
int main()
{
	int pid,i,back[10];
	cout<<"Enter the size of the processes"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter details of process "<<i+1<<endl;
		cout<<"Enter arrival time"<<endl;
		cin>>p[i].at;
		cout<<"Enter service time"<<endl;
		cin>>p[i].st;
		p[i].status=0;
		p[i].already=0;
		back[i]=p[i].st;
	}
	i=0;
	cur_time=0;
	for(i=0;i<n;i++)
	{
		if(p[i].at<=cur_time)
		{
			enq(i);
		}
	}
	while(execute());
	for(int i=0;i<n;i++)
	{
		p[i].tt=p[i].ft-p[i].at;
		p[i].wt=p[i].tt-back[i];
	}
	cout<<"process "<<" Arrival Time "<<" Service Time "<<"  Finish Time  "<<"  Turn Around  "<<"  Waiting Time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t  "<<p[i].at<<"\t\t"<<back[i]<<"\t\t"<<p[i].ft<<"\t\t"<<p[i].tt<<"\t\t"<<p[i].wt<<endl;
	}
}
