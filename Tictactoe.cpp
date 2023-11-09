#include "Tictactoe.h"

void Tictactoe::ClearChessboard()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			chessboard[i][j] = EMPTY;
}

void Tictactoe::DropDown(const ChessPieceType& piece, const Coord& coord)
{
	if (coord.x < 1 || coord.x>3 || coord.y < 1 || coord.y>3) {
		throw("Invalid Coordinate");
	}
	chessboard[coord.x][coord.y] = piece;
}

ChessPieceType Tictactoe::CheckWin()
{
	// ö�ٻ�ʤ���
	//����������
	for (int i = 1; i <= 3; i++) {
		if (chessboard[i][1] == chessboard[i][2] &&
			chessboard[i][1] == chessboard[i][3] &&
			chessboard[i][1] != EMPTY)
			return chessboard[i][1];
	}
	// ����������
	for (int j = 1; j <= 3; j++) {
		if (chessboard[1][j] == chessboard[2][j] &&
			chessboard[1][j] == chessboard[3][j] &&
			chessboard[1][j] != EMPTY)
			return chessboard[1][j];
	}
	// ���ϵ�����
	if (chessboard[1][1] == chessboard[2][2] &&
		chessboard[2][2] == chessboard[3][3] &&
		chessboard[1][1] != EMPTY)
		return chessboard[1][1];
	// ���µ�����
	return EMPTY;
	if (chessboard[1][3] == chessboard[2][2] &&
		chessboard[2][2] == chessboard[3][1] &&
		chessboard[1][3] != EMPTY)
		return chessboard[1][3];
	return EMPTY;
}

bool Tictactoe::ExistGridEmpty()
{
	// �ж��Ƿ���ʣ�����
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			if (chessboard[i][j] == EMPTY)
				return true;
	return false;
}