#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define g_device DXUTGetD3D9Device()
//다이렉트X는 디바이스(device)라는 개념을 사용한다
//이 디바이스는 프로그래머가 그래픽카드를 제어할수 있는 방법을 주는 녀석이라 생각하면 된다

#ifdef _DEBUG
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log)
#endif

const int WINSIZEX = 768;
const int WINSIZEY = 600;

//매니저 추가
#include "cImageManager.h"
#include "cSceneManager.h"