#ifndef GLOBAL_H
#define GLOBAL_H
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include <time.h>
#include "resource.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


//Ӣ����
class Hero {
public:
	Hero();
	void CreateHero(long, long, long, long, HBITMAP, int, int, int);
	int& getHeroRunState();
	long& getHeroPos(bool);
	long& getHeroSize(bool);
	long& getHeroVel(bool);
	long& getHeroAcceration(bool);
	HBITMAP getHerohBmp();
	int& getHeroLife();
	int& getHeroLifeDecrease();
	int& getHeroWalkTerrian();
	int& getHeroTimes();
	int& getHeroWeapon();
	bool& getHeroMotionState();
	int& getLifeDecreaseTime();
	void team1Restart();
	void team2Restart();
private:
	HBITMAP	hBmp;	//Ӣ��ͼƬ
	POINT	pos;	//Ӣ��λ��
	POINT   vel;
	SIZE	size;
	float   mass;	//Ӣ������
	POINT   acceleration;  //Ӣ�ۼ��ٶ� (��Ӣ������һ������ʾ��)
	int     curFrameIndex;
	int     maxFrameSize;
	int RunState;				//Ӣ���˶�״̬ -1/1 -2/2��ʾ����ֹ���˶� ���Ҿ�ֹ �˶�
	int HeroLife;				//Ѫ��ֵ
	int HeroLifeDecrease;		//Ѫ�������� ������ʾ
	int HeroWalkTerrian;		//���µĵؿ���
	int HeroTimes;				//Ӣ��ʱ��֡
	int weapon;					//��ǰ���� 0/1/2/4		���� ��� ������ ��Ͷ
	bool motionState;			//0��ʾ�����ƣ�1��ʾû�б�����
	int LifeDecreaseTime;		//Ѫ��������ʾʱ��
};

//������
class ShouLei {
public:
	ShouLei();
	void CreateShouLei(HBITMAP, long, long);
	long& getShouLeiPos(bool);
	long& getShouLeiV(bool);
	long& getShouLeiSize(bool);
	long& getShouLeiA(bool);
	HBITMAP getShouLeiHsl();
	int& getShouLeiState();
	int& getShouLeiState1();
	int& getShouLeiExplodePct();
	int& getShouLeiWait();
private:
	HBITMAP hsl;  //����ͼƬ
	POINT   pos;
	POINT   vel;
	SIZE    size;
	POINT   acceleration;
	int shouLeiState; //0/1/2/3/4 ���� ��ȥ ��ը״̬ ͼƬ��ʾ��� ��ը�ȴ�	
	int shouLeiState1;//0/1/2/3 ��̬ ����˺� ��� ���׳��ٶ�
	int shouLeiExplodePct;		//���ױ�ըʱ��֡
	int shouLeiWait;			//���ױ�ը�ȴ�ʱ��
};

//�����
class Rocket {
public:
	Rocket();
	long& getRocketPos(bool);
	long& getRocketV(bool);
	long& getRocketA(bool);
	long& getRocketSize(bool);
	HBITMAP getRockethBmp();
	void CreateRocket(HBITMAP, long, long);
	int& getBoomState();
	int& getBoomState1();
	int& getRocketState();
	int& getRocketState1();
private:
	HBITMAP hBmp;
	POINT   pos;
	POINT   vel;
	SIZE    size;
	POINT   acceleration;
	int boomState;					//��״̬	ͬ����
	int boomState1;
	int rocketState;				//���״̬ ͬ����
	int rocketState1;
};

class RocketExplode {
public:
	RocketExplode();
	long& getRocketExplodePos(bool);
	long& getRocketExplodeSize(bool);
	HBITMAP& getRocketExplodehBmp();
private:
	HBITMAP hBmp;
	POINT pos;
	SIZE  size;
};

class ShouLeiExplode {
public:
	ShouLeiExplode();
	long& getShouLeiExplodePos(bool);
	long& getShouLeiExplodeSize(bool);
	HBITMAP& getShouLeiExplodehBmp();
private:
	HBITMAP hBmp;//���ױ�ըͼƬ
	POINT pos;
	SIZE  size;
};

