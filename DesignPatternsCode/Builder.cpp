#include <iostream>
#include <memory>
/** 生成器模式 -Builder
 * 只有当您的产品相当复杂并需要大量配置时，使用生成器模式才有意义
 *
 * 与其他创建模式不同的是，不同的具体构建器可以生成不相关的产品。
 * 换句话说，不同构建器的结果可能并不总是遵循相同的接口
 */

// 1. 产品类：房屋
class House
{
public:
	void setFoundation(const std::string& foundation) { foundation_ = foundation; }
	void setStructure(const std::string& structure) { structure_ = structure; }
	void setRoof(const std::string& roof) { roof_ = roof; }

	void show() const
	{
		std::cout << "房屋组成："
			<< "\n地基：" << foundation_
			<< "\n结构：" << structure_
			<< "\n屋顶：" << roof_ << "\n\n";
	}

private:
	std::string foundation_;
	std::string structure_;
	std::string roof_;
};


/**
 * 生成器接口指定了创建产品对象不同部分的方法
 */
class HouseBuilder
{
public:
	virtual ~HouseBuilder() = default;
	virtual void buildFoundation() = 0; //建地基用这个方法
	virtual void buildStructure() = 0; //建框架用这个方法
	virtual void buildRoof() = 0; //建屋顶用这个方法
	virtual std::shared_ptr<House> getHouse() = 0;
};

/**
 * Concrete Builder 类遵循 Builder 接口，并提供构建步骤的具体实现
 * 程序中可能有多个不同的构建器，它们的实现方式也各不相同
 */
class WoodenHouseBuilder : public HouseBuilder
{
public:
	WoodenHouseBuilder() { house_ = std::make_shared<House>(); }

	void buildFoundation() override { house_->setFoundation("木质地基"); }
	void buildStructure() override { house_->setStructure("木质框架"); }
	void buildRoof() override { house_->setRoof("木质斜顶"); }
	std::shared_ptr<House> getHouse() override { return house_; }

private:
	std::shared_ptr<House> house_;
};

// 4. 具体建造者：玻璃房
class GlassHouseBuilder : public HouseBuilder
{
public:
	GlassHouseBuilder() { house_ = std::make_shared<House>(); }

	void buildFoundation() override { house_->setFoundation("钢化玻璃地基"); }
	void buildStructure() override { house_->setStructure("玻璃幕墙"); }
	void buildRoof() override { house_->setRoof("全景玻璃顶"); }
	std::shared_ptr<House> getHouse() override { return house_; }

private:
	std::shared_ptr<House> house_;
};

/**
 * Director 只负责按特定顺序执行建造步骤。它有助于`按照特定顺序`或配置生产产品
 * 严格来说，Director 类是可选的，因为客户端可以直接控制构建器
 */
class Director
{
public:
	void setBuilder(std::shared_ptr<HouseBuilder> builder) { builder_ = builder; }

	void constructHouse()//最主要的就是控制构建流程
	{
		if (builder_)
		{
			builder_->buildFoundation();
			builder_->buildStructure();
			builder_->buildRoof();
		}
	}

private:
	std::shared_ptr<HouseBuilder> builder_;
};

/**
 * 客户端代码会创建一个构建器对象，将其传递给指挥器，然后启动构建过程。
 * 最终结果将从 生成器对象中获取最终结果
 */

void ClientCode(Director& director, std::shared_ptr<HouseBuilder> Builder)
{
	director.setBuilder(Builder);
	director.constructHouse();
	Builder->getHouse()->show();
}

/*
int main()
{
	Director director;

	auto woodenBuilder = std::make_shared<WoodenHouseBuilder>();
	ClientCode(director, woodenBuilder);

	auto glassBuilder = std::make_shared<GlassHouseBuilder>();
	ClientCode(director, glassBuilder);

	system("pause");
	return 0;
} 
*/