#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int8_t write_buf[1024];
int8_t read_buf[1024];

int main()
{
	int fd;
	char option;
	printf("welcome to the ur 1st character device driver\n");
	
	fd = open("/dev/my_device",O_RDWR);
//	printf("fd:%d\n",fd);	
	if(fd<0){
		printf("cannot open device file\n");
		return 0;
	}
	
	while(1){
		printf("***please enter your option\n");
		printf("          1.Write          \n");
		printf("          2.Read           \n");
		printf("          3.close          \n");
		scanf("%c",&option);	
		printf("your option : %c\n",option);

		switch(option){
			case '1':
				printf("enter the string to write into the driver:\n");
				scanf("%s",write_buf);
				write(fd,write_buf,strlen(write_buf)+1);
				printf("written done successfully\n");
				break;
			case '2':
				printf("data is reading\n");
				read(fd,read_buf,1024);
				printf("\n");
				printf("data : %s\n\n",read_buf);
				break;
			case '3':
				close(fd);
				exit(1);
				break;
			default:
				printf("please enter valid option : %d\n",option);
				break;
		}
	}
	close(fd);
	return 0;
}
