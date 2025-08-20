# Asymptotic Notation

為了評估資料量對執行時間的成長速率之影響，評估演算法時往往會用 asymptotic notation 表示。  
通常我們考慮的是當 $n$ 足夠大時，不同函數之間成長速率之關係。以資料量來說就是：當處理足夠大筆資料時，若 $A$ 演算法所需時間成長的比 $B$ 還要快，表示隨著資料量提升， $A$ 所需時間會比 $B$ 來得多，故我們會認定 $A$ 的效率比 $B$ 差。

許多人學完後會忘記，我們討論的往往是 $n$ 足夠大的情況。

本章節學起來比較數學，聽完覺得有些難懂的同學可以先記住上述意義。

## Definition

Let $f(n)$ and $g(n)$ be two functions that map positive integers to positive real numbers.

1. $\Theta (g(n)) = \{ f(n) | \exists c_1, c_2 \gt 0, \exists n_0 \gt 0, \forall n \ge n_0, 0\le c_1 g(n) \le f(n) \le c_2 g(n) \}$
2. $O(g(n)) = \{ f(n) | \exists c \gt 0, \exists n_0 \gt 0, \forall n \ge n_0, 0\le f(n) \le c g(n) \}$
3. $\Omega (g(n)) = \{ f(n) | \exists c \gt 0, \exists n_0 \gt 0, \forall n \ge n_0, 0\le c g(n) \le f(n) \}$
4. $o(g(n)) = \{ f(n) | \forall c \gt 0, \exists n_0 \gt 0, \forall n \ge n_0, 0\le f(n) \lt c g(n) \}$
5. $\omega (g(n)) = \{ f(n) | \forall c \gt 0, \exists n_0 \gt 0, \forall n \ge n_0, 0\le c g(n) \lt f(n) \}$