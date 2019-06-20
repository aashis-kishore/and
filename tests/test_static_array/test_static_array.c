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


// ================================================================================================== [sa_getMaxNumElements(sarrayptr_t, int8_t*)]
// test: sa_getMaxNumElements(NULL, NULL)
START_TEST(test_sa_getMaxNumElements__args__NULL__NULL) {
    ck_assert_int_eq(sa_getMaxNumElements(NULL, NULL), AND_ZERO);
} END_TEST

// test: sa_getMaxNumElements(NULL, status)
START_TEST(test_sa_getMaxNumElements__args__NULL__status) {
    int8_t status = AND_OK;
    ck_assert_int_eq(sa_getMaxNumElements(NULL, &status), AND_ZERO);
    ck_assert_int_eq(status, AND_NOK);
} END_TEST

// test: sa_getMaxNumElements(sarr, NULL)
START_TEST(test_sa_getMaxNumElements__args__sarr__NULL) {
    size_t max_num_elements = 64;
    sarrayptr_t sarr = sa_create(max_num_elements, sizeof(int));

    ck_assert_int_eq(sa_getMaxNumElements(sarr, NULL), max_num_elements);

    sa_destroy(sarr, AND_FALSE);
} END_TEST

// test: sa_getMaxNumElements(sarr, status)
START_TEST(test_sa_getMaxNumElements__args__sarr__status) {
    size_t max_num_elements = 96;
    sarrayptr_t sarr = sa_create(max_num_elements, sizeof(int));
    int8_t status = AND_NOK;

    ck_assert_int_eq(sa_getMaxNumElements(sarr, &status), max_num_elements);
    ck_assert_int_eq(status, AND_OK);

    sa_destroy(sarr, AND_FALSE);
} END_TEST


Suite* sa_getMaxNumElements_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetMaxNumElements");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_sa_getMaxNumElements__args__NULL__NULL);
    tcase_add_test(tc_failure, test_sa_getMaxNumElements__args__NULL__status);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_sa_getMaxNumElements__args__sarr__NULL);
    tcase_add_test(tc_success, test_sa_getMaxNumElements__args__sarr__status);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [sa_insert(sarrayptr_t, void*, size_t, size_t)]
// test: sa_insert(NULL, NULL, 0, 0)
START_TEST(test_sa_insert__args__NULL__NULL__0__0) {
    ck_assert_int_eq(sa_insert(NULL, NULL, 0, 0), AND_NOK);
} END_TEST

// test: sa_insert(NULL, element, 0, 0)
START_TEST(test_sa_insert__args__NULL__element__0__0) {
    int element = 101;
    ck_assert_int_eq(sa_insert(NULL, &element, 0, 0), AND_NOK);
} END_TEST

// test: sa_insert(sarr, NULL, 0, 0)
START_TEST(test_sa_insert__args__sarr__NULL__0__0) {
    sarrayptr_t sarr = sa_create(0, sizeof(int));

    ck_assert_int_eq(sa_insert(sarr, NULL, 0, 0), AND_NOK);

    sa_destroy(sarr, AND_FALSE);
} END_TEST

// test: sa_insert(sarr, element, gmax_index, 0)
START_TEST(test_sa_insert__args__sarr__element__gmax_index__0) {
    sarrayptr_t sarr = sa_create(SA_DEFAULT_SIZE, sizeof(int));

    int element = 102;
    size_t gmax_index = SA_DEFAULT_SIZE;
    ck_assert_int_eq(sa_insert(sarr, &element, gmax_index, 0), AND_NOK);

    sa_destroy(sarr, AND_FALSE);
} END_TEST

// test: sa_insert(sarr, element, 24, 0)
START_TEST(test_sa_insert__args__sarr__element__24__0) {
    sarrayptr_t sarr = sa_create(0, sizeof(int));

    int element = 123;
    ck_assert_int_eq(sa_insert(sarr, &element, 24, 0), AND_OK);

    sa_destroy(sarr, AND_FALSE);
} END_TEST

// test: sa_insert(sarr, str_element, 12, sizeof(str_element))
START_TEST(test_sa_insert__args__sarr__str_element__12__sizeof_str_element) {
    sarrayptr_t sarr = sa_create(0, sizeof(char*));

    char* element = "this string should be saved";
    ck_assert_int_eq(sa_insert(sarr, element, 12, strlen(element)+1), AND_OK);

    sa_destroy(sarr, AND_TRUE);
} END_TEST


