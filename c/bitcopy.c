

/*
        Sample for bitwise copy: BitsToCopy(16)
                        |<--HALF WORD-->|
                        |<------------WORD-------------->|
                        0123456789ABCDEF|0123456789ABCDEF|012
        from:	----------------|################|###
        to:		########--------|--------########|###
        bCnt(16) fOfs(0) tOfs(8)
        rMask(0000000011111111)
        wMask(0000111111110000)
*/

#include <stdint.h>
#include <stdio.h>

#define HALF_WORD uint16_t
#define WORD uint32_t

/*
函数说明：from地址处，从fOfs位偏移开始，连续拷贝fCnt个比特，到to地址的tOfs偏移处，且最多拷贝tCnt个比特。返回实际拷贝的比特数。
*/

int bitcopy(void *to, unsigned int tOfs, int tCnt, const void *from,
            unsigned int fOfs, int fCnt) {
  int BitsOfHalfWord = sizeof(HALF_WORD) * 8;
  // align data and offset to HALF_WORD
  to = (void *)((intptr_t)to + (tOfs / BitsOfHalfWord) * sizeof(HALF_WORD));
  from = (void *)((intptr_t)from + (fOfs / BitsOfHalfWord) * sizeof(HALF_WORD));
  fOfs %= BitsOfHalfWord;
  tOfs %= BitsOfHalfWord;

  int NbrOfCopiedBits = 0, bCnt = (fCnt < tCnt) ? fCnt : tCnt;
  WORD rMask, wMask;
  WORD temp, *_to = (WORD *)to, *_from = (WORD *)from;
  while (bCnt > 0) {
    // update counter
    int BitsToCopy = (bCnt < BitsOfHalfWord) ? bCnt : BitsOfHalfWord;
    bCnt -= BitsToCopy;
    NbrOfCopiedBits += BitsToCopy;
    // mask reading from '_from' and mask writing to '_to'
    wMask = (((WORD)-1) << tOfs) ^ (((WORD)-1) << (tOfs + BitsToCopy));
    rMask = (((WORD)-1) << fOfs) ^ (((WORD)-1) << (fOfs + BitsToCopy));
    temp = (*_from & rMask) >> fOfs << tOfs;
    *_to &= ~wMask;
    *_to |= temp;
    printf("%d bit(s) copied\n", BitsToCopy);
    // increase data pointer if copy is not completed
    if (BitsToCopy == BitsOfHalfWord) {
      _to = (WORD *)((intptr_t)_to + sizeof(HALF_WORD));
      _from = (WORD *)((intptr_t)_from + sizeof(HALF_WORD));
    }
  }
  return NbrOfCopiedBits;
}

int main() {
  // printf("DstData[0]:%#04x  DstData[1]:%#04x\n", DstData[0], DstData[1]);
  uint32_t src_data[] = {0};

  return 0;
}