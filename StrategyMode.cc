#include <iostream>
#include <memory>
/*
 * Strategy Mode 策略模式 
 * 将每种算法封装起来, 并且可以使他们可以相互替换
 * 抽象策略 具体策略 环境角色
 */
// 抽象策略类
class IWind
{
  public:
    virtual ~IWind(){};
    virtual void blowWind() = 0;
};
// 具体策略类
class ColdWind : public virtual IWind
{
  public:
    void blowWind()
    {
        std::cout << "blow cold wind." << std::endl;
    };
};
class HotWind : public virtual IWind
{
  public:
    void blowWind()
    {
        std::cout << "blow hot wind." << std::endl;
    };
};
// 环境
class WindMode
{
  public:
    WindMode(IWind* const sptr)
    {
        m_smart_ptr.reset(sptr);
    };
    void blowWind()
    {
        m_smart_ptr->blowWind();
    };

  private:
    std::unique_ptr<IWind> m_smart_ptr;
};

int main(int argc, char** argv)
{
    WindMode* cold_wind = new WindMode(new ColdWind());
    WindMode* hot_wind = new WindMode(new HotWind());
    cold_wind->blowWind();
    hot_wind->blowWind();

    delete cold_wind;
    delete hot_wind;
    return 0;
}
