/**
 * ������ģʽ������������߶������ӳ�һ�������������������ݣ�ֱ���ж�������Ϊֹ
 */

#include <iostream>
#include <string>
using namespace std;

// ������־������
class LogHandler {
protected:
    LogHandler* nextHandler;
public:
    virtual ~LogHandler() = default;
    void setNext(LogHandler* handler) { nextHandler = handler; }
    virtual void handle(const string& level, const string& message) = 0;
};

// ����̨������������INFO,����������־���ݸ���һ��Loger��
class ConsoleHandler : public LogHandler {
public:
    void handle(const string& level, const string& message) override {
        if (level == "INFO") {
            cout << "[����̨] INFO: " << message << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handle(level, message); // ���ݸ���һ������
        }
    }
};

// �ļ�������������WARNING��
class FileHandler : public LogHandler {
public:
    void handle(const string& level, const string& message) override {
        if (level == "WARNING") {
            cout << "[�ļ�] WARNING: " << message << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handle(level, message);
        }
    }
};

// ���ݿ⴦����������ERROR��
class DatabaseHandler : public LogHandler {
public:
    void handle(const string& level, const string& message) override {
        if (level == "ERROR") {
            cout << "[���ݿ�] ERROR: " << message << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handle(level, message);
        }
    }
};

// �ͻ��ˣ���������������������
//int main() {
//    ConsoleHandler console;
//    FileHandler file;
//    DatabaseHandler db;
//
//    console.setNext(&file);
//    file.setNext(&db);
//
//    // �ύ��־����
//    console.handle("INFO", "�û���¼�ɹ�"); //console�Լ�����
//    console.handle("WARNING", "�ڴ�ռ�ù���"); //console -> FileHandler ����
//    console.handle("ERROR", "���ݿ�����ʧ��"); // console -> FileHandler -> DatabaseHandler ���д���
//    console.handle("DEBUG", "������Ϣ��δ����");
//
//    system("pause");
//    return 0;
//}