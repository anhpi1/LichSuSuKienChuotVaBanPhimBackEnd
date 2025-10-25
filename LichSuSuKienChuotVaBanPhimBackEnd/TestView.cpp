#include "TestView.h"


void ViewAllVector2(std::vector<Vector2> a) {
	for(auto v : a) {
		printf("Vector2: %d , %d\n", v.a, v.b);
	}
}

