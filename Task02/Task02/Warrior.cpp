#include "warrior.h"
#include "monster.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname)
{
    job_name = "전사";
    cout << "* 전사로 전직하였습니다." << endl;
    HP = 80;
}

void Warrior::attack()
{
    cout << "* 검을 휘두른다" << endl;
}

void Warrior::attack(Monster* monster)
{
    int damage = power - monster->getDefence();
    if (damage <= 0) {
        damage = 1;
    }
    
    cout << "* 몬스터에게 검으로 " << damage << "의 데미지를 입혔습니다\n";

    monster->setHP(monster->getHP() - damage);

    if (monster->getHP() > 0) {
        cout << "* 몬스터의 남은 HP는 " << monster->getHP() << "입니다\n";
    }
    else {
        cout << "* 플레이어가 승리했습니다\n";
    }
}