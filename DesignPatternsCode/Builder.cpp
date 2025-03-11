#include <iostream>
#include <memory>
/** ������ģʽ -Builder
 * ֻ�е����Ĳ�Ʒ�൱���Ӳ���Ҫ��������ʱ��ʹ��������ģʽ��������
 *
 * ����������ģʽ��ͬ���ǣ���ͬ�ľ��幹�����������ɲ���صĲ�Ʒ��
 * ���仰˵����ͬ�������Ľ�����ܲ���������ѭ��ͬ�Ľӿ�
 */

// 1. ��Ʒ�ࣺ����
class House
{
public:
	void setFoundation(const std::string& foundation) { foundation_ = foundation; }
	void setStructure(const std::string& structure) { structure_ = structure; }
	void setRoof(const std::string& roof) { roof_ = roof; }

	void show() const
	{
		std::cout << "������ɣ�"
			<< "\n�ػ���" << foundation_
			<< "\n�ṹ��" << structure_
			<< "\n�ݶ���" << roof_ << "\n\n";
	}

private:
	std::string foundation_;
	std::string structure_;
	std::string roof_;
};


/**
 * �������ӿ�ָ���˴�����Ʒ����ͬ���ֵķ���
 */
class HouseBuilder
{
public:
	virtual ~HouseBuilder() = default;
	virtual void buildFoundation() = 0; //���ػ����������
	virtual void buildStructure() = 0; //��������������
	virtual void buildRoof() = 0; //���ݶ����������
	virtual std::shared_ptr<House> getHouse() = 0;
};

/**
 * Concrete Builder ����ѭ Builder �ӿڣ����ṩ��������ľ���ʵ��
 * �����п����ж����ͬ�Ĺ����������ǵ�ʵ�ַ�ʽҲ������ͬ
 */
class WoodenHouseBuilder : public HouseBuilder
{
public:
	WoodenHouseBuilder() { house_ = std::make_shared<House>(); }

	void buildFoundation() override { house_->setFoundation("ľ�ʵػ�"); }
	void buildStructure() override { house_->setStructure("ľ�ʿ��"); }
	void buildRoof() override { house_->setRoof("ľ��б��"); }
	std::shared_ptr<House> getHouse() override { return house_; }

private:
	std::shared_ptr<House> house_;
};

// 4. ���彨���ߣ�������
class GlassHouseBuilder : public HouseBuilder
{
public:
	GlassHouseBuilder() { house_ = std::make_shared<House>(); }

	void buildFoundation() override { house_->setFoundation("�ֻ������ػ�"); }
	void buildStructure() override { house_->setStructure("����Ļǽ"); }
	void buildRoof() override { house_->setRoof("ȫ��������"); }
	std::shared_ptr<House> getHouse() override { return house_; }

private:
	std::shared_ptr<House> house_;
};

/**
 * Director ֻ�����ض�˳��ִ�н��첽�衣��������`�����ض�˳��`������������Ʒ
 * �ϸ���˵��Director ���ǿ�ѡ�ģ���Ϊ�ͻ��˿���ֱ�ӿ��ƹ�����
 */
class Director
{
public:
	void setBuilder(std::shared_ptr<HouseBuilder> builder) { builder_ = builder; }

	void constructHouse()//����Ҫ�ľ��ǿ��ƹ�������
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
 * �ͻ��˴���ᴴ��һ�����������󣬽��䴫�ݸ�ָ������Ȼ�������������̡�
 * ���ս������ �����������л�ȡ���ս��
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