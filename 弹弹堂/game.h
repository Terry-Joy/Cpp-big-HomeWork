#ifndef EVENT_H
#define EVENT_H

#include <Windows.h>


// 窗体过程函数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// 初始化
void Init(HWND hWnd, WPARAM wParam, LPARAM lParam);
//双缓冲绘制
void Render(HWND hWnd);
void Render_Start(HWND hWnd);//绘制游戏开始界面
void Render_Game(HWND hWnd);//绘制游戏界面
//定时器
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
//hero更新
void HeroUpdate();
//地形更新
void TerrianUpdate();
//准心更新
void ZhunXinUpdate();
//手雷更新
void ShouLeiUpdate();
void RocketUpdate();
//回合更新
void RoundUpdate();
//判断是否点击按钮
bool ButtonClicked(POINT, RECT);
//键盘按下处理
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
//键盘松开处理
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
//左鼠标点击
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
//生成土地函数
void CreateMap1(int posleft, int posright, int postop, int posbottom, int maxR, int maxC, int range, int start, int num);//maxR表示圆的最大半径，maxC表示圆的个数.range表示随机圆的范围,num表示terrian第二个数,start表示地块开始
void CreateMap3(int posleft, int posright, int postop, int posbottom, int maxR, int maxC, int range, int start, int num);//有底
//生成岩浆函数
void CreateMap2(int posleft, int posright, int postop, int posdown);
//音频更新
void SoundUpdate();
//按键下——力度对应函数
void Forcevkrightdown();
void Forcevkleftdown();
void Adown();
void Ddown();
void Spacedown();
//按键上——力度对应函数
void Forcevkrightup();
void Forcevkleftup();
void Aup();
void Dup();
//手雷碰撞函数
void ShouLeiCrush();
void RocketCrush();
//手雷伤害函数
void ShouLeiDamage();
void RocketDamage();
//人物坠落碰撞函数
void HeroCrush();
//箭头更新函数
void JianTouUpdate();
//手雷爆炸图片更新函数
void ShouLeiExplodeUpdate();
void RocketExplodeUpdate();
//手雷爆炸震飞效果
void ShouLeiMove();
void RocketMove();
//人物阻力
void HeroFriction();
//动作状态更新
void HeroMotionUpdate();
//回合结束清算函数
void RoundEnd();
//血量减少控制
void BloodDecrease();
//camara控制
void Camera();
void WindUpdate();
void FoodUpdate();
void TransUpdate();
void Restart();
void PlaneUpdate();
void BoomCrush();
void BoomUpdate();
void CrateUpdate();
void AI();

void limit();
#endif // !EVENT_H