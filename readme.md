学习资料：

DeepSeek

还有这本书

[广受推荐的最新设计模式书籍：《深入设计模式》](https://refactoringguru.cn/design-patterns/book)

#### **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">设计模式的核心目的</font>**
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">实现代码工程化：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">将设计经验标准化，使代码更易维护和扩展，成为软件开发的“基石”</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">支持开闭原则：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">对扩展开放，对修改关闭（如通过抽象类或接口扩展功能，而非修改原有代码）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">解耦与高内聚：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">降低模块间的依赖（低耦合），增强模块内功能的相关性（高内聚）</font>

#### **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">设计模式遵循的原则</font>**
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">单一职责原则 (SRP)：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">每个类或方法只负责一个功能（如订单类处理订单逻辑，支付类处理支付逻辑）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">开闭原则 (OCP)：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">通过抽象（接口/抽象类）扩展功能，避免直接修改现有代码（如工厂模式支持新增产品类型）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">里氏替换原则 (LSP)：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">子类必须能替换父类且不破坏原有逻辑（如正方形继承长方形时需确保面积计算正确）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">依赖倒置原则 (DIP)：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">高层模块不依赖低层模块，两者都依赖抽象（如通过接口定义数据库操作，而非直接调用具体数据库类）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">接口隔离原则 (ISP)：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">接口按功能细分，避免“臃肿接口”（如用户管理接口拆分为查询接口和更新接口）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">迪米特法则 (LoD)：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">减少类之间的直接依赖，通过中间类通信（如通过“中介者模式”协调对象交互）</font>

# 创建模式
<font style="color:rgb(68, 68, 68);">这类模式提供创建对象的机制， 能够提升已有代码的灵活性和可复用性</font>

## 工厂模式
**<font style="color:rgb(68, 68, 68);">工厂方法模式</font>**<font style="color:rgb(68, 68, 68);">是一种创建型设计模式， 其在父类中提供一个创建对象的方法， 允许子类决定实例化对象的类型</font>

<font style="color:rgb(68, 68, 68);">使用特殊的工厂方法代</font>**<font style="color:rgb(68, 68, 68);">替对于对象构造函数的直接调用</font>**<font style="color:rgb(68, 68, 68);">，改在工厂方法中调用。 工厂方法返回的对象通常被称作 “产品”。</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1740731945425-61c5ef98-0613-4eca-abfd-5f3b09994c8d.png)



**适用场景：**

+ <font style="color:rgb(68, 68, 68);">无法预知对象确切类别及其依赖关系时， 可使用工厂方法</font>
+ <font style="color:rgb(68, 68, 68);">希望用户能扩展你软件库或框架的内部组件， 可使用工厂方法</font>
+ <font style="color:rgb(68, 68, 68);">希望复用现有对象来节省系统资源， 而不是每次都重新创建对象， 可使用工厂方法</font>

****

## 抽象工厂
**<font style="color:rgb(68, 68, 68);">创建一系列</font>****<font style="color:#DF2A3F;">相关的对象</font>****<font style="color:rgb(68, 68, 68);">， 而无需指定其具体类</font>**

有个耳机厂，但是提前不知道生产什么类型的耳机，但是**无线耳机只能和无线麦克风使用，有线耳机只能和有线麦克风使用**，那么该耳机厂仅有个最基础的生产流线，而具体的子工厂实装不同的生产流线机器（无线生产线，有线生产线）

**<font style="background-color:#E7E9E8;">产品</font>**** ****<font style="background-color:#CEF5F7;">Abstract Product</font>****：基础的功能（抽象方法）**

+ 耳机 (产品代号1)：放声音、播放麦克风收集的声音
+ 麦克风 (产品代号2)：收集声音

**<font style="background-color:#E7E9E8;">工厂</font>**** ****<font style="background-color:#CEF5F7;">Abstract Factory</font>**** (基础产线)：**

+ **有线**耳麦**工厂 (****<font style="background-color:#CEF5F7;">ConcreteProductA</font>****)：**
    - 生产有线耳机：ConcreteProduct A1
    - 生产有线麦克风：ConcreteProduct A2
+ **无线**耳麦**工厂(****<font style="background-color:#CEF5F7;">ConcreteProductB</font>****)：**
    - 生产无线耳机：ConcreteProduct B1
    - 生产无线麦克风：ConcreteProduct B2



![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741008181095-37210704-3481-40a4-86f4-e4efa9ba81c0.png)

**适用场景：**

+ **<font style="color:rgb(68, 68, 68);"> 如果代码需要与</font>****<font style="color:#DF2A3F;">多个不同系列的相关产品交互</font>****<font style="color:rgb(68, 68, 68);">， 但是由于</font>****<font style="color:#DF2A3F;">无法提前获取相关信息</font>****<font style="color:rgb(68, 68, 68);">， 或者出于对未来扩展性的考虑， 你不希望代码基于产品的具体类进行构建。</font>**
+ **<font style="color:rgb(68, 68, 68);">如果你有一个基于一组</font>**[<font style="color:rgb(68, 68, 68);">抽象方法</font>](https://refactoringguru.cn/design-patterns/factory-method)**<font style="color:rgb(68, 68, 68);">的类， 且其主要功能因此变得不明确， 那么在这种情况下可以考虑使用抽象工厂模式</font>**

## <font style="color:rgb(68, 68, 68);">生成器模式 Builder</font>
<font style="color:rgb(68, 68, 68);">生成器模式建议将对象构造代码从产品类中抽取出来， 并将其放在一个名为</font>_<font style="color:rgb(68, 68, 68);">生成器</font>_<font style="color:rgb(68, 68, 68);">的独立对象中</font>

<font style="color:rgb(68, 68, 68);"></font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">建造者模式将</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">复杂对象的构建过程</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">与</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">最终表示形式</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">分离，通过分步骤构造对象，允许相同构建过程生成不同配置的产品</font>

<font style="color:rgb(68, 68, 68);">其核心角色包括：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">产品（Product）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：最终要构建的复杂对象（如房屋、汽车）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">建造者接口（Builder）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：定义构建各部分的抽象方法</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">具体建造者（Concrete Builder）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：实现具体构建逻辑</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">指挥者（Director）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：控制构建流程</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741059160226-62d71df5-15e5-43e4-9ea2-c8571102cc85.png)

