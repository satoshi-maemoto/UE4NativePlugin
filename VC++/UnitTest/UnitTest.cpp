#include "pch.h"
#include "CppUnitTest.h"
#include "SimpleDll.h"
#include <Windows.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			for (auto i = 0; i < 100; i++)
			{
				OutputDebugString((std::to_wstring(i) + L"\n").c_str());
				auto a = GetStringValue(i);
				Assert::AreEqual(GetStringValue(i) == std::to_wstring(i), true);
			}
		}
	};
}
