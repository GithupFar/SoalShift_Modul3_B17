#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

pthread_t tid [2];
int lohstat, kepistat;


void* kepiting(void *arg)
{
	while (kepistat >0 && kepistat <=100){
		if (kepistat<=0 || kepistat>=100 || lohstat<=0 || lohstat >=100) pthread_exit (&kepistat);
		kepistat -= 10;
//		printf("kepiting semakin lapar = %d\n",kepistat);
		sleep (20);
	}
//	if (kepistat<=0 || lohstat<=0) pthread_exit (&kepistat);
}

void* lohan (void *arg)
{
	while (lohstat >0 && lohstat <=100){
		if (kepistat<=0 || kepistat>=100 || lohstat<=0 || lohstat >=100) pthread_exit (&lohstat);
		lohstat -= 15;
//		printf("lohan semakin lapar = %d\n",lohstat);
		sleep (10);
	}
//	if (kepistat<=0 || lohstat<=0) pthread_exit (&lohstat);
}

int main(){
	lohstat = 100; kepistat = 100;
	int makan;
	
	pthread_create (&tid[0], NULL, &kepiting, NULL);
	pthread_create (&tid[1], NULL, &lohan, NULL);
	

	while (1)
	{
		if (kepistat < 1 || lohstat < 1 || kepistat >100 || lohstat > 100){
			printf("Mati semua!\n");
			pthread_cancel (tid[0]);
			pthread_cancel (tid[1]);
			break;
		}
		printf("Kasih makan\n1.Kepiting\n2.Lohan\n");
		printf("Kasih makan ke mana (1/2)? ");
		scanf("%d",&makan);
		if (makan==1){
			kepistat += 10;
			printf("kepiting dikasih makan = %d\n",kepistat);
		}
		else if (makan ==2 ){
			lohstat += 10;
			printf("lohan dikasih makan = %d\n",lohstat);
		}
	}

	pthread_join (tid[0],NULL);
	pthread_join (tid[1], NULL);

	

/*	if (kepistat < 0 || lohstat < 0){
		pthread_kill (&tid[0], NULL);
		pthread_kill (&tid[1], NULL);
		printf("sudah terbunuh semua\n");
	}
*/
	return 0;
}
