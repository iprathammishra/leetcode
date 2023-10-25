## Hash Table

A hash table is a data structure that allows for efficient storage and retrieval of key-value pairs. It uses a hash function to map keys to specific locations (buckets) in an array,where the corresponding values are stored. I'll break down the implementation into the following steps.

1. Chossing a Hash Function
2. Defining the Hash Table Data Strucuture. (items and table)
3. Inserting into the Hash Table.
4. Searching for Items in the Hash Table.
5. Handling Collisions.
6. Deleting from the Hash Table.

Main driver program is [here](main.cpp).

### Some Coding Questions

1. **Is Unique:** Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

2. **Check Permutation:** Given two strings, write a method to decide if one is a permutation of the other.

3. **URLify:** Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

Example:
Input: "Mr John Smith "
Output: "Mr%20John%20Smith"

4. **Palindrome Permutation:** Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the sae forwards and backwards. A permutation is a rearrangement of letter. The palindrome does not need to be limited to just dictonary words.

Example:
Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc.)

5. **One Away:** There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

Example:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false

6. **String Compression:** Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your methos should return the original string. You can assume the string has only uppercase and lowercase letters (a-z).

7. **Rotate Matrix:** Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

8. **Zero Matrix:** Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

9. **String Rotation:** Assume you have method isSubstring which checks if one word is a substring of another. Given two strings, S1 and S2, write a code to check if S2 is a rotation of S1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").

### Interview Questions

- [Fullstack](https://www.fullstack.cafe/blog/hash-tables-interview-questions)
- [Interviewprep](https://interviewprep.org/hash-table-interview-questions/#:~:text=Top%2025%20Hash%20Table%20Interview%20Questions%20and%20Answers,a%20language%20of%20your%20choice%3F%20...%20More%20items)
