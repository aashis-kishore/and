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


// ================================================================================================== [da_getNumElements(darrayptr_t, int8_t*)]
// test: da_getNumElements(NULL, stat)
START_TEST(test_da_getNumElements__args__NULL__stat) {
    int8_t get_num_elements_stat = AND_OK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), AND_ZERO);
    ck_assert_int_eq(get_num_elements_stat, AND_NOK);
} END_TEST

// test: da_getNumElements(darr, stat) -- DELETE 1
START_TEST(test_da_getNumElements__args__darr__stat) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    ck_assert_ptr_null(da_delete(darr, 47));

    int8_t get_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), AND_ZERO);
    ck_assert_int_eq(get_num_elements_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_getNumElements(darr, stat) -- INSERT 3
START_TEST(test_da_getNumElements__args__darr__stat__INS_3) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int element = 67;
    ck_assert_int_eq(da_insert(darr, &element, 12, 0), AND_OK);
    element = 45;
    ck_assert_int_eq(da_insert(darr, &element, 67, 0), AND_OK);
    element = -90;
    ck_assert_int_eq(da_insert(darr, &element, 33, 0), AND_OK);

    int8_t get_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), 3);
    ck_assert_int_eq(get_num_elements_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_getNumElements(darr, stat) -- INSERT 2, DELETE 2, INSERT 1
START_TEST(test_da_getNumElements__args__darr__stat__INS_2_DEL_2_INS_1) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int element = 67;
    ck_assert_int_eq(da_insert(darr, &element, 12, 0), AND_OK);
    element = -90;
    ck_assert_int_eq(da_insert(darr, &element, 33, 0), AND_OK);

    int8_t get_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), 2);
    ck_assert_int_eq(get_num_elements_stat, AND_OK);

    ck_assert_ptr_nonnull(da_delete(darr, 33));
    get_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), 1);
    ck_assert_int_eq(get_num_elements_stat, AND_OK);

    ck_assert_ptr_nonnull(da_delete(darr, 12));
    get_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), 0);
    ck_assert_int_eq(get_num_elements_stat, AND_OK);

    ck_assert_ptr_null(da_delete(darr, 33));
    get_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), 0);
    ck_assert_int_eq(get_num_elements_stat, AND_OK);
    
    element = -980;
    ck_assert_int_eq(da_insert(darr, &element, 62, 0), AND_OK);

    get_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getNumElements(NULL, &get_num_elements_stat), 1);
    ck_assert_int_eq(get_num_elements_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_getNumElements_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetNumElements");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_getNumElements__args__NULL__stat);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_getNumElements__args__darr__stat);
    tcase_add_test(tc_success, test_da_getNumElements__args__darr__stat__INS_3);
    tcase_add_test(tc_success, test_da_getNumElements__args__darr__stat__INS_2_DEL_2_INS_1);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_getMaxNumElements(darrayptr_t, int8_t*)]
// test: da_getMaxNumElements(NULL, stat)
START_TEST(test_da_getMaxNumElements__args__NULL__stat) {
    int8_t get_max_num_elements_stat = AND_OK;

    ck_assert_int_eq(da_getMaxNumElements(NULL, &get_max_num_elements_stat), AND_ZERO);
    ck_assert_int_eq(get_max_num_elements_stat, AND_NOK);
} END_TEST

