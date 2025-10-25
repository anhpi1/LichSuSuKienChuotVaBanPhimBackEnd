#include "TestController.h"


Vector2 TestVectorKhoiTao(int a, int b) {
	Vector2 v;
	v.a = a;
	v.b = b;
	return v;
}

Vector2 TestVector2Cong(Vector2 a, Vector2 b) {
	a.a += b.a;
	a.b += b.b;
	return a;	
}

void TestVector2Xem(Vector2 a) {
	printf("%d , %d\n", a.a, a.b);
}