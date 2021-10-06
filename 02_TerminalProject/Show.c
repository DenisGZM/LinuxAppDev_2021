#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WINDOW *create_newwin( int height, int width, int starty, int startx);
void destroy_win( WINDOW *local_win);

const int lines_batch = 1024;

int
min( int a, int b)
{
    return a < b ? a : b;
}

void
freelines( char ***lines, int lines_num)
{
    for ( int i = 0; i < lines_num; ++i )
    {
        free((*lines)[i]);
    }
    free(*lines);
}

int
readfile( char ***lines, int *lines_num, char *filename)
{
    FILE *file;
    int batches = 1;
    size_t line_size = 0;
    char *curline = NULL;
    *lines_num=0;
    *lines = (char **)malloc( batches*lines_batch*sizeof(char *));

    file = fopen( filename, "r");
    if ( !file )
    {
        fprintf( stderr, "Couldn't open file: %s\n", filename);
        return -1;
    }

    
    while ( (line_size = getline( &curline, &line_size, file)) != -1 )
    {
        (*lines)[*lines_num] = curline;
        *lines_num += 1;
        curline = NULL;
        line_size = 0;
        if ( *lines_num > batches*lines_batch )
        {
            ++batches;
            *lines = (char **)realloc( *lines, batches*lines_batch*sizeof(char *));
        }
    }

    *lines = (char **)realloc( *lines, *lines_num*sizeof(char *));
    return 0;
}

void
drawText( WINDOW *wnd, char **lines,
          int lines_num, int top, int bot)
{
    for ( int i = top, pos = 1; i < min(lines_num,bot); ++i, ++pos )
    {
        mvwaddstr( wnd, pos, 1,lines[i]);
    }
}

int
main(int argc, char **argv)
{    
    WINDOW *my_win;
    char **lines;
    int lines_num;
    int startx, starty, width, height, row, col;
    int ch;
    int page_size;
    int top, bot;

    if ( readfile( &lines, &lines_num, argv[1]) == -1 )
    {
        return -1;
    }

    initscr();
    cbreak();
    noecho();
    keypad( stdscr, TRUE);
    getmaxyx( stdscr,row,col);
    page_size = height = row - 3;
    top = 0;
    bot = page_size - 2;
    width = col - 3;
    starty = (row - height) / 2;
    startx = (col - width) / 2;
    refresh(); 
    printw("Filename: %s", argv[1]);

    my_win = create_newwin( height, width, starty, startx);
    drawText( my_win, lines, lines_num, top, bot);
    wborder( my_win, 0,0,0,0,0,0,0,0);
    wrefresh( my_win);

    while ( (ch = getch()) != 27 )  // ESC - code 27
    {
        switch ( ch )
        {
            
            case KEY_UP:
                if ( top <= 0 )
                {
                    break;
                }
                top--;
                bot--;
                break;
            case KEY_DOWN:
                if ( bot >= lines_num )
                {
                    break;
                }
                top++;
                bot++;
                break;
        }
        wclear( my_win);
        drawText( my_win, lines, lines_num, top, bot);
        wborder( my_win, 0,0,0,0,0,0,0,0);
        wrefresh( my_win);
    }

    endwin();
    freelines(&lines, lines_num);
    return 0;
}

WINDOW *
create_newwin( int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin( height, width, starty, startx);
    box( local_win, 0 , 0);
    wrefresh( local_win);

    return local_win;
}

void
destroy_win( WINDOW *local_win)
{    
    wborder( local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');

    wrefresh( local_win);
    delwin( local_win);
}