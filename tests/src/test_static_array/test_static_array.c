#include <check.h>
#include <stdint.h>
#include <string.h>
#include "sarray.h"
#include "and.h"


// ================================================================================================== [sa_create(size_t, size_t)]
// test: sa_create(0, 0)
START_TEST(test_sa_create__args__0__0) {
    sarrayptr_t sarr = sa_create(0, 0);
    ck_assert_ptr_null(sarr);
} END_TEST

// test: sa_create(0, sizeof(int))
START_TEST(test_sa_create__args__0__sizeof_int) {
    sarrayptr_t sarr = sa_create(0, sizeof(int));
    ck_assert_ptr_nonnull(sarr);
    sa_destroy(sarr, AND_FALSE);
} END_TEST

// test: sa_create(12, 0)
START_TEST(test_sa_create__args__12__0) {
    sarrayptr_t sarr = sa_create(12, 0);
    ck_assert_ptr_null(sarr);
} END_TEST

// test: sa_create(12, sizeof(int))
START_TEST(test_sa_create__args__12__sizeof_int) {
    sarrayptr_t sarr = sa_create(12, sizeof(int));
    ck_assert_ptr_nonnull(sarr);
    sa_destroy(sarr, AND_FALSE);
} END_TEST


Suite* sa_create_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Create");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_sa_create__args__0__0);
    tcase_add_test(tc_failure, test_sa_create__args__12__0);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_sa_create__args__0__sizeof_int);
    tcase_add_test(tc_success, test_sa_create__args__12__sizeof_int);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(sa_create_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}