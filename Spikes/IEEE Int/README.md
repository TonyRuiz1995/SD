# (int) IEEE-754 SPIKE
## About
The purpose of this spike is to test how some integer operations are handled in standard C.

## Information
#### Casting
    (int)nan = 0
    (int)inf = 2147483647
    (int)-inf = -2147483648
    (int)FLT_MAX = 2147483647
    (int)DBL_MAX = 2147483647

#### INT_MAX
    INT_MAX = 2147483647
    2147483647 + 1 = -2147483648
    -2147483647 - 1 = -2147483648
    -2147483647 - 2 = 2147483647
    2147483647 * 2147483647 = 1
    2147483647 / 2147483647 = 1
    1 / 0 = make: *** [run] Floating point exception: 8