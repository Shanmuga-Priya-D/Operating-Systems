#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct queue
{
long type;
char text[200];
}buf;

long int x;
int i=1;
int main()
{
int msgqid;
msgqid=msgget(42L,0666|IPC_CREAT);
printf("%d",msgqid);
while(i<=5)
{
printf("enter the type");
scanf("%ld",&buf.type);
printf("%ld",buf.type);


msgrcv(msgqid,&buf,sizeof(buf.text),buf.type,0);
printf("message associated with type is %s",buf.text);


i++;
}
}

