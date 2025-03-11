/**
 * ���ģʽ��Ϊ����⡢ ��ܻ������������ṩһ���򵥵Ľӿ�
 */

#include <iostream>
/**
 * Subsystem�ȿ��Խ�������facade������Ҳ����ֱ�ӽ��ܿͻ��˵�����
 * ������Σ�����Subsystem��˵��Facade����һ���ͻ��ˣ������� Subsystem ��һ���֡�
 */
class Subsystem1 {
public:
    std::string Operation1() const {
        return "Subsystem1: ׼��!\n";
    }
    // ...
    std::string OperationN() const {
        return "Subsystem1: ����!\n";
    }
};
/**
 * ĳЩfacades��ͬʱ������ϵͳЭͬ����
 */
class Subsystem2 {
public:
    std::string Operation1() const {
        return "Subsystem2: ׼��!\n";
    }
    // ...
    std::string OperationZ() const {
        return "Subsystem2: ����!\n";
    }
};

/**
 * Facade ��Ϊһ��������ϵͳ�ĸ����߼��ṩ��һ���򵥵Ľӿڡ�
 * Facade ���ͻ�������ί�и���ϵͳ�ڵ���Ӧ����
 * Facade ������������ǵ��������ڡ�
 * ������Щ��ʹ�ͻ���������ϵͳ�����Ե�Ӱ�졣
 */
class Facade {
protected:
    Subsystem1* subsystem1_;
    Subsystem2* subsystem2_;
    /**
     * ����Ӧ�ó������Ҫ�������� Facade �ṩ���е���ϵͳ����Ҳ����ǿ�� Facade ���д�����ϵͳ����
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
     * Facade �ķ�����ͨ����ϵͳ���ӹ��ܵı�ݽݾ���
     * Ȼ�����ͻ���ֻ��ʹ����ϵͳ���ܵ�һС���֡�
     */
    std::string Operation() {
        std::string result = "Facade ��ʼ����ϵͳ:\n";
        result += this->subsystem1_->Operation1();
        result += this->subsystem2_->Operation1();
        result += "Facade ������ϵͳִ�в���:\n";
        result += this->subsystem1_->OperationN();
        result += this->subsystem2_->OperationZ();
        return result;
    }
};

/**
 * ��facade������ϵͳ����������ʱ���ͻ��˿��ܸ�����֪����ϵͳ�Ĵ��ڡ�
 * ���ַ��������ø����Եõ�����
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