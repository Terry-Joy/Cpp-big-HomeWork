#include "global.h"

Hero::Hero() {
	HeroLife = 100;
	HeroLifeDecrease = 100;
	weapon = 0;
}

Terrian::Terrian() {

}

ShouLei::ShouLei() {
	shouLeiState = shouLeiState1 = 1;
	shouLeiExplodePct = 0;
	shouLeiWait = 0;
}

void Hero::CreateHero(long posX, long posY, long sizeX, long sizeY, HBITMAP hbmp, int curFrame, int maxFrame, int times) {
	hBmp = hbmp;
	pos.x = posX; pos.y = posY;
	vel.x = vel.y = 0;
	size.cx = sizeX;
	size.cy = sizeY;
	curFrameIndex = curFrame;
	maxFrameSize = maxFrame;
	RunState = -1;
	HeroTimes = times;
}

void Hero::team1Restart() {
	HeroLife = HeroLifeDecrease = 100;
	HeroTimes = 1;
	LifeDecreaseTime = weapon = HeroWalkTerrian = motionState = 0;
	RunState = -1;
}

void Hero::team2Restart() {
	HeroLife = HeroLifeDecrease = 100;
	HeroTimes = 4;
	LifeDecreaseTime = weapon = HeroWalkTerrian = motionState = 0;
	RunState = -2;
}

bool& Hero::getHeroMotionState() {
	return motionState;
}

int& Hero::getHeroWeapon() {
	return weapon;
}

int& Hero::getLifeDecreaseTime() {
	return LifeDecreaseTime;
}

int& Hero::getHeroTimes() {
	return HeroTimes;
}

int& Hero::getHeroWalkTerrian() {
	return HeroWalkTerrian;
}

int& Hero::getHeroLife() {
	return HeroLife;
}

int& Hero::getHeroLifeDecrease() {
	return HeroLifeDecrease;
}

int& Hero::getHeroRunState() {
	return RunState;
}

long& Hero::getHeroPos(bool is) {
	return is ? pos.x : pos.y;
}

long& Hero::getHeroSize(bool is) {
	return is ? size.cx : size.cy;
}

long& Hero::getHeroVel(bool is) {
	return is ? vel.x : vel.y;
}

long& Hero::getHeroAcceration(bool is) {
	return is ? acceleration.x : acceleration.y;
}

HBITMAP Hero::getHerohBmp() {
	return hBmp;
}

long& Terrian::getPos1(bool is) {
	return is ? pos1.x : pos1.y;
}

long& Terrian::getPos2(bool is) {
	return is ? pos2.x : pos2.y;
}

void Terrian::CreateTerrian(long posX1, long posY1, long pos2X, long pos2Y, HBITMAP hbmp) {
	pos1.x = posX1;
	pos1.y = posY1;
	pos2.x = pos2X;
	pos2.y = pos2Y;
	hBmp = hbmp;
}

long& ShouLei::getShouLeiPos(bool is) {
	return is ? pos.x : pos.y;
}

long& ShouLei::getShouLeiV(bool is) {
	return is ? vel.x : vel.y;
}

int& ShouLei::getShouLeiState() {
	return shouLeiState;
}

int& ShouLei::getShouLeiState1() {
	return shouLeiState1;
}

int& ShouLei::getShouLeiWait() {
	return shouLeiWait;
}

int& ShouLei::getShouLeiExplodePct() {
	return shouLeiExplodePct;
}

void ShouLei::CreateShouLei(HBITMAP hbmp, long x1, long y1) {
	pos.x = x1;
	pos.y = y1;
	hsl = hbmp;
	size.cx = 10;
	size.cy = 10;
	vel.x = vel.y = 0;
	acceleration.x = acceleration.y = 0;
}

long& ShouLei::getShouLeiSize(bool is) {
	return is ? size.cx : size.cy;
}

long& ShouLei::getShouLeiA(bool is) {
	return is ? acceleration.x : acceleration.y;
}

HBITMAP ShouLei::getShouLeiHsl() {
	return hsl;
}

Rocket::Rocket() {
	boomState = boomState1 = 1;
	rocketState = rocketState1 = 1;
}

int& Rocket::getRocketState1() {
	return rocketState1;
}

