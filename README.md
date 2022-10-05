# Roots-of-Equation
INTRODUCTION:

Numerical root finding is one of the most important topics for several engineering specializations. specializations. The ever increasing development in technologies and computer sciences has led
us to engage in various numerical root finding methods to simulate important physical
phenomena in sciences, optimization and other similar fields of engineering like circuit analysis,
weather forecasting, mechanical motions and oscillations, and analysis of state equations for
real gases, let alone the useful applications in interesting scientific computations It is also used
in automatic control design as well as in solving optimization problems for machine learning.
Finding the roots of a mathematical equation is a specialized version of solving an equation. In
this project, we are going to solve the following root finding case:

                                𝑓(𝑥) = 𝑎𝑛𝑥^𝑛 + 𝑎𝑛−1𝑥^𝑛−1 + 𝑎𝑛−2𝑥^𝑛−2 + ⋯ + 𝑎1𝑥 + 𝑎0 = 0
                                
NUMERICAL ROOT FINDING METHOD: 

finding of the root concept in the first order polynomial equation where it works by finding the coefficient of the first-degree variable and the discriminant and the coefficients of the second degree variable and calculate it in the formula below where (a: is the coefficient of the second degree variable, b: is the first degree variable, c: is the constant and discriminant = b * b - 4 * a * c)
root1 = (-b + sqrt(discriminant)) / (2 * a);
it also calculates the complex roots through this formula
real Part = -b / (2 * a)
imaginary Part = sqrt(-discriminant) / (2 * a
where it gets the real part, and the imaginary part then concatenates the values
we split the higher order polynomial equation into two equations of a lower order equation then 
calculate the roots by the method of these lower order equation
