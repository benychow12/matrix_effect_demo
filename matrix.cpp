#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ncurses.h>

using namespace std;

#define DARK_GREEN_PAIR 1
#define LIGHT_GREEN_PAIR 2

int main(int argc, char *argv[])
{
    // Initialize curses
    initscr();
    curs_set(0);
    clear();

    // Initialize colour
    start_color();
    init_pair(LIGHT_GREEN_PAIR, COLOR_CYAN, COLOR_BLACK);
    init_pair(DARK_GREEN_PAIR, COLOR_GREEN, COLOR_BLACK);

    // Initialize effect variables
    int maxlines = LINES - 1;
    int maxcols = COLS - 1;

    while (1)
    {
        // Calculate random position to draw text
        int position_x = rand() % LINES;
        int position_y = rand() % COLS;
        char matrix_char;

        // Rand 0 or 1
        if (rand() % 2 == 0)
        {
            matrix_char = '0';
        }
        else
        {
            matrix_char = '1';
        }

        // Even odd green or dark green
        if (rand() % 2 == 0)
        {
            attron(COLOR_PAIR(DARK_GREEN_PAIR));
            mvaddch(position_x, position_y, matrix_char);
            refresh();
        }
        else
        {
            attron(COLOR_PAIR(LIGHT_GREEN_PAIR));
            mvaddch(position_x, position_y, matrix_char);
            refresh();
        }
    }
    endwin();
    return 0;
}
