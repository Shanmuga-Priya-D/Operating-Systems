#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct queue
{
long type;
char text[200];
}m1,m2;

int main()
{
int msgid;

int msgqid;
msgqid=msgget(42L,0666|IPC_CREAT);
printf("msgqid is %d",msgqid);

/*for(;;)
{
msgrcv(msgqid,&m1,sizeof(m1),1,0);
printf("%s\n",m1.text);
}*/
do
{
//printf("enter the message");
msgrcv(msgqid,&m1,sizeof(m1),1,0);
printf("message received from user 1:%s\n",m1.text);


m2.type=2;

//scanf("%s",m2.text);
fgets(m2.text,50,stdin);

msgsnd(msgqid,&m2,sizeof(m2),0);



}while(strcmp(m2.text,"end")!=0);


return 0;
}
