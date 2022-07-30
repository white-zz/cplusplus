#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{   
    // int ret;
    // ret  =write(1,"!!!!!!",5);


    // if(ret == -1)
    //   {printf("this is a error!\n");}
    // else
    //     {
    //         printf("it is normol!\n");
    //     }

    void signal_handler(int arg)
    {
        printf("this is a signal handler promt\n!");
    }
    

    signal(SIGINT,signal_handler);

    for(int i=0 ; i<10 ; i++)
    {
        write(1,"*",1);
        sleep(1);
    }


    

    exit(233);
}


