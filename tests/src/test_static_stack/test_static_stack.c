#include <check.h>
#include <stdint.h>
#include <sstack.h>


// ================================================================================================== [sstk_create(size_t, size_t)]
// CASE: NUM_ELMNTS_0
// test: sstk_create(0, 0)
START_TEST(test_sstk_create__args__0__0) {
    sstackptr_t sstk = sstk_create(0, 0);
    ck_assert_ptr_null(sstk);
} END_TEST

// test: sstk_create(0, sizeof(int))
START_TEST(test_sstk_create__args__0__sizeof_int) {
    sstackptr_t sstk = sstk_create(0, sizeof(int));
    ck_assert_ptr_nonnull(sstk);
} END_TEST


// CASE: ELMNT_SIZE_0
// test: sstk_create(12, 0)
START_TEST(test_sstk_create__args_12__0) {
    sstackptr_t sstk = sstk_create(12, 0);
    ck_assert_ptr_null(sstk);
} END_TEST

// test: sstk_create(12, sizeof(int))
START_TEST(test_sstk_create__args_12__sizeof_int) {
    sstackptr_t sstk = sstk_create(12, sizeof(int));
    ck_assert_ptr_nonnull(sstk);
} END_TEST


Suite* sstk_create_suite(void) {
    Suite* suite;
    TCase *tc_num_elmnts_0, *tc_elmnt_size_0;

    suite = suite_create("Create");

    tc_num_elmnts_0 = tcase_create("Num Elmnt 0");
    tcase_add_test(tc_num_elmnts_0, test_sstk_create__args__0__0);
    tcase_add_test(tc_num_elmnts_0, test_sstk_create__args__0__sizeof_int);

    tc_elmnt_size_0 = tcase_create("Elmnt Size 0");
    tcase_add_test(tc_elmnt_size_0, test_sstk_create__args_12__0);
    tcase_add_test(tc_elmnt_size_0, test_sstk_create__args_12__sizeof_int);

    suite_add_tcase(suite, tc_num_elmnts_0);
    suite_add_tcase(suite, tc_elmnt_size_0);

    return suite;
}

// =========================================================================================


// ========================================================================================= [sstk_isEmpty(sstackptr_t)]
// test: sstk_isEmpty(NULL)
START_TEST(test_sstk_isEmpty__args__NULL) {
    int8_t is_empty_stat = sstk_isEmpty(NULL);
    ck_assert_int_eq(is_empty_stat, SSTK_NOK);
} END_TEST

// test: sstk_isEmpty(sstk)
START_TEST(test_sstk_isEmpty__args__empty_sstk) {
    sstackptr_t empty_sstk = sstk_create(SSTK_DEFAULT_SIZE, sizeof(int));
    int8_t is_empty_stat = sstk_isEmpty(empty_sstk);
    ck_assert_int_eq(is_empty_stat, SSTK_TRUE);
} END_TEST

START_TEST(test_sstk_isEmpty__args__nempty_sstk) {
    sstackptr_t nempty_sstk = sstk_create(3, sizeof(int));

    int elmnt = 12;
    sstk_push(nempty_sstk, &elmnt, 0);
        
    int8_t is_nempty_stat = sstk_isEmpty(nempty_sstk);
    ck_assert_int_eq(is_nempty_stat, SSTK_TRUE);
} END_TEST;


Suite* sstk_isEmpty_suite(void) {
    Suite* suite;
    TCase *tc_error, *tc_empty, *tc_nempty;

    suite = suite_create("IsEmpty");

    tc_error = tcase_create("Error");
    tcase_set_tags(tc_error, "ERROR");
    tcase_add_test(tc_error, test_sstk_isEmpty__args__NULL);

    tc_empty = tcase_create("Empty");
    tcase_set_tags(tc_empty, "EMPTY");
    tcase_add_test(tc_empty, test_sstk_isEmpty__args__empty_sstk);
    
    tc_nempty = tcase_create("Not Empty");
    tcase_set_tags(tc_nempty, "NEMPTY");
    tcase_add_test(tc_nempty, test_sstk_isEmpty__args__nempty_sstk);

    suite_add_tcase(suite, tc_error);
    suite_add_tcase(suite, tc_empty);
    suite_add_tcase(suite, tc_nempty);

    return suite;
}

