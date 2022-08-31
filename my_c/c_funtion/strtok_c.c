
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



 
int main()
{
        // int in = 0;
        // char buffer[20] = "Fred,John,Ann";
        // char *p[3];
        // char *buf = buffer;
        // while((p[in] = strtok(buf, ",")) != NULL)
        // {   
        //         in++;
        //         buf = NULL;
        //         printf("1\n");
        // }   
        // printf("buffer = %s\n", buffer);
        // printf("p1 = %s\n", p[0]);
        // printf("p2 = %s\n", p[1]);
        // printf("p3 = %s\n", p[2]);

       char buffer[20] = "Fred,John,Ann";
       char *buf=buffer;
        char *outer_ptr=NULL;
        char *inner_ptr=NULL;
        char *p[20];
        int i = 0;
        while((p[i++]=strtok_r(buf,",",&outer_ptr))!=NULL) {      
         buf = NULL;
        }
         for (int j=0; j<i-1;j++){
            printf("%s\n",p[j]);
         }      


        return 0;

}

