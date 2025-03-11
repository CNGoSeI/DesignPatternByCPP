#include <iostream>
#include <string>
/**
 * 工厂模式
 * 产品类(Product)抽象类，纯虚方法以供具体类实现
 * 创建者(Create) 生产 --> 产品类(Product)，提供虚函数(FactoryMethod())让子类实现，其中SomeOperation()调用不同Product子类实例的Operation()
 * 各种创建者继承 ——> Create 类，实现FactoryMethod()方法，返回不同的 Product子类 实例
 */


/**
 * Product接口声明了所有 具体产品 必须进行的操作
 * implement.
 */
class Product
{
public:
	virtual ~Product(){}

	virtual std::string Operation() const = 0;
};

/**
 * 具体"产品" 不同的实现Product的方法
 */
class ConcreteProduct1 : public Product
{
public:
	std::string Operation() const override
	{
		return "{Result of the ConcreteProduct1}";
	}
};

class ConcreteProduct2 : public Product
{
public:
	std::string Operation() const override
	{
		return "{Result of the ConcreteProduct2}";
	}
};

/**
 * Creator 类声明了工厂方法，该方法应返回一个产品类的对象，为抽象类
 * 创建者的子类通常会提供该方法的实现。
 */
class Creator
{
	/**
	 * 请注意，创建者也可能提供一些默认的工厂方法的默认实现
	 */
public:
	virtual ~Creator(){};
	virtual Product* FactoryMethod() const = 0; //能够返回不同的Product类，以供SomeOperation()中调用不同Product的方法
	/**
	 * 还要注意的是，尽管名为 “创建者”，但其主要职责并不是创建产品。
	 * 通常，它包含一些依赖于工厂方法返回的 Product 对象的核心业务逻辑。
	 * 子类可以通过重载工厂方法并从中返回不同类型的产品来间接改变业务逻辑
	 */

	std::string SomeOperation() const
	{
		// 调用工厂方法创建 Product 对象.
		Product* product = this->FactoryMethod();
		//现在，使用该 product
		std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
		delete product;
		return result;
	}
};

/**
 * 具体创建者会覆盖工厂方法，以便更改生成产品的类型。
 */
class ConcreteCreator1 : public Creator
{
	/**
	 * 请注意，该方法的签名仍然使用抽象产品类型、
	 * 尽管该方法实际返回的是具体产品。这样
	 * 这样，创造者就可以独立于具体的产品类别。
	 */
public:
	Product* FactoryMethod() const override
	{
		return new ConcreteProduct1();
	}
};

class ConcreteCreator2 : public Creator
{
public:
	Product* FactoryMethod() const override
	{
		return new ConcreteProduct2();
	}
};

/**
 * 客户端代码与具体创建者的实例协同工作，尽管是通过其基本接口。
 * 只要客户端继续通过基本接口，你就可以向它传递任何创建者的子类。
 */

void ClientCode(const Creator& creator)
{
		// ...
		std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
			<< creator.SomeOperation() << std::endl;
		// ...
}


/**
 * 应用程序会根据配置或环境选择创建者的类型
 */
/*
int main()
{
	using namespace FactoryMethod;
	std::cout << "App: Launched with the ConcreteCreator1.\n";
	Creator* creator = new ConcreteCreator1();
	ClientCode(*creator);
	std::cout << std::endl;
	std::cout << "App: Launched with the ConcreteCreator2.\n";
	Creator* creator2 = new ConcreteCreator2();
	ClientCode(*creator2);

	delete creator;
	delete creator2;
	return 0;
}
*/
