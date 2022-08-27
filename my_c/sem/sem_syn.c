#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

// 生产者和消费者模型
// 实现同步的操作

// 代码表现上就是，两个线程共享一个资源
// 一个线程提供资源
// 另一个线程消费资源
// 资源是有限的，不能提供过多的资源，不能预支资源

// 注意：
// 同步进程，是两个合作的进程
// 多个semWait操作的次序不能颠倒，否则可能导致死锁
// 多个semSignal操作的次序可任意

// 关系：
// 互斥：临界资源者进程互斥访问
// 同步： 有先后关系
// 缓冲区未满，生产者才能放东西
// 缓冲区非空，消费者才能取东西

// 生产者：  生产        |是否能添加|  -》添加 -》（临界区  ） -》 |是否能取出|   -》 取出      消费 消费者 

#define NUM 5
sem_t blank_number, product_number;

int arr[NUM];

void P(sem_t* s) {sem_wait(s);}
void V(sem_t* s) {sem_post(s);}

void *produce(){
    int i = 0;
    while(1){
        P(&blank_number);   // is blank ?
        arr[i] = rand()%100 + 1;
        printf("---comsumer--%d\n",arr[i]);
        V(&product_number);
        i = (i+1)%NUM;

        sleep(rand()%2);
    }

}
void *comsumer(){
    int i = 0;
    while(1){
        P(&product_number);   // is product ?
        printf("---produce--%d\n",arr[i]);
        arr[i] = 0;
        V(&blank_number);
        i = (i+1)%NUM;

        sleep(rand()%3);
    }


}

int main(){
    pthread_t pid_p,pid_c;
    sem_init(&blank_number,0,NUM);
    sem_init(&product_number,0,0);
    pthread_create(&pid_p,NULL,produce,NULL);
    pthread_create(&pid_c,NULL,comsumer,NULL);

    pthread_join(pid_p, NULL);  //等待子线程执行完，没执行完阻塞
    pthread_join(pid_c, NULL);  //防止子线程没执行完，主线程直接跑完了


    sem_destroy(&blank_number);
    sem_destroy(&product_number);
    return 0;
}