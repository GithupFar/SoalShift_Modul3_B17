#include<stdio.h>
#include<pthread.h>
typedef long long int LL;

int i,j;
void factorial(int a)
{
    LL hasil=1;
    for(i=1;i<=a;i++){
        hasil=i*hasil;
    }
    printf("Hasil %d! = %lld\n",a,hasil);		
		//faktorial yg masih bisa dihitung dengan LL adalah hingga 20
}

int main(){
    int n=0,t;
    pthread_t tid[100];
    while(scanf("%d",&t)!=EOF){		//membuat hingga EOF
        pthread_create(&tid[n],NULL,factorial,t);
        pthread_join(tid[n], NULL);
        n++;
    }
	return 0;
}
