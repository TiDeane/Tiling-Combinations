#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void printMatrix(int lines, int columns, int columnsPerLine[]) {
    printf("\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++)
            if (j < columnsPerLine[i])
                printf("1 ");
            else
                printf("0 ");
        printf("\n");
    }
}

void copyIntArray(int arraySize, int copy[], int original[]) {
    for (int i = 0; i < arraySize; i++)
        copy[i] = original[i];
}

void putSquare(int columnsPerLine[], int currentLine, int size) {
    for (int i = currentLine; i > currentLine - size; i--)
        columnsPerLine[i] -= size;
}

int combinations(int lines, int columns, int columnsPerLine[]) {
    //printf("\nnew call\n");
    //printMatrix(lines, columns, columnsPerLine);
    int currentLine = lines - 1, size = 0, biggest = 0, result = 0, aux[lines];

    for (int line = lines - 1; line >= 0; line--)
        if (columnsPerLine[line] > biggest) {
            currentLine = line;
            biggest = columnsPerLine[line];
            size = 1;
        }
        else if (biggest != 0 && columnsPerLine[line] == biggest && size < biggest && line == currentLine - size) {
            size += 1;
        }
    //printf("currentLine = %d, size = %d\n", currentLine, size);

    if (size == 0)
        return 1;
    else if (size == 1) {
        columnsPerLine[currentLine] -= 1;
        return combinations(lines, columns, columnsPerLine);
    }
    else {
        for (int s = size; s >= 1; s--) {
            copyIntArray(lines, aux, columnsPerLine);
            putSquare(aux, currentLine, s);
            result += combinations(lines, columns, aux);
        }
    }

    return result;
}

int main() {
    int lines, columns, step, result = 0;

    scanf("%d", &lines);
    scanf("%d", &columns);
    int columnsPerLine[lines];

    for (int i = 0; i < lines; i++) {
        scanf("%d", &step);
        columnsPerLine[i] = step;
    }

    if (step == 0) { /* "step" is the number of columns in the last line */
        result = 0;
    } else {
        result = combinations(lines, columns, columnsPerLine);
    }
    
    printf("%d\n", result);

    return 0;
}