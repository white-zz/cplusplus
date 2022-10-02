#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>



// 互斥锁，是用来防止两个线程同时访问同一个资源
// 线程同步 - 条件变量  用来阻塞一个线程，等待另一个线程使条件成立，而唤醒线程


// 多线程编程， A线程要在B线程完成后再继续进行
// 1. 使用锁+轮询  （消耗cpu时间多）
// 2. 使用条件变量的线程同步 

// 线程条件变量  pthread_cond_t   
pthread_mutex_t mutex;
pthread_cond_t cond;

void* func1(void* arg)
{
	pthread_mutex_lock(&mutex);
	printf("func1\n");
	pthread_mutex_unlock(&mutex);

}

void* func2(void* arg)
{
	// sleep(1);
	// printf("func2\n");
	// pthread_cond_signal(&cond);
}


int main()
{

	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_t pd1,pd2;

	pthread_create(&pd1,NULL,func1,NULL);
	pthread_create(&pd2,NULL,func2,NULL);

	pthread_mutex_lock(&mutex);
	printf("main1\n");
	pthread_cond_wait(&cond,&mutex); //该线程已经被互斥量锁住了，  解锁给另一个线程去，修改条件变量，该 cond上锁阻塞
	printf("main2\n");

	pthread_join(pd1,NULL);
	pthread_join(pd2,NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	return 0;
}
