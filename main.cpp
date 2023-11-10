#include <graphics.h>
#include "Tictactoe.h"
#include <string>
#include "TictactoeGUI.h"
using std::string;

Tictactoe tictactoe;
bool needExit = false;

void MessageHandler(const ExMessage& exMessage) {
	// 左键消息
	if (exMessage.message == WM_LBUTTONDOWN) {
		// 根据点按位置计算落子地点
		Coord index = {
			exMessage.x / TictactoeGUI::gridSize + 1,
			exMessage.y / TictactoeGUI::gridSize + 1
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
			needExit = true;
		}
		else {
			MessageBox(GetHWnd(), _T("Player X Wins!"), _T("Game Over"), MB_OK);
			needExit = true;
		}
	}
	else {
		if (!tictactoe.ExistGridEmpty()) {
			MessageBox(GetHWnd(), _T("Draw! No Winner!"), _T("Game Over"), MB_OK);
			needExit = true;
		}
	}
}

int main() {
	TictactoeGUI tictactoeGUI(tictactoe);

	initgraph(TictactoeGUI::windowSize, TictactoeGUI::windowSize);
	BeginBatchDraw();
	while (!needExit) {
		// 消息处理
		ExMessage exMessage;
		while (peekmessage(&exMessage))MessageHandler(exMessage);

		// 绘制
		cleardevice();
		tictactoeGUI.Draw();
		FlushBatchDraw();

		// 处理数据
		DataHandler();
	}

	EndBatchDraw();
	return 0;
}