## The Extended Euclidean Algorithm

($\star$)   =  **Important**

Bezout's Theorem, which states that for any positive integers $ gcd(a_1, b_1) = 1$, there must exist a integer solution to the equation $a_1x + b_1y = 1$ can be extended by multiplying both sides with $m$ : $ma_1x + mb_1y = m$. Let $a_2 = ma_1$, and $b_2 = mb_1$, we get : $a_2x + b_2y = gcd(a_2, b_2)$, or in general form, 
$$
\forall a, b \in \N, \exists x, y \in \Z \ \textrm{such that}\ :\ ax + by = (a,b)
$$
To find such solution, realize that $(a, b) = (b, a \ \textrm{mod} \ b)$, which means that there also exist $(x', y')$ such that $bx' + (a \ \textrm{mod} \ b)y' = (a,b)$. Also, notice that $a \ \textrm{mod} \ b = a - \lfloor \frac{a}{b} \rfloor \cdot b$. 

After substitution, we get :
$$
bx' + (a - \lfloor \frac{a}{b} \rfloor \cdot b)y' = (a,b) n
$$
Rearrange it to :
$$
ay' + b(x' - y'\lfloor \frac{a}{b} \rfloor) = (a, b) = ax + by \ \ \ (\star)
$$
Which yields the result of $ x = y', y = x' - y'\lfloor \frac{a}{b} \rfloor$.

And since $gcd(a, 0) = a, $ then $(1, 0)$ is a solution when $b = 0$. This can be then used recursively, with (1, 0) as the base case, to update all other $(x, y)$ pairs.

Lastly, swap the values of $(x', y')$ and the final equation becomes $ x = x', y = y' - x'\lfloor \frac{a}{b} \rfloor$.

The substitution and rearrangement were the key steps, as it allowed the comparison of the two equations.

