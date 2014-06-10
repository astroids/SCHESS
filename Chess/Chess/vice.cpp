#include <stdio.h>
#include "defs.h"

int main(){
	AllInit();
	int index = 0;

	U64 playBitBoard = 0ULL;
	printf("Start:\n\n");
	PrintBitBoard(playBitBoard);


	playBitBoard |= (1ULL << SQ64(D2));
	printf("D2 Added: \n\n");
	PrintBitBoard(playBitBoard);


	playBitBoard |= (1ULL << SQ64(G2));
	printf("D2 Added: \n\n");
	PrintBitBoard(playBitBoard);

}