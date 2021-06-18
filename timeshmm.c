#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/mman.h>
#include <sys/stat.h> 


int main(int argc, char *argv[]){

	pid_t pid;
	int status;
	pid = fork();
	
	const int SIZE = 4096; 
    	const char* name = "memoryShare";
    	struct timeval comienzo;
    	struct timeval final;
    
    	int shm_fd; 
    	void* ptr; 
    	
	if(argc<2){
		printf("se debe ejecutar bin/timeshmm <comando/s>\n");
		exit(-1);
	}
	
	if(pid==-1){
		printf("Error al crear el Fork()\n");
		exit(-1);
	}
	
	if(pid == 0){
	//proceso hijo
	    char *argument[]={};
	    for(int i=1;i<argc;i++){
			argument[i-1] = argv[i];
	    }
	    argument[argc-1]=NULL;  
	    
	    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); 
    	    ftruncate(shm_fd, SIZE); 
            ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); 
    	    gettimeofday(&comienzo,NULL);
    	    sprintf(ptr, "%ld",comienzo.tv_usec);
    

	    execvp(argv[1],argument);	
	}
	
	if(pid>0){
	//proceso papa
	    if (waitpid(pid, &status, 0) > 0){
	    	char *temp;
	    	gettimeofday(&final,NULL);
    		shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); 
    		ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); 
    		long tiempo_inicial = strtol((char*)ptr,&temp,10);
    		
    		printf("Tiempo estimado: %ld\n",(final.tv_usec - tiempo_inicial));
    		shm_unlink(name); 
	    
            	printf("Hijo termino su ejecucion correctamente\n");
            	exit(0);
            }
            else{
            	printf("error en el waitpid() \n");
        	exit(-1);
            }
	}
	
	return 0;
}

