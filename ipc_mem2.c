#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main() {
	int *array;
	int shmid;
	int new = 1;
	char pathname[] = "fifo1.c";
	key_t key;
	if ((key = ftok(pathname, 0)) < 0){
		printf("ne udalos generate ip-key\n");
		exit(-1);
	}
	if((shmid = shmget(key, 3*sizeof(int), 0666 | IPC_CREAT | IPC_EXCL)) < 0) {
		if(errno != EEXIST) {
			printf("ne udalos create segment shared memory\n");
			exit(-1);
	}
	else {
		if((shmid = shmget(key, 3*sizeof(int), 0)) < 0) {
				printf("ne udalis find shared memory segment\n");
				exit(-1);
		}
		new = 0;
	}
}
if ((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {
	printf("ne udalos connect shared memory segment to adress prostranstvu processa\n");
	exit(-1);
}
if(new)
	 {
	array[0] = 0;
	array[1] = 1;
	array[2] = 1;
}
	else{
		array[1] += 1;
		array[2] += 1;
	}
printf("program 2 was launched %d raz(a), obshee amount of launches of both programs: %d\n", array[1], array[2]);
if(shmdt(array) <0) {
	printf("ne udalos delete segment shared memory out of adr. prostranstva tekushego process\n");
	exit(-1);
	}
return 0;
}
