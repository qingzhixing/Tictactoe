#include <graphics.h>
#include "Tictactoe.h"
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

		// ����
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}