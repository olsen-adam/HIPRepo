#include <stdio.h>
#include <stdlib.h>


char maze[];
char visited[];
int rows;
int cols;

enum terrain {
    empty,
    wall,
    goal,
    crumb
};

void get_maze(char file_name[]) {
    char c;
    char rows_s[3] = { '\0' };
    char cols_s[3] = { '\0' };
    int rows_i = 0;
    int cols_i = 0;
    int swap = 0;

    FILE* file = fopen(file_name, "r");

    if (file) {
        while ((c = getc(file)) != EOF) {
            if (c == '\n') {
                break;
                } else if (c == ',') {

                swap = 1;

                } else if (!swap) {
                rows_s[rows_i] = c;
                rows_i++;
                } else {
                cols_s[cols_i] = c;
                cols_i++;
                }
        }
    }

    rows = atoi(rows_s);
    cols = atoi(cols_s);
}


int main(){

get_maze("maze.txt");

printf("%d, %d\n", rows, cols);

return 0;
}

