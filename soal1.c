#include <stdio.h>
#include <unistd.h>

struct details
{
const char* name[10];
int qty;
};

struct details stock[10];


int main ()
{
	*stock[1].name="MP4A1";
        *stock[2].name="PM2-V1";
        *stock[3].name="SPR-3";
        *stock[4].name="MP4A1";
        *stock[5].name="SS2-V5";
        *stock[6].name="SPG1-V3";
        *stock[7].name="MINE";

}
