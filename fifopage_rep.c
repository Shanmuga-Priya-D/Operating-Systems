#define N  4

#include<stdio.h>


struct RAM
{
  int pno;
}frame[N];

int q_ptr=0;


int isitinRAM(int p_no)
{ int i,flag=0;
  for(i=0;i<N;i++)
  if(frame[i].pno==p_no)
    return i;

  return -1;
}
void init()
{ int i;
  for(i=0;i<N;i++)
    frame[i].pno=-1;
}
void display()
{ int i;
  printf("\nFrame(RAM)");
  for(i=0;i<N;i++)
    printf("\n%d",frame[i].pno);
}


int main()
{
   int p_no, pf=0;
	
   init();
   display();

   while(1)
   {
      printf("\nRequest Page.No: ");
      scanf("%d",&p_no);      
	  if(p_no==-1) break;
	if(isitinRAM(p_no) != -1)
	   	printf("\nPage Hit");
	else
	{
		pf++;
	   	printf("\nPage Miss");
	   	frame[q_ptr].pno=p_no;
	   	q_ptr=(q_ptr+1)%N;
	}
       	display();
        printf("page faults : %d ",pf);
   }
 
   return 0;
}


