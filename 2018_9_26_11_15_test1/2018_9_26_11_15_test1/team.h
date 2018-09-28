#pragma once

//�����Ϣ��¼�ṹ
struct TeamInfor
{
	char nameTeam[20];  //�������
	int numWin;  //ʤ�ĳ���
	int numFlat;  //ƽ�ĳ���
	int numNegative;  //���ĳ���
	int numGoal;  //��ʤ��
	int integral;  //���� -- ��������/���ְ�����
};

const int NTEAM = 32;  //һ��32������

//������Ϣ������
class TeamInforManage
{
private:
	//������Ϣ������ݳ�Ա
	TeamInfor team[NTEAM];  //������Ϣ�ṹ����
	int teamCount;  //���ļ��ж���������Ŀ - ����test
public:
	//��������
	void Display(const TeamInfor &teamInfor);  //��ʾ��¼
	void DisplayALL();  //��ʾ������Ӽ�¼
	void LeagueTable();  //���ݶ���������ɻ��ְ���ʾ - С������
	void SwapTeamInfor(TeamInfor &a, TeamInfor &b);  //�������������������е�λ��
	//���к���
	TeamInforManage();  //�޲ι��캯��
//	virtual ~TeamInforManage();  //��������
};