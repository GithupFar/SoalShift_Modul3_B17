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
    int n,t;
    scanf("%d",&n);
    pthread_t tid[n];
    for(j=0;j<n;j++){
        scanf("%d",&t);
        pthread_create(&tid[j],NULL,factorial,t);
        pthread_join(tid[j], NULL);
    }
}
