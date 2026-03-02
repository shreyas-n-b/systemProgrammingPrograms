#include<stdio.h>
#include<unistd.h> 
#include<fcntl.h>
#include<sys/types.h>
int main() 
{ 
	int file=0, n; 
	char buffer[25]; 
 	if((file=open("sample.txt",O_RDONLY)) < 0) 
		printf("file open error!\n");
    printf("20 characters from first: ");
 	read(file,buffer,20);
    write(STDOUT_FILENO,buffer,20);
	lseek(file,10,SEEK_SET);
    read(file,buffer,20);
    printf("\n20 characters from middle: ");
    write(STDOUT_FILENO,buffer,20);   
	if((n = lseek(file,0,SEEK_END)) <0)
        printf("lseek operation to end of file failed\n");
    printf("\n20 characters from end of file: ");
    lseek(file,-20,SEEK_END);
    read(file,buffer,20);
    write(STDOUT_FILENO,buffer,20);
    printf("\n---------------------------");
	printf("\nsize of file is %d bytes\n",n);
	close(file);
	return 0; 
}
