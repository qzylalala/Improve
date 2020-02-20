#include <iostream>
#include <thread>


void thread_function()
{
    for(int i = 0; i < 10; i++)
        std::cout<<"thread function Executing"<<std::endl;
}

int main()
{
    std::thread threadObj(thread_function);
    for(int i = 0; i < 10; i++)
        std::cout<<"Display From MainThread"<<std::endl;
    std::cout << threadObj.hardware_concurrency() << std::endl;
    threadObj.join();
    std::cout<<"Exit of Main function"<<std::endl;

    system("pause");
    return 0;
}