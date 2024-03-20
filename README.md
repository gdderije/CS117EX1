# CS117EX1
Solutions to Quartic Equations

Consider the quartic equation

ax^4 + bx^3 + cx^2 + dx + e = 0,
where a, b, c, d, e are given real numbers with a != 0.

Step 1. As a first step, let us make the polynomial monic, that is, the coefficient of
the leading term must be equal to one. To do this, we simply divide both sides of the
equation by a to obtain the equivalent equation

x^4 + Ax^3 + Bx^2 + Cx + D = 0, (1)
where A = b/a, B = c/a, C = d/a, and D = e/a.

Step 2. Introduce the new variable y = x − k, so that x = y + k. By substituting
this equation in (1), expanding the powers, combining like terms, one can deduce the
following equation:

y^4 + J(k)y^3 + P(k)y^2 + Q(k)y + R(k) = 0, (2)
where J(k) = 4k + A, P(k) = 6k^2 + 3Ak + B, Q(k) = 4k^3 + 3Ak^2 + 2Bk + C and R(k) = k^4 + Ak^3 + Bk^2 + Ck + D. Let us chose k = −A/4 = −b/4a so that J(k) = J(−A/4) = 0.
For this value of k, the other coefficients in (0.7) can be expressed according to

![image](https://github.com/gdderije/CS117EX1/assets/71222985/13d12614-ad37-44eb-8117-19e508298f1c)


If q = 0, then (2) reduces to the quadratic equation y^4 + py2 + r = 0 in y^2, and therefore, in this case, the solutions are given by

![image](https://github.com/gdderije/CS117EX1/assets/71222985/db18c3dc-2aeb-4dc9-a43a-9a16fd48d207)


Step 3. Now, let us consider the case where q 6= 0. Given a fixed parameter β, (2) is
equivalent to the equation y^4 + (p + β)y^2 − βy^2 + qy + r = 0.

Completing the squares on the right hand side of this equation, we have

![image](https://github.com/gdderije/CS117EX1/assets/71222985/e3f62d54-20e0-4e65-ad09-52430561f7c9)

The right hand side is zero precisely when β is a solution of the cubic equation

β^3 + 2pβ2 + (p^2 − 4r)β − q^2 = 0,

and in this case, we obtain by taking square roots and rearranging the terms that

![image](https://github.com/gdderije/CS117EX1/assets/71222985/666c009a-2ebb-4bce-8ac0-4a567f94daca)

Note that β != 0 since q != 0.

Step 4. Using the quadratic formula, and recalling that x = y − b/4a, it follows that the solutions of (1) are, using the plus sign:

![image](https://github.com/gdderije/CS117EX1/assets/71222985/1f2d74a5-7e27-4e89-9e1b-7155ebd33ee3)


or using the minus sign:

![image](https://github.com/gdderije/CS117EX1/assets/71222985/07a5f0bc-8e83-4f03-b4a8-b51a86526292)

Note that the calculation of β can be carried out using Cardano’s formula.
