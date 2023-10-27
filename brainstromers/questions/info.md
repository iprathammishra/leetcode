# Some along-the-way Questions.

### Why we use `nullptr` instead of `NULL`?

In modern C++, it's recommended to use `nullptr` instead of `NULL`or `0` for several reasons:

1. **Type Safety:** `nullptr` is a keyword that has a specific type - `nullptr_t`, whereas `NULL` or `0` are integer literals. This means `nullptr` is a type-safe and can be used with any pointer type, reducing the chances of type-related bugs.
2. **Avoid Ambiguity:** Using `0` or `NULL` can lead to ambiguity, as they could be interpreted as integers or pointers. `nullptr` explicitly represents a null pointer, making the code's intent clear.
3. **Compatibility:** `nullptr` is standard in C++11 and later, ensuring code compatilibity and readability across different compilers and C++ versions.

In short, use `nullptr` for improved type safety, clarity, and compatibility in modern C++ code.

### What is the difference between `implicit` and `explicit` in programming?

In programming, `implicit` and `explicit` refer to different ways of performing operations or type conversions:

1. **Implicit:** Implicit operations or type conversions happen automatically by the language or compiler without requiring explicit instructions from the programmer. For example, when you assign a smaller data type to a larger one (e.g., assigning an integer to a floating-point number), the conversion is done implicitly.
2. **Explicit:** Explicit operations or type conversions require specific instructions from the programmer to indicate their intent. This ensures clarity and precision. For example, in C++, you can use the `static_cast` keyword to explicitly convert one data type to another.

In short, `implicit` actions occur automatically, while `explicit` actions require deliberate programmer intervention for clarity and control.
