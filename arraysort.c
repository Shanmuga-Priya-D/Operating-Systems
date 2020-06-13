// SORTING OF ARRAY ELEMENTS FROM PARENT TO CHILD
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
 int  p[2];
 int pid;
 int  inbuf[10],outbuf[10];
 int temp;
 int n;
 if(pipe(p)==-1)
 {
  printf("pipe failed\n");
  return 1;
 }
else
{
 pid=fork();
 if(pid)
 {
 printf("in parent process\n");
 printf("enter the number of elements");
 scanf("%d",&n);
 printf("type the data to be sent to child \n");
for(int i=0;i<n;i++)
 {
 scanf("%d",&outbuf[i]);
 }
 write(p[1],outbuf,sizeof(outbuf));
 sleep(2);
 printf("after sleep in parent process\n");
 read(p[0],outbuf,sizeof(outbuf));
for(int i=0;i<5;i++)
 {
 printf("%d \n",outbuf[i]);
 }
 }
 else
 {
 printf("in child process\n");
 read(p[0],inbuf,sizeof(inbuf));
 printf("the data received by the child id \n");
 for (int i=0;i<5;i++)
 {
   for(int j=0;j<5-i-1;j++)
    {
     if(inbuf[j]>inbuf[j+1])
        {
         temp=inbuf[j];
         inbuf[j]=inbuf[j+1];
         inbuf[j+1]=temp;
        }
     }
 }
  write(p[1],inbuf,sizeof(inbuf));

 }
}
return 0;
}
