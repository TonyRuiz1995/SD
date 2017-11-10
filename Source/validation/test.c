#include "validate.h"
#include <CUnit/Basic.h>
#define MERR 0.000001

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_pass()
{
	int status;
	double  a, b, c;
	char buff[1000] = "1.2 2 3";
	status  = validate(buff, &a, &b, &c);
	CU_ASSERT_EQUAL(status, 0);
	CU_ASSERT_DOUBLE_EQUAL(a, 1.2, MERR);
	CU_ASSERT_DOUBLE_EQUAL(b, 2, MERR);
	CU_ASSERT_DOUBLE_EQUAL(c, 3, MERR);
}

void test_double_overflow()
{
	int status;
	double a, b, c;
	char buff[1000];
	sprintf(buff, "%Lf 2 3", ((long double)DBL_MAX)*((long double)2));
	status  = validate(buff, &a, &b, &c);
	CU_ASSERT_EQUAL(status, 3);
}

void test_non_numeric()
{
	int status;
	double  a, b, c;
	char buff[1000] = "1 a 3";
	status  = validate(buff, &a, &b, &c);
	CU_ASSERT_EQUAL(status, 2);
}

void test_less_input()
{
	int status;
	double  a, b, c;
	char buff[1000] = "1 123";
	status  = validate(buff, &a, &b, &c);
	CU_ASSERT_EQUAL(status, 1);
}

int main ()
{
	log_start("TEST_QSOLVE", "qsolve/test.c");
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
	if ((NULL == CU_add_test(pSuite, "test_pass", test_pass)) ||
		(NULL == CU_add_test(pSuite, "test_double_overflow", test_double_overflow)) ||
		(NULL == CU_add_test(pSuite, "test_non_numeric", test_non_numeric)) ||
		(NULL == CU_add_test(pSuite, "test_less_input", test_less_input))  )
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
