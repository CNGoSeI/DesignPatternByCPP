#include <iostream>
using namespace std;

/*
 * 抽象工厂
 */

//第一种产品 有不同类型的子类
class 耳机
{
public:
	virtual void PlaySound() const = 0;
};

class 有线耳机:public 耳机
{
public:
	void PlaySound() const override
	{
		cout << "有线耳机播放 " << std::endl;
	}

};

class 无线耳机 :public 耳机
{
public:
	void PlaySound() const override
	{
		cout << "！！！ 无线耳机断连了 " << std::endl;
	}
};

//第二种产品 有不同类型的子类
class 麦克风
{
public:
	virtual void GiveSound() const = 0;
	virtual void ConnectOut(const 耳机& Out) const = 0; //一个产品与另一个产品存在交互
};

class 有线麦克风 :public 麦克风
{
public:
	void GiveSound()const override
	{
		cout << "有线麦克风拾音 " << std::endl;
	}

	void ConnectOut(const 耳机& Out) const override
	{
		cout << "有线麦克风链接耳机，开始播放" << std::endl;
		Out.PlaySound();
	}

};

class 无线麦克风 :public 麦克风
{
public:
	void GiveSound()const override
	{
		cout << "无线麦克风没电了 " << std::endl;
	}

	void ConnectOut(const 耳机& Out) const override
	{
		cout << "无线麦克风蓝牙搜索无线耳机中，等待链接..." << std::endl;
		Out.PlaySound();
	}
};

/* 抽象工厂，仅声明要生产哪些产品
 * 至于生产产品的类型，则由具体类型定义
 */
class 耳麦厂
{
public:
	virtual unique_ptr<麦克风> CreateMic()const = 0;
	virtual unique_ptr<耳机> CreateOut()const = 0;
};

class 有线耳麦厂:public 耳麦厂
{
public:
	virtual unique_ptr<麦克风> CreateMic()const
	{
		cout << "造了个有线麦克风 " << std::endl;
		return make_unique<有线麦克风>();
	}

	virtual unique_ptr<耳机> CreateOut()const
	{

		cout << "造个有线耳机 "  << std::endl;
		return make_unique<有线耳机>();
	}
};

class 无线耳麦厂 :public 耳麦厂
{
	virtual unique_ptr<麦克风> CreateMic()const
	{
		cout << "造无线麦克风，蓝牙5.0 " << std::endl;
		return make_unique<无线麦克风>() ;
	}

	virtual unique_ptr<耳机> CreateOut()const
	{

		cout << "无线耳机造了，蓝牙5.0 HIFI " << std::endl;
		return make_unique<无线耳机>();
	}

};

void CreateMicOut(const 耳麦厂& InCreater)
{
		auto out = InCreater.CreateOut();
		auto mic = InCreater.CreateMic();
		mic->GiveSound();
		mic->ConnectOut(*out);
}

/*
int main() {

	std::cout << "有线耳麦工厂:\n";
	有线耳麦厂* f1 = new 有线耳麦厂();
	CreateMicOut(*f1);
	delete f1;
	std::cout << std::endl;
	std::cout << "无线耳麦工厂:\n";
	无线耳麦厂* f2 = new 无线耳麦厂();
	CreateMicOut(*f2);
	delete f2;
	return 0;
}
*/