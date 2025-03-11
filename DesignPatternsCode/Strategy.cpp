/**
 * ����ģʽ����ÿ���ۿ��߼���װΪ���������࣬����ϵͳֻ���л����Զ��󼴿ɶ�̬����۸�
 */
#include <iostream>
#include <memory>

// ���Խӿڣ��ۿۼ������
class DiscountStrategy {
public:
    virtual double applyDiscount(double originalPrice) = 0;
    virtual ~DiscountStrategy() = default;
};

// ��������ࣺ�¿ͻ����ۿ�
class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double originalPrice) override {
        return originalPrice;
    }
};

// ��������ࣺVIP�ͻ�8��
class VipDiscount : public DiscountStrategy {
public:
    double applyDiscount(double originalPrice) override {
        return originalPrice * 0.8;
    }
};

// �������ࣺ����ϵͳ
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

// �ͻ��˵���
//int main() {
//    ShoppingCart cart;
//
//    // Ĭ�ϲ��ԣ��¿ͻ�
//    cart.setStrategy(std::make_unique<NoDiscount>());
//    std::cout << "�¿ͻ��۸�: " << cart.checkout(100.0) << std::endl; // ���100
//
//    // �л����ԣ�VIP�ͻ�
//    cart.setStrategy(std::make_unique<VipDiscount>());
//    std::cout << "VIP�ͻ��۸�: " << cart.checkout(100.0) << std::endl; // ���80
//
//    return 0;
//}