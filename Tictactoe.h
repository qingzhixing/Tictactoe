#pragma once
#ifndef __TICTACTOE_H
#define __TICTACTOE_H

// һ�����������ӵ�״̬
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

// ��������,���ڹ�������״̬
class Tictactoe
{
public:
	Tictactoe() {
		ClearChessboard();
	}

	void ClearChessboard();

	void DropDown(const ChessPieceType& piece, const Coord& coord);

	// �ж���Ϸ��Ӯ,��Ӯ�ҷ���EMPTY,���򷵻�Ӯ��
	ChessPieceType CheckWin();

	// �ж��Ƿ��п����
	bool ExistGridEmpty();
private:
	ChessPieceType chessboard[4][4];
};

#endif // !__TICTACTOE_H
