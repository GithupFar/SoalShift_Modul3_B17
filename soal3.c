#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[5];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread

int lohstat = 100, kepistat = 100;

void* kasihmakan(void *arg)
{
	unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    if(pthread_equal(id,tid[0]))//thread untuk counter time lohan
    {
		while (lohstat <=100 && lohstat >=0)
		{
			printf("Berkurang 10 lho!");
			sleep (1);
			lohstat -= 10;
			
		}
	}
/*	
	printf("ini ada yang jalan lho");
	system ("cvlc bagimu-negri.mp3");
*/	
	else if (pthread_equal (id,tid[1]))
	{
		while (kepistat <=100 && kepistat >=0)
		{
			printf("Berkurang 10 kepitingnya lho!");
			sleep (2);
			kepistat -= 10;
		}
	}
    else if(pthread_equal(id,tid[2]))
    {
		int anu;
        scanf("%d",&anu);
		lohstat += anu;
		system ("pkill");
    }
    return NULL;
}

void kenyang(int score)

int main(void)
{
    /*int i=0;
    int err;
    while(i<2)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&kasihmakan,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
		pthread_join(tid[i],NULL);
        i++;
    }*/
	int pil;
    printf("Lohan status: %d  |  Crab stat: %d  \n", lohstat, crabstat);
    while(1){
	    printf("1. Feed Lfish\n");
	    printf("2. Feed Crab\n");
	    scanf("%d", &pil);
    if(pil==1){
        pthread_create(&tid[3],NULL,kenyang,lohstat);
    }
    else if(pil==2){
        pthread_create(&tid[4],NULL,kenyang,kepinstat);
    }
	for(i=0;i<5;i++){
	    pthread_join(tid[i],NULL);
	}
    return 0;
}
