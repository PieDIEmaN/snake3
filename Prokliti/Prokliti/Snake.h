#pragma once
#include "curses.h"
#include <time.h>
#include <stdlib.h>

#include "Board.h"
#include "WrawS.h"
#include"Food.h"
#include "Frick.h"
class Snake// для самой игры
{
public:
	Snake(int height, int width) { //запуск полупокерского поля на этом классе 
		board = Board(height, width);
		board.create();
		game_over = false;
		srand(time(NULL));
		

	}

	void pInpud() {//chtype тип символов, с которыми 
		//работает ncurses (он включает в себя код символа, цвет и дополнительные атрибуты)
		chtype input = board.getInpute();
	
	}
	void uState() {
		int y, x;
		
		board.getEmCrdiinat(y, x);//нахождение пустых коорд
		food = new Food(y, x);//создание нового объекта по пустым коорд		
		board.addd(*food);//отрисовка объекта

		board.getEmCrdiinat(y, x);
		board.addd(Food(y, x));
		
		//board.addd(WrawS(3, 5, '#'));
	}

	void redraw() {//отрисовка
		board.refresh();
	}

	bool isover() {//концовочка 
		return game_over;
	}
private:
	Board board;
	Food* food;
	bool game_over;
	
};

