# Numerical Methods and Big Integer Arithmetic

## Overview

This repository contains educational C++ projects focused on numerical computation and arbitrary-precision arithmetic.

The projects demonstrate the implementation of mathematical algorithms without relying on built-in high-level arithmetic functions and data types.

## Projects

### 1. Sine Approximation Using Taylor Series

Implementation of the sine function using its Taylor series expansion.

#### Features

* Calculation of `sin(x)` with user-defined precision
* Iterative computation of series terms
* No direct factorial calculation
* No direct exponentiation of `x`
* Each term is computed from the previous one using a recurrence relation
* Comparison with the standard library `sin()` function

#### Mathematical Concepts

* Taylor series
* Numerical approximation
* Floating-point precision
* Error analysis

---

### 2. Arbitrary-Precision Integer Arithmetic

Implementation of operations on very large integers using linked lists.

#### Features

* Input numbers as strings
* Support for numbers containing hundreds of digits
* Splitting numbers into groups of nine digits
* Storage of groups in linked list nodes
* Addition of large integers
* Subtraction of large integers
* Multiplication of large integers
* Input validation and error handling

#### Example

```text
134557952499317879
79349864365110

Result:
134637302363682989
```

#### Data Structures

* Singly linked lists
* Custom node structures
* Manual carry and borrow handling

## Technologies

* C++
* Linked Lists
* Numerical Methods
* Arbitrary-Precision Arithmetic
* Dynamic Memory Management

## Learning Objectives

This repository demonstrates:

* Series-based function approximation
* Working with numerical precision
* Implementation of large-number arithmetic
* Custom data structures
* String processing and parsing
* Dynamic memory allocation

## Compilation

Compile using a standard C++ compiler:

```bash
g++ main.cpp -o program
./program
```

## Author

Educational projects developed for studying numerical methods, data structures, and algorithm implementation in C++.
