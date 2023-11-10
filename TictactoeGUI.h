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
	// ����һ֡
	void Draw();

	void Bind(const Tictactoe& tictactoe);

private:
	// ��������
	void DrawChessboard();

	// ��������
	void DrawPieces();

	// ������ʾ��Ϣ
	void DrawTipText();

private:
	const Tictactoe* bindTictactoe;

public:
	const static int windowSize = 600;
	const static int gridSize = windowSize / 3;
};

#endif // !__GUI_H
