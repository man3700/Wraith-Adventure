#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define g_device DXUTGetD3D9Device()
//���̷�ƮX�� ����̽�(device)��� ������ ����Ѵ�
//�� ����̽��� ���α׷��Ӱ� �׷���ī�带 �����Ҽ� �ִ� ����� �ִ� �༮�̶� �����ϸ� �ȴ�

#ifdef _DEBUG
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log)
#endif

const int WINSIZEX = 768;
const int WINSIZEY = 600;

//�Ŵ��� �߰�
#include "cImageManager.h"
#include "cSceneManager.h"