Suite* sa_insert_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Insert");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_sa_insert__args__NULL__NULL__0__0);
    tcase_add_test(tc_failure, test_sa_insert__args__NULL__element__0__0);
    tcase_add_test(tc_failure, test_sa_insert__args__sarr__NULL__0__0);
    tcase_add_test(tc_failure, test_sa_insert__args__sarr__element__gmax_index__0);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_sa_insert__args__sarr__element__24__0);
    tcase_add_test(tc_success, test_sa_insert__args__sarr__str_element__12__sizeof_str_element);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [sa_get(sarrayptr_t, size_t)]
// test: sa_get(NULL, 0)
START_TEST(test_sa_get__args__NULL__0) {
    ck_assert_ptr_null(sa_get(NULL, 0));
} END_TEST

// test: sa_get(sarr, 13)
START_TEST(test_sa_get__args__sarr__13) {
    sarrayptr_t sarr = sa_create(0, sizeof(int));

    int element = 1313;
    ck_assert_int_eq(sa_insert(sarr, &element, 13, 0), AND_OK);
    void* elmnt = sa_get(sarr, 13);
    ck_assert_ptr_nonnull(elmnt);
    ck_assert_int_eq(and_getElement(elmnt, int), element);

    sa_destroy(sarr, AND_FALSE);
} END_TEST

// test: sa_get(sarr, 13) -- MEM_ALLOCED
START_TEST(test_sa_get__args__sarr__13__MEM_ALLOCED) {
    sarrayptr_t sarr = sa_create(0, sizeof(char*));

    char* element = "this data is persistent";
    ck_assert_int_eq(sa_insert(sarr, element, 13, strlen(element)+1), AND_OK);
    void* elmnt = sa_get(sarr, 13);
    ck_assert_ptr_nonnull(elmnt);
    ck_assert_str_eq(and_getElement(elmnt, char*), element);

    sa_destroy(sarr, AND_TRUE);
} END_TEST


Suite* sa_get_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Get");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_sa_get__args__NULL__0);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_failure, test_sa_get__args__sarr__13);
    tcase_add_test(tc_failure, test_sa_get__args__sarr__13__MEM_ALLOCED);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}
// ==================================================================================================


// ================================================================================================== [sa_destroy(sarrayptr_t, AND_BOOL)]
// test: sa_destroy(NULL, AND_FALSE)
START_TEST(test_sa_destroy__args__NULL__AND_FALSE) {
    int8_t destroy_stat = sa_destroy(NULL, AND_FALSE);
    ck_assert_int_eq(destroy_stat, AND_NOK);
} END_TEST

// test: sa_destroy(NULL, AND_TRUE)
START_TEST(test_sa_destroy__args__NULL__AND_TRUE) {
    int8_t destroy_stat = sa_destroy(NULL, AND_TRUE);
    ck_assert_int_eq(destroy_stat, AND_NOK);
} END_TEST
   
// test: sa_destroy(sarr, AND_FALSE)
START_TEST(test_sa_destroy__args__sarr__AND_FALSE) {
    sarrayptr_t sarr = sa_create(0, sizeof(int));

    int8_t destroy_stat = sa_destroy(sarr, AND_FALSE);
    ck_assert_int_eq(destroy_stat, AND_OK);
} END_TEST

// test: sa_destroy(sarr, AND_TRUE)
START_TEST(test_sa_destroy__args__sarr__AND_TRUE) {
    sarrayptr_t sarr = sa_create(0, sizeof(char*));

    char elmnt[] = "test string two";
    sa_insert(sarr, elmnt, 2, strlen(elmnt)+1);

    int8_t destroy_stat = sa_destroy(sarr, AND_TRUE);
    ck_assert_int_eq(destroy_stat, AND_OK);
} END_TEST


Suite* sa_destroy_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Destroy");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_sa_destroy__args__NULL__AND_FALSE);
    tcase_add_test(tc_failure, test_sa_destroy__args__NULL__AND_TRUE);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_sa_destroy__args__sarr__AND_FALSE);
    tcase_add_test(tc_success, test_sa_destroy__args__sarr__AND_TRUE);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(sa_create_suite());
    srunner_add_suite(suite_runner, sa_getMaxNumElements_suite());
    srunner_add_suite(suite_runner, sa_insert_suite());
    srunner_add_suite(suite_runner, sa_get_suite());
    srunner_add_suite(suite_runner, sa_destroy_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}