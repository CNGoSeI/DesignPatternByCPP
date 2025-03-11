/*
 * 组合/对象树 模式——将对象组合成树状结构， 并且能像使用独立对象一样使用它们
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
/**
 * Component基类 声明了组合中简单和复杂对象的通用操作
 */
class Component {
    /**
     * @var Component
     */
protected:
    Component* parent_;
    /**
     * 作为选项，基本Component可以声明一个接口，用于在树形结构中设置和访问组件的父级。
     * 它还可以为这些方法提供一些默认实现
     */
public:
    virtual ~Component() {}

    /*父项相关操作*/
    void SetParent(Component* parent) { this->parent_ = parent;}
    Component* GetParent() const { return this->parent_;}

    /**
     * 在某些情况下，在基础 Component 类中直接定义子组件管理操作是非常有益的。
     * 这样，即使在对象树组装过程中，也无需向客户端代码公开任何具体的组件类。
     * 这样做的缺点是，叶级组件的这些方法将是空的
     */
    virtual void Add(Component* component) {}
    virtual void Remove(Component* component) {}
    /**
     * 您可以提供一种方法，让客户端代码找出组件是否可以生孩子.
     */
    virtual bool IsComposite() const {
        return false;
    }
    /**
     * 基础组件可以实现一些默认行为，也可以将其留给具体类（将包含行为的方法声明为 “抽象"）
     */
    virtual std::string Operation() const = 0;
};

/**
 * Leaf 类代表一个组合的终端对象。叶子不能有任何子对象。
 * 
 * 通常情况下，Leaf 对象执行实际工作，而 Composite对象只委托其子组件
 */
class Leaf : public Component {
public:
    std::string Operation() const override {
        return "Leaf";
    }
};
/**
 * Composite 类代表可能有子节点的复杂组件。
 * 通常，复合对象将实际工作委托给其子对象，然后 “汇总 ”结果
 */
class Composite : public Component {
    /**
     * @var \SplObjectStorage
     */
protected:
    std::list<Component*> children_;//子对象

public:
    /**
     * 复合对象可以在其子对象列表中添加或删除其他组件（包括简单或复杂组件）
     */
    void Add(Component* component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    /**
     * 请注意，该方法会删除指向列表的指针，但不会释放内存，因此应手动删除或使用智能指针
     */
    void Remove(Component* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }
    bool IsComposite() const override {
        return true;
    }
    /**
     * 综合系统以特定方式执行其主要逻辑。
     * 它以递归方式遍历其所有子代，收集并汇总它们的结果。
     * 由于复合元素的子元素会将这些调用传递给它们的子元素，因此整个对象树都会被遍历
     */
    std::string Operation() const override {
        std::string result;
        for (const Component* c : children_) {
            //不为最后一个则添加+号
            if (c == children_.back()) {
                result += c->Operation();
            }
            else {
                result += c->Operation() + "+";
            }
        }
        return "树(" + result + ")";
    }
};
/**
 * ClientCode 通过基础接口与所有组件协同工作
 */
void ClientCode(Component* component) {
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}

/**
 * 由于子代管理操作是在基本组件类中声明的，因此客户端代码可以与任何组件（简单或复杂）协同工作，而无需依赖于它们的具体类
 * 向component1添加component2，并且调用component1的Operation()
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
    std::cout << "Client: 我有一个简单的 Component:\n";
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
    std::cout << "Client: 现在我有了一棵复合树:\n";
    ClientCode(tree);
    std::cout << "\n\n";

    std::cout << "Client: 即使在管理树时，我也不需要检查组件类:\n";
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