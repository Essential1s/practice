#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int fd;
	size_t size;
	char string[] = "Gr. 3.008.2.23";
	if((fd = open("wrfile.txt", O_WRONLY|O_CREAT, 0666)) < 0){
		printf("Oshibka pri otkritie faila on record\n");
		exit(-1);
	}
	size = write(fd, string, 14);
	if (size != 14) {
		printf ("ne udalos 14 bytes v file\n");
		exit (-1);
	}
	else printf ("stroka zapisana v file\n");
	if(close(fd) < 0) {
		printf("ne poluchilos zakrit file\n");
		exit(-1);
	}
	char resstring[14];
	if((fd = open("wrfile.txt", O_RDONLY)) < 0) {
		printf("error open file to read\n");
		exit(-1);
	}
	size - read(fd, resstring, 14);
	if (size != 14) {
		printf("ne udalos read 14 byte out file\n");
		exit(-1);
		}
		else printf("read stroka: %s\n", resstring);
		if (close(fd) < 0) {
			printf("ne poluchilos close file\n");
			exit(-1);
	}
	return 0;
}
