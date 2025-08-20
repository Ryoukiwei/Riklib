#include <print>     //(C++23)
#include <array>     // For std::array
#include <algorithm> // std::fill, std::sort
#include <ranges>    // std::ranges::fill, std::ranges::sort (C++20)

int main()
{
    // ===== C-style array =====
    std::println("=== C-style array ===");

    // Initialize a C-style array
    int arr[] = {11, 22, 33, 44, 55};
    const size_t n = sizeof(arr) / sizeof(arr[0]);

    // Access each element with manual indexing
    for (size_t i = 0; i < n; ++i)
    {
        std::print("{} ", arr[i]);
    }
    std::println();

    // Modify element
    arr[2] = 77;

    for (size_t i = 0; i < n; ++i)
    {
        std::print("{} ", arr[i]);
    }
    std::println();

    // ===== C-style array (Pointer access) =====
    int *ptr = arr;
    for (size_t i = 0; i < n; ++i)
    {
        std::print("{} ", *(ptr + i)); // pointer arithmetic
    }
    std::println();

    // Traversing array using raw pointers (like STL iterators)
    for (int *p = arr; p != arr + n; ++p)
    {
        std::print("{} ", *p); // dereference pointer
    }
    std::println();

    // ===== C++ std::array =====
    std::println("\n=== std::array ===");

    // Declare and initialize a std::array with fixed size
    std::array<int, 5> a = {11, 22, 33, 44, 55};

    // Range-based for loop (more concise and safe)
    for (int x : a)
    {
        std::print("{} ", x);
    }
    std::println();

    // Modify elements with bounds checking
    // a[2] = 77;
    a.at(2) = 77; // Throws std::out_of_range if index is invalid

    for (int x : a)
    {
        std::print("{} ", x);
    }
    std::println();

    // STL-provided member functions
    std::println("Size: {}", a.size()); // Safer than sizeof
    std::println("First element: {}", a.front());
    std::println("Last element: {}", a.back());

    // Fill the entire array with a value
#if 1
    std::println("\n[std::fill]");
    a.fill(42);
#else
    std::println("\n[std::ranges::fill]");
    std::ranges::fill(a, 42);
#endif

    for (int x : a)
    {
        std::print("{} ", x);
    }
    std::println();

    // std::array supports iterators and standard algorithms
#if 1
    std::println("[std::sort]");
    std::sort(a.begin(), a.end());
#else
    std::println("[std::ranges::sort]");
    std::ranges::sort(a);
#endif

    for (int x : a)
    {
        std::print("{} ", x);
    }
    std::println();

    return 0;
}