// test: da_getMaxNumElements(darr, stat)
START_TEST(test_da_getMaxNumElements__args__darr__stat) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int8_t get_max_num_elements_stat = AND_NOK;

    ck_assert_int_eq(da_getMaxNumElements(darr, &get_max_num_elements_stat), DA_DEFAULT_SIZE);
    ck_assert_int_eq(get_max_num_elements_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_getMaxNumElements(darr, stat) -- NON-DEFAULT SIZE
START_TEST(test_da_getMaxNumElements__args__darr__stat__NON_DEFAULT_SIZE) {
    darrayptr_t darr = da_create(100, sizeof(int), 0, 0);

    int8_t get_max_num_elements_stat = AND_NOK;

    ck_assert_int_eq(da_getMaxNumElements(darr, &get_max_num_elements_stat), 100);
    ck_assert_int_eq(get_max_num_elements_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_getMaxNumElements(darr, stat) -- RESIZE
START_TEST(test_da_getMaxNumElements__args__darr__stat__RESIZE) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int element = 1012;
    ck_assert_int_eq(da_insert(darr, &element, 101, 0), AND_OK);

    int8_t get_max_num_elements_stat = AND_NOK;

    ck_assert_int_eq(da_getMaxNumElements(darr, &get_max_num_elements_stat), 108);
    ck_assert_int_eq(get_max_num_elements_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_getMaxNumElements_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetMaxNumElements");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_getMaxNumElements__args__NULL__stat);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_getMaxNumElements__args__darr__stat);
    tcase_add_test(tc_success, test_da_getMaxNumElements__args__darr__stat__NON_DEFAULT_SIZE);
    tcase_add_test(tc_success, test_da_getMaxNumElements__args__darr__stat__RESIZE);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_getElementSize(darrayptr_t, int8_t*)]
// test: da_getElementSize(NULL, stat)
START_TEST(test_da_getElementSize__args__NULL__stat) {
    int8_t get_element_size_stat = AND_OK;

    ck_assert_int_eq(da_getElementSize(NULL, &get_element_size_stat), AND_ZERO);
    ck_assert_int_eq(get_element_size_stat, AND_NOK);
} END_TEST

// test: da_getElementSize(darr, stat)
START_TEST(test_da_getElementSize__args__darr__stat) {
    darrayptr_t darr = da_create(0, sizeof(char*), 0, 0);

    int8_t get_element_size_stat = AND_NOK;

    ck_assert_int_eq(da_getElementSize(darr, &get_element_size_stat), sizeof(char*));
    ck_assert_int_eq(get_element_size_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_getElementSize_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetElementSize");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_getElementSize__args__NULL__stat);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_getElementSize__args__darr__stat);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_getGrowthFactor(darrayptr_t, int8_t*)]
// test: getGrowthFactor(NULL, stat)
START_TEST(test_da_getGrowthFactor__args__NULL__stat) {
    int8_t get_growth_factor_stat = AND_OK;

    ck_assert_int_eq(da_getGrowthFactor(NULL, &get_growth_factor_stat), AND_ZERO);
    ck_assert_int_eq(get_growth_factor_stat, AND_NOK);
} END_TEST

// test: getGrowthFactor(darr, stat)
START_TEST(test_da_getGrowthFactor__args__darr__stat) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int8_t get_growth_factor_stat = AND_NOK;

    ck_assert_int_eq(da_getGrowthFactor(darr, &get_growth_factor_stat), DA_DEFAULT_GROWTH_FACTOR);
    ck_assert_int_eq(get_growth_factor_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: getGrowthFactor(darr, stat) -- NON-DEFAULT GROWTH FACTOR
START_TEST(test_da_getGrowthFactor__args__darr__stat__NON_DEFAULT) {
    darrayptr_t darr = da_create(0, sizeof(int), 135, 0);

    int8_t get_growth_factor_stat = AND_NOK;

    ck_assert_int_eq(da_getGrowthFactor(darr, &get_growth_factor_stat), 135);
    ck_assert_int_eq(get_growth_factor_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: getGrowthFactor(darr, stat) -- RESIZE
START_TEST(test_da_getGrowthFactor__args__darr__stat__RESIZE) {
    darrayptr_t darr = da_create(0, sizeof(int), 135, 0);

    int8_t get_growth_factor_stat = AND_NOK;

    ck_assert_int_eq(da_getGrowthFactor(darr, &get_growth_factor_stat), 135);
    ck_assert_int_eq(get_growth_factor_stat, AND_OK);

    int element = 785;
    ck_assert_int_eq(da_insert(darr, &element, 48, 0), AND_OK);

    int8_t get_max_num_elements_stat = AND_NOK;
    ck_assert_int_eq(da_getMaxNumElements(darr, &get_max_num_elements_stat), 44);
    ck_assert_int_eq(get_max_num_elements_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_getGrowthFactor_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetGrowthFactor");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_getGrowthFactor__args__NULL__stat);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_getGrowthFactor__args__darr__stat);
    tcase_add_test(tc_success, test_da_getGrowthFactor__args__darr__stat__NON_DEFAULT);
    tcase_add_test(tc_success, test_da_getGrowthFactor__args__darr__stat__RESIZE);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_getLoadFactor(darrayptr_t, int8_t*)]
// test: da_getLoadFactor(NULL, stat)
START_TEST(test_da_getLoadFactor__args__NULL__stat) {
    int8_t get_load_factor_stat = AND_OK;

    ck_assert_int_eq(da_getLoadFactor(NULL, &get_load_factor_stat), AND_ZERO);
    ck_assert_int_eq(get_load_factor_stat, AND_NOK);
} END_TEST

// test: da_getLoadFactor(darr, stat)
START_TEST(test_da_getLoadFactor__args__darr__stat) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int8_t get_load_factor_stat = AND_NOK;

    ck_assert_int_eq(da_getLoadFactor(darr, &get_load_factor_stat), DA_DEFAULT_LOAD_FACTOR);
    ck_assert_int_eq(get_load_factor_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_getLoadFactor(darr, stat) -- NON-DEFAULT LOAD FACTOR
START_TEST(test_da_getLoadFactor__args__darr__stat__NON_DEFAULT) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 45);

    int8_t get_load_factor_stat = AND_NOK;

    ck_assert_int_eq(da_getLoadFactor(darr, &get_load_factor_stat), 45);
    ck_assert_int_eq(get_load_factor_stat, AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_getLoadFactor(darr, stat) -- RESIZE
START_TEST(test_da_getLoadFactor__args__darr__stat__RESIZE) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 25);

    int8_t get_load_factor_stat = AND_NOK;

    ck_assert_int_eq(da_getLoadFactor(darr, &get_load_factor_stat), 25);
    ck_assert_int_eq(get_load_factor_stat, AND_OK);

    for (int i=0; i<8; i++)
        ck_assert_int_eq(da_insert(darr, &i, i, 0), AND_OK);

    int8_t get_max_num_elements = AND_OK;
    ck_assert_int_eq(da_getMaxNumElements(darr, &get_max_num_elements), AND_OK);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_getLoadFactor_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("GetLoadFactor");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_getLoadFactor__args__NULL__stat);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_getLoadFactor__args__darr__stat);
    tcase_add_test(tc_success, test_da_getLoadFactor__args__darr__stat__NON_DEFAULT);
    tcase_add_test(tc_success, test_da_getLoadFactor__args__darr__stat__RESIZE);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_insert(darrayptr_t, void*, size_t, size_t)]
// test: da_insert(NULL, element, 12, 0)
START_TEST(test_da_insert__args__NULL__element__12__0) {
    int element = -78;

    ck_assert_int_eq(da_insert(NULL, &element, 12, 0), AND_NOK);
} END_TEST

// test: da_insert(darr, NULL, 34, 0)
START_TEST(test_da_insert__args__darr__NULL__34__0) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    ck_assert_int_eq(da_insert(darr, NULL, 34, 0), AND_NOK);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_insert(darr, element, 46, 0)
START_TEST(test_da_insert__args__darr__element__46__0) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int element = -101;

    ck_assert_int_eq(da_insert(darr, &element, 46, 0), AND_OK);
    ck_assert_int_eq(and_getElement(da_get(darr, 46), int), element);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_insert(darr, element, 52, sizeof(char*))
START_TEST(test_da_insert__args__darr__element__52__sizeof_char_ptr) {
    darrayptr_t darr = da_create(0, sizeof(char*), 0, 0);

    char* str = "name is ....";

    ck_assert_int_eq(da_insert(darr, str, 52, strlen(str)+1), AND_OK);
    void* returned_str = and_getElement(da_get(darr, 52), char*);
    ck_assert_str_eq(returned_str, str);

    free(returned_str);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_insert_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Insert");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_insert__args__NULL__element__12__0);
    tcase_add_test(tc_failure, test_da_insert__args__darr__NULL__34__0);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_insert__args__darr__element__46__0);
    tcase_add_test(tc_success, test_da_insert__args__darr__element__52__sizeof_char_ptr);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_delete(darrayptr_t, size_t)]
// test: da_delete(NULL, 11)
START_TEST(test_da_delete__args__NULL__11) {
    ck_assert_ptr_null(da_delete(NULL, 11));
} END_TEST

// test: da_delete(darr, 78)
START_TEST(test_da_delete__args__darr__78) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    ck_assert_ptr_null(da_delete(darr, 78));

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_delete(darr, 99) -- INSERT 1, DELETE 1
START_TEST(test_da_delete__args__darr__99__INS_1_DEL_1) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int element = 45;
    ck_assert_int_eq(da_insert(darr, &element, 99, 0), AND_OK);
    ck_assert_ptr_nonnull(da_delete(darr, 99));
    ck_assert_ptr_null(da_delete(darr, 99));

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_delete(darr, 101) -- MEM ALLOCED
START_TEST(test_da_delete__args__darr__101__MEM_ALLOCED) {
    darrayptr_t darr = da_create(0, sizeof(char*), 0, 0);

    char* str = "test string";
    ck_assert_int_eq(da_insert(darr, str, 101, strlen(str)+1), AND_OK);
    
    void* returned_str = and_getElement(da_delete(darr, 101), char*);
    ck_assert_ptr_nonnull(returned_str);
    ck_assert_str_eq(returned_str, str);

    free(returned_str);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_delete_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Delete");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_delete__args__NULL__11);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_delete__args__darr__78);
    tcase_add_test(tc_success, test_da_delete__args__darr__99__INS_1_DEL_1);
    tcase_add_test(tc_success, test_da_delete__args__darr__101__MEM_ALLOCED);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_get(darrayptr_t, size_t)]
// test: da_get(NULL, 55)
START_TEST(test_da_get__args__NULL__55) {
    ck_assert_ptr_null(da_get(NULL, 55));
} END_TEST

// test: da_get(darr, 67)
START_TEST(test_da_get__args__darr__67) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    ck_assert_ptr_null(da_get(darr, 67));

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_get(darr, 100)
START_TEST(test_da_get__args__darr__100) {
    darrayptr_t darr = da_create(0, sizeof(char*), 0, 0);

    char* str = "test string";
    ck_assert_int_eq(da_insert(darr, str, 100, strlen(str)+1), AND_OK);
    
    void* returned_str = and_getElement(da_get(darr, 100), char*);
    ck_assert_ptr_nonnull(returned_str);
    ck_assert_str_eq(returned_str, str);

    free(returned_str);

    da_destroy(darr, AND_FALSE);
} END_TEST


Suite* da_get_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Get");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_get__args__NULL__55);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_get__args__darr__67);
    tcase_add_test(tc_success, test_da_get__args__darr__100);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_swap(darrayptr_t, size_t, size_t)]
// test: da_swap(NULL, 23, 56)
START_TEST(test_da_swap__args__NULL__23__56) {
    ck_assert_ptr_null(da_swap(NULL, 23, 56));
} END_TEST

// test: da_swap(darr, 60, 60)
START_TEST(test_da_swap__args__darr__60__60) {
    darrayptr_t darr = da_create(0, sizeof(char*), 0, 0);

    char* str = "test string";

    ck_assert_int_eq(da_insert(darr, str, 60, strlen(str)+1), AND_OK);

    void* returned_str = and_getElement(da_get(darr, 60), char*);
    ck_assert_ptr_nonnull(returned_str);
    ck_assert_str_eq(returned_str, str);

    free(returned_str);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_swap(darr, 127, 190)
START_TEST(test_da_swap__args__darr__127__190) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int element1 = 78, element2 = 87;
    ck_assert_int_eq(da_insert(darr, &element1, 127, 0), AND_OK);
    ck_assert_int_eq(da_insert(darr, &element2, 190, 0), AND_OK);

    void* element = da_swap(darr, 127, 190);
    ck_assert_ptr_nonnull(element);
    ck_assert_int_eq(and_getElement(element, int), element1);

    da_destroy(darr, AND_FALSE);
} END_TEST

// test: da_swap(darr, 255, 0)
START_TEST(test_da_swap__args__darr__255__0) {
    darrayptr_t darr = da_create(0, sizeof(char*), 0, 0);

    char *str1 = "test str1", *str2 = "test str2";
    ck_assert_int_eq(da_insert(darr, str1, 255, strlen(str1)+1), AND_OK);
    ck_assert_int_eq(da_insert(darr, str2, 0, strlen(str2)+1), AND_OK);

    void* str = and_getElement(da_swap(darr, 255, 0), char*);
    ck_assert_ptr_nonnull(str);
    ck_assert_str_eq(str, str1);

    free(str1);

    da_destroy(darr, AND_TRUE);
} END_TEST


Suite* da_swap_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Swap");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_swap__args__NULL__23__56);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_swap__args__darr__60__60);
    tcase_add_test(tc_success, test_da_swap__args__darr__127__190);
    tcase_add_test(tc_success, test_da_swap__args__darr__255__0);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


// ================================================================================================== [da_destroy(darrayptr_t, AND_BOOL)]
// test: da_destroy(NULL, AND_FALSE)
START_TEST(test_da_destroy__args__NULL__AND_FALSE) {
    ck_assert_int_eq(da_destroy(NULL, AND_FALSE), AND_NOK);
} END_TEST

// test: da_destroy(darr, AND_FALSE)
START_TEST(test_da_destroy__args__darr__AND_FALSE) {
    darrayptr_t darr = da_create(0, sizeof(int), 0, 0);

    int element = 101;
    ck_assert_int_eq(da_insert(darr, &element, 23, 0), AND_OK);
    element = 103;
    ck_assert_int_eq(da_insert(darr, &element, 67, 0), AND_OK);
    element = -90;
    ck_assert_int_eq(da_insert(darr, &element, 122, 0), AND_OK);

    ck_assert_int_eq(da_destroy(darr, AND_FALSE), AND_OK);
} END_TEST

// test: da_destroy(darr, AND_TRUE)
START_TEST(test_da_destroy__args__darr__AND_TRUE) {
    darrayptr_t darr = da_create(0, sizeof(char*), 0, 0);

    char *str1 = "one", *str2 = "two one", *str3 = "three one two";

    ck_assert_int_eq(da_insert(darr, &str1, 11, strlen(str1)+1), AND_OK);
    ck_assert_int_eq(da_insert(darr, &str2, 34, strlen(str2)+1), AND_OK);
    ck_assert_int_eq(da_insert(darr, &str3, 131, strlen(str3)+1), AND_OK);

    void* str = da_delete(darr, 34);
    ck_assert_ptr_nonnull(str);
    ck_assert_str_eq(and_getElement(str, char*), str2);
    ck_assert_ptr_null(da_delete(darr, 34));

    ck_assert_int_eq(da_destroy(darr, AND_TRUE), AND_OK);
} END_TEST


Suite* da_destroy_suite(void) {
    Suite* suite;
    TCase *tc_failure, *tc_success;

    suite = suite_create("Destroy");

    tc_failure = tcase_create("Failure");
    tcase_add_test(tc_failure, test_da_destroy__args__NULL__AND_FALSE);

    tc_success = tcase_create("Success");
    tcase_add_test(tc_success, test_da_destroy__args__darr__AND_FALSE);
    tcase_add_test(tc_success, test_da_destroy__args__darr__AND_TRUE);

    suite_add_tcase(suite, tc_failure);
    suite_add_tcase(suite, tc_success);

    return suite;
}

// ==================================================================================================


int main(int argc, char** argv) {
    int num_tests_failed;
    
    SRunner* suite_runner = srunner_create(da_create_suite());
    srunner_add_suite(suite_runner, da_getNumElements_suite());
    srunner_add_suite(suite_runner, da_getMaxNumElements_suite());
    srunner_add_suite(suite_runner, da_getElementSize_suite());
    srunner_add_suite(suite_runner, da_getGrowthFactor_suite());
    srunner_add_suite(suite_runner, da_getLoadFactor_suite());
    srunner_add_suite(suite_runner, da_insert_suite());
    srunner_add_suite(suite_runner, da_delete_suite());
    srunner_add_suite(suite_runner, da_get_suite());
    srunner_add_suite(suite_runner, da_swap_suite());
    srunner_add_suite(suite_runner, da_destroy_suite());

    if (argc == 1) {
        srunner_run_all(suite_runner, CK_NORMAL);
    } else if (argc >= 2) {
        srunner_run_tagged(suite_runner, argv[1], NULL, NULL, NULL, CK_NORMAL);
    }
    
    num_tests_failed = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (num_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}