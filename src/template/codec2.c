#define index(i, j, gsize) ((i) + gsize * (j))

/* order coefficients (i, j) by i + j, then i^2 + j^2 */
cache_align_(static const uchar perm_2[][64]) = {
  { /* order 0 */
    index(0, 0, 1), /*   0 :  0 */
  },
  { /* order 1 */
    index(0, 0, 2), /*   0 :  0 */

    index(1, 0, 2), /*   1 :  1 */
    index(0, 1, 2), /*   2 :  1 */

    index(1, 1, 2), /*   3 :  2 */
  },
  { /* order 2 */
    index(0, 0, 3), /*   0 :  0 */

    index(1, 0, 3), /*   1 :  1 */
    index(0, 1, 3), /*   2 :  1 */

    index(1, 1, 3), /*   3 :  2 */

    index(2, 0, 3), /*   4 :  2 */
    index(0, 2, 3), /*   5 :  2 */

    index(2, 1, 3), /*   6 :  3 */
    index(1, 2, 3), /*   7 :  3 */

    index(2, 2, 3), /*   8 :  4 */
  },
  { /* order 3 */
    index(0, 0, 4), /*   0 :  0 */

    index(1, 0, 4), /*   1 :  1 */
    index(0, 1, 4), /*   2 :  1 */

    index(1, 1, 4), /*   3 :  2 */

    index(2, 0, 4), /*   4 :  2 */
    index(0, 2, 4), /*   5 :  2 */

    index(2, 1, 4), /*   6 :  3 */
    index(1, 2, 4), /*   7 :  3 */

    index(3, 0, 4), /*   8 :  3 */
    index(0, 3, 4), /*   9 :  3 */

    index(2, 2, 4), /*  10 :  4 */

    index(3, 1, 4), /*  11 :  4 */
    index(1, 3, 4), /*  12 :  4 */

    index(3, 2, 4), /*  13 :  5 */
    index(2, 3, 4), /*  14 :  5 */

    index(3, 3, 4), /*  15 :  6 */
  },
  { /* order 4 */
    index(0, 0, 5), /*   0 :  0 */

    index(1, 0, 5), /*   1 :  1 */
    index(0, 1, 5), /*   2 :  1 */

    index(1, 1, 5), /*   3 :  2 */

    index(2, 0, 5), /*   4 :  2 */
    index(0, 2, 5), /*   5 :  2 */

    index(2, 1, 5), /*   6 :  3 */
    index(1, 2, 5), /*   7 :  3 */

    index(3, 0, 5), /*   8 :  3 */
    index(0, 3, 5), /*   9 :  3 */

    index(2, 2, 5), /*  10 :  4 */

    index(3, 1, 5), /*  11 :  4 */
    index(1, 3, 5), /*  12 :  4 */

    index(4, 0, 5), /*  13 :  4 */
    index(0, 4, 5), /*  14 :  4 */

    index(3, 2, 5), /*  15 :  5 */
    index(2, 3, 5), /*  16 :  5 */

    index(4, 1, 5), /*  17 :  5 */
    index(1, 4, 5), /*  18 :  5 */

    index(3, 3, 5), /*  19 :  6 */

    index(4, 2, 5), /*  20 :  6 */
    index(2, 4, 5), /*  21 :  6 */

    index(4, 3, 5), /*  22 :  7 */
    index(3, 4, 5), /*  23 :  7 */

    index(4, 4, 5), /*  24 :  8 */
  },
  { /* order 5 */
    index(0, 0, 6), /*   0 :  0 */

    index(1, 0, 6), /*   1 :  1 */
    index(0, 1, 6), /*   2 :  1 */

    index(1, 1, 6), /*   3 :  2 */

    index(2, 0, 6), /*   4 :  2 */
    index(0, 2, 6), /*   5 :  2 */

    index(2, 1, 6), /*   6 :  3 */
    index(1, 2, 6), /*   7 :  3 */

    index(3, 0, 6), /*   8 :  3 */
    index(0, 3, 6), /*   9 :  3 */

    index(2, 2, 6), /*  10 :  4 */

    index(3, 1, 6), /*  11 :  4 */
    index(1, 3, 6), /*  12 :  4 */

    index(4, 0, 6), /*  13 :  4 */
    index(0, 4, 6), /*  14 :  4 */

    index(3, 2, 6), /*  15 :  5 */
    index(2, 3, 6), /*  16 :  5 */

    index(4, 1, 6), /*  17 :  5 */
    index(1, 4, 6), /*  18 :  5 */

    index(5, 0, 6), /*  19 :  5 */
    index(0, 5, 6), /*  20 :  5 */

    index(3, 3, 6), /*  21 :  6 */

    index(4, 2, 6), /*  22 :  6 */
    index(2, 4, 6), /*  23 :  6 */

    index(5, 1, 6), /*  24 :  6 */
    index(1, 5, 6), /*  25 :  6 */

    index(4, 3, 6), /*  26 :  7 */
    index(3, 4, 6), /*  27 :  7 */

    index(5, 2, 6), /*  28 :  7 */
    index(2, 5, 6), /*  29 :  7 */

    index(4, 4, 6), /*  30 :  8 */

    index(3, 5, 6), /*  31 :  8 */
    index(5, 3, 6), /*  32 :  8 */

    index(4, 5, 6), /*  33 :  9 */
    index(5, 4, 6), /*  34 :  9 */

    index(5, 5, 6), /*  35 : 10 */
  },
  { /* order 6 */
    index(0, 0, 7), /*   0 :  0 */

    index(1, 0, 7), /*   1 :  1 */
    index(0, 1, 7), /*   2 :  1 */

    index(1, 1, 7), /*   3 :  2 */

    index(2, 0, 7), /*   4 :  2 */
    index(0, 2, 7), /*   5 :  2 */

    index(2, 1, 7), /*   6 :  3 */
    index(1, 2, 7), /*   7 :  3 */

    index(3, 0, 7), /*   8 :  3 */
    index(0, 3, 7), /*   9 :  3 */

    index(2, 2, 7), /*  10 :  4 */

    index(3, 1, 7), /*  11 :  4 */
    index(1, 3, 7), /*  12 :  4 */

    index(4, 0, 7), /*  13 :  4 */
    index(0, 4, 7), /*  14 :  4 */

    index(3, 2, 7), /*  15 :  5 */
    index(2, 3, 7), /*  16 :  5 */

    index(4, 1, 7), /*  17 :  5 */
    index(1, 4, 7), /*  18 :  5 */

    index(5, 0, 7), /*  19 :  5 */
    index(0, 5, 7), /*  20 :  5 */

    index(3, 3, 7), /*  21 :  6 */

    index(4, 2, 7), /*  22 :  6 */
    index(2, 4, 7), /*  23 :  6 */

    index(5, 1, 7), /*  24 :  6 */
    index(1, 5, 7), /*  25 :  6 */

    index(6, 0, 7), /*  26 :  6 */
    index(0, 6, 7), /*  27 :  6 */

    index(4, 3, 7), /*  28 :  7 */
    index(3, 4, 7), /*  29 :  7 */

    index(5, 2, 7), /*  30 :  7 */
    index(2, 5, 7), /*  31 :  7 */

    index(6, 1, 7), /*  32 :  7 */
    index(1, 6, 7), /*  33 :  7 */

    index(4, 4, 7), /*  34 :  8 */

    index(3, 5, 7), /*  35 :  8 */
    index(5, 3, 7), /*  36 :  8 */

    index(2, 6, 7), /*  37 :  8 */
    index(6, 2, 7), /*  38 :  8 */

    index(4, 5, 7), /*  39 :  9 */
    index(5, 4, 7), /*  40 :  9 */

    index(3, 6, 7), /*  41 :  9 */
    index(6, 3, 7), /*  42 :  9 */

    index(5, 5, 7), /*  43 : 10 */

    index(4, 6, 7), /*  44 : 10 */
    index(6, 4, 7), /*  45 : 10 */

    index(5, 6, 7), /*  46 : 11 */
    index(6, 5, 7), /*  47 : 11 */

    index(6, 6, 7), /*  48 : 12 */
  },
  { /* order 7 */
    index(0, 0, 8), /*   0 :  0 */

    index(1, 0, 8), /*   1 :  1 */
    index(0, 1, 8), /*   2 :  1 */

    index(1, 1, 8), /*   3 :  2 */

    index(2, 0, 8), /*   4 :  2 */
    index(0, 2, 8), /*   5 :  2 */

    index(2, 1, 8), /*   6 :  3 */
    index(1, 2, 8), /*   7 :  3 */

    index(3, 0, 8), /*   8 :  3 */
    index(0, 3, 8), /*   9 :  3 */

    index(2, 2, 8), /*  10 :  4 */

    index(3, 1, 8), /*  11 :  4 */
    index(1, 3, 8), /*  12 :  4 */

    index(4, 0, 8), /*  13 :  4 */
    index(0, 4, 8), /*  14 :  4 */

    index(3, 2, 8), /*  15 :  5 */
    index(2, 3, 8), /*  16 :  5 */

    index(4, 1, 8), /*  17 :  5 */
    index(1, 4, 8), /*  18 :  5 */

    index(5, 0, 8), /*  19 :  5 */
    index(0, 5, 8), /*  20 :  5 */

    index(3, 3, 8), /*  21 :  6 */

    index(4, 2, 8), /*  22 :  6 */
    index(2, 4, 8), /*  23 :  6 */

    index(5, 1, 8), /*  24 :  6 */
    index(1, 5, 8), /*  25 :  6 */

    index(6, 0, 8), /*  26 :  6 */
    index(0, 6, 8), /*  27 :  6 */

    index(4, 3, 8), /*  28 :  7 */
    index(3, 4, 8), /*  29 :  7 */

    index(5, 2, 8), /*  30 :  7 */
    index(2, 5, 8), /*  31 :  7 */

    index(6, 1, 8), /*  32 :  7 */
    index(1, 6, 8), /*  33 :  7 */

    index(7, 0, 8), /*  34 :  7 */
    index(0, 7, 8), /*  35 :  7 */

    index(4, 4, 8), /*  36 :  8 */

    index(3, 5, 8), /*  37 :  8 */
    index(5, 3, 8), /*  38 :  8 */

    index(2, 6, 8), /*  39 :  8 */
    index(6, 2, 8), /*  40 :  8 */

    index(1, 7, 8), /*  41 :  8 */
    index(7, 1, 8), /*  42 :  8 */

    index(4, 5, 8), /*  43 :  9 */
    index(5, 4, 8), /*  44 :  9 */

    index(3, 6, 8), /*  45 :  9 */
    index(6, 3, 8), /*  46 :  9 */

    index(2, 7, 8), /*  47 :  9 */
    index(7, 2, 8), /*  48 :  9 */

    index(5, 5, 8), /*  49 : 10 */

    index(4, 6, 8), /*  50 : 10 */
    index(6, 4, 8), /*  51 : 10 */

    index(3, 7, 8), /*  52 : 10 */
    index(7, 3, 8), /*  53 : 10 */

    index(5, 6, 8), /*  54 : 11 */
    index(6, 5, 8), /*  55 : 11 */

    index(4, 7, 8), /*  56 : 11 */
    index(7, 4, 8), /*  57 : 11 */

    index(6, 6, 8), /*  58 : 12 */

    index(5, 7, 8), /*  59 : 12 */
    index(7, 5, 8), /*  60 : 12 */

    index(6, 7, 8), /*  61 : 13 */
    index(7, 6, 8), /*  62 : 13 */

    index(7, 7, 8), /*  63 : 14 */
  },
};

#undef index
