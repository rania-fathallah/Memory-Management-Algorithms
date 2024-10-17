
# Memory Management Algorithms

This project was created as part of an operating systems course during the first year of engineering. It implements various memory management algorithms for page replacement, including FIFO, LRU, LFU, and Second Chance algorithms. The code is structured across multiple C files and is compiled using a Makefile.

## Project Structure

```
.
├── FIFO.c
├── LFU.c
├── LRU.c
├── Second_Chance.c
├── main.c
├── Makefile
├── Memoire.h
```

- **FIFO.c**: Implements the FIFO (First-In-First-Out) page replacement algorithm.
- **LFU.c**: Implements the LFU (Least Frequently Used) page replacement algorithm.
- **LRU.c**: Implements the LRU (Least Recently Used) page replacement algorithm.
- **Second_Chance.c**: Implements the Second Chance page replacement algorithm.
- **main.c**: Contains the main program and allows the user to choose the desired algorithm for simulation.
- **Memoire.h**: Header file containing the structure definitions and function prototypes.
- **Makefile**: Makefile for building the project.

## Compilation and Execution

To compile the project, use the `Makefile`:
```bash
make
```

This will compile all the source files and generate an executable.

To run the program, execute:
```bash
./remp
```

Replace `program_name` with the name of the compiled executable.

## Program Usage

1. **Specify the Number of Frames**: The program will prompt you to enter the number of page frames.
2. **Input Pages to Reference**: The program will prompt you to enter the number of pages and their values.
3. **Select an Algorithm**: Choose one of the following algorithms:
   -  1 : FIFO
   -  2 : LRU
   -  3 : LFU
   -  4 : Second Chance

The program will then simulate the chosen algorithm and display the page frames' status and the number of page faults.

## Cleaning Up

To clean up the compiled files, use:
```bash
make clean
```

This will remove the executable and any object files.
