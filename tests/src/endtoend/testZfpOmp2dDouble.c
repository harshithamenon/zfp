#include "src/encode2d.c"

#include "constants/2dDouble.h"
#include "utils/hash64.h"
#include "ompExecBase.c"

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(when_seededRandomSmoothDataGenerated_expect_ChecksumMatches),

    /* strided tests */
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed0Thread2Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed1Thread2Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleReversedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupReversed2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted0Thread2Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted1Thread2Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved0Thread2Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved1Thread2Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved2Thread2Chunk, teardown),

    /* fixed-precision */
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0Param2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1Param2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2Param2Thread2Chunk, teardown),

    /* fixed-rate */
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0Param2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1Param2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2Param2Thread2Chunk, teardown),

    /* fixed-accuracy */
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0Param2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1Param2Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param0Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param0Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param0Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param1Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param1Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param1Thread2Chunk, teardown),

    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param2Thread0Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param2Thread1Chunk, teardown),
    cmocka_unit_test_setup_teardown(given_OpenMP_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2Param2Thread2Chunk, teardown),
  };

  return cmocka_run_group_tests(tests, setupRandomData, teardownRandomData);
}
