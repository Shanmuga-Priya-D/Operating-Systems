// CONCATENATE STRING
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
int fd1[2];
int fd2[2];

char a[]="hello";
char b[20];

int p;

if(pipe(fd1)==-1)
{
printf("pipe failed");
return 1;
}
if(pipe(fd2)==-1)
{
printf("pipe failed");
return 1;
}
printf("enter the string");
scanf("%s",b);
char concat_str[10];
p=fork();
if(p<0)
{
printf("fork failed");
return 1;
}
else if(p>0)
{
close(fd1[0]);
write(fd1[1],b,strlen(b)+1);
close(fd1[1]);
close(fd2[1]);
read(fd2[0],concat_str,100);
printf("concatenated string is %s",concat_str);
close(fd2[0]);
}
else
{
close(fd1[1]);
read(fd1[0],concat_str,100);
int k=strlen(concat_str);
int i;
for(i=0;i<strlen(a);i++)
concat_str[k++]=a[i];

concat_str[k]='\0';
close(fd1[0]);
close(fd2[0]);

write(fd2[1],concat_str,strlen(concat_str)+1);
close(fd2[1]);
}
return 0;
}

	

