#include <iostream>
using namespace std;

namespace library
{
    class Facade
    {
    private:
        class SubsystemA
        {
        public:
            string A1();
            string A2();
        };

        class SubsystemB
        {
        public:
            string B1();
        };

        class SubsystemC
        {
        public:
            string C1();
        };

    public:
        static void Operation1();
        static void Operation2();
    };
}
