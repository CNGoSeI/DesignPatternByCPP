#include <iostream>
#include <string>
#include <vector>

/**
 * ����¼ģʽ������һ��ר�ŵ��࣬�洢Ŀ���������ݣ����Ҳ�����Ŀ����ķ�װ
 */

// ����¼�ࣨ�洢��Ϸ��ɫ״̬��
class Memento {
private:
    int attack;
    int defense;
    friend class GameRole; // ����GameRole����˽�г�Ա

public:
    Memento(int atk, int def) : attack(atk), defense(def) {}
};

// ԭ�����ࣨ��Ϸ��ɫ��
class GameRole {
private:
    int attack;
    int defense;

public:
    GameRole(int atk, int def) : attack(atk), defense(def) {}

    // �����浵
    Memento createMemento() {
        return Memento(attack, defense);
    }

    // �ָ��浵
    void restoreFromMemento(const Memento& memento) {
        attack = memento.attack;
        defense = memento.defense;
    }

    void setState(int atk, int def) {
        attack = atk;
        defense = def;
    }

    void display() const {
        std::cout << "��ǰ������: " << attack
            << "��������: " << defense << std::endl;
    }
};

// �������ࣨ�浵��������
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

// �ͻ���ʹ��ʾ��
//int main() {
//    GameRole role(100, 100); // ��ʼ״̬������100������100
//    Caretaker caretaker;
//
//    // ��һ�δ浵
//    caretaker.addMemento(role.createMemento());
//    role.display(); // ���������100������100
//
//    // ս����״̬�仯
//    role.setState(80, 60);
//    std::cout << "ս���󡪡�";
//    role.display(); // ���������80������60
//
//    // �ָ���ʼ�浵
//    role.restoreFromMemento(caretaker.getMemento(0));
//    std::cout << "�ָ��浵����";
//    role.display(); // ���������100������100
//
//    system("pause");
//    return 0;
//}