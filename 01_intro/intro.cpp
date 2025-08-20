#include <print>
#include <vector>
#include <cmath>
#include <ranges>

namespace fib
{

    /**
     * @brief Compute the n-th Fibonacci number using naive recursion.
     *
     * This method is very inefficient (O(2^n)) and is only suitable for teaching recursion basics.
     *
     * @param n Index of the Fibonacci number (0-based).
     * @return The n-th Fibonacci number.
     */
    int naive(int n)
    {
        if (n < 0)
            throw std::invalid_argument("n must be non-negative");

        if (n <= 1)
            return n;
        return naive(n - 1) + naive(n - 2);
    }

    /**
     * @brief Compute the n-th Fibonacci number using tail recursion.
     *
     * @param n Index of the Fibonacci number (0-based).
     * @param a Value at position n-2 (default 0).
     * @param b Value at position n-1 (default 1).
     * @return The n-th Fibonacci number.
     */
    int tail(int n, int a = 0, int b = 1)
    {
        if (n < 0)
            throw std::invalid_argument("n must be non-negative");

        if (n == 0)
            return a;
        if (n == 1)
            return b;
        return tail(n - 1, b, a + b);
    }

    int memo_helper(int n, std::vector<int> &memo);
    /**
     * @brief Compute the n-th Fibonacci number using memoization (top-down DP).
     *
     * @param n Index of the Fibonacci number (0-based).
     * @return The n-th Fibonacci number.
     */
    int memo(int n)
    {
        if (n < 0)
            throw std::invalid_argument("n must be non-negative");

        std::vector<int> memo(n + 1, -1);
        return memo_helper(n, memo);
    }

    int memo_helper(int n, std::vector<int> &memo)
    {
        if (n <= 1)
            return n;
        if (memo[n] != -1)
            return memo[n];
        return memo[n] = memo_helper(n - 1, memo) + memo_helper(n - 2, memo);
    }

    /**
     * @brief Compute the n-th Fibonacci number using an iterative approach.
     *
     * Time complexity: O(n). Space complexity: O(1).
     *
     * @param n Index of the Fibonacci number (0-based).
     * @return The n-th Fibonacci number.
     */
    int iter(int n)
    {
        if (n < 0)
            throw std::invalid_argument("n must be non-negative");

        if (n <= 1)
            return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i)
        {
            int next = a + b;
            a = b;
            b = next;
        }
        return b;
    }

    /**
     * @brief Compute the n-th Fibonacci number using the closed-form expression.
     *
     * Note: This method uses floating-point operations and may be inaccurate for large n.
     *
     * @param n Index of the Fibonacci number (0-based).
     * @return The n-th Fibonacci number (rounded to nearest integer).
     */
    int formula(int n)
    {
        if (n < 0)
            throw std::invalid_argument("n must be non-negative");

        const double sqrt5 = std::sqrt(5.0);
        const double phi = (1.0 + sqrt5) / 2.0;
        const double psi = (1.0 - sqrt5) / 2.0;
        return static_cast<int>((std::pow(phi, n) - std::pow(psi, n)) / sqrt5 + 0.5);
    }

} // namespace fib

namespace fact
{
    int iter(int n)
    {
        if (n < 0)
            throw std::invalid_argument("n must be non-negative");

        int res = 1;
        for (int i = 2; i <= n; ++i)
            res *= i;
        return res;
    }

    int recur(int n)
    {
        if (n < 0)
            throw std::invalid_argument("n must be non-negative");

        return (n <= 1) ? 1 : n * recur(n - 1);
    }
}; // namespace fact

namespace prac
{
    /**
     * TODO: Write a recursive function to compute the binomial coefficient C(n, m).
     */
    int bin(int n, int m);

    /**
     * TODO: Write a recursive function to compute the greatest common divisor (GCD) of two integers.
     * Hint: Use the Euclidean algorithm.
     */
    int gcd(int a, int b);

    /**
     * TODO: Write a recursive function to compute x^n.
     * Challenge: Can you optimize your implementation to run in O(log n) time?
     * Hint: Use the technique of exponentiation by squaring.
     */
    int exp(int x, int n);

    // Advanced practices

    /** Print All Permutations of Data
     * TODO: Given a container of elements, print all permutations of the elements.
     *
     * @tparam Container A container type supporting random access iterators (e.g., std::vector, std::array).
     * @param data The container holding elements to permute.
     *
     * Hint: Use recursion and backtracking to generate permutations.
     */
    template <std::ranges::random_access_range Container>
    void perm(const Container &data);

}; // namespace prac

void test_fib(int n)
{
    std::println("Fibonacci Number Calculation Demo (n = {})", n);
    std::println("{:>20} | Result", "Method");
    std::println("---------------------+--------");

    std::println("{:>20} | {}", "Naive Recursive", fib::naive(n));
    std::println("{:>20} | {}", "Tail Recursive", fib::tail(n));
    std::println("{:>20} | {}", "Memoization", fib::memo(n));
    std::println("{:>20} | {}", "Iterative", fib::iter(n));
    std::println("{:>20} | {}", "Closed Formula", fib::formula(n));
}

void test_fact(int n)
{
    std::println("Factorial Calculation Demo (n = {})", n);
    std::println("{:>10} | Result", "Method");
    std::println("------------+--------");
    std::println("{:>10} | {}", "Iterative", fact::iter(n));
    std::println("{:>10} | {}", "Recursive", fact::recur(n));
}

int main()
{
    // test_fib(10);
    // test_fact(5);

    return 0;
}