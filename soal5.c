#include <stdio.h>
#include <string.h>
#include <pthread.h>

void* carinama(char cari[])
{
	int banyaknama = 0;
	
	FILE *fileIn;
	char *line = NULL;
	size_t len = 0;
	fileIn = fopen ("Novel.txt","r");
	char txt [2000];	//karena sudah tau jumlahnya

	fgets (txt, sizeof(txt), fileIn);
	int pjgnama = strlen (cari);
	int pjgtxt = strlen (txt);
	int banyak = 0;
//	printf("pgjnama %d pgxt %d\n",pjgnama,pjgtxt);

	for (int i = 0; i <= pjgtxt - pjgnama; i++)
    {
        int j;
  
        /* For current index i, check for pattern match */
        for (j = 0; j < pjgnama; j++)
            if (txt[i+j] != cari[j])
                break;
 
        if (j == pjgnama){  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
//           printf("Pattern found at index %d n", i);
		banyak++;
	}
    }
	printf("%s : %d\n",cari,banyak);
}

int main()
{
	char nama [1000];
	pthread_t tid[1000];
	int n=0;
	while (scanf("%s",nama)!=EOF)
	{
		pthread_create(&tid[n],NULL,&carinama,nama);
        	n++;
	}
	for (int i=0;i<n;i++) pthread_join (tid [i],NULL);
	return 0;
}
