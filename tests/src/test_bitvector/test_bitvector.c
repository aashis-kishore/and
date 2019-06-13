#include <check.h>
#include <stdint.h>
#include "bitvector.h"
#include "and.h"


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


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(bv_create_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}