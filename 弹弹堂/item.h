#ifndef ITEM_H
#define ITEM_H

#include "global.h"
//// ȫ�ֱ���
// ����λͼ���
HBITMAP m_hBackgroundBmp;
HBITMAP m_hHeroBmp;
HBITMAP m_hGameStartButtonBmp;
HBITMAP hzhunxin;
HBITMAP hshoulei;
HBITMAP hrocket;
HBITMAP hredjiantou;
HBITMAP hbluejiantou;
HBITMAP hshouleiexplode;
HBITMAP hground;
HBITMAP hteam1hero;
HBITMAP hteam1throw;
HBITMAP hteam1launch;
HBITMAP hrocketexplode;
HBITMAP hrocketwalk;
HBITMAP hrocketpicture;
HBITMAP hshouleipicture;
HBITMAP hframe;
HBITMAP hred;
HBITMAP hgreen;
HBITMAP hFrame2;
HBITMAP h0;
HBITMAP h1;
HBITMAP h2;
HBITMAP hwind;
HBITMAP hwinddirection;
HBITMAP hwdstill;
HBITMAP happle, hgrape, hbanana, hjar;
HBITMAP hnumber;
HBITMAP htranseffect;
HBITMAP htransitem;
HBITMAP hmenu, hmenu2;
HBITMAP hsinglemission;
HBITMAP hbutton1, hbutton2, hbutton3, hbutton4;
HBITMAP hmap1, hmap2, hmap3, hmap4;
HBITMAP hback, hnext;
HBITMAP hhelp, hhelp2;
HBITMAP hhelppage;
HBITMAP end1, end2, end3, end4, end5, end6, end7, end8;
HBITMAP restart, resume, pause, hexit;
HBITMAP airstrike;
HBITMAP hplane;
HBITMAP hcrate;
HBITMAP hboom;
HBITMAP hversus;
HBITMAP mywar;
HBITMAP hversuspicture;
HBITMAP sptBmp;
HDC hdcshrink;
// ����Ӣ�ۡ����������Ρ���ť
JianTou       redjiantou, bluejiantou;//��ɫ��ͷָ�򼺷�,��ɫ��ͷָ��з�
Hero		  team1[4];//�Լ���
Hero          team1imitate[4];//ģ�⼺��������ײ��õؿ���Ϣ
Hero          team2imitate[9];//ģ��з�������ײ��õؿ���Ϣ
Hero		 team1walk[4], team2walk[9];
Hero		  team2[9]; //����
Terrian       m_terrian[2560][6];
GameButton    m_gameStartButton, scene1, scene2, scene3, scene4, back, help, bpause, brestart, bexit, bresume, bnext, bversus;
GameButton    scene11, scene21, scene31, scene41, back1;
ShouLei       m_shoulei;
Rocket        m_rocket;
ZhunXin		  m_zhunxin;
FORCE         m_force;
ShouLeiExplode shouleiexplode;
RocketExplode  rocketexplode;
Rocket    plane, boom;
// ������Ϸ״̬
GameStatus gameStatus;
Item WD[3], food[6], crate;
PictureBGM pictureBGM;//ͼƬ��bgm�Ĳ���
CAMERA camera;
TransmitGate transmitGate;
Ai ai;
#endif
