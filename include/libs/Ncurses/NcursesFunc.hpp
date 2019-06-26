/*
** EPITECH PROJECT, 2019
** NcursesFunc.hpp
** File description:
** Ncurses basic functions
*/

#ifndef NCURSESFUNC_HPP_
    #define NCURSESFUNC_HPP_

#include <curses.h>

class NcursesFunc
{
    public:
        static SCREEN *newTerm(char *type, FILE *outfd, FILE *infd);
        static int noEcho();
        static int cBreak();
        static int cursSet(int visibility);
        static int noDelay(WINDOW *win, bool bf);
        static int keyPad(WINDOW *win, bool bf);
        static WINDOW *subWin(WINDOW *orig, int nlines, int ncols, int begin_y, int begin_x);
        static int startColor(void);
        static int initPair(short pair, short f, short b);
        static int endWin(void);
        static int Clear();
        static int wClear(WINDOW *win);
        static int Refresh();
        static int wRefresh(WINDOW *win);
        static int getCh();
        static int Attron(int attrs);
        static int Attroff(int attrs);
        static int mvPrintw(int y, int x, const char *fmt);
};

#endif /* !NCURSESFUNC_HPP_ */
