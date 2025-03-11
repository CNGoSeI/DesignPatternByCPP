/** 命令模式：将“做什么”和“怎么做”分离，让请求的发送者只需关注命令的触发，而不必关心具体执行细节
 * 遥控器控制灯光（支持撤销）
 */

#include <iostream>
#include <memory>
using namespace std;

// 接收者：灯
class Light {
public:
    void on() { cout << "灯已打开" << endl; }
    void off() { cout << "灯已关闭" << endl; }
};

// 命令接口
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;  // 支持撤销
};

// 具体命令：开灯命令
class LightOnCommand : public Command {
private:
    Light& light;
public:
    LightOnCommand(Light& l) : light(l) {}
    void execute() override { light.on(); }
    void undo() override { light.off(); }  // 开灯的撤销即为 关灯
};

// 具体命令：关灯命令
class LightOffCommand : public Command {
private:
    Light& light;
public:
    LightOffCommand(Light& l) : light(l) {}
    void execute() override { light.off(); }
    void undo() override { light.on(); }   // 光灯的撤销即为 开灯
};

// 调用者：遥控器按钮
class RemoteControl {
private:
    unique_ptr<Command> onCommand;
    unique_ptr<Command> offCommand;
    unique_ptr<Command> lastCommand;  // 记录最后一次操作
public:
    void setCommand(Command* on, Command* off) {
        onCommand.reset(on);
        offCommand.reset(off);
    }
    void pressOn() {
        onCommand->execute();
        lastCommand = move(onCommand);
    }
    void pressOff() {
        offCommand->execute();
        lastCommand = move(offCommand);
    }
    void pressUndo() {
        if (lastCommand) lastCommand->undo();
    }
};

// 客户端
//int main() {
//    Light light;
//    RemoteControl remote;
//
//    // 配置命令
//    remote.setCommand(
//        new LightOnCommand(light),
//        new LightOffCommand(light)
//    );
//
//    remote.pressOn();   // 输出：灯已打开
//    remote.pressUndo(); // 输出：灯已关闭（撤销）
//    remote.pressOff();  // 输出：灯已关闭
//    return 0;
//}