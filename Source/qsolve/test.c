#include "qsolve.h"
#include <CUnit/Basic.h>
#define MERR 0.000001

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_zero_a_ceoff()
{
	double a, b, c, x1, x2;
	int status;
	a = 0; b = 1; c = 1;
	status = qsolve(a, b, c, &x1, &x2);
	
	CU_ASSERT_EQUAL(status, 3);
}
void test_two_roots()
{
	double a, b, c, x1, x2;
	int status;
	a = 1; b = 0; c = -1;
	status = qsolve(a, b, c, &x1, &x2);
	
	CU_ASSERT_DOUBLE_EQUAL(x1, 1.0, MERR);
	CU_ASSERT_DOUBLE_EQUAL(x2, -1.0, MERR);
	CU_ASSERT_EQUAL(status, 0);
}
void test_one_root()
{
	double a, b, c, x1, x2;
	int status;
	a = 1; b = 2; c = 1;
	status = qsolve(a, b, c, &x1, &x2);
	
	CU_ASSERT_DOUBLE_EQUAL(x1, -1.0, MERR);
	CU_ASSERT_EQUAL(status, 1);
}
void test_imaginary_roots()
{
	double a, b, c, x1, x2;
	int status;
	a = 1; b = 1; c = 1;
	status = qsolve(a, b, c, &x1, &x2);
	
	CU_ASSERT_EQUAL(status, 2);
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
	 if ((NULL == CU_add_test(pSuite, "Test_Zero_a_Coeff", test_zero_a_ceoff)) ||
	 	 (NULL == CU_add_test(pSuite, "Test_Two_Roots", test_two_roots)) ||
	 	 (NULL == CU_add_test(pSuite, "Test_One_Root", test_one_root)) ||
	 	 (NULL == CU_add_test(pSuite, "Test_Imaginary_Roots", test_imaginary_roots)) )
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