![画板](https://cdn.nlark.com/yuque/0/2025/jpeg/36214189/1741077497723-5a03b071-c142-4580-841c-a307bfd094e6.jpeg)



**适用场景：**

+ 可避免 “重叠构造函数 （telescoping constructor）” 的出现
    - <font style="color:rgb(68, 68, 68);">假设构造函数中有十个可选参数， 那么调用会非常不方便； 因此， 需要重载这个构造函数， </font>**<font style="color:rgb(68, 68, 68);">新建几个只有较少参数的简化版。 但这些构造函数仍需调用主构造函数</font>**<font style="color:rgb(68, 68, 68);">， 传递一些默认数值来替代省略掉的参数</font>
+ <font style="color:rgb(68, 68, 68);">希望使用代码创建不同形式的产品 （例如石头或木头房屋） 时</font>
    - <font style="color:rgb(68, 68, 68);">需要</font>**<font style="color:rgb(68, 68, 68);">创建的各种形式的产品， 它们的制造过程相似且仅有细节上的差异</font>**
+ <font style="color:rgb(68, 68, 68);">使用生成器构造组合树或其他复杂对象</font>
    - <font style="color:rgb(68, 68, 68);">生成器模式让你能</font>**<font style="color:rgb(68, 68, 68);">分步骤构造产品</font>**<font style="color:rgb(68, 68, 68);">。 你可以</font>**<font style="color:rgb(68, 68, 68);">延迟执行某些步骤</font>**<font style="color:rgb(68, 68, 68);">而不会影响最终产品。</font>

## <font style="color:rgb(68, 68, 68);">原型模式 Prototype</font>
使你能够复制已有对象， 而又无需使代码依赖它们所属的类。

步骤：

+ 创建抽象类，存在一个 <font style="background-color:#FBF5CB;">Clone</font> 方法
+ 子类继承抽象类，重写  方法，创建一个自身
+ <font style="color:rgb(68, 68, 68);">还可以创建一个中心化原型注册表， 用于存储常用原型，通过调用该类进行创建原型</font>



![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741084222953-c3ca3c3a-872e-4052-8d67-14b8a4897205.png)

![](https://cdn.nlark.com/yuque/0/2024/png/36214189/1718956488679-a8067c03-5547-462b-ad41-ff3810314775.png?x-oss-process=image%2Fformat%2Cwebp)

```cpp
//抽象类
class ISplitter{
public:
virtual void split()=0;
virtual ISplitter* clone()=0; //通过克隆自己来创建对象  
virtual ~ISplitter(){}
};

//具体类
class BinarySplitter : public ISplitter{
public:

//进行拷贝构造 创建一个自己
virtual ISplitter* clone(){
    return new BinarySplitter(*this);
}
};
```

```cpp
class Spawner
{
public:
  virtual ~Spawner() {}
  virtual Monster* spawnMonster() = 0;
};


template <class T>
class SpawnerFor : public Spawner
{
public:
  virtual Monster* spawnMonster() { return new T(); }
};
```

**适用场景：**

+ 需要复制一些对象， 同时又希望代码独立于这些对象所属的具体类
    - <font style="color:rgb(68, 68, 68);">通常出现在代码需要处理第三方代码通过接口传递过来的对象时</font>
    - <font style="color:rgb(68, 68, 68);">为客户端代码提供一个通用接口， 客户端代码可通过这一接口与所有实现了克隆的对象进行交互， 它也使得客户端代码与其所克隆的对象具体类独立开来</font>
+  如果子类的区别仅在于其对象的初始化方式， 那么你可以使用该模式来减少子类的数量

## 单例 Singleton
**<font style="color:rgb(115, 132, 140);background-color:rgb(249, 250, 251);">保证一个类只有一个实例，并且提供了访问该实例的全局访问点。</font>**

C11之后，静态局部变量线程安全，因此非常合适做单例

```cpp
//单例基类模板
template <typename T>
class TSingleton
{
private:
    TSingleton() = default;
    TSingleton(const TSingleton<T>&) = delete;
    TSingleton& operator=(const TSingleton<T>&) = delete;
    friend T;//为了正常访问 使其成为友元

public:
    static T& GetInstance() //返回实例的方法
    {
        static T ins;
        return ins;
    }

    virtual ~TSingleton(){};
};

//实际需要成为模板的类
class InsClass : public TSingleton<InsClass>//继承时填写模板参数
{
public:
   virtual ~InsClass() {};
    int GetNum() const { return n; }
  //..一些该类的成员方法
private:
    //一些该类的成员变量
};
```

# <font style="color:rgb(68, 68, 68);">结构型模式</font>
<font style="color:rgb(68, 68, 68);">这类模式介绍如何将对象和类组装成较大的结构， 并同时保持结构的灵活和高效</font>

## <font style="color:rgb(68, 68, 68);">适配器模式</font>
**适配器模式**是一种结构型设计模式， 它能使接口不兼容的对象能够相互合作；适配器是一个特殊的对象， 能够转换对象接口， 使其能与其他对象进行交互。

<font style="color:rgb(68, 68, 68);">适配器不仅可以转换不同格式的数据</font><font style="color:rgb(68, 68, 68);">，</font><font style="color:rgb(68, 68, 68);"> </font><font style="color:rgb(68, 68, 68);">其还有助于采用不同接口的对象之间的合作</font><font style="color:rgb(68, 68, 68);">。</font><font style="color:rgb(68, 68, 68);"> </font><font style="color:rgb(68, 68, 68);">它的运作方式如下</font><font style="color:rgb(68, 68, 68);">：</font>

1. <font style="color:rgb(68, 68, 68);">适配器实现与其中一个现有对象兼容的</font><font style="color:rgb(68, 68, 68);background-color:#FBDE28;">接口</font><font style="color:rgb(68, 68, 68);">。</font>
2. <font style="color:rgb(68, 68, 68);">现有对象可以使用该接口安全地调用</font><font style="color:rgb(68, 68, 68);background-color:#FBDE28;">适配器方法</font><font style="color:rgb(68, 68, 68);">。</font>
3. <font style="color:rgb(68, 68, 68);">适配器方法被调用后将以</font>**<font style="color:rgb(68, 68, 68);">另一个对象兼容的格式和顺序将请求传递给该对象</font>**

<font style="color:rgb(68, 68, 68);"></font>

**<font style="color:rgb(68, 68, 68);">适用场景：</font>**

+ <font style="color:rgb(68, 68, 68);">你希望使用某个类， 但是其接口与其他代码不兼容时</font>
+ <font style="color:rgb(68, 68, 68);">需要复用这样一些类， 他们处于同一个继承体系， 并且他们又有了额外的一些共同的方法， 但是这些</font>**<font style="color:rgb(68, 68, 68);">共同的方法不是所有在这一继承体系中的子类所具有的共性</font>**

<font style="color:rgb(68, 68, 68);"></font>

### <font style="color:rgb(68, 68, 68);">对象适配器</font>
<font style="color:rgb(68, 68, 68);">实现时使用了构成原则： 适配器实现了其中一个对象的接口， 并对另一个对象进行封装。</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741098896999-59927efd-892f-4669-8d41-e2bf80fc8b89.png)

### 类适配器
<font style="color:rgb(68, 68, 68);">这一实现使用了继承机制： 适配器同时继承两个对象的接口。 请注意， 这种方式仅能在支持多重继承的编程语言中实现</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741098925219-3ce40345-2784-4f90-a920-7184f927efad.png)

