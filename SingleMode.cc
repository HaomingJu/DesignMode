#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
class SingleModeClass
{
  public:
    static std::unique_ptr<SingleModeClass> getInstance();
    void func1();
    void func2();

  public:
    ~SingleModeClass() = default;
    SingleModeClass(const SingleModeClass&) = delete;
    SingleModeClass& operator=(const SingleModeClass&) = delete;

  private:
    SingleModeClass() = default;
    static std::unique_ptr<SingleModeClass> sm_smart_ptr;
    static std::mutex sm_mutex;
};

std::unique_ptr<SingleModeClass> SingleModeClass::sm_smart_ptr;
std::mutex SingleModeClass::sm_mutex;
std::unique_ptr<SingleModeClass> SingleModeClass::getInstance()
{
    std::lock_guard<std::mutex> lg(sm_mutex);
    if(!(SingleModeClass::sm_smart_ptr.get()))
    {
        SingleModeClass::sm_smart_ptr.reset(new SingleModeClass());
    }
    return std::move(SingleModeClass::sm_smart_ptr);
};

void SingleModeClass::func1()
{
    std::cout << "SingleModeClass::func1: hello world." << std::endl;
    return;
};

void SingleModeClass::func2()
{
    std::cout << "SingleModeClass::func2: hello world." << std::endl;
    return;
};
void thread_func1()
{
    for(std::size_t i = 0; i < 100; ++i)
    {
        auto a = SingleModeClass::getInstance();
        a->func1();
    }
};
void thread_func2()
{
    for(std::size_t i = 0; i < 100; ++i)
    {
        auto a = SingleModeClass::getInstance();
        a->func2();
    }
};

int main(int argc, char** argv)
{


    std::thread t1(thread_func1);
    std::thread t2(thread_func2);
    if(t1.joinable())
        t1.join();

    if(t2.joinable())
        t2.join();
    return 0;
}
