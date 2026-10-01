#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t mutex,wrt;
int sharedVar = 2;
pthread_t writers[5],readers[5];
int readercount = 0;


void* writer(){
printf("Writer wants to write\n");

sem_wait(&wrt);//lock
printf("Writer entered\n");
sharedVar = sharedVar*10;
printf("Value written to sharedVar is %d\n",sharedVar);
sem_post(&wrt);//release lock0
printf("Writer exited\n");

}


void* reader(){
printf("Reader wants to read\n");
sem_wait(&mutex);
readercount++;

if(readercount == 1){
sem_wait(&wrt);
}

sem_post(&mutex);
printf("%d Reader shared variable is %d\n",readercount,sharedVar);

//exit
sem_wait(&mutex);
readercount--;

if(readercount == 0){
sem_post(&wrt);
}
sem_post(&mutex);

}

int main(){
int n2;
printf("Enter the number of readers and writers:");
scanf("%d",&n2);

//initializing with semaphores with default values
sem_init(&mutex,0,1);
sem_init(&wrt,0,1);

//storing thread id's in the array and jumping to function writer/reader
for(int i = 0; i < n2;i++){
pthread_create(&writers[i],NULL, (void*)writer,NULL);
pthread_create(&readers[i],NULL ,(void*)reader,NULL);
}

//Suspends the calling thread
for(int i = 0; i < n2;i++){
pthread_join(writers[i],NULL);
pthread_join(readers[i],NULL);
}

return 0;
}
