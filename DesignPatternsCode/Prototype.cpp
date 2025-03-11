#include <iostream>
#include <unordered_map>
#include <xstring>
using std::string;

/* -ԭ�����ģʽ
 * ��ͼ�������ڸ������ж���ʱ�����벻�����������ǵ���
 */

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

/**
 * ���п�¡���ܵ�ʾ���ࡣ���ǽ�������ο�¡��ͬ�����ֶε�ֵ
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
 * �ڱ����У�Prototype ����������ݳ�Ա���ڶ�ջ�С�
 * ��������������ָ�룬���磺String* name_���㽫��Ҫʵ�� Copy-Constructor�����ƹ��캯��������ȷ���� clone �����л����ȿ���
 * Ҳ����ģ�廯new�Ķ���
 */

class ConcretePrototype1 : public Prototype {
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}

    /**
     * ��ע�⣬Clone �����᷵��һ��ָ���µ� ConcretePrototype1 ���Ƶ�ָ�롣
     * ��ˣ��ͻ��ˣ����� clone �������ˣ��������ͷŸ��ڴ档
     * ���ܸ�ϲ����ʹ�� unique_pointer��
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

/** PrototypeFactory��һ�������࣬������������ö�ٲ�����ͬԭ�ͣ���ʡ��
 * �� PrototypeFactory �У�������������ԭ��
 * ���ÿ��Ҫ�����ӵ�ʱ������ʹ�����е�ԭ�Ͳ���¡���ǡ�
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
     * ��ע�⣬��ֻ��ָ�������ԭ�����ͣ��÷����ͻ�Ӹ����͵Ķ����д�����
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