#include <graphics.h>
#include "Tictactoe.h"
#include <string>
#include "TictactoeGUI.h"
using std::string;

Tictactoe tictactoe;
bool needExit = false;

void MessageHandler(const ExMessage& exMessage) {
	// �����Ϣ
	if (exMessage.message == WM_LBUTTONDOWN) {
		// ���ݵ㰴λ�ü������ӵص�
		Coord index = {
			exMessage.x / TictactoeGUI::gridSize,
			exMessage.y / TictactoeGUI::gridSize
		};
		auto success = tictactoe.DropDown(index);
		if (success == false) {
			MessageBox(GetHWnd(), _T("Please Redrop!"), _T("Invalid Coordinate"), MB_OK);
		}
	}
}

void DataHandler() {
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
}

int main() {
	TictactoeGUI tictactoeGUI(tictactoe);

	initgraph(TictactoeGUI::windowSize, TictactoeGUI::windowSize);
	BeginBatchDraw();
	while (!needExit) {
		// ��Ϣ����
		ExMessage exMessage;
		while (peekmessage(&exMessage))MessageHandler(exMessage);

		// ��������
		DataHandler();

		// ����
		tictactoeGUI.Draw();
		cleardevice();
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}