int& Rocket::getRocketState() {
	return rocketState;
}

int& Rocket::getBoomState() {
	return boomState;
}

int& Rocket::getBoomState1() {
	return boomState1;
}

long& Rocket::getRocketPos(bool is) {
	return is ? pos.x : pos.y;
}

long& Rocket::getRocketV(bool is) {
	return is ? vel.x : vel.y;
}

long& Rocket::getRocketA(bool is) {
	return is ? acceleration.x : acceleration.y;
}

long& Rocket::getRocketSize(bool is) {
	return is ? size.cx : size.cy;
}

HBITMAP Rocket::getRockethBmp() {
	return hBmp;
}

void Rocket::CreateRocket(HBITMAP hbmp, long x1, long y1) {
	pos.x = x1;
	pos.y = y1;
	size.cx = 12;
	size.cy = 3;
	vel.x = vel.y = 0;
	acceleration.x = acceleration.y = 0;
	hBmp = hbmp;
}

RocketExplode::RocketExplode() {

}

long& RocketExplode::getRocketExplodePos(bool is) {
	return is ? pos.x : pos.y;
}

HBITMAP& RocketExplode::getRocketExplodehBmp() {
	return hBmp;
}

long& RocketExplode::getRocketExplodeSize(bool is) {
	return is ? size.cx : size.cy;
}

ShouLeiExplode::ShouLeiExplode() {

}

long& ShouLeiExplode::getShouLeiExplodePos(bool is) {
	return is ? pos.x : pos.y;
}

long& ShouLeiExplode::getShouLeiExplodeSize(bool is) {
	return is ? size.cx : size.cy;
}

HBITMAP& ShouLeiExplode::getShouLeiExplodehBmp() {
	return hBmp;
}

JianTou::JianTou() {

}


long& JianTou::getJianTouPos(bool is) {
	return is ? pos.x : pos.y;
}

long& JianTou::getJianTouV(bool is) {
	return is ? vel.x : vel.y;
}

long& JianTou::getJianTouA(bool is) {
	return is ? acceleration.x : acceleration.y;
}

HBITMAP& JianTou::getJianTouhBmp() {
	return hjiantou;
}

long& JianTou::getJianTouSize(bool is) {
	return is ? size.cx : size.cy;
}

void JianTou::CreateJianTou(HBITMAP hBmp, long x1, long y1) {
	hjiantou = hBmp;
	pos.x = x1;
	pos.y = y1;
	vel.x = vel.y = acceleration.x = acceleration.y = 0;
	size.cx = 30;
	size.cy = 30;
}

ZhunXin::ZhunXin() {
	ZhunXinState = 0;
}

int& ZhunXin::getZhunXinState() {
	return ZhunXinState;
}

long& ZhunXin::getZhunXinPos(bool is) {
	return is ? pos.x : pos.y;
}

long& ZhunXin::getZhunXinV(bool is) {
	return is ? vel.x : vel.y;
}

long& ZhunXin::getZhunXinSize(bool is) {
	return is ? size.cx : size.cy;
}

HBITMAP ZhunXin::getZhunXinhBmp() {
	return hzx;
}

float& ZhunXin::getZhunXinJiaoDu() {
	return jiaodu;
}

int& ZhunXin::getZhunXinR() {
	return r;
}

float& ZhunXin::getZhunXinW() {
	return w;
}

void ZhunXin::CreateZhunXin(HBITMAP hBmp, int r1, long x1, long y1, int flag) {
	hzx = hBmp;
	if (flag == -1)
		pos.x = x1 - r1;
	if (flag == -2)
		pos.x = x1 + r1;
	vel.x = vel.y = jiaodu = w = 0;
	r = r1;
	size.cx = size.cy = 30;
	pos.y = y1;
}

FORCE::FORCE() {
	forcestate = 0;
	forceInterval = 1;
}

float& FORCE::getLine() {
	return line;
}

int& FORCE::getForceState() {
	return forcestate;
}

int& FORCE::getForceInterval() {
	return forceInterval;
}

