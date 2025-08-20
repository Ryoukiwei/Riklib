#include <print>
#include <vector>

int main()
{
    std::println("=== C-style Dynamic Array ===");

    const size_t n = 5;

    // Manually allocate memory for the array
    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = i * 10;
    }

    for (int i = 0; i < n; ++i)
    {
        std::print("{} ", arr[i]);
    }
    std::println();

    // IMPORTANT!!!
    // Deallocate memory to avoid memory leak
    delete[] arr;

    std::println("\n=== std::vector ===");

    /**
     * std::vector automatically manages memory, supports resizing,
     * and is the preferred dynamic array type in modern C++.
     * */
    std::vector<int> vec = {0, 10, 20, 30, 40};
    // Range-based loop
    for (int x : vec)
    {
        std::print("{} ", x);
    }
    std::println();

    vec.push_back(50);
    vec.push_back(60);

    for (int x : vec)
    {
        std::print("{} ", x);
    }
    std::println();

    std::println("Size: {}", vec.size());
    std::println("Capacity: {}", vec.capacity()); // Number of elements the vector can currently hold without resizing.
    std::println("First: {}", vec.front());
    std::println("Last: {}", vec.back());

    vec.at(2) = 77; // Throws std::out_of_range if index is invalid (out of bounds)
    std::println("Modified 3rd element: {}", vec[2]);

    return 0;
}