#pragma once
#include <chrono>
#include <GLFW/glfw3.h>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		static void error_callback(int error, const char* description)
		{
			fputs(description, stderr);
		}
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);
		}
		GLFWwindow* window;

		void Run()
		{
			window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
		
			if (!glfwInit())
				exit(EXIT_FAILURE);
		
			while (_isGameRunning)
			{
			
				Input();
				Update();
				Render();

			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{

		}
		void Release()
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				p.isKeyPressed();
			}
			else
			{
				p.isKeyUnpressed();
			}

		}
		void Update()
		{

		}
		void Render()
		{
			while (!glfwWindowShouldClose(window))
			{
				float ratio;
				int width, height;
				glfwGetFramebufferSize(window, &width, &height);
				ratio = width / (float)height;


				glClearColor(0, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);

				glfwSwapBuffers(window);
				glfwPollEvents();

			cRenderer.Clear();


			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("P");


			cRenderer.MoveCursor(10, 20);


			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));
						}
		}


		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));




	};






}