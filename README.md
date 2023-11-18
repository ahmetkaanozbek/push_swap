# push_swap
Summary:
"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting."


 This project is one of the 42 Curcus projects. It aims to sort integers with limited set of instructions. Instructions are defined by the <a href="en.subject.pdf">subject.pdf.</a> This program uses radix algorithm
to correctly sort the integers. The traditional form of radix algorithm has linear time complexity. It can be expressed like this: O(nk). 'k' stands for the average number of digits in the elements. The reason for that is the radix algorithm sorts numbers based on their digits. To understand radix algortihm in a more detailed way one can click <a href="https://www.geeksforgeeks.org/radix-sort/">here.</a> However, in this project instructions says there could be only 2 stacks to store the digits. To sort the 10 base numbers with using radix algortihm there should be 10 stacks which means there should be one stack for every digit. Therefore, with 2 stacks radix algorithm can't be used for 10 base numbers. To overcome that problem and to apply the rules of instructions 10 base numbers should be treated as binary numbers. With this solution, 1s and 0s of a binary number can be stored in two stacks.

 Firstly, the program converts the given command line arguments to array of integers. If there is any illegal arguments or illegal form of arguments the program should display "Error\n" in stderr. Arguments like this will be considered legal: 1, 2, "+4, 3, -2" or 4 0 3 1 -21. To be informed in a more detailed way about legal and illegal arguments: <a href="en.subject.pdf">subject.pdf.</a> After adding all numbers of the given argument to an integer array, the program creates an integer array of the sorted position of all integers. For example, if the numbers are: 1, 9, -4, 3, 8 the sorted positions of the numbers are: 1, 4, 0, 2, 3. Position numbers, starting from zero, are positive numbers due to not deal with the two's complement. After that, a linked list is created to create a stack. Then, radix algortihm is used with the several actions, which is defined by the <a href="en.subject.pdf">subject.pdf</a>, to sort them in ascending order. It is important to note that the program doesn't convert 10 base numbers to binary numbers, it uses bitwise operations to treat them as binary numbers. Also, the program should apply the rule of limited number of actions. For 100 random numbers, the number of the actions shouldn't exceed 1500 and for 500 random numbers it is 11500. However, for 5 and less random values radix algorithm exceed the limit of actions. Therefore, the program uses a custom algorithm to apply the rule of limited actions. To understand the what are these instruction-defined actions are click <a href="en.subject.pdf">here.</a>
 
After cloning the repo, one can execute ```make``` command inside of the project folder to build the program. After building it, one can run the program applying this blueprint ```./push_swap random numbers``` For example: ```./push_swap 1 0 3 -99 878 -45``` or ```./push_swap 2 "+4 3 9 -100" 98 "-32 -31"``` . Executing these commands will show the list of the actions executed by the program to sort the numbers. To find the numbers of the actions which is executed by the program: ```./push_swap 1 0 3 -99 878 -45 | wc -l```. If there is any illegal arguments or illegal form of arguments the program will display ```Error\n``` stderr. Also, to check if the stack is sorted correctly, checker_Mac could be used like this: ```./push_swap 1 0 3 -99 878 -45 | ./checker_Mac 1 0 3 -99 878 -45```. If it is sorted in ascending order the output will be ```OK``` if it isn't sorted correctly it will be ```KO```.

To get more detail about the project: <a href="en.subject.pdf">subject.pdf</a>
