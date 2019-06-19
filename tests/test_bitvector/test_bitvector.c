#include <check.h>
#include <stdint.h>
#include "bitvector.h"


// ================================================================================================== [bv_create(size_t, uint8_t, uint8_t, AND_BOOL)]
// test: bv_create(0, 0, 0, AND_FALSE)
START_TEST(test_bv_create__args__0__0__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);
    
    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 0, 0, AND_TRUE)
START_TEST(test_bv_create__args__0__0__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 0, 50, AND_FALSE)
START_TEST(test_bv_create__args__0__0__50__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 0, 50, AND_FALSE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 0, 50, AND_TRUE)
START_TEST(test_bv_create__args__0__0__50__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 0, 50, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 150, 0, AND_FALSE)
START_TEST(test_bv_create__args__0__150__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 150, 0, AND_FALSE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 150, 0, AND_TRUE)
START_TEST(test_bv_create__args__0__150__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 150, 0, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 150, 50, AND_FALSE)
START_TEST(test_bv_create__args__0__150__50__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 150, 50, AND_FALSE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 150, 50, AND_TRUE)
START_TEST(test_bv_create__args__0__150__50__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 150, 50, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 0, 0, AND_FALSE)
START_TEST(test_bv_create__args__128__0__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 0, 0, AND_FALSE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 0, 0, AND_TRUE)
START_TEST(test_bv_create__args__128__0__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 0, 0, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 0, 50, AND_FALSE)
START_TEST(test_bv_create__args__128__0__50__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 0, 50, AND_FALSE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 0, 50, AND_TRUE)
START_TEST(test_bv_create__args__128__0__50__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 0, 50, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 150, 0, AND_FALSE)
START_TEST(test_bv_create__args__128__150__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 150, 0, AND_FALSE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 150, 0, AND_TRUE)
START_TEST(test_bv_create__args__128__150__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 150, 0, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 150, 50, AND_FALSE)
START_TEST(test_bv_create__args__128__150__50__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 150, 50, AND_FALSE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(128, 150, 50, AND_TRUE)
START_TEST(test_bv_create__args__128__150__50__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 150, 50, AND_TRUE);

    ck_assert_ptr_nonnull(bv);
    bv_destroy(bv);
} END_TEST

// test: bv_create(0, 0, 24, AND_FALSE)
START_TEST(test_bv_create__args__0__0__24__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 0, 24, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 0, 24, AND_TRUE)
START_TEST(test_bv_create__args__0__0__24__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 0, 24, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 124, 0, AND_FALSE)
START_TEST(test_bv_create__args__0__124__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 124, 0, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 124, 0, AND_TRUE)
START_TEST(test_bv_create__args__0__124__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 124, 0, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 0, 101, AND_FALSE)
START_TEST(test_bv_create__args__0__0__101__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 0, 101, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 0, 101, AND_TRUE)
START_TEST(test_bv_create__args__0__0__101__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 0, 101, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 201, 0, AND_FALSE)
START_TEST(test_bv_create__args__0__201__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 201, 0, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 201, 0, AND_TRUE)
START_TEST(test_bv_create__args__0__201__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 201, 0, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 124, 24, AND_FALSE)
START_TEST(test_bv_create__args__0__124__24__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 124, 24, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 124, 24, AND_TRUE)
START_TEST(test_bv_create__args__0__124__24__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 124, 24, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 201, 101, AND_FALSE)
START_TEST(test_bv_create__args__0__201__101__AND_FALSE) {
    bitvectorptr_t bv = bv_create(0, 201, 101, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(0, 201, 101, AND_TRUE)
START_TEST(test_bv_create__args__0__201__101__AND_TRUE) {
    bitvectorptr_t bv = bv_create(0, 201, 101, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST


// test: bv_create(128, 0, 24, AND_FALSE)
START_TEST(test_bv_create__args__128__0__24__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 0, 24, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 0, 24, AND_TRUE)
START_TEST(test_bv_create__args__128__0__24__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 0, 24, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 124, 0, AND_FALSE)
START_TEST(test_bv_create__args__128__124__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 124, 0, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 124, 0, AND_TRUE)
START_TEST(test_bv_create__args__128__124__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 124, 0, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 0, 101, AND_FALSE)
START_TEST(test_bv_create__args__128__0__101__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 0, 101, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 0, 101, AND_TRUE)
START_TEST(test_bv_create__args__128__0__101__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 0, 101, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 201, 0, AND_FALSE)
START_TEST(test_bv_create__args__128__201__0__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 201, 0, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 201, 0, AND_TRUE)
START_TEST(test_bv_create__args__128__201__0__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 201, 0, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 124, 24, AND_FALSE)
START_TEST(test_bv_create__args__128__124__24__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 124, 24, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 124, 24, AND_TRUE)
START_TEST(test_bv_create__args__128__124__24__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 124, 24, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 201, 101, AND_FALSE)
START_TEST(test_bv_create__args__128__201__101__AND_FALSE) {
    bitvectorptr_t bv = bv_create(128, 201, 101, AND_FALSE);

    ck_assert_ptr_null(bv);
} END_TEST

// test: bv_create(128, 201, 101, AND_TRUE)
START_TEST(test_bv_create__args__128__201__101__AND_TRUE) {
    bitvectorptr_t bv = bv_create(128, 201, 101, AND_TRUE);

    ck_assert_ptr_null(bv);
} END_TEST


Suite* bv_create_suite(void) {
    Suite* suite;

    TCase *tc_failure, *tc_success;

    suite = suite_create("Create");

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_create__args__0__0__0__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__0__0__0__AND_TRUE);
    tcase_add_test(tc_success, test_bv_create__args__0__0__50__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__0__0__50__AND_TRUE);
    tcase_add_test(tc_success, test_bv_create__args__0__150__0__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__0__150__0__AND_TRUE);
    tcase_add_test(tc_success, test_bv_create__args__0__150__50__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__0__150__50__AND_TRUE);
    tcase_add_test(tc_success, test_bv_create__args__128__0__0__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__128__0__0__AND_TRUE);
    tcase_add_test(tc_success, test_bv_create__args__128__0__50__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__128__0__50__AND_TRUE);
    tcase_add_test(tc_success, test_bv_create__args__128__150__0__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__128__150__0__AND_TRUE);
    tcase_add_test(tc_success, test_bv_create__args__128__150__50__AND_FALSE);
    tcase_add_test(tc_success, test_bv_create__args__128__150__50__AND_TRUE);
    
    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_create__args__0__0__24__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__0__0__24__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__0__124__0__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__0__124__0__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__0__0__101__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__0__0__101__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__0__201__0__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__0__201__0__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__0__124__24__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__0__124__24__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__0__201__101__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__0__201__101__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__128__0__24__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__128__0__24__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__128__124__0__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__128__124__0__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__128__0__101__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__128__0__101__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__128__201__0__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__128__201__0__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__128__124__24__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__128__124__24__AND_TRUE);
    tcase_add_test(tc_failure, test_bv_create__args__128__201__101__AND_FALSE);
    tcase_add_test(tc_failure, test_bv_create__args__128__201__101__AND_TRUE);
    
    suite_add_tcase(suite, tc_success);
    suite_add_tcase(suite, tc_failure);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_getVectorSize(bitvectorptr_t, int8_t*)]
// test: bv_getVectorSize(NULL, NULL)
START_TEST(test_bv_getVectorSize__args__NULL__NULL) {
    size_t vector_size = bv_getVectorSize(NULL, NULL);
    ck_assert_int_eq(vector_size, 0);
} END_TEST

// test: bv_getVectorSize(NULL, stat)
START_TEST(test_bv_getVectorSize__args__NULL__stat) {
    int8_t get_vector_size_stat;
    bv_getVectorSize(NULL, &get_vector_size_stat);
    ck_assert_int_eq(get_vector_size_stat, AND_NOK);
} END_TEST

// test: bv_getVectorSize(bv, NULL)
START_TEST(test_bv_getVectorSize__args__bv__NULL) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    size_t vector_size = bv_getVectorSize(bv, NULL);
    ck_assert_int_eq(vector_size, 8);
    bv_destroy(bv);
} END_TEST

// test: bv_getVectorSize(bv, stat)
START_TEST(test_bv_getVectorSize__args__bv__stat) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);
    int8_t get_vector_size_stat = AND_NOK;

    size_t vector_size = bv_getVectorSize(bv, &get_vector_size_stat);
    ck_assert_int_eq(get_vector_size_stat, AND_OK);
    ck_assert_int_eq(vector_size, 8);
    bv_destroy(bv);
} END_TEST

