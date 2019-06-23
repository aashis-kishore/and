#include <check.h>
#include <stdint.h>
#include <string.h>
#include "sstack.h"
#include "and.h"


// ================================================================================================== [ss_create(size_t, size_t)]
// CASE: NUM_ELMNTS_0
// test: ss_create(0, 0)
START_TEST(test_ss_create__args__0__0) {
    sstackptr_t sstk = ss_create(0, 0);
    ck_assert_ptr_null(sstk);
} END_TEST

// test: ss_create(0, sizeof(int))
START_TEST(test_ss_create__args__0__sizeof_int) {
    sstackptr_t sstk = ss_create(0, sizeof(int));
    ck_assert_ptr_nonnull(sstk);
    ss_destroy(sstk, AND_FALSE);
} END_TEST


// CASE: ELMNT_SIZE_0
// test: ss_create(12, 0)
START_TEST(test_ss_create__args_12__0) {
    sstackptr_t sstk = ss_create(12, 0);
    ck_assert_ptr_null(sstk);
} END_TEST

// test: ss_create(12, sizeof(int))
START_TEST(test_ss_create__args_12__sizeof_int) {
    sstackptr_t sstk = ss_create(12, sizeof(int));
    ck_assert_ptr_nonnull(sstk);
    ss_destroy(sstk, AND_FALSE);
} END_TEST


Suite* ss_create_suite(void) {
    Suite* suite;
    TCase *tc_num_elmnts_0, *tc_elmnt_size_0;

    suite = suite_create("Create");

    tc_num_elmnts_0 = tcase_create("Num Elmnt 0");
    tcase_add_test(tc_num_elmnts_0, test_ss_create__args__0__0);
    tcase_add_test(tc_num_elmnts_0, test_ss_create__args__0__sizeof_int);

    tc_elmnt_size_0 = tcase_create("Elmnt Size 0");
    tcase_add_test(tc_elmnt_size_0, test_ss_create__args_12__0);
    tcase_add_test(tc_elmnt_size_0, test_ss_create__args_12__sizeof_int);

    suite_add_tcase(suite, tc_num_elmnts_0);
    suite_add_tcase(suite, tc_elmnt_size_0);

    return suite;
}

// =========================================================================================


// ========================================================================================= [ss_isFull(sstackptr_t)]
// test: ss_isFull(NULL)
START_TEST(test_ss_isFull__args__NULL) {
    int8_t is_full_stat = ss_isFull(NULL);
    ck_assert_int_eq(is_full_stat, AND_NOK);
} END_TEST

//test: ss_isFull(full_sstk)
START_TEST(test_ss_isFull__args__full_sstk) {
    sstackptr_t full_sstk = ss_create(3, sizeof(int));
    for (int i=1; i<=3; i++)
        ss_push(full_sstk, &i, 0);
    
    int8_t is_full_stat = ss_isFull(full_sstk);
    ck_assert_int_eq(is_full_stat, AND_TRUE);
    ss_destroy(full_sstk, AND_FALSE);
} END_TEST

//test: ss_isFull(nfull_sstk)
START_TEST(test_ss_isFull__args__nfull_sstk) {
    sstackptr_t nfull_sstk = ss_create(0, sizeof(int));
    int elmnt = 12;
    ss_push(nfull_sstk, &elmnt, 0);

    int8_t is_full_stat = ss_isFull(nfull_sstk);
    ck_assert_int_eq(is_full_stat, AND_FALSE);
    ss_destroy(nfull_sstk, AND_FALSE);
} END_TEST


Suite* ss_isFull_suite(void) {
    Suite* suite;
    TCase *tc_error, *tc_full, *tc_nfull;

    suite = suite_create("IsFull");

    tc_error = tcase_create("Error");
    tcase_set_tags(tc_error, "ERROR");
    tcase_add_test(tc_error, test_ss_isFull__args__NULL);

    tc_full = tcase_create("Full");
    tcase_set_tags(tc_full, "FULL");
    tcase_add_test(tc_full, test_ss_isFull__args__full_sstk);
    
    tc_nfull = tcase_create("Not Full");
    tcase_set_tags(tc_nfull, "NFULL");
    tcase_add_test(tc_nfull, test_ss_isFull__args__nfull_sstk);

    suite_add_tcase(suite, tc_error);
    suite_add_tcase(suite, tc_full);
    suite_add_tcase(suite, tc_nfull);

    return suite;
}

// =========================================================================================


