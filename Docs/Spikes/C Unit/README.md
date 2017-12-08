# C Unit Spike

### Notes
 - Tests are organized into suites, which are organized into a registry
 - Can run all suites/tests at once or each individually

##### Using the C Unit framework
 1. Write test functions
 2. Initialize the test registry
 3. Add suite(s) to the test registry
 4. Add test(s) to the suite(s)
 5. Run tests using the chosen interface
 6. Cleanup the registry

##### Test function
 - Test functions run the assertions
 - Assertions test a single condition
 - There are fatal versions of assertions, which aborts the test fucntion if it fails

##### Test Registry
 - It is the repository for suites and its tests
 - User needs to intialize the registry and clean up afterwards to avoid memory leaks. Cleanup must be the last CUnit function call

##### Suites
 - Tests that will run must be added to a suite that's registered w/ the test registry
 - The test registry must be initialized before adding a suite
 - CU_add_suite takes in initialization and cleanup functions as parameters. This allows the suite to set up and tear down temporary fixtures

 ##### Running Tests
  - CUnit/Automated.h: non-interactive; outputs to XML file
  - CUnit/Basic.h: non-interactive; outputs to stdout; can choose suites to run
  - CUnit/Console.h: interactive console interface
  - CUnit/Curses.h: interactive interface
  - CUnit/TestRun.h: used when the other interfaces are insufficient

### Further Reading
 - [CUnit Info](http://cunit.sourceforge.net/doc/introduction.html)
 - [Assertion Functions](http://cunit.sourceforge.net/doc/writing_tests.html)
 - [Test Interfaces](http://cunit.sourceforge.net/doc/running_tests.html)
 - [Simple CUnit Program](https://myembeddeddiary.wordpress.com/2016/03/28/how-to-write-your-first-cunit-test-program-a-basic-example/)
 - [Sample CUnit Program](http://cunit.sourceforge.net/screenshots.html)