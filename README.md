# C++ Multithreaded Primality
This is a somewhat simple C++ application. It utilizes OpenMP to calculate primality. The advantage to 
calculating in parallel allows the primality determination of large numbers.

Once the program is compiled, pass in a comma separated list of numbers as an argument. An example of how the arg would look is: 3,5,7,2104234,
2100971,146897832178324.

The output will display in the console in the following format:
num : prime/not prime
