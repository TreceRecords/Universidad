//
//  demo9.c
//  El pthread_exit() devuelve una variable global  
//
//  Created by Enrique García Salcines on 10/10/15.
//  Copyright (c) 2015 Universidad de Córdoba. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];

int ret1,ret2;

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();
    
    if(pthread_equal(id,tid[0]))
    {
        printf("\n First thread processing done\n");
        ret1  = 100;
    }
    else
    {
        printf("\n Second thread processing done\n");
        ret2  = 200;
    }
	pthread_exit(NULL);
}

int main(void)
{
    int i = 0;  
    int err;
    int *ptr[2];
    
    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");
        
        i++;
    }
  
    pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
  
	printf("\n return value from first thread is [%d]\n", ret1);
    printf("\n return value from second thread is [%d]\n", ret2);
    
    return 0;
}
