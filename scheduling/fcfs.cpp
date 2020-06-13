#include<iostream>
using namespace std;
struct process
{
	int at;
	int st;
	int ft;
	int status;
}p[10];
int n;
int execute(int time)
{
	int index=-1,i;
	for(i=0;i<n;i++)
	{
		if(p[i].status!=1)
		{
			if(p[i].at<=time)
			{
				index= i;
				break;
			}
		}
	}
	return index;
}
int main()
{
	int cur_time,pid,i;
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
	}
	i=0;
	cur_time=0;
	while(i<n)
	{
		pid=execute(cur_time);
		p[pid].ft=p[pid].st+cur_time;
		cur_time+=p[pid].st;
		p[pid].status=1;
		i++;
	}
	cout<<"process "<<" Arrival Time "<<" Service Time "<<"  Finish Time  "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t  "<<p[i].at<<"\t\t"<<p[i].st<<"\t\t"<<p[i].ft<<endl;;
	}
}
