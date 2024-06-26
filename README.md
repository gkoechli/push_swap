# push_swap
Sorting program that aims to sort an integer list with the least amount of manipulations between a set of pre-determined rules.

# Usage

Git clone the repository and cd into it. Then use make to compile.

Then run it with :

      ./push_swap numbers
  
numbers = list of integers seperated by white spaces, no duplicates. (for example: "10 9 8 7 6 5 4 3 2 1")

# Push_Swap Rules
The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

pa (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.

pb (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.

sa (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.

sb (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.

ss: sa and sb at the same time.

ra (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.

rb (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.

rr: ra and rb at the same time.

rra (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.

rrb (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.
