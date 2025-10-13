#include <iostream>
#include <iomanip>
#include <cmath>
#include "Fixed.hpp"

// Color codes for better visibility
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;36m"
#define RESET "\033[0m"

// Test helper functions
bool floatCompare(float a, float b, float epsilon = 0.01f) {
    return std::fabs(a - b) < epsilon;
}

void printTestHeader(const std::string& testName) {
    std::cout << "\n" << BLUE << "=== " << testName << " ===" << RESET << std::endl;
}

void printResult(bool passed, const std::string& testName) {
    if (passed) {
        std::cout << GREEN << "[PASS] " << RESET << testName << std::endl;
    } else {
        std::cout << RED << "[FAIL] " << RESET << testName << std::endl;
    }
}

int main( void ) {
    int totalTests = 0;
    int passedTests = 0;
    
    // ==================== EXERCISE 00 TESTS ====================
    printTestHeader("EXERCISE 00: Orthodox Canonical Form");
    {
        Fixed a;
        Fixed b( a );
        Fixed c;
        c = b;
        
        bool test1 = (a.getRawBits() == 0);
        bool test2 = (b.getRawBits() == 0);
        bool test3 = (c.getRawBits() == 0);
        
        std::cout << "Raw bits - a: " << a.getRawBits() << std::endl;
        std::cout << "Raw bits - b: " << b.getRawBits() << std::endl;
        std::cout << "Raw bits - c: " << c.getRawBits() << std::endl;
        
        printResult(test1, "Default constructor initializes to 0");
        printResult(test2, "Copy constructor works correctly");
        printResult(test3, "Copy assignment operator works correctly");
        
        totalTests += 3;
        passedTests += (test1 + test2 + test3);
    }
    
    // ==================== EXERCISE 01 TESTS ====================
    printTestHeader("EXERCISE 01: Constructors and Conversions");
    {
        Fixed a;
        Fixed const b( 10 );
        Fixed const c( 42.42f );
        Fixed const d( b );
        a = Fixed( 1234.4321f );
        
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        
        // Test conversions
        bool test1 = floatCompare(a.toFloat(), 1234.43f, 0.1f);
        bool test2 = (b.toInt() == 10);
        bool test3 = floatCompare(c.toFloat(), 42.42f, 0.1f);
        bool test4 = (d.toInt() == 10);
        bool test5 = (a.toInt() == 1234);
        bool test6 = (c.toInt() == 42);
        
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
        
        printResult(test1, "Float to Fixed conversion (1234.4321f)");
        printResult(test2, "Int to Fixed conversion (10)");
        printResult(test3, "Float to Fixed conversion (42.42f)");
        printResult(test4, "Copy constructor preserves value");
        printResult(test5, "Fixed to Int conversion (1234)");
        printResult(test6, "Fixed to Int conversion (42)");
        
        totalTests += 6;
        passedTests += (test1 + test2 + test3 + test4 + test5 + test6);
    }
    
    // ==================== EXERCISE 02 TESTS ====================
    printTestHeader("EXERCISE 02: Increment/Decrement and Arithmetic");
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        
        std::cout << "Initial a: " << a << std::endl;
        
        // Test pre-increment
        Fixed preInc = ++a;
        std::cout << "After ++a: " << a << std::endl;
        bool test1 = floatCompare(a.toFloat(), 0.00390625f, 0.001f);
        bool test2 = floatCompare(preInc.toFloat(), 0.00390625f, 0.001f);
        
        // Test post-increment
        Fixed postInc = a++;
        std::cout << "After a++ (returned): " << postInc << std::endl;
        std::cout << "After a++ (a value): " << a << std::endl;
        bool test3 = floatCompare(postInc.toFloat(), 0.00390625f, 0.001f);
        bool test4 = floatCompare(a.toFloat(), 0.0078125f, 0.001f);
        
        // Test multiplication
        std::cout << "b (5.05f * 2): " << b << std::endl;
        bool test5 = floatCompare(b.toFloat(), 10.1f, 0.2f);
        
        // Test max
        Fixed maxResult = Fixed::max( a, b );
        std::cout << "max(a, b): " << maxResult << std::endl;
        bool test6 = floatCompare(maxResult.toFloat(), b.toFloat(), 0.001f);
        
        printResult(test1, "Pre-increment increases by epsilon (0.00390625)");
        printResult(test2, "Pre-increment returns incremented value");
        printResult(test3, "Post-increment returns original value");
        printResult(test4, "Post-increment increases value after return");
        printResult(test5, "Multiplication (5.05f * 2 ≈ 10.1)");
        printResult(test6, "max() returns larger value");
        
        totalTests += 6;
        passedTests += (test1 + test2 + test3 + test4 + test5 + test6);
    }
    
    // ==================== COMPARISON OPERATORS ====================
    printTestHeader("COMPARISON OPERATORS");
    {
        Fixed a( 10.5f );
        Fixed b( 5.25f );
        Fixed c( 10.5f );
        
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
        
        bool test1 = (a > b) == true;
        bool test2 = (a < b) == false;
        bool test3 = (a >= c) == true;
        bool test4 = (a <= c) == true;
        bool test5 = (a == c) == true;
        bool test6 = (a != b) == true;
        
        std::cout << "a > b: " << (a > b) << " (expected: 1)" << std::endl;
        std::cout << "a < b: " << (a < b) << " (expected: 0)" << std::endl;
        std::cout << "a >= c: " << (a >= c) << " (expected: 1)" << std::endl;
        std::cout << "a <= c: " << (a <= c) << " (expected: 1)" << std::endl;
        std::cout << "a == c: " << (a == c) << " (expected: 1)" << std::endl;
        std::cout << "a != b: " << (a != b) << " (expected: 1)" << std::endl;
        
        printResult(test1, "Greater than operator (>)");
        printResult(test2, "Less than operator (<)");
        printResult(test3, "Greater or equal operator (>=)");
        printResult(test4, "Less or equal operator (<=)");
        printResult(test5, "Equality operator (==)");
        printResult(test6, "Inequality operator (!=)");
        
        totalTests += 6;
        passedTests += (test1 + test2 + test3 + test4 + test5 + test6);
    }
    
    // ==================== ARITHMETIC OPERATORS ====================
    printTestHeader("ARITHMETIC OPERATORS");
    {
        Fixed a( 10.5f );
        Fixed b( 2.5f );
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        
        Fixed sum = a + b;
        Fixed diff = a - b;
        Fixed prod = a * b;
        Fixed quot = a / b;
        
        bool test1 = floatCompare(sum.toFloat(), 13.0f, 0.1f);
        bool test2 = floatCompare(diff.toFloat(), 8.0f, 0.1f);
        bool test3 = floatCompare(prod.toFloat(), 26.25f, 0.5f);
        bool test4 = floatCompare(quot.toFloat(), 4.2f, 0.1f);
        
        std::cout << "a + b = " << sum << " (expected: 13)" << std::endl;
        std::cout << "a - b = " << diff << " (expected: 8)" << std::endl;
        std::cout << "a * b = " << prod << " (expected: 26.25)" << std::endl;
        std::cout << "a / b = " << quot << " (expected: 4.2)" << std::endl;
        
        printResult(test1, "Addition operator (+)");
        printResult(test2, "Subtraction operator (-)");
        printResult(test3, "Multiplication operator (*)");
        printResult(test4, "Division operator (/)");
        
        totalTests += 4;
        passedTests += (test1 + test2 + test3 + test4);
    }
    
    // ==================== DECREMENT OPERATORS ====================
    printTestHeader("DECREMENT OPERATORS");
    {
        Fixed a( 5.0f );
        std::cout << "Initial a: " << a << std::endl;
        
        Fixed preDec = --a;
        std::cout << "After --a: " << a << std::endl;
        bool test1 = floatCompare(a.toFloat(), 4.996f, 0.01f);
        bool test2 = floatCompare(preDec.toFloat(), a.toFloat(), 0.001f);
        
        Fixed postDec = a--;
        std::cout << "After a-- (returned): " << postDec << std::endl;
        std::cout << "After a-- (a value): " << a << std::endl;
        bool test3 = floatCompare(postDec.toFloat(), 4.996f, 0.01f);
        bool test4 = floatCompare(a.toFloat(), 4.992f, 0.01f);
        
        printResult(test1, "Pre-decrement decreases by epsilon");
        printResult(test2, "Pre-decrement returns decremented value");
        printResult(test3, "Post-decrement returns original value");
        printResult(test4, "Post-decrement decreases value after return");
        
        totalTests += 4;
        passedTests += (test1 + test2 + test3 + test4);
    }
    
    // ==================== MIN/MAX FUNCTIONS ====================
    printTestHeader("MIN/MAX STATIC FUNCTIONS");
    {
        Fixed a( 10.5f );
        Fixed b( 20.75f );
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        
        Fixed minVal = Fixed::min(a, b);
        Fixed maxVal = Fixed::max(a, b);
        
        bool test1 = floatCompare(minVal.toFloat(), 10.5f, 0.1f);
        bool test2 = floatCompare(maxVal.toFloat(), 20.75f, 0.1f);
        
        std::cout << "min(a, b) = " << minVal << " (expected: 10.5)" << std::endl;
        std::cout << "max(a, b) = " << maxVal << " (expected: 20.75)" << std::endl;
        
        Fixed const c( 15.25f );
        Fixed const d( 8.5f );
        
        Fixed minConst = Fixed::min(c, d);
        Fixed maxConst = Fixed::max(c, d);
        
        bool test3 = floatCompare(minConst.toFloat(), 8.5f, 0.1f);
        bool test4 = floatCompare(maxConst.toFloat(), 15.25f, 0.1f);
        
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min(c, d) = " << minConst << " (expected: 8.5)" << std::endl;
        std::cout << "max(c, d) = " << maxConst << " (expected: 15.25)" << std::endl;
        
        printResult(test1, "min() with non-const references");
        printResult(test2, "max() with non-const references");
        printResult(test3, "min() with const references");
        printResult(test4, "max() with const references");
        
        totalTests += 4;
        passedTests += (test1 + test2 + test3 + test4);
    }
    
    // ==================== EPSILON VERIFICATION ====================
    printTestHeader("EPSILON VALUE VERIFICATION");
    {
        Fixed a( 1.0f );
        Fixed b = a;
        ++b;
        Fixed epsilon = b - a;
        
        bool test1 = floatCompare(epsilon.toFloat(), 0.00390625f, 0.0001f);
        bool test2 = (a < b);
        bool test3 = floatCompare(epsilon.toFloat(), 1.0f / 256.0f, 0.0001f);
        
        std::cout << "a = " << a << std::endl;
        std::cout << "a + epsilon = " << b << std::endl;
        std::cout << "epsilon value = " << epsilon << " (expected: 0.00390625)" << std::endl;
        std::cout << "1/256 = " << (1.0f / 256.0f) << std::endl;
        std::cout << "a < (a + epsilon): " << (a < b) << " (expected: 1)" << std::endl;
        
        printResult(test1, "Epsilon equals 0.00390625 (2^-8)");
        printResult(test2, "1 + epsilon > 1 verification");
        printResult(test3, "Epsilon equals 1/256");
        
        totalTests += 3;
        passedTests += (test1 + test2 + test3);
    }
    
    // ==================== FINAL SUMMARY ====================
    std::cout << "\n" << YELLOW << "========================================" << RESET << std::endl;
    std::cout << YELLOW << "          TEST SUMMARY" << RESET << std::endl;
    std::cout << YELLOW << "========================================" << RESET << std::endl;
    std::cout << "Total Tests: " << totalTests << std::endl;
    std::cout << GREEN << "Passed: " << passedTests << RESET << std::endl;
    std::cout << RED << "Failed: " << (totalTests - passedTests) << RESET << std::endl;
    
    float percentage = (static_cast<float>(passedTests) / totalTests) * 100.0f;
    std::cout << "Success Rate: " << std::fixed << std::setprecision(1) << percentage << "%" << std::endl;
    
    if (passedTests == totalTests) {
        std::cout << GREEN << "\n✓ ALL TESTS PASSED! ✓" << RESET << std::endl;
    } else {
        std::cout << RED << "\n✗ SOME TESTS FAILED ✗" << RESET << std::endl;
    }
    std::cout << YELLOW << "========================================" << RESET << std::endl;
    
    return 0;
}

