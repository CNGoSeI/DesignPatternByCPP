/**
 * ģ�巽����ͨ�����̷�װ�ڳ������У����첽��������ʵ��
 */
#include <iostream>

// �����ࣺ��������ģ��
class BeverageTemplate {
public:
    // ģ�巽�����̶����̣�
    void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    // ͨ�ò���
    void boilWater() { std::cout << "��ˮ..." << std::endl; }
    void pourInCup() { std::cout << "���뱭��..." << std::endl; }

    // ������ʵ�ֵĳ�����
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    virtual ~BeverageTemplate() = default;
};

// �������ࣺ����
class Coffee : public BeverageTemplate {
public:
    void brew() override { std::cout << "���ݿ��ȷ�..." << std::endl; }
    void addCondiments() override { std::cout << "����ţ�̺���..." << std::endl; }
};

// �������ࣺ��
class Tea : public BeverageTemplate {
public:
    void brew() override { std::cout << "���ݲ�Ҷ..." << std::endl; }
    void addCondiments() override { std::cout << "��������..." << std::endl; }
};

// �ͻ��˵���
//int main() {
//    BeverageTemplate* coffee = new Coffee();
//    coffee->prepareBeverage();  // ���������������
//
//    BeverageTemplate* tea = new Tea();
//    tea->prepareBeverage();     // �������������
//
//    delete coffee;
//    delete tea;
//    return 0;
//}