// test: bv_getVectorSize(bv, stat) -- POST RESIZE
START_TEST(test_bv_getVectorSize__args__bv__stat__POST_RESIZE) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);
    int8_t get_vector_size_stat = AND_NOK;

    bv_setBit(bv, 256);

    size_t vector_size = bv_getVectorSize(bv, &get_vector_size_stat);
    ck_assert_int_eq(get_vector_size_stat, AND_OK);
    ck_assert_int_eq(vector_size, 12);
    bv_destroy(bv);
} END_TEST


Suite* bv_getVectorSize_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetVectorSize");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_getVectorSize__args__NULL__NULL);
    tcase_add_test(tc_failure, test_bv_getVectorSize__args__NULL__stat);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_getVectorSize__args__bv__NULL);
    tcase_add_test(tc_success, test_bv_getVectorSize__args__bv__stat);
    tcase_add_test(tc_success, test_bv_getVectorSize__args__bv__stat__POST_RESIZE);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_getNumBitsSet(bitvectorptr_t, size_t)]
// test: bv_getNumBitsSet(NULL, NULL)
START_TEST(test_bv_getNumBitsSet__args__NULL__NULL) {
    ck_assert_int_eq(bv_getNumBitsSet(NULL, NULL), 0);
} END_TEST

// testL bv_getNumBitsSet(bv, NULL)
START_TEST(test_bv_getNumBitsSet__args__bv__NULL) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 12);
    bv_setBit(bv, 12);
    bv_setBit(bv, 255);
    bv_setBit(bv, 179);

    ck_assert_int_eq(bv_getNumBitsSet(bv, NULL), 3);
    bv_destroy(bv);
} END_TEST

// test: bv_getNumBitsSet(bv, stat)
START_TEST(test_bv_getNumBitsSet__args__bv__stat) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 19);
    bv_setBit(bv, 205);
    bv_setBit(bv, 205);
    bv_setBit(bv, 19);
    bv_setBit(bv, 5);
    bv_setBit(bv, 190);

    int8_t get_num_bits_set_stat = AND_NOK;
    size_t num_bits_set = bv_getNumBitsSet(bv, &get_num_bits_set_stat);
    ck_assert_int_eq(num_bits_set, 4);
    ck_assert_int_eq(get_num_bits_set_stat, AND_OK);
    bv_destroy(bv);
} END_TEST

// test: bv_getNumBitsSet(bv, stat) -- POST RESIZE
START_TEST(test_bv_getNumBitsSet__args__bv__stat__POST_SETBIT_RESIZE) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 19);
    bv_setBit(bv, 5);
    bv_setBit(bv, 205);
    bv_setBit(bv, 189);
    bv_setBit(bv, 5);
    bv_setBit(bv, 190);
    bv_setBit(bv, 256);
    bv_setBit(bv, 289);

    int8_t get_num_bits_set_stat = AND_NOK;
    size_t num_bits_set = bv_getNumBitsSet(bv, &get_num_bits_set_stat);
    ck_assert_int_eq(num_bits_set, 7);
    ck_assert_int_eq(get_num_bits_set_stat, AND_OK);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);
    bv_destroy(bv);
} END_TEST


Suite* bv_getNumBitsSet_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetNumBitsSet");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_getNumBitsSet__args__NULL__NULL);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_getNumBitsSet__args__bv__NULL);
    tcase_add_test(tc_success, test_bv_getNumBitsSet__args__bv__stat);
    tcase_add_test(tc_success, test_bv_getNumBitsSet__args__bv__stat__POST_SETBIT_RESIZE);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_isBitSet(bitvectorptr_t, size_t)]
