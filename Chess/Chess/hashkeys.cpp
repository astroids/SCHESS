#include "defs.h"

U64 GeneratePosKey(const S_BOARD * pos){

	U64 finalKey = 0;
	int piece = EMPTY;

	for (size_t i = 0; i < BRD_SQ_NUM; i++)
	{
		piece = pos->pieces[i];
		if (piece != NO_SQ && piece != EMPTY){
			ASSERT(piece >= wP && piece <= bK);
			finalKey ^= PieceKeys[piece][i];
		}

	}

	if (pos->side == WHITE){
		finalKey ^= SideKey;
	}
	if (pos->enPas != NO_SQ){
		ASSERT(pos->enPas >= 0 && pos->enPas < BRD_SQ_NUM);
		finalKey ^= PieceKeys[EMPTY][pos->enPas];

	}

	ASSERT(pos->castlePerm >= 0 && pos->castlePerm <= 15);

	finalKey ^= CastleKeys[pos->castlePerm];

	return finalKey;
}