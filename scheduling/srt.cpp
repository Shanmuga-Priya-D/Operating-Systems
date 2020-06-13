#include<iostream>
using namespace std;
struct process
{
	int at;
	int st;
	int ft;
	int wt;
	int status;
}p[10];
int n;
int execute(int time)
{
	int small=1000;
	int index=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i].status!=1)
		{
			if(p[i].at<=time)
			{
				if(p[i].st<small)
				{
						small=p[i].st;
						index=i;
				}
			}
		}
	}
	return index;
}
int main()
{
	int i,cur_time,pid,back[100];
	int add=0;
	cout<<"Enter the no of the process"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter details of process "<<i+1<<endl;
		cout<<"Enter arrival time"<<endl;
		cin>>p[i].at;
		cout<<"Enter service time"<<endl;
		cin>>p[i].st;
		p[i].status=0;
		back[i]=p[i].st;
	}
	i=0;
	cur_time=0;
	for(int i=0;i<n;i++)
	{
		add+=p[i].st;
	}
	while(cur_time<=add)
	{
		pid=execute(cur_time);
		p[pid].st-=1;
		cur_time+=1;
		if(p[pid].st==0)
		{
			p[pid].status=1;
			p[pid].ft=cur_time;
		}
	}
	
	cout<<"process "<<" Arrival Time "<<" Service Time "<<"  Finish Time  "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t  "<<p[i].at<<"\t\t"<<back[i]<<"\t\t"<<p[i].ft<<endl;;
	}
}
