/*
** EPITECH PROJECT, 2019
** NcursesFunc.cpp
** File description:
** Ncurses basic functions
*/

#include "../../../include/libs/Ncurses/NcursesFunc.hpp"

SCREEN *NcursesFunc::newTerm(char *type, FILE *outfd, FILE *infd)
{
    return newterm(type, outfd, infd);
}

int NcursesFunc::noEcho()
{
    return noecho();
}

int NcursesFunc::cBreak()
{
    return cbreak();
}

int NcursesFunc::cursSet(int visibility)
{
    return curs_set(visibility);
}

int NcursesFunc::noDelay(WINDOW *win, bool bf)
{
    return nodelay(win, bf);
}

int NcursesFunc::keyPad(WINDOW *win, bool bf)
{
    return keypad(win, bf);
}

WINDOW *NcursesFunc::subWin(WINDOW *orig, int nlines, int ncols, int begin_y, int begin_x)
{
    return subwin(orig, nlines, ncols, begin_y, begin_x);
}

int NcursesFunc::startColor(void)
{
    return start_color();
}

int NcursesFunc::initPair(short pair, short f, short b)
{
    return init_pair(pair, f, b);
}

int NcursesFunc::endWin(void)
{
    return endwin();
}

int NcursesFunc::Clear()
{
    return clear();
}

int NcursesFunc::wClear(WINDOW *win)
{
    return wclear(win);
}

int NcursesFunc::Refresh()
{
    return refresh();
}

int NcursesFunc::wRefresh(WINDOW *win)
{
    return wrefresh(win);
}

int NcursesFunc::getCh()
{
    return getch();
}

int NcursesFunc::Attron(int attrs)
{
    return attron(attrs);
}

int NcursesFunc::Attroff(int attrs)
{
    return attroff(attrs);
}

int NcursesFunc::mvPrintw(int y, int x, const char *fmt)
{
    return mvprintw(y, x, fmt);
}
