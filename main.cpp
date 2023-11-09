#include <graphics.h>
#include "Tictactoe.h"
int main() {
	initgraph(600, 600);
	BeginBatchDraw();

	Tictactoe tictactoe;

	bool needExit = false;
	while (!needExit) {
		// 消息处理
		ExMessage exMessage;
		while (peekmessage(&exMessage)) {
		}

		// 处理数据

		// 绘制
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}