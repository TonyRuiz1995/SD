#include <stdio.h>
#include <math.h>
#include <float.h>
#include <CUnit/Basic.h>
#define MERR 0.0001

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_sum()
{
	CU_ASSERT(5==3+2);	
}
void test_mult()
{
	CU_ASSERT_EQUAL(6, 3*2);
}
void test_mult_fail()
{
	int i = 5;
	CU_ASSERT_EQUAL(i, 3*2);	
}
void test_add_fail()
{
	CU_ASSERT_EQUAL(5, 3*2);
}
void test_dbl_func_assert()
{
	CU_ASSERT_EQUAL(0.3, 0.1+0.1+0.1);
	CU_FAIL("Automatic failure I added here");
}
void test_dbl_func_merr()
{
	CU_ASSERT_DOUBLE_EQUAL(0.3, 0.1+0.1+0.1, MERR);
}

int main ()
{
	CU_pSuite pSuite = NULL;

	// Initialize CUnit registry
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	// Add suite to registry
	pSuite = CU_add_suite("Test Suite", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	// Add test to registry
	 if ((NULL == CU_add_test(pSuite, "test_sum", test_sum)) ||
	 	(NULL == CU_add_test(pSuite, "test_mult", test_mult)) ||
	 	(NULL == CU_add_test(pSuite, "test_mult_fail", test_mult_fail)) ||
	 	(NULL == CU_add_test(pSuite, "test_add_fail", test_add_fail)) ||
	 	(NULL == CU_add_test(pSuite, "test_dbl_func_assert", test_dbl_func_assert)) ||
	 	(NULL == CU_add_test(pSuite, "test_dbl_func_merr", test_dbl_func_merr)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}


	// Output results using the basic interface
	CU_basic_set_mode(CU_BRM_SILENT);
   	CU_basic_run_tests();
   	printf("\nFailures:");
   	CU_basic_show_failures(CU_get_failure_list());
   	printf("\n");

	// clean registry
	CU_cleanup_registry();

	return CU_get_error();
}