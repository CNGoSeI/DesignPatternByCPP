/** 单例模式： 全局访问到的该类对象都是同一实例
 *  在C++11之后，局部的static变量是 全局生命周期、仅初始化一次、线程安全
 *  因此static用作单例变量类型非常合适
 */

#include <iostream>

//基础单例示例
class CSingleton
{
private:
    CSingleton() = default;
    CSingleton(const CSingleton&) = delete;
    CSingleton& operator=(const CSingleton&) = delete;

public:
    static CSingleton& GetInstance() //返回实例的方法
    {
        static CSingleton Ins;
        return Ins;
    }

    virtual ~CSingleton() {};

};

//单例基类模板
template <typename T>
class TSingleton
{
private:
    TSingleton() = default;
    TSingleton(const TSingleton<T>&) = delete;
    TSingleton& operator=(const TSingleton<T>&) = delete;
    friend T;//为了正常访问 使其成为友元

public:
    static T& GetInstance() //返回实例的方法
    {
        static T ins;
        return ins;
    }

    virtual ~TSingleton() {};
};

//实际需要成为模板的类
class InsClass : public TSingleton<InsClass>//继承时填写模板参数
{
public:
    virtual ~InsClass() {};
    //..一些该类的成员方法
    void DoSomething() { std::cout << "InsClass 做了某些事\n"; }
private:
    //一些该类的成员变量
};

/*
int main()
{
    CSingleton::GetInstance();
    InsClass::GetInstance().DoSomething();
}
*/