/**
 * 模板方法将通用流程封装在抽象类中，差异步骤由子类实现
 */
#include <iostream>

// 抽象类：饮料制作模板
class BeverageTemplate {
public:
    // 模板方法（固定流程）
    void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    // 通用步骤
    void boilWater() { std::cout << "烧水..." << std::endl; }
    void pourInCup() { std::cout << "倒入杯子..." << std::endl; }

    // 需子类实现的抽象步骤
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    virtual ~BeverageTemplate() = default;
};

// 具体子类：咖啡
class Coffee : public BeverageTemplate {
public:
    void brew() override { std::cout << "冲泡咖啡粉..." << std::endl; }
    void addCondiments() override { std::cout << "加入牛奶和糖..." << std::endl; }
};

// 具体子类：茶
class Tea : public BeverageTemplate {
public:
    void brew() override { std::cout << "浸泡茶叶..." << std::endl; }
    void addCondiments() override { std::cout << "加入柠檬..." << std::endl; }
};

// 客户端调用
//int main() {
//    BeverageTemplate* coffee = new Coffee();
//    coffee->prepareBeverage();  // 输出咖啡制作流程
//
//    BeverageTemplate* tea = new Tea();
//    tea->prepareBeverage();     // 输出茶制作流程
//
//    delete coffee;
//    delete tea;
//    return 0;
//}