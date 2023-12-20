# Tiling Combinations

IST Analysis and Synthesis of Algorithms first course project, 2022/2023. Prints the number of different square tile combinations that can cover a specific area.

--------------------------------

## The Goal

The objective is to tile a given area defined over a rectangle, delimited by a staircase path, as illustrated below. The area to be tiled is defined over a unitary grid, with _n_ rows and _m_ columns. The tiles to be used are always squares with integer side dimensions, such as 1 × 1, 2 × 2, etc.

<p align="center">
  <img width="300" src="https://github.com/TiDeane/Tiling-Combinations/assets/120483063/0e125ac6-2e44-4549-8b05-bc66e44a8bfe">
</p>

Considering you can use an arbitrary number of square tiles of various dimensions, there are several possible tile configurations that allow you to completely cover the area in question. In the example illustrated above, there are 4 possible configurations for tiling the area: one configuration using only 1 × 1 tiles, and the remaining three using one 2 × 2 tile and six 1 × 1 tiles.

<p align="center">
  <img width="300" src="https://github.com/TiDeane/Tiling-Combinations/assets/120483063/54399bb0-79ea-47f6-8ecb-922d27913263">
</p>

Given the dimensions _n_ and _m_, as well as the specification of the staircase that delimits the area to be tiled, the program returns the number of different tile configurations that cover the entire area.

## Input

The input has the following format:
- A line containing an integer value _n_, which indicates the number of lines in the unit grid used to describe the area to be tiled;
- A line containing an integer value _m_, which indicates the number of columns in the unitary grid used to describe the area to be tiled;
- _n_ lines, where each line contains an integer value $c_{i}$, which indicates the index of the column through which the staircase passes in the _i_-th line. In other words, the length of line _i_.

For example, the **input** for the previously given example would be:

4  \
5  \
0  \
2  \
3  \
5

## Algorithm Explanation

The solution we created stores the number of lines, the number of columns and the length of each line, and reduces this length, from right to left, until all lines have length 0. When there are _s_ possibilities it performs recursion _s_ times, placing squares of size 1 to size _s_ in that position, and adding the results of each recursion. As we do not store a matrix, the act of putting a square corresponds to reducing the size of the corresponding lines by the size of the square. When all lines reach size 0, it means that the area is fully covered with tiles, and 1 is returned. As each recursion puts a square of a different size, the final filling of the area will be different in each one, making it possible to reach the correct total number of combinations by adding 1 whenever a recursion fills the area to the end. 

Below is an animation that shows the algorithm's process:

<p align="center">
  <img src="https://github.com/TiDeane/Tiling-Combinations/assets/120483063/b06c952c-cf6c-49e8-ae39-616a3f98eaf8" alt="animated" />
</p>

## Time Complexity

The problem with our implementation is that, for bigger areas, many states and calculations start to repeat. For this reason, while the end result is always correct, the runtime grows exponentially. Our original plan was to use dynamic programming to achieve O(n) time complexity, but unfortunately we couldn't get it done before the project's deadline.


## Testing

The program `validTilingGenerator.cpp` was provided to generate inputs.
- `./generator` **\<number of lines\> \<number of columns\> \<seed\>** > **\<nome ficheiro de teste\>**
- `<number of lines>`: replace with the desired number of lines
- `<number of columns>`: replace with the desired number of columns
- `<seed>`: replace by an integer; giving the same seed and the same parameters as before, the generated instance will be the same
- **Example**: ./generator 4 5 10 > example4x5.txt