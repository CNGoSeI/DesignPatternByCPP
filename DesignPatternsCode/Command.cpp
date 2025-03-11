/** ����ģʽ��������ʲô���͡���ô�������룬������ķ�����ֻ���ע����Ĵ����������ع��ľ���ִ��ϸ��
 * ң�������Ƶƹ⣨֧�ֳ�����
 */

#include <iostream>
#include <memory>
using namespace std;

// �����ߣ���
class Light {
public:
    void on() { cout << "���Ѵ�" << endl; }
    void off() { cout << "���ѹر�" << endl; }
};

// ����ӿ�
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;  // ֧�ֳ���
};

// ���������������
class LightOnCommand : public Command {
private:
    Light& light;
public:
    LightOnCommand(Light& l) : light(l) {}
    void execute() override { light.on(); }
    void undo() override { light.off(); }  // ���Ƶĳ�����Ϊ �ص�
};

// ��������ص�����
class LightOffCommand : public Command {
private:
    Light& light;
public:
    LightOffCommand(Light& l) : light(l) {}
    void execute() override { light.off(); }
    void undo() override { light.on(); }   // ��Ƶĳ�����Ϊ ����
};

// �����ߣ�ң������ť
class RemoteControl {
private:
    unique_ptr<Command> onCommand;
    unique_ptr<Command> offCommand;
    unique_ptr<Command> lastCommand;  // ��¼���һ�β���
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

// �ͻ���
//int main() {
//    Light light;
//    RemoteControl remote;
//
//    // ��������
//    remote.setCommand(
//        new LightOnCommand(light),
//        new LightOffCommand(light)
//    );
//
//    remote.pressOn();   // ��������Ѵ�
//    remote.pressUndo(); // ��������ѹرգ�������
//    remote.pressOff();  // ��������ѹر�
//    return 0;
//}