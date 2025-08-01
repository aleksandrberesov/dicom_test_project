A simple code to solve this task:   
Write a console application that includes the following entities:

A - a class that stores a real vector of dimension 3 and provides effective concurrent access to it, the initial value is (0.0, 0.0, 0.0)

B - a class that monitors the state of the vector module from A N times per second and, if the value of the vector module falls within the specified interval <L1, L2> inclusive,
prints the vector in the console window

C - a class that changes the contents of the components of vector A randomly in the range of 0..100 each M times per second

the code of classes A, B and C is executed in independent threads

in total, when the program starts, we have 5 threads with code B and 2 with code C, class A in a single instance

the values of N, M, L1, L2 are generated randomly and are transmitted during the initialization of each copy of the class, respectively, to whomever needs what

it is known that N is a minimum of 1000 and a maximum of 10000

M - minimum 10 and maximum 100

L1 and L2 are in the range from 1 to 200, the minimum difference between them is 20

maximum program execution time is 60 seconds

implementation using STL tools version C++17
