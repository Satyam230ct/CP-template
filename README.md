# CP-template
Some Imp Points

a+b = (a XOR b) + (a AND b)*2

To erase dublicate in the vector efficient way->
sort( vec.begin(), vec.end() );
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );



The Inclusion-Exclusion Principle
bits(num1 OR num2) + bits(num1 AND num2) = bits(num1) + bits(num2)
-> https://leetcode.com/problems/number-of-excellent-pairs
