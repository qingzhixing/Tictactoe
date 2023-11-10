#include "TictactoeGUI.h"

TictactoeGUI::TictactoeGUI()
{
}

TictactoeGUI::TictactoeGUI(const Tictactoe& tictactoe)
{
	Bind(tictactoe);
}

void TictactoeGUI::Draw()
{
	DrawChessboard();
	DrawPieces();
	DrawTipText();
}

void TictactoeGUI::Bind(const Tictactoe& tictactoe)
{
	bindTictactoe = &tictactoe;
}

void TictactoeGUI::DrawChessboard()
{
}