// test: bv_isBitSet(NULL, 3)
START_TEST(test_bv_isBitSet__args__NULL__3) {
    ck_assert_int_eq(bv_isBitSet(NULL, 3), AND_NOK);
} END_TEST

// test: bv_isBitSet(NULL, 18)
START_TEST(test_bv_isBitSet__args__NULL__18) {
    ck_assert_int_eq(bv_isBitSet(NULL, 18), AND_NOK);
} END_TEST

// test: bv_isBitSet(bv, 6)
START_TEST(test_bv_isBitSet__args__bv__6) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 5);

    ck_assert_int_eq(bv_isBitSet(bv, 6), AND_FALSE);
    bv_destroy(bv);
} END_TEST

// test: bv_isBitSet(bv, 73)
START_TEST(test_bv_isBitSet__args__bv__73) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 73);

    ck_assert_int_eq(bv_isBitSet(bv, 73), AND_TRUE);
    bv_destroy(bv);
} END_TEST


Suite* bv_isBitSet_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("IsBitSet");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_isBitSet__args__NULL__3);
    tcase_add_test(tc_failure, test_bv_isBitSet__args__NULL__18);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_isBitSet__args__bv__6);
    tcase_add_test(tc_success, test_bv_isBitSet__args__bv__73);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_isBitClear(bitvectorptr_t, size_t)]
// test: bv_isBitClear(NULL, 8)
START_TEST(test_bv_isBitClear__args__NULL__8) {
    ck_assert_int_eq(bv_isBitClear(NULL, 8), AND_NOK);
} END_TEST

// test: bv_isBitClear(NULL, 80)
START_TEST(test_bv_isBitClear__args__NULL__80) {
    ck_assert_int_eq(bv_isBitClear(NULL, 80), AND_NOK);
} END_TEST

// test: bv_isBitClear(bv, 12)
START_TEST(test_bv_isBitClear__args__bv__12) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_isBitClear(bv, 12), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_isBitClear(bv, 289)
START_TEST(test_bv_isBitClear__args__bv__289) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 500);

    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 18);
    ck_assert_int_eq(bv_isBitClear(bv, 500), AND_FALSE);
    bv_destroy(bv);
} END_TEST


Suite* bv_isBitClear_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("IsBitClear");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_isBitClear__args__NULL__8);
    tcase_add_test(tc_failure, test_bv_isBitClear__args__NULL__80);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_isBitClear__args__bv__12);
    tcase_add_test(tc_success, test_bv_isBitClear__args__bv__289);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_numBitsSetInRange(bitvectorptr_t, size_t, size_t, int8_t*)]
// test: bv_numBitsSetInRange(NULL, 45, 90, NULL)
START_TEST(test_bv_numBitsSetInRange__args__NULL__45__90__NULL) {
    ck_assert_int_eq(bv_numBitsSetInRange(NULL, 45, 90, NULL), AND_ZERO);
} END_TEST

// test: bv_numBitsSetInRange(NULL, 45, 90, stat)
START_TEST(test_bv_numBitsSetInRange__args__NULL__45__90__stat) {
    int8_t num_bits_set_in_range_stat = AND_NOK;
    ck_assert_int_eq(bv_numBitsSetInRange(NULL, 45, 90, &num_bits_set_in_range_stat), AND_ZERO);
} END_TEST

// test: bv_numBitsSetInRange(bv, 167, 167, NULL)
START_TEST(test_bv_numBitsSetInRange__args__bv__167__167__NULL) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 167);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 167, 167, NULL);

    ck_assert_int_eq(num_bits_set_in_range, AND_ZERO);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 167, 167, stat)
START_TEST(test_bv_numBitsSetInRange__args__bv__167__167__stat) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 167);

    int8_t num_bits_set_in_range_stat = AND_OK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 167, 167, &num_bits_set_in_range_stat);

    ck_assert_int_eq(num_bits_set_in_range_stat, AND_NOK);
    ck_assert_int_eq(num_bits_set_in_range, AND_ZERO);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 255, 200, NULL)
START_TEST(test_bv_numBitsSetInRange__args__bv__255__200__NULL) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 255);
    bv_setBit(bv, 200);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 255, 200, NULL);

    ck_assert_int_eq(num_bits_set_in_range, AND_ZERO);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 255, 200, stat)
START_TEST(test_bv_numBitsSetInRange__args__bv__255__200__stat) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 255);
    bv_setBit(bv, 200);

    int8_t num_bits_set_in_range_stat = AND_OK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 255, 200, &num_bits_set_in_range_stat);

    ck_assert_int_eq(num_bits_set_in_range_stat, AND_NOK);
    ck_assert_int_eq(num_bits_set_in_range, AND_ZERO);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 0, 300, NULL)
START_TEST(test_bv_numBitsSetInRange__args__bv__0__300__NULL) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 0);
    bv_setBit(bv, 300);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 300, NULL);

    ck_assert_int_eq(num_bits_set_in_range, AND_ZERO);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 0, 300, stat)
START_TEST(test_bv_numBitsSetInRange__args__bv__0__300__stat) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 0);
    bv_setBit(bv, 300);

    int8_t num_bits_set_in_range_stat = AND_OK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 300, &num_bits_set_in_range_stat);

    ck_assert_int_eq(num_bits_set_in_range_stat, AND_NOK);
    ck_assert_int_eq(num_bits_set_in_range, AND_ZERO);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 129, 190, NULL) -- STATIC
START_TEST(test_bv_numBitsSetInRange__args__bv__129__190__NULL__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 129);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 129, 190, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 129), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 3);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 129, 190, NULL) -- DYNAMIC
START_TEST(test_bv_numBitsSetInRange__args__bv__129__190__NULL__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 129);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 129, 190, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 129), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 3);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 129, 190, stat) -- STATIC
START_TEST(test_bv_numBitsSetInRange__args__bv__129__190__stat__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 129);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);

    int8_t num_bits_set_in_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 129, 190, &num_bits_set_in_range_stat);

    ck_assert_int_eq(bv_isBitSet(bv, 129), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 3);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 129, 190, stat) -- DYNAMIC
