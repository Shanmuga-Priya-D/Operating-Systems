#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
//SHMSZ 30;
int main()
{
int retval,shmid;

void *memory=NULL;
char *p;

key_t key;
key=1234;
shmid=shmget(key,6,IPC_CREAT|0666);

printf("shared memory is created at   %d  ",shmid);

memory=shmat(shmid,NULL,0);
p=(char*)memory;

memset(p,'\0',6);

memcpy(p,"elephant",6);

retval=shmdt(p);

return 0;
}

