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
	Tictactoe();

	void ClearChessboard();

	// �����Ƿ�ɹ�����
	bool DropDown(const ChessPieceType& piece, const Coord& coord);

	// �ɳ����Զ�����Ӧ����, �����Ƿ�ɹ�����
	bool DropDown(const Coord& coord);

	// �ж���Ϸ��Ӯ,��Ӯ�ҷ���EMPTY,���򷵻�Ӯ��
	ChessPieceType CheckWin();

	// �ж��Ƿ��п����
	bool ExistGridEmpty();

	// ��ȡ����Ҫ�µ��ӵ�����
	ChessPieceType CurrentPiece() const;

	// �л�����һ�����������
	void NextPiece();
private:
	ChessPieceType chessboard[4][4];
	ChessPieceType currentPiece;
};

#endif // !__TICTACTOE_H