// =========================================================================================


// ========================================================================================= [sstk_destroy(sstackptr_t, SSTK_BOOL)]
// CASE: UNDEFINED STACK
// test: stk_destroy(NULL, SSTK_FALSE)
START_TEST(test_sstk_destroy__args__NULL__SSTK_FALSE) {
    int8_t destroy_stat = sstk_destroy(NULL, SSTK_FALSE);
    ck_assert_int_eq(destroy_stat, SSTK_NOK);
} END_TEST

// test: sstk_destroy(NULL, SSTK_TRUE)
START_TEST(test_sstk_destroy__args__NULL__SSTK_TRUE) {
    int8_t destroy_stat = sstk_destroy(NULL, SSTK_TRUE);
    ck_assert_int_eq(destroy_stat, SSTK_NOK);
} END_TEST


// CASE: DEFINED STACK
sstackptr_t sstk;
void setup__sstk_destroy__defined_stack(void) {
sstk = sstk_create(0, sizeof(int*));
}    

// test: sstk_destroy(sstk, SSTK_FALSE)
START_TEST(test_sstk_destroy__args_sstk__SSTK_FALSE) {
    // sstackptr_t sstk = sstk_create(0, sizeof(int));
    // ck_assert_ptr_nonnull(sstk);

    int8_t destroy_stat = sstk_destroy(sstk, SSTK_FALSE);
    ck_assert_int_eq(destroy_stat, SSTK_OK);
} END_TEST

// test: sstk_destroy(sstk, SSTK_TRUE)
START_TEST(test_sstk_destroy__args_sstk__SSTK_TRUE) {
    // sstackptr_t sstk = sstk_create(0, sizeof(int));
    // ck_assert_ptr_nonnull(sstk);

    int8_t destroy_stat = sstk_destroy(sstk, SSTK_TRUE);
    ck_assert_int_eq(destroy_stat, SSTK_OK);
} END_TEST


Suite* sstk_destroy_suite(void) {
    Suite* suite;
    TCase *tc_undefined_stack, *tc_defined_stack;

    suite = suite_create("Destroy");

    tc_undefined_stack = tcase_create("Undefined Stack");
    // tcase_set_tags(tc_undefined_stack, "SKIP");
    tcase_add_test(tc_undefined_stack, test_sstk_destroy__args__NULL__SSTK_FALSE);
    tcase_add_test(tc_undefined_stack, test_sstk_destroy__args__NULL__SSTK_TRUE);

    tc_defined_stack = tcase_create("Defined Stack");
    tcase_set_tags(tc_defined_stack, "SKIP");
    tcase_add_checked_fixture(tc_defined_stack, setup__sstk_destroy__defined_stack, NULL);
    tcase_add_test(tc_defined_stack, test_sstk_destroy__args_sstk__SSTK_FALSE);
    tcase_add_test(tc_defined_stack, test_sstk_destroy__args_sstk__SSTK_TRUE);

    suite_add_tcase(suite, tc_undefined_stack);
    suite_add_tcase(suite, tc_defined_stack);

    return suite;
}

// =========================================================================================


int main(void) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(sstk_create_suite());
    srunner_add_suite(suite_runner, sstk_destroy_suite());
    srunner_add_suite(suite_runner, sstk_isEmpty_suite());

    // srunner_run_all(suite_runner, CK_NORMAL);
    // srunner_run_tagged(suite_runner, "Create", NULL, NULL, NULL, CK_NORMAL);
    // srunner_run_tagged(suite_runner, "Destroy", NULL, NULL, NULL, CK_NORMAL);
    // srunner_run_tagged(suite_runner, "Destroy", NULL, NULL, "SKIP", CK_NORMAL);
    srunner_run_tagged(suite_runner, "IsEmpty", NULL, NULL, "NEMPTY", CK_NORMAL);
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}