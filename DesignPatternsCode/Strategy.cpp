/**
 * 策略模式：将每种折扣逻辑封装为独立策略类，收银系统只需切换策略对象即可动态计算价格
 */
#include <iostream>
#include <memory>

// 策略接口：折扣计算规则
class DiscountStrategy {
public:
    virtual double applyDiscount(double originalPrice) = 0;
    virtual ~DiscountStrategy() = default;
};

// 具体策略类：新客户无折扣
class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double originalPrice) override {
        return originalPrice;
    }
};

// 具体策略类：VIP客户8折
class VipDiscount : public DiscountStrategy {
public:
    double applyDiscount(double originalPrice) override {
        return originalPrice * 0.8;
    }
};

// 上下文类：收银系统
class ShoppingCart {
private:
    std::unique_ptr<DiscountStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<DiscountStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    double checkout(double price) {
        return strategy ? strategy->applyDiscount(price) : price;
    }
};

// 客户端调用
//int main() {
//    ShoppingCart cart;
//
//    // 默认策略：新客户
//    cart.setStrategy(std::make_unique<NoDiscount>());
//    std::cout << "新客户价格: " << cart.checkout(100.0) << std::endl; // 输出100
//
//    // 切换策略：VIP客户
//    cart.setStrategy(std::make_unique<VipDiscount>());
//    std::cout << "VIP客户价格: " << cart.checkout(100.0) << std::endl; // 输出80
//
//    return 0;
//}