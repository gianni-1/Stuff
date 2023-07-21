#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void encrypt(char *msg,int shift_value){

    for(int i=0;i<(strlen(msg));i++){
        char n= msg[i]%127;
        n=n+shift_value;
        msg[i]=n;
    }
}

int main(){
    int shift_value=7;

    int fd[2],nbytesparent,nbyteschild;
    pipe(fd);

    char string[]="Lang lebe IBN!";
    char readbufferparent[128];
    char readbufferchild[128];

    pid_t pid;
    pid = fork();
    if(pid==-1){
        std::cerr<<"fork"<<std::endl;
    }

    else if(pid>0){
        //Parent process
        
        write(fd[1],string,(strlen(string)+1));
        

        wait(0);           //wait for child process to finish 

        close(fd[1]); //closes up output side of pipe
        nbytesparent = read(fd[0],readbufferparent,sizeof(readbufferparent));
        close(fd[0]); //closes up input side of pipe

        std::cout<<"Received and encrypted string: "<<readbufferparent<<std::endl;
    }

    else{
        //Child process
        
        nbyteschild=read(fd[0],readbufferchild,sizeof(readbufferchild));
        


        encrypt(string,shift_value); //encrypt the message

        //send encrypted message back to parent
        close(fd[0]); //closes up input side of pipe
        write(fd[1],string,(strlen(string)+1));
        close(fd[1]); //closes up output side of pipe

        

    }
    return 0;
}