# IEEE-754 SPIKE
#### Devloper(s)
- Apolinar Ortega

## About
The purpose of this spike is to test how some floating point operations are handled according to IEEE standards.

## Information
#### Basic Exceptions
 - Invalid Operation: returns NaN (ie. √-1)
 - Division By Zero: returns ±inf (ie. x/0, ln(0))
 - Overflow: returns ±inf
 - Underflow: occurs when the result of an operation is smaller in magnitude than the smallest value that can be stored in the format; returns denormalizd value by default; can return 0
 - Inexact: occurs when the rounded result is different from the precise result; returns rounded result by default
#### Handling Exceptions
 - Pre-substitution of user-deined variables
 - traps: exceptions that can affect the flow of control in some way
 - try/catch structures

## Output
##### *∞*
> inf - inf = nan
> inf / inf = nan
> 0.000000e+00 / inf = 0.000000e+00
> inf * -1.000000e+00 = -inf
> inf * 0.000000e+00 = nan
> inf * 2.000000e+00 = inf
##### *NaN*
> nan + inf = nan
> nan + 0.000000e+00 = nan
> nan * inf = nan
##### *Divide By 0*
> 1.000000e+00 / 0.000000e+00 = inf
> -1.000000e+00 / 0.000000e+00 = -inf
##### *DBL_MAX*
> DBL_MAX = 1.797693e+308
> 1.797693e+308 + 1.000000e+00 = 1.797693e+308
> 1.797693e+308 + 1.000000e+308 = inf
> -1.797693e+308 - 1.000000e+308 = -inf
> 1.797693e+308 * 0.000000e+00 = 0.000000e+00
##### *Underflow*
> 1.000000e+00 / 1.797693e+308 = 5.562685e-309
> 5.562685e-309 / 1.000000e+15 = 4.940656e-324
> 4.940656e-324 / 1.000000e+01 = 0.000000e+00
> 10e+309 = inf