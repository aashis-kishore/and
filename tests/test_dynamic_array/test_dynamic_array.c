#include <check.h>
#include <stdint.h>
#include <string.h>
#include "darray.h"
#include "and.h"


// ================================================================================================== [da_create(size_t, size_t, uint8_t, uint8_t)]
// test: da_create(0, 0, 0, 0)
START_TEST(test_da_create__args__0__0__0__0) {
    ck_assert_ptr_null(da_create(0, 0, 0, 0));
} END_TEST

// test: da_create(0, sizeof(int), 124, 0)
START_TEST(test_da_create__args__0__sizeof_int__124__0) {
    ck_assert_ptr_null(da_create(0, sizeof(int), 124, 0));
} END_TEST

// test: da_create(0, sizeof(int), 201, 0)
START_TEST(test_da_create__args__0__sizeof_int__201__0) {
    ck_assert_ptr_null(da_create(0, sizeof(int), 201, 0));
} END_TEST

// test: da_create(0, sizeof(int), 0, 24)
START_TEST(test_da_create__args__0__sizeof_int__0__24) {
    ck_assert_ptr_null(da_create(0, sizeof(int), 0, 24));
} END_TEST

// test: da_create(0, sizeof(int), 0, 101)
START_TEST(test_da_create__args__0__sizeof_int__0__101) {
    ck_assert_ptr_null(da_create(0, sizeof(int), 0, 101));
} END_TEST

// test: da_create(0, sizeof(int), 124, 101)
START_TEST(test_da_create__args__0__sizeof_int__124__101) {
    ck_assert_ptr_null(da_create(0, sizeof(int), 124, 101));
} END_TEST

// test: da_create(0, sizeof(int), 125, 24)
START_TEST(test_da_create__args__0__sizeof_int__125__24) {
    ck_assert_ptr_null(da_create(0, sizeof(int), 125, 24));
} END_TEST

// test: da_create(0, sizeof(int), 201, 25)
START_TEST(test_da_create__args__0__sizeof_int__201__25) {
    ck_assert_ptr_null(da_create(0, sizeof(int), 201, 25));
} END_TEST

// test: da_create(0, sizeof(int), 0, 0)
START_TEST(test_da_create__args__0__sizeof_int__0__0) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);
    
    ck_assert_ptr_nonnull(darr);
    ck_assert_int_eq(da_getMaxNumElements(darr, NULL), DA_DEFAULT_SIZE);
    ck_assert_int_eq(da_getElementSize(darr, NULL), sizeof(int));
    ck_assert_int_eq(da_getGrowthFactor(darr, NULL), DA_DEFAULT_GROWTH_FACTOR);
    ck_assert_int_eq(da_getLoadFactor(darr, NULL), DA_DEFAULT_LOAD_FACTOR);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_create(8, sizeof(int), 135, 0)
START_TEST(test_da_create__args__8__sizeof_int__135__0) {
    darrayptr_t darr = da_create(8, sizeof(int), 135, 0);
    
    ck_assert_ptr_nonnull(darr);
    ck_assert_int_eq(da_getMaxNumElements(darr, NULL), DA_DEFAULT_SIZE);
    ck_assert_int_eq(da_getElementSize(darr, NULL), sizeof(int));
    ck_assert_int_eq(da_getGrowthFactor(darr, NULL), 135);
    ck_assert_int_eq(da_getLoadFactor(darr, NULL), DA_DEFAULT_LOAD_FACTOR);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_create(0, sizeof(int), 145, 85)
START_TEST(test_da_create__args__0__sizeof_int__145__85) {
    darrayptr_t darr = da_create(0, sizeof(int), 145, 85);
    
    ck_assert_ptr_nonnull(darr);
    ck_assert_int_eq(da_getMaxNumElements(darr, NULL), DA_DEFAULT_SIZE);
    ck_assert_int_eq(da_getElementSize(darr, NULL), sizeof(int));
    ck_assert_int_eq(da_getGrowthFactor(darr, NULL), 145);
    ck_assert_int_eq(da_getLoadFactor(darr, NULL), 85);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_create(256, sizeof(int), 200, 100)
START_TEST(test_da_create__args__256__sizeof_int__200__100) {
    darrayptr_t darr = da_create(256, sizeof(int), 200, 100);
    
    ck_assert_ptr_nonnull(darr);
    ck_assert_int_eq(da_getMaxNumElements(darr, NULL), 256);
    ck_assert_int_eq(da_getElementSize(darr, NULL), sizeof(int));
    ck_assert_int_eq(da_getGrowthFactor(darr, NULL), 200);
    ck_assert_int_eq(da_getLoadFactor(darr, NULL), 100);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_create_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Create");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_create__args__0__0__0__0);
    tcase_add_test(tc_failure, test_da_create__args__0__sizeof_int__124__0);
    tcase_add_test(tc_failure, test_da_create__args__0__sizeof_int__201__0);
    tcase_add_test(tc_failure, test_da_create__args__0__sizeof_int__0__24);
    tcase_add_test(tc_failure, test_da_create__args__0__sizeof_int__0__101);
    tcase_add_test(tc_failure, test_da_create__args__0__sizeof_int__124__101);
    tcase_add_test(tc_failure, test_da_create__args__0__sizeof_int__125__24);
    tcase_add_test(tc_failure, test_da_create__args__0__sizeof_int__201__25);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_create__args__0__sizeof_int__0__0);
    tcase_add_test(tc_success, test_da_create__args__8__sizeof_int__135__0);
    tcase_add_test(tc_success, test_da_create__args__0__sizeof_int__145__85);
    tcase_add_test(tc_success, test_da_create__args__256__sizeof_int__200__100);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(da_create_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}