## 桥接模式 Bridge
**<font style="color:rgb(68, 68, 68);">桥接模式</font>**<font style="color:rgb(68, 68, 68);"> 可将一个大类或一系列紧密相关的类拆分为抽象和实现两个独立的层次结构， 从而能在开发时分别使用</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741231324447-6db7bc32-2062-4e12-adb3-6208983c8eea.png)

**<font style="color:rgb(68, 68, 68);">适用场景：</font>**

+ <font style="color:rgb(68, 68, 68);">如果你想要拆分或重组一个具有多重功能的庞杂类（例如能与多个数据库服务器进行交互的类）</font>
    - <font style="color:rgb(68, 68, 68);">桥接模式可以将庞杂类拆分为几个类层次结构。 此后， 你可以</font>**<font style="color:rgb(68, 68, 68);">修改任意一个类层次结构而不会影响到其他类层次结构</font>**<font style="color:rgb(68, 68, 68);">。 这种方法可以简化代码的维护工作， 并将修改已有代码的风险降到最低</font>
+ <font style="color:rgb(68, 68, 68);">希望在几个独立维度上扩展一个类</font>
    - <font style="color:rgb(68, 68, 68);">将每个维度抽取为独立的类层次。 初始类将相关工作委派给属于对应类层次的对象， 无需自己完成所有工作</font>

## <font style="color:rgb(68, 68, 68);">组合模式 </font><font style="color:rgb(68, 68, 68);">Composite</font>
**<font style="color:rgb(68, 68, 68);">组合模式 </font>**<font style="color:rgb(68, 68, 68);">也叫做对象树模式(对象树)，是一种结构型设计模式， 你可以使用它将对象组合成树状结构， 并且能像使用独立对象一样使用它们</font>

<font style="color:rgb(68, 68, 68);">应用的核心模型</font>**<font style="color:rgb(68, 68, 68);">能用树状结构表示， 在应用中使用组合模式才有价值</font>**

**<font style="color:rgb(68, 68, 68);"></font>**

**<font style="color:rgb(68, 68, 68);">结构：</font>**

**<font style="color:rgb(68, 68, 68);">组件(Component)：</font>**<font style="color:rgb(68, 68, 68);">提供 </font>**<font style="color:rgb(68, 68, 68);">组合(Composite)</font>**<font style="color:rgb(68, 68, 68);"> 与 </font>**<font style="color:rgb(68, 68, 68);">叶(Leaf)</font>**<font style="color:rgb(68, 68, 68);"> 的共用操作</font>

**<font style="color:rgb(68, 68, 68);">叶(Leaf)：</font>**<font style="color:rgb(68, 68, 68);">不管理对象树的组成，只负责执行</font><font style="color:rgb(68, 68, 68);background-color:#FBF5CB;">工作</font>

**<font style="color:rgb(68, 68, 68);">组合(Composite)：</font>**<font style="color:rgb(68, 68, 68);">负责分配子项，添加子项及相关的</font>**<font style="color:rgb(68, 68, 68);">树状管理工作</font>**

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741233468185-89a4d99f-317e-4f4f-9233-0bdf244cda8d.png)

**<font style="color:rgb(68, 68, 68);">适用场景：</font>**

+ <font style="color:rgb(68, 68, 68);">如果需要实现树状对象结构</font>
    - <font style="color:rgb(68, 68, 68);">组合模式为你提供了两种共享公共接口的基本元素类型： 简单叶节点和复杂容器。 容器中可以包含叶节点和其他容器。 这使得你可以</font>**<font style="color:rgb(68, 68, 68);">构建树状嵌套递归对象结构</font>**
+ <font style="color:rgb(68, 68, 68);">如果希望客户端代码以相同方式处理简单和复杂元素</font>
    - <font style="color:rgb(68, 68, 68);">组合模式中定义的所有元素共用同一个接口。 在这一接口的帮助下， 客户端不必在意其所使用的对象的具体类</font>

## <font style="color:rgb(68, 68, 68);">装饰模式 Decorator</font>
**<font style="color:rgb(68, 68, 68);">装饰模式</font>**<font style="color:rgb(68, 68, 68);">允许你通过将对象放入包含行为的特殊封装对象中来</font>**<font style="color:rgb(68, 68, 68);">为原对象绑定新的行为</font>**

**<font style="color:rgb(68, 68, 68);">结构：</font>**

<font style="color:rgb(68, 68, 68);">Component：存基础的公用接口(</font><font style="color:rgb(68, 68, 68);background-color:#FBF5CB;">Execute</font><font style="color:rgb(68, 68, 68);">)  
</font><font style="color:rgb(68, 68, 68);">Decorator（装饰器）：继承Component，同时存在一个Component 成员变量，调用该类的 </font><font style="color:rgb(68, 68, 68);background-color:#FBF5CB;">Execute</font><font style="color:rgb(68, 68, 68);"> 实际上是调用成员变量的</font><font style="color:rgb(68, 68, 68);background-color:#FBF5CB;">Execute </font><font style="color:rgb(68, 68, 68);"> 子类继承自该类</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741251193389-7524007c-26fd-4fe1-8ff7-1aff27e3f3d4.png)

### <font style="color:rgb(68, 68, 68);">适用场景</font>
<font style="color:rgb(68, 68, 68);">如果创建一个特殊子类来将多种通知方法组合在一起以解决该问题。 但这种方式会使得代码量迅速膨胀， 不仅仅是程序库代码， 客户端代码也会如此。下图举例了组合通知方法的复杂度</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741250918032-58b3d92e-df51-4553-9d26-49c0891f5c49.png)

<font style="color:rgb(68, 68, 68);">更改一个对象的行为时， 第一个跳入脑海的想法就是扩展它所属的类。 但是， 你</font>**<font style="color:rgb(68, 68, 68);">不能忽视继承可能引发的几个严重问题</font>**

+ <font style="color:rgb(68, 68, 68);">继承是静态的。 你无法在运行时更改已有对象的行为， 只能使用由不同子类创建的对象来替代当前的整个对象。</font>

<font style="color:rgb(68, 68, 68);"></font>

<font style="color:rgb(68, 68, 68);">因此：</font>

