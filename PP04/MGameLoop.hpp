#pragma once
#include<chrono>
#include<thread>
#include "MConsoleUtil.hpp";

using namespace std;

namespace MuSeoun_Engine {
	double a;
	int countFPS;
	float sumCountFPS;
	float AverageCountFPS;
	int count;
	class MGameLoop {

	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
	public:
		
		MGameLoop() {
			_isGameRunning = false;
		}
		~MGameLoop() {

		}
		void Run() {
			_isGameRunning = true;
			Initialize();
			while (_isGameRunning) {
				Input();
				Update();
				Render();
			}
			Release();
		}
		void Stop() {
			_isGameRunning = false;
		}
	private:

		void Initialize(){
		//	SetCursorState(false);
		}
		void Input(){
		/*	if (GetAsyncKeyState(VK_SPACE)==-0x8000|| GetAsyncKeyState(VK_SPACE) == -0x8001) {
			
			}
			else {

			}*/
		}
		void Update(){
			
		}
		void Render(){
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);
		//	cRenderer.DrawString("test");
		//	system("cls");
		//	MoveCursor(10, 20);
		//	cout << "Rendering..";
	
		//	cout << "Rendering speed:" <<renderduration.count() <<"sec"<< endl;
		//과제 Duration을 찍는건데 FPS를 실제로 구현해야된다
			chrono::duration<double> renderduration = chrono::system_clock::now() - startRenderTimePoint;
			a += renderduration.count();
			cout <<"Count"<< countFPS << "AVERAGE FPS" << AverageCountFPS;
			countFPS++;
			
				string fps = "FPS(millseconds" + to_string(a);
				cRenderer.DrawString(fps,countFPS);
				if (a >= 1) {
				a = 0;
				sumCountFPS += countFPS;
				countFPS = 0;
				count++;
				AverageCountFPS = sumCountFPS/count;
			}
		//	int remainingFrameTime = 100 - (DWORD)(renderduration.count()*1000.0);
		
		//	if (remainingFrameTime > 0)
			//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		}

		void Release(){}
	private://게임 사용 함수
		void MoveCursor(short x,short y) {
			COORD playerPosition = { x,y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPosition);
		}
		void SetCursorState(bool visible) {
		
			CONSOLE_CURSOR_INFO consoleCursorinfo;
			consoleCursorinfo.bVisible = visible;
			consoleCursorinfo.dwSize = 1;

			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&consoleCursorinfo);
		}
	};
}