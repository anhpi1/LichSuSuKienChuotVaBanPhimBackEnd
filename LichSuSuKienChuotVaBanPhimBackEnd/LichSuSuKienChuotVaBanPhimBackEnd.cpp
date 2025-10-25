// LichSuSuKienChuotVaBanPhimBackEnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestController.h"
#include "TestModel.h"
#include "TestView.h"

int main()
{
	Vector2 a = TestVectorKhoiTao(2,4), b = TestVectorKhoiTao(1,1);
	a = TestVector2Cong(a, b);
	TestVector2Xem(a);
	if (ConnectDatabase()) {
		InsertVector2(a.a, a.b);
		std::vector<Vector2>Data = SelectVector2();
		ViewAllVector2(Data);
		DisconnectDatabase();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
