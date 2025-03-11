/**
 * 外观模式：为程序库、 框架或其他复杂类提供一个简单的接口
 */

#include <iostream>
/**
 * Subsystem既可以接受来自facade的请求，也可以直接接受客户端的请求。
 * 无论如何，对于Subsystem来说，Facade是另一个客户端，而不是 Subsystem 的一部分。
 */
class Subsystem1 {
public:
    std::string Operation1() const {
        return "Subsystem1: 准备!\n";
    }
    // ...
    std::string OperationN() const {
        return "Subsystem1: 发车!\n";
    }
};
/**
 * 某些facades可同时与多个子系统协同工作
 */
class Subsystem2 {
public:
    std::string Operation1() const {
        return "Subsystem2: 准备!\n";
    }
    // ...
    std::string OperationZ() const {
        return "Subsystem2: 开火!\n";
    }
};

/**
 * Facade 类为一个或多个子系统的复杂逻辑提供了一个简单的接口。
 * Facade 将客户端请求委托给子系统内的相应对象。
 * Facade 还负责管理它们的生命周期。
 * 所有这些都使客户端免受子系统复杂性的影响。
 */
class Facade {
protected:
    Subsystem1* subsystem1_;
    Subsystem2* subsystem2_;
    /**
     * 根据应用程序的需要，可以向 Facade 提供现有的子系统对象，也可以强制 Facade 自行创建子系统对象
     */
public:
    Facade(Subsystem1* subsystem1 = nullptr,Subsystem2* subsystem2 = nullptr)
	{
        this->subsystem1_ = subsystem1 ? subsystem1 : new Subsystem1;
        this->subsystem2_ = subsystem2 ? subsystem2 : new Subsystem2;
    }
    ~Facade() {
        delete subsystem1_;
        delete subsystem2_;
    }
    /**
     * Facade 的方法是通向子系统复杂功能的便捷捷径。
     * 然而，客户端只能使用子系统功能的一小部分。
     */
    std::string Operation() {
        std::string result = "Facade 初始化子系统:\n";
        result += this->subsystem1_->Operation1();
        result += this->subsystem2_->Operation1();
        result += "Facade 命令子系统执行操作:\n";
        result += this->subsystem1_->OperationN();
        result += this->subsystem2_->OperationZ();
        return result;
    }
};

/**
 * 当facade管理子系统的生命周期时，客户端可能根本不知道子系统的存在。
 * 这种方法可以让复杂性得到控制
 */
void ClientCode(Facade* facade) {
    // ...
    std::cout << facade->Operation();
    // ...
}

//int main() {
//    Subsystem1* subsystem1 = new Subsystem1;
//    Subsystem2* subsystem2 = new Subsystem2;
//    Facade* facade = new Facade(subsystem1, subsystem2);
//    ClientCode(facade);
//
//    delete facade;
//
//    return 0;
//}