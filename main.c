#include "header.h"

const int rows=9,cols=17;
const int r_rows = rows, r_cols = cols-2;

mouse_pos_t* mouse_start_pos = NULL;
mouse_pos_t* mouse_end_pos = NULL;

void main()
{
    uint8_t **const maze_p = calloc(rows,sizeof(uint8_t*));
    for(int i=0 ; i<rows ; i++){
        maze_p[i] = calloc(cols,sizeof(uint8_t));
        memcpy(maze_p[i],sample_maze[i],cols);
    }        

    /* copy original maze to maze_sol to modify for solution*/
    uint8_t **maze_sol = calloc(rows,sizeof(uint8_t*));
    for(int i = 0; i < rows; i++){
        maze_sol[i] = calloc(cols,sizeof(uint8_t));
        memcpy(maze_sol[i],maze_p[i],cols);
    }
    mouse_start_pos = fetch_entry_pos(maze_sol);
    mouse_end_pos = fetch_exit_pos(maze_sol);
    
    print_maze(maze_sol);
    create_algo_maze(maze_sol);
    draw_path(maze_sol);
    printf("\n");
    print_maze(maze_sol);
}

void print_maze(uint8_t **maze){
    for(uint8_t i = 0; i<rows; i++)
        printf("%s",maze[i]);
}

mouse_pos_t* fetch_entry_pos(uint8_t **maze){
uint8_t i;
mouse_pos_t* pos = NULL;
    for(i=0 ; i<r_cols ; i++){
        if(maze[0][i] == ' '){
            pos = calloc(1,sizeof(mouse_pos_t));
            pos->col = i;
            pos->row = 0;
            break;
        }
    }
    return pos;
}

mouse_pos_t* fetch_exit_pos(uint8_t **maze){

    mouse_pos_t* pos = NULL;
    for(uint8_t i=0 ; i<r_cols ; i++){
        if(maze[r_rows-1][i] == ' '){
            pos = calloc(1,sizeof(mouse_pos_t));
            pos->col = i;
            pos->row = r_rows-1;
            break;
        }
    }
    return pos;
}

void create_algo_maze(uint8_t **maze){

    int row = mouse_end_pos->row;
    int col = mouse_end_pos->col;
    maze[row][col] = '0';
    maze[--row][col] = '1';

    int search_char = 1;
    while(1){
        int t_row = row;
        int t_col = r_cols-1;
        
        for(int i=t_row; i>=0; i--)
        {
            for(int j=t_col; j>=0; j--)
            {
                if(maze[i][j] == search_char+48)
                {
                    if(maze[i][j-1] == ' ')
                    {
                        maze[i][j-1] = search_char+48+1;
                    }
                    if(maze[i][j+1] == ' ')
                    {
                        maze[i][j+1] = search_char+48+1;
                    }
                    if(maze[i-1][j] == ' ')
                    {
                        maze[i-1][j] = search_char+48+1;
                    }
                    if(maze[i+1][j] == ' ')
                    {
                        maze[i+1][j] = search_char+48+1;
                    }
                }
            }
        }

        search_char++;
        if(maze[mouse_start_pos->row][mouse_start_pos->col] != ' ')
        break;
    }
}
//TODO: draw_path function pending
void draw_path(uint8_t **maze){
    int row = mouse_start_pos->row+1;
    int col = mouse_start_pos->col;
    mouse_pos_t c_pos = *mouse_start_pos;

    int search_count = 0;
    int break_point = 1;
    while(1){
        
        if(row == 0){
            if(maze[c_pos.row][c_pos.col] > maze[c_pos.row][col-1]){
                c_pos.col--;
                printf("\033[\e[42m");
                printf(" ");
                printf("\033[0m\n");
            }
            if(maze[c_pos.row][c_pos.col] > maze[c_pos.row][col+1]){
                c_pos.col++;
                printf("\033[\e[42m");
                printf(" ");
                printf("\033[0m\n");
            }
            if(maze[c_pos.row][c_pos.col] > maze[c_pos.row+1][col]){
                c_pos.row++;
                printf("\033[\e[42m");
                printf(" ");
                printf("\033[0m\n");
            }
        }
        search_count++;
        if(break_point== search_count)
                break;
    }
}