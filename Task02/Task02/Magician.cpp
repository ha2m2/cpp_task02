#include "Magician.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Magician::Magician(string nickname) : Player(nickname)
{
    job_name = "마법사";
    cout << "* 마법사로 전직하였습니다." << endl;
    MP = 80;
}

void Magician::attack()
{
    cout << "* 주문을 외운다" << endl;
}

void Magician::attack(Monster* monster)
{
    int damage = (power - monster->getDefence());

    if (damage <= 0) {
        damage = 1;
    }

    cout << "* 몬스터에게 마법으로 " << damage << "의 데미지를 입혔습니다\n";
    monster->setHP(monster->getHP() - damage);

    if (monster->getHP() > 0) {
        cout << "* 몬스터의 남은 HP는 " << monster->getHP() << "입니다\n";
    }
    else {
        cout << "* 플레이어가 승리했습니다\n";
    }
}