START_TEST(test_bv_numBitsSetInRange__args__bv__129__190__stat__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 129);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);

    int8_t num_bits_set_in_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 129, 190, &num_bits_set_in_range_stat);

    ck_assert_int_eq(bv_isBitSet(bv, 129), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 3);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 0, 255, NULL) -- STATIC
START_TEST(test_bv_numBitsSetInRange__args__bv__0__255__NULL__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 0);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 8);
    bv_setBit(bv, 232);
    bv_setBit(bv, 0);
    bv_setBit(bv, 255);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 255, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 0), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 232), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 255), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 6);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 0, 255, NULL) -- DYNAMIC
START_TEST(test_bv_numBitsSetInRange__args__bv__0__255__NULL__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 0);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 8);
    bv_setBit(bv, 232);
    bv_setBit(bv, 0);
    bv_setBit(bv, 255);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 255, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 0), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 232), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 255), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 6);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 0, 255, stat) -- STATIC
START_TEST(test_bv_numBitsSetInRange__args__bv__0__255__stat__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 0);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 8);
    bv_setBit(bv, 232);
    bv_setBit(bv, 0);
    bv_setBit(bv, 255);

    int8_t num_bits_set_in_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 255, &num_bits_set_in_range_stat);

    ck_assert_int_eq(bv_isBitSet(bv, 0), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 232), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 255), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 6);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 0, 255, stat) -- DYNAMIC
START_TEST(test_bv_numBitsSetInRange__args__bv__0__255__stat__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 0);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 8);
    bv_setBit(bv, 232);
    bv_setBit(bv, 0);
    bv_setBit(bv, 255);

    int8_t num_bits_set_in_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 255, &num_bits_set_in_range_stat);

    ck_assert_int_eq(bv_isBitSet(bv, 0), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 232), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 255), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 6);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 128, 200, NULL) -- STATIC
START_TEST(test_bv_numBitsSetInRange__args__bv__128__200__NULL__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 128);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 8);
    bv_setBit(bv, 201);
    bv_setBit(bv, 0);
    bv_setBit(bv, 200);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 128, 200, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 128), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 201), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 0), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 200), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 4);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 8);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 128, 200, NULL) -- DYNAMIC
START_TEST(test_bv_numBitsSetInRange__args__bv__128__200__NULL__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 128);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 8);
    bv_setBit(bv, 201);
    bv_setBit(bv, 0);
    bv_setBit(bv, 200);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 128, 200, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 128), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 201), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 0), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 200), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 4);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 8);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 129, 200, stat) -- STATIC
START_TEST(test_bv_numBitsSetInRange__args__bv__129__200__stat__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 128);
    bv_setBit(bv, 129);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 201);
    bv_setBit(bv, 200);

    int8_t num_bits_set_in_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 129, 200, &num_bits_set_in_range_stat);

    ck_assert_int_eq(bv_isBitSet(bv, 128), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 129), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 201), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 200), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 4);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 8);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 129, 200, stat) -- DYNAMIC
START_TEST(test_bv_numBitsSetInRange__args__bv__129__200__stat_DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 128);
    bv_setBit(bv, 129);
    bv_setBit(bv, 145);
    bv_setBit(bv, 190);
    bv_setBit(bv, 201);
    bv_setBit(bv, 200);

    int8_t num_bits_set_in_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 129, 200, &num_bits_set_in_range_stat);

    ck_assert_int_eq(bv_isBitSet(bv, 128), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 129), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 145), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 190), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 201), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 200), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 4);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 8);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 4, 28, NULL) -- STATIC
START_TEST(test_bv_numBitsSetInRange__args__bv__4__28__NULL__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 3);
    bv_setBit(bv, 8);
    bv_setBit(bv, 14);
    bv_setBit(bv, 19);
    bv_setBit(bv, 29);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 4, 28, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 3), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 14), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 19), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 29), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 3);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 8);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsSetInRange(bv, 257, 285, NULL) -- DYNAMIC
START_TEST(test_bv_numBitsSetInRange__args__bv__257__285__NULL__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 256);
    bv_setBit(bv, 278);
    bv_setBit(bv, 263);
    bv_setBit(bv, 287);
    bv_setBit(bv, 285);

    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 257, 285, NULL);

    ck_assert_int_eq(bv_isBitSet(bv, 256), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 278), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 263), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 287), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 285), AND_TRUE);
    ck_assert_int_eq(num_bits_set_in_range, 3);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);

    bv_destroy(bv);
} END_TEST


Suite* bv_numBitsSetInRange_suite(void) {
    Suite* suite = suite_create("NumBitsSetInRange");
    TCase *tc_failure, *tc_success;

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__NULL__45__90__NULL);
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__NULL__45__90__stat);
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__bv__167__167__NULL);
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__bv__167__167__stat);
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__bv__255__200__NULL);
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__bv__255__200__stat);
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__bv__0__300__NULL);
    tcase_add_test(tc_failure, test_bv_numBitsSetInRange__args__bv__0__300__stat);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__129__190__NULL__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__129__190__NULL__DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__129__190__stat__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__129__190__stat__DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__0__255__NULL__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__0__255__NULL__DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__0__255__stat__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__0__255__stat__DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__128__200__NULL__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__128__200__NULL__DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__129__200__stat__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__129__200__stat_DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__4__28__NULL__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsSetInRange__args__bv__257__285__NULL__DYNAMIC);
    
    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}
// ==================================================================================================


// ================================================================================================== [bv_numBitsClearInRange(bitvectorptr_t, size_t, size_t, int8_t*)]
// test: bv_numBitsClearInRange(NULL, 5, 90, NULL)
START_TEST(test_bv_numBitsClearInRange__args__NULL__5__90__NULL) {
    ck_assert_int_eq(bv_numBitsClearInRange(NULL, 5, 90, NULL), 0);
} END_TEST

