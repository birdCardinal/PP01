#pragma once
#include "MCommand.hpp"

using namespace Musoeum;
class JumpCommand : public MCommand
{
public:
	void Execute() {
		std::cout << "�ѽ� ����!!";
	}
};

class RunCommand : public MCommand
{
public:
	void Execute() {
		std::cout << "�ѽ� �޸���!!";
	}
};

class LeftCommand : public MCommand
{
public:
	void Execute() {
		std::cout << "�ѽ� ����!!";
	}
};

class RightCommand : public MCommand
{
public:
	void Execute() {
		std::cout << "�����̾� ������!!";
	}
};

class DownCommand : public MCommand
{
public:
	void Execute() {
		std::cout << "������ ���� ���� ������!!";
	}
};