#include "Archer.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Archer::Archer(string nickname) : Player(nickname)
{
    job_name = "궁수";
    cout << "* 궁수로 전직하였습니다." << endl;
    accuracy = 80;
}

void Archer::attack()
{
    cout << "* 화살을 쏜다" << endl;
}

void Archer::attack(Monster* monster)
{
    int damage = (power - monster->getDefence()) / 3;

    if (damage <= 0) {
        damage = 1;
    }

    for (int i = 0; i < 3; i++) {
        cout << "* 몬스터에게 화살로 " << damage << "의 데미지를 입혔습니다\n";
        monster->setHP(monster->getHP() - damage);
    }
    
    if (monster->getHP() > 0) {
        cout << "* 몬스터의 남은 HP는 " << monster->getHP() << "입니다\n";
    }
    else {
        cout << "* 플레이어가 승리했습니다\n";
    }
}