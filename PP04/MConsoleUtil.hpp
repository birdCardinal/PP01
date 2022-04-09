#pragma once
#include<iostream>
#include<string>
#include <Windows.h>

using namespace std;

namespace MuSeoun_Engine {
	class MConsoleRenderer {
	public:
		MConsoleRenderer() { SetCursorState(false); }
		~MConsoleRenderer(){}
		void MoveCursor(short x, short y) {
			COORD playerPosition = { x,y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPosition);
		}
		void SetCursorState(bool visible) {

			CONSOLE_CURSOR_INFO consoleCursorinfo;
			consoleCursorinfo.bVisible = visible;
			consoleCursorinfo.dwSize = 1;

			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorinfo);
		}

		void DrawString(string s,int a) {
			cout << s<<a;
		}
		void Clear() {
			system("cls");
		}
	};
}