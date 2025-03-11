/**
 * 责任链模式：将多个处理者对象连接成一条链，请求沿着链传递，直到有对象处理它为止
 */

#include <iostream>
#include <string>
using namespace std;

// 抽象日志处理器
class LogHandler {
protected:
    LogHandler* nextHandler;
public:
    virtual ~LogHandler() = default;
    void setNext(LogHandler* handler) { nextHandler = handler; }
    virtual void handle(const string& level, const string& message) = 0;
};

// 控制台处理器（处理INFO,其他级别日志传递给下一个Loger）
class ConsoleHandler : public LogHandler {
public:
    void handle(const string& level, const string& message) override {
        if (level == "INFO") {
            cout << "[控制台] INFO: " << message << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handle(level, message); // 传递给下一处理器
        }
    }
};

// 文件处理器（处理WARNING）
class FileHandler : public LogHandler {
public:
    void handle(const string& level, const string& message) override {
        if (level == "WARNING") {
            cout << "[文件] WARNING: " << message << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handle(level, message);
        }
    }
};

// 数据库处理器（处理ERROR）
class DatabaseHandler : public LogHandler {
public:
    void handle(const string& level, const string& message) override {
        if (level == "ERROR") {
            cout << "[数据库] ERROR: " << message << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handle(level, message);
        }
    }
};

// 客户端：构建责任链并触发处理
//int main() {
//    ConsoleHandler console;
//    FileHandler file;
//    DatabaseHandler db;
//
//    console.setNext(&file);
//    file.setNext(&db);
//
//    // 提交日志请求
//    console.handle("INFO", "用户登录成功"); //console自己处理
//    console.handle("WARNING", "内存占用过高"); //console -> FileHandler 处理
//    console.handle("ERROR", "数据库连接失败"); // console -> FileHandler -> DatabaseHandler 进行处理
//    console.handle("DEBUG", "调试信息（未处理）");
//
//    system("pause");
//    return 0;
//}