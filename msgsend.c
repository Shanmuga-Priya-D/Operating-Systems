#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<string.h>

struct queue
{
long type;
char text[200];
}buf;

int main()
{
int msgqid;
msgqid=msgget(42L,0666|IPC_CREAT);
printf("msgqid is %d",msgqid);

printf("enter the message");
scanf("%s",buf.text);

do
{
printf("enter the message type");
scanf("%ld",&buf.type);

int len=strlen(buf.text);
msgsnd(msgqid,&buf,len+1,0);
printf("enter the message");
scanf("%s",buf.text);
}
while(strcmp(buf.text,"end")!=0);

//msgctl(msgqid,);

}

