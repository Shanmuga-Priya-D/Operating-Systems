#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
struct person
{
    int id;
    char name[20];
    int m1;
    int m2;
};
char buf[25];
int main()
{
int p[2];
int pid;
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

FILE *outfile;

    // open file for writing
    outfile = fopen ("student.txt", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        return 0;
    }

    struct person input1 = {1, "rohan", 100,100};
    struct person input2 = {2, "mahendra",50,50};

    // write struct to file
    fwrite (&input1, sizeof(struct person), 1, outfile);
    fwrite (&input2, sizeof(struct person), 1, outfile);

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);

   write(p[1],"student.txt",12);
 sleep(2);
 printf("after sleep in parent process\n");


}
else
 {
 printf("in child process\n");
read(p[0],buf,12);
FILE *infile;
    struct person input;

    // Open person.dat for reading
    infile = fopen (buf, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return 0;
    }

    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, infile))
        printf ("id = %d name = %s m1=%d m2=%d \n", input.id,
        input.name, input.m1,input.m2);

    // close file
    fclose (infile);
}
return 0;
}
}

	

