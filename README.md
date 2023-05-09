# Push Swap

Push Swap is a program that sorts a stack of integer numbers using two stacks and a set of allowed operations.

## How to use

### Compilation

To compile the program, run the following command:

```
make
```

### Execution

To run the program, execute the following command:

```
./push_swap [integer list]
```

where `[integer list]` is a list of integer numbers separated by spaces.

The program will output a list of instructions that will sort the integer list.

## Operations

The following operations are allowed:

- **sa** : swap the first two elements of stack A
- **sb** : swap the first two elements of stack B
- **ss** : sa and sb at the same time
- **pa** : take the first element from stack B and put it at the top of stack A
- **pb** : take the first element from stack A and put it at the top of stack B
- **ra** : shift up all elements of stack A by 1. The first element becomes the last one.
- **rb** : shift up all elements of stack B by 1. The first element becomes the last one.
- **rr** : ra and rb at the same time.
- **rra** : shift down all elements of stack A by 1. The last element becomes the first one.
- **rrb** : shift down all elements of stack B by 1. The last element becomes the first one.
- **rrr** : rra and rrb at the same time.

## Example

```
$> ./push_swap 2 1 3 6 5 8 7 4
pb
ra
pb
ra
pb
rra
pa
ra
pa
ra
ra
```
## Sorting Types

### Size 2

When the size of the stack is 2, there are only two possible combinations: the stack is already sorted, or the elements are in the wrong order. In the latter case, we can simply swap the two elements using the `sa` operation.

### Size 3

The sort of size 3 is a bit more complex, but still relatively simple. We start by finding the smallest number and moving it to the top of the stack. Then, we check if the two remaining numbers are in order. If they are, we're done. If not, we perform a sequence of moves to sort them.

1. Find the smallest number in the stack and move it to the top using either `sa` or `ra` move.
2. Check if the two remaining numbers are in order (i.e. if `a[1]` is smaller than `a[2]`). If they are, we're done. If not, perform the following sequence of moves:
    1. If the largest number is on top, rotate the stack (`ra`).
    2. Swap the top two numbers (`sa`).
    3. Rotate the stack back to its original position (`rra`).

By carefully following these steps, we can sort a stack of size 3 using a relatively small number of moves. While the algorithm may seem complex at first, with some practice, it becomes relatively easy to implement and use in practice.

### Above size 3

The algorithm begins with the calculation of the moves required to move each element of stack B to stack A, using two variables `mv_a` and `mv_b`. These variables are calculated as follows:
- `mv_b` is the number of moves required to move an element from its current position to the top of stack B, either by rotating to the right or to the left, whichever is the shortest.
- `mv_a` is the number of moves required to move an element from the top of stack B to its correct position in stack A, considering the elements that are already sorted in stack A.

After calculating `mv_a` and `mv_b` for each element in stack B, the algorithm finds the element that requires the least amount of moves to be moved to stack A. Once this element is found, the algorithm rotates stack A and stack B accordingly, using the variables `mv_a` and `mv_b`, to move this element to its correct position in stack A.

To rotate stack A and stack B, there are four functions:
- **reverse_both:** rotates both stack A and stack B in the opposite direction until both `mv_a` and `mv_b` are zero or positive.
- **rotate_both:** rotates both stack A and stack B in the same direction until both `mv_a` and `mv_b` are zero or negative.
- **rotate_a:** rotates stack A in the direction required to make `mv_a` zero.
- **rotate_b:** rotates stack B in the direction required to make `mv_b` zero.

Before starting the sorting algorithm, the function `where_fit_in_a` is called to calculate the position of each element in stack B in stack A. This function finds the position of each element in stack A where the element from stack B should be inserted, considering the elements that are already sorted.

After sorting each element in stack B, there may be elements that are not in their correct positions in stack A, because they were already sorted when they were inserted in stack B. Therefore, a function `last_rotates` is called to rotate stack A to put these elements in their correct positions.

This algorithm is an improvement over the basic sorting algorithm for size 3 or more, because it considers the positions of the elements in stack A to move the elements from stack B to stack A in the most efficient way.

## Grade: 100 / 100

## Used Tests
- Push-Swap-Tester: https://github.com/gemartin99/Push-Swap-Tester
-  push_swap_visualizer: https://github.com/o-reo/push_swap_visualizer