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

for(;;)
{
msgrcv(msgqid,&m1,sizeof(m1),1,0);
printf("%s\n",m1.text);
}
return 0;
}
