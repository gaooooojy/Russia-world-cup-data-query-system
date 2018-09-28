#include "pch.h"
#include "team.h"

void TeamInforManage::Display(const TeamInfor & teamInfor)
//�����������ʾָ����Ӽ�¼
{
	cout << teamInfor.nameTeam << "\t\t" << teamInfor.numWin << "\t"
		<< teamInfor.numFlat << "\t" << teamInfor.numNegative << "\t"
		<< teamInfor.numGoal << "\t" << teamInfor.integral << endl;
}

void TeamInforManage::DisplayALL()
//�����������ʾ������Ӽ�¼
{
	cout << "�������" << "\t" << "ʤ" << "\t"
		<< "ƽ" << "\t" << "��" << "\t" << "��ʤ��" << "\t"
		<< "����" << endl;

	for (int i = 0; i < teamCount; ++i)
	{
		Display(team[i]);
	}
}

void TeamInforManage::LeagueTable()
//������������ݶ���������ɻ��ְ���ʾ - С������
{
	TeamInfor teamCopy[NTEAM];  //˽�г�Աteam�ṹ����Ŀ���
	//��team[NTEAM]�е����ݿ�����teamCopy[NTEAM]
	//���ṹ����ֶΣ�һ��8��С��
	//0~3,4~7, 8~11, 12~15, 16~19, 20~23, 24~27, 28~31

	//0~3
	for (int i = 0; i < 4; ++i)
	{
		strcpy(teamCopy[i].nameTeam, team[i].nameTeam);
		teamCopy[i].numWin = team[i].numWin;
		teamCopy[i].numFlat = team[i].numFlat;
		teamCopy[i].numNegative = team[i].numNegative;
		teamCopy[i].numGoal = team[i].numGoal;
		teamCopy[i].integral = team[i].integral;
	}

	//0~3����������
	for (int i = 0; i < 4-1; ++i)
	{
		for (int j = 0; j < 4 - i - 1; ++j)
		{
			if (teamCopy[j].integral < teamCopy[j + 1].integral) //�Ӵ�С
			{
				SwapTeamInfor(teamCopy[j], teamCopy[j + 1]);  //������������λ���������е���Ϣ
			}
		}
	}

	cout << "A������" << endl;
	for (int i = 0; i < 4; ++i)
	{
		Display(teamCopy[i]);
	}
}

void TeamInforManage::SwapTeamInfor(TeamInfor & a, TeamInfor & b)
//�������������������е�λ��
{
	TeamInfor temp;
	strcpy(temp.nameTeam, a.nameTeam);
	temp.numWin = a.numWin;
	temp.numFlat = a.numFlat;
	temp.numNegative = a.numNegative;
	temp.numGoal = a.numGoal;
	temp.integral = a.integral;

	strcpy(a.nameTeam, b.nameTeam);
	a.numWin = b.numWin;
	a.numFlat = b.numFlat;
	a.numNegative = b.numNegative;
	a.numGoal = b.numGoal;
	a.integral = b.integral;

	strcpy(b.nameTeam, temp.nameTeam);
	b.numWin = temp.numWin;
	b.numFlat = temp.numFlat;
	b.numNegative = temp.numNegative;
	b.numGoal = temp.numGoal;
	b.integral = temp.integral;
}

TeamInforManage::TeamInforManage() 
//�������:��ʼ�������Ϣ
{
	teamCount = 0;
	//������ļ��ж�ȡ���ݵ�Team�ṹ��������
	ifstream infile("F:\\VS2017\\2018_9_26_11_15_test1\\2018_9_26_11_15_test1\\teamRecord.txt", ios::in);  //������ķ�ʽ���ļ�

	if (!infile) //�����Ƿ�򿪳ɹ�
	{
		cerr << "open teamRecord.txt error" << endl;
		exit(1);
	}

	int i = 0;
	while (!infile.eof())
	{
		infile >> team[i].nameTeam >> team[i].numWin
			>> team[i].numFlat >> team[i].numNegative
			>> team[i].numGoal >> team[i].integral;

		++teamCount;
		++i;
	}

	infile.close();
}
