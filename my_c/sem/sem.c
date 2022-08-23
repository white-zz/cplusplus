#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>  

// compile  gcc sem.c -lpthread


//open two thread  to add a num
// if num is enough ,   num is not double, because synchron 




// global shared varible
volatile int cnt = 0; // counter

void *thread(void* arg)
{
  int i, niters = *((int*)arg);
  
  for(int i = 0; i < niters; ++i)
    cnt++;
  
  return NULL;
}

int main(int argc, char* argv[])
{

    pthread_t tid1, tid2;
    int nCount;
    if(argc != 2)
    {
        printf("please input a num \n");
        exit(0);
    }

   nCount = atoi(argv[1]);
  // create thread and wait for them to finish
  pthread_create(&tid1, NULL, thread, &nCount);
  pthread_create(&tid2, NULL, thread, &nCount);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  printf("cnt = %d\n", cnt);




}