GameStatus::GameStatus() {
	HeroSide = 0;
	roundstate = 0;
	statusJustNow = 0;
	skip = 0;
	throwState = throwTimes = 0;
	roundCount = 0;
	allOver = 0;
	paintAgain = 0;
	launchState = launchTimes = 0;
	roundstart1 = 0;
	roundstart2 = 1;
	gameStart = gameEnd = 0;
	endleft = 0; endright = 1920; endtop = 900; endbottom = 1080;
	memset(terrianState, 0, sizeof(terrianState));
	memset(terrianSecond, 0, sizeof(terrianSecond));
	wdTimes = windVel = 0;
	windInterval = 1000;
	jump = 20;
	planeState = 0;
	weapon4Use = weapon4State = 0; weapon4Side = weapon4Num = -1;
	boomPct = 0;
	target = -1;
	limitstate = 0;
}

void GameStatus::GameStatusRestart() {
	jump = 20;
	roundtime = roundstate = 0;
	HeroOrder1 = HeroOrder2 = HeroSide = 0;
	TimePast = skip = 0;
	roundstart1 = 0; roundstart2 = 1;
	throwState = throwTimes = 0;
	wdTimes = 1000; windInterval = windVel = 0;
	gameStart = gameEnd = 0;
	launchState = launchTimes = 0;
	endleft = 0; endright = 1920; endtop = 900; endbottom = 1080;
	roundCount = allOver = 0;
	planeState = 0;
	weapon4Use = weapon4State = 0; weapon4Side = weapon4Num = -1;
	target = -1;
	boomPct = 0;
	limitstate = 0;
}

int& GameStatus::getWeapon4Num() {
	return weapon4Num;
}

int& GameStatus::getWeapon4Side() {
	return weapon4Side;
}

int& GameStatus::getWeapon4State() {
	return weapon4State;
}

int& GameStatus::getBoomPct() {
	return boomPct;
}

int& GameStatus::getTarget() {
	return target;
}

int& GameStatus::getWeapon4Use() {
	return weapon4Use;
}

int& GameStatus::getPlaneState() {
	return planeState;
}

int& GameStatus::getJump() {
	return jump;
}

bool& GameStatus::getLimitState() {
	return limitstate;
}

int& GameStatus::getEndLeft() {
	return endleft;
}

int& GameStatus::getFoodTimes() {
	return foodtimes;
}

int& GameStatus::getEndRight() {
	return endright;
}

int& GameStatus::getTerrianState(int i, int j) {
	return terrianState[i][j];
}

int& GameStatus::getWindVel() {
	return windVel;
}

int& GameStatus::getTerrianSecond(int i) {
	return terrianSecond[i];
}

int& GameStatus::getEndTop() {
	return endtop;
}

int& GameStatus::getEndBottom() {
	return endbottom;
}


bool& GameStatus::getPaintAgain() {
	return paintAgain;
}

bool& GameStatus::getGameEnd() {
	return gameEnd;
}

bool& GameStatus::getLaunchState() {
	return launchState;
}

int& GameStatus::getLaunchTimes() {
	return launchTimes;
}

bool& GameStatus::getThrowState() {
	return throwState;
}

int& GameStatus::getThrowTimes() {
	return throwTimes;
}

int& GameStatus::getSkip() {
	return skip;
}

bool& GameStatus::getGameStart() {
	return gameStart;
}

int& GameStatus::getGameStatusJustNow() {
	return statusJustNow;
}

int& GameStatus::getJianTouDelay() {
	return JianTouDelay;
}

int& GameStatus::getRoundState() {
	return roundstate;
}

int& GameStatus::getRoundTime() {
	return roundtime;
}

int& GameStatus::getHeroOrder1() {
	return HeroOrder1;
}

int& GameStatus::getHeroOrder2() {
	return HeroOrder2;
}

int& GameStatus::getTimePast() {
	return TimePast;
}

int& GameStatus::getGameStatus() {
	return status;
}

HBITMAP& GameStatus::getGameStatushBmp() {
	return hBmp;
}

int& GameStatus::getHeroSide() {
	return HeroSide;
}

int& GameStatus::getRoundCount() {
	return roundCount;
}

int& GameStatus::getWdTimes() {
	return wdTimes;
}

int& GameStatus::getWindInterval() {
	return windInterval;
}
int& GameStatus::getAllover() {
	return allOver;
}

