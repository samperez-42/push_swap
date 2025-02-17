# What is Push_Swap?
Push_Swap is a 42 project that aims to teach students how to use algorithms by making a program designed for sorting numbers.  
  
The goal is to sort an unsorted list of numbers in ascending order, by using two piles, or *stacks* to do so.  
  
You need at least 84/100 to pass this challenge. To do so, your program needs to sort 100 numbers in less than 700 moves and sort 500 numbers in less than 5500 operations

## How to use this program
You need to compile with the Makefile
```Makefile
make
```
And then execute the program with the numeric parameters you want to sort
```c
./push_swap 3 2 1
```
or
```c
./push_swap "3 2 1"
```

## Operations available

| Operations | Explanation |
| :--- | :--- |
| sa | swap a - swap the first two elements on top of stack a.
| sb | swap b - swap the first two elements on top of stack b.
| ss | swap a and swap b at the same time. |
| pa | push a - takes the first element from stack b and places it on top of stack a. |
| pb | push b - takes the first element from stack a and puts it on top of stack b. |
| ra | rotate a - moves up all elements of the stack to one position, the first element becomes the last. |
| rb | rotate b - moves up all elements of stack b one position, the first element becomes the last one. |
| rr | ra and rb at the same time. |
| rra | reverse rotate a - moves down all elements of stack a one position, the last element becomes the first one.
| rrb | reverse rotate b - moves down all elements of stack b one position, the last element becomes the first one.
| rrr | rra and rrb at the same time. |

## What did I learn?
This project took me a while to get used to, but once I got the hang of operating with stacks, I flew through the project with little effort  
I learnt to better operate with pointers and structs thanks to this project.

## My algorithm
My algorithm uses a cost based system to check the number that requires the less amount of moves to push from one stack to the other, I took inspiration from [this site](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), which uses a similar method
