#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int count = 0;


void alarm_handler()
{  count++;
   if(count % 5==0)
     printf("5s is come____count:%d\n",count);
   else if(count % 3 == 0)
      printf("3s is come____count:%d\n",count);
   
   
   alarm(1);

}


int main()
{

//   while(1){   
//     alarm(1);
//     count++;
//     }
    signal(SIGALRM,alarm_handler);
    alarm(1);

    
 
    
   
  
   while(1){
     pause();
   }

   exit(0);
}