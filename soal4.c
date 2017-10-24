#include<stdio.h>
#include<pthread.h>

int i,j;
void factorial(int a)
{
    int hasil=1;
    for(i=1;i<=a;i++){
        hasil=i*hasil;
    }
    printf("Hasil %d! = %d\n",a,hasil);
}

int main(){
    int n=0,t;
    pthread_t tid[n];
    while(1){
        scanf("%d",&t);
        pthread_create(&tid[n],NULL,factorial,t);
        pthread_join(tid[n], NULL);
        n++;
    }
}