// ========================================================================================= [ss_isEmpty(sstackptr_t)]
// test: ss_isEmpty(NULL)
START_TEST(test_ss_isEmpty__args__NULL) {
    int8_t is_empty_stat = ss_isEmpty(NULL);
    ck_assert_int_eq(is_empty_stat, AND_NOK);
} END_TEST

// test: ss_isEmpty(sstk)
START_TEST(test_ss_isEmpty__args__empty_sstk) {
    sstackptr_t empty_sstk = ss_create(SS_DEFAULT_SIZE, sizeof(int));
    int8_t is_empty_stat = ss_isEmpty(empty_sstk);
    ck_assert_int_eq(is_empty_stat, AND_TRUE);
    ss_destroy(empty_sstk, AND_FALSE);
} END_TEST

// test: ss_isEmpty(nempty_sstk)
START_TEST(test_ss_isEmpty__args__nempty_sstk) {
    sstackptr_t nempty_sstk = ss_create(3, sizeof(int));

    int elmnt = 12;
    ss_push(nempty_sstk, &elmnt, 0);
        
    int8_t is_nempty_stat = ss_isEmpty(nempty_sstk);
    ck_assert_int_eq(is_nempty_stat, AND_FALSE);
    ss_destroy(nempty_sstk, AND_FALSE);
} END_TEST;

// test: ss_isEmpty(full_then_empty_sstk)
START_TEST(test_ss_isEmpty__args__full_then_empty_sstk) {
    sstackptr_t full_then_empty_sstk = ss_create(3, sizeof(int));

    for (int i=1; i<=3; i++)
        ss_push(full_then_empty_sstk, &i, 0);

    ss_pop(full_then_empty_sstk);
    ss_pop(full_then_empty_sstk);
    ss_pop(full_then_empty_sstk);

    int8_t is_empty_stat = ss_isEmpty(full_then_empty_sstk);

    ck_assert_int_eq(is_empty_stat, AND_TRUE);
    ss_destroy(full_then_empty_sstk, AND_FALSE);
} END_TEST


Suite* ss_isEmpty_suite(void) {
    Suite* suite;
    TCase *tc_error, *tc_empty, *tc_nempty, *tc_full_then_empty;

    suite = suite_create("IsEmpty");

    tc_error = tcase_create("Error");
    tcase_set_tags(tc_error, "ERROR");
    tcase_add_test(tc_error, test_ss_isEmpty__args__NULL);

    tc_empty = tcase_create("Empty");
    tcase_set_tags(tc_empty, "EMPTY");
    tcase_add_test(tc_empty, test_ss_isEmpty__args__empty_sstk);
    
    tc_nempty = tcase_create("Not Empty");
    tcase_set_tags(tc_nempty, "NEMPTY");
    tcase_add_test(tc_nempty, test_ss_isEmpty__args__nempty_sstk);

    tc_full_then_empty = tcase_create("Full Then Empty");
    tcase_add_test(tc_full_then_empty, test_ss_isEmpty__args__full_then_empty_sstk);

    suite_add_tcase(suite, tc_error);
    suite_add_tcase(suite, tc_empty);
    suite_add_tcase(suite, tc_nempty);
    suite_add_tcase(suite, tc_full_then_empty);

    return suite;
}

// =========================================================================================


// ========================================================================================= [ss_push(sstackptr_t, void*, size_t)]
//test: ss_push(NULL, NULL, 0)
START_TEST(test_ss_push__args__NULL__NULL__0) {
    int8_t push_stat = ss_push(NULL, NULL, 0);
    ck_assert_int_eq(push_stat, AND_NOK);
} END_TEST

// test: ss_push(NULL, NULL, sizeof(char*))
START_TEST(test_ss_push__args__NULL__NULL__sizeof_int_ptr) {
    int8_t push_stat = ss_push(NULL, NULL, sizeof(char*));
    ck_assert_int_eq(push_stat, AND_NOK);
} END_TEST

// test: ss_push(NULL, elmnt, 0)
START_TEST(test_ss_push__args__NULL__elmnt__0) {
    int elmnt = 12;
    int8_t push_stat = ss_push(NULL, &elmnt, 0);
    ck_assert_int_eq(push_stat, AND_NOK);
} END_TEST

// test: ss_push(NULL, elmnt, sizeof(char*))
START_TEST(test_ss_push__args__NULL__elmnt__sizeof_int_ptr) {
    int elmnt = 12;
    int8_t push_stat = ss_push(NULL, &elmnt, sizeof(char*));
    ck_assert_int_eq(push_stat, AND_NOK);
} END_TEST

