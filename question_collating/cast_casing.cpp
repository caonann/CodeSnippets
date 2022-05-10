//强制类型转换的一些坑解析
#include <iostream>
#include <utility>

class A
{
   public:
    std::string a_name;
    virtual void SetAName(std::string name) { a_name = std::move(name); }

    virtual std::string &GetAName() { return a_name; }
};

class B
{
   public:
    virtual void SetEnabled(bool enable) = 0;

    virtual bool GetEnabled() = 0;
};

std::string empty_str = std::string("被禁止了");

class C : public A, public B
{
   public:
    std::string d_name;
    bool enable = true;

    bool GetEnabled() override { return enable; }

    void SetEnabled(bool enable) override { this->enable = enable; }

    void SetAName(std::string name) override
    {
        A::SetAName(name);
        d_name = std::move(name);
    }

    std::string &GetAName() override
    {
        if (GetEnabled()) {
            return d_name;
        } else {
            return empty_str;
        }
    }
};

int main()
{
    C *demo = new C();
    demo->SetAName("sollian");
    std::cout << demo->GetAName() << std::endl;
    // 问题描述：在注释处崩溃。同样是解析为父类指针，a_class的函数调用没问题，b_class不行。

    intptr_t addr = reinterpret_cast<intptr_t>(demo);
    // 实际业务场景要求从addr进行转换
    A *a_class = reinterpret_cast<A *>(addr);
    a_class->SetAName("jojo");  // 这里没问题

    B *b_class = reinterpret_cast<B *>(addr);
    b_class->SetEnabled(false);  // 这里会崩溃

    std::cout << demo->GetAName() << std::endl;
    delete demo;

    /*
    原因是用错了cast。从C的指针转为A和B的指针，应该用static_cast（或者dynamic_cast)，转出来的地址是不同的，带了偏移。reinterpret_cast“强制当成”地址，不带偏移：
     C *p = reinterpret_cast<C *>(addr);
        A *a_class = static_cast<A *>(p);
        a_class->SetAName("jojo");
        std::cout << "A: " << a_class << '\n';

        B *b_class = static_cast<B *>(p);
        b_class->SetEnabled(false);
        std::cout << "B: " << b_class << '\n';

        A: 0x607000001130
        B: 0x607000001150
        A的地址和C相同，假如写成class C: public B, public A，则B的地址和C相同（可能是implementation
    defined，代码上不应该依赖这种行为） 慎用reinterpret_cast 两种cast同时满足条件时，用最安全的、要求最严格的那个

        简单来说，多重继承的情况下，reinterpret_cast过去再reinterpret_cast回来，必须是同一个类的指针。不允许reinterpret_cast在子类父类之间乱转。
        B *b_class = reinterpret_cast<B *>(addr + sizeof(A)); 加了偏移量可以了
        或者：
        intptr_t addr = reinterpret_cast<intptr_t>(static_cast<B*>(demo));
        再addr to B*
        要么先reinterpret_cast到C*再static_cast到B*
    */
    return 0;
}
