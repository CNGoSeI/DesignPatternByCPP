#include <iostream>
#include <string>

// �����н��߽ӿڣ�����Э������
// ����֪ͨ����������������н��߷����¼�֪ͨ[5,7](@ref)
class BaseComponent;

//�н���
class Mediator {
public:
    virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

// ��������ࣨ����ͬ����Ļ��ࣩ
// �����н������ã�ʵ�����н��ߵ������[1,6](@ref)
class BaseComponent {
protected:
    Mediator* mediator_;  // �ؼ���ƣ��������ֻ�����н��߽ӿ�

public:
    BaseComponent(Mediator* mediator = nullptr) : mediator_(mediator) {}
    // ��̬�����н��ߣ�֧������ʱ��
    void set_mediator(Mediator* mediator) {
        this->mediator_ = mediator;
    }
};

// �������1��ͬ����A��
// ʵ�ֶ���ҵ���ܣ�ͨ���н���Э�����������[5,7](@ref)
class Component1 : public BaseComponent {
public:
    // ҵ�����A��������ͨ���н���֪ͨ������
    void DoA() {
        std::cout << "���1ִ�в���A\n";
        this->mediator_->Notify(this, "A");  // �ؼ��¼����ݻ���
    }

    // ҵ�����B���ɱ��������ͨ���н��ߴ���
    void DoB() {
        std::cout << "���1ִ�в���B\n";
        this->mediator_->Notify(this, "B");
    }
};

// �������2��ͬ����B��
// ͨ���н���ʵ�������1�ļ��ͨ��[6,7](@ref)
class Component2 : public BaseComponent {
public:
    void DoC() {
        std::cout << "���2ִ�в���C\n";
        this->mediator_->Notify(this, "C");
    }

    void DoD() {
        std::cout << "���2ִ�в���D\n";
        this->mediator_->Notify(this, "D");  // ���������Э������ڵ�
    }
};

// �����н���ʵ�֣�Э�����ģ�
// ��װ����临�ӵĽ����߼�[1,5](@ref)
class ConcreteMediator : public Mediator {
private:
    Component1* component1_;
    Component2* component2_;

public:
    // ��ʼ��ʱ����˫��󶨣��ؼ����õ㣩
    ConcreteMediator(Component1* c1, Component2* c2)
        : component1_(c1), component2_(c2) {
        this->component1_->set_mediator(this);  // ע���н�������
        this->component2_->set_mediator(this);
    }

    // �¼��������ࣨ����Э���߼���[5,7](@ref)
    void Notify(BaseComponent* sender, std::string event) const override {
        // ����1�����A�Ĳ����������C����Ӧ
        if (event == "A") {
            std::cout << "�н�����ӦA�¼�������Э��������\n";
            this->component2_->DoC();  // ���������
        }

        // ����2�����D�Ĳ�������������Ӧ
        if (event == "D") {
            std::cout << "�н�����ӦD�¼�����������������\n";
            this->component1_->DoB();  // �ȴ������B
            this->component2_->DoC();  // �ٴ������C
        }
    }
};

// �ͻ�����ʾ����
void ClientCode() {
    Component1* c1 = new Component1;
    Component2* c2 = new Component2;
    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);

    std::cout << "\n�ͻ��˴�������A��\n";
    c1->DoA();  // ��ʾ���¼�����

    std::cout << "\n�ͻ��˴�������D��\n";
    c2->DoD();  // ��ʾ����Э���߼�

    delete c1;
    delete c2;
    delete mediator;
}

/*
int main() {
    ClientCode();
    return 0;
}
*/