#include "Tictactoe.h"

Tictactoe::Tictactoe()
{
	ClearChessboard();
	currentPiece = CIRCLE;
}

void Tictactoe::ClearChessboard()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			chessboard[i][j] = EMPTY;
}

bool Tictactoe::DropDown(const ChessPieceType& piece, const Coord& coord)
{
	if (coord.x < 1 || coord.x>3 || coord.y < 1 || coord.y>3) {
		throw("Invalid Coordinate");
	}
	if (chessboard[coord.x][coord.y] != EMPTY)return false;
	chessboard[coord.x][coord.y] = piece;
	NextPiece();
}

bool Tictactoe::DropDown(const Coord& coord)
{
	return DropDown(currentPiece, coord);
}

ChessPieceType Tictactoe::CheckWin()
{
	// 枚举获胜情况
	//横向三个子
	for (int i = 1; i <= 3; i++) {
		if (chessboard[i][1] == chessboard[i][2] &&
			chessboard[i][1] == chessboard[i][3] &&
			chessboard[i][1] != EMPTY)
			return chessboard[i][1];
	}
	// 纵向三个子
	for (int j = 1; j <= 3; j++) {
		if (chessboard[1][j] == chessboard[2][j] &&
			chessboard[1][j] == chessboard[3][j] &&
			chessboard[1][j] != EMPTY)
			return chessboard[1][j];
	}
	// 左上到右下
	if (chessboard[1][1] == chessboard[2][2] &&
		chessboard[2][2] == chessboard[3][3] &&
		chessboard[1][1] != EMPTY)
		return chessboard[1][1];
	// 左下到右上
	return EMPTY;
	if (chessboard[1][3] == chessboard[2][2] &&
		chessboard[2][2] == chessboard[3][1] &&
		chessboard[1][3] != EMPTY)
		return chessboard[1][3];
	return EMPTY;
}

bool Tictactoe::ExistGridEmpty()
{
	// 判断是否有剩余棋格
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			if (chessboard[i][j] == EMPTY)
				return true;
	return false;
}

ChessPieceType Tictactoe::CurrentPiece() const
{
	return currentPiece;
}

void Tictactoe::NextPiece()
{
	if (currentPiece == CIRCLE)currentPiece = FORK;
	else currentPiece = CIRCLE;
}

ChessPieceType Tictactoe::GetPiece(const Coord& coord) const
{
	if (coord.x < 1 || coord.x>3 || coord.y < 1 || coord.y>3) {
		throw("Invalid Coordinate");
	}
	return chessboard[coord.x][coord.y];
}