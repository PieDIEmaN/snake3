#pragma once
#include "curses.h"
#include <time.h>
#include <stdlib.h>

#include "Board.h"
#include "WrawS.h"
#include"Food.h"
#include "Frick.h"
class Snake// ��� ����� ����
{
public:
	Snake(int height, int width) { //������ �������������� ���� �� ���� ������ 
		board = Board(height, width);
		board.create();
		game_over = false;
		srand(time(NULL));
		

	}

	void pInpud() {//chtype ��� ��������, � �������� 
		//�������� ncurses (�� �������� � ���� ��� �������, ���� � �������������� ��������)
		chtype input = board.getInpute();
	
	}
	void uState() {
		int y, x;
		
		board.getEmCrdiinat(y, x);//���������� ������ �����
		food = new Food(y, x);//�������� ������ ������� �� ������ �����		
		board.addd(*food);//��������� �������

		board.getEmCrdiinat(y, x);
		board.addd(Food(y, x));
		
		//board.addd(WrawS(3, 5, '#'));
	}

	void redraw() {//���������
		board.refresh();
	}

	bool isover() {//���������� 
		return game_over;
	}
private:
	Board board;
	Food* food;
	bool game_over;
	
};

