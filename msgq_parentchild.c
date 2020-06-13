
//ipc using message queue between parent and child
// if child is created successfully then send message to parent

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct queue
{
long type;
char text[200];
}m1;
int main()
{
int pid;

int msgqid;
msgqid=msgget(42L,0666|IPC_CREAT);
printf("msgqid is %d",msgqid);

m1.type=1;
strcpy(m1.text,"ooooooooo");

pid=fork();
printf("\n the value of pid is %d\n",pid);

if(pid==0)
{
msgsnd(msgqid,&m1,sizeof(m1),0);
printf("\nmessage is sent\n");
}
if(pid>0)
{
msgrcv(msgqid,&m1,sizeof(m1),1,0);
printf("message  is %s\n",m1.text);
printf("\n message is received\n");
}
return 0;
}


