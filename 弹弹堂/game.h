#ifndef EVENT_H
#define EVENT_H

#include <Windows.h>


// ������̺���
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// ��ʼ��
void Init(HWND hWnd, WPARAM wParam, LPARAM lParam);
//˫�������
void Render(HWND hWnd);
void Render_Start(HWND hWnd);//������Ϸ��ʼ����
void Render_Game(HWND hWnd);//������Ϸ����
//��ʱ��
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
//hero����
void HeroUpdate();
//���θ���
void TerrianUpdate();
//׼�ĸ���
void ZhunXinUpdate();
//���׸���
void ShouLeiUpdate();
void RocketUpdate();
//�غϸ���
void RoundUpdate();
//�ж��Ƿ�����ť
bool ButtonClicked(POINT, RECT);
//���̰��´���
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
//�����ɿ�����
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
//�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
//�������غ���
void CreateMap1(int posleft, int posright, int postop, int posbottom, int maxR, int maxC, int range, int start, int num);//maxR��ʾԲ�����뾶��maxC��ʾԲ�ĸ���.range��ʾ���Բ�ķ�Χ,num��ʾterrian�ڶ�����,start��ʾ�ؿ鿪ʼ
void CreateMap3(int posleft, int posright, int postop, int posbottom, int maxR, int maxC, int range, int start, int num);//�е�
//�����ҽ�����
void CreateMap2(int posleft, int posright, int postop, int posdown);
//��Ƶ����
void SoundUpdate();
//�����¡������ȶ�Ӧ����
void Forcevkrightdown();
void Forcevkleftdown();
void Adown();
void Ddown();
void Spacedown();
//�����ϡ������ȶ�Ӧ����
void Forcevkrightup();
void Forcevkleftup();
void Aup();
void Dup();
//������ײ����
void ShouLeiCrush();
void RocketCrush();
//�����˺�����
void ShouLeiDamage();
void RocketDamage();
//����׹����ײ����
void HeroCrush();
//��ͷ���º���
void JianTouUpdate();
//���ױ�ըͼƬ���º���
void ShouLeiExplodeUpdate();
void RocketExplodeUpdate();
//���ױ�ը���Ч��
void ShouLeiMove();
void RocketMove();
//��������
void HeroFriction();
//����״̬����
void HeroMotionUpdate();
//�غϽ������㺯��
void RoundEnd();
//Ѫ�����ٿ���
void BloodDecrease();
//camara����
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