// test: bv_numBitsClearInRange(NULL, 9, 120, stat)
START_TEST(test_bv_numBitsClearInRange__args__NULL__9__120__stat) {
    int8_t num_bits_clear_in_range_stat;
    bv_numBitsClearInRange(NULL, 9, 120, &num_bits_clear_in_range_stat);
    ck_assert_int_eq(num_bits_clear_in_range_stat, AND_NOK);
} END_TEST

// test: bv_numBitsClearInRange(bv, 5, 5, NULL) -- STATIC
START_TEST(test_bv_numBitsClearInRange__args__bv__5__5__NULL__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);
    
    ck_assert_int_eq(bv_numBitsClearInRange(bv, 5, 5, NULL), 0);
    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 5, 5, NULL) -- DYNAMIC
START_TEST(test_bv_numBitsClearInRange__args__bv__5__5__NULL__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_numBitsClearInRange(bv, 5, 5, NULL), 0);
    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 50, 25, NULL) -- STATIC
START_TEST(test_bv_numBitsClearInRange__args__bv__50__25__NULL__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_numBitsClearInRange(bv, 50, 25, NULL), 0);
    bv_destroy(bv);  
} END_TEST

// test: bv_numBitsClearInRange(bv, 50, 25, NULL) -- DYNAMIC
START_TEST(test_bv_numBitsClearInRange__args__bv__50__25__NULL__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_numBitsClearInRange(bv, 50, 25, NULL), 0);
    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 33, 78, NULL) -- STATIC
START_TEST(test_bv_numBitsClearInRange__args__bv__33__78__NULL__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 32);
    bv_setBit(bv, 33);
    bv_setBit(bv, 78);
    bv_setBit(bv, 45);
    bv_setBit(bv, 79);

    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 33, 78, NULL);
    ck_assert_int_eq(bv_isBitSet(bv, 32), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 33), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 78), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 45), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 79), AND_TRUE);
    ck_assert_int_eq(num_bits_clear_in_range, 43);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 5, 26, NULL) -- DYNAMIC
START_TEST(test_bv_numBitsClearInRange__args__bv__5__26__NULL__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 8);
    bv_setBit(bv, 3);
    bv_setBit(bv, 4);
    bv_setBit(bv, 10);
    bv_setBit(bv, 12);
    bv_setBit(bv, 28);
    bv_setBit(bv, 29);

    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 5, 26, NULL);
    ck_assert_int_eq(bv_isBitSet(bv, 8), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 3), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 4), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 10), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 12), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 28), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 29), AND_TRUE);
    ck_assert_int_eq(num_bits_clear_in_range, 19);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 0, 255, stat) -- STATIC
START_TEST(test_bv_numBitsClearInRange__args__bv__0__255__stat__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 18);
    bv_setBit(bv, 79);
    bv_setBit(bv, 155);
    bv_setBit(bv, 15);

    int8_t num_bit_clear_in_range_stat = AND_NOK;
    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 0, 255, &num_bit_clear_in_range_stat);
    ck_assert_int_eq(bv_isBitSet(bv, 18), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 79), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 155), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 15), AND_TRUE);
    ck_assert_int_eq(num_bit_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range, 252);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 0, 255, stat) -- DYNAMIC
START_TEST(test_bv_numBitsClearInRange__args__bv__0__255__stat__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 18);
    bv_setBit(bv, 79);
    bv_setBit(bv, 155);
    bv_setBit(bv, 15);

    int8_t num_bit_clear_in_range_stat = AND_NOK;
    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 0, 255, &num_bit_clear_in_range_stat);
    ck_assert_int_eq(bv_isBitSet(bv, 18), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 79), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 155), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 15), AND_TRUE);
    ck_assert_int_eq(num_bit_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range, 252);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 0, 289, stat) -- STATIC
START_TEST(test_bv_numBitsClearInRange__args__bv__0__289__stat__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t num_bit_clear_in_range_stat = AND_OK;
    bv_numBitsClearInRange(bv, 0, 289, &num_bit_clear_in_range_stat);
    ck_assert_int_eq(num_bit_clear_in_range_stat, AND_NOK);

    bv_destroy(bv);
} END_TEST

// test: bv_numBitsClearInRange(bv, 267, 300, stat) -- DYNAMIC
START_TEST(test_bv_numBitsClearInRange__args__bv__267__300__stat__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 278);
    bv_setBit(bv, 261);
    bv_setBit(bv, 256);
    bv_setBit(bv, 301);
    bv_setBit(bv, 299);

    int8_t num_bit_clear_in_range_stat = AND_NOK;
    bv_numBitsClearInRange(bv, 267, 300, &num_bit_clear_in_range_stat);
    ck_assert_int_eq(bv_isBitSet(bv, 278), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 261), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 256), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 301), AND_TRUE);
    ck_assert_int_eq(bv_isBitSet(bv, 299), AND_TRUE);
    ck_assert_int_eq(num_bit_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);

    bv_destroy(bv);
} END_TEST


Suite* bv_numBitsClearInRange_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("NumBitsClearInRange");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_numBitsClearInRange__args__NULL__5__90__NULL);
    tcase_add_test(tc_failure, test_bv_numBitsClearInRange__args__NULL__9__120__stat);
    tcase_add_test(tc_failure, test_bv_numBitsClearInRange__args__bv__5__5__NULL__STATIC);
    tcase_add_test(tc_failure, test_bv_numBitsClearInRange__args__bv__5__5__NULL__DYNAMIC);
    tcase_add_test(tc_failure, test_bv_numBitsClearInRange__args__bv__50__25__NULL__STATIC);
    tcase_add_test(tc_failure, test_bv_numBitsClearInRange__args__bv__50__25__NULL__DYNAMIC);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_numBitsClearInRange__args__bv__33__78__NULL__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsClearInRange__args__bv__5__26__NULL__DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsClearInRange__args__bv__0__255__stat__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsClearInRange__args__bv__0__255__stat__DYNAMIC);
    tcase_add_test(tc_success, test_bv_numBitsClearInRange__args__bv__0__289__stat__STATIC);
    tcase_add_test(tc_success, test_bv_numBitsClearInRange__args__bv__267__300__stat__DYNAMIC);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_setBit(bitvectorptr_t, size_t)]
