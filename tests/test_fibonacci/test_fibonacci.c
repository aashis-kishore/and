#include <check.h>
#include <stdint.h>
#include "fibonacci.h"
#include "and.h"


// ================================================================================================== [fibIter(size_t, size_t)]
// test: fibIter(4, 0)
START_TEST(test_fibIter__args__4__0) {
    ck_assert_int_eq(fibIter(4, 0), AND_NOK);
} END_TEST

// test: fibIter(0, 0)
START_TEST(test_fibIter__args__0__0) {
    ck_assert_int_eq(fibIter(0, 0), AND_OK);
} END_TEST

// test: fibIter(0, 15)
START_TEST(test_fibIter__args__0__15) {
    ck_assert_int_eq(fibIter(0, 15), AND_OK);
} END_TEST

// test: fibIter(10, 20)
START_TEST(test_fibIter__args__10__20) {
    ck_assert_int_eq(fibIter(10, 20), AND_OK);
} END_TEST


Suite* fibIter_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("FibIter");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_fibIter__args__4__0);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_failure, test_fibIter__args__0__0);
    tcase_add_test(tc_failure, test_fibIter__args__0__15);
    tcase_add_test(tc_failure, test_fibIter__args__10__20);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [fibRec(size_t, size_t)]
// test: fibRec(4, 0)
START_TEST(test_fibRec__args__4__0) {
    ck_assert_int_eq(fibRec(4, 0), AND_NOK);
} END_TEST

// test: fibRec(0, 0)
START_TEST(test_fibRec__args__0__0) {
    ck_assert_int_eq(fibRec(0, 0), AND_OK);
} END_TEST

// test: fibRec(0, 15)
START_TEST(test_fibRec__args__0__15) {
    ck_assert_int_eq(fibRec(0, 15), AND_OK);
} END_TEST

// test: fibRec(10, 20)
START_TEST(test_fibRec__args__10__20) {
    ck_assert_int_eq(fibRec(10, 20), AND_OK);
} END_TEST


Suite* fibRec_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("FibRec");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_fibRec__args__4__0);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_failure, test_fibRec__args__0__0);
    tcase_add_test(tc_failure, test_fibRec__args__0__15);
    tcase_add_test(tc_failure, test_fibRec__args__10__20);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [fibTab(size_t, size_t)]

// ==================================================================================================


// ================================================================================================== [fibMem(size_t, size_t)]

// ==================================================================================================


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(fibIter_suite());
    srunner_add_suite(suite_runner, fibRec_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}