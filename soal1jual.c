#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char nama [6][10] = { "MP4A1" , "PM2-V1" , "SPR-3" , "SS2-V5" , "SPG1-V3" , "MINE" };
	int arr [6];
	char input[10];
	int menu = 0,jumlah;
	memset (arr,0,sizeof(arr));

	printf("\n=====\t\tHawari Penjual\t\t=====\n\n");
	while (menu >= 0 && menu < 3)
	{
		printf("Menu: \n 1. List Stock Senjata \n 2. Tambah Stock\n 3. Exit\n");
		scanf("%d",&menu);
		if (menu == 1)
		{
//			printf("Barang yang tersedia\n");
			for (int i=0;i<6;i++)
			{
				if (arr[i] > 0) printf("%s %d \n",nama[i],arr[i]);
			}
			sleep (2);
		}
		else if (menu == 2)
		{
			int n;
			printf ("Berapa banyak barang yang ingin anda update? ");
			scanf("%d",&n);
			while (n>0)
			{
				printf("Masukkan dengan format (nama barang <spasi> jumlah barang): ");
				scanf("%s",input);
				scanf("%d",&jumlah);
				for (int i=0;i<6;i++)
				{
					if (strcmp (input,nama[i]) == 0 )
					{
						arr[i] += jumlah;
						printf("%s %d \n",nama[i],arr[i]);
					}
				}
				n--;
			}
		}
	}
	return 0;
}
