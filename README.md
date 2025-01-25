# Hidden Pitfalls of std::vector<bool> in C++

This repository demonstrates a common, yet often overlooked, issue with `std::vector<bool>` in C++. While seemingly space-efficient, this specialization of the standard vector template can lead to performance degradation and subtle bugs due to its non-standard implementation involving proxy objects rather than direct boolean storage. The code illustrates how using `operator[]` directly can produce unintended consequences when modifying boolean values within the vector.

## Problem
`std::vector<bool>` is optimized for space, but this optimization comes at the cost of performance and potential unexpected behavior when elements are accessed and modified. It doesn't behave like a typical `std::vector`.  The `operator[]` doesn't return a reference to a boolean but a proxy object. Modifying this proxy object doesn't always directly modify the stored bool value, leading to errors.

## Solution
To avoid this issue, it's recommended to use `at()` or iterators instead of `operator[]` when accessing and modifying elements in `std::vector<bool>`.  Consider using `std::vector<char>` or `std::vector<int>` (with bit manipulation) if space optimization is not crucial but predictability and performance are important.
