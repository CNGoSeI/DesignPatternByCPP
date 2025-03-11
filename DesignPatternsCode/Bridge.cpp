/** �Ž�ģʽ
 */
#include <iostream>
#include <ostream>

 /* Implementation����������ʵ����Ľӿڡ�
  * �����������Ľӿ���ƥ�䡣
  * ��ʵ�ϣ��������ӿڿ�����ȫ��ͬ��
  * ͨ������£�ʵ�ֽӿ�ֻ�ṩ����������������ӿ�������Щ���������Ļ����϶�����߼���Ĳ���
  */
class Implementation {
public:
    virtual ~Implementation() {}
    virtual std::string OperationImplementation() const = 0;
};

/**
 * ÿ������ʵ�֣�ConcreteImplementation������Ӧһ���ض���ƽ̨���� ʹ�ø�ƽ̨�� API ʵ��ʵ�ֽӿ�
 */
class ConcreteImplementationA : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationA: ������ƽ̨�ϵĽ�� A.\n";
    }
};
class ConcreteImplementationB : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationB: ������ƽ̨�ϵĽ�� B.\n";
    }
};

/**
 *  Abstraction�������������νṹ�� ������ �����ֵĽӿڡ�
 *  ��ά����ʵ�ֲ�νṹ��������ã���������ʵ�ʹ���ί�и��ö���
 */
class Abstraction {
    /**
     * @var Implementation
     */
protected:
    Implementation* implementation_;

public:
    //ͨ��Implementation�����ʼ��Abstraction��������ͬ��Abstraction���õĽӿ�ʵ�ֲ�ͬ
    Abstraction(Implementation* implementation) : implementation_(implementation) {}

    virtual ~Abstraction() {}

    virtual std::string Operation() const {
        return "Abstraction: Base operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};
/**
 * �������ڲ��ı�Abstraction����������չImplementation��
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
 * �ڳ�ʼ���׶Σ�Implementation��������ض���Abstraction���������ӣ�����֮�⣬�ͻ�������Ӧ��ֻ������Abstraction�ࡣ
 * ������ClientCode����֧���κγ�����ʵ�ֵ����
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