#include <stdlib.h>

#include "bitmap.h"

#define BITMASK 0X1F
#define BITSHIFT 5
#define BLOCK 8		/* 3 bits = 2^3 = 8 blocks */
#define WORDSIZE 32

struct BITMAP_STRUCT 
{
	unsigned int bitmap[BLOCK];
	/* 8 * 32 = 256 bits */
};

bitmap_struct* bitmap_new(void)
{
	bitmap_struct* bms = (bitmap_struct*) malloc (sizeof(bitmap_struct));

	if(!bms) return NULL;

	bitmap_clear(bms);
	return bms
}

void bitmap_free(bitmap_struct *bms)
{
	free(bms);
}

void bitmap_clear(bitmap_struct* bms)
{
	unsigned int i;
	for(i = 0; i < BLOCK; i++)
		bms->bitmap[i] = 0;
}

void bitmap_print(bitmap_struct* bms)
{
	unsigned int i;
	for(i = 0; i < BLOCK; i++)
		printf("%d: %0x\n", i, bms->bitmap[i]);
}

int bitmap_set(bitmap_struct* bms, unsigned int val)
{
	if(val >= BLOCK*WORDSIZE)
		return -1;
	bms->bitmap[(val >> BITSHIFT)] |= (1 << (val & BITMASK));
    return 0;
}

int bitmap_check(bitmap_struct* bms, unsigned int val)
{
	if(val >= BLOCK*WORDSIZE)
		return 0;
	if(bms->bitmap[(val >> BITSHIFT)] & (1 << (val & BITMASK)))
		return 1;
	return 0;
}
