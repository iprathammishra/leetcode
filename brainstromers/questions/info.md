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

### Why do we use `&` and `const` with `string` datatype as a paramter in some methods in C++?

Using `&` and `const` with the `string` datatype as parameters in C++ methods is an important practice for optimizing performance and ensuring the safety of your code. Let's discuss this in the context of a potential interview question:

**Interviewer:** Can you explain why we often use `&` and `const` with `string` datatype as parameters in C++ methods?

**You:** Certainly. Using `&` and `const` with `string` datatype in C++ is a good practice for several reasons:

1. **Passing by Reference (`&`)**

- When we use `&`, we are passing the string parameter by reference, which means that we are not making a copy of the string when the function is called. This can significantly improve performance, especially for large strings, because copying a string can be computationally expensive.

2. **`const` Qualifier:**

- The `const` keyword is used to indicate that the function does not modify the string passes as a paramter. This is an important aspect of code safety and clarity.
- Using `const` prevents accidental modification of the input string within the function. It's a way of expressing the function's intent and ensuring that the function behaves as expected without altering the caller's data.

3. **Efficiency:**

- Using `const` with string parameters is not just about safety; it can also enable certain optimizations by the C++ compiler. The compiler knows that the function won't modify the string, so it can make certain assumptions and apply optimizations accordingly.

4. **Compatibility:**

- Functions that accept `const` references as parameters can be called with both constant (read-only) and non-constant (modifiable) strings. This allow you to use the same function for various scenarios without having to create multiple overloads.

Here's an example to illustrate the use of `&` and `const` with `string` parameters:

```cpp
void processString(const std::string& str) {
    // This function takes a constant reference to a string, indicating that it won't modify the input string.
    // It's safe and efficient for processing strings.
    // ...
}

int main() {
    std::string text = "Hello, World!";
    const std::string readOnlyText = "This is read-only.";

    processString(text);          // OK to pass a non-constant string.
    processString(readOnlyText);  // OK to pass a constant (read-only) string.

    return 0;
}
```

In this example, `processString` takes a `const` reference to a string, allowing you to pass both non-constant and constant strings to the function while ensuring safety and efficiency. It also communicates the intent that the function doesn't modify the input string.
