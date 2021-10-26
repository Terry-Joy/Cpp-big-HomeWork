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


//英雄类
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
	HBITMAP	hBmp;	//英雄图片
	POINT	pos;	//英雄位置
	POINT   vel;
	SIZE	size;
	float   mass;	//英雄质量
	POINT   acceleration;  //英雄加速度 (和英雄质量一起来表示力)
	int     curFrameIndex;
	int     maxFrameSize;
	int RunState;				//英雄运动状态 -1/1 -2/2表示向左静止，运动 向右静止 运动
	int HeroLife;				//血量值
	int HeroLifeDecrease;		//血量减少量 用于显示
	int HeroWalkTerrian;		//脚下的地块名
	int HeroTimes;				//英雄时间帧
	int weapon;					//当前武器 0/1/2/4		手雷 火箭 传送门 空投
	bool motionState;			//0表示被控制，1表示没有被控制
	int LifeDecreaseTime;		//血量减少显示时间
};

//手雷类
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
	HBITMAP hsl;  //手雷图片
	POINT   pos;
	POINT   vel;
	SIZE    size;
	POINT   acceleration;
	int shouLeiState; //0/1/2/3/4 绘制 隐去 爆炸状态 图片显示完成 爆炸等待	
	int shouLeiState1;//0/1/2/3 初态 造成伤害 震飞 手雷初速度
	int shouLeiExplodePct;		//手雷爆炸时间帧
	int shouLeiWait;			//手雷爆炸等待时间
};

//火箭类
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
	int boomState;					//榴弹状态	同手雷
	int boomState1;
	int rocketState;				//火箭状态 同手雷
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
	HBITMAP hBmp;//手雷爆炸图片
	POINT pos;
	SIZE  size;
};

//准心类
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
	float   jiaodu;//顺时针+；逆时针-
	float   w;		//角速度
	int ZhunXinState;//0/1 隐去绘制
};

//指向箭头类
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

//力度条类
class FORCE {
public:
	FORCE();
	float& getLine();
	int& getForceState();
	int& getForceInterval();
private:
	float line;								//力度线
	int forcestate;							//力度条显现状态
	int forceInterval;						//蓄力时间
};

//地形类
class Terrian {
public:
	Terrian();
	long& getPos1(bool);
	long& getPos2(bool);
	void CreateTerrian(long, long, long, long, HBITMAP);
private:
	HBITMAP hBmp;
	POINT	pos1;//起点坐标	
	POINT   pos2;//终点坐标
};

//按键类
class GameButton {
public:
	GameButton();
	long& getPos(bool);
	long& getSize(bool);
	void CreateGameButton(long, long, long, long, HBITMAP, int);
	POINT& getpos();
	SIZE& getsize();
private:
	HBITMAP	hBmp;	//按钮图片
	POINT   pos;	//按钮位置
	SIZE	size;	//按钮尺寸
	int	status;	//按钮状态
};

//游戏状态类
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
	HBITMAP	hBmp;	//背景图片
	int	status;	//各种游戏状态 0首页 2/3/4/5 四张地图 1单人模式页 7第一幅地图下的pause 9对战模式页面 6首页的help 8help内的next界面
	int statusJustNow;//游戏刚刚的状态
	int HeroSide;
	int HeroOrder1;			//己方英雄循环
	int HeroOrder2;			//敌方英雄循环
	int TimePast;			//过去时间
	int roundstate;			//回合状态 0/1/2 回合中 结束中 已经结束
	int roundtime;			//回合计时
	int JianTouDelay;		//箭头竖直方向偏移量
	int skip;				//是否跳过回合
	bool throwState;			//是否扔	0/1 不绘制绘制
	int throwTimes;			//扔手雷的时间帧
	int roundCount;			//回合轮数
	int allOver;			//回合是否结束
	bool paintAgain;		//0/1 不重绘 重绘
	bool launchState;		//同手雷
	int launchTimes;		//
	bool restartState;		//重置判断
	bool roundstart1;
	bool roundstart2;	//roundstart1==0表示开始 roundstart==1表示回合中 判断箭头显示
	bool gameStart;		//判断回合开始	
	bool gameEnd;		//判断回合结束
	int endleft;		//地图四个方向限制
	int endright;
	int endtop;
	int endbottom;
	int terrianState[1920][6];		//地块状态 1/0/-1 土地 未初始化 岩浆
	int terrianSecond[1920];		//每个x上的地块个数
	int wdTimes;		//风向风强图片帧
	int windInterval;	//风更新间隔
	int windVel;		//风速 风级 0/1/2/3
	int foodtimes;		//食物时间间隔
	int jump;
	//第四把武器空袭相关变量
	int planeState;		//空袭发射状态
	int weapon4Use;		//是否有
	int weapon4Side;	//哪一边
	int weapon4Num;		//一边中的哪一个 
	int weapon4State;	//所处的状态
	int boomPct;		//空袭手雷的时间帧
	int target;			//空袭目标
	bool limitstate;		//地图限制
};

//音乐和BGM控制
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
	bool scenebgm[5];			//四个背景BGM
	bool menubgm;
	bool endpage;				//游戏结束画面是否已经绘制
	int endPagePicture;			//游戏随机ending选取
	int rocketExplodePct;		//火箭爆炸图片时间帧
	bool soundStart;			//所以声音更新与否判断
	bool hurtSoundState;		//人物伤害声音
	bool explodeSoundState;		//爆炸音效
};

//物品类
class Item {			//风、食物、木箱空袭
public:
	Item();
	long& getPos(bool);
	int& getFoodPicture();
	int& getFoodState();
	int& getCrateState();
	int& getCrateTimes();
private:
	POINT pos;
	int foodPicture;		//存储食物的图片
	int foodState;			//0/1 不绘制 绘制
	int crateState;			//同食物状态
	int crateTimes;
};

//传送门类
class TransmitGate {
public:
	TransmitGate();
	int& getTranState();
	int& getTranTimes();
private:
	int transtate;		//0/1/2传送门没用 开始传送 用完了
	int trantimes;
};

//照相机类
class CAMERA {
public:
	CAMERA();
	long& getCamera1Pos(bool);
	long& getCameraPos(bool);
	float& getPro();
	bool& getControl();		//照相机操纵状态
private:
	POINT camera;//摄像机，绘制起点位置
	POINT camera1;
	bool cameracontrol;
	float proportion;//屏幕缩放比例

};

//AI类
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
	int AIstart;							//AI是否开始
	int AIstate;							//状态
	int AIattack;							//攻击
	int weaponr;							//武器随机半径
	int team1r;
	int X, Y;
	float angler;						//力度随机角度
	float vshould;
	float forceshould;
	int AIdirection;
	int AImovestate;					//人物移动状态
	int AImove;
	int AIcount;						//AI时间帧
	int AIzhunxinstate;					//人物准心状态
};
#endif