bool& GameStatus::getRestartState() {
	return restartState;
}

bool& GameStatus::getRoundStart1() {
	return roundstart1;
}

bool& GameStatus::getRoundStart2() {
	return roundstart2;
}

int& Item::getFoodPicture() {
	return foodPicture;
}

int& Item::getFoodState() {
	return foodState;
}

PictureBGM::PictureBGM() {
	memset(scenebgm, 0, sizeof(scenebgm));
	menubgm = 0;
	endpage = endPagePicture = 0;
	rocketExplodePct = 0;
	soundStart = 0;
	hurtSoundState = explodeSoundState = 0;
}

bool& PictureBGM::getHurtSoundState() {
	return hurtSoundState;
}

bool& PictureBGM::getExplodeSoundState() {
	return explodeSoundState;
}

bool& PictureBGM::getSoundStart() {
	return soundStart;
}

bool& PictureBGM::getSceneBGM(int i) {
	return scenebgm[i];
}

bool& PictureBGM::getMenuBGM() {
	return menubgm;
}

bool& PictureBGM::getEndPage() {
	return endpage;
}

int& PictureBGM::getEndPagePicture() {
	return endPagePicture;
}

int& PictureBGM::getRocketExplodePct() {
	return rocketExplodePct;
}

Item::Item() {
	crateState = crateTimes = 0;
}

long& Item::getPos(bool is) {
	return is ? pos.x : pos.y;
}

int& Item::getCrateState() {
	return crateState;
}

int& Item::getCrateTimes() {
	return crateTimes;
}

TransmitGate::TransmitGate() {
	transtate = trantimes = 0;
}

int& TransmitGate::getTranState() {
	return transtate;
}

int& TransmitGate::getTranTimes() {
	return trantimes;
}

CAMERA::CAMERA() {
	cameracontrol = 0;
	proportion = 1;
}

long& CAMERA::getCamera1Pos(bool is) {
	return is ? camera1.x : camera1.y;
}

long& CAMERA::getCameraPos(bool is) {
	return is ? camera.x : camera.y;
}

float& CAMERA::getPro() {
	return proportion;
}

bool& CAMERA::getControl() {
	return cameracontrol;
}

Ai::Ai() {
	AIstart = 0;
	AIstate = -1;
	AIattack = 0;
	weaponr = team1r = X = Y = 0;
	angler = vshould = forceshould = 0;
	AIdirection = -1;
	AImovestate = AImove = AIcount = AIzhunxinstate = 0;
}

void Ai::AIrestart() {
	AIdirection = -1;
	AIstart = AIattack = weaponr = team1r = X = Y = 0;
	angler = vshould = forceshould = 0;
	AImovestate = AIcount = AIzhunxinstate = 0;
}

int& Ai::getAIattack() {
	return AIattack;
}

int& Ai::getAIcount() {
	return AIcount;
}

int& Ai::getAIdirection() {
	return AIdirection;
}

int& Ai::getAImove() {
	return AImove;
}

int& Ai::getAImoveState() {
	return AImovestate;
}

int& Ai::getAIstart() {
	return AIstart;
}

int& Ai::getAIstate() {
	return AIstate;
}

int& Ai::getAIzhunxinState() {
	return AIzhunxinstate;
}

float& Ai::getAngler() {
	return angler;
}

float& Ai::getForceShould() {
	return forceshould;
}

int& Ai::getTeam1R() {
	return team1r;
}

float& Ai::getVshould() {
	return vshould;
}

int& Ai::getWeaponR() {
	return weaponr;
}

int& Ai::getPos(bool is) {
	return is ? X : Y;
}

GameButton::GameButton() {

}

long& GameButton::getPos(bool is) {
	return is ? pos.x : pos.y;
}

long& GameButton::getSize(bool is) {
	return is ? size.cx : size.cy;
}

POINT& GameButton::getpos() {
	return pos;
}

SIZE& GameButton::getsize() {
	return size;
}

void GameButton::CreateGameButton(long posX, long posY, long sizeX, long sizeY, HBITMAP hbmp, int statu) {
	pos.x = posX;
	pos.y = posY;
	size.cx = sizeX;
	size.cy = sizeY;
	hBmp = hbmp;
	status = statu;
}
