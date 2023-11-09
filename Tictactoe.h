#pragma once
#ifndef __TICTACTOE_H
#define __TICTACTOE_H

// 一个格子中棋子的状态
enum ChessPieceType {
	EMPTY,
	CIRCLE,
	FORK
};

struct Coord {
	int x, y;
	Coord() :x(0), y(0) {}
	Coord(int _x, int _y) :x(_x), y(_y) {}
};

// 井字棋类,用于管理井字棋状态
class Tictactoe
{
public:
	Tictactoe() {
		ClearChessboard();
	}

	void ClearChessboard();

	void DropDown(const ChessPieceType& piece, const Coord& coord);

	// 判断游戏输赢,无赢家返回EMPTY,有则返回赢家
	ChessPieceType CheckWin();

	// 判断是否有空棋格
	bool ExistGridEmpty();
private:
	ChessPieceType chessboard[4][4];
};

#endif // !__TICTACTOE_H
