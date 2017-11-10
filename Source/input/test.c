#include "input.h"
#include <fcntl.h>
#include <unistd.h>
#include <CUnit/Basic.h>
#define MERR 0.000001

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void testPassInput()
{
	char buff[300];

	// Redirect input
	int testInput = open("testInput.txt", O_RDONLY);
	dup2(testInput, 0);

	input(buff);

	close(testInput);
	CU_ASSERT_STRING_EQUAL(buff, "12.323 3242.432 10E78 ");
}

int main ()
{
	log_start("TEST_INPUT", "input/test.c");
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
	 if ((NULL == CU_add_test(pSuite, "testPassInput", testPassInput)))
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