+ <font style="color:rgb(68, 68, 68);">如果你希望在</font>**<font style="color:rgb(68, 68, 68);">无需修改代码的情况下即可使用对象</font>**<font style="color:rgb(68, 68, 68);">， 且希望在</font>**<font style="color:rgb(68, 68, 68);">运行时为对象新增额外的行为</font>**
    - <font style="color:rgb(68, 68, 68);">装饰能将业务逻辑组织为层次结构， 你可为各层创建一个装饰， 在运行时将各种不同逻辑组合成对象</font>
    - <font style="color:rgb(68, 68, 68);">由于这些对象都遵循通用接口， 客户端代码能以相同的方式使用这些对象。</font>
+ <font style="color:rgb(68, 68, 68);">如果用继承来扩展对象行为的方案难以实现或者根本不可行</font>

## 外观模式 Facade
**<font style="color:rgb(68, 68, 68);">外观模式</font>**<font style="color:rgb(68, 68, 68);">能为程序库、 框架或其他复杂类提供一个简单的接口</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741260381786-0dbe11da-2e36-421e-9f65-74fb5ec956c4.png)



### <font style="color:rgb(68, 68, 68);">适用场景</font>
<font style="color:rgb(68, 68, 68);">上传短视频到社交媒体网站的应用可能会用到专业的视频转换库， 但它只需使用一个包含 </font>`<font style="color:rgb(68, 68, 68);background-color:rgb(238, 238, 238);">encode­()</font>`<font style="color:rgb(68, 68, 68);">方法的类即可。 在创建这个类并将其连接到视频转换库后， 你就拥有了自己的第一个外观</font>

<font style="color:rgb(68, 68, 68);"></font>

+ <font style="color:rgb(68, 68, 68);">如果你需要一个指向复杂子系统的直接接口， 且该接口的功能有限</font>
    - <font style="color:rgb(68, 68, 68);">尽管在多种情形中子系统可能是更灵活或易于复用的， 但其所需的配置和样板代码数量将会增长得更快。 为了解决这个问题， 外观将会提供指向子系统中最常用功能的快捷方式</font>
+ <font style="color:rgb(68, 68, 68);">如果需要将子系统组织为多层结构</font>
    - <font style="color:rgb(68, 68, 68);">创建外观来定义子系统中各层次的入口。 可以要求子系统仅使用外观来进行交互， 以减少子系统之间的耦合</font>

## 享元模式 Flyweight
在游戏中，相同的模型难道都要处理运算加载吗?这岂不是很浪费？

享元简单理解就是**不同对象的其中成员是相同实例，**能减少资源消耗



<font style="color:rgb(34, 34, 34);">这个模式通过将对象的数据分为两种</font>

+ <font style="color:rgb(34, 34, 34);">第一种数据没有特定指明是哪个对象的</font>_**<font style="color:rgb(34, 34, 34);">实例</font>**_<font style="color:rgb(34, 34, 34);">，因此可以在它们间分享</font>
+ <font style="color:rgb(34, 34, 34);">数据的剩余部分是</font>_**<font style="color:rgb(34, 34, 34);">变化</font>**_<font style="color:rgb(34, 34, 34);">状态，那些每个实例独一无二的东西</font>

## <font style="color:rgb(34, 34, 34);">代理模式 Proxy</font>
**<font style="color:rgb(68, 68, 68);">代理模式</font>**能够提供对象的替代品或其占位符。 代理控制着对于原对象的访问， 并允许在将请求提交给对象前后进行一些处理

代理模式<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">通过引入一个中间层（代理对象）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">控制对真实对象的访问</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">，从而在不修改原对象代码的前提下扩展功能。它的核心角色包括：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">抽象接口</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：定义代理和真实对象的共同操作（如</font>`<font style="background-color:rgb(252, 252, 252);">Image</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">接口中的</font>`<font style="background-color:rgb(252, 252, 252);">display()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">方法）；</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">真实对象</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：实现具体业务逻辑（如加载高清图片的</font>`<font style="background-color:rgb(252, 252, 252);">RealImage</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">类）；</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">代理对象</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：持有真实对象的引用，并在其操作前后添加额外逻辑（如延迟加载、权限校验）</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741317237897-19b45b77-e3ee-472e-aea2-7914f6ae61fd.png)

### 应用场景
+ 延迟初始化 （虚拟代理）。 如果你有一个偶尔使用的重量级服务对象， 一直保持该对象运行会消耗系统资源时， 可使用代理模式
+ 访问控制 （保护代理）。 如果你只希望特定客户端使用服务对象， 这里的对象可以是操作系统中非常重要的部分， 而客户端则是各种已启动的程序 （包括恶意程序）
+ 智能引用。 可在没有客户端使用某个重量级对象时立即销毁该对象

# 行为模式
行为模式负责对象间的高效沟通和职责委派

## 责任链模式 ChainOfResponsibility
**<font style="color:rgb(68, 68, 68);">责任链模式</font>**<font style="color:rgb(68, 68, 68);">将请求沿着处理者链进行发送。 收到请求后， 每个处理者均可对请求进行处理， 或将其传递给链上的下个处理者</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741327768144-9ed2fce3-e870-4c10-bda1-8dd7905bebe2.png)

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">核心特点是 </font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">解耦请求发送者与接收者</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">，并支持动态调整处理流程。核心角色包括：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">抽象处理者（Handler）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：定义处理请求的接口，维护对下一个处理者的引用。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">具体处理者（Concrete Handler）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：实现具体的处理逻辑，或决定是否将请求传递下去。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">客户端（Client）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：构建责任链并向链头发送请求</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741328861724-c3f045e6-67be-493a-9b8e-38eb4c565597.png)

### <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">应用场景</font>
+ 当程序需要使用不同方式处理不同种类请求， 而且请求类型和顺序预先未知时， 可以使用责任链模式
+ 当必须按顺序执行多个处理者时， 可以使用该模式
+ 如果所需处理者及其顺序必须在运行时进行改变， 可以使用责任链模式

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">生活案例：请假审批流程（动态传递）</font>**

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">场景</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：假设公司请假规则为：</font>

+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">1天内由直属领导批准；</font>
+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">1-3天由部门经理批准；</font>
+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">3天以上由总经理批准。</font>

## 命令模式 Common
**<font style="color:rgb(68, 68, 68);">命令模式</font>**<font style="color:rgb(68, 68, 68);">可将</font>**<font style="color:rgb(68, 68, 68);">请求转换为一个包含与请求相关的所有信息的独立对象</font>**<font style="color:rgb(68, 68, 68);">。 该转换让你能根据不同的请求将方法参数化、 延迟请求执行或将其</font>**<font style="color:rgb(68, 68, 68);">放入队列中</font>**<font style="color:rgb(68, 68, 68);">， 且</font>**<font style="color:rgb(68, 68, 68);">能实现可撤销</font>**<font style="color:rgb(68, 68, 68);">操作</font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">核心思想是</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">将“做什么”和“怎么做”分离</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">，让请求的发送者只需关注命令的触发，而不必关心具体执行细节。以下是模式的关键角色：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">命令接口（Command）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：定义执行操作的统一方法（如</font>`<font style="background-color:rgb(252, 252, 252);">execute()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">）；</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">具体命令（ConcreteCommand）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：封装特定操作及其参数，并绑定接收者；</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">接收者（Receiver）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：实际执行命令操作的对象（如设备、服务）；</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">调用者（Invoker）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：触发命令的对象（如按钮、遥控器）；</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">客户端（Client）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：创建命令对象并配置调用者。</font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"></font>

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">案例—遥控开关灯：</font>**

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">遥控器能对灯发出指令，控制灯的开关，还能撤销操作</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">命令接口（Command）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：定义两个接口，执行命令</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">(</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:#FBF5CB;">execute</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">)</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">和撤销</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">(</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:#FBF5CB;">undo</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">)</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">；</font>
    - **<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;">LightOnCommand </font>**
        * **<font style="color:rgba(0, 0, 0, 0.9);background-color:#FBF5CB;">execute</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"> ：开灯</font>
        * **<font style="color:rgba(0, 0, 0, 0.9);background-color:#FBF5CB;">undo</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"> ：关灯</font>
    - <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">  </font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;">LightOffCommand</font>**
        * **<font style="color:rgba(0, 0, 0, 0.9);background-color:#FBF5CB;">execute</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"> ：关灯</font>
        * **<font style="color:rgba(0, 0, 0, 0.9);background-color:#FBF5CB;">undo</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"> ：开灯</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">接收者（Receiver）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;">Light</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;"> </font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">有开关两个功能</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">调用者（Invoker）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;">RemoteControl </font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;"> </font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"> 有不同的命令成员，执行不同的功能</font>
    - **<font style="color:rgba(0, 0, 0, 0.9);background-color:#CEF5F7;">onCommand</font>****<font style="color:rgba(0, 0, 0, 0.9);"> ：</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;">LightOnCommand</font>** 类型，负责开灯操作
    - **<font style="color:rgba(0, 0, 0, 0.9);background-color:#CEF5F7;">offCommand</font>****<font style="color:rgba(0, 0, 0, 0.9);"> ：</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;">LightOffCommand</font>** 类型，负责关灯操作
    - **<font style="color:rgba(0, 0, 0, 0.9);background-color:#CEF5F7;">lastCommand</font>****<font style="color:rgba(0, 0, 0, 0.9);"> ：</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:#D9EAFC;">Command</font>****<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"> 类型，</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">记录最后一次执行的命令，执行该成员的 </font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:#FBF5CB;">undo</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"> (撤销)功能</font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"></font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">客户端（Client）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：创建命令对象并配置调用者。</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741332128145-6d1755c2-ebc6-4a3b-97de-53c80c193f3b.png)

