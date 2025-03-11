#include <iostream>
#include <unordered_map>
#include <string>

// ������Ԫ�ࣺ�����ַ���ʾ�ӿ�
class Character {
public:
    virtual void display(int fontSize, const std::string& color) = 0;
    virtual ~Character() = default;
};

// ������Ԫ�ࣺ�洢������ַ����ڲ�״̬��
class ConcreteCharacter : public Character {
private:
    char m_char;  // �ڲ�״̬������
public:
    explicit ConcreteCharacter(char c) : m_char(c) {}

    void display(int fontSize, const std::string& color) override {
        std::cout << "�ַ�: " << m_char
            << " | �ֺ�: " << fontSize
            << " | ��ɫ: " << color << std::endl;
    }
};

// ��Ԫ�����ࣺ�����ַ�����Ĵ����빲��
class CharacterFactory {
private:
    std::unordered_map<char, Character*> m_charPool;  // �ַ������

public:
    Character* getCharacter(char c) {
        if (m_charPool.find(c) == m_charPool.end()) {
            m_charPool[c] = new ConcreteCharacter(c); // �������򴴽��¶���
            std::cout << "�������ַ�����: " << c << std::endl;
        }
        return m_charPool[c]; // ���ع������
    }

    ~CharacterFactory() {
        for (auto& pair : m_charPool) {
            delete pair.second; // �ͷ��ڴ�
        }
    }
};

/*
int main() {
    CharacterFactory factory;

    // �����ַ���"Hello,���ģʽ"
    std::string text = "Hello,DS";

    for (char c : text) {
        Character* character = factory.getCharacter(c);
        // �ⲿ״̬���ֺš���ɫ���ɿͻ��˴���
        character->display(12, "��ɫ");
    }

    // ��֤�����ظ��ַ�ʹ��ͬһ����
    Character* h1 = factory.getCharacter('H');
    Character* h2 = factory.getCharacter('H');
    std::cout << "H�ַ������ַ�Ƿ���ͬ: " << std::boolalpha
        << (h1 == h2) << std::endl; // ���true

    system("pause");
    return 0;
}
*/