// test: bv_setBit(NULL, 45)
START_TEST(test_bv_setBit__args__NULL__45) {
    ck_assert_int_eq(bv_setBit(NULL, 45), AND_NOK);
} END_TEST

// test: bv_setBit(bv, 67) -- STATIC
START_TEST(test_bv_setBit__args__bv__67__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t set_bit_stat = bv_setBit(bv, 67);

    ck_assert_int_eq(set_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitSet(bv, 67), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_setBit(bv, 67) -- DYNAMIC
START_TEST(test_bv_setBit__args__bv__67__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t set_bit_stat = bv_setBit(bv, 67);

    ck_assert_int_eq(set_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitSet(bv, 67), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_setBit(bv, 88) -- STATIC
START_TEST(test_bv_setBit__args__bv__88__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t set_bit_stat = bv_setBit(bv, 88);

    ck_assert_int_eq(set_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitSet(bv, 89), AND_FALSE);
    bv_destroy(bv);
} END_TEST

// test: bv_setBit(bv, 88) -- DYNAMIC
START_TEST(test_bv_setBit__args__bv__88__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t set_bit_stat = bv_setBit(bv, 88);

    ck_assert_int_eq(set_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitSet(bv, 89), AND_FALSE);
    bv_destroy(bv);
} END_TEST

// test: bv_setBit(bv, 23) -- STATIC
START_TEST(test_bv_setBit__args__bv__23__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t set_bit_stat = bv_setBit(bv, 23);

    ck_assert_int_eq(set_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitSet(bv, 22), AND_FALSE);
    bv_destroy(bv);
} END_TEST


// test: bv_setBit(bv, 23) -- DYNAMIC
START_TEST(test_bv_setBit__args__bv__23__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t set_bit_stat = bv_setBit(bv, 23);

    ck_assert_int_eq(set_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitSet(bv, 22), AND_FALSE);
    bv_destroy(bv);
} END_TEST

// test: bv_setBit(bv, 256) -- STATIC
START_TEST(test_bv_setBit__args__bv__256__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t set_bit_stat = bv_setBit(bv, 256);

    ck_assert_int_eq(set_bit_stat, AND_NOK);
    ck_assert_int_eq(bv_isBitSet(bv, 256), AND_FALSE);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 8);
    bv_destroy(bv);
} END_TEST

// test: bv_setBit(bv, 256) -- DYNAMIC
START_TEST(test_bv_setBit__args__bv__256__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t set_bit_stat = bv_setBit(bv, 256);

    ck_assert_int_eq(set_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitSet(bv, 256), AND_TRUE);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);
    bv_destroy(bv);
} END_TEST


Suite* bv_setBit_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("SetBit");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_setBit__args__NULL__45);
    tcase_add_test(tc_failure, test_bv_setBit__args__bv__256__STATIC);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_setBit__args__bv__67__STATIC);
    tcase_add_test(tc_success, test_bv_setBit__args__bv__67__DYNAMIC);
    tcase_add_test(tc_success, test_bv_setBit__args__bv__88__STATIC);
    tcase_add_test(tc_success, test_bv_setBit__args__bv__88__DYNAMIC);
    tcase_add_test(tc_success, test_bv_setBit__args__bv__23__STATIC);
    tcase_add_test(tc_success, test_bv_setBit__args__bv__23__DYNAMIC);
    tcase_add_test(tc_success, test_bv_setBit__args__bv__256__DYNAMIC);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_clearBit(bitvectorptr_t, size_t)]
// test: bv_clearBit(NULL, 56)
START_TEST(test_bv_clearBit__args__NULL__56) {
    ck_assert_int_eq(bv_clearBit(NULL, 56), AND_NOK);
} END_TEST

