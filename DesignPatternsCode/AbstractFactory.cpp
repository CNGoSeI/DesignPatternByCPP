#include <iostream>
#include <string>

/** 抽象工厂：创建一系列相关的对象， 而无需指定其具体类
 * 抽象工厂定义了用于创建不同产品的接口， 但将实际的创建工作留给了具体工厂类。 每个工厂类型都对应一个特定的产品变体
 * 
 *
 * 仅通过其抽象接口与工厂和产品进行交互。 该接口允许同一客户端代码与不同产品进行交互。 你只需创建一个具体工厂类并将其传递给客户端代码即可 ClientCode()。
*/

/* AbstractProductA：产品的工厂接口
 * Product系列中的每个不同Product都应有一个基本接口 UsefulFunctionA 。
 * 所有Product的所有变体都必须实现该接口。
 */
class AbstractProductA {
public:
    virtual ~AbstractProductA() {};
    virtual std::string UsefulFunctionA() const = 0;
};

/**
 * Concrete实例由相应的工厂类产生
 */
class ConcreteProductA1 : public AbstractProductA {
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA {
    std::string UsefulFunctionA() const override {
        return "The result of the product A2.";
    }
};

/** AbstractProductB：另一种产品的工厂接口
 * 
 * 所有Product都可以相互影响，但只有在相同具体变体的Product之间才能实现适当的相互影响
 */
class AbstractProductB {
    /**
     * ProductB 可以做自己的事情...
     */
public:
    virtual ~AbstractProductB() {};
    virtual std::string UsefulFunctionB() const = 0;
    /**
     * ...但也能通过ProductA 实例调用其对应的方法
     *
     * 抽象工厂会确保它创建的所有产品都属于相同的变体，因此是兼容的
     */
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;
};

/**
 * ConcreteProductBX 派生自 AbstractProductB
 */
class ConcreteProductB1 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B1.";
    }
    /**
     * 变体 “Product B1 ”只能与变体一起正常工作
     * collaborator 接受任何 AbstractProductA 的实例作为参数
     */
    std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B2.";
    }
    /**
     * 变体 “Product B2 ”只能与变体一起正常工作
     * collaborator 接受任何 AbstractProductA 的实例作为参数
     */
    std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

/** AbstractFactory：抽象工厂接口声明了一组方法，可返回不同的抽象产品。
 * 
 * 这些产品被称为一个系列，通过一个高级主题或概念相互关联。
 * 一个系列的产品通常可以相互协作。一个产品系列可能有多个变体，但其中一个变体的产品与另一个变体的产品不兼容
 * 该例子中存在两组产品
 */
class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};

/** ConcreteFactory1 工厂
 *
 * Concrete工厂生产属于单一变体的产品系列。工厂保证所生产的产品是兼容的。
 * 请注意，具体工厂方法的签名返回的是抽象产品、 而在方法内部则实例化一个具体产品
 */
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override { //CreateProductA 产生A1
        return new ConcreteProductA1();
    }
    AbstractProductB* CreateProductB() const override { //CreateProductB 产生B1
        return new ConcreteProductB1();
    }
};

/** ConcreteFactory2 工厂
 * 每个Concrete工厂都有一个相应的产品变体。
 */
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override { //CreateProductA 产生A2
        return new ConcreteProductA2(); 
    }
    AbstractProductB* CreateProductB() const override { //CreateProductB 产生B2
        return new ConcreteProductB2();
    }
};

/**
 * 客户端代码只能通过抽象类型来处理工厂和产品： 抽象工厂（AbstractFactory）和抽象产品（AbstractProduct）。
 * 这样，你就可以将任何工厂或产品子类传递给客户端代码，而不会破坏它
 */

void ClientCode(const AbstractFactory& factory) {
        const AbstractProductA* product_a = factory.CreateProductA();
        const AbstractProductB* product_b = factory.CreateProductB();
        std::cout << product_b->UsefulFunctionB() << "\n";
        std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
        delete product_a;
        delete product_b;
}

/*
int main() {

    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1* f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2* f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    return 0;
}
*/