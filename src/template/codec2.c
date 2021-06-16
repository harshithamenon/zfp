#define index(i, j) ((i) + 6 * (j))

/* order coefficients (i, j) by i + j, then i^2 + j^2 */
//cache_align_(static const uchar perm_2[16]) = {
//  index(0, 0), /*  0 : 0 */
//
//  index(1, 0), /*  1 : 1 */
//  index(0, 1), /*  2 : 1 */
//
//  index(1, 1), /*  3 : 2 */
//
//  index(2, 0), /*  4 : 2 */
//  index(0, 2), /*  5 : 2 */
//
//  index(2, 1), /*  6 : 3 */
//  index(1, 2), /*  7 : 3 */
//
//  index(3, 0), /*  8 : 3 */
//  index(0, 3), /*  9 : 3 */
//
//  index(2, 2), /* 10 : 4 */
//
//  index(3, 1), /* 11 : 4 */
//  index(1, 3), /* 12 : 4 */
//
//  index(3, 2), /* 13 : 5 */
//  index(2, 3), /* 14 : 5 */
//
//  index(3, 3), /* 15 : 6 */
//};

cache_align_(static const uchar perm_2[36]) = {
  index(0, 0), /*   0 :  0 */

  index(1, 0), /*   1 :  1 */
  index(0, 1), /*   2 :  1 */

  index(1, 1), /*   3 :  2 */

  index(2, 0), /*   4 :  2 */
  index(0, 2), /*   5 :  2 */

  index(2, 1), /*   6 :  3 */
  index(1, 2), /*   7 :  3 */

  index(3, 0), /*   8 :  3 */
  index(0, 3), /*   9 :  3 */

  index(2, 2), /*  10 :  4 */

  index(3, 1), /*  11 :  4 */
  index(1, 3), /*  12 :  4 */

  index(4, 0), /*  13 :  4 */
  index(0, 4), /*  14 :  4 */

  index(3, 2), /*  15 :  5 */
  index(2, 3), /*  16 :  5 */

  index(4, 1), /*  17 :  5 */
  index(1, 4), /*  18 :  5 */

  index(5, 0), /*  19 :  5 */
  index(0, 5), /*  20 :  5 */

  index(3, 3), /*  21 :  6 */

  index(4, 2), /*  22 :  6 */
  index(2, 4), /*  23 :  6 */

  index(5, 1), /*  24 :  6 */
  index(1, 5), /*  25 :  6 */

  index(4, 3), /*  26 :  7 */
  index(3, 4), /*  27 :  7 */

  index(5, 2), /*  28 :  7 */
  index(2, 5), /*  29 :  7 */

  index(4, 4), /*  30 :  8 */

  index(3, 5), /*  31 :  8 */
  index(5, 3), /*  32 :  8 */

  index(4, 5), /*  33 :  9 */
  index(5, 4), /*  34 :  9 */

  index(5, 5), /*  35 : 10 */
};


#undef index
