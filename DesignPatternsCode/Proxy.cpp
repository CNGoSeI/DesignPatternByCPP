/**
 * 代理模式：创建一个接管类，使接管类来调用或管理目标方法
 */

#include <iostream>
#include <memory>
using namespace std;

// 抽象接口：图片操作
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// 真实对象：加载图片
class RealImage : public Image {
private:
    string filename;
    void loadFromDisk() {
        cout << "Loading image: " << filename << " (耗时操作)" << endl;
    }
public:
    RealImage(const string& filename) : filename(filename) {
        loadFromDisk(); // 构造函数中模拟耗时加载
    }
    void display() override {
        cout << "Displaying image: " << filename << endl;
    }
};

// 代理类：延迟加载
class ProxyImage : public Image {
private:
    string filename;
    unique_ptr<RealImage> realImage;
public:
    ProxyImage(const string& filename) : filename(filename) {}

    /*
     * 可以插入其他操作
     *  - 比如判断客户端用户是否有权限让图片显示
     *  - 在加载前后执行其他操作
     */
    void display() override {
        if (!realImage) { // 首次调用时加载真实对象
            realImage = make_unique<RealImage>(filename);
        }
        realImage->display();
    }
};

// 客户端
//int main() {
//    ProxyImage proxy("high_res_photo.jpg");
//    cout << "第一次访问图片：" << endl;
//    proxy.display(); // 触发加载
//    cout << "\n第二次访问图片：" << endl;
//    proxy.display(); // 直接使用缓存
//    return 0;
//}