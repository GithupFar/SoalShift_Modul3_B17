#include <stdio.h>
#include <string.h>



int carinama(char cari[])
{
	int banyaknama = 0;
	FILE *fileIn;
	char *line = NULL;
	size_t len = 0;
	fileIn = fopen ("Novel.txt","r");
	while (getline (&line, &len, fileIn) != -1){
		if (strstr(line,cari)!=NULL){
			banyaknama++;
		}
	}
	return banyaknama;
}

int main()
{
	char nama [100];
	scanf("%s",nama);

	int banyak;
	banyak = carinama(nama);
	printf("%d\n",banyak);
	return 0;
}

		
