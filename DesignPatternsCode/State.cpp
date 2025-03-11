/**
 * 状态模式：相同的接口下，在不同的状态实现的功能不同，有限状态机
 */
#include <iostream>
#include <memory>

// 抽象状态接口
class ElevatorState {
public:
    virtual void openDoors() = 0;
    virtual void closeDoors() = 0;
    virtual void moveToFloor(int floor) = 0;
    virtual ~ElevatorState() = default;
};

// 具体状态类：停止状态
class StoppedState : public ElevatorState {
public:
    void openDoors() override {
        std::cout << "电梯门已打开" << std::endl;
    }

    void closeDoors() override {
        std::cout << "电梯门已关闭" << std::endl;
    }

    void moveToFloor(int floor) override {
        std::cout << "电梯开始移动至楼层 " << floor << std::endl;
    }
};

// 具体状态类：运行状态
class RunningState : public ElevatorState {
public:
    void openDoors() override {
        std::cout << "错误：运行中无法开门！" << std::endl;
    }

    void closeDoors() override {
        std::cout << "错误：运行中门已关闭！" << std::endl;
    }

    void moveToFloor(int floor) override {
        std::cout << "正在前往楼层 " << floor << "..." << std::endl;
    }
};

// 上下文类（电梯控制器）
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

// 客户端调用示例
//int main() {
//    ElevatorController elevator;
//
//    elevator.requestOpenDoors();  // 输出：电梯门已打开
//    elevator.requestMoveToFloor(5); // 输出：电梯开始移动至楼层 5
//
//    // 切换为运行状态
//    elevator.setState(std::make_unique<RunningState>());
//    elevator.requestOpenDoors();  // 输出：错误：运行中无法开门！
//    elevator.requestMoveToFloor(3); // 输出：正在前往楼层 3...
//
//    system("pause");
//    return 0;
//}