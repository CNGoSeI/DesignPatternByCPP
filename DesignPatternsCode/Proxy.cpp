/**
 * ����ģʽ������һ���ӹ��࣬ʹ�ӹ��������û����Ŀ�귽��
 */

#include <iostream>
#include <memory>
using namespace std;

// ����ӿڣ�ͼƬ����
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// ��ʵ���󣺼���ͼƬ
class RealImage : public Image {
private:
    string filename;
    void loadFromDisk() {
        cout << "Loading image: " << filename << " (��ʱ����)" << endl;
    }
public:
    RealImage(const string& filename) : filename(filename) {
        loadFromDisk(); // ���캯����ģ���ʱ����
    }
    void display() override {
        cout << "Displaying image: " << filename << endl;
    }
};

// �����ࣺ�ӳټ���
class ProxyImage : public Image {
private:
    string filename;
    unique_ptr<RealImage> realImage;
public:
    ProxyImage(const string& filename) : filename(filename) {}

    /*
     * ���Բ�����������
     *  - �����жϿͻ����û��Ƿ���Ȩ����ͼƬ��ʾ
     *  - �ڼ���ǰ��ִ����������
     */
    void display() override {
        if (!realImage) { // �״ε���ʱ������ʵ����
            realImage = make_unique<RealImage>(filename);
        }
        realImage->display();
    }
};

// �ͻ���
//int main() {
//    ProxyImage proxy("high_res_photo.jpg");
//    cout << "��һ�η���ͼƬ��" << endl;
//    proxy.display(); // ��������
//    cout << "\n�ڶ��η���ͼƬ��" << endl;
//    proxy.display(); // ֱ��ʹ�û���
//    return 0;
//}