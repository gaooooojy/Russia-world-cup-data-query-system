#pragma once

//��Ա��Ϣ��¼
struct PlayerInfor
{
	char name[20];  //��Ա����
	char nameTeam[20];  //�����������
	int number;  //���
	int numGoal;  //������ -- ���ְ���������
};

const int NPLAYER = 150;  //�������籭һ����110�˽���

//��Ա��Ϣ������
class PlayerInforManage
{
private:
	//��Ա��Ϣ������ݳ�Ա
	PlayerInfor player[NPLAYER];  //��Ա��Ϣ�ṹ����
	int playerCount;  //���ļ��ж������Ա��Ϣ����

public:
	//��������
	void Display(const PlayerInfor &playerInfor);  //��ʾ������Ϣ
	void DisplayALL();  //��ʾ���н����¼
	void ShooterList();  //������Ա��Ϣ�������ְ���ʾ

	PlayerInforManage();  //�޲ι��캯�� - ��Ա��Ϣ��ʼ��
//	virtual ~PlayerInforManage();  //��������
};