// test: bv_clearBit(bv, 129) -- STATIC
START_TEST(test_bv_clearBit__args__bv__129__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t clear_bit_stat = bv_clearBit(bv, 129);

    ck_assert_int_eq(clear_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitClear(bv, 129), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBit(bv, 129) -- DYNAMIC
START_TEST(test_bv_clearBit__args__bv__129__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t clear_bit_stat = bv_clearBit(bv, 129);

    ck_assert_int_eq(clear_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitClear(bv, 129), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBit(bv, 12) -- STATIC
START_TEST(test_bv_clearBit__args__bv__12__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 12);
    int8_t clear_bit_stat = bv_clearBit(bv, 12);

    ck_assert_int_eq(clear_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitClear(bv, 12), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBit(bv, 12) -- DYNAMIC
START_TEST(test_bv_clearBit__args__bv__12__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 12);
    int8_t clear_bit_stat = bv_clearBit(bv, 12);

    ck_assert_int_eq(clear_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitClear(bv, 12), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBit(bv, 255) -- STATIC
START_TEST(test_bv_clearBit__args__bv__255__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 254);
    int8_t clear_bit_stat = bv_clearBit(bv, 255);

    ck_assert_int_eq(clear_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitClear(bv, 255), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBit(bv, 255) -- DYNAMIC
START_TEST(test_bv_clearBit__args__bv__255__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 254);
    int8_t clear_bit_stat = bv_clearBit(bv, 255);

    ck_assert_int_eq(clear_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitClear(bv, 255), AND_TRUE);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBit(bv, 256) -- STATIC
START_TEST(test_bv_clearBit__args__bv__256__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    bv_setBit(bv, 256);
    int8_t clear_bit_stat = bv_clearBit(bv, 256);

    ck_assert_int_eq(clear_bit_stat, AND_NOK);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 8);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBit(bv, 256) -- DYNAMIC
START_TEST(test_bv_clearBit__args__bv__256__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    bv_setBit(bv, 256);
    int8_t clear_bit_stat = bv_clearBit(bv, 256);

    ck_assert_int_eq(clear_bit_stat, AND_OK);
    ck_assert_int_eq(bv_isBitClear(bv, 256), AND_TRUE);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);
    bv_destroy(bv);
} END_TEST


Suite* bv_clearBit_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("ClearBit");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_clearBit__args__NULL__56);
    tcase_add_test(tc_failure, test_bv_clearBit__args__bv__256__STATIC);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_clearBit__args__bv__129__STATIC);
    tcase_add_test(tc_success, test_bv_clearBit__args__bv__129__DYNAMIC);
    tcase_add_test(tc_success, test_bv_clearBit__args__bv__12__STATIC);
    tcase_add_test(tc_success, test_bv_clearBit__args__bv__12__DYNAMIC);
    tcase_add_test(tc_success, test_bv_clearBit__args__bv__255__STATIC);
    tcase_add_test(tc_success, test_bv_clearBit__args__bv__255__DYNAMIC);
    tcase_add_test(tc_success, test_bv_clearBit__args__bv__256__DYNAMIC);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [bv_setBitRange(bitvectorptr_t, size_t, size_t)]
// test: bv_setBitRange(NULL, 10, 12)
START_TEST(test_bv_setBitRange__args__NULL__10__12) {
    ck_assert_int_eq(bv_setBitRange(NULL, 10, 12), AND_NOK);
} END_TEST

// test: bv_setBitRange(bv, 26, 26)
START_TEST(test_bv_setBitRange__args__bv__26__26) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_setBitRange(bv, 26, 26), AND_NOK);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 4, 8) -- STATIC
START_TEST(test_bv_setBitRange__args__bv__4__8__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_setBitRange(bv, 4, 8), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 4, 8, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 5);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 4, 8) -- DYNAMIC
START_TEST(test_bv_setBitRange__args__bv__4__8__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_setBitRange(bv, 4, 8), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 4, 8, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 5);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 28, 34) -- STATIC
START_TEST(test_bv_setBitRange__args__bv__28__34__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_setBitRange(bv, 28, 34), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 28, 34, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 7);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 28, 34) -- DYNAMIC
START_TEST(test_bv_setBitRange__args__bv__28__34__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_setBitRange(bv, 28, 34), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 28, 34, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 7);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 28, 66) -- STATIC
START_TEST(test_bv_setBitRange__args__bv__28__66__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_setBitRange(bv, 28, 66), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 28, 66, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 39);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 28, 66) -- DYNAMIC
START_TEST(test_bv_setBitRange__args__bv__28__66__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_setBitRange(bv, 28, 66), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 28, 66, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 39);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 0, 255) -- STATIC
START_TEST(test_bv_setBitRange__args__bv__0__255__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_setBitRange(bv, 0, 255), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 255, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 256);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 0, 255) -- DYNAMIC
START_TEST(test_bv_setBitRange__args__bv__0__255__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_setBitRange(bv, 0, 255), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 255, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 256);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 0, 256) -- STATIC
START_TEST(test_bv_setBitRange__args__bv__0__256__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_setBitRange(bv, 0, 256), AND_NOK);
    int8_t num_bit_set_In_range_stat = AND_OK;
    bv_numBitsSetInRange(bv, 0, 256, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_NOK);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 0, 256) -- DYNAMIC
START_TEST(test_bv_setBitRange__args__bv__0__256__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_setBitRange(bv, 0, 256), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 0, 256, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 257);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 10, 256) -- STATIC
START_TEST(test_bv_setBitRange__args__bv__10__256__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_setBitRange(bv, 10, 256), AND_NOK);
    int8_t num_bit_set_In_range_stat = AND_OK;
    bv_numBitsSetInRange(bv, 10, 256, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_NOK);

    bv_destroy(bv);
} END_TEST

// test: bv_setBitRange(bv, 10, 256) -- DYNAMIC
START_TEST(test_bv_setBitRange__args__bv__10__256__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_setBitRange(bv, 10, 256), AND_OK);
    int8_t num_bit_set_In_range_stat = AND_NOK;
    size_t num_bits_set_in_range = bv_numBitsSetInRange(bv, 10, 256, &num_bit_set_In_range_stat);
    ck_assert_int_eq(num_bit_set_In_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_set_in_range, 247);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);

    bv_destroy(bv);
} END_TEST


Suite* bv_setBitRange_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("SetBitRange");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_setBitRange__args__NULL__10__12);
    tcase_add_test(tc_failure, test_bv_setBitRange__args__bv__26__26);
    tcase_add_test(tc_failure, test_bv_setBitRange__args__bv__0__256__STATIC);
    tcase_add_test(tc_failure, test_bv_setBitRange__args__bv__10__256__STATIC);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__4__8__STATIC);
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__4__8__DYNAMIC);
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__28__34__STATIC);
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__28__34__DYNAMIC);
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__28__66__STATIC);
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__28__66__DYNAMIC);
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__0__255__STATIC);
    tcase_add_test(tc_success, test_bv_setBitRange__args__bv__0__255__DYNAMIC);
    tcase_add_test(tc_failure, test_bv_setBitRange__args__bv__0__256__DYNAMIC);
    tcase_add_test(tc_failure, test_bv_setBitRange__args__bv__10__256__DYNAMIC);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}
// ==================================================================================================


// ================================================================================================== [bv_clearBitRange(bitvectorptr_t, size_t, size_t)]
// test: bv_clearBitRange(NULL, 10, 89)
START_TEST(test_bv_clearBitRange__args__NULL__10__89) {
    ck_assert_int_eq(bv_clearBitRange(NULL, 10, 89), AND_NOK);
} END_TEST

