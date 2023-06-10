#include <iostream>
using namespace std;

class AbstractSmile
{
public:
    virtual void transform() 
    {
        cout << "abstract 基函数 transform" << endl;
    }
    virtual void ability() 
    {
        cout << "abstract 基函数 transform" << endl;

    }
    virtual ~AbstractSmile() {}
};
// 人造恶魔果实· 绵羊形态
class SheepSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 山羊人形态..." << endl;
    }
    void ability() override
    {
        cout << "将手臂变成绵羊角的招式 -- 巨羊角" << endl;
    }
};

// 人造恶魔果实· 狮子形态
class LionSmile : public AbstractSmile
{
public:
    void transform() override   // c++ 关键字，表示覆盖基类的虚函数。如果重写函数名和基类的虚函数不一样，就报错
    {
        cout << "变成人兽 -- 狮子人形态..." << endl;
    }
    void ability() override
    {
        cout << "火遁· 豪火球之术..." << endl;
    }
};

class BatSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 蝙蝠人形态..." << endl;
    }
    void ability() override
    {
        cout << "声纳引箭之万剑归宗..." << endl;
    }
};

// 恶魔果实工厂类
enum class Type:char{SHEEP, LION, BAT};  // C++ 11 新特性，强枚举类型，枚举类，更加安全使用，定义枚举。 转换其他类型需要显示转换
class SmileFactory
{
public:
    SmileFactory() {}
    ~SmileFactory() {}
    AbstractSmile* createSmile(Type type)
    {
        AbstractSmile* ptr = nullptr;
        switch (type)
        {
        case Type::SHEEP:
            ptr = new SheepSmile;
            break;
        case Type::LION:
            ptr = new LionSmile;
            break;
        case Type::BAT:
            ptr = new BatSmile;
            break;
        default:
            break;
        }
        return ptr;
    }
};

int main()
{

    // cout << "==============11===============" << endl;
    // AbstractSmile *p = new AbstractSmile();
    // p->transform();
    // p->ability();

    cout << "==============22===============" << endl;
    SmileFactory* factory = new SmileFactory;
    AbstractSmile* obj = factory->createSmile(Type::BAT);
    obj->transform();
    obj->ability();

    cout << "==============33===============" << endl;

    AbstractSmile* obj1 = factory->createSmile(Type::LION);
    obj1->transform();
    obj1->ability();
    return 0;
}