### 适用场景
+ **<font style="color:rgb(68, 68, 68);">如果你要通过操作来参数化对象</font>**
    - <font style="color:rgb(68, 68, 68);">可以将命令作为方法的参数进行传递、 将命令保存在其他对象中， 或者在运行时切换已连接的命令等</font>
+ **想要将操作放入队列中、 操作的执行或者远程执行操作**
+ **想要实现操作回滚功能**

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">生活案例：智能家居遥控器（解耦控制与设备）</font>**

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">场景</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：用遥控器控制多个家电（灯、空调、音响）。  
</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">传统问题</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：若直接调用设备方法，新增设备需修改遥控器代码，违反开闭原则。  
</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">命令模式解决</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>

1. <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">遥控器按钮绑定具体命令（如“开灯”命令）；</font>
2. <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">命令对象调用接收者（灯）的实际操作；</font>
3. <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">遥控器无需知道灯如何开启，只需触发命令</font>

## 中介者模式 Mediator
**<font style="color:rgb(68, 68, 68);">中介者模式</font>**<font style="color:rgb(68, 68, 68);"> 能让你减少对象之间混乱无序的依赖关系。 该模式会</font>**<font style="color:rgb(68, 68, 68);">限制对象之间的直接交互</font>**<font style="color:rgb(68, 68, 68);">， </font>**<font style="color:rgb(68, 68, 68);">迫使它们通过一个中介者对象进行合作</font>**



**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">模式核心价值</font>**

1. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">解耦对象关系</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：将 N:M 的网状通信变为 1:N 的星型结构</font>**<font style="background-color:rgb(252, 252, 252);">6</font>**
2. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">集中控制逻辑</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：如聊天室的敏感词过滤、设备联动规则（开空调自动关窗）可集中在中介者实现</font>**<font style="background-color:rgb(252, 252, 252);">5</font>**
3. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">扩展性提升</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：新增设备只需注册到中介者，无需修改其他设备代码</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741343810798-a21b6eee-2c7f-43a1-8bbc-52884aa8a3c6.png)

### 适用场景
<font style="color:rgb(68, 68, 68);">比如真实世界中，飞机降落不是由飞机和飞机之间沟通，而是</font>**<font style="color:rgb(68, 68, 68);">统一联系塔台，由塔台通知各飞机如何降落</font>**

+ <font style="color:rgb(68, 68, 68);">一些对象和其他对象紧密耦合以致难以对其进行修改时， 可使用中介者模式</font>
+ <font style="color:rgb(68, 68, 68);">组件因过于依赖其他组件而无法在不同应用中复用时， 可使用中介者模式</font>

## <font style="color:rgb(68, 68, 68);">备忘录模式 Memento</font>
**<font style="color:rgb(68, 68, 68);">备忘录模式</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">允许在不破坏对象封装性的前提下，捕获并保存对象的内部状态，以便后续恢复到指定状态。其核心角色包括：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">Originator（原发器）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：需要保存状态的对象（如游戏角色、文本编辑器）。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">Memento（备忘录）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：存储Originator的特定时刻状态（如存档文件）。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">Caretaker（管理者）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：管理备忘录的存储与恢复（如存档管理器）</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741603208602-e8eca02e-dec0-4ecd-ae3e-efba0ebe4f46.png)

### <font style="color:rgb(68, 68, 68);">适用场景</font>
**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">生活场景</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">游戏存档</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：玩家在游戏中保存当前进度（如攻击力、位置），后续可随时从存档点恢复</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">视频播放器断点续播</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：切换视频时记录播放时间，再次切回时继续播放</font>**<font style="background-color:rgb(252, 252, 252);">5</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">开发场景</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">文本编辑器的撤销（Ctrl+Z）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：每次编辑操作后保存状态，撤销时回退到上一个状态</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">数据库事务回滚</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：保存事务执行前的数据状态，失败时恢复</font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);"></font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">总结：</font>

