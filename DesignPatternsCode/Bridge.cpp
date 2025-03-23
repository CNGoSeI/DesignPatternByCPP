/** 桥接模式
 * 将功能拆分为不同类（读类、写类），不同类各自有自己的子类（读文本、视频...；写文本、视频...）
 * 而不同类功能类之间又存在依赖关系(读文本的类需要写文本的类进行写入)
 */
#include <iostream>
#include <ostream>

 /* Implementation定义了所有实现类的接口。
  * 它不必与抽象的接口相匹配。
  * 事实上，这两个接口可以完全不同。
  * 通常情况下，实现接口只提供基本操作，而抽象接口则在这些基本操作的基础上定义更高级别的操作
  */
class Implementation {
public:
    virtual ~Implementation() {}
    virtual std::string OperationImplementation() const = 0;
};

/**
 * 每个具体实现（ConcreteImplementation）都对应一个特定的平台，并 使用该平台的 API 实现实现接口
 */
class ConcreteImplementationA : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationA: 这下是平台上的结果 A.\n";
    }
};
class ConcreteImplementationB : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationB: 这下是平台上的结果 B.\n";
    }
};

/**
 *  Abstraction定义了两个类层次结构中 “控制 ”部分的接口。
 *  它维护对实现层次结构对象的引用，并将所有实际工作委托给该对象
 */
class Abstraction {
    /**
     * @var Implementation
     */
protected:
    Implementation* implementation_;

public:
    //通过Implementation对象初始化Abstraction，这样不同的Abstraction调用的接口实现不同
    Abstraction(Implementation* implementation) : implementation_(implementation) {}

    virtual ~Abstraction() {}

    virtual std::string Operation() const {
        return "Abstraction: Base operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};
/**
 * 您可以在不改变Abstraction类的情况下扩展Implementation类
 */
class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {}
    std::string Operation() const override {
        return "ExtendedAbstraction: Extended operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

/**
 * 在初始化阶段，Implementation对象会与特定的Abstraction对象相连接，除此之外，客户机代码应该只依赖于Abstraction类。
 * 这样，ClientCode就能支持任何抽象与实现的组合
 */
void ClientCode(const Abstraction& abstraction) {
    // ...
    std::cout << abstraction.Operation();
    // ...
}

/*
int main() {
    Implementation* implementation = new ConcreteImplementationA;
    Abstraction* abstraction = new Abstraction(implementation);
    ClientCode(*abstraction);
    std::cout << std::endl;
    delete implementation;
    delete abstraction;

    implementation = new ConcreteImplementationB;
    abstraction = new ExtendedAbstraction(implementation);
    ClientCode(*abstraction);

    delete implementation;
    delete abstraction;

    return 0;
}
*/