//׼����
class ZhunXin {
public:
	ZhunXin();
	long& getZhunXinPos(bool);
	long& getZhunXinV(bool);
	long& getZhunXinSize(bool);
	HBITMAP getZhunXinhBmp();
	float& getZhunXinJiaoDu();
	int& getZhunXinR();
	float& getZhunXinW();
	void CreateZhunXin(HBITMAP, int, long, long, int);
	int& getZhunXinState();
private:
	int r;
	HBITMAP hzx;
	POINT   pos;
	POINT  vel;
	SIZE    size;
	float   jiaodu;//˳ʱ��+����ʱ��-
	float   w;		//���ٶ�
	int ZhunXinState;//0/1 ��ȥ����
};

//ָ���ͷ��
class JianTou {
public:
	JianTou();
	long& getJianTouPos(bool is);
	long& getJianTouV(bool is);
	long& getJianTouA(bool is);
	long& getJianTouSize(bool is);
	void CreateJianTou(HBITMAP, long, long);
	HBITMAP& getJianTouhBmp();
private:
	HBITMAP hjiantou;
	POINT pos;
	POINT vel;
	POINT acceleration;
	SIZE  size;
};

//��������
class FORCE {
public:
	FORCE();
	float& getLine();
	int& getForceState();
	int& getForceInterval();
private:
	float line;								//������
	int forcestate;							//����������״̬
	int forceInterval;						//����ʱ��
};

//������
class Terrian {
public:
	Terrian();
	long& getPos1(bool);
	long& getPos2(bool);
	void CreateTerrian(long, long, long, long, HBITMAP);
private:
	HBITMAP hBmp;
	POINT	pos1;//�������	
	POINT   pos2;//�յ�����
};

//������
class GameButton {
public:
	GameButton();
	long& getPos(bool);
	long& getSize(bool);
	void CreateGameButton(long, long, long, long, HBITMAP, int);
	POINT& getpos();
	SIZE& getsize();
private:
	HBITMAP	hBmp;	//��ťͼƬ
	POINT   pos;	//��ťλ��
	SIZE	size;	//��ť�ߴ�
	int	status;	//��ť״̬
};

//��Ϸ״̬��
class GameStatus {
public:
	GameStatus();
	int& getGameStatus();
	int& getHeroSide();
	HBITMAP& getGameStatushBmp();
	int& getHeroOrder1();
	int& getHeroOrder2();
	int& getTimePast();
	int& getRoundState();
	int& getRoundTime();
	int& getJianTouDelay();
	int& getGameStatusJustNow();
	int& getSkip();
	bool& getThrowState();
	int& getThrowTimes();
	int& getRoundCount();
	int& getAllover();
	bool& getPaintAgain();
	bool& getLaunchState();
	int& getLaunchTimes();
	bool& getRestartState();
	bool& getRoundStart1();
	bool& getRoundStart2();
	bool& getGameStart();
	bool& getGameEnd();
	int& getEndLeft();
	int& getEndRight();
	int& getEndTop();
	int& getEndBottom();
	int& getTerrianState(int, int);
	int& getTerrianSecond(int);
	int& getWdTimes();
	int& getWindInterval();
	int& getWindVel();
	int& getFoodTimes();
	int& getJump();
	int& getPlaneState();
	int& getWeapon4Use();
	int& getWeapon4Side();
	int& getWeapon4Num();
	int& getWeapon4State();
	int& getTarget();
	int& getBoomPct();
	bool& getLimitState();
	void GameStatusRestart();
private:
	HBITMAP	hBmp;	//����ͼƬ
	int	status;	//������Ϸ״̬ 0��ҳ 2/3/4/5 ���ŵ�ͼ 1����ģʽҳ 7��һ����ͼ�µ�pause 9��սģʽҳ�� 6��ҳ��help 8help�ڵ�next����
	int statusJustNow;//��Ϸ�ոյ�״̬
	int HeroSide;
	int HeroOrder1;			//����Ӣ��ѭ��
	int HeroOrder2;			//�з�Ӣ��ѭ��
	int TimePast;			//��ȥʱ��
	int roundstate;			//�غ�״̬ 0/1/2 �غ��� ������ �Ѿ�����
	int roundtime;			//�غϼ�ʱ
	int JianTouDelay;		//��ͷ��ֱ����ƫ����
	int skip;				//�Ƿ������غ�
	bool throwState;			//�Ƿ���	0/1 �����ƻ���
	int throwTimes;			//�����׵�ʱ��֡
	int roundCount;			//�غ�����
	int allOver;			//�غ��Ƿ����
	bool paintAgain;		//0/1 ���ػ� �ػ�
	bool launchState;		//ͬ����
	int launchTimes;		//
	bool restartState;		//�����ж�
	bool roundstart1;
	bool roundstart2;	//roundstart1==0��ʾ��ʼ roundstart==1��ʾ�غ��� �жϼ�ͷ��ʾ
	bool gameStart;		//�жϻغϿ�ʼ	
	bool gameEnd;		//�жϻغϽ���
	int endleft;		//��ͼ�ĸ���������
	int endright;
	int endtop;
	int endbottom;
	int terrianState[1920][6];		//�ؿ�״̬ 1/0/-1 ���� δ��ʼ�� �ҽ�
	int terrianSecond[1920];		//ÿ��x�ϵĵؿ����
	int wdTimes;		//�����ǿͼƬ֡
	int windInterval;	//����¼��
	int windVel;		//���� �缶 0/1/2/3
	int foodtimes;		//ʳ��ʱ����
	int jump;
	//���İ�������Ϯ��ر���
	int planeState;		//��Ϯ����״̬
	int weapon4Use;		//�Ƿ���
	int weapon4Side;	//��һ��
	int weapon4Num;		//һ���е���һ�� 
	int weapon4State;	//������״̬
	int boomPct;		//��Ϯ���׵�ʱ��֡
	int target;			//��ϮĿ��
	bool limitstate;		//��ͼ����
};

