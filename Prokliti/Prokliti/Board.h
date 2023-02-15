#pragma once

#include "WrawS.h"




class Board //�������� ������ ��� ���� ��� ���� 
{
public ://��������� ����� ��� ���������� ����� ��� ����� 
    Board() {
        construct(0, 0);
    }
    Board(int height, int width) //��� ����� ������ 
    {
      
        construct(height, width);
        
	}   

    
    void create() {// ��� ������������� 

        clear();
        refresh();

    }

    void AddBorder() {// ��� �������(�������� �������)
        box(board_win, 0, 0);//������� ������� �� ������ (������)

    }

    void addd(WrawS wrawS) {
        AddAt(wrawS.getY(), wrawS.getX(), wrawS.getIcone());
    }


    void AddAt(int y, int x, chtype ch)//chtype ��������� ������������� ������ � �������� �������� ���������.
    {
        mvwaddch(board_win, y, x, ch);
    }

    chtype getInpute() 
    {
        return wgetch(board_win);
    }

    void getEmCrdiinat(int& y, int& x) {
        
        while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ')  
            ; 
    }

    void clear() {//�������� 

        wclear(board_win);
        AddBorder();

    }

    void refresh() 
    {// ��� ��������� ����

        wrefresh(board_win);// ��� ��������� ����� ������� ������ 
        //������ ��� �� �������      

    }


private:
    WINDOW* board_win;
    int height, width;

    void construct(int height ,int width) 
    {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        this->height = height;
        this->width = width;
        board_win = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
        //newwin - ������� ���� ��� ���� ���� 

    }
    
};