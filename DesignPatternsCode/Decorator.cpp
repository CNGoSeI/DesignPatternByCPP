/* *
 * װ����ģʽ�����ڲ��޸�ԭ��Ļ����ϣ�Ϊ�����һЩ����ʱ��������װ����ģʽ 
 */

#include <iostream>

/**
 * Component�ӿڶ����˿���װ�����ı�Ĳ���
 */
class Component {
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};
/**
 * ���������ConcreteComponent���ṩ������Ĭ��ʵ��
 * ��Щ������ж��ֱ��塣
 */
class ConcreteComponent : public Component {
public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};
/**
 * ����Decorator����ѭ�����������ͬ�Ľӿڡ�
 * �������ҪĿ���Ƕ������о���Decorator�ķ�װ�ӿڡ�
 * ��װ�����Ĭ��ʵ�ֿ��ܰ���һ�����ڴ洢��װ������ֶκͳ�ʼ������ķ�����
 */
class Decorator : public Component {
    /**
     * @var Component
     */
protected:
    Component* component_;

public:
    /*
     * ������������
     */
    Decorator(Component* component) : component_(component) {}
    /**
     * Decorator�����й���ί�и���װ���.
     */
    std::string Operation() const override {
        return this->component_->Operation();
    }
};
/**
 * ����װ�������÷�װ���󣬲���ĳ�ַ�ʽ�ı�����
 */
class ConcreteDecoratorA : public Decorator {
    /**
     * װ�������Ե��ò����ĸ�ʵ�֣�������ֱ�ӵ��÷�װ����
     * ���ַ�������װ���������չ
     */
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};
/**
 * װ���������ڵ��÷�װ����֮ǰ��֮��ִ������Ϊ
 */
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    std::string Operation() const override {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

void DecoratorClientCode(Component* component) {
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}

//int main() {
//
//    Component* simple = new ConcreteComponent;
//    std::cout << "Client:һ���򵥵� component:\n";
//    DecoratorClientCode(simple);
//    std::cout << "\n\n";
//    /**
//     * װ�����������԰�װ�򵥵�����������԰�װ����װ����
//     */
//    Component* decorator1 = new ConcreteDecoratorA(simple);
//    Component* decorator2 = new ConcreteDecoratorB(decorator1);
//    std::cout << "Client: ����һ��װ����� component:\n";
//    DecoratorClientCode(decorator2);
//    std::cout << "\n";
//
//    delete simple;
//    delete decorator1;
//    delete decorator2;
//
//    return 0;
//}