# push\_swap

## Introduction

The `push_swap` project is an algorithmic challenge from 42 School that focuses on sorting a stack of numbers using a limited set of operations. The goal is to implement an efficient sorting algorithm that minimizes the number of moves required to sort the stack.

## Features

- Efficient sorting of integer sequences using stack-based operations.
- Implementation of a custom sorting algorithm.
- Optimized move count to achieve the best possible performance.
- Supports various input sizes, from small sets to large stacks.

## Allowed Operations

The program utilizes the following stack operations:

- `sa` (swap a): Swap the first two elements of stack A.
- `sb` (swap b): Swap the first two elements of stack B.
- `pa` (push a): Move the top element from stack B to stack A.
- `pb` (push b): Move the top element from stack A to stack B.
- `ra` (rotate a): Shift all elements of stack A up by one position.
- `rb` (rotate b): Shift all elements of stack B up by one position.
- `rra` (reverse rotate a): Shift all elements of stack A down by one position.
- `rrb` (reverse rotate b): Shift all elements of stack B down by one position.

   

## Compilation and Usage

### Compilation

To compile the project, run:

```sh
make all
```

This generates the `push_swap` executable.

### Usage

Run the program with a sequence of numbers as arguments:

```sh
./push_swap 4 67 3 87 23
```

This will output the sequence of operations needed to sort the given numbers.

### Testing with `checker`

To validate the correctness of the sorting algorithm, you can use the `checker` program (if implemented):

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithm Overview

The sorting algorithm is designed to efficiently sort numbers using the given operations. The approach typically includes:

- Handling small sets (e.g., 3-5 numbers) with hardcoded optimal moves.
- Implementing an efficient sorting strategy such as:
  - **Cost-Based Sorting Algorithm**: Each potential move is assigned a cost based on its impact on sorting efficiency. The algorithm selects the most cost-effective move to minimize total operations.
  - **Greedy Approach**: Ensures the fastest path to sorting by prioritizing moves that result in the largest progress toward an ordered stack.
  - **Optimized Rotations**: The algorithm determines the optimal rotation strategy to align elements efficiently before performing swaps and pushes.

## Performance Optimization

- The program is designed to use the minimum number of operations for sorting.
- Advanced techniques like median selection and optimized pivot points are used.
- Benchmarking is done against 42's test cases to ensure efficiency.
