#include <iostream>
#include <xstring>

/** ���������������������б�����Զ�����ʵ��
 *
 */

 /*
  * Target �����˿ͻ��˴���ʹ�õ��ض���ӿ�
  */
class Target {
public:
    virtual ~Target() = default;

    virtual std::string Request() const {
        return "Target: Ĭ��Ŀ����Ϊ";
    }
};

/**
 *  Adaptee ����һЩ���õ���Ϊ��������������еĿͻ��˴��벻���ݡ�
 *  ��ʹ�� Adaptee ֮ǰ����Ҫ�������һЩ����
 */
class Adaptee {
public:
    std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

/**
 * ������(Adapter)ʹ��������(Adaptee)�Ľӿ���Ŀ��(Target)�Ľӿڼ���
 */
class Adapter : public Target {
private:
    Adaptee* adaptee_;//�������Ŀ��

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}

    /*
     * ͸��Target��Request()ת�� Adaptee��SpecificRequest()
     * �����Զ�������������
     */
    std::string Request() const override
	{
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (����) " + to_reverse;
    }
};

/* AdapterMul�������ػ����ķ�ʽ
 * ������ԣ�ֱ�����ö��ؼ̳еķ�ʽ����������
 * �������Ͳ���Ҫһ���������ߵĳ�Ա��
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
    std::cout << "Client: �ҿ��Ժܺõ�ʹ��Ŀ�����\n";
    Target* target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee* adaptee = new Adaptee;
    std::cout << "Client: daptee ����һ����ֵĽӿڡ������Ҳ����ף�\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: ���ҿ���ͨ����������Adapter��ʹ����\n";
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