#include <iostream>
#include <string>

// 抽象中介者接口（核心协调器）
// 声明通知方法，用于组件向中介者发送事件通知[5,7](@ref)
class BaseComponent;

//中介者
class Mediator {
public:
    virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

// 基础组件类（所有同事类的基类）
// 包含中介者引用，实现与中介者的松耦合[1,6](@ref)
class BaseComponent {
protected:
    Mediator* mediator_;  // 关键设计：所有组件只依赖中介者接口

public:
    BaseComponent(Mediator* mediator = nullptr) : mediator_(mediator) {}
    // 动态设置中介者，支持运行时绑定
    void set_mediator(Mediator* mediator) {
        this->mediator_ = mediator;
    }
};

// 具体组件1（同事类A）
// 实现独立业务功能，通过中介者协调跨组件操作[5,7](@ref)
class Component1 : public BaseComponent {
public:
    // 业务操作A：触发后通过中介者通知相关组件
    void DoA() {
        std::cout << "组件1执行操作A\n";
        this->mediator_->Notify(this, "A");  // 关键事件传递机制
    }

    // 业务操作B：可被其他组件通过中介者触发
    void DoB() {
        std::cout << "组件1执行操作B\n";
        this->mediator_->Notify(this, "B");
    }
};

// 具体组件2（同事类B）
// 通过中介者实现与组件1的间接通信[6,7](@ref)
class Component2 : public BaseComponent {
public:
    void DoC() {
        std::cout << "组件2执行操作C\n";
        this->mediator_->Notify(this, "C");
    }

    void DoD() {
        std::cout << "组件2执行操作D\n";
        this->mediator_->Notify(this, "D");  // 触发跨组件协调的入口点
    }
};

// 具体中介者实现（协调中心）
// 封装组件间复杂的交互逻辑[1,5](@ref)
class ConcreteMediator : public Mediator {
private:
    Component1* component1_;
    Component2* component2_;

public:
    // 初始化时建立双向绑定（关键设置点）
    ConcreteMediator(Component1* c1, Component2* c2)
        : component1_(c1), component2_(c2) {
        this->component1_->set_mediator(this);  // 注入中介者引用
        this->component2_->set_mediator(this);
    }

    // 事件处理中枢（核心协调逻辑）[5,7](@ref)
    void Notify(BaseComponent* sender, std::string event) const override {
        // 规则1：组件A的操作触发组件C的响应
        if (event == "A") {
            std::cout << "中介者响应A事件，触发协调操作：\n";
            this->component2_->DoC();  // 跨组件调用
        }

        // 规则2：组件D的操作触发级联响应
        if (event == "D") {
            std::cout << "中介者响应D事件，触发级联操作：\n";
            this->component1_->DoB();  // 先触发组件B
            this->component2_->DoC();  // 再触发组件C
        }
    }
};

// 客户端演示代码
void ClientCode() {
    Component1* c1 = new Component1;
    Component2* c2 = new Component2;
    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);

    std::cout << "\n客户端触发操作A：\n";
    c1->DoA();  // 演示简单事件传递

    std::cout << "\n客户端触发操作D：\n";
    c2->DoD();  // 演示复杂协调逻辑

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