+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">当你需要创建对象状态快照来恢复其之前的状态时</font>
+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">当直接访问对象的成员变量、 获取器或设置器将导致封装被突破时， 可以使用该模式</font>

## <font style="color:rgb(34, 34, 34);">观察者模式Observer</font>
**观察者模式** 允许你定义一种订阅机制， 可在对象事件发生时通知多个 “观察” 该对象的其他对象。

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">对象间的一对多依赖关系，使得当一个对象（主题/被观察者）状态变化时，所有依赖它的对象（观察者）会自动收到通知并更新</font>

其核心角色包括：

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">Subject（主题）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：维护观察者列表，提供注册、移除和通知观察者的接口。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">Observer（观察者）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：定义更新接口，用于接收主题状态变化的通知。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">ConcreteSubject/ConcreteObserver</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：具体实现类。</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741604223918-c4a455e4-ddaf-4529-8db1-53cf438a11df.png)

### 适用场景
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">生活场景</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>
    1. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">公众号订阅</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：用户关注公众号后，公众号发布新文章时，所有订阅者会收到推送通知</font>**<font style="background-color:rgb(252, 252, 252);"></font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>
    2. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">天气预报服务</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：用户订阅天气预报后，天气数据变化时自动推送最新信息</font>**<font style="background-color:rgb(252, 252, 252);"></font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">开发场景</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>
    1. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">GUI事件监听</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：按钮点击事件触发多个监听器的响应（如网页中的按钮点击回调）</font>**<font style="background-color:rgb(252, 252, 252);"></font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>
    2. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">游戏成就系统</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：玩家达成特定条件（如击败Boss）时，成就系统自动解锁并更新UI</font>**<font style="background-color:rgb(252, 252, 252);"></font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>
    3. **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">数据与UI同步</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：在MVC架构中，Model数据更新后自动刷新View</font>**<font style="background-color:rgb(252, 252, 252);"></font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">。</font>

**总结：**

+ 当一个对象状态的改变需要改变其他对象， 或实际对象是事先未知的或动态变化的时
+ 当应用中的一些对象必须观察其他对象时， 可使用该模式。 但仅能在有限时间内或特定情况下使用

## 状态模式
状态模式 让你能在一个对象的内部状态变化时改变其行为， 使其看上去就像改变了自身所属的类一样

+ 存在一个状态接口基类(状态机)，让不同的状态继承这个基类
+ 重写其执行内容的方法，让有不同状态的类定义最基类的状态机变量
+ 切换状态就是<font style="color:#DF2A3F;">让状态机指向不同的状态机类 </font>，总的来说就是多态的应用

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741660073075-4ef019ac-4928-4060-8348-c1bc216e1a26.png)

**电梯控制系统（生活场景）**

电梯有四个核心状态：**停止状态、运行状态、开门状态、关门状态**。不同状态下电梯对操作的响应不同：

+ 停止状态：可响应开门请求，但拒绝移动请求
+ 运行状态：可响应到达目标楼层事件，但拒绝开门请求
+ 开门状态：自动触发关门倒计时，拒绝移动请求
+ 关门状态：可响应移动请求

通过将每个状态的行为封装为独立类，当电梯状态切换时，只需替换当前状态对象，无需复杂的if-else分支判断

### 适用场景
**总结：**

+ <font style="color:rgb(68, 68, 68);">如果对象需要根据自身当前状态进行不同行为， 同时状态的数量非常多且与状态相关的代码会频繁变更的话， 可使用状态模式</font>
+ <font style="color:rgb(68, 68, 68);">如果某个类需要根据成员变量的当前值改变自身行为， 从而需要使用大量的条件语句时， 可使用该模式</font>
+ <font style="color:rgb(68, 68, 68);">当相似状态和基于条件的状态机转换中存在许多重复代码时， 可使用状态模式</font>

## <font style="color:rgb(68, 68, 68);">策略模式 Strategy</font>
**策略模式** 能让你定义一系列算法， 并将每种算法分别放入独立的类中， 以使算法的对象能够相互替换

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">角色构成</font>**

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">策略接口</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">（如</font>`<font style="background-color:rgb(252, 252, 252);">DiscountStrategy</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">）定义算法标准</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">具体策略类</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">（如</font>`<font style="background-color:rgb(252, 252, 252);">VipDiscount</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">、</font>`<font style="background-color:rgb(252, 252, 252);">WechatPay</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">）实现具体算法</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">上下文类</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">（如</font>`<font style="background-color:rgb(252, 252, 252);">ShoppingCart</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">）持有策略引用并调用</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741662504433-28330e01-60f0-455b-95d6-a8fcb6b75f9e.png)

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">商场折扣策略（生活场景）</font>**

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">商场根据不同客户类型提供不同折扣：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">新客户</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：无折扣</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">老客户</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：9折</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">VIP客户</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：8折</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">节假日促销</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：额外满减</font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">通过</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">将每种折扣逻辑封装为独立策略类，收银系统只需切换策略对象即可动态计算价格</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">，无需修改核心代码</font>

### <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">适用场景</font>
+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">当系统需要在运行时根据需求灵活选择不同算法实现时（如电商促销活动切换满减、折扣、秒杀策略）</font>
+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">当存在多个仅在行为细节上存在差异的类时（如不同排序算法、表单验证规则或支付方式）</font>
+ <font style="color:rgb(68, 68, 68);"></font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">当算法实现复杂度较高或对业务逻辑非核心时（如网络流量控制规则、数据库连接策略）</font>
+ <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">当类中存在多重条件语句（如</font>`<font style="color:rgba(0, 0, 0, 0.9);">if-else</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">或</font>`<font style="color:rgba(0, 0, 0, 0.9);">switch-case</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">）管理不同行为时（如游戏角色技能选择、权限校验规则）</font>

## <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">模板方法模式 </font><font style="color:rgb(68, 68, 68);">TemplateMethod</font>
**模板方法模式** 在超类中定义了一个算法的框架， 允许子类在不修改结构的情况下重写算法的特定步骤

