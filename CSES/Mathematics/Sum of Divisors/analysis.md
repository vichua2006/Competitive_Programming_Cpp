instead iterating from 1 to $n$ and getting a definite TLE, we can approach it from the perspective of the divisors.

for each divisor $k$, we can compute how many numbers has such a divisor. This number is equal to $\lfloor \frac{n}{k} \rfloor$.

Thus, have to compute $\sum_{k=1}^{n} \lfloor \frac{n}{k} \rfloor \ (\textrm{mod 1e9 + 7} )$. However, this still TLEs. 

The next optimization was also used in CCC 2018 S4: Balanced Trees. It states that there are only $2\cdot\sqrt{n}$ distinct numbers in the form $\lfloor \frac{n}{k} \rfloor$. For specific examples or more detailed (not really) explanation, refer to the comments in the code for that problem. For any $j = \lfloor \frac{n}{k} \rfloor$, there are $\lfloor \frac{n}{j} \rfloor - \lfloor \frac{n}{j + 1} \rfloor$ values of $k$ that will produce the same $j$. In other words, let $k_x = \lfloor \frac{n}{j} \rfloor$ and $k_y = \lfloor \frac{n}{j + 1} \rfloor$, then $\forall k_y < k \leq k_x, j = \lfloor \frac{n}{k} \rfloor$. The sum of these $k_x - k_y$ factors equals :
$$
j \cdot (k_x + (k_x - 1) +...+(k_y + 1)) = j \cdot (\frac{(k_x + k_y + 1)(k_x - k_y)}{2}) = \frac{1}{2}j(k_x + k_y + 1)(k_x - k_y)
$$
The $\frac{1}{2}$ is not that problematic, as we only need to find its inverse, which exists because 1e9 + 7 is prime.