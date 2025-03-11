/** ����ģʽ�� ȫ�ַ��ʵ��ĸ��������ͬһʵ��
 *  ��C++11֮�󣬾ֲ���static������ ȫ���������ڡ�����ʼ��һ�Ρ��̰߳�ȫ
 *  ���static���������������ͷǳ�����
 */

#include <iostream>

//��������ʾ��
class CSingleton
{
private:
    CSingleton() = default;
    CSingleton(const CSingleton&) = delete;
    CSingleton& operator=(const CSingleton&) = delete;

public:
    static CSingleton& GetInstance() //����ʵ���ķ���
    {
        static CSingleton Ins;
        return Ins;
    }

    virtual ~CSingleton() {};

};

//��������ģ��
template <typename T>
class TSingleton
{
private:
    TSingleton() = default;
    TSingleton(const TSingleton<T>&) = delete;
    TSingleton& operator=(const TSingleton<T>&) = delete;
    friend T;//Ϊ���������� ʹ���Ϊ��Ԫ

public:
    static T& GetInstance() //����ʵ���ķ���
    {
        static T ins;
        return ins;
    }

    virtual ~TSingleton() {};
};

//ʵ����Ҫ��Ϊģ�����
class InsClass : public TSingleton<InsClass>//�̳�ʱ��дģ�����
{
public:
    virtual ~InsClass() {};
    //..һЩ����ĳ�Ա����
    void DoSomething() { std::cout << "InsClass ����ĳЩ��\n"; }
private:
    //һЩ����ĳ�Ա����
};

/*
int main()
{
    CSingleton::GetInstance();
    InsClass::GetInstance().DoSomething();
}
*/