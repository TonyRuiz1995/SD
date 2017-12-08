#include "output.h"
#include "../qsolve/qsolve.h"
#include "../validation/validate.h"
#include <fcntl.h>
#include <unistd.h>
#include <CUnit/Basic.h>
#define MERR 0.000001

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

// output
void test_output_zero_a_coefficient()
{
	double a, b, c, x1, x2;
	char outs[255];
	int status;
	a = 0; b = 1; c = 1;
	status = qsolve(a, b, c, &x1, &x2);
	output(status, x1, x2, outs);
	
	CU_ASSERT_EQUAL(status, 3);
	CU_ASSERT_STRING_EQUAL(outs, "a=0\n");
}

void test_output_imaginary_roots()
{
	double a, b, c, x1, x2;
	char outs[255];
	int status;
	a = 1; b = 1; c = 1;
	status = qsolve(a, b, c, &x1, &x2);
	output(status, x1, x2, outs);
	
	CU_ASSERT_EQUAL(status, 2);
	CU_ASSERT_STRING_EQUAL(outs, "Imaginary Roots!\n");
}

void test_output_single_root()
{
	double a, b, c, x1, x2;
	char outs[255];
	int status;
	a = 1; b = 2; c = 1;
	status = qsolve(a, b, c, &x1, &x2);
	output(status, x1, x2, outs);
	
	CU_ASSERT_EQUAL(status, 1);
	CU_ASSERT_STRING_EQUAL(outs, "x = {-1.000000}\n");
}

void test_output_double_root()
{
	double a, b, c, x1, x2;
	char outs[255];
	int status;
	a = 1; b = 0; c = -1;
	status = qsolve(a, b, c, &x1, &x2);
	output(status, x1, x2, outs);
	
	CU_ASSERT_EQUAL(status, 0);
	CU_ASSERT_STRING_EQUAL(outs, "x = {1.000000, -1.000000}\n");
}

// output_validation
void test_output_validation_valid_input()
{
	double a, b, c;
	char outs[255];
	char buff[50] = "1 2 3";
	int status = validate(buff, &a, &b, &c);
	output_validation(status, outs);
	
	CU_ASSERT_EQUAL(status, 0);
	CU_ASSERT_STRING_EQUAL(outs, "Input is valid.\n");
}

void test_output_validation_not_enough_numbers()
{
	double a, b, c;
	char outs[255];
	char buff[50] = "1 23";
	int status = validate(buff, &a, &b, &c);
	output_validation(status, outs);
	
	CU_ASSERT_EQUAL(status, 1);
	CU_ASSERT_STRING_EQUAL(outs, "Not enough numbers entered!\n");
}

void test_output_validation_not_all_inputs_numbers()
{
	double a, b, c;
	char outs[255];
	char buff[50] = "1 a 3";
	int status = validate(buff, &a, &b, &c);
	output_validation(status, outs);
	
	CU_ASSERT_EQUAL(status, 2);
	CU_ASSERT_STRING_EQUAL(outs, "Not all input are numbers!\n");
}

void test_output_validation_too_big_number()
{
	double a, b, c;
	char outs[255];
	char buff[1000];
	sprintf(buff, "%Lf 2 3", ((long double)DBL_MAX)*((long double)2));
	int status = validate(buff, &a, &b, &c);
	output_validation(status, outs);
	
	CU_ASSERT_EQUAL(status, 3);
	CU_ASSERT_STRING_EQUAL(outs, "Numbers are too big!\n");
}

int main ()
{
	log_start("TEST_OUTPUT", "output/test.c");
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
	 if((NULL == CU_add_test(pSuite, "test_output_zero_a_coefficient", test_output_zero_a_coefficient)) ||
	 	(NULL == CU_add_test(pSuite, "test_output_imaginary_roots", test_output_imaginary_roots)) ||
	 	(NULL == CU_add_test(pSuite, "test_output_single_root", test_output_single_root)) || 
	 	(NULL == CU_add_test(pSuite, "test_output_double_root", test_output_double_root)) ||


	 	(NULL == CU_add_test(pSuite, "test_output_validation_valid_input", test_output_validation_valid_input)) ||
	 	(NULL == CU_add_test(pSuite, "test_output_validation_not_enough_numbers", test_output_validation_not_enough_numbers)) ||
	 	(NULL == CU_add_test(pSuite, "test_output_validation_not_all_inputs_numbers", test_output_validation_not_all_inputs_numbers)) ||
	 	(NULL == CU_add_test(pSuite, "test_output_validation_too_big_number", test_output_validation_too_big_number))
	 	)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}


	// Output results using the basic interface
	CU_basic_set_mode(CU_BRM_SILENT);
   	
	// Surpress output from running tests
	int devNull = open("/dev/null", O_WRONLY);
	int sout = dup(1);
	dup2(devNull, 1);
   	CU_basic_run_tests();
   	dup2(sout, 1);
   	close(sout);
   	close(devNull);

   	if(CU_get_number_of_failures() > 0)
   	{
	   	printf("*********ERRR*********");
	   	printf("\nqsolve\n");
	   	CU_basic_show_failures(CU_get_failure_list());
	   	printf("\n**********************\n");
   	}

	// clean registry
	CU_cleanup_registry();

	return CU_get_error();
}
