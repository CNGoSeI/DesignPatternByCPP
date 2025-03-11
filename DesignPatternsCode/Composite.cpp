/*
 * ���/������ ģʽ������������ϳ���״�ṹ�� ��������ʹ�ö�������һ��ʹ������
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
/**
 * Component���� ����������м򵥺͸��Ӷ����ͨ�ò���
 */
class Component {
    /**
     * @var Component
     */
protected:
    Component* parent_;
    /**
     * ��Ϊѡ�����Component��������һ���ӿڣ����������νṹ�����úͷ�������ĸ�����
     * ��������Ϊ��Щ�����ṩһЩĬ��ʵ��
     */
public:
    virtual ~Component() {}

    /*������ز���*/
    void SetParent(Component* parent) { this->parent_ = parent;}
    Component* GetParent() const { return this->parent_;}

    /**
     * ��ĳЩ����£��ڻ��� Component ����ֱ�Ӷ����������������Ƿǳ�����ġ�
     * ��������ʹ�ڶ�������װ�����У�Ҳ������ͻ��˴��빫���κξ��������ࡣ
     * ��������ȱ���ǣ�Ҷ���������Щ�������ǿյ�
     */
    virtual void Add(Component* component) {}
    virtual void Remove(Component* component) {}
    /**
     * �������ṩһ�ַ������ÿͻ��˴����ҳ�����Ƿ����������.
     */
    virtual bool IsComposite() const {
        return false;
    }
    /**
     * �����������ʵ��һЩĬ����Ϊ��Ҳ���Խ������������ࣨ��������Ϊ�ķ�������Ϊ ������"��
     */
    virtual std::string Operation() const = 0;
};

/**
 * Leaf �����һ����ϵ��ն˶���Ҷ�Ӳ������κ��Ӷ���
 * 
 * ͨ������£�Leaf ����ִ��ʵ�ʹ������� Composite����ֻί���������
 */
class Leaf : public Component {
public:
    std::string Operation() const override {
        return "Leaf";
    }
};
/**
 * Composite �����������ӽڵ�ĸ��������
 * ͨ�������϶���ʵ�ʹ���ί�и����Ӷ���Ȼ�� ������ �����
 */
class Composite : public Component {
    /**
     * @var \SplObjectStorage
     */
protected:
    std::list<Component*> children_;//�Ӷ���

public:
    /**
     * ���϶�����������Ӷ����б�����ӻ�ɾ����������������򵥻��������
     */
    void Add(Component* component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    /**
     * ��ע�⣬�÷�����ɾ��ָ���б��ָ�룬�������ͷ��ڴ棬���Ӧ�ֶ�ɾ����ʹ������ָ��
     */
    void Remove(Component* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }
    bool IsComposite() const override {
        return true;
    }
    /**
     * �ۺ�ϵͳ���ض���ʽִ������Ҫ�߼���
     * ���Եݹ鷽ʽ�����������Ӵ����ռ����������ǵĽ����
     * ���ڸ���Ԫ�ص���Ԫ�ػὫ��Щ���ô��ݸ����ǵ���Ԫ�أ�����������������ᱻ����
     */
    std::string Operation() const override {
        std::string result;
        for (const Component* c : children_) {
            //��Ϊ���һ�������+��
            if (c == children_.back()) {
                result += c->Operation();
            }
            else {
                result += c->Operation() + "+";
            }
        }
        return "��(" + result + ")";
    }
};
/**
 * ClientCode ͨ�������ӿ����������Эͬ����
 */
void ClientCode(Component* component) {
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}

/**
 * �����Ӵ�����������ڻ���������������ģ���˿ͻ��˴���������κ�������򵥻��ӣ�Эͬ���������������������ǵľ�����
 * ��component1���component2�����ҵ���component1��Operation()
 */
void ClientCode2(Component* component1, Component* component2) {
    // ...
    if (component1->IsComposite()) {
        component1->Add(component2);
    }
    std::cout << "RESULT: " << component1->Operation();
    // ...
}


/*
int main() {
    Component* simple = new Leaf;
    std::cout << "Client: ����һ���򵥵� Component:\n";
    ClientCode(simple);
    std::cout << "\n\n";

    Component* tree = new Composite;
    Component* branch1 = new Composite;

    Component* leaf_1 = new Leaf;
    Component* leaf_2 = new Leaf;
    Component* leaf_3 = new Leaf;
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);
    Component* branch2 = new Composite;
    branch2->Add(leaf_3);
    tree->Add(branch1);
    tree->Add(branch2);
    std::cout << "Client: ����������һ�ø�����:\n";
    ClientCode(tree);
    std::cout << "\n\n";

    std::cout << "Client: ��ʹ�ڹ�����ʱ����Ҳ����Ҫ��������:\n";
    ClientCode2(tree, simple);
    std::cout << "\n";

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    return 0;
}
*/