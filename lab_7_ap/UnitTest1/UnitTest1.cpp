#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_ap/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(QueueTest)
    {
    public:

        TEST_METHOD(TestEnqueue)
        {
           
            Elem* first = nullptr;
            Elem* last = nullptr;
            Patient p1 = { "Doe", "Flu", 0 };
            Patient p2 = { "Smith", "Fever", 0 };

           
            enqueue(first, last, p1);
            enqueue(first, last, p2);

         
            Assert::AreEqual(first->info.surname, p1.surname);
            Assert::AreEqual(first->link->info.surname, p2.surname);
        }
    };
}
