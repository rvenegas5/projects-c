#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#define MSGSIZE 7

int main(int argc , char *argv[] ){

        pid_t pid;
        int status;
        struct timeval comienzo;
        struct timeval final;
	char inMsg[MSGSIZE];
	int p[2], nbytes;
	char outMsg[MSGSIZE];

	if(pipe(p) < 0){
		printf("error en el pipe");
		exit(-1);
	};
	
	if(argc<2){
		printf("se debe ejecutar bin/timeshmm <comando/s>\n");
		exit(-1);
	}

	pid = fork();

        if (pid == -1){
                printf("Error en el fork()");
                exit(-1);
        }


        if(pid == 0){

                int i;
                char *argv_list[30] = {};
                
 		for( i = 1; i < argc; i++){
                        argv_list[i-1]=argv[i];
                }

                argv_list[argc]= NULL;
                gettimeofday(&comienzo,NULL);
                
		snprintf(outMsg,sizeof(outMsg),"%ld",comienzo.tv_usec);
		int writedBytes = write(p[1], outMsg, MSGSIZE);
                if(writedBytes == -1){
			printf("Error en la escritura del pipe()");
			exit(-1);
		}
		
		execvp(argv[1], argv_list);
		               
	}

        if(pid>0){
                if (waitpid(pid, &status, 0) > 0){
                	gettimeofday(&final,NULL);
               	nbytes = read(p[0], inMsg, MSGSIZE);
			if(nbytes > 0 ){
				char* temp;
				long tiempo_inicial = strtol((char*)inMsg,&temp,10);
		                printf("Tiempo estimado: %ld\n", (final.tv_usec - tiempo_inicial));
			}

			if(nbytes == -1){
				printf("error en la lectura del pipe()");
				exit(-1);
			}
		
		        printf("Hijo termino su ejecucion correctamente\n");
            		exit(0);
		 }else{
		 	printf("Hubo un fallo con el waitpid\n");
		 }
               
        }

        exit(0);
}
