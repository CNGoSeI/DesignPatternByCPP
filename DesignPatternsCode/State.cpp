/**
 * ״̬ģʽ����ͬ�Ľӿ��£��ڲ�ͬ��״̬ʵ�ֵĹ��ܲ�ͬ������״̬��
 */
#include <iostream>
#include <memory>

// ����״̬�ӿ�
class ElevatorState {
public:
    virtual void openDoors() = 0;
    virtual void closeDoors() = 0;
    virtual void moveToFloor(int floor) = 0;
    virtual ~ElevatorState() = default;
};

// ����״̬�ֹࣺͣ״̬
class StoppedState : public ElevatorState {
public:
    void openDoors() override {
        std::cout << "�������Ѵ�" << std::endl;
    }

    void closeDoors() override {
        std::cout << "�������ѹر�" << std::endl;
    }

    void moveToFloor(int floor) override {
        std::cout << "���ݿ�ʼ�ƶ���¥�� " << floor << std::endl;
    }
};

// ����״̬�ࣺ����״̬
class RunningState : public ElevatorState {
public:
    void openDoors() override {
        std::cout << "�����������޷����ţ�" << std::endl;
    }

    void closeDoors() override {
        std::cout << "�������������ѹرգ�" << std::endl;
    }

    void moveToFloor(int floor) override {
        std::cout << "����ǰ��¥�� " << floor << "..." << std::endl;
    }
};

// �������ࣨ���ݿ�������
class ElevatorController {
private:
    std::unique_ptr<ElevatorState> currentState;

public:
    ElevatorController() : currentState(std::make_unique<StoppedState>()) {}

    void setState(std::unique_ptr<ElevatorState> newState) {
        currentState = std::move(newState);
    }

    void requestOpenDoors() {
        currentState->openDoors();
    }

    void requestCloseDoors() {
        currentState->closeDoors();
    }

    void requestMoveToFloor(int floor) {
        currentState->moveToFloor(floor);
    }
};

// �ͻ��˵���ʾ��
//int main() {
//    ElevatorController elevator;
//
//    elevator.requestOpenDoors();  // ������������Ѵ�
//    elevator.requestMoveToFloor(5); // ��������ݿ�ʼ�ƶ���¥�� 5
//
//    // �л�Ϊ����״̬
//    elevator.setState(std::make_unique<RunningState>());
//    elevator.requestOpenDoors();  // ����������������޷����ţ�
//    elevator.requestMoveToFloor(3); // ���������ǰ��¥�� 3...
//
//    system("pause");
//    return 0;
//}