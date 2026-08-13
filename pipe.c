#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>

int main() {
    int fd[2]; 
    char read_msg[100]; 
    char input_msg[100]; 
    printf("Enter a message for the child: ");
    scanf("%99s", input_msg);

    pipe(fd); 

    if (fork() != 0) { 
        close(fd[0]); 
        write(fd[1], input_msg, sizeof(input_msg)); 
        close(fd[1]); 
        wait(NULL);    
    } else { 
        close(fd[1]); 
        read(fd[0], read_msg, sizeof(read_msg)); 
        printf("Child received: %s\n", read_msg); 
        close(fd[0]); 
    }
    
    return 0;
}



