#pragma once
#include "Tictactoe.h"
#include <graphics.h>
#ifndef __GUI_H
#define __GUI_H

class TictactoeGUI
{
public:
	TictactoeGUI();
	TictactoeGUI(const Tictactoe& tictactoe);
public:
	// 绘制一帧
	void Draw();

	void Bind(const Tictactoe& tictactoe);

private:
	// 绘制棋盘
	void DrawChessboard();

	// 绘制棋子
	void DrawPieces();

	// 绘制提示信息
	void DrawTipText();

private:
	const Tictactoe* bindTictactoe;

public:
	const static int windowSize = 600;
	const static int gridSize = windowSize / 3;
};

#endif // !__GUI_H
