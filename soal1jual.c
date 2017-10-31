#include <stdio.h>
#include <string.h>

int main()
{
	char barang [6][10] = { "MP4A1" , "PM2-V1" , "SPR-3" , "SS2-V5" , "SPG1-V3" , "MINE" };
	char input[10];
	int jumlah;
	scanf("%s",input);
	for (int i=0;i<6;i++)
	{
		if (strcmp (input,barang[i]) == 0 ) printf("%s BENAR\n",barang[i]);
	}
	return 0;
}
