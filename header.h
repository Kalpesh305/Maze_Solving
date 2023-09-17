#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const uint8_t sample_maze[9][17]={"##### #########\n",
                            "#   #       # #\n",
                            "### # ##### # #\n",
                            "#   #   #     #\n",
                            "# # ### ##### #\n",
                            "# #   #   # # #\n",
                            "# ####### # # #\n",
                            "#           # #\n",
                            "### ###########\n"};
typedef struct{
    uint8_t row;
    uint8_t col;
}mouse_pos_t;

void print_maze(uint8_t**maze);
mouse_pos_t* fetch_entry_pos(uint8_t **maze);
mouse_pos_t* fetch_exit_pos(uint8_t **maze);
void create_algo_maze(uint8_t **maze);
void draw_path(uint8_t **maze);