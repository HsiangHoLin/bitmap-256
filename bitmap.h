#ifndef BITMAP_H
#define BITMAP_H

typedef struct BITMAP_STRUCT bitmap_struct;

bitmap_struct* bitmap_new(void);
void bitmap_free(bitmap_struct *bms);
void bitmap_clear(bitmap_struct* bms);
void bitmap_print(bitmap_struct* bms);
int bitmap_set(bitmap_struct* bms, unsigned int val);
int bitmap_check(bitmap_struct* bms, unsigned int val);

#endif
