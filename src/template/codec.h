#define PERM _t1(perm, DIMS)           /* coefficient order */
#define BLOCK_SIZE 36 /*(1 << (2 * DIMS))*/   /* values per block */
#define BLOCK_SIZE_MAX 64
#define BLOCK_SIZE_N(n) (pow(n,DIMS))
#define EBIAS ((1 << (EBITS - 1)) - 1) /* exponent bias */
#define REVERSIBLE(zfp) ((zfp)->minexp < ZFP_MIN_EXP) /* reversible mode? */