//���ֺ�BGM����
class PictureBGM {
public:
	PictureBGM();
	bool& getSceneBGM(int);
	bool& getMenuBGM();
	bool& getEndPage();
	int& getEndPagePicture();
	int& getRocketExplodePct();
	bool& getSoundStart();
	bool& getHurtSoundState();
	bool& getExplodeSoundState();
private:
	bool scenebgm[5];			//�ĸ�����BGM
	bool menubgm;
	bool endpage;				//��Ϸ���������Ƿ��Ѿ�����
	int endPagePicture;			//��Ϸ���endingѡȡ
	int rocketExplodePct;		//�����ըͼƬʱ��֡
	bool soundStart;			//����������������ж�
	bool hurtSoundState;		//�����˺�����
	bool explodeSoundState;		//��ը��Ч
};

//��Ʒ��
class Item {			//�硢ʳ�ľ���Ϯ
public:
	Item();
	long& getPos(bool);
	int& getFoodPicture();
	int& getFoodState();
	int& getCrateState();
	int& getCrateTimes();
private:
	POINT pos;
	int foodPicture;		//�洢ʳ���ͼƬ
	int foodState;			//0/1 ������ ����
	int crateState;			//ͬʳ��״̬
	int crateTimes;
};

//��������
class TransmitGate {
public:
	TransmitGate();
	int& getTranState();
	int& getTranTimes();
private:
	int transtate;		//0/1/2������û�� ��ʼ���� ������
	int trantimes;
};

//�������
class CAMERA {
public:
	CAMERA();
	long& getCamera1Pos(bool);
	long& getCameraPos(bool);
	float& getPro();
	bool& getControl();		//���������״̬
private:
	POINT camera;//��������������λ��
	POINT camera1;
	bool cameracontrol;
	float proportion;//��Ļ���ű���

};

//AI��
class Ai {
public:
	Ai();
	int& getAIstart();
	int& getAIstate();
	int& getAIattack();
	int& getWeaponR();
	int& getTeam1R();
	int& getPos(bool);
	float& getAngler();
	float& getVshould();
	float& getForceShould();
	int& getAIdirection();
	int& getAImoveState();
	int& getAImove();
	int& getAIcount();
	int& getAIzhunxinState();
	void AIrestart();
private:
	int AIstart;							//AI�Ƿ�ʼ
	int AIstate;							//״̬
	int AIattack;							//����
	int weaponr;							//��������뾶
	int team1r;
	int X, Y;
	float angler;						//��������Ƕ�
	float vshould;
	float forceshould;
	int AIdirection;
	int AImovestate;					//�����ƶ�״̬
	int AImove;
	int AIcount;						//AIʱ��֡
	int AIzhunxinstate;					//����׼��״̬
};
#endif
