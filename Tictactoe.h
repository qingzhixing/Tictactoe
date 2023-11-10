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
	Tictactoe();

	void ClearChessboard();

	// 返回是否成功落子
	bool DropDown(const ChessPieceType& piece, const Coord& coord);

	// 由程序自动落相应的子, 返回是否成功落子
	bool DropDown(const Coord& coord);

	// 判断游戏输赢,无赢家返回EMPTY,有则返回赢家
	ChessPieceType CheckWin();

	// 判断是否有空棋格
	bool ExistGridEmpty();

	// 获取现在要下的子的类型
	ChessPieceType CurrentPiece() const;

	// 切换到下一个种类的棋子
	void NextPiece();
private:
	ChessPieceType chessboard[4][4];
	ChessPieceType currentPiece;
};

#endif // !__TICTACTOE_H