// test: ss_push(sstk, NULL, 0)
START_TEST(test_ss_push__args__sstk__NULL__0) {
    sstackptr_t sstk = ss_create(SS_DEFAULT_SIZE, sizeof(int));
    int elmnt = 12;
    int8_t push_stat = ss_push(sstk, NULL, 0);
    ck_assert_int_eq(push_stat, AND_NOK);
    ss_destroy(sstk, AND_FALSE);
} END_TEST

// test: ss_push(sstk, NULL, sizeof(char*))
START_TEST(test_ss_push__args__sstk__NULL__sizeof_int_ptr) {
    sstackptr_t sstk = ss_create(SS_DEFAULT_SIZE, sizeof(int));
    int elmnt = 12;
    int8_t push_stat = ss_push(sstk, NULL, sizeof(char*));
    ck_assert_int_eq(push_stat, AND_NOK);
    ss_destroy(sstk, AND_FALSE);
} END_TEST

// test: ss_push(sstk, elmnt, 0)
START_TEST(test_ss_push__args__sstk__elmnt__0) {
    sstackptr_t sstk = ss_create(SS_DEFAULT_SIZE, sizeof(int));
    int elmnt = 12;
    int8_t push_stat = ss_push(sstk, &elmnt, 0);
    ck_assert_int_eq(push_stat, AND_OK);
    ss_destroy(sstk, AND_FALSE);
} END_TEST

// test: ss_push(sstk, elmnt, sizeof(char*))
START_TEST(test_ss_push__args__sstk__elmnt__sizeof_char_ptr) {
    sstackptr_t sstk = ss_create(SS_DEFAULT_SIZE, sizeof(char*));
    char elmnt[] = "test string";

    int8_t push_stat = ss_push(sstk, elmnt, strlen(elmnt)+1);
    ck_assert_int_eq(push_stat, AND_OK);
    ss_destroy(sstk, AND_TRUE);
} END_TEST


Suite* ss_push_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Push");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_ss_push__args__NULL__NULL__0);
    tcase_add_test(tc_failure, test_ss_push__args__NULL__NULL__sizeof_int_ptr);
    tcase_add_test(tc_failure, test_ss_push__args__NULL__elmnt__0);
    tcase_add_test(tc_failure, test_ss_push__args__NULL__elmnt__sizeof_int_ptr);
    tcase_add_test(tc_failure, test_ss_push__args__sstk__NULL__0);
    tcase_add_test(tc_failure, test_ss_push__args__sstk__NULL__sizeof_int_ptr);

    tc_success = tcase_create("Success");
    tcase_set_tags(tc_success, "SUCCESS");
    tcase_add_test(tc_success, test_ss_push__args__sstk__elmnt__0);
    tcase_add_test(tc_success, test_ss_push__args__sstk__elmnt__sizeof_char_ptr);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// =========================================================================================


// ========================================================================================= [ss_pop(sstackptr_t, AND_BOOL)]
// test: ss_pop(NULL)
START_TEST(test_ss_pop__args__NULL) {
    void* pop_stat = ss_pop(NULL);
    ck_assert_ptr_null(pop_stat);
} END_TEST

// test: ss_pop(sstk)
START_TEST(test_ss_pop__args__sstk) {
    sstackptr_t sstk = ss_create(SS_DEFAULT_SIZE, sizeof(int));
    int elmnt = 12;
    ss_push(sstk, &elmnt, 0);

    void* popped_elmnt = ss_pop(sstk);

    ck_assert_ptr_nonnull(popped_elmnt);
    ck_assert_int_eq(and_getElement(popped_elmnt, int), 12);

    ss_destroy(sstk, AND_FALSE);
} END_TEST

// test: ss_pop(sstk) -- MEM ALLOCED
START_TEST(test_ss_pop__args__sstk__MEM_ALLOCED) {
    sstackptr_t sstk = ss_create(SS_DEFAULT_SIZE, sizeof(char*));
    char elmnt[] = "test string";
    ss_push(sstk, elmnt, strlen(elmnt)+1);

    void* popped_elmnt = ss_pop(sstk);

    ck_assert_ptr_nonnull(popped_elmnt);
    ck_assert_str_eq(and_getElement(popped_elmnt, char*), elmnt);

    free(and_getElement(popped_elmnt, char*));
    ss_destroy(sstk, AND_TRUE);
} END_TEST


Suite* ss_pop_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Pop");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_ss_pop__args__NULL);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_ss_pop__args__sstk);
    tcase_add_test(tc_success, test_ss_pop__args__sstk__MEM_ALLOCED);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// =========================================================================================


