#pragma once
#ifndef TEST_MODEL_H
#define TEST_MODEL_H

#include <windows.h>
#include <sqlext.h>
#include <string>
#include <vector>
#include <iostream>

typedef struct {
	int a;
	int b;
}Vector2;

bool ConnectDatabase();
void DisconnectDatabase();
bool InsertVector2(int a, int b);
std::vector<Vector2> SelectVector2();


#endif
