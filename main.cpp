#include <graphics.h>
#include "Tictactoe.h"
#include <string>
using std::string;

int main() {
	initgraph(600, 600);
	BeginBatchDraw();

	Tictactoe tictactoe;

	bool needExit = false;
	while (!needExit) {
		// ��Ϣ����
		ExMessage exMessage;
		while (peekmessage(&exMessage)) {
		}

		// ��������
		auto winner = tictactoe.CheckWin();
		if (winner != EMPTY) {
			if (winner == CIRCLE) {
				MessageBox(GetHWnd(), _T("Player O Wins!"), _T("Game Over"), MB_OK);
			}
			else {
				MessageBox(GetHWnd(), _T("Player X Wins!"), _T("Game Over"), MB_OK);
			}
		}
		else {
			if (!tictactoe.ExistGridEmpty()) {
				MessageBox(GetHWnd(), _T("Draw! No Winner!"), _T("Game Over"), MB_OK);
			}
		}

		// ����
		cleardevice();
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}