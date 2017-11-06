## About
This program will take in the coefficient values _a_, _b_, and _c_ from a quadratic equation. It will then process and print out the roots _x1_ and _x2_. Along with this, it will watch out for special conditions such as when _a = 0_, when the roots are imaginary, and when there's one unique root. The program wil run using a command-line interface and will be programmed using the C language.
#### Stories
The input will be carefully checked to make sure that the coefficients _a_, _b_, and _c_ are all valid, single-precision floating point types. If it fails, the user will be prompted to enter new values for the coefficients.
 - **Risk**: low
 - **Time**: 2 Days
 - **Tests**: Test for buffer overflow, test if the input is a valid numeric type

This program will include logging where it record the trace of a program into a simple text file. Logging can be turned on and off. The trace of the program will include the file name, function name, and the arguments it was given.
 * **Risk**: low
 * **Time**: 1 Day
 * **Tests**: Test if it can be integrated into the other programs
___
The program will inform the user if precision has been lost using the quadratic solver.
 * **Risk**: high
 * **Time**: 1 Week
 * **Tests**: Test absolute and relative precision