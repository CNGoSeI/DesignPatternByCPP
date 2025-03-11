#include <iostream>
#include <string>
#include <vector>

/**
 * 备忘录模式：存在一个专门的类，存储目标对象的数据，并且不打破目标类的封装
 */

// 备忘录类（存储游戏角色状态）
class Memento {
private:
    int attack;
    int defense;
    friend class GameRole; // 允许GameRole访问私有成员

public:
    Memento(int atk, int def) : attack(atk), defense(def) {}
};

// 原发器类（游戏角色）
class GameRole {
private:
    int attack;
    int defense;

public:
    GameRole(int atk, int def) : attack(atk), defense(def) {}

    // 创建存档
    Memento createMemento() {
        return Memento(attack, defense);
    }

    // 恢复存档
    void restoreFromMemento(const Memento& memento) {
        attack = memento.attack;
        defense = memento.defense;
    }

    void setState(int atk, int def) {
        attack = atk;
        defense = def;
    }

    void display() const {
        std::cout << "当前攻击力: " << attack
            << "，防御力: " << defense << std::endl;
    }
};

// 管理者类（存档管理器）
class Caretaker {
private:
    std::vector<Memento> mementos;

public:
    void addMemento(const Memento& memento) {
        mementos.push_back(memento);
    }

    Memento getMemento(int index) {
        return mementos.at(index);
    }
};

// 客户端使用示例
//int main() {
//    GameRole role(100, 100); // 初始状态：攻击100，防御100
//    Caretaker caretaker;
//
//    // 第一次存档
//    caretaker.addMemento(role.createMemento());
//    role.display(); // 输出：攻击100，防御100
//
//    // 战斗后状态变化
//    role.setState(80, 60);
//    std::cout << "战斗后——";
//    role.display(); // 输出：攻击80，防御60
//
//    // 恢复初始存档
//    role.restoreFromMemento(caretaker.getMemento(0));
//    std::cout << "恢复存档——";
//    role.display(); // 输出：攻击100，防御100
//
//    system("pause");
//    return 0;
//}