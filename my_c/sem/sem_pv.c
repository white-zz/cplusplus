#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>


// PV use


// interface
//int sem_init(sem_t *sem, int pshared, unsigned int value);
//int sem_wait(sem_t *sem);
//int sem_post(sem_t *sem);



//如果线程 0 持有锁（即调用了 sem_wait()之后，调用 sem_post()之前），
//另一个线程（线程 1）调用 sem_wait()尝试进入临界区
//线程 1把信号量减为-1，然后等待（自己睡眠，放弃处理器）
//线程 0 再次运行，它最终调用 sem_post()，将信号量的值增加到 0，唤醒等待的线程（线程 1）
//然后线程 1 就可以获取锁。线程 1 执行结束时，再次增加信号量的值，将它恢复为 1。
volatile int cnt = 0; // counter

sem_t mutex;

void P(sem_t* s) {sem_wait(s);}
void V(sem_t* s) {sem_post(s);}

//thread
void *thread(void* arg)
{
  int i, niters = *((int*)arg);
  
  for(int i = 0; i < niters; ++i)
  {
    P(&mutex);
    cnt++;
    V(&mutex);
  }
  return NULL;
}

int main(int argc, char *argv[]){
    int num;
    pthread_t tid1,tid2;
    sem_init(&mutex,0,1);   //mute =1

    if(argc != 2)
      {
        printf("please input a num \n");
        exit(0);
      }

    num = atoi(argv[1]);
    pthread_create(&tid1, NULL, thread, &num);
    pthread_create(&tid2, NULL, thread, &num);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
  
     printf("cnt = %d\n", cnt);

  return 0;
}



