#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int p1, p2, status, minetot;
int mine [5][5]; //4x4 >> mulai dari 0,1,2,3
pthread_t tid [2];
pthread_mutex_t lock;


void isiranjau(int num)
{
	int i,j;
	if (num % 4 == 0){
		i = (num/4)-1;
		j = (num%4)-1;
	}
	else{
		i = num/4;
		j = num%4;
	}
	mine [i][j] = 1; //diisi ranjau
	minetot++;
}

int cekranjau (int num)
{
	int i,j;
	if (num % 4 == 0){
		i = (num/4)-1;
		j = (num%4)-1;
	}
	else{
		i = num/4;
		j = num%4;
	}
	if (mine[i][j]) return 1;
	else return 0;
}


void* play(int player)
{
	int ranjau,pasang,tebak;
	pthread_mutex_lock (&lock);	


	printf("p%d memasang ranjau!\n",player);
	printf("Berapa banyak ranjau yg mau dipasang? ");
	scanf("%d",&ranjau);
	
	for (int i=0;i<ranjau;i++)
	{
		printf("Ranjau mau dipasang dilubang mana? ");
		scanf("%d",&pasang);
		isiranjau (pasang);
		printf("Ranjau sudah dipasang di lubang %d\n",pasang);
	}
	
	if (player==1){
		printf("p2 menebak ranjau sebanyak 4 kali!\n");
		for (int i=0;i<4;i++){
			printf("Mau tebak lubang mana saja? ");
			scanf("%d",&tebak);
			int temp = cekranjau (tebak);
			if (temp) printf("p2 Kena RANJAU!\n");
			p1 += temp;
		}
	}

	else if (player==2){
		printf("p1 menebak ranjau sebanyak 4 kali!\n");
		for (int i=0;i<4;i++){
			printf("Mau tebak lubang mana saja? ");
			scanf("%d",&tebak);
			int temp = cekranjau (tebak);
			if (temp) printf("p1 Kena RANJAU!\n");
			p2 += temp;
		}
	}	

	printf("-----\nskor sementara p1 : %d p2 : %d\n-----\n",p1,p2);
	
	pthread_mutex_unlock (&lock);	

}

int main()
{
	int error;
	if (pthread_mutex_init (&lock, NULL)!=0){
		printf("\n mutex init failed \n");
		return 1;
	}

	pthread_create (&tid[0], NULL, &play, 1);
	pthread_create (&tid[1], NULL, &play, 2);

	while (p1 < 10 || p2 <10 || minetot < 16){
		pthread_create (&tid[0], NULL, &play, 1);
		pthread_create (&tid[1], NULL, &play, 2);
	}

/*	while (1){
		if (p1>10 || p2>10 || minetot > 15) break;
	}
*/
	pthread_join (tid[0], NULL);
	pthread_join (tid[1], NULL);
	pthread_mutex_destroy (&lock);
	
	if (p1>10 || p2>10 || minetot > 15){
		pthread_kill (&tid[0], NULL);
		pthread_kill (&tid[1], NULL);
		if (p1 > p2) printf("\n=====\np1 win\n=====");
		if (p2 > p1) printf("\n=====\np2 win\n=====");
		else printf("No one win\n");
	}

	return 0;
}			