**特性**

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">固定流程</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>`<font style="background-color:rgb(252, 252, 252);">prepareBeverage()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">定义通用步骤顺序，不可被子类重写</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">差异扩展</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：子类仅需实现</font>`<font style="background-color:rgb(252, 252, 252);">brew()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">和</font>`<font style="background-color:rgb(252, 252, 252);">addCondiments()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">方法</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">多态调用</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：通过抽象类指针动态绑定具体子类行为</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741663766940-4d253a36-db75-41ad-8653-ff5350bfc943.png)

### 适用场景
**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">烹饪流程（生活场景）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font><font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">制作不同菜品的流程遵循固定步骤，但具体操作细节不同：</font>

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">通用步骤</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：准备食材→烹饪→装盘→调味</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">差异步骤</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>
    - **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">披萨</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：面团发酵、烤箱烘烤、撒芝士</font>
    - **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">蛋糕</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：混合面糊、模具烘焙、涂抹奶油</font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">模板方法将通用流程封装在抽象类中，差异步骤由子类实现</font>

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">总结：</font>**

+ <font style="color:rgb(68, 68, 68);">扩展某个特定算法步骤， 而不是整个算法或其结构时</font>
+ <font style="color:rgb(68, 68, 68);">多个类的算法除一些细微不同之外几乎完全一样时</font>

## <font style="color:rgb(68, 68, 68);">访问者模式 </font><font style="color:rgb(68, 68, 68);">Visitor</font>
**<font style="color:rgb(68, 68, 68);">访问者模式 </font>**<font style="color:rgb(68, 68, 68);">能将算法与其所作用的对象隔离开来</font>

<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">通过</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">双分派机制</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">（Double Dispatch）实现</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">数据结构与操作的解耦</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">，将操作逻辑封装在独立访问者对象中</font>

**<font style="color:rgb(68, 68, 68);">其核心角色包括：</font>**

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">抽象访问者（Visitor）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：定义对所有元素类型的操作接口（如</font>`<font style="background-color:rgb(252, 252, 252);">visit()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">方法）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">具体访问者（ConcreteVisitor）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：实现针对不同元素的具体操作逻辑</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">元素接口（Element）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：声明接受访问者的</font>`<font style="background-color:rgb(252, 252, 252);">accept()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">方法</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">对象结构（ObjectStructure）</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：管理元素集合并提供遍历接口</font>

