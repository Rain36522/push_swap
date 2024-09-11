# push_swap
42 push_swap

This is my push_swap project from 42 school.

In this project, we need to sort a stack of numbers using only a few commands and two stacks.

## Main

In `main.c`, there are two main options:

### 1. For Testing
This option prints both stacks and allows you to run commands that will change the stack. It provides a better view of how the project works.

### 2. Using the Algorithm
The second option runs the program with my radix algorithm for sorting.

## Makefile

- **`make`**: Compiles the project.
- **`make clean`**: Removes the `objet` folder.
- **`make fclean`**: Runs `make clean` and removes the executable and the `libft` library.
- **`make re`**: Runs `make fclean` and then `make`.
- **`make check`**: Runs the program with arguments defined by the `INPUT` variable in the Makefile.
- **`make leak`**: Run the programme with leak commande.
- **`make header`**: Prints a decorative header.

## test.py

The `test.py` script generates a string of random integers, ensuring that no two runs have the same integers. You can use the output to replace the `INPUT` variable in the Makefile and run the tests with `make check`.
