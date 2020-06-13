#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct queue
{
long type;
char text[200];
}m1;

int main()
{
int msgid;

int msgqid;
msgqid=msgget(42L,0666|IPC_CREAT);
printf("msgqid is %d",msgqid);

do
{
//printf("enter the message");

m1.type=1;

scanf("%s",m1.text);

msgsnd(msgqid,&m1,sizeof(m1),0);
}while(strcmp(m1.text,"end")!=0);


return 0;
}
