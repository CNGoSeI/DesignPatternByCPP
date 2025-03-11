#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class 图片文件;
class 视频文件;

class 压缩器
{
public:
	virtual ~压缩器() = default;
	virtual void 压缩图片(图片文件&) = 0;
	virtual void 压缩视频(视频文件&) = 0;
};

class 资源文件
{
public:
	explicit 资源文件(const string& InitFileName) :FileName(InitFileName) {};
	virtual void 访问压缩(压缩器& Target) = 0;

	const string& GetFileName()const { return FileName; };

protected:
	string FileName{ "" };
};

class 图片文件:public 资源文件
{
public:
	explicit 图片文件(const string& InitFileName) :资源文件(InitFileName) {};
	void 访问压缩(压缩器& Target) override
	{
		Target.压缩图片(*this);
	};
};

class 视频文件 :public 资源文件
{
public:
	explicit 视频文件(const string& InitFileName) :资源文件(InitFileName) {};
	void 访问压缩(压缩器& Target) override
	{
		Target.压缩视频(*this);
	};
};

class ZIP压缩器:public 压缩器
{
public:
	void 压缩图片(图片文件& Img) override
	{
		cout << "ZIP: 压缩图片 [" << Img.GetFileName() << "] 为ZIP格式" << endl;
	};
	void 压缩视频(视频文件& Video) override
	{
		cout << "ZIP: 压缩视频 [" << Video.GetFileName() << "] 为ZIP格式" << endl;
	};
};

class RAR压缩器 :public 压缩器
{
public:
	void 压缩图片(图片文件& Img) override
	{
		cout << "RAR: 压缩图片 [" << Img.GetFileName() << "] 为RAR格式" << endl;
	};
	void 压缩视频(视频文件& Video) override
	{
		cout << "RAR: 压缩视频 [" << Video.GetFileName() << "] 为RAR格式" << endl;
	};
};

class 文件压缩管理器
{
public:
	void 添加文件管理(unique_ptr<资源文件> File)
	{
		Files.push_back(move(File));
	}

	void 执行压缩(压缩器& Excuter)
	{
		for (const auto& it:Files)
		{
			it->访问压缩(Excuter);
		}
	}

private:
	vector<unique_ptr<资源文件>> Files;
};

int main()
{
	auto FileManger = make_unique<文件压缩管理器>();

	//添加文件
	FileManger->添加文件管理(make_unique<视频文件>("夫の前に寝られた.mkv"));
	FileManger->添加文件管理(make_unique<图片文件>("喵吉酱甜心福利.png"));

	//zip压缩
	cout << "ZIP: \n";
	auto Ziper = make_unique<ZIP压缩器>();
	FileManger->执行压缩(*Ziper);

	//RAR压缩
	cout << "\nRAR: \n";
	auto RARer = make_unique<RAR压缩器>();
	FileManger->执行压缩(*RARer);

	system("pause");
}