/* *
 * 装饰器模式：想在不修改原类的基础上，为类添加一些功能时，可以用装饰器模式 
 */

#include <iostream>

/**
 * Component接口定义了可由装饰器改变的操作
 */
class Component {
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};
/**
 * 具体组件（ConcreteComponent）提供操作的默认实现
 * 这些类可能有多种变体。
 */
class ConcreteComponent : public Component {
public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};
/**
 * 基本Decorator类遵循与其他组件相同的接口。
 * 该类的主要目的是定义所有具体Decorator的封装接口。
 * 封装代码的默认实现可能包括一个用于存储封装组件的字段和初始化组件的方法。
 */
class Decorator : public Component {
    /**
     * @var Component
     */
protected:
    Component* component_;

public:
    /*
     * 采用其他部件
     */
    Decorator(Component* component) : component_(component) {}
    /**
     * Decorator将所有工作委托给封装组件.
     */
    std::string Operation() const override {
        return this->component_->Operation();
    }
};
/**
 * 具体装饰器调用封装对象，并以某种方式改变其结果
 */
class ConcreteDecoratorA : public Decorator {
    /**
     * 装饰器可以调用操作的父实现，而不是直接调用封装对象。
     * 这种方法简化了装饰器类的扩展
     */
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};
/**
 * 装饰器可以在调用封装对象之前或之后执行其行为
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
//    std::cout << "Client:一个简单的 component:\n";
//    DecoratorClientCode(simple);
//    std::cout << "\n\n";
//    /**
//     * 装饰器不仅可以包装简单的组件，还可以包装其他装饰器
//     */
//    Component* decorator1 = new ConcreteDecoratorA(simple);
//    Component* decorator2 = new ConcreteDecoratorB(decorator1);
//    std::cout << "Client: 有了一个装饰组件 component:\n";
//    DecoratorClientCode(decorator2);
//    std::cout << "\n";
//
//    delete simple;
//    delete decorator1;
//    delete decorator2;
//
//    return 0;
//}