#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

pthread_t tid [2];
int mine [5][5]; //4x4 >> mulai dari 0,1,2,3
int minetot,p1,p2;
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
	if (!mine[i][j]) minetot++;
	mine [i][j] = 1; //diisi ranjau
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

void* play1 (void* arg)
{
	int ranjau,pasang,tebak;
	pthread_mutex_lock (&lock);
	printf("p1 memasang ranjau!\n");
	
	while (1)
	{
		printf("Berapa banyak ranjau yg mau dipasang oleh p1? ");
		scanf("%d",&ranjau);
		if (ranjau > 4) printf("input invalid! Masukkan 1-4 saja!\n");
		else if (ranjau >= 0 && ranjau <= 4) break;
		
	}
	
	for (int i=0;i<ranjau;i++)
	{
		printf("Ranjau mau dipasang dilubang mana? ");
		scanf("%d",&pasang);
		isiranjau (pasang);
		printf("Ranjau sudah dipasang di lubang %d\n",pasang);
	}
	printf("\np2 menebak ranjau sebanyak 4 kali!\n");
	for (int i=0;i<4;i++){
		printf("Mau tebak lubang mana saja? ");
		scanf("%d",&tebak);
		int temp = cekranjau (tebak);
		if (temp) printf("p2 Kena RANJAU!\n");
		p1 += temp;
	}

	printf("\n\nStatus => p1 : %d \t p2 : %d\n\n",p1,p2);
	pthread_mutex_unlock (&lock);
}

void* play2 (void* arg)
{
	int ranjau,pasang,tebak;
	pthread_mutex_lock (&lock);
	printf("p2 memasang ranjau!\n");
	
	while (1)
	{
		printf("Berapa banyak ranjau yg mau dipasang oleh p2? ");
		scanf("%d",&ranjau);
		if (ranjau > 4) printf("input invalid! Masukkan 1-4 saja!\n");
		else if (ranjau >= 0 && ranjau <= 4) break;
		
	}
	
	
	for (int i=0;i<ranjau;i++)
	{
		printf("Ranjau mau dipasang dilubang mana? ");
		scanf("%d",&pasang);
		isiranjau (pasang);
		printf("Ranjau sudah dipasang di lubang %d\n",pasang);
	}
	printf("p1 menebak ranjau sebanyak 4 kali!\n");
	for (int i=0;i<4;i++){
		printf("Mau tebak lubang mana saja? ");
		scanf("%d",&tebak);
		int temp = cekranjau (tebak);
		if (temp) printf("p1 Kena RANJAU!\n");
		p2 += temp;
	}

	printf("\n\nStatus => p1 : %d \t p2 : %d\n\n",p1,p2);
	pthread_mutex_unlock (&lock);
}

int main()
{
	minetot = 0; p1 = 0; p2 = 0;

	printf("LET'S PLAY!\n");
	while (1)
	{
		if (minetot>15 || p1 > 9 || p2 > 9){
			printf("Sudah selesai!\n");
			pthread_cancel (tid[0]);
			pthread_cancel (tid[1]);
			break;
		}

	pthread_create (&tid[0], NULL, &play1, NULL);
	pthread_create (&tid[1], NULL, &play2, NULL);

		
	}
	
	pthread_join (tid[0],NULL);
	pthread_join (tid[1],NULL);

	pthread_mutex_destroy (&lock);
	printf("Winner of this Game!\n");
	if (p1 > p2) printf("\n=====\np1 win\n=====\n");
	else if (p2 > p1) printf("\n=====\np2 win\n=====\n");
	else printf("No one win\n");
	return 0;
}
