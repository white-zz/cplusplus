#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>



static void *print_test(void)
{
    while(1)
    {printf("this is a thread! \n");
    sleep(5);}
    return NULL;
}


int main()
{
    pthread_t tid;

    pthread_create(&tid,NULL,print_test,NULL);

    while(1){
       printf("this is a main! \n");
       sleep(5);


    }
}