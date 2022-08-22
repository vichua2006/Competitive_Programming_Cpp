## The Chinese Remainder Theorem

The theorem states that given $k$ integers $m_1, m_2, ... , m_k$ and $a_1, a_2, ..., a_k$ where $ \forall 1 \leq i,j \leq k, \ gcd(a_i, a_j) = 1$ ($m$'s are pair-wise coprime), there must exist a solution to the equation :
$$
x \equiv m_1 (\textrm{mod} \ a_1) \equiv m_2 (\textrm{mod} \ a_2)\equiv ...\equiv m_k (\textrm{mod} \ a_k)
$$
**Proof:**

First, let us only consider $k = 2$.

Therefore, in terms of $a_1$, $x$ could be expressed as $m_1, a_1 + m_1, 2a_1 + m_1, ...,(a_2 - 1)a_1 + m_1, a_2a_1 + m_1,...$ and so on.

Realize that $m_1, a_1 + m_1, 2a_1 + m_1, ..., (a_2 - 1)a_1 + m_1$ forms a complete residue system mod $a_2$ (because $gcd(a_1, a_2) = 1$). In other words, 
$$
\forall i \not\equiv j \ (\textrm{mod} \ a_2), ia_1 + m_1 \not= ja_1 + m_1.
$$
This means that these $a_2$ numbers must be congruent to $0, 1, 2, ..., a_2 - 1$ in some order, which means that, $\forall m_2$ there must exists an integer $p$ such that $x = pa_1 + m_1 \equiv m_2 \ (\textrm{mod} \ a_2)$. Thus, $x$ must exist. 