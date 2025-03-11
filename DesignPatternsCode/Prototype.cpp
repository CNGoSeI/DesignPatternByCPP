#include <iostream>
#include <unordered_map>
#include <xstring>
using std::string;

/* -原型设计模式
 * 意图：让你在复制现有对象时，代码不会依赖于它们的类
 */

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

/**
 * 具有克隆功能的示例类。我们将看到如何克隆不同类型字段的值
 */

class Prototype {
protected:
    string prototype_name_;
    float prototype_field_;

public:
    Prototype() {}
    Prototype(string prototype_name): prototype_name_(prototype_name){}
    virtual ~Prototype() {}

    virtual Prototype* Clone() const = 0;

    virtual void Method(float prototype_field)
	{
        this->prototype_field_ = prototype_field;
        std::cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << std::endl;
    }
};

/**
 * 在本例中，Prototype 类的所有数据成员都在堆栈中。
 * 如果你的属性中有指针，例如：String* name_，你将需要实现 Copy-Constructor（复制构造函数），以确保从 clone 方法中获得深度拷贝
 * 也可以模板化new的对象
 */

class ConcretePrototype1 : public Prototype {
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}

    /**
     * 请注意，Clone 方法会返回一个指向新的 ConcretePrototype1 复制的指针。
     * 因此，客户端（调用 clone 方法的人）有责任释放该内存。
     * 可能更喜欢在使用 unique_pointer。
     */
    Prototype* Clone() const override
	{
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype {
private:
    float concrete_prototype_field2_;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field) {}
    Prototype* Clone() const override
	{
        return new ConcretePrototype2(*this);
    }
};

/** PrototypeFactory是一个集中类，用来工具输入枚举产生不同原型，可省略
 * 在 PrototypeFactory 中，你有两个具体原型
 * 因此每次要创建子弹时，可以使用现有的原型并克隆它们。
 */

class PrototypeFactory {
private:
    std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
    PrototypeFactory() {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
    }

    ~PrototypeFactory() {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    /**
     * 请注意，您只需指定所需的原型类型，该方法就会从该类型的对象中创建。
     */
    Prototype* CreatePrototype(Type type) {
        return prototypes_[type]->Clone();
    }
};

void Client(PrototypeFactory& prototype_factory) {
    std::cout << "Let's create a Prototype 1\n";

    Prototype* prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->Method(90);
    delete prototype;

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2 \n";

    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->Method(10);

    delete prototype;
}

/*
int main() {
    PrototypeFactory* prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}
*/