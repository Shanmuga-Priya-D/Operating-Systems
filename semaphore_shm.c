
// semaphore+parent child+shared memory
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<semaphore.h>
#include<stdlib.h>

int main()
{
int i;
int shmid;
key_t key;
sem_t *sem;
pid_t pid;
int *p;  // shared varibale i.e resource
int n; //fork count user will enter
int value; //semaphore value user will enter

// we initialize a shared variable in shared memory 

/*........................................... part-1 shared memory usage.............................*/
key=1234;
shmid=shmget(key,6,IPC_CREAT|0666);

p=(int*)shmat(shmid,NULL,0);// attach p to shared memory
*p=0;
printf("p=%d is allocated in shared memory\n\n",*p);

/*------------------------------------------------part-2 forking and semaphore count declaration-------------*/
printf("enter the number of children u want to fork?\n");
printf("count");
scanf("%d",&n);

printf("semphore value, binary or counting\n");
printf("semaphore value:");
scanf("%d",&value);

/*--------------------------------------------part-4 forking and shell ----------------------------*/

for(i=0;i<n;i++)
{
pid=fork();
if(pid==0)
   break; // child process
}
    
if(pid!=0) // parent process
{

}


else
{
sem_wait(sem);
printf("child(%d)is in critical section.\n",i);
sleep(5);
*p+=i%3; //increment *p by 0,1,2 based on i
printf("child(%d)new value of *p=%d\n",i,*p);
sem_post(sem);
}
}







