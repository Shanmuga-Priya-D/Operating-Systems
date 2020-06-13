// PARENT AND CHILD PROCESS
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int p[2];
int pid;
char inbuf[10],outbuf[10];
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
printf("type the data to be sent to child");
scanf("%s",outbuf);
write(p[1],outbuf,sizeof(outbuf));
sleep(2);
printf("after sleep in parent process");
}
else
{
printf("in child process");
read(p[0],inbuf,10);
printf("data received by child is %s\n",inbuf);
}
return 0;
}
}
