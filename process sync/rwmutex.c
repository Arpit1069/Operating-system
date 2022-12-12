#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t wr,mutex;
int a = 10,readcount=0;

void * reader(void *arg){
long int num;//when we enter into thread routine we first convert void * argument to integer argument
             //why long int?-void * = 8 bytes and int = 4 bytes
num=(long int) arg;
pthread_mutex_lock(&mutex);
readcount++;
pthread_mutex_unlock(&mutex);

if(readcount==1){
    pthread_mutex_lock(&wr);
}
printf("\nReader %ld is in critical section",num);
printf("\nReader %ld is reading data %d",num,a);
//sleep(1);

pthread_mutex_lock(&mutex);
readcount--;
pthread_mutex_unlock(&mutex);
if(readcount==0){
    pthread_mutex_unlock(&wr);
}
printf("\nReader %ld left the critical section",num);
}

void * writer(void *arg){
long int num;
num=(long int)arg;

//lock wr variable to enter critical section
pthread_mutex_lock(&wr);

printf("\nWriter %ld is in critical section",num);
printf("\n Writer %ld have written data as %d:",num,++a);
//sleep(1);


//writer releases a lock on wr
pthread_mutex_unlock(&wr);
printf("\nWriter %ld left the critical section",num);
}

int main()
{
pthread_t r[10],w[10]; //array of variable reader and writer
long int i,j;
int no_of_reader,no_of_writer; //index variables required for joining threads

//initialize mutex variables
pthread_mutex_init(&wr,NULL);
pthread_mutex_init(&mutex,NULL);

//get number of reader and writer
printf("Enter number of readers:");
scanf("%d",&no_of_reader);
printf("Enter number of writers:");
scanf("%d",&no_of_writer);

//create reader and writer threads of given number
for (i=0;i<no_of_reader;i++){
    pthread_create(&r[i],NULL,reader,(void * )i);
}
for (j=0;j<no_of_writer;j++){
    pthread_create(&w[j],NULL,writer,(void * )j);
}

//Join the threads
for (i=0;i<no_of_reader;i++){
    pthread_join(r[i],NULL);
}
for (j=0;j<no_of_writer;j++){
    pthread_join(w[j],NULL);
}

return 0;
}