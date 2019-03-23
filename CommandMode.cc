/*
 * 命令对象讲动作和接受者包进对象中, 这个对象只暴露一个execute()方法
 * 例子: 遥控器上有一个插槽, 可以放上不同装置, 然后用按钮控制. 
 */
#include <iostream>
// 电灯类
class Light
{
  public:
    void on()
    {
        std::cout << "Light on" << std::endl;
    };
    void off()
    {
        std::cout << "Light off" << std::endl;
    };
};
// 命令类
class Command
{
  public:
    virtual void execute() = 0;
    virtual ~Command(){};
};


int main(int argc, char** argv)
{
    return 0;
}
