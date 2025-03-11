#include <iostream>
#include <unordered_map>
#include <string>

// 抽象享元类：定义字符显示接口
class Character {
public:
    virtual void display(int fontSize, const std::string& color) = 0;
    virtual ~Character() = default;
};

// 具体享元类：存储共享的字符（内部状态）
class ConcreteCharacter : public Character {
private:
    char m_char;  // 内部状态（共享）
public:
    explicit ConcreteCharacter(char c) : m_char(c) {}

    void display(int fontSize, const std::string& color) override {
        std::cout << "字符: " << m_char
            << " | 字号: " << fontSize
            << " | 颜色: " << color << std::endl;
    }
};

// 享元工厂类：管理字符对象的创建与共享
class CharacterFactory {
private:
    std::unordered_map<char, Character*> m_charPool;  // 字符对象池

public:
    Character* getCharacter(char c) {
        if (m_charPool.find(c) == m_charPool.end()) {
            m_charPool[c] = new ConcreteCharacter(c); // 不存在则创建新对象
            std::cout << "创建新字符对象: " << c << std::endl;
        }
        return m_charPool[c]; // 返回共享对象
    }

    ~CharacterFactory() {
        for (auto& pair : m_charPool) {
            delete pair.second; // 释放内存
        }
    }
};

/*
int main() {
    CharacterFactory factory;

    // 输入字符串"Hello,设计模式"
    std::string text = "Hello,DS";

    for (char c : text) {
        Character* character = factory.getCharacter(c);
        // 外部状态（字号、颜色）由客户端传递
        character->display(12, "黑色");
    }

    // 验证共享：重复字符使用同一对象
    Character* h1 = factory.getCharacter('H');
    Character* h2 = factory.getCharacter('H');
    std::cout << "H字符对象地址是否相同: " << std::boolalpha
        << (h1 == h2) << std::endl; // 输出true

    system("pause");
    return 0;
}
*/