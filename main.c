#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

const int rows=9,cols=17;
const int r_rows = rows, r_cols = cols-2;

void main()
{
    uint8_t **maze_p = calloc(rows,sizeof(uint8_t*));
    for(int i=0 ; i<rows ; i++)
    maze_p[i] = calloc(cols,sizeof(uint8_t));
    
    for (int i = 0; i < rows; i++)
        memcpy(maze_p[i],sample_maze[i],cols);

    /* copy original maze to maze_sol to modify for solution*/
    uint8_t **maze_sol = calloc(rows,sizeof(uint8_t*));
    for(int i = 0; i < rows; i++){
        maze_sol[i] = calloc(cols,sizeof(uint8_t));
        memcpy(maze_sol[i],maze_p[i],cols);
    }
    print_maze(maze_p);    
}


void print_maze(uint8_t **maze){
    for(uint8_t i = 0; i<rows; i++)
        printf("%s",maze[i]);
}