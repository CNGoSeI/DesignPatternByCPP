#include <iostream>
#include <xstring>

/** 对象适配器——所有流行编程语言都可以实现
 *
 */

 /*
  * Target 定义了客户端代码使用的特定域接口
  */
class Target {
public:
    virtual ~Target() = default;

    virtual std::string Request() const {
        return "Target: 默认目标行为";
    }
};

/**
 *  Adaptee 包含一些有用的行为，但其界面与现有的客户端代码不兼容。
 *  在使用 Adaptee 之前，需要对其进行一些调整
 */
class Adaptee {
public:
    std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

/**
 * 适配器(Adapter)使被适配者(Adaptee)的接口与目标(Target)的接口兼容
 */
class Adapter : public Target {
private:
    Adaptee* adaptee_;//被适配的目标

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}

    /*
     * 透过Target的Request()转调 Adaptee的SpecificRequest()
     * 并可以对齐进行适配操作
     */
    std::string Request() const override
	{
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (翻译) " + to_reverse;
    }
};

/* AdapterMul——多重基础的方式
 * 如果可以，直接适用多重继承的方式定义适配器
 * 这样，就不需要一个被适配者的成员了
 */
class AdapterMul : public Target, public Adaptee {
public:
    AdapterMul() {}
    std::string Request() const override {
        std::string to_reverse = SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

void ClientCode(const Target* target) {
    std::cout << target->Request();
}

/*
int main() {
    std::cout << "Client: 我可以很好地使用目标对象：\n";
    Target* target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee* adaptee = new Adaptee;
    std::cout << "Client: daptee 类有一个奇怪的接口。看，我不明白：\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: 但我可以通过适配器（Adapter）使用它\n";
    Adapter* adapter = new Adapter(adaptee);
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    system("pause");
    return 0;
}
*/