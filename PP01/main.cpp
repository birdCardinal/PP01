// PP01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<string>
//#include <stdio.h>//경로설정을 해준 애들은 꺽쇄로 가져올수있다
//#include "stdio.h" 도가능 사용자가 이 프로젝트에 포함한 파일

using namespace std;
bool is_game_running = false;
class GameObject{
public:
	GameObject() {
		cout << "게임 오브젝트 생성!\n";
	}
	virtual ~GameObject() {
		cout << "게임 오브젝트 제거!\n";
	}
	virtual void Start() {
		cout << "게임 오브젝트 스타트\n";
	}

	virtual void Update() {
		cout << "게임 오브젝트 업데 이트\n";
	}
};
class Player :public GameObject {
public:
	int Hp = 100;
	Player() {
		cout << "넓적부리황새 생성!!\n";
	}
	~Player() {
		cout << "넓적부리황새 소멸!\n";
	}
	void Start() {
		cout << "넓적부리황새의 HP는" << Hp << "입니다\n";
	}
	void Update() {
		cout << "넓적부리황새 업데이트!!\n";
	}
};
class Enemy :public GameObject {
public:
	int Hp = 100;
	Enemy() {
		cout << "적 생성!!\n";
	}
	~Enemy() {
		cout << "적 소멸!!\n";
	}
	
	void Start() {
		cout << "적의 HP는" << Hp << "입니다\n";
	}
	void Update() {
		cout << "적 업데이트!!\n";
	}
};
void main()
{
	is_game_running = true;

	GameObject* p = new Player();
	GameObject* e = new Enemy();

	p->Start();
	e->Start();
	while (is_game_running) {
		p->Update();
		e->Update();

		cout << "입력해주세요 1:겜종료,2:겜계속";
		int input;
		cin >> input;//입력
		if(input == 1)
		is_game_running = false;
	}
	delete(p);
	delete(e);
}