// test: bv_clearBitRange(bv, 67, 67) -- STATIC
START_TEST(test_bv_clearBitRange__args__bv__67__67__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    ck_assert_int_eq(bv_clearBitRange(bv, 67, 67), AND_NOK);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBitRange(bv, 67, 67) -- DYNAMIC
START_TEST(test_bv_clearBitRange__args__bv__67__67__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    ck_assert_int_eq(bv_clearBitRange(bv, 67, 67), AND_NOK);
    bv_destroy(bv);
} END_TEST

// test: bv_clearBitRange(bv, 10, 89) -- STATIC
START_TEST(test_bv_clearBitRange__args__bv__10__89__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t clear_bit_range_stat = bv_clearBitRange(bv, 10, 89);
    
    int8_t num_bits_clear_in_range_stat;
    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 10, 89, &num_bits_clear_in_range_stat);

    ck_assert_int_eq(clear_bit_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range, 89-10+1);

    bv_destroy(bv);
} END_TEST

// test: bv_clearBitRange(bv, 10, 89) -- DYNAMIC
START_TEST(test_bv_clearBitRange__args__bv__10__89__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t clear_bit_range_stat = bv_clearBitRange(bv, 10, 89);
    
    int8_t num_bits_clear_in_range_stat;
    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 10, 89, &num_bits_clear_in_range_stat);

    ck_assert_int_eq(clear_bit_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range, 89-10+1);

    bv_destroy(bv);
} END_TEST

// test: bv_clearBitRange(bv, 0, 255) -- STATIC
START_TEST(test_bv_clearBitRange__args__bv__0__255__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t clear_bit_range_stat = bv_clearBitRange(bv, 0, 255);
    
    int8_t num_bits_clear_in_range_stat;
    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 0, 255, &num_bits_clear_in_range_stat);

    ck_assert_int_eq(clear_bit_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range, 256);

    bv_destroy(bv);
} END_TEST

// test: bv_clearBitRange(bv, 0, 255) -- DYNAMIC
START_TEST(test_bv_clearBitRange__args__bv__0__255__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t clear_bit_range_stat = bv_clearBitRange(bv, 0, 255);
    
    int8_t num_bits_clear_in_range_stat;
    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 0, 255, &num_bits_clear_in_range_stat);

    ck_assert_int_eq(clear_bit_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range, 256);

    bv_destroy(bv);
} END_TEST

// test: bv_clearBitRange(bv, 78, 256) -- STATIC
START_TEST(test_bv_clearBitRange__args__bv__78__256__STATIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t clear_bit_range_stat = bv_clearBitRange(bv, 78, 256);
    
    int8_t num_bits_clear_in_range_stat;
    bv_numBitsClearInRange(bv, 78, 256, &num_bits_clear_in_range_stat);

    ck_assert_int_eq(clear_bit_range_stat, AND_NOK);
    ck_assert_int_eq(num_bits_clear_in_range_stat, AND_NOK);

    bv_destroy(bv);
} END_TEST

// test: bv_clearBitRange(bv, 78, 256) -- DYNAMIC
START_TEST(test_bv_clearBitRange__args__bv__78__256__DYNAMIC) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_TRUE);

    int8_t clear_bit_range_stat = bv_clearBitRange(bv, 78, 256);
    
    int8_t num_bits_clear_in_range_stat;
    size_t num_bits_clear_in_range = bv_numBitsClearInRange(bv, 78, 256, &num_bits_clear_in_range_stat);

    ck_assert_int_eq(clear_bit_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range_stat, AND_OK);
    ck_assert_int_eq(num_bits_clear_in_range, 256-78+1);
    ck_assert_int_eq(bv_getVectorSize(bv, NULL), 12);

    bv_destroy(bv);
} END_TEST


Suite* bv_clearBitRange_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("ClearBitRange");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_clearBitRange__args__NULL__10__89);
    tcase_add_test(tc_failure, test_bv_clearBitRange__args__bv__67__67__STATIC);
    tcase_add_test(tc_failure, test_bv_clearBitRange__args__bv__67__67__DYNAMIC);
    tcase_add_test(tc_failure, test_bv_clearBitRange__args__bv__78__256__STATIC);    

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_clearBitRange__args__bv__0__255__STATIC);            
    tcase_add_test(tc_success, test_bv_clearBitRange__args__bv__0__255__DYNAMIC);
    tcase_add_test(tc_success, test_bv_clearBitRange__args__bv__10__89__STATIC);
    tcase_add_test(tc_success, test_bv_clearBitRange__args__bv__10__89__DYNAMIC);    
    tcase_add_test(tc_success, test_bv_clearBitRange__args__bv__78__256__DYNAMIC);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}
// ==================================================================================================


// ================================================================================================== [bv_destroy(bitvectorptr_t)]
// test: bv_destroy(NULL)
START_TEST(test_bv_destroy__args__NULL) {
    int8_t destroy_stat = bv_destroy(NULL);

    ck_assert_int_eq(destroy_stat, AND_NOK);
} END_TEST

// test: bv_destroy(bv)
START_TEST(test_bv_destroy__args__bv) {
    bitvectorptr_t bv = bv_create(0, 0, 0, AND_FALSE);

    int8_t destroy_stat = bv_destroy(bv);
    ck_assert_int_eq(destroy_stat, AND_OK);
} END_TEST


Suite* bv_destroy_suite(void) {
    Suite *suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Destroy");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_bv_destroy__args__NULL);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_bv_destroy__args__bv);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(bv_create_suite());
    srunner_add_suite(suite_runner, bv_getVectorSize_suite());    
    srunner_add_suite(suite_runner, bv_getNumBitsSet_suite());
    srunner_add_suite(suite_runner, bv_isBitSet_suite());
    srunner_add_suite(suite_runner, bv_isBitClear_suite());
    srunner_add_suite(suite_runner, bv_numBitsSetInRange_suite());
    srunner_add_suite(suite_runner, bv_numBitsClearInRange_suite());
    srunner_add_suite(suite_runner, bv_setBit_suite());
    srunner_add_suite(suite_runner, bv_clearBit_suite());
    srunner_add_suite(suite_runner, bv_setBitRange_suite());
    srunner_add_suite(suite_runner, bv_clearBitRange_suite());
    srunner_add_suite(suite_runner, bv_destroy_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}