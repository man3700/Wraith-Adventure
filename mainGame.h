#pragma once
class mainGame
{
private:

public:
	mainGame();//���� ���� ������
	~mainGame();//���� ���� �Ҹ���

	void Init();//���� //�Ŵ��������� Init�� ���ΰ����� Init�� �����ǰ�? 
	//������ �� �ʱ�ȭ, �⺻ ����
	void Release();//�ʱ�ȭ
	//�Ҵ�� ���� ����
	void Update();//����
	//����� ����, �Է¹޴� ����
	void Render();//���
	//ȭ�鿡 ���̴� ��

	void LostDevice();  
	void ResetDevice();
};