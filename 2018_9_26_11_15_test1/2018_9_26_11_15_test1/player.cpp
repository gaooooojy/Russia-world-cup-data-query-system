#include "pch.h"
#include "player.h"

void PlayerInforManage::Display(const PlayerInfor & playerInfor)
//�����������ʾָ����Ա��Ϣ
{
	cout << playerInfor.name << "\t"
		<< playerInfor.nameTeam << "\t"
		<< playerInfor.number << "\t"
		<< playerInfor.numGoal << endl;
}

void PlayerInforManage::DisplayALL()
//�����������ʾ������Ա��Ϣ
{
	cout << "����" << "\t" << "���" << "\t"
		<< "���" << "\t" << "������" << endl;

	for (int i = 0; i < playerCount; ++i)
	{
		Display(player[i]);
	}
}

void PlayerInforManage::ShooterList()
//������Ա��Ϣ�������ְ���ʾ
{
	PlayerInfor playerCopy[NPLAYER];  //˽�г�Աplayer�ṹ����Ŀ���

	//��player[NPLAYER]�е����ݿ�����playerCopy[NPLAYER]
	for (int i = 0; i < 4; ++i)
	{
		strcpy(playerCopy[i].name, player[i].name);
		strcpy(playerCopy[i].nameTeam, player[i].nameTeam);
		playerCopy[i].number = player[i].number;
		playerCopy[i].numGoal = player[i].numGoal;
	}

	//����numGoalð������ - �������ְ� -- Waiting...


	//���ְ����� - ð������
	


}

PlayerInforManage::PlayerInforManage()
//�����������ʼ����Ա��Ϣ
{
	playerCount = 0;

	//�����playerRecord.txt�ļ��ж�ȡ���ݵ��ṹ��������
	ifstream infile("F:\\VS2017\\2018_9_26_11_15_test1\\2018_9_26_11_15_test1\\playerRecord.txt", ios::in); //������ķ�ʽ���ļ�

	if (!infile)  //�����Ƿ�򿪳ɹ�
	{
		cerr << "open playerRecord.txt error" << endl;
		exit(1);  //��������
	}

	int i = 0;  //��ʱ��������
	while (!infile.eof())
	{
		infile >> player[i].name  //��Ա����
			>> player[i].nameTeam  //��������
			>> player[i].number  //��Ա���
			>> player[i].numGoal;  //������

		++playerCount;
		++i;
	}

	infile.close();
}
