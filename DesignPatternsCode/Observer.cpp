/** 观察者模式：当一个对象（主题/被观察者）状态变化时，所有依赖它的对象（观察者）会自动收到通知并更新
 * ​Subject：维护观察者列表，提供attach()、detach()和notify()方法。
 * GameEventPublisher：具体主题，触发事件时通知所有观察者。
 * AchievementSystem/UINotifier：具体观察者，实现update()方法处理事件。
 */

#include <iostream>
#include <vector>
#include <memory>
#include <string>

 // 观察者接口
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& event) = 0;
};

// 主题（被观察者）
class Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void attach(const std::shared_ptr<Observer>& observer) {
        observers.push_back(observer);
    }

    void detach(const std::shared_ptr<Observer>& observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    
    //遍历容器内每个成员，调用成员update函数
    void notify(const std::string& event) {
        for (const auto& observer : observers) {
            observer->update(event);
        }
    }
};

// 具体主题：游戏事件发布器
class GameEventPublisher : public Subject {
public:
    void triggerEvent(const std::string& eventName) {
        std::cout << "【系统】触发事件: " << eventName << std::endl;
        notify(eventName);
    }
};

// 具体观察者：成就系统
class AchievementSystem : public Observer {
public:
    void update(const std::string& event) override {
        if (event == "BOSS_DEFEATED") {
            std::cout << "【成就】击败Boss成就已解锁！" << std::endl;
        }
        else if (event == "LEVEL_UP") {
            std::cout << "【成就】升级奖励已发放！" << std::endl;
        }
    }
};

// 具体观察者：UI通知系统
class UINotifier : public Observer {
public:
    void update(const std::string& event) override {
        std::cout << "【UI】收到事件: " << event << "，刷新界面..." << std::endl;
    }
};

/*
int main() {
    // 创建主题和观察者
    auto gameEvents = std::make_shared<GameEventPublisher>();
    auto achievement = std::make_shared<AchievementSystem>();
    auto ui = std::make_shared<UINotifier>();

    // 注册观察者
    gameEvents->attach(achievement);
    gameEvents->attach(ui);

    // 触发事件
    gameEvents->triggerEvent("LEVEL_UP");
    gameEvents->triggerEvent("BOSS_DEFEATED");

    // 取消UI订阅
    gameEvents->detach(ui);
    gameEvents->triggerEvent("ITEM_COLLECTED");  // 仅成就系统响应

    system("pause");
    return 0;
}
*/