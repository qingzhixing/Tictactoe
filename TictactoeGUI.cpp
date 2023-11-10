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
	// 水平
	for (int i = 1; i <= 2; i++)
	{
		line(0 * gridSize, i * gridSize, 3 * gridSize, i * gridSize);
	}

	// 垂直
	for (int j = 1; j <= 2; j++)
	{
		line(j * gridSize, 0 * gridSize, j * gridSize, 3 * gridSize);
	}
}

void TictactoeGUI::DrawPieces()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			switch (bindTictactoe->GetPiece({ i + 1, j + 1 }))
			{
			case CIRCLE: {
				Coord center(i * gridSize + gridSize / 2, j * gridSize + gridSize / 2);
				circle(center.x, center.y, gridSize / 4);
				break;
			}

			case FORK: {
				line(i * gridSize, j * gridSize, (i + 1) * gridSize, (j + 1) * gridSize);
				line(i * gridSize, (j + 1) * gridSize, (i + 1) * gridSize, j * gridSize);
				break;
			}
			case EMPTY:
				break;
			}
		}
}

void TictactoeGUI::DrawTipText()
{
	static TCHAR str[64];
	static char currentPirceChar;
	if (bindTictactoe->CurrentPiece() == CIRCLE)
		currentPirceChar = 'O';
	else
		currentPirceChar = 'X';

	_stprintf_s(str, _T("当前棋子类型: %c"), currentPirceChar);

	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}