![](https://cdn.nlark.com/yuque/0/2025/png/36214189/1741664686040-3cc2d379-569a-4810-b600-784bb39f8147.png)

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">双向依赖</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：元素类通过</font>`<font style="background-color:rgb(252, 252, 252);">accept()</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">调用访问者，访问者通过重载方法处理具体元素</font>**<font style="background-color:rgb(252, 252, 252);">1214</font>**

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">对象结构隔离</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>`<font style="background-color:rgb(252, 252, 252);">DocumentSystem</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">仅关注元素集合管理</font>

**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">扩展方向</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：新增操作（如加密）需扩展</font>`<font style="background-color:rgb(252, 252, 252);">Compressor</font>`<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">，新增元素类型需修改所有访问者</font>

### <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">适用场景</font>
**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">博物馆导览系统（生活场景）</font>**

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">对象结构</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：展品集合（油画、雕塑、古籍）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">访问者</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：普通游客、艺术研究者、儿童讲解员</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">操作差异</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：</font>
    - <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">普通游客获取简介</font>
    - <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">艺术研究者查看修复记录</font>
    - <font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">儿童讲解员播放动画解说</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">优势</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">：新增导览类型无需修改展品类代码</font>**<font style="background-color:rgb(252, 252, 252);">69</font>**

**总结：**

+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">稳定数据结构 + 频繁变化的操作</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">（如电商订单的计价、报表生成）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">跨类型统一处理</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">（如编译器对语法树节点的类型检查、代码优化）</font>
+ **<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">避免污染对象结构</font>**<font style="color:rgba(0, 0, 0, 0.9);background-color:rgb(252, 252, 252);">（如文档系统对图片、视频、文本的压缩/加密操作</font>

# 类型对象
_<font style="color:rgb(34, 34, 34);">创造一个类A来允许灵活地创造新“类型”，类A的每个实例都代表了不同的对象类型。</font>_

<font style="color:rgb(34, 34, 34);">比如血量、攻击是怪物都有的，龙也有，史莱姆也有，在他们父类中定义相关变量就行了。</font>

<font style="color:rgb(34, 34, 34);">但是这样如果需要修改，就需要动代码，然后重新编译。</font>

<font style="color:rgb(34, 34, 34);">想想UE的GAS，</font>**<font style="color:rgb(34, 34, 34);">属性集是一个单独的类，让需要属性的类添加属性集就行了，而且为了方便修改属性数值，可以配表、文件读数据进行初始化</font>**

# <font style="color:rgb(34, 34, 34);">组件模式</font>
**<font style="color:rgb(34, 34, 34);">单一实体跨越了多个领域</font>**<font style="color:rgb(34, 34, 34);">。为了保持领域之间相互分离，将每部分代码放入</font>**<font style="color:rgb(34, 34, 34);">各自的组件类</font>**<font style="color:rgb(34, 34, 34);">中。 实体被简化为</font>_**<font style="color:rgb(34, 34, 34);">组件的容器</font>**_<font style="color:rgb(34, 34, 34);">。</font>

<font style="color:rgb(34, 34, 34);"></font>

<font style="color:rgb(34, 34, 34);">组件通常在定义游戏实体的核心部分中使用，但它们在其他地方也有用。 </font>

<font style="color:rgb(34, 34, 34);">这个模式应用在在如下情况中：</font>

+ <font style="color:rgb(34, 34, 34);">有一个涉及了多个领域的类，而你想保持这些领域互相隔离。</font>
+ <font style="color:rgb(34, 34, 34);">一个类正在变大而且越来越难以使用。</font>
+ <font style="color:rgb(34, 34, 34);">想要能定义一系列分享不同能力的类，但是使用继承无法让你精确选取要重用的部分。</font>

## <font style="color:rgb(34, 34, 34);">对象如何获取组件？</font>
+ **<font style="color:rgb(34, 34, 34);">如果对象创建组件：</font>**
    - _**<font style="color:rgb(34, 34, 34);">这保证了对象总是能拿到需要的组件。</font>**_<font style="color:rgb(34, 34, 34);"> </font><font style="color:rgb(34, 34, 34);">你永远不必担心某人忘记连接正确的组件然后破坏了整个游戏。容器类自己会处理这个问题。</font>
    - _**<font style="color:rgb(34, 34, 34);">重新设置对象比较困难。</font>**_<font style="color:rgb(34, 34, 34);"> </font><font style="color:rgb(34, 34, 34);">这个模式的强力特性之一就是只需重新组合组件就可以创建新的对象。 如果对象总是用硬编码的组件组装自己，我们就无法利用这个特性。</font>
+ **<font style="color:rgb(34, 34, 34);">如果外部代码提供组件：</font>**
    - _**<font style="color:rgb(34, 34, 34);">对象更加灵活。</font>**_<font style="color:rgb(34, 34, 34);"> </font><font style="color:rgb(34, 34, 34);">我们可以提供不同的组件，这样就能改变对象的行为。 通过共用组件，对象变成了组件容器，我们可以为不同目的一遍又一遍地重用它。</font>
    - _**<font style="color:rgb(34, 34, 34);">对象可以与具体的组件类型解耦。</font>**_

<font style="color:rgb(34, 34, 34);">如果我们允许外部代码提供组件，好处是也可以传递</font>_**<font style="color:rgb(34, 34, 34);">派生</font>**_<font style="color:rgb(34, 34, 34);">的组件类型。 这样，对象只知道组件</font>_**<font style="color:rgb(34, 34, 34);">接口</font>**_<font style="color:rgb(34, 34, 34);">而不知道组件的具体类型。这是一个很好的封装结构。</font>

## <font style="color:rgb(34, 34, 34);">组件之间如何通信？</font>
# 事件队列
**<font style="color:rgb(34, 34, 34);">事件队列</font>**<font style="color:rgb(34, 34, 34);">在队列中按先入先出的顺序存储一系列</font>**<font style="color:rgb(34, 34, 34);">通知或请求</font>**<font style="color:rgb(34, 34, 34);">。 发送通知时，</font>**<font style="color:rgb(34, 34, 34);">将请求放入队列并返回</font>**<font style="color:rgb(34, 34, 34);">。 处理请求的系统之后稍晚</font>**<font style="color:rgb(34, 34, 34);">从队列中获取请求</font>**<font style="color:rgb(34, 34, 34);">并处理。 这</font>**<font style="color:rgb(34, 34, 34);">解耦了发送者和接收者</font>**<font style="color:rgb(34, 34, 34);">，既</font>**<font style="color:rgb(34, 34, 34);">静态</font>**<font style="color:rgb(34, 34, 34);">又</font>**<font style="color:rgb(34, 34, 34);">及时</font>**<font style="color:rgb(34, 34, 34);">。</font>

# <font style="color:rgb(34, 34, 34);">脏标识数据</font>
<font style="color:rgb(34, 34, 34);">一组</font>**<font style="color:rgb(34, 34, 34);">原始数据</font>**<font style="color:rgb(34, 34, 34);">随着时间变化而改变。 使用</font>**<font style="color:rgb(34, 34, 34);">代价昂贵的过程</font>**<font style="color:rgb(34, 34, 34);">推定一组</font>**<font style="color:rgb(34, 34, 34);">导出数据</font>**<font style="color:rgb(34, 34, 34);">。 用一个</font>**<font style="color:rgb(34, 34, 34);">“脏”标识</font>**<font style="color:rgb(34, 34, 34);">追踪导出数据是否与原始数据保持一致。 它在</font>**<font style="color:rgb(34, 34, 34);">原始数据改变时被设置。</font>**<font style="color:rgb(34, 34, 34);"> 如果导出数据被请求时，该标识被设置了，那么</font>**<font style="color:rgb(34, 34, 34);">重新计算并清除标识</font>**<font style="color:rgb(34, 34, 34);"> 否则的话，使用之前</font>**<font style="color:rgb(34, 34, 34);">缓存的导出数据</font>**<font style="color:rgb(34, 34, 34);">。</font>

<font style="color:rgb(34, 34, 34);">这里是一些其他的应用场景：</font>

+ **<font style="color:rgb(34, 34, 34);">原始数据的变化速度远高于导出数据的使用速度。</font>**<font style="color:rgb(34, 34, 34);"> </font><font style="color:rgb(34, 34, 34);">避免在导出数据使用前原始数据多次变化带来的不必要计算。 如果你总在原始数据变化后立即使用导出数据，这个模式无法帮忙。</font>
+ **<font style="color:rgb(34, 34, 34);">增量更新十分困难。</font>**<font style="color:rgb(34, 34, 34);"> 假设海盗船只能携带特定数量的战利品。我们需要获取携带事物的总重量。 我们</font>_**<font style="color:rgb(34, 34, 34);">可以</font>**_<font style="color:rgb(34, 34, 34);">使用这个模式，然后为总重量设立脏标识。每次添加或者移除一些战利品，我们设置这个标识。 当我们需要总量时，将所有战利品的重量加起来，然后清除标识。</font>

# <font style="color:rgb(34, 34, 34);">对象池</font>
<font style="color:rgb(34, 34, 34);">定义一个</font>**<font style="color:rgb(34, 34, 34);">池</font>**<font style="color:rgb(34, 34, 34);">对象，其包含了一组</font>**<font style="color:rgb(34, 34, 34);">可重用对象</font>**<font style="color:rgb(34, 34, 34);">。 其中每个可重用对象都支持</font>**<font style="color:rgb(34, 34, 34);">查询“使用中”状态</font>**<font style="color:rgb(34, 34, 34);">，说明它是不是“正在使用”。 池被初始化时，它就</font>**<font style="color:rgb(34, 34, 34);">创建了整个对象集合</font>**<font style="color:rgb(34, 34, 34);">（通常使用一次连续的分配），然后初始化所有对象到“不在使用中”状态。</font>

<font style="color:rgb(34, 34, 34);">当你需要新对象，向池子要一个。 它找到一个可用对象，初始化为“使用中”然后返回。 当对象不再被需要，它被设置回“不在使用中”。 通过这种方式，可以轻易地创建和销毁对象而不必分配内存或其他资源。</font>

<font style="color:rgb(34, 34, 34);">在以下情况中使用对象池：</font>

+ <font style="color:rgb(34, 34, 34);">需要频繁创建和销毁对象。</font>
+ <font style="color:rgb(34, 34, 34);">对象大小相仿。</font>
+ <font style="color:rgb(34, 34, 34);">在堆上进行对象内存分配十分缓慢或者会导致内存碎片。</font>
+ <font style="color:rgb(34, 34, 34);">每个对象都封装了像数据库或者网络连接这样很昂贵又可以重用的资源。</font>

# <font style="color:rgb(34, 34, 34);">空间分区</font>
<font style="color:rgb(34, 34, 34);">对于一系列</font>**<font style="color:rgb(34, 34, 34);">对象</font>**<font style="color:rgb(34, 34, 34);">，每个对象都有</font>**<font style="color:rgb(34, 34, 34);">空间上的位置</font>**<font style="color:rgb(34, 34, 34);">。 将它们存储在根据位置组织对象的</font>**<font style="color:rgb(34, 34, 34);">空间数据结构</font>**<font style="color:rgb(34, 34, 34);">中，让你</font>**<font style="color:rgb(34, 34, 34);">有效查询在某处或者某处附近的对象</font>**<font style="color:rgb(34, 34, 34);">。 当对象的位置改变时，</font>**<font style="color:rgb(34, 34, 34);">更新空间数据结构</font>**<font style="color:rgb(34, 34, 34);">，这样它可以继续找到对象。</font>

<font style="color:rgb(34, 34, 34);">一句话，在相同空间区域之间的对象才能互相产生影响</font>

