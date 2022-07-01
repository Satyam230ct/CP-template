# CP-template
Some Imp Points

a+b = (a XOR b) + (a AND b)*2

To erase dublicate in the vector efficient way->
sort( vec.begin(), vec.end() );
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
