static uint _t2(rev_encode_block, Int, DIMS)(bitstream* stream, int minbits, int maxbits, int maxprec, Int* iblock);

/* public functions -------------------------------------------------------- */

/* encode contiguous integer block */
uint
_t2(zfp_encode_block, Int, DIMS)(zfp_stream* zfp, const Int* iblock)
{
  cache_align_(Int block[BLOCK_SIZE_MAX]);
  uint i;
  uint grid_size = zfp->grid_size;
  /* copy block */
  for (i = 0; i < BLOCK_SIZE_N(grid_size); i++)
    block[i] = iblock[i];
  return REVERSIBLE(zfp) ? _t2(rev_encode_block, Int, DIMS)(zfp->stream, zfp->minbits, zfp->maxbits, zfp->maxprec, block) : _t2(encode_block, Int, DIMS)(zfp->stream, zfp->minbits, zfp->maxbits, zfp->maxprec, block, grid_size);
}
