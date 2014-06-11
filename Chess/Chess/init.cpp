#include "defs.h"
#include <stdlib.h>

// generate 15 bits at a time and shift them to generate 64 bit num
#define RAND_64 ((U64)rand() + \
				 (U64)rand() << 15 + \
				 (U64)rand() << 30 + \
				 (U64)rand() << 45 + \
				 ((U64)rand() & 0xf)<<60)



int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];
U64	SetMask[64];
U64 ClearMask[64];

U64 PieceKeys[13][120];
U64 SideKey;
U64 CastleKeys[16];


void InitHashKeys(){
	for (size_t i = 0; i < 13; i++)
	{
		for (size_t j = 0; j < 120; j++)
		{
			PieceKeys[i][j] = RAND_64;
		}
	}
	SideKey = RAND_64;
	for (size_t i = 0; i < 16; i++)
	{
		CastleKeys[i] = RAND_64;
	}


}











void InitBitMasks(){
	for (size_t i = 0; i < 64; i++)
	{
		SetMask[i] = 0ULL;
		ClearMask[i] = 0ULL;
			
	}

	for (size_t i = 0; i < 64; i++)
	{
		SetMask[i] |= (1ULL << i);   //000001
		ClearMask[i] = ~SetMask[i];	 //111110  //BW NOT op
	}


}



void InitSq120To64(){

	int index = 0;
	int file = FILE_A;
	int rank = RANK_1;
	int sq = A1;
	int sq64 = 0;

	for (index = 0; index < BRD_SQ_NUM; index++)
	{
		Sq120ToSq64[index] = 65; // erasing values shouldn't be 63+
	}

	for (index = 0; index < 64; index++)
	{
		Sq64ToSq120[index] = 120;
	}


	for (rank = RANK_1; rank <= RANK_8; rank++)
	{
		for (file = 0; file <= FILE_H; file++)
		{
			sq = FR2SQ(file, rank);
			Sq64ToSq120[sq64] = sq;
			Sq120ToSq64[sq] = sq64;
			sq64++;
		}

	}


}


void AllInit(){
	InitSq120To64();
	InitBitMasks();
	InitHashKeys();
		
}

