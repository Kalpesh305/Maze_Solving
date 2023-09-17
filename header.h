#include <stdint.h>

uint8_t sample_maze[9][17]={"##### #########\n",
                            "#   #       # #\n",
                            "### # ##### # #\n",
                            "#   #   #     #\n",
                            "# # ### ##### #\n",
                            "# #   #   # # #\n",
                            "# ####### # # #\n",
                            "#           # #\n",
                            "### ###########\n"};
typedef struct{
    uint8_t rows;
    uint8_t cols;
}mouse_pos_t;

void print_maze(uint8_t**maze);