// ========================================================================================= [ss_peek(sstackptr_t, size_t)]
// test: ss_peek(NULL, 0)
START_TEST(test_ss_peek__args__NULL__0) {
    void* peeked_elmnt = ss_peek(NULL, 0);

    ck_assert_ptr_null(peeked_elmnt);
} END_TEST

// test: ss_peek(NULL, 2)
START_TEST(test_ss_peek__args__NULL__2) {
    void* peeked_elmnt = ss_peek(NULL, 2);

    ck_assert_ptr_null(peeked_elmnt);
} END_TEST

// test: ss_peek(sstk, 0)
START_TEST(test_ss_peek__args__sstk__0) {
    sstackptr_t sstk = ss_create(0, sizeof(int));

    for (int i=1; i<=3; i++)
        ss_push(sstk, &i, 0);

    void* peeked_elmnt = ss_peek(sstk, 0);
    ck_assert_ptr_nonnull(peeked_elmnt);
    ck_assert_int_eq(and_getElement(peeked_elmnt, int), 3);
    ss_destroy(sstk, AND_FALSE);
} END_TEST

// test: ss_peek(sstk, 3)
START_TEST(test_ss_peek__args__sstk__3) {
    sstackptr_t sstk = ss_create(0, sizeof(int));

    for (int i=1; i<=5; i++)
        ss_push(sstk, &i, 0);

    void* peeked_elmnt = ss_peek(sstk, 3);
    ck_assert_ptr_nonnull(peeked_elmnt);
    ck_assert_int_eq(and_getElement(peeked_elmnt, int), 2);
    ss_destroy(sstk, AND_FALSE);
} END_TEST

// test: ss_peek(sstk, peek_beyond_first)
START_TEST(test_ss_peek__args__sstk__peek_beyond_first) {
    sstackptr_t sstk = ss_create(0, sizeof(int));

    for (int i=1; i<=5; i++)
        ss_push(sstk, &i, 0);

    void* peeked_elmnt = ss_peek(sstk, 7);
    ck_assert_ptr_nonnull(peeked_elmnt);
    ck_assert_int_eq(and_getElement(peeked_elmnt, int), 3);
    ss_destroy(sstk, AND_FALSE);
} END_TEST


Suite* ss_peek_suite(void) {
    Suite* suite;
    TCase *failure, *success;

    suite = suite_create("Peek");

    failure = tcase_create("Failure");
    tcase_add_test(failure, test_ss_peek__args__NULL__0);
    tcase_add_test(failure, test_ss_peek__args__NULL__2);

    success = tcase_create("Success");
    tcase_add_test(success, test_ss_peek__args__sstk__0);
    tcase_add_test(success, test_ss_peek__args__sstk__3);
    tcase_add_test(success, test_ss_peek__args__sstk__peek_beyond_first);

    suite_add_tcase(suite, failure);
    suite_add_tcase(suite, success);
    return suite;
}

// =========================================================================================


// ========================================================================================= [ss_swap(sstackptr_t)]
// test: ss_swap(NULL)
START_TEST(test_ss_swap__args__NULL) {
    void* swap_stat = ss_swap(NULL);

    ck_assert_ptr_null(swap_stat);
} END_TEST

// test: ss_swap(empty_sstk)
START_TEST(test_ss_swap__args__empty_sstk) {
    sstackptr_t empty_sstk = ss_create(0, sizeof(int));
    
    void* swap_stat = ss_swap(empty_sstk);

    ck_assert_ptr_null(swap_stat);
    ss_destroy(empty_sstk, AND_FALSE);
} END_TEST

// test: ss_swap(one_elmnt_sstk)
START_TEST(test_ss_swap__args__one_elmnt_sstk) {
    sstackptr_t one_elmnt_sstk = ss_create(0, sizeof(int));
    int elmnt = 67;
    ss_push(one_elmnt_sstk, &elmnt, 0);

    void* swap_stat = ss_swap(one_elmnt_sstk);

    ck_assert_ptr_nonnull(swap_stat);
    ck_assert_int_eq(and_getElement(swap_stat, int), 67);
    ss_destroy(one_elmnt_sstk, AND_FALSE);
} END_TEST

// test: ss_swap(two_elmnt_sstk)
START_TEST(test_ss_swap__args__two_elmnt_sstk) {
    sstackptr_t two_elmnt_sstk = ss_create(0, sizeof(int));

    int elmnt_1 = 21, elmnt_2 = 22;
    ss_push(two_elmnt_sstk, &elmnt_1, 0);
    ss_push(two_elmnt_sstk, &elmnt_2, 0);

    void* swap_stat = ss_swap(two_elmnt_sstk);

    void* new_top = ss_peek(two_elmnt_sstk, 0);

    ck_assert_ptr_nonnull(swap_stat);
    ck_assert_int_eq(and_getElement(swap_stat, int), 22);
    ck_assert_int_eq(and_getElement(new_top, int), 21);
    ss_destroy(two_elmnt_sstk, AND_FALSE);
} END_TEST

// test: ss_swap(n_elmnt_sstk)
START_TEST(test_ss_swap__args__n_elmnt_sstk) {
    sstackptr_t n_elmnt_sstk = ss_create(0, sizeof(int));

    for (int i=1; i<=5; i++)
        ss_push(n_elmnt_sstk, &i, 0);

    void* swap_stat = ss_swap(n_elmnt_sstk);

    void* new_top = ss_peek(n_elmnt_sstk, 0);

    ck_assert_ptr_nonnull(swap_stat);
    ck_assert_int_eq(and_getElement(swap_stat, int), 5);
    ck_assert_int_eq(and_getElement(new_top, int), 4);
    ss_destroy(n_elmnt_sstk, AND_FALSE);
} END_TEST


Suite* ss_swap_suite(void) {
    Suite *suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Swap");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_ss_swap__args__NULL);
    tcase_add_test(tc_failure, test_ss_swap__args__empty_sstk);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_ss_swap__args__one_elmnt_sstk);
    tcase_add_test(tc_success, test_ss_swap__args__two_elmnt_sstk);
    tcase_add_test(tc_success, test_ss_swap__args__n_elmnt_sstk);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// =========================================================================================


// ========================================================================================= [ss_destroy(sstackptr_t, AND_BOOL)]
// CASE: UNDEFINED STACK
// test: ss_destroy(NULL, AND_FALSE)
START_TEST(test_ss_destroy__args__NULL__AND_FALSE) {
    int8_t destroy_stat = ss_destroy(NULL, AND_FALSE);
    ck_assert_int_eq(destroy_stat, AND_NOK);
} END_TEST

// test: ss_destroy(NULL, AND_TRUE)
START_TEST(test_ss_destroy__args__NULL__AND_TRUE) {
    int8_t destroy_stat = ss_destroy(NULL, AND_TRUE);
    ck_assert_int_eq(destroy_stat, AND_NOK);
} END_TEST


// CASE: DEFINED STACK   
// test: ss_destroy(sstk, AND_FALSE)
START_TEST(test_ss_destroy__args_sstk__AND_FALSE) {
    sstackptr_t sstk = ss_create(0, sizeof(int));
    ck_assert_ptr_nonnull(sstk);

    int8_t destroy_stat = ss_destroy(sstk, AND_FALSE);
    ck_assert_int_eq(destroy_stat, AND_OK);
} END_TEST

// test: ss_destroy(sstk, AND_TRUE)
START_TEST(test_ss_destroy__args_sstk__AND_TRUE) {
    sstackptr_t sstk = ss_create(0, sizeof(char*));
    ck_assert_ptr_nonnull(sstk);

    char elmnt[] = "test string two";
    ss_push(sstk, elmnt, strlen(elmnt)+1);

    int8_t destroy_stat = ss_destroy(sstk, AND_TRUE);
    ck_assert_int_eq(destroy_stat, AND_OK);
} END_TEST


Suite* ss_destroy_suite(void) {
    Suite* suite;
    TCase *tc_undefined_stack, *tc_defined_stack;

    suite = suite_create("Destroy");

    tc_undefined_stack = tcase_create("Undefined Stack");
    tcase_add_test(tc_undefined_stack, test_ss_destroy__args__NULL__AND_FALSE);
    tcase_add_test(tc_undefined_stack, test_ss_destroy__args__NULL__AND_TRUE);

    tc_defined_stack = tcase_create("Defined Stack");
    tcase_add_test(tc_defined_stack, test_ss_destroy__args_sstk__AND_FALSE);
    tcase_add_test(tc_defined_stack, test_ss_destroy__args_sstk__AND_TRUE);

    suite_add_tcase(suite, tc_undefined_stack);
    suite_add_tcase(suite, tc_defined_stack);

    return suite;
}

// =========================================================================================


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(ss_create_suite());
    srunner_add_suite(suite_runner, ss_isEmpty_suite());
    srunner_add_suite(suite_runner, ss_isFull_suite());
    srunner_add_suite(suite_runner, ss_push_suite());
    srunner_add_suite(suite_runner, ss_pop_suite());
    srunner_add_suite(suite_runner, ss_peek_suite());
    srunner_add_suite(suite_runner, ss_swap_suite());
    srunner_add_suite(suite_runner, ss_destroy_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}