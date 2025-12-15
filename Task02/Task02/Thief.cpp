#include "Thief.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
    job_name = "도적";
    cout << "* 도적으로 전직하였습니다." << endl;
    speed = 80;
}

void Thief::attack()
{
    cout << "* 표창을 던진다" << endl;
}

void Thief::attack(Monster* monster)
{
    int damage = (power - monster->getDefence()) / 5;

    if (damage <= 0) {
        damage = 1;
    }

    for (int i = 0; i < 5; i++) {
        cout << "* 몬스터에게 표창으로 " << damage << "의 데미지를 입혔습니다\n";
        monster->setHP(monster->getHP() - damage);
    }

    if (monster->getHP() > 0) {
        cout << "* 몬스터의 남은 HP는 " << monster->getHP() << "입니다\n";
    }
    else {
        cout << "* 플레이어가 승리했습니다\n";
    }
}