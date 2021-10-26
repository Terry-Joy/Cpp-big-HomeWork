#include "game.h"
#include "global.h"
#include "item.h"
#include<fstream>
// ����������WNDWIDTH��WNDHEIGHTΪ���ڵĿ�͸�
int TIMER_ID;             		//��ʱ��ID
int TIMER_ELAPSE;         		//��ʱ�����(ms)
int WNDWIDTH;             	//���ڵĿ�
int  WNDHEIGHT;            	//���ڵĸ�
int TITLEBARHEIGHT;       		//��������
// ������Դ�ĳߴ�
long HERO_SIZE_X;
long HERO_SIZE_Y;
long HERO_MAX_FRAME_NUM;
long GAME_START_BUTTON_SIZE_X;
long GAME_START_BUTTON_SIZE_Y;
long SHOULEI_SIZE_X;
long SHOULEI_SIZE_Y;
long ROCKET_SIZE_X;
long ROCKET_SIZE_Y;
long ARROW_SIZE_X;
long ARROW_SIZE_Y;
long SHOULEIEXPLODE_SIZE_X;     //���ױ�ըͼƬ�ߴ�
long SHOULEIEXPLODE_SIZE_Y;
long ROCKETEXPLODE_SIZE_X;
long ROCKETEXPLODE_SIZE_Y;
int WINDINTERVAL;           //
int ENDTIME;              //��ʮ�غ�����
int PLANEX;
int PLANEY;
int BOOMX;
int BOOMY;
int BOOMR;
int BOOMMOVE;

int CRATEINTERVAL;
//������Ϸ����
int GRAVITY;						//����
long HERO_VEL_X;			 		//Ӣ��ˮƽ�ٶ�
long HERO_VEL_Y;					//Ӣ����ֱ�ٶ�
int HERO_FORCE;                 //�յ�ˮƽ����
int INTERVALJUMP;              //��Ծ���ʱ��/20ms
float FORCESPEED;                //���������ٶ�
int INTERVALFORCE;		     //�����������/20ms
int deltax;                    //���Ⱦ���������ƫ����
int MAXLINE;				    //Լ�����������߳�
int SHOULEIGRAVITY;           //������������
int ROCKETGRAVITY;
int ROUNDTIME;               //�غϲ����׶�ʱ��/20ms->20s
int ROUNDENDTIME;              //�غϽ��������׶�ʱ�䣬ֻ���ƶ�һ��Ӣ��/2s
int SHOULEIR;                 //���ױ�ը�뾶
int ROCKETR;
int LeftFoot;                  //Ӣ�����λ��
int RightFoot;                //Ӣ���ҽ�λ��
int SHOULEIWAIT;			       //���ױ�ը����ʱ��/20ms
int SHOULEIMOVEVEL;		       //���ױ�ը��ɺ��ٶ�
int ROCKETMOVEVEL;
int SHOULEIMOVERANGE;          //���ױ�ը������÷�Χ
int ROCKETMOVERANGE;
int BLOODDECREASETIME;        //Ѫ������������ʾʱ��
int CAMERASPEED;              //camera�ƶ��ٶ�
int FOODINTERVAL;

void Init(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	std::ifstream infile("A.txt");
	infile >> TIMER_ID >> TIMER_ELAPSE >> WNDWIDTH >> WNDHEIGHT >> TITLEBARHEIGHT >> HERO_SIZE_X >> HERO_SIZE_Y
		>> HERO_MAX_FRAME_NUM >> GAME_START_BUTTON_SIZE_X >> GAME_START_BUTTON_SIZE_Y >> SHOULEI_SIZE_X
		>> SHOULEI_SIZE_Y >> ROCKET_SIZE_X >> ROCKET_SIZE_Y >> ARROW_SIZE_X >> ARROW_SIZE_Y >> SHOULEIEXPLODE_SIZE_X
		>> SHOULEIEXPLODE_SIZE_Y >> ROCKETEXPLODE_SIZE_X >> ROCKETEXPLODE_SIZE_Y >> WINDINTERVAL >> ENDTIME
		>> PLANEX >> PLANEY >> BOOMX >> BOOMY >> BOOMR >> BOOMMOVE >> CRATEINTERVAL >> GRAVITY >> HERO_VEL_X >> HERO_VEL_Y
		>> HERO_FORCE >> INTERVALJUMP >> FORCESPEED >> INTERVALFORCE >> deltax >> MAXLINE >> SHOULEIGRAVITY
		>> ROCKETGRAVITY >> ROUNDTIME >> ROUNDENDTIME >> SHOULEIR >> ROCKETR >> LeftFoot >> RightFoot >> SHOULEIWAIT >> SHOULEIMOVEVEL
		>> ROCKETMOVEVEL >> SHOULEIMOVERANGE >> ROCKETMOVERANGE >> BLOODDECREASETIME >> CAMERASPEED >> FOODINTERVAL;
	infile.close();
	srand((unsigned)time(NULL));
	//����׼��λͼ
	hzhunxin = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP74));
	//��������λͼ
	hshoulei = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP3));
	// ����Heroλͼ
	m_hHeroBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP66));
	hteam1hero = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP72));
	// ���ؿ�ʼ��Ϸ��ťλͼ
	m_hGameStartButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP56));
	//���غ��ͷ������ͷλͼ
	hredjiantou = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP47));
	hbluejiantou = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP9));
	//�������ױ�ըλͼ
	hshouleiexplode = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP54));
	//����ͼƬλͼ
	hground = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP30));
	//����������λͼ
	hteam1throw = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP71));
	hteam1launch = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP67));
	hrocket = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP50));
	hrocketexplode = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP51));
	//���ؿ����Ͳλͼ
	hrocketwalk = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP68));
	hrocketpicture = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP53));
	hshouleipicture = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP55));
	//�����߿�
	hframe = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP26));
	hred = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP48));
	hgreen = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP29));
	hFrame2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP27));
	h0 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	h1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
	h2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP3));
	hwind = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP64));
	hwinddirection = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP62));
	hwdstill = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP63));
	happle = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP5));
	hgrape = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP28));
	hbanana = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP7));
	hjar = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP40));
	hnumber = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP45));
	htransitem = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP58));
	htranseffect = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP59));
	hmenu = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP41));
	hsinglemission = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP56));
	hmenu2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP42));
	hbutton1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP37));
	hbutton2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP11));
	hbutton3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP32));
	hbutton4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP33));
	hmap2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP4));
	hmap1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP25));
	hmap3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP14));
	hmap4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP15));
	hback = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP31));
	hhelp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP12));
	hhelppage = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP34));
	//8��ending
	end1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP17));
	end2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP18));
	end3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP19));
	end4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP20));
	end5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP21));
	end6 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP22));
	end7 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP23));
	end8 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP24));
	//��ͣҳ���еļ���
	resume = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP49));
	restart = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP39));
	hexit = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP36));
	pause = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP38));
	hhelp2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP35));
	hnext = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP44));
	hplane = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP46));
	hboom = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP10));
	hcrate = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP13));
	airstrike = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP52));
	hversus = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP60));
	hversuspicture = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP61));
	mywar = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP43));
	// ��������Ӣ��
	int k1, k2, i;
	for (i = 0; i < 3; i++) {
		k1 = rand() % 1500 + 120;
		k2 = rand() % 600 + 100;
		team1[i].CreateHero(k1, k2, HERO_SIZE_X, HERO_SIZE_Y, hteam1hero, 0, HERO_MAX_FRAME_NUM, 1);
	}
	//�����з�Ӣ��
	for (i = 0; i < 3; i++) {
		k1 = rand() % 1500 + 120;
		k2 = rand() % 600 + 120;
		team2[i].CreateHero(k1, k2, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp, 0, HERO_MAX_FRAME_NUM, 4);
	}
	// ��������
	CreateMap1(100, 1800, 900, 1080, 45, 70, 1600, 100, 0);
	CreateMap3(100, 560, 500, 660, 50, 30, 500, -20, 1);
	CreateMap3(920, 1690, 400, 560, 55, 70, 900, 860, 1);
	CreateMap2(0, 100, 900, 1080);
	CreateMap2(1800, 1920, 900, 1080);
	//��ʼ������
	long x1 = team1[0].getHeroPos(1), y1 = team1[0].getHeroPos(0);
	int runstate = team1[0].getHeroRunState();
	m_zhunxin.CreateZhunXin(hzhunxin, 70, x1, y1, runstate);
	m_shoulei.CreateShouLei(hshoulei, x1, y1);
	m_rocket.CreateRocket(hrocket, x1, y1);
	//��Ϸ��ť����
	m_gameStartButton.CreateGameButton(80, 250, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hsinglemission, 0);
	bversus.CreateGameButton(80, 370, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hversus, 0);
	scene1.CreateGameButton(80, 80, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton1, 0);
	scene2.CreateGameButton(80, 200, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton2, 0);
	scene3.CreateGameButton(80, 320, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton3, 0);
	scene4.CreateGameButton(80, 440, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton4, 0);
	back.CreateGameButton(80, 580, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hback, 0);
	bnext.CreateGameButton(700, 580, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hnext, 0);
	help.CreateGameButton(80, 490, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hhelp, 0);
	bpause.CreateGameButton(80, 640, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, pause, 0);
	bresume.CreateGameButton(80, 300, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, resume, 0);
	brestart.CreateGameButton(80, 440, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton3, 0);
	bexit.CreateGameButton(80, 610, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hexit, 0);
	scene11.CreateGameButton(630, 80, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton1, 0);
	scene21.CreateGameButton(630, 200, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton2, 0);
	scene31.CreateGameButton(630, 320, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton3, 0);
	scene41.CreateGameButton(630, 440, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hbutton4, 0);
	back1.CreateGameButton(630, 580, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, hback, 0);
	//�趨��ʼ��Ϸ״̬
	gameStatus.getGameStatus() = 0;
	//��ʼ������Լ������
	m_force.getLine() = 0;
	//��ʼ����ͷ
	x1 = team1[0].getHeroPos(1), y1 = team1[0].getHeroPos(0);
	long x2 = team2[0].getHeroPos(1), y2 = team2[0].getHeroPos(0);
	redjiantou.CreateJianTou(hredjiantou, x1, y1);
	bluejiantou.CreateJianTou(hbluejiantou, x2, y2);
	//��ʼ�����ױ�ըͼƬ
	shouleiexplode.getShouLeiExplodehBmp() = hshouleiexplode;
	shouleiexplode.getShouLeiExplodeSize(1) = SHOULEIEXPLODE_SIZE_X;
	shouleiexplode.getShouLeiExplodeSize(0) = SHOULEIEXPLODE_SIZE_Y;
	shouleiexplode.getShouLeiExplodePos(1) = m_shoulei.getShouLeiPos(1);
	shouleiexplode.getShouLeiExplodePos(0) = m_shoulei.getShouLeiPos(0);
	//�����ըͼƬ��ʼ��
	rocketexplode.getRocketExplodehBmp() = hrocketexplode;
	rocketexplode.getRocketExplodeSize(1) = ROCKETEXPLODE_SIZE_X;
	rocketexplode.getRocketExplodeSize(0) = ROCKETEXPLODE_SIZE_Y;
	rocketexplode.getRocketExplodePos(1) = m_rocket.getRocketPos(1);
	rocketexplode.getRocketExplodePos(0) = m_rocket.getRocketPos(0);
	//��ʼcamera
	camera.getCameraPos(1) = 0;
	camera.getCameraPos(0) = 0;
	camera.getCamera1Pos(1) = 0;
	camera.getCamera1Pos(0) = 0;
	//��ʼ������
	WD[0].getPos(1) = rand() % 1200 + 300;
	WD[0].getPos(0) = m_terrian[WD[0].getPos(1) + 30][0].getPos1(0) - 32;
	WD[1].getPos(1) = rand() % 400 + 100;
	WD[1].getPos(0) = m_terrian[WD[1].getPos(1) + 30][1].getPos1(0) - 32;
	WD[2].getPos(1) = rand() % 600 + 950;
	WD[2].getPos(0) = m_terrian[WD[2].getPos(1) + 30][1].getPos1(0) - 32;
	//��ʼ��ʳ��
	food[0].getPos(1) = rand() % 1200 + 300;
	food[0].getPos(0) = m_terrian[food[0].getPos(1) + 5][0].getPos1(0);
	food[0].getFoodState() = 1;
	food[0].getFoodPicture() = rand() % 4;
}

void Render(HWND hWnd) {
	//�ж���Ϸ״̬�л�BGM
	switch (gameStatus.getGameStatus()) {
	case 0://���ƿ�ʼ����
		Render_Start(hWnd);
		if (pictureBGM.getSceneBGM(1) == 1) {
			mciSendString(TEXT("close bgm1"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(1) = 0;
		}
		if (pictureBGM.getSceneBGM(2) == 1) {
			mciSendString(TEXT("close bgm2"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(2) = 0;
		}
		if (pictureBGM.getSceneBGM(3) == 1) {
			mciSendString(TEXT("close bgm3"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(3) = 0;
		}
		if (pictureBGM.getSceneBGM(4) == 1) {
			mciSendString(TEXT("close bgm4"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(4) = 0;
		}
		if (pictureBGM.getMenuBGM() == 0) {
			mciSendString(L"open res\\menubgm.mp3 alias menubgm", NULL, 0, NULL);
			mciSendString(L"play menubgm repeat", NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 1;
		}
		break;
	case 1://���뵥����Ϸ����
		if (pictureBGM.getMenuBGM() == 0) {
			mciSendString(TEXT("open res\\menubgm.mp3 alias menubgm"), NULL, 0, NULL);
			mciSendString(TEXT("play menubgm repeat"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 1;
		}
		Render_Start(hWnd);
		break;
	case 6://��ҳhelp
		if (pictureBGM.getMenuBGM() == 0) {
			mciSendString(TEXT("open res\\menubgm.mp3 alias menubgm"), NULL, 0, NULL);
			mciSendString(TEXT("play menubgm repeat"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 1;
		}
		Render_Start(hWnd);
		break;
	case 8://help�ڵ�next����
		if (pictureBGM.getMenuBGM() == 0) {
			mciSendString(TEXT("open res\\menubgm.mp3 alias menubgm"), NULL, 0, NULL);
			mciSendString(TEXT("play menubgm repeat"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 1;
		}
		Render_Start(hWnd);
		break;
	case 9://˫��ģʽ����
		if (pictureBGM.getMenuBGM() == 0) {
			mciSendString(TEXT("open res\\menubgm.mp3 alias menubgm"), NULL, 0, NULL);
			mciSendString(TEXT("play menubgm repeat"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 1;
		}
		Render_Start(hWnd);
		break;
	case 2://���ŵ�ͼ
		if (pictureBGM.getMenuBGM() == 1) {
			mciSendString(TEXT("close menubgm"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 0;
		}
		if (pictureBGM.getSceneBGM(1) == 0) {
			mciSendString(TEXT("open res\\bgm1.mp3 alias bgm1"), NULL, 0, NULL);
			mciSendString(TEXT("play bgm1 repeat"), NULL, 0, NULL);
			mciSendString(TEXT("setaudio bgm1 volume to 50"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(1) = 1;
		}
		Render_Game(hWnd);
		break;
	case 3:
		if (pictureBGM.getMenuBGM() == 1) {
			mciSendString(TEXT("close menubgm"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 0;
		}
		if (pictureBGM.getSceneBGM(2) == 0) {
			mciSendString(TEXT("open res\\bgm2.mp3 alias bgm2"), NULL, 0, NULL);
			mciSendString(TEXT("play bgm2 repeat"), NULL, 0, NULL);
			mciSendString(TEXT("setaudio bgm2 volume to 50"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(2) = 1;
		}
		Render_Game(hWnd);
		break;
	case 4:
		if (pictureBGM.getMenuBGM() == 1) {
			mciSendString(TEXT("close menubgm"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 0;
		}
		if (pictureBGM.getSceneBGM(3) == 0) {
			mciSendString(TEXT("open res\\bgm3.mp3 alias bgm3"), NULL, 0, NULL);
			mciSendString(TEXT("play bgm3 repeat"), NULL, 0, NULL);
			mciSendString(TEXT("setaudio bgm3 volume to 50"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(3) = 1;
		}
		Render_Game(hWnd);
		break;
	case 5:
		if (pictureBGM.getMenuBGM() == 1) {
			mciSendString(TEXT("close menubgm"), NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 0;
		}
		if (pictureBGM.getSceneBGM(4) == 0) {
			mciSendString(TEXT("open res\\bgm4.mp3 alias bgm4"), NULL, 0, NULL);
			mciSendString(TEXT("play bgm4 repeat"), NULL, 0, NULL);
			mciSendString(TEXT("setaudio bgm4 volume to 50"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(4) = 1;
		}
		Render_Game(hWnd);
		break;
	case 7:
		if (pictureBGM.getSceneBGM(1) == 1) {
			mciSendString(TEXT("close bgm1"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(1) = 0;
		}
		if (pictureBGM.getSceneBGM(2) == 1) {
			mciSendString(TEXT("close bgm2"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(2) = 0;
		}
		if (pictureBGM.getSceneBGM(3) == 1) {
			mciSendString(TEXT("close bgm3"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(3) = 0;
		}
		if (pictureBGM.getSceneBGM(4) == 1) {
			mciSendString(TEXT("close bgm4"), NULL, 0, NULL);
			pictureBGM.getSceneBGM(4) = 0;
		}
		if (pictureBGM.getMenuBGM() == 0) {
			mciSendString(L"open res\\menubgm.mp3 alias menubgm", NULL, 0, NULL);
			mciSendString(L"play menubgm repeat", NULL, 0, NULL);
			pictureBGM.getMenuBGM() = 1;
		}
		//���ö�ʱ��
		KillTimer(hWnd, TIMER_ID);
		InvalidateRect(hWnd, NULL, TRUE);
		Render_Start(hWnd);
		break;
	default:
		break;
	}
}

void Render_Start(HWND hWnd) {//��Ϸ��ʼ����
	PAINTSTRUCT ps;
	HDC hdc;
	// ��ʼ����
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;				//˫������� �ڴ�DC ����DC(���壩
	HBITMAP	cptBmp;						//����

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);

	if (gameStatus.getGameStatus() == 0) {
		// ���Ʊ�����������
		SelectObject(hdcBuffer, cptBmp);
		SelectObject(hdcBmp, hmenu);
		TransparentBlt(hdcBuffer, 0, 0, 1000, 800, hdcBmp, 0, 0, 1300, 1000, RGB(255, 255, 255));

		SelectObject(hdcBmp, mywar);
		TransparentBlt(hdcBuffer, 55, 35, 420, 210, hdcBmp, 0, 0, 400, 200, RGB(255, 255, 255));

		SelectObject(hdcBmp, hsinglemission);
		TransparentBlt(hdcBuffer, m_gameStartButton.getPos(1), m_gameStartButton.getPos(0), m_gameStartButton.getSize(1), m_gameStartButton.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));

		SelectObject(hdcBmp, hhelp);
		TransparentBlt(hdcBuffer, help.getPos(1), help.getPos(0), help.getSize(1), help.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));

		SelectObject(hdcBmp, hversus);
		TransparentBlt(hdcBuffer, bversus.getPos(1), bversus.getPos(0), bversus.getSize(1), bversus.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));

		SelectObject(hdcBmp, hexit);
		TransparentBlt(hdcBuffer, bexit.getPos(1), bexit.getPos(0), bexit.getSize(1), bexit.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
	}
	if (gameStatus.getGameStatus() == 1) {//����ģʽ�»�ͼ
		SelectObject(hdcBuffer, cptBmp);
		SelectObject(hdcBmp, hmenu2);
		TransparentBlt(hdcBuffer, 0, 0, 1000, 800,
			hdcBmp, 280, 224, 1000, 800, RGB(255, 255, 255));
		//�ķ���ͼ������ͼ
		SelectObject(hdcBmp, hbutton1);
		TransparentBlt(hdcBuffer, scene1.getPos(1), scene1.getPos(0), scene1.getSize(1), scene1.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, hbutton2);
		TransparentBlt(hdcBuffer, scene2.getPos(1), scene2.getPos(0), scene2.getSize(1), scene2.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, hbutton3);
		TransparentBlt(hdcBuffer, scene3.getPos(1), scene3.getPos(0), scene3.getSize(1), scene3.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, hbutton4);
		TransparentBlt(hdcBuffer, scene4.getPos(1), scene4.getPos(0), scene4.getSize(1), scene4.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));

		SelectObject(hdcBmp, hback);	TransparentBlt(hdcBuffer, back.getPos(1), back.getPos(0), back.getSize(1), back.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
	}
	if (gameStatus.getGameStatus() == 9) {//˫��ģʽ
		SelectObject(hdcBuffer, cptBmp);
		SelectObject(hdcBmp, hversuspicture);
		BitBlt(hdcBuffer, 0, 0, 1000, 800, hdcBmp, 0, 0, SRCCOPY);
		//�ķ���ͼ
		SelectObject(hdcBmp, hbutton1);
		TransparentBlt(hdcBuffer, scene11.getPos(1), scene11.getPos(0), scene11.getSize(1), scene11.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, hbutton2);
		TransparentBlt(hdcBuffer, scene21.getPos(1), scene21.getPos(0), scene21.getSize(1), scene21.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, hbutton3);
		TransparentBlt(hdcBuffer, scene31.getPos(1), scene31.getPos(0), scene31.getSize(1), scene31.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, hbutton4);
		TransparentBlt(hdcBuffer, scene41.getPos(1), scene41.getPos(0), scene41.getSize(1), scene41.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));

		SelectObject(hdcBmp, hback);	
		TransparentBlt(hdcBuffer, back1.getPos(1), back1.getPos(0), back1.getSize(1), back1.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
	}

	if (gameStatus.getGameStatus() == 8){
		SelectObject(hdcBuffer, cptBmp);

		SelectObject(hdcBmp, hhelp2);
		BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);

		SelectObject(hdcBmp, hback);
		TransparentBlt(hdcBuffer, back.getPos(1), back.getPos(0), back.getSize(1), back.getSize(0),
			hdcBmp, 0, 0,
			1153, 360, RGB(255, 255, 255));
	}
	if (gameStatus.getGameStatus() == 6) {//���������ͼ
		SelectObject(hdcBuffer, cptBmp);
		SelectObject(hdcBmp, hhelppage);
		TransparentBlt(hdcBuffer, 0, 0, 1000, 800, hdcBmp, 100, 0, 1080, 800, RGB(255, 255, 255));

		SelectObject(hdcBmp, hback);
		TransparentBlt(hdcBuffer, back.getPos(1), back.getPos(0), back.getSize(1), back.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));

		SelectObject(hdcBmp, hnext);
		TransparentBlt(hdcBuffer, bnext.getPos(1), bnext.getPos(0), bnext.getSize(1), bnext.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
	}
	if (gameStatus.getGameStatus() == 7) {//8����Ϸendingѡȡ
		if (pictureBGM.getEndPage() == 0) {
			pictureBGM.getEndPagePicture() = rand() % 8;
			pictureBGM.getEndPage() = 1;
		}
		SelectObject(hdcBuffer, cptBmp);
		if (pictureBGM.getEndPagePicture() == 0) {
			SelectObject(hdcBmp, end1);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		if (pictureBGM.getEndPagePicture() == 1) {
			SelectObject(hdcBmp, end2);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		if (pictureBGM.getEndPagePicture() == 2) {
			SelectObject(hdcBmp, end8);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		if (pictureBGM.getEndPagePicture() == 3) {
			SelectObject(hdcBmp, end3);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		if (pictureBGM.getEndPagePicture() == 4) {
			SelectObject(hdcBmp, end4);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		if (pictureBGM.getEndPagePicture() == 5) {
			SelectObject(hdcBmp, end5);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		if (pictureBGM.getEndPagePicture() == 6) {
			SelectObject(hdcBmp, end6);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		if (pictureBGM.getEndPagePicture() == 7) {
			SelectObject(hdcBmp, end7);
			BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBmp, 0, 0, SRCCOPY);
		}
		SelectObject(hdcBmp, hback);
		TransparentBlt(hdcBuffer, back.getPos(1), back.getPos(0), back.getSize(1), back.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, resume);
		TransparentBlt(hdcBuffer, bresume.getPos(1), bresume.getPos(0), bresume.getSize(1), bresume.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
		SelectObject(hdcBmp, restart);
		TransparentBlt(hdcBuffer, brestart.getPos(1), brestart.getPos(0), brestart.getSize(1), brestart.getSize(0), hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
	}
	// ���Ƶ���Ļ
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);
	// ������Դ��������
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);
	EndPaint(hWnd, &ps);
}

void Render_Game(HWND hWnd) {//��Ϸ�л���
	PAINTSTRUCT ps;
	HDC hdc;
	// ��ʼ����
	hdc = BeginPaint(hWnd, &ps);
	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;
	cptBmp = CreateCompatibleBitmap(hdc, 1920, 1080);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	//�ķ���ͼ
	if (gameStatus.getGameStatus() == 2) gameStatus.getGameStatushBmp() = hmap1;
	else if (gameStatus.getGameStatus() == 3) gameStatus.getGameStatushBmp() = hmap2;
	else if (gameStatus.getGameStatus() == 4) gameStatus.getGameStatushBmp() = hmap3;
	else if (gameStatus.getGameStatus() == 5) gameStatus.getGameStatushBmp() = hmap4;

	// ���Ʊ���������
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.getGameStatushBmp());
	BitBlt(hdcBuffer, 0, 0, 1920, 1080, hdcBmp, 0, 0, SRCCOPY);

	if (gameStatus.getGameStart() == 0 || gameStatus.getPaintAgain() == 1) {
		DeleteObject(sptBmp);
		DeleteDC(hdcshrink);
		sptBmp = CreateCompatibleBitmap(hdc, 1920, 1080);
		hdcshrink = CreateCompatibleDC(hdc);
		SelectObject(hdcshrink, sptBmp);
		SelectObject(hdcBmp, gameStatus.getGameStatushBmp());
		BitBlt(hdcshrink, 0, 0, 1920, 1080, hdcBmp, 0, 0, SRCCOPY);
		// ���Ƶ���
		int k, j;
		SelectObject(hdcBmp, hground);
		for (k = 1; k < 1920; k++) {
			for (j = 0; j < gameStatus.getTerrianSecond(k); j++) {
				if (gameStatus.getTerrianState(k, j) == 1) {//�������ز���
					TransparentBlt(hdcBuffer, m_terrian[k][j].getPos1(1), m_terrian[k][j].getPos1(0), 1, m_terrian[k][j].getPos2(0) - m_terrian[k][j].getPos1(0), hdcBmp, m_terrian[k][j].getPos1(1), m_terrian[k][j].getPos1(0), 1, m_terrian[k][j].getPos2(0) - m_terrian[k][j].getPos1(0), RGB(255, 255, 255));
				}
			}
		}
		//(�����ҽ�)
		HPEN linePen1;//����
		HBRUSH brush;//��ˢ
		linePen1 = CreatePen(PS_SOLID, 1, RGB(255, 69, 0));
		brush = CreateSolidBrush(RGB(255, 69, 0));
		SelectObject(hdcBuffer, linePen1);
		SelectObject(hdcBuffer, brush);
		Rectangle(hdcBuffer, 0, 900, 100, 1080);		//�ҽ�
		Rectangle(hdcBuffer, 1760, 900, 1920, 1080);
		DeleteObject(linePen1);
		DeleteObject(brush);
		TransparentBlt(hdcshrink, 0, 0, 1920, 1080, hdcBuffer, 0, 0, 1920, 1080, RGB(255, 255, 255));
		gameStatus.getGameStart() = 1;
		gameStatus.getPaintAgain() = 0;
	}
	TransparentBlt(hdcBuffer, 0, 0, 1920, 1080, hdcshrink, 0, 0, 1920, 1080, RGB(255, 255, 255));
	// ���Ƽ���Ӣ��
	HPEN linePen1;
	HBRUSH brush;
	int j;
	for (j = 0; j < 3; j++) {
		if (team1[j].getHeroLife() != 0) {
			if (team1[j].getHeroRunState() == -2) {
				if (team1[j].getHeroWeapon() == 0) {//���Ҿ�ֹ��������
					if (j == gameStatus.getHeroOrder1() && (gameStatus.getThrowState() == 1 || gameStatus.getLaunchState() == 1));
					else {//��ȥ����Ͷ�����״̬ ԭ�ػ���
						SelectObject(hdcBmp, team1[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, 180, 72, 60, 72, RGB(255, 255, 255));
					}
				}
				else if (team1[j].getHeroWeapon() == 1) {//���Ҿ�ֹ���Ż��
					if (j == gameStatus.getHeroOrder1() && (gameStatus.getThrowState() == 1 || gameStatus.getLaunchState() == 1));
					else {
						SelectObject(hdcBmp, hrocketwalk);
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), 32, 35, hdcBmp, 630, 75, 105, 75, RGB(255, 255, 255));
					}
				}
				else if (team1[j].getHeroWeapon() == 2) {//���Ŵ�����
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {//û����ʱ��
						SelectObject(hdcBmp, team1[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, 180, 72, 60, 72, RGB(255, 255, 255));
					}
				}
				else if (team1[j].getHeroWeapon() == 4) {//���ſ�Ϯ��ʱ��
					SelectObject(hdcBmp, team1[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, 180, 72, 60, 72, RGB(255, 255, 255));
				}
			}
			if (team1[j].getHeroRunState() == -1) {//����ֹ
				if (team1[j].getHeroWeapon() == 0) {
					if (j == gameStatus.getHeroOrder1() && (gameStatus.getThrowState() == 1 || gameStatus.getLaunchState() == 1));
					else {
						SelectObject(hdcBmp, team1[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, 0, 0, 60, 72, RGB(255, 255, 255));
					}
				}
				else if (team1[j].getHeroWeapon() == 1) {
					if (j == gameStatus.getHeroOrder1() && (gameStatus.getThrowState() == 1 || gameStatus.getLaunchState() == 1));
					else {
						SelectObject(hdcBmp, hrocketwalk);
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), 32, 35, hdcBmp, 0, 0, 105, 75, RGB(255, 255, 255));
					}
				}
				else if (team1[j].getHeroWeapon() == 2) {
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {
						SelectObject(hdcBmp, team1[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, 0, 0, 60, 72, RGB(255, 255, 255));
					}
				}
				else if (team1[j].getHeroWeapon() == 4) {
					SelectObject(hdcBmp, team1[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, 0, 0, 60, 72, RGB(255, 255, 255)
					);
				}
			}
			if (team1[j].getHeroRunState() == 1) {//������·
				if (team1[j].getHeroWeapon() == 0) {
					SelectObject(hdcBmp, team1[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, (team1[j].getHeroTimes() + 2) / 4 * 60, 0, 60, 72, RGB(255, 255, 255));
					team1[j].getHeroTimes()--;//8֡ 4times 1֡
					if (team1[j].getHeroTimes() == -3) team1[j].getHeroTimes() = 29;
				}
				else if (team1[j].getHeroWeapon() == 1) {
					SelectObject(hdcBmp, hrocketwalk);
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), 32, 35, hdcBmp, (team1[j].getHeroTimes() + 2) / 4 * 105, 0, 105, 75, RGB(255, 255, 255));
					team1[j].getHeroTimes()--;//7֡ 4timesһ֡
					if (team1[j].getHeroTimes() == -3) team1[j].getHeroTimes() = 25;
				}
				else if (team1[j].getHeroWeapon() == 2) {
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {
						SelectObject(hdcBmp, team1[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, (team1[j].getHeroTimes() + 2) / 4 * 60, 0, 60, 72, RGB(255, 255, 255));
						team1[j].getHeroTimes()--;	//8֡ 4timesһ֡
						if (team1[j].getHeroTimes() == -3) team1[j].getHeroTimes() = 29;
					}
				}
				else if (team1[j].getHeroWeapon() == 4) {
					SelectObject(hdcBmp, team1[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, (team1[j].getHeroTimes() + 2) / 4 * 60, 0, 60, 72, RGB(255, 255, 255));
					team1[j].getHeroTimes()--;//8֡ 4timesһ֡
					if (team1[j].getHeroTimes() == -3) team1[j].getHeroTimes() = 29;
				}
			}
			if (team1[j].getHeroRunState() == 2) {//������· ͬ��
				if (team1[j].getHeroWeapon() == 0) {
					SelectObject(hdcBmp, team1[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, (team1[j].getHeroTimes() + 27) / 4 * 60, 72, 60, 72, RGB(255, 255, 255));
					team1[j].getHeroTimes()++;
					if (team1[j].getHeroTimes() == 5) team1[j].getHeroTimes() = -27;
				}
				else if (team1[j].getHeroWeapon() == 1) {
					SelectObject(hdcBmp, hrocketwalk);
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), 32, 35, hdcBmp, (team1[j].getHeroTimes() + 23) / 4 * 105, 75, 105, 75, RGB(255, 255, 255));
					team1[j].getHeroTimes()++;
					if (team1[j].getHeroTimes() == 5) team1[j].getHeroTimes() = -23;
				}
				else if (team1[j].getHeroWeapon() == 2) {
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {
						SelectObject(hdcBmp, team1[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, (team1[j].getHeroTimes() + 27) / 4 * 60, 72, 60, 72, RGB(255, 255, 255));
						team1[j].getHeroTimes()++;
						if (team1[j].getHeroTimes() == 5) team1[j].getHeroTimes() = -27;
					}
				}
				else if (team1[j].getHeroWeapon() == 4){
					SelectObject(hdcBmp, team1[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0), team1[j].getHeroSize(1), team1[j].getHeroSize(1), hdcBmp, (team1[j].getHeroTimes() + 27) / 4 * 60, 72, 60, 72, RGB(255, 255, 255));
					team1[j].getHeroTimes()++;
					if (team1[j].getHeroTimes() == 5) team1[j].getHeroTimes() = -27;
				}
			}
		}
	}
	//���Ƶз�Ӣ�� ͬ�ѷ�
	for (j = 0; j < 3; j++) {
		if (team2[j].getHeroLife() != 0) {
			if (team2[j].getHeroRunState() == -2) {
				if (team2[j].getHeroWeapon() == 0 || team2[j].getHeroWeapon() == 1 || team2[j].getHeroWeapon() == 4) {
					SelectObject(hdcBmp, team2[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, 750, 150, 150, 150, RGB(255, 255, 255));
				}
				else if (team2[j].getHeroWeapon() == 2) {
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {
						SelectObject(hdcBmp, team2[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, 750, 150, 150, 150, RGB(255, 255, 255));
					}
				}
			}
			if (team2[j].getHeroRunState() == -1) {
				if (team2[j].getHeroWeapon() == 0 || team2[j].getHeroWeapon() == 1 || team2[j].getHeroWeapon() == 4) {
					SelectObject(hdcBmp, team2[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, 750, 0, 150, 150, RGB(255, 255, 255)
					);
				}
				else if (team2[j].getHeroWeapon() == 2) {
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {
						SelectObject(hdcBmp, team2[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, 750, 0, 150, 150, RGB(255, 255, 255));
					}
				}
			}
			if (team2[j].getHeroRunState() == 1) {
				if (team2[j].getHeroWeapon() == 0 || team2[j].getHeroWeapon() == 1 || team2[j].getHeroWeapon() == 4) {
					SelectObject(hdcBmp, team2[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, team2[j].getHeroTimes() * 150, 0, 150, 150, RGB(255, 255, 255));
					team2[j].getHeroTimes()--;
					if (team2[j].getHeroTimes() == -1) team2[j].getHeroTimes() = 10;
				}
				else if (team2[j].getHeroWeapon() == 2) {
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {
						SelectObject(hdcBmp, team2[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, team2[j].getHeroTimes() * 150, 0, 150, 150, RGB(255, 255, 255));
						team2[j].getHeroTimes()--;	//11֡ 1times 1֡
						if (team2[j].getHeroTimes() == -1) team2[j].getHeroTimes() = 10;
					}
				}
			}
			if (team2[j].getHeroRunState() == 2) {
				if (team2[j].getHeroWeapon() == 0 || team2[j].getHeroWeapon() == 1 || team2[j].getHeroWeapon() == 4) {
					SelectObject(hdcBmp, team2[j].getHerohBmp());
					TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, (team2[j].getHeroTimes() + 2) * 150, 150, 150, 150, RGB(255, 255, 255));
					team2[j].getHeroTimes()++;
					if (team2[j].getHeroTimes() == 9) team2[j].getHeroTimes() = -2;
				}
				else if (team2[j].getHeroWeapon() == 2) {
					if (transmitGate.getTranState() == 0 || transmitGate.getTranState() == 3) {
						SelectObject(hdcBmp, team2[j].getHerohBmp());
						TransparentBlt(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0), team2[j].getHeroSize(1), team2[j].getHeroSize(1), hdcBmp, (team2[j].getHeroTimes() + 2) * 150, 150, 150, 150, RGB(255, 255, 255));
						team2[j].getHeroTimes()++;
						if (team2[j].getHeroTimes() == 9) team2[j].getHeroTimes() = -2;
					}
				}
			}
		}
		//���ƴ���Ч��
		if (gameStatus.getHeroSide() == 0) {
			if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2) {
				if (transmitGate.getTranState() == 1) {
					SelectObject(hdcBmp, htranseffect);
					TransparentBlt(hdcBuffer, team1[gameStatus.getHeroOrder1()].getHeroPos(1), team1[gameStatus.getHeroOrder1()].getHeroPos(0) - 20, 40, 80, hdcBmp, transmitGate.getTranTimes() / 10 * 200, 0, 200, 500, RGB(255, 255, 255));
					transmitGate.getTranTimes()++;//16֡ 10timesһ֡
					if (transmitGate.getTranTimes() == 160)
					{
						transmitGate.getTranState() = 2;
						transmitGate.getTranTimes() = 0;
					}
				}
				else if (transmitGate.getTranState() == 2) {
					SelectObject(hdcBmp, htranseffect);
					TransparentBlt(hdcBuffer, team1[gameStatus.getHeroOrder1()].getHeroPos(1), team1[gameStatus.getHeroOrder1()].getHeroPos(0) - 20, 40, 80, hdcBmp, transmitGate.getTranTimes() / 10 * 200, 0, 200, 500, RGB(255, 255, 255));
					transmitGate.getTranTimes()++;
					if (transmitGate.getTranTimes() == 160) {
						transmitGate.getTranState() = 3;
						transmitGate.getTranTimes() = 0;
					}
				}
			}
		}
		if (gameStatus.getHeroSide() == 1) {//�з�
			if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2) {
				if (transmitGate.getTranState() == 1) {
					SelectObject(hdcBmp, htranseffect);
					TransparentBlt(hdcBuffer, team2[gameStatus.getHeroOrder2()].getHeroPos(1), team2[gameStatus.getHeroOrder2()].getHeroPos(0) - 20, 40, 80, hdcBmp, transmitGate.getTranTimes() / 10 * 200, 0, 200, 500, RGB(255, 255, 255));
					transmitGate.getTranTimes()++;
					if (transmitGate.getTranTimes() == 160) {
						transmitGate.getTranState() = 2;
						transmitGate.getTranTimes() = 0;
					}
				}
				else if (transmitGate.getTranState() == 2) {
					SelectObject(hdcBmp, htranseffect);
					TransparentBlt(hdcBuffer, team2[gameStatus.getHeroOrder2()].getHeroPos(1), team2[gameStatus.getHeroOrder2()].getHeroPos(0) - 20, 40, 80, hdcBmp, transmitGate.getTranTimes() / 10 * 200, 0, 200, 500, RGB(255, 255, 255));
					transmitGate.getTranTimes()++;
					if (transmitGate.getTranTimes() == 160) {
						transmitGate.getTranState() = 3;
						transmitGate.getTranTimes() = 0;
					}
				}
			}
		}
	}
	//����������
	if (gameStatus.getHeroSide() == 0) {
		if (gameStatus.getThrowState() == 1) {
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1) {//�����Ӷ���
				SelectObject(hdcBmp, hteam1throw);
				TransparentBlt(hdcBuffer, team1[gameStatus.getHeroOrder1()].getHeroPos(1), team1[gameStatus.getHeroOrder1()].getHeroPos(0), team1[gameStatus.getHeroOrder1()].getHeroSize(1), team1[gameStatus.getHeroOrder1()].getHeroSize(1), hdcBmp, (gameStatus.getThrowTimes() / 2) * 80, 0, 80, 73, RGB(255, 255, 255));
				gameStatus.getThrowTimes()++;//��7֡��ʱ���Ѿ�����
				if (gameStatus.getThrowTimes() == 12) m_shoulei.getShouLeiState() = 0;//����״̬
				if (gameStatus.getThrowTimes() == 18) {
					gameStatus.getThrowTimes() = 0;//9֡ 2times 1֡
					gameStatus.getThrowState() = 0;
				}
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2) {//ͬ��
				SelectObject(hdcBmp, hteam1throw);
				TransparentBlt(hdcBuffer, team1[gameStatus.getHeroOrder1()].getHeroPos(1), team1[gameStatus.getHeroOrder1()].getHeroPos(0), team1[gameStatus.getHeroOrder1()].getHeroSize(1), team1[gameStatus.getHeroOrder1()].getHeroSize(1), hdcBmp, (gameStatus.getThrowTimes() + 17) / 2 * 80, 73, 80, 73, RGB(255, 255, 255));
				gameStatus.getThrowTimes()--;
				if (gameStatus.getThrowTimes() == -9) m_shoulei.getShouLeiState() = 0;
				if (gameStatus.getThrowTimes() == -18) {
					gameStatus.getThrowTimes() = 0;
					gameStatus.getThrowState() = 0;
				}
			}
		}
	}
	//������
	if (gameStatus.getHeroSide() == 0) {
		if (gameStatus.getLaunchState() == 1) {
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1) {
				SelectObject(hdcBmp, hteam1launch);
				TransparentBlt(hdcBuffer, team1[gameStatus.getHeroOrder1()].getHeroPos(1), team1[gameStatus.getHeroOrder1()].getHeroPos(0), 32, 35, hdcBmp, (gameStatus.getLaunchTimes() / 2) * 95, 0, 95, 95, RGB(255, 255, 255));
				gameStatus.getLaunchTimes()++;//Ҫ������
				if (gameStatus.getLaunchTimes() == 7) m_rocket.getRocketState() = 0;
				if (gameStatus.getLaunchTimes() == 14) {//��4֡��ʱ�� ����ȥ׼����ը
					gameStatus.getLaunchTimes() = 0;
					gameStatus.getLaunchState() = 0;
				}
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2) {
				SelectObject(hdcBmp, hteam1launch);
				TransparentBlt(hdcBuffer, team1[gameStatus.getHeroOrder1()].getHeroPos(1), team1[gameStatus.getHeroOrder1()].getHeroPos(0), 32, 35, hdcBmp, (gameStatus.getLaunchTimes() + 13) / 2 * 95, 95, 95, 95, RGB(255, 255, 255));
				gameStatus.getLaunchTimes()--;
				if (gameStatus.getLaunchTimes() == -6) m_rocket.getRocketState() = 0;
				if (gameStatus.getLaunchTimes() == -14) {
					gameStatus.getLaunchTimes() = 0;
					gameStatus.getLaunchState() = 0;
				}
			}
		}
	}
	//��������
	if (m_shoulei.getShouLeiState() == 0 || m_shoulei.getShouLeiState() == 4) {
		SelectObject(hdcBmp, m_shoulei.getShouLeiHsl());
		TransparentBlt(hdcBuffer, m_shoulei.getShouLeiPos(1), m_shoulei.getShouLeiPos(0), m_shoulei.getShouLeiSize(1), m_shoulei.getShouLeiSize(0), hdcBmp, 0, 0, 720, 720, RGB(255, 255, 255));
	}
	//���ƻ����
	if (m_rocket.getRocketState() == 0 || m_rocket.getRocketState() == 4) {
		SelectObject(hdcBmp, m_rocket.getRockethBmp());
		TransparentBlt(hdcBuffer, m_rocket.getRocketPos(1), m_rocket.getRocketPos(0), m_rocket.getRocketSize(1), m_rocket.getRocketSize(0), hdcBmp, 0, 0, 60, 15, RGB(255, 255, 255));
	}
	//���Ƽ���Ѫ��
	float per;
	int end;//end��ʾ��ɫѪ���յ�
	for (j = 0; j < 3; j++) {
		if (team1[j].getHeroLife() >= 100) {
			linePen1 = CreatePen(PS_SOLID, 3, RGB(252, 13, 27));//�û��ʻ�
			SelectObject(hdcBuffer, linePen1);
			MoveToEx(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0) - 10, NULL);
			LineTo(hdcBuffer, team1[j].getHeroPos(1) + HERO_SIZE_X, team1[j].getHeroPos(0) - 10);
			DeleteObject(linePen1);
		}
		else if (team1[j].getHeroLife() > 0) {
			per = (float)team1[j].getHeroLife() / 100.0;//�ٷֱ���Ѫ
			end = team1[j].getHeroPos(1) + HERO_SIZE_X * per;
			linePen1 = CreatePen(PS_SOLID, 3, RGB(252, 13, 27));
			SelectObject(hdcBuffer, linePen1);
			MoveToEx(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0) - 10, NULL);
			LineTo(hdcBuffer, end, team1[j].getHeroPos(0) - 10);
			DeleteObject(linePen1);
			linePen1 = CreatePen(PS_SOLID, 3, RGB(105, 105, 105));
			SelectObject(hdcBuffer, linePen1);
			MoveToEx(hdcBuffer, end, team1[j].getHeroPos(0) - 10, NULL);
			LineTo(hdcBuffer, team1[j].getHeroPos(1) + HERO_SIZE_X, team1[j].getHeroPos(0) - 10);
			DeleteObject(linePen1);
		}
	}
	//���Ƶз�Ѫ��
	for (j = 0; j < 3; j++) {
		if (team2[j].getHeroLife() >= 100) {
			linePen1 = CreatePen(PS_SOLID, 3, RGB(42, 253, 132));
			SelectObject(hdcBuffer, linePen1);
			MoveToEx(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0) - 10, NULL);
			LineTo(hdcBuffer, team2[j].getHeroPos(1) + HERO_SIZE_X, team2[j].getHeroPos(0) - 10);
			DeleteObject(linePen1);
		}
		else if (team2[j].getHeroLife() > 0) {
			per = (float)team2[j].getHeroLife() / 100.0;
			end = team2[j].getHeroPos(1) + HERO_SIZE_X * per;
			linePen1 = CreatePen(PS_SOLID, 3, RGB(42, 253, 132));
			SelectObject(hdcBuffer, linePen1);
			MoveToEx(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0) - 10, NULL);
			LineTo(hdcBuffer, end, team2[j].getHeroPos(0) - 10);
			DeleteObject(linePen1);
			linePen1 = CreatePen(PS_SOLID, 3, RGB(105, 105, 105));
			SelectObject(hdcBuffer, linePen1);
			MoveToEx(hdcBuffer, end, team2[j].getHeroPos(0) - 10, NULL);
			LineTo(hdcBuffer, team2[j].getHeroPos(1) + HERO_SIZE_X, team2[j].getHeroPos(0) - 10);
			DeleteObject(linePen1);
		}
	}
	//���Ƽ���Ѫ������	
	for (j = 0; j < 3; j++) {
		if (team1[j].getHeroLife() != 0) {
			if (team1[j].getHeroLife() >= 100) {
				TCHAR	blood[13];
				SetTextColor(hdcBuffer, RGB(252, 13, 27));//������ɫ
				SetBkMode(hdcBuffer, TRANSPARENT);		//������ʽ
				wsprintfW(blood, L"%d", team1[j].getHeroLife());
				TextOutW(hdcBuffer, team1[j].getHeroPos(1), team1[j].getHeroPos(0) - 30, blood, _tcslen(blood));
			}
			else {
				TCHAR	blood[13];
				SetTextColor(hdcBuffer, RGB(252, 13, 27));
				SetBkMode(hdcBuffer, TRANSPARENT);
				wsprintfW(blood, L"%d", team1[j].getHeroLife());
				TextOutW(hdcBuffer, team1[j].getHeroPos(1) + 5, team1[j].getHeroPos(0) - 30, blood, _tcslen(blood));
			}
		}
	}
	//���Ƶз�Ѫ������
	for (j = 0; j < 3; j++) {
		if (team2[j].getHeroLife() != 0) {
			if (team2[j].getHeroLife() >= 100) {
				TCHAR	blood[13];
				SetTextColor(hdcBuffer, RGB(42, 253, 132));
				SetBkMode(hdcBuffer, TRANSPARENT);
				wsprintfW(blood, L"%d", team2[j].getHeroLife());
				TextOutW(hdcBuffer, team2[j].getHeroPos(1), team2[j].getHeroPos(0) - 30, blood, _tcslen(blood));
			}
			else {
				TCHAR	blood[13];
				SetTextColor(hdcBuffer, RGB(42, 253, 132));
				SetBkMode(hdcBuffer, TRANSPARENT);
				wsprintfW(blood, L"%d", team2[j].getHeroLife());
				TextOutW(hdcBuffer, team2[j].getHeroPos(1) + 5, team2[j].getHeroPos(0) - 30, blood, _tcslen(blood));
			}
		}
	}
	//���Ƽ�����ͷ
	if (gameStatus.getHeroSide() == 0) {
		if (team2[j].getHeroLife() != 0) {
			SelectObject(hdcBmp, redjiantou.getJianTouhBmp());
			TransparentBlt(hdcBuffer, redjiantou.getJianTouPos(1), redjiantou.getJianTouPos(0) - 50, redjiantou.getJianTouSize(1), redjiantou.getJianTouSize(0), hdcBmp, 0, 0, 300, 300, RGB(255, 255, 255));
		}
	}
	//���Ƶз���ͷ
	if (gameStatus.getHeroSide() == 1) {
		SelectObject(hdcBmp, bluejiantou.getJianTouhBmp());
		TransparentBlt(hdcBuffer, bluejiantou.getJianTouPos(1), bluejiantou.getJianTouPos(0) - 50, bluejiantou.getJianTouSize(1), bluejiantou.getJianTouSize(0), hdcBmp, 0, 0, 300, 300, RGB(255, 255, 255));
	}
	//ͷ������Ѫ��������
	//����
	for (j = 0; j < 3; j++) {
		if (team1[j].getHeroLifeDecrease() - team1[j].getHeroLife() != 0) {
			TCHAR	decrease[13];
			SetTextColor(hdcBuffer, RGB(252, 40, 252));
			SetBkMode(hdcBuffer, TRANSPARENT);
			wsprintfW(decrease, L"%d", team1[j].getHeroLife() - team1[j].getHeroLifeDecrease());
			TextOutW(hdcBuffer, team1[j].getHeroPos(1) + 4, team1[j].getHeroPos(0) - 46, decrease, _tcslen(decrease));
		}
	}
	//�з� 
	for (j = 0; j < 3; j++) {
		if (team2[j].getHeroLifeDecrease() - team2[j].getHeroLife() != 0) {
			TCHAR	decrease[13];
			SetTextColor(hdcBuffer, RGB(252, 40, 252));
			SetBkMode(hdcBuffer, TRANSPARENT);
			wsprintfW(decrease, L"%d", team2[j].getHeroLife() - team2[j].getHeroLifeDecrease());
			TextOutW(hdcBuffer, team2[j].getHeroPos(1) + 4, team2[j].getHeroPos(0) - 46, decrease, _tcslen(decrease));
		}
	}
	//����ʳ��
	for (j = 0; j < 6; j++) {
		if (food[j].getFoodState() == 1) {//�������
			if (food[j].getFoodPicture() == 0) {//��û������
				SelectObject(hdcBmp, happle);	//ƻ��
				TransparentBlt(hdcBuffer, food[j].getPos(1), food[j].getPos(0) - 25, 25, 25, hdcBmp, 0, 0, 30, 30, RGB(255, 255, 255));
			}
			if (food[j].getFoodPicture() == 1) {
				SelectObject(hdcBmp, hbanana);//�㽶
				TransparentBlt(hdcBuffer, food[j].getPos(1), food[j].getPos(0) - 25, 25, 25, hdcBmp, 0, 0, 30, 30, RGB(255, 255, 255));
			}
			if (food[j].getFoodPicture() == 2) {
				SelectObject(hdcBmp, hgrape);//����
				TransparentBlt(hdcBuffer, food[j].getPos(1), food[j].getPos(0) - 25, 25, 25, hdcBmp, 0, 0, 30, 30, RGB(255, 255, 255));
			}
			if (food[j].getFoodPicture() == 3) {
				SelectObject(hdcBmp, hjar);//��ͷ
				TransparentBlt(hdcBuffer, food[j].getPos(1), food[j].getPos(0) - 25, 25, 25, hdcBmp, 0, 0, 30, 30, RGB(255, 255, 255));
			}
		}
	}
	if (crate.getCrateState() == 2) {
		SelectObject(hdcBmp, hcrate);
		TransparentBlt(hdcBuffer, crate.getPos(1), crate.getPos(0) - 19, 19, 19, hdcBmp, 0, 0, 48, 48, RGB(255, 255, 255));
	}
	//�������ױ�ըͼƬ
	if (m_shoulei.getShouLeiState() == 7) {
		SelectObject(hdcBmp, shouleiexplode.getShouLeiExplodehBmp());
		TransparentBlt(hdcBuffer, shouleiexplode.getShouLeiExplodePos(1) - shouleiexplode.getShouLeiExplodeSize(1) / 2, shouleiexplode.getShouLeiExplodePos(0) - shouleiexplode.getShouLeiExplodeSize(0) / 3, shouleiexplode.getShouLeiExplodeSize(1), shouleiexplode.getShouLeiExplodeSize(0), hdcBmp, m_shoulei.getShouLeiExplodePct() / 2 * 50, 0, 50, 50, RGB(255, 255, 255));
	}
	//���ƻ������ըͼƬ
	if (m_rocket.getRocketState() == 7) {
		SelectObject(hdcBmp, rocketexplode.getRocketExplodehBmp());
		TransparentBlt(hdcBuffer, rocketexplode.getRocketExplodePos(1) - rocketexplode.getRocketExplodeSize(1) / 2, rocketexplode.getRocketExplodePos(0) - rocketexplode.getRocketExplodeSize(0) / 3, rocketexplode.getRocketExplodeSize(1), rocketexplode.getRocketExplodeSize(0), hdcBmp, pictureBGM.getRocketExplodePct() / 2 * 85, 0, 85, 85, RGB(255, 255, 255));
	}
	if (boom.getBoomState() == 5) {//�񵯱�ը֡
		SelectObject(hdcBmp, rocketexplode.getRocketExplodehBmp());
		TransparentBlt(hdcBuffer, boom.getRocketPos(1) - 20, boom.getRocketPos(0) - 12, 80, 80, hdcBmp, gameStatus.getBoomPct() / 2 * 85, 0, 85, 85, RGB(255, 255, 255));
		if (gameStatus.getBoomPct() < 20) gameStatus.getBoomPct()++;
		if (gameStatus.getBoomPct() == 20) {//������
			gameStatus.getBoomPct() = 0;//����
			boom.getBoomState() = 6;
			gameStatus.getWeapon4Use() = 0;
		}

	}
	if (boom.getBoomState() == 2) {//������
		SelectObject(hdcBmp, hboom);
		TransparentBlt(hdcBuffer, boom.getRocketPos(1), boom.getRocketPos(0), 10, 20, hdcBmp, 0, 0, 29, 44, RGB(255, 255, 255));
	}
	if (gameStatus.getPlaneState() == 2) {
		SelectObject(hdcBmp, hplane);
		TransparentBlt(hdcBuffer, plane.getRocketPos(1), plane.getRocketPos(0), 250, 110, hdcBmp, 0, 0, 210, 107, RGB(255, 255, 255));
	}
	//����׼��
	if (m_zhunxin.getZhunXinState() == 1) {
		SelectObject(hdcBmp, m_zhunxin.getZhunXinhBmp());
		TransparentBlt(hdcBuffer, m_zhunxin.getZhunXinPos(1), m_zhunxin.getZhunXinPos(0), m_zhunxin.getZhunXinSize(1), m_zhunxin.getZhunXinSize(0), hdcBmp, 0, 0, 500, 500, RGB(255, 255, 255));
	}
	//���Ƽ���������
	if (gameStatus.getHeroSide() == 0) {
		if (m_force.getForceState() == 1) {
			linePen1 = CreatePen(PS_SOLID, 1, RGB(252, 13, 27));
			SelectObject(hdcBuffer, linePen1);
			HBRUSH Brush = CreateSolidBrush(RGB(252, 13, 27));
			SelectObject(hdcBuffer, Brush);
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2) {
				Pie(hdcBuffer,//���λ��� �Խ����ཻ
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2 + deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2,
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2 + deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2,
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 + 80 * cos(m_zhunxin.getZhunXinJiaoDu() - 0.2618) + deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() - 0.2618),
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 + 80 * cos(m_zhunxin.getZhunXinJiaoDu() + 0.2618) + deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() + 0.2618)
				);
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1) {
				Pie(hdcBuffer,
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2 - deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2,
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2 - deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2,
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 - 80 * cos(m_zhunxin.getZhunXinJiaoDu() + 0.2618) - deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() + 0.2618),
					team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)HERO_SIZE_X / 2 - 80 * cos(m_zhunxin.getZhunXinJiaoDu() - 0.2618) - deltax,
					team1[gameStatus.getHeroOrder1()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() - 0.2618)
				);
			}
			DeleteObject(Brush);
			DeleteObject(linePen1);
		}
	}
	//���Ƶз�������
	if (gameStatus.getHeroSide() == 1) {
		if (m_force.getForceState() == 1) {
			linePen1 = CreatePen(PS_SOLID, 1, RGB(42, 253, 132));
			SelectObject(hdcBuffer, linePen1);
			HBRUSH Brush = CreateSolidBrush(RGB(42, 253, 132));
			SelectObject(hdcBuffer, Brush);
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2) {
				Pie(hdcBuffer,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2 + deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2 + deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + 80 * cos(m_zhunxin.getZhunXinJiaoDu() - 0.2618) + deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() - 0.2618),
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + 80 * cos(m_zhunxin.getZhunXinJiaoDu() + 0.2618) + deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() + 0.2618)
				);
			}
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1) {
				Pie(hdcBuffer,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2 - deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - m_force.getLine() / 2,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2 - deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 + m_force.getLine() / 2,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - 80 * cos(m_zhunxin.getZhunXinJiaoDu() + 0.2618) - deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() + 0.2618),
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_X / 2 - 80 * cos(m_zhunxin.getZhunXinJiaoDu() - 0.2618) - deltax,
					team2[gameStatus.getHeroOrder2()].getHeroPos(0) + (float)HERO_SIZE_Y / 2 - 80 * sin(m_zhunxin.getZhunXinJiaoDu() - 0.2618)
				);
			}
			DeleteObject(Brush);
			DeleteObject(linePen1);
		}
	}
	//���� Ѫ���ſ�
	linePen1 = CreatePen(PS_SOLID, 3, RGB(252, 13, 27));
	brush = CreateSolidBrush(RGB(203, 41, 45));
	int start = camera.getCamera1Pos(1) + 360 * camera.getPro();
	SelectObject(hdcBuffer, brush);
	SelectObject(hdcBuffer, linePen1);
	for (j = 0; j < 3; j++) {
		Rectangle(hdcBuffer, start, camera.getCamera1Pos(0) + 30 * camera.getPro(), start + team1[j].getHeroLife() / 2 * camera.getPro(), camera.getCamera1Pos(0) + 70 * camera.getPro());
		start += (team1[j].getHeroLife() / 2 + 15) * camera.getPro();
	}
	DeleteObject(brush);
	DeleteObject(linePen1);
	SelectObject(hdcBmp, hred);
	TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 250 * camera.getPro(), camera.getCamera1Pos(0) + 20 * camera.getPro(), 80 * camera.getPro(), 60 * camera.getPro(), hdcBmp, 0, 0, 580, 420, RGB(255, 255, 255));
	//�з�
	start = camera.getCamera1Pos(1) + 360 * camera.getPro();
	linePen1 = CreatePen(PS_SOLID, 3, RGB(60, 203, 62));
	brush = CreateSolidBrush(RGB(51, 138, 89));
	SelectObject(hdcBuffer, brush);
	SelectObject(hdcBuffer, linePen1);
	for (j = 0; j < 3; j++) {
		Rectangle(hdcBuffer, start, camera.getCamera1Pos(0) + 90 * camera.getPro(), start + team2[j].getHeroLife() / 2 * camera.getPro(), camera.getCamera1Pos(0) + 130 * camera.getPro());
		start += (team2[j].getHeroLife() / 2 + 15) * camera.getPro();
	}
	DeleteObject(brush);
	DeleteObject(linePen1);
	SelectObject(hdcBmp, hgreen);
	TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 215 * camera.getPro(), camera.getCamera1Pos(0) + 80 * camera.getPro(), 120 * camera.getPro(), 60 * camera.getPro(), hdcBmp, 0, 0, 760, 400, RGB(255, 255, 255));
	//�������Ͻ�ͼ��
	SelectObject(hdcBmp, hframe);
	TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 5, camera.getCamera1Pos(0) + 5, 200 * camera.getPro(), 150 * camera.getPro(), hdcBmp, 0, 0, 400, 400, RGB(255, 255, 255));
	if (gameStatus.getHeroSide() == 0) {
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {//���
			SelectObject(hdcBmp, hrocketpicture);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 20 * camera.getPro(), camera.getCamera1Pos(0) + 25 * camera.getPro(), 160 * camera.getPro(), 100 * camera.getPro(), hdcBmp, 0, 0, 1919, 619, RGB(255, 255, 255));
		}
		else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0) {//����
			SelectObject(hdcBmp, hshouleipicture);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 25 * camera.getPro(), camera.getCamera1Pos(0) + 10 * camera.getPro(), 150 * camera.getPro(), 150 * camera.getPro(), hdcBmp, 0, 0, 1024, 1024, RGB(255, 255, 255));
		}
		else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2) {//������
			SelectObject(hdcBmp, htransitem);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 35 * camera.getPro(), camera.getCamera1Pos(0) + 30 * camera.getPro(), 140 * camera.getPro(), 100 * camera.getPro(), hdcBmp, 0, 0, 750, 547, RGB(255, 255, 255));
		}
		else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4) {//��Ϯ
			SelectObject(hdcBmp, airstrike);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 55 * camera.getPro(), camera.getCamera1Pos(0) + 30 * camera.getPro(), 100 * camera.getPro(), 100 * camera.getPro(), hdcBmp, 0, 0, 699, 800, RGB(255, 255, 255));
		}
	}
	if (gameStatus.getHeroSide() == 1) {//�з�
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
			SelectObject(hdcBmp, hrocketpicture);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 20, camera.getCamera1Pos(0) + 25, 160 * camera.getPro(), 100 * camera.getPro(), hdcBmp, 0, 0, 1919, 610, RGB(255, 255, 255));
		}
		else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0) {
			SelectObject(hdcBmp, hshouleipicture);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 20 * camera.getPro(), camera.getCamera1Pos(0) + 10 * camera.getPro(), 150 * camera.getPro(), 150 * camera.getPro(), hdcBmp, 0, 0, 1024, 1024, RGB(255, 255, 255));
		}
		else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2) {
			SelectObject(hdcBmp, htransitem);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 35 * camera.getPro(), camera.getCamera1Pos(0) + 30 * camera.getPro(), 140 * camera.getPro(), 100 * camera.getPro(), hdcBmp, 0, 0, 750, 547, RGB(255, 255, 255));
		}
		else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4) {
			SelectObject(hdcBmp, airstrike);
			TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 55 * camera.getPro(), camera.getCamera1Pos(0) + 30 * camera.getPro(), 100 * camera.getPro(), 100 * camera.getPro(), hdcBmp, 0, 0, 699, 800, RGB(255, 255, 255));
		}
	}
	//���Ʒ���
	SelectObject(hdcBmp, hwind);
	TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 570 * camera.getPro(), camera.getCamera1Pos(0) + 30 * camera.getPro(), 60 * camera.getPro(), 90 * camera.getPro(), hdcBmp, 0, 0, 110, 128, RGB(255, 255, 255));
	if (gameStatus.getWindVel() == 0) {
		SelectObject(hdcBmp, h0);
		TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 630 * camera.getPro(), camera.getCamera1Pos(0) + 65 * camera.getPro(), 40 * camera.getPro(), 40 * camera.getPro(), hdcBmp, 0, 0, 128, 128, RGB(255, 255, 255));
	}
	if (gameStatus.getWindVel() == 1 || gameStatus.getWindVel() == -1) {
		SelectObject(hdcBmp, h1);//�м���Ʒ��ٵȼ�
		TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 630 * camera.getPro(), camera.getCamera1Pos(0) + 65 * camera.getPro(), 40 * camera.getPro(), 40 * camera.getPro(), hdcBmp, 0, 0, 128, 128, RGB(255, 255, 255));
	}
	if (gameStatus.getWindVel() == 2 || gameStatus.getWindVel() == -2) {
		SelectObject(hdcBmp, h2);
		TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 620 * camera.getPro(), camera.getCamera1Pos(0) + 65 * camera.getPro(), 40 * camera.getPro(), 40 * camera.getPro(), hdcBmp, 0, 0, 128, 128, RGB(255, 255, 255));
	}
	if (gameStatus.getWindVel() == 1 || gameStatus.getWindVel() == 2) {
		for (j = 0; j < 3; j++) {
			SelectObject(hdcBmp, hwinddirection);
			TransparentBlt(hdcBuffer, WD[j].getPos(1), WD[j].getPos(0), 50, 35, hdcBmp, gameStatus.getWdTimes() / 4 * 150, 95, 150, 95, RGB(255, 255, 255));
		}
		gameStatus.getWdTimes()++;
		if (gameStatus.getWdTimes() == 8) gameStatus.getWdTimes() = 0;
	}
	if (gameStatus.getWindVel() == -1 || gameStatus.getWindVel() == -2) {
		for (j = 0; j < 3; j++) {
			SelectObject(hdcBmp, hwinddirection);
			TransparentBlt(hdcBuffer, WD[j].getPos(1), WD[j].getPos(0), 50, 35, hdcBmp, gameStatus.getWdTimes() / 4 * 150, 0, 150, 95, RGB(255, 255, 255));
		}
		gameStatus.getWdTimes()++;
		if (gameStatus.getWdTimes() == 8) gameStatus.getWdTimes() = 0;
	}
	if (gameStatus.getWindVel() == 0) {
		for (j = 0; j < 3; j++)
		{
			SelectObject(hdcBmp, hwdstill);
			TransparentBlt(hdcBuffer, WD[j].getPos(1), WD[j].getPos(0), 50, 35, hdcBmp, gameStatus.getWdTimes() / 4 * 150, 0, 145, 85, RGB(255, 255, 255));
		}
	}
	if (gameStatus.getAllover() == 1) {
		linePen1 = CreatePen(PS_SOLID, 1, RGB(255, 69, 0));
		brush = CreateSolidBrush(RGB(255, 69, 0));
		SelectObject(hdcBuffer, linePen1);
		SelectObject(hdcBuffer, brush);
		Rectangle(hdcBuffer, gameStatus.getEndLeft(), gameStatus.getEndTop(), gameStatus.getEndRight(), gameStatus.getEndBottom());
		DeleteObject(linePen1);
		DeleteObject(brush);
	}
	//���ƻغϵ���ʱ
	if (gameStatus.getRoundState() == 0)
	{
		SelectObject(hdcBmp, hnumber);
		TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 900 * camera.getPro(), camera.getCamera1Pos(0) + 700 * camera.getPro(), 80, 80, hdcBmp, (20 - gameStatus.getTimePast()) * 150, 0, 150, 150, RGB(255, 255, 255));
	}
	if (gameStatus.getRoundState() == 1) {
		SelectObject(hdcBmp, hnumber);
		TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 900 * camera.getPro(), camera.getCamera1Pos(0) + 700 * camera.getPro(), 80, 80, hdcBmp, (5 - gameStatus.getTimePast()) * 150, 0, 150, 150, RGB(255, 255, 255));
	}
	//back
	SelectObject(hdcBmp, pause);
	TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + bpause.getPos(1), camera.getCamera1Pos(0) + bpause.getPos(0), bpause.getSize(1) / 2, bpause.getSize(0) / 2, hdcBmp, 0, 0, 1153, 360, RGB(255, 255, 255));
	//����ͼ
	TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 700 * camera.getPro(), camera.getCamera1Pos(0) + 10 * camera.getPro(), 270 * camera.getPro(), 120 * camera.getPro(), hdcshrink, 0, 0, 1920, 1080, RGB(254, 254, 254));
	SelectObject(hdcBmp, hFrame2);
	TransparentBlt(hdcBuffer, camera.getCamera1Pos(1) + 685 * camera.getPro() + (float)(camera.getCamera1Pos(1)) / 1920.0 * 270 * camera.getPro(), camera.getCamera1Pos(0) + 3 * camera.getPro() + (float)(camera.getCamera1Pos(0)) / 1080.0 * 120 * camera.getPro(), 1000.0 / 1920.0 * 340.0 * camera.getPro(), 800.0 / 1080.0 * 150 * camera.getPro(), hdcBmp, 0, 0, 820, 580, RGB(255, 255, 255));
	// ���Ƶ���Ļ ������Դ
	TransparentBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, camera.getCamera1Pos(1), camera.getCamera1Pos(0), camera.getPro() * WNDWIDTH, camera.getPro() * WNDHEIGHT, RGB(254, 254, 254));
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);
	// ��������
	EndPaint(hWnd, &ps);
}
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	//�غϺ͸���ʱ��֡�ĸ���
	if (gameStatus.getRoundState() == 0 || gameStatus.getRoundState() == 1)  gameStatus.getRoundTime()++;
	if (m_shoulei.getShouLeiState() == 7 && m_shoulei.getShouLeiExplodePct() < 11) m_shoulei.getShouLeiExplodePct()++;
	if (m_shoulei.getShouLeiState() == 7 && m_shoulei.getShouLeiExplodePct() == 11)	m_shoulei.getShouLeiState() = 9;
	if (m_shoulei.getShouLeiState() == 4 && m_shoulei.getShouLeiWait() <= SHOULEIWAIT) 		m_shoulei.getShouLeiWait()++;
	if (m_shoulei.getShouLeiState() == 4 && m_shoulei.getShouLeiWait() == SHOULEIWAIT + 1)
		m_shoulei.getShouLeiState() = 2;
	if (gameStatus.getWindInterval() == WINDINTERVAL) {//����ﵽ���·�ĵȼ�
		WindUpdate();
		gameStatus.getWindInterval() = 0;
	}
	//���ʱ��֡�ƽ�
	if (m_rocket.getRocketState() == 7 && pictureBGM.getRocketExplodePct() < 20) pictureBGM.getRocketExplodePct()++;
	if (m_rocket.getRocketState() == 7 && pictureBGM.getRocketExplodePct() == 20) m_rocket.getRocketState() = 3;
	if (m_rocket.getRocketState() == 4)
		m_rocket.getRocketState() = 2;
	//ʳ��ʱ��֡�ƽ�
	if (gameStatus.getFoodTimes() == FOODINTERVAL) FoodUpdate();
	if (gameStatus.getFoodTimes() < FOODINTERVAL) gameStatus.getFoodTimes()++;
	if (pictureBGM.getSoundStart() == 0) {//��Ч����
		SoundUpdate();
		pictureBGM.getSoundStart() = 1;
	}
	if (gameStatus.getWeapon4Use() == 0 && gameStatus.getWeapon4State() == 0 && crate.getCrateState() == 0 && crate.getCrateTimes() < CRATEINTERVAL)
		crate.getCrateTimes()++;
	if (gameStatus.getWeapon4Use() == 0 && gameStatus.getWeapon4State() == 0 && crate.getCrateState() == 0 && crate.getCrateTimes() == CRATEINTERVAL) {
		crate.getCrateTimes() = 0;//��Ϯ����ʱ��֡�ƽ�
		crate.getCrateState() = 1;
	}
	if (gameStatus.getAllover() == 1)gameStatus.getEndTop()--;//��Ϸ����
	AI();
	Camera();
	ZhunXinUpdate();
	TerrianUpdate();
	ShouLeiDamage();
	ShouLeiMove();
	RocketDamage();
	RocketMove();
	BoomCrush();
	BoomUpdate();
	PlaneUpdate();
	CrateUpdate();
	HeroCrush();
	HeroFriction();
	HeroUpdate();
	JianTouUpdate();
	if (gameStatus.getJump() < INTERVALJUMP) gameStatus.getJump()++;
	TransUpdate();
	ShouLeiUpdate();
	RocketUpdate();
	if (m_force.getForceInterval() < INTERVALFORCE) m_force.getForceInterval()++;
	ShouLeiExplodeUpdate();
	RocketExplodeUpdate();
	HeroMotionUpdate();
	BloodDecrease();
	limit();
	RoundUpdate();
	InvalidateRect(hWnd, NULL, FALSE);
}

void SoundUpdate() {
	int random;
	random = rand() % 8;
	if (gameStatus.getHeroSide() == 0) {//������������
		if (random == 0)	mciSendString(TEXT("play res\\761.mp3"), NULL, 0, NULL);
		if (random == 1)  mciSendString(TEXT("play res\\762.mp3"), NULL, 0, NULL);
		if (random == 2)  mciSendString(TEXT("play res\\763.mp3"), NULL, 0, NULL);
		if (random == 3)  mciSendString(TEXT("play res\\764.mp3"), NULL, 0, NULL);
		if (random == 4)  mciSendString(TEXT("play res\\765.mp3"), NULL, 0, NULL);
		if (random == 5)  mciSendString(TEXT("play res\\766.mp3"), NULL, 0, NULL);
		if (random == 6)  mciSendString(TEXT("play res\\767.mp3"), NULL, 0, NULL);
		if (random == 7)  mciSendString(TEXT("play res\\768.mp3"), NULL, 0, NULL);
	}
	if (gameStatus.getHeroSide() == 1) {
		if (random == 0)	mciSendString(TEXT("play res\\m1.mp3"), NULL, 0, NULL);
		if (random == 1)  mciSendString(TEXT("play res\\m2.mp3"), NULL, 0, NULL);
		if (random == 2)  mciSendString(TEXT("play res\\m3.mp3"), NULL, 0, NULL);
		if (random == 3)  mciSendString(TEXT("play res\\m4.mp3"), NULL, 0, NULL);
		if (random == 4)  mciSendString(TEXT("play res\\m5.mp3"), NULL, 0, NULL);
		if (random == 5)  mciSendString(TEXT("play res\\m6.mp3"), NULL, 0, NULL);
		if (random == 6)  mciSendString(TEXT("play res\\m7.mp3"), NULL, 0, NULL);
		if (random == 7)  mciSendString(TEXT("play res\\m8.mp3"), NULL, 0, NULL);
	}
}

void ShouLeiUpdate() {
	//λ�ø���
	m_shoulei.getShouLeiPos(1) += m_shoulei.getShouLeiV(1);
	m_shoulei.getShouLeiPos(0) += m_shoulei.getShouLeiV(0);
	m_shoulei.getShouLeiV(1) += m_shoulei.getShouLeiA(1);
	m_shoulei.getShouLeiV(0) += m_shoulei.getShouLeiA(0);
	//��������
	if (gameStatus.getHeroSide() == 0) {
		if (m_shoulei.getShouLeiState() == 1) {
			m_shoulei.getShouLeiPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1);
			m_shoulei.getShouLeiPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0);
		}
		//��ֵ���ٶ�
		if (m_shoulei.getShouLeiState() == 0 && m_shoulei.getShouLeiState1() == 1) {
			m_shoulei.getShouLeiA(0) = SHOULEIGRAVITY;
			m_shoulei.getShouLeiV(1) += gameStatus.getWindVel();
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2) {//���������߻��ȷɳ�
				m_shoulei.getShouLeiV(1) = m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
				m_shoulei.getShouLeiV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1) {
				m_shoulei.getShouLeiV(1) = -m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
				m_shoulei.getShouLeiV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
			}
			m_shoulei.getShouLeiState1() = 0;
		}
		if (m_shoulei.getShouLeiState() == 0)	ShouLeiCrush();//������ײ��ʼ
		if (m_shoulei.getShouLeiState() == 4 || m_shoulei.getShouLeiState() == 2) {
			m_shoulei.getShouLeiV(1) = 0;
			m_shoulei.getShouLeiV(0) = 0;
			m_shoulei.getShouLeiA(1) = 0;
			m_shoulei.getShouLeiA(0) = 0;
		}
	}
	//�з�����
	if (gameStatus.getHeroSide() == 1) {
		if (m_shoulei.getShouLeiState() == 1) {
			m_shoulei.getShouLeiPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1);
			m_shoulei.getShouLeiPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0);
		}
		if (m_shoulei.getShouLeiState() == 0 && m_shoulei.getShouLeiState1() == 1) {
			m_shoulei.getShouLeiA(0) = SHOULEIGRAVITY;
			m_shoulei.getShouLeiV(1) += gameStatus.getWindVel();
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2) {
				m_shoulei.getShouLeiV(1) = m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
				m_shoulei.getShouLeiV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
			}
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1) {
				m_shoulei.getShouLeiV(1) = -m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
				m_shoulei.getShouLeiV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
			}
			m_shoulei.getShouLeiState1() = 0;
		}
		if (m_shoulei.getShouLeiState() == 0)	ShouLeiCrush();
		if (m_shoulei.getShouLeiState() == 4 || m_shoulei.getShouLeiState() == 2) {
			m_shoulei.getShouLeiV(1) = 0;
			m_shoulei.getShouLeiV(0) = 0;
			m_shoulei.getShouLeiA(1) = 0;
			m_shoulei.getShouLeiA(0) = 0;
		}
	}
}

void RocketUpdate() {
	m_rocket.getRocketPos(1) += m_rocket.getRocketV(1);
	m_rocket.getRocketPos(0) += m_rocket.getRocketV(0);
	m_rocket.getRocketV(1) += m_rocket.getRocketA(1);
	m_rocket.getRocketV(0) += m_rocket.getRocketA(0);

	//������� ͬ����
	if (gameStatus.getHeroSide() == 0) {
		if (m_rocket.getRocketState() == 1) {
			m_rocket.getRocketPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1);
			m_rocket.getRocketPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0);
		}
		if (m_rocket.getRocketState() == 0 && m_rocket.getRocketState1() == 1) {
			m_rocket.getRocketA(0) = ROCKETGRAVITY;
			m_rocket.getRocketV(1) += gameStatus.getWindVel();
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2) {
				m_rocket.getRocketV(1) = m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
				m_rocket.getRocketV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1) {
				m_rocket.getRocketV(1) = -m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
				m_rocket.getRocketV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 3.0;
			}
			m_rocket.getRocketState1() = 0;
		}
		if (m_rocket.getRocketState() == 0)	RocketCrush();
		if (m_rocket.getRocketState() == 4 || m_rocket.getRocketState() == 2) {
			m_rocket.getRocketV(1) = 0;
			m_rocket.getRocketV(0) = 0;
			m_rocket.getRocketA(1) = 0;
			m_rocket.getRocketA(0) = 0;
		}
	}
	if (gameStatus.getHeroSide() == 1) {//�з����
		if (m_rocket.getRocketState() == 1) {
			m_rocket.getRocketPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1);
			m_rocket.getRocketPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0);
		}
		//���¸����ٶȵĲ���ֻ��Ҫִ��һ�Σ�
		if (m_rocket.getRocketState() == 0 && m_rocket.getRocketState1() == 1) {
			m_rocket.getRocketA(0) = ROCKETGRAVITY;
			m_rocket.getRocketV(1) += gameStatus.getWindVel();
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2) {
				m_rocket.getRocketV(1) = m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 2.0;
				m_rocket.getRocketV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 2.0;
			}
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1) {
				m_rocket.getRocketV(1) = -m_force.getLine() * cos(m_zhunxin.getZhunXinJiaoDu()) / 2.0;
				m_rocket.getRocketV(0) = -m_force.getLine() * sin(m_zhunxin.getZhunXinJiaoDu()) / 2.0;
			}
			m_rocket.getRocketState1() = 0;
		}
		if (m_rocket.getRocketState() == 0)	RocketCrush();//�����ײ���ƿ�ʼ
		if (m_rocket.getRocketState() == 4 || m_rocket.getRocketState() == 2) {
			m_rocket.getRocketV(1) = 0;
			m_rocket.getRocketV(0) = 0;
			m_rocket.getRocketA(1) = 0;
			m_rocket.getRocketA(0) = 0;
		}
	}
}

void ZhunXinUpdate() {
	//����
	if (gameStatus.getHeroSide() == 0) {
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {
			m_zhunxin.getZhunXinJiaoDu() += m_zhunxin.getZhunXinW();
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2) {//���������������߱仯
				m_zhunxin.getZhunXinPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1) + (float)m_zhunxin.getZhunXinR() * cos(m_zhunxin.getZhunXinJiaoDu());
				m_zhunxin.getZhunXinPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0) - (float)m_zhunxin.getZhunXinR() * sin(m_zhunxin.getZhunXinJiaoDu());
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1) {
				m_zhunxin.getZhunXinPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1) - (float)m_zhunxin.getZhunXinR() * cos(m_zhunxin.getZhunXinJiaoDu());
				m_zhunxin.getZhunXinPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0) - (float)m_zhunxin.getZhunXinR() * sin(m_zhunxin.getZhunXinJiaoDu());
			}
		}
		else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4) {
			m_zhunxin.getZhunXinPos(1) += m_zhunxin.getZhunXinV(1);
			m_zhunxin.getZhunXinPos(0) += m_zhunxin.getZhunXinV(0);
		}
	}
	//�з�
	if (gameStatus.getHeroSide() == 1) {
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
			m_zhunxin.getZhunXinJiaoDu() += m_zhunxin.getZhunXinW();
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2) {
				m_zhunxin.getZhunXinPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1) + (float)m_zhunxin.getZhunXinR() * cos(m_zhunxin.getZhunXinJiaoDu());
				m_zhunxin.getZhunXinPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0) - (float)m_zhunxin.getZhunXinR() * sin(m_zhunxin.getZhunXinJiaoDu());
			}
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1) {
				m_zhunxin.getZhunXinPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1) - (float)m_zhunxin.getZhunXinR() * cos(m_zhunxin.getZhunXinJiaoDu());
				m_zhunxin.getZhunXinPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0) - (float)m_zhunxin.getZhunXinR() * sin(m_zhunxin.getZhunXinJiaoDu());
			}
		}
		else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4) {
			m_zhunxin.getZhunXinPos(1) += m_zhunxin.getZhunXinV(1);
			m_zhunxin.getZhunXinPos(0) += m_zhunxin.getZhunXinV(0);
		}
	}
}

void HeroUpdate()
{
	int i;
	//��������
	for (i = 0; i < 3; i++) {
		team1[i].getHeroVel(1) += team1[i].getHeroAcceration(1);
		team1[i].getHeroVel(0) += team1[i].getHeroAcceration(0);
		team1[i].getHeroPos(1) += team1[i].getHeroVel(1);
		team1[i].getHeroPos(0) += team1[i].getHeroVel(0);
		if (gameStatus.getAllover() == 1) {
			if (team1[i].getHeroPos(0) + HERO_SIZE_Y >= gameStatus.getEndTop())
				team1[i].getHeroLife() = 0;
		}
	}
	for (i = 0; i < 3; i++) {
		team2[i].getHeroVel(1) += team2[i].getHeroAcceration(1);
		team2[i].getHeroVel(0) += team2[i].getHeroAcceration(0);
		team2[i].getHeroPos(1) += team2[i].getHeroVel(1);
		team2[i].getHeroPos(0) += team2[i].getHeroVel(0);
		if (gameStatus.getAllover() == 1) {
			if (team2[i].getHeroPos(0) + HERO_SIZE_Y >= gameStatus.getEndTop())
				team2[i].getHeroLife() = 0;
		}
	}
	//�˳�Ѫ��/������
	if (gameStatus.getHeroSide() == 0) {
		for (i = 0; i < 6; i++)
			if (team1[gameStatus.getHeroOrder1()].getHeroPos(1) == food[i].getPos(1) && team1[gameStatus.getHeroOrder1()].getHeroPos(0) + 60 >= food[i].getPos(0) && food[i].getFoodState() == 1) {
				food[i].getFoodState() = 0;
				team1[gameStatus.getHeroOrder1()].getHeroLife() += 20;
			}
		if (team1[gameStatus.getHeroOrder1()].getHeroPos(1) == crate.getPos(1) && team1[gameStatus.getHeroOrder1()].getHeroPos(0) + 60 >= crate.getPos(0) && crate.getCrateState() == 2) {
			gameStatus.getWeapon4Side() = 0;
			gameStatus.getWeapon4Num() = gameStatus.getHeroOrder1();
			gameStatus.getWeapon4State() = 1;
			crate.getCrateState() = 0;
			gameStatus.getWeapon4Use() = 1;
		}
	}
	if (gameStatus.getHeroSide() == 1) {
		for (i = 0; i < 6; i++)
			if (team2[gameStatus.getHeroOrder2()].getHeroPos(1) == food[i].getPos(1) && team2[gameStatus.getHeroOrder2()].getHeroPos(0) + 60 >= food[i].getPos(0) && food[i].getFoodState() == 1) {
				food[i].getFoodState() = 0;
				team2[gameStatus.getHeroOrder2()].getHeroLife() += 20;
			}
		if (team2[gameStatus.getHeroOrder2()].getHeroPos(1) == crate.getPos(1) && team2[gameStatus.getHeroOrder2()].getHeroPos(0) + 60 >= crate.getPos(0) && crate.getCrateState() == 2) {
			gameStatus.getWeapon4Side() = 1;
			gameStatus.getWeapon4Num() = gameStatus.getHeroOrder2();
			gameStatus.getWeapon4State() = 1;
			crate.getCrateState() = 0;
			gameStatus.getWeapon4Use() = 1;
		}
	}
}

void TerrianUpdate() {
	//Բ�ӱ�ը������
	if (m_shoulei.getShouLeiState() == 2) {
		int i, j, y, x, k;
		for (i = m_shoulei.getShouLeiPos(1) - SHOULEIR; i <= m_shoulei.getShouLeiPos(1) + SHOULEIR; i++) {
			x = m_shoulei.getShouLeiPos(1) - i;
			y = sqrt(float(SHOULEIR) * float(SHOULEIR) - float(x) * (float)(x));//��һ��СԲ�ϵ�y����
			j = gameStatus.getTerrianSecond(i);
			for (k = 0; k < j; k++) {
				if (gameStatus.getTerrianState(i, k) == 1) {//�������������
					if (m_shoulei.getShouLeiPos(0) - y > m_terrian[i][k].getPos1(0)) {//ö�ٵؿ���е��β���
						if (m_terrian[i][k].getPos2(0) <= m_shoulei.getShouLeiPos(0) + y) {
							if (m_terrian[i][k].getPos2(0) > m_shoulei.getShouLeiPos(0) - y)
								m_terrian[i][k].getPos2(0) = m_shoulei.getShouLeiPos(0) - y;
						}
						else {//��������Ƕ���ȥ�͸��ѷָ�����µؿ�
							gameStatus.getTerrianState(i, gameStatus.getTerrianSecond(i)) = 1;
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos2(0) = m_terrian[i][k].getPos2(0);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos2(1) = m_terrian[i][k].getPos2(1);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos1(1) = m_terrian[i][k].getPos2(1);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos1(0) = m_shoulei.getShouLeiPos(0) + y;
							m_terrian[i][k].getPos2(0) = m_shoulei.getShouLeiPos(0) - y;
							gameStatus.getTerrianSecond(i)++;
						}
					}
					else {//�������������
						if (m_shoulei.getShouLeiPos(0) + y >= m_terrian[i][k].getPos2(0))//��������
							gameStatus.getTerrianState(i, k) = 0;
						else {
							if (m_terrian[i][k].getPos1(0) < m_shoulei.getShouLeiPos(0) + y)//��������
								m_terrian[i][k].getPos1(0) = m_shoulei.getShouLeiPos(0) + y;
						}
					}
				}
			}
		}
		gameStatus.getPaintAgain() = 1;	//�ػ�
		m_shoulei.getShouLeiState() = 6;//���β�������
	}
	if (m_rocket.getRocketState() == 2) {//ͬ����
		int i, j, y, x, k;
		for (i = m_rocket.getRocketPos(1) - ROCKETR; i <= m_rocket.getRocketPos(1) + ROCKETR; i++) {
			x = m_rocket.getRocketPos(1) - i;
			y = sqrt(float(ROCKETR) * float(ROCKETR) - float(x) * (float)(x));
			j = gameStatus.getTerrianSecond(i);
			for (k = 0; k < j; k++) {
				if (gameStatus.getTerrianState(i, k) == 1) {
					if (m_rocket.getRocketPos(0) - y > m_terrian[i][k].getPos1(0)) {
						if (m_terrian[i][k].getPos2(0) <= m_rocket.getRocketPos(0) + y) {
							if (m_terrian[i][k].getPos2(0) > m_rocket.getRocketPos(0) - y)
								m_terrian[i][k].getPos2(0) = m_rocket.getRocketPos(0) - y;
						}
						else {
							gameStatus.getTerrianState(i, gameStatus.getTerrianSecond(i)) = 1;
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos2(0) = m_terrian[i][k].getPos2(0);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos2(1) = m_terrian[i][k].getPos2(1);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos1(1) = m_terrian[i][k].getPos2(1);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos1(0) = m_rocket.getRocketPos(0) + y;
							m_terrian[i][k].getPos2(0) = m_rocket.getRocketPos(0) - y;
							gameStatus.getTerrianSecond(i)++;
						}
					}
					else {
						if (m_rocket.getRocketPos(0) + y >= m_terrian[i][k].getPos2(0))
							gameStatus.getTerrianState(i, k) = 0;
						else {
							if (m_terrian[i][k].getPos1(0) < m_rocket.getRocketPos(0) + y)
								m_terrian[i][k].getPos1(0) = m_rocket.getRocketPos(0) + y;
						}
					}
				}
			}
		}
		gameStatus.getPaintAgain() = 1;
		m_rocket.getRocketState() = 6;
	}

	if (boom.getBoomState() == 3) {//�񵯱�ը ͬ����
		int i, j, y, x, k;
		for (i = boom.getRocketPos(1) - BOOMR; i <= boom.getRocketPos(1) + BOOMR; i++) {
			x = boom.getRocketPos(1) - i;
			y = sqrt(float(BOOMR) * float(BOOMR) - float(x) * (float)(x));
			j = gameStatus.getTerrianSecond(i);
			for (k = 0; k < j; k++) {
				if (gameStatus.getTerrianState(i, k) == 1) {
					if (boom.getRocketPos(0) - y > m_terrian[i][k].getPos1(0)) {
						if (m_terrian[i][k].getPos2(0) <= boom.getRocketPos(0) + y) {
							if (m_terrian[i][k].getPos2(0) > boom.getRocketPos(0) - y)
								m_terrian[i][k].getPos2(0) = boom.getRocketPos(0) - y;
						}
						else {
							gameStatus.getTerrianState(i, gameStatus.getTerrianSecond(i)) = 1;
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos2(0) = m_terrian[i][k].getPos2(0);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos2(1) = m_terrian[i][k].getPos2(1);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos1(1) = m_terrian[i][k].getPos2(1);
							m_terrian[i][gameStatus.getTerrianSecond(i)].getPos1(0) = boom.getRocketPos(0) + y;
							m_terrian[i][k].getPos2(0) = boom.getRocketPos(0) - y;
							gameStatus.getTerrianSecond(i)++;
						}
					}
					else {
						if (boom.getRocketPos(0) + y >= m_terrian[i][k].getPos2(0))
							gameStatus.getTerrianState(i, k) = 0;
						else {
							if (m_terrian[i][k].getPos1(0) < boom.getRocketPos(0) + y)
								m_terrian[i][k].getPos1(0) = boom.getRocketPos(0) + y;
						}
					}
				}
			}
		}
		boom.getBoomState() = 4;
		gameStatus.getPaintAgain() = 1;
	}


}

bool ButtonClicked(POINT ptMouse, POINT buttonPos, SIZE buttonSize) {//�����Ƿ��� �жϵ��Ƿ���һ�������ڲ�
	RECT rectButton;
	rectButton.left = buttonPos.x;
	rectButton.top = buttonPos.y;
	rectButton.right = buttonPos.x + buttonSize.cx;
	rectButton.bottom = buttonPos.y + buttonSize.cy;
	return PtInRect(&rectButton, ptMouse);
}

void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	if (ai.getAIstate() == 0 || (ai.getAIstate() == 1 && gameStatus.getHeroSide() == 0)) {
		switch (wParam) {
		case ' '://��Ծ
			Spacedown();
			break;
		case '1'://����
			if (gameStatus.getHeroSide() == 0)  team1[gameStatus.getHeroOrder1()].getHeroWeapon() = 0;
			if (gameStatus.getHeroSide() == 1)team2[gameStatus.getHeroOrder2()].getHeroWeapon() = 0;
			break;
		case '2'://���
			if (gameStatus.getHeroSide() == 0)  team1[gameStatus.getHeroOrder1()].getHeroWeapon() = 1;
			if (gameStatus.getHeroSide() == 1)team2[gameStatus.getHeroOrder2()].getHeroWeapon() = 1;
			break;
		case '3'://������
			if (gameStatus.getHeroSide() == 0) team1[gameStatus.getHeroOrder1()].getHeroWeapon() = 2;
			if (gameStatus.getHeroSide() == 1) team2[gameStatus.getHeroOrder2()].getHeroWeapon() = 2;
			break;
		case '4'://��Ϯ
			if (gameStatus.getWeapon4State() == 1) {
				if (gameStatus.getHeroSide() == 0 && gameStatus.getWeapon4Side() == 0)
					team1[gameStatus.getWeapon4Num()].getHeroWeapon() = 4;
				else if (gameStatus.getHeroSide() == 1 && gameStatus.getWeapon4Side() == 1)
					team2[gameStatus.getWeapon4Num()].getHeroWeapon() = 4;
			}
			break;
		case 'A'://�����ƶ�
			Adown();
			break;
		case 'D'://�����ƶ�
			Ddown();
			break;
		case 'F'://׼������
			if (gameStatus.getRoundState() == 0) {//�����غϵ�ʱ��
				if (m_zhunxin.getZhunXinState() == 0) {
					if (gameStatus.getHeroSide() == 0)
						if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4) {
							m_zhunxin.getZhunXinPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1);//׼�ĳ���
							m_zhunxin.getZhunXinPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0);
						}
					if (gameStatus.getHeroSide() == 1)
						if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4) {
							m_zhunxin.getZhunXinPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1);
							m_zhunxin.getZhunXinPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0);
						}
					m_zhunxin.getZhunXinState() = 1;
					break;
				}
				if (m_zhunxin.getZhunXinState() == 1) {//��ʧ
					m_zhunxin.getZhunXinState() = 0;
					break;
				}
			}
			break;
		case 'L'://�������
			if (camera.getPro() < 1.2) camera.getPro() += 0.2;
			if (camera.getCameraPos(0) + camera.getPro() * WNDHEIGHT >= 1080)
				camera.getCameraPos(0) = 1080 - camera.getPro() * WNDHEIGHT;
			if (camera.getCameraPos(1) + camera.getPro() * WNDWIDTH >= 1920)
				camera.getCameraPos(1) = 1920 - camera.getPro() * WNDWIDTH;
			break;
		case 'K'://���ٱ���
			if (camera.getPro() > 0.8)	camera.getPro() -= 0.2;
			break;
		case 'P'://������ͣ����
			gameStatus.getGameStatus() = 7;
			break;
		case VK_ESCAPE://�����غ�
			gameStatus.getSkip() = 1;
			m_zhunxin.getZhunXinState() = 0;
			break;
		case VK_UP://
			if (m_zhunxin.getZhunXinState() == 1) {
				if (gameStatus.getHeroSide() == 0) {
					if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {
						m_zhunxin.getZhunXinW() = 0.02;//���ٶ����������ƶ�
						if (m_zhunxin.getZhunXinJiaoDu() >= 1.5707)
							m_zhunxin.getZhunXinW() = 0;
					}
					else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4)
						m_zhunxin.getZhunXinV(0) = -5;//׼�������ƶ�
				}
				if (gameStatus.getHeroSide() == 1) {
					if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
						m_zhunxin.getZhunXinW() = 0.02;
						if (m_zhunxin.getZhunXinJiaoDu() >= 1.5707)
							m_zhunxin.getZhunXinW() = 0;
					}
					else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4)
						m_zhunxin.getZhunXinV(0) = -5;
				}
			}
			if (m_zhunxin.getZhunXinState() == 0 && m_force.getForceState() == 0) {
				camera.getControl() = 1;
				if (camera.getCamera1Pos(0) > 0)
					camera.getCamera1Pos(0) -= CAMERASPEED;
				else if (camera.getCamera1Pos(0) < 0)
					camera.getCamera1Pos(0) = 0;
			}
			break;
		case VK_DOWN:
			if (m_zhunxin.getZhunXinState() == 1) {//ͬ��
				if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {
					m_zhunxin.getZhunXinW() = -0.02;
					if (m_zhunxin.getZhunXinJiaoDu() >= 1.5707)
						m_zhunxin.getZhunXinW() = 0;
				}
				else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4)
					m_zhunxin.getZhunXinV(0) = 5;

				if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
					m_zhunxin.getZhunXinW() = -0.02;
					if (m_zhunxin.getZhunXinJiaoDu() >= 1.5707)
						m_zhunxin.getZhunXinW() = 0;
				}
				else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4)
					m_zhunxin.getZhunXinV(0) = 5;
			}
			if (m_zhunxin.getZhunXinState() == 0 && m_force.getForceState() == 0) {
				camera.getControl() = 1;
				if (camera.getCamera1Pos(0) + WNDHEIGHT * camera.getPro() < 1080)
					camera.getCamera1Pos(0) += CAMERASPEED;
				else if (camera.getCamera1Pos(0) + WNDHEIGHT * camera.getPro() > 1080)
					camera.getCamera1Pos(0) = 1440 - WNDHEIGHT * camera.getPro();
			}
			break;
		case VK_RIGHT://�Ҽ���������׼���ƶ��ж�
			Forcevkrightdown();
			break;
		case VK_LEFT://���ͬ��
			Forcevkleftdown();
			break;
		case VK_RETURN://��Ϯ�ʹ����Żس��µĲ���
			if (gameStatus.getHeroSide() == 0) {
				if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 && m_zhunxin.getZhunXinState() == 1) {
					m_zhunxin.getZhunXinState() = 0;
					transmitGate.getTranState() = 1;
					m_zhunxin.getZhunXinV(1) = 0;
					m_zhunxin.getZhunXinV(0) = 0;
				}//�����źͿ�Ϯ׼���ж�
				else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4 && m_zhunxin.getZhunXinState() == 1) {
					m_zhunxin.getZhunXinState() = 0;
					gameStatus.getPlaneState() = 1;
					gameStatus.getTarget() = m_zhunxin.getZhunXinPos(1);
				}
			}
			if (gameStatus.getHeroSide() == 1) {
				if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 && m_zhunxin.getZhunXinState() == 1) {
					m_zhunxin.getZhunXinState() = 0;
					transmitGate.getTranState() = 1;
					m_zhunxin.getZhunXinV(1) = 0;
					m_zhunxin.getZhunXinV(0) = 0;
				}
				else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4 && m_zhunxin.getZhunXinState() == 1) {
					m_zhunxin.getZhunXinState() = 0;
					gameStatus.getPlaneState() = 1;
					gameStatus.getTarget() = m_zhunxin.getZhunXinPos(1);
				}
			}
			break;
		default:    break;
		}
	}
}

void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	//�����ɿ�
	if (ai.getAIstate() == 0 || (ai.getAIstate() == 1 && gameStatus.getHeroSide() == 0)) {
		switch (wParam) {
		case ' ':
			break;
		case 'F':
			break;
		case 'A':
			Aup();
			break;
		case 'D':
			Dup();
			break;
		case VK_UP:
			camera.getControl() = 0;
			m_zhunxin.getZhunXinW() = 0;
			m_zhunxin.getZhunXinV(0) = 0;
			break;
		case VK_DOWN:
			camera.getControl() = 0;
			m_zhunxin.getZhunXinW() = 0;
			m_zhunxin.getZhunXinV(0) = 0;
			break;
		case VK_RIGHT:
			Forcevkrightup();
			break;
		case VK_LEFT:
			Forcevkleftup();
			break;
		default:
			break;
		}
	}
}

void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	//�������
	POINT ptMouse; // �����������
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);
	if (gameStatus.getGameStatus() == 0 && ButtonClicked(ptMouse, m_gameStartButton.getpos(), m_gameStartButton.getsize())) {
		//�˵��е㵽����ģʽ
		KillTimer(hWnd, TIMER_ID);
		gameStatus.getGameStatus() = 1;
		InvalidateRect(hWnd, NULL, TRUE);//�ػ�����������
	}
	else if (gameStatus.getGameStatus() == 0 && ButtonClicked(ptMouse, bversus.getpos(), bversus.getsize())) {
		//�˵���˫��ģʽ
		KillTimer(hWnd, TIMER_ID);
		gameStatus.getGameStatus() = 9;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 9 && ButtonClicked(ptMouse, scene11.getpos(), scene11.getsize())) {
		//˫��ģʽ�����һ�ŵ�ͼ
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);//���ö�ʱ��
		ai.getAIstate() = 0;
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getRestartState() = 1;
			gameStatus.getGameStatus() = 2;
		}
		else if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 2;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 9 && ButtonClicked(ptMouse, scene21.getpos(), scene21.getsize())) {
		ai.getAIstate() = 0;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getGameStatus() = 3;
			gameStatus.getRestartState() = 1;
		}
		if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 3;
		}
		InvalidateRect(hWnd, NULL, TRUE);//������������ΪTRUE���ػ�����������
	}
	else if (gameStatus.getGameStatus() == 9 && ButtonClicked(ptMouse, scene31.getpos(), scene31.getsize())) {
		ai.getAIstate() = 0;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getGameStatus() = 4;
			gameStatus.getRestartState() = 1;
		}
		if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 4;
		}
		InvalidateRect(hWnd, NULL, TRUE);//������������ΪTRUE���ػ�����������
	}
	else if (gameStatus.getGameStatus() == 9 && ButtonClicked(ptMouse, scene41.getpos(), scene41.getsize())) {
		ai.getAIstate() = 0;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getGameStatus() = 5;
			gameStatus.getRestartState() = 1;
		}
		if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 5;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 9 && ButtonClicked(ptMouse, back1.getpos(), back1.getsize())) {
		KillTimer(hWnd, TIMER_ID);
		gameStatus.getGameStatus() = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 2 && ButtonClicked(ptMouse, bpause.getpos(), bpause.getsize())) {
		gameStatus.getGameStatus() = 7;//��ͼ�°�����ͣ��
		gameStatus.getGameStatusJustNow() = 2;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 0 && ButtonClicked(ptMouse, help.getpos(), help.getsize())) {
		KillTimer(hWnd, TIMER_ID);
		gameStatus.getGameStatus() = 6;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 0 && ButtonClicked(ptMouse, bexit.getpos(), bexit.getsize()))
		PostQuitMessage(0);
	else if (gameStatus.getGameStatus() == 1 && ButtonClicked(ptMouse, scene1.getpos(), scene1.getsize())) {
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		ai.getAIstate() = 1;
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getRestartState() = 1;
			gameStatus.getGameStatus() = 2;
		}
		else if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 2;
		}
		InvalidateRect(hWnd, NULL, TRUE);//������������ΪTRUE���ػ�����������
	}
	else if (gameStatus.getGameStatus() == 1 && ButtonClicked(ptMouse, scene2.getpos(), scene2.getsize())) {
		ai.getAIstate() = 1;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getGameStatus() = 3;
			gameStatus.getRestartState() = 1;
		}
		if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 3;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 1 && ButtonClicked(ptMouse, scene3.getpos(), scene3.getsize())) {
		ai.getAIstate() = 1;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getGameStatus() = 4;
			gameStatus.getRestartState() = 1;
		}
		if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 4;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 1 && ButtonClicked(ptMouse, scene4.getpos(), scene4.getsize())) {
		ai.getAIstate() = 1;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		if (gameStatus.getRestartState() == 0) {
			gameStatus.getGameStatus() = 5;
			gameStatus.getRestartState() = 1;
		}
		if (gameStatus.getRestartState() == 1) {
			Restart();
			gameStatus.getGameStatus() = 5;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 1 && ButtonClicked(ptMouse, back.getpos(), back.getsize())) {
		KillTimer(hWnd, TIMER_ID);
		gameStatus.getGameStatus() = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 2 && ButtonClicked(ptMouse, bpause.getpos(), bpause.getsize())) {
		gameStatus.getGameStatus() = 7;
		gameStatus.getGameStatusJustNow() = 2;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 3 && ButtonClicked(ptMouse, bpause.getpos(), bpause.getsize())) {
		gameStatus.getGameStatus() = 7;
		gameStatus.getGameStatusJustNow() = 3;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 4 && ButtonClicked(ptMouse, bpause.getpos(), bpause.getsize())) {
		gameStatus.getGameStatus() = 7;
		gameStatus.getGameStatusJustNow() = 4;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 5 && ButtonClicked(ptMouse, bpause.getpos(), bpause.getsize())) {
		gameStatus.getGameStatus() = 7;
		gameStatus.getGameStatusJustNow() = 5;
		InvalidateRect(hWnd, NULL, TRUE);
	}//��help���淵��
	else if (gameStatus.getGameStatus() == 6 && ButtonClicked(ptMouse, back.getpos(), back.getsize())) {
		gameStatus.getGameStatus() = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 6 && ButtonClicked(ptMouse, bnext.getpos(), bnext.getsize())) {
		gameStatus.getGameStatus() = 8;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 8 && ButtonClicked(ptMouse, back.getpos(), back.getsize())) {
		gameStatus.getGameStatus() = 6;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 7 && ButtonClicked(ptMouse, back.getpos(), back.getsize())) {
		ai.getAIstate() = -1;
		gameStatus.getGameStatus() = 0;//��ͣ�����з���
		pictureBGM.getEndPage() = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 7 && ButtonClicked(ptMouse, bresume.getpos(), bresume.getsize()) && gameStatus.getGameEnd() == 0) {
		pictureBGM.getEndPage() = 0;
		gameStatus.getGameStatus() = gameStatus.getGameStatusJustNow();
		gameStatus.getGameStatusJustNow() = 0;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (gameStatus.getGameStatus() == 7 && ButtonClicked(ptMouse, brestart.getpos(), brestart.getsize())) {
		pictureBGM.getEndPage() = 0;
		InvalidateRect(hWnd, NULL, TRUE);
		Restart();
		gameStatus.getGameStatus() = gameStatus.getGameStatusJustNow();
		gameStatus.getGameStatusJustNow() = 0;
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		Render(hWnd);//������ͣ�е����restart,�ػ�
	}
}

void Adown() {//�����ƶ�
	int i, j;
	if (gameStatus.getHeroSide() == 0 && (gameStatus.getRoundState() == 0 || gameStatus.getRoundState() == 1) && gameStatus.getThrowState() == 0) {
		if (m_force.getForceState() == 0) {//�������׵�ʱ��
			m_zhunxin.getZhunXinState() = 0;
			team1[gameStatus.getHeroOrder1()].getHeroMotionState() = 1;
			team1[gameStatus.getHeroOrder1()].getHeroRunState() = 1;
			team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian() = -1;
			team1walk[gameStatus.getHeroOrder1()].getHeroPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0);
			team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1) - 1;
			while (1) {//��һ������ģ���ƶ�ֱ���ȵ��ؿ�
				team1walk[gameStatus.getHeroOrder1()].getHeroPos(0) += 10;//ѭ���ı�y
				for (i = 0; i < gameStatus.getTerrianSecond(team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot); i++) {
					if (gameStatus.getTerrianState(team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot, i) != 0) {
						if ((team1walk[gameStatus.getHeroOrder1()].getHeroPos(0) + HERO_SIZE_Y) < m_terrian[team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][i].getPos2(0))
							if (team1walk[gameStatus.getHeroOrder1()].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][i].getPos1(0)) {
								team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian() = i;//ȷ��ģ��ȵ��ĵؿ�
							}
					}
				}
				if (team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian() != -1) break;
			}
			if (m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) - 1 + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0) >= m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0))
				team1[gameStatus.getHeroOrder1()].getHeroVel(1) = -1;//�������¼���
			else if (m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0) - m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) - 1 + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0) <= 3)
				team1[gameStatus.getHeroOrder1()].getHeroVel(1) = -1;//���Ǻܶ������¾�����ȥ
			else team1[gameStatus.getHeroOrder1()].getHeroVel(1) = 0;
		}
	}
	//�з�����
	if (gameStatus.getHeroSide() == 1 && (gameStatus.getRoundState() == 0 || gameStatus.getRoundState() == 1)) {
		if (m_force.getForceState() == 0) {//ͬ��
			m_zhunxin.getZhunXinState() = 0;
			team2[gameStatus.getHeroOrder2()].getHeroRunState() = 1;
			team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 1;
			team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian() = -1;
			team2walk[gameStatus.getHeroOrder2()] = team2[gameStatus.getHeroOrder2()];
			team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1) - 1;
			while (1) {
				team2walk[gameStatus.getHeroOrder2()].getHeroPos(0) += 10;
				for (i = 0; i < gameStatus.getTerrianSecond(team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot); i++) {
					if (gameStatus.getTerrianState(team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot, i) != 0) {
						if ((team2walk[gameStatus.getHeroOrder2()].getHeroPos(0) + HERO_SIZE_Y) < m_terrian[team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][i].getPos2(0))
							if (team2walk[gameStatus.getHeroOrder2()].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][i].getPos1(0))
								team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian() = i;
					}
				}
				if (team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian() != -1) break;
			}
			if (m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) - 1 + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0) >= m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0))
				team2[gameStatus.getHeroOrder2()].getHeroVel(1) = -1;
			else if (m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0) - m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) - 1 + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0) <= 3)
				team2[gameStatus.getHeroOrder2()].getHeroVel(1) = -1;
			else team2[gameStatus.getHeroOrder2()].getHeroVel(1) = 0;

		}
	}
}
void Ddown() {//ͬA��
	//����
	int i;
	if (gameStatus.getHeroSide() == 0 && (gameStatus.getRoundState() == 0 || gameStatus.getRoundState() == 1) && gameStatus.getThrowState() == 0) {
		if (m_force.getForceState() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			team1[gameStatus.getHeroOrder1()].getHeroRunState() = 2;
			team1[gameStatus.getHeroOrder1()].getHeroMotionState() = 1;
			team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian() = -1;
			team1walk[gameStatus.getHeroOrder1()] = team1[gameStatus.getHeroOrder1()];
			team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1) + 1;
			while (1) {
				team1walk[gameStatus.getHeroOrder1()].getHeroPos(0) += 10;
				for (i = 0; i < gameStatus.getTerrianSecond(team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot); i++) {
					if (gameStatus.getTerrianState(team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot, i) != 0) {
						if ((team1walk[gameStatus.getHeroOrder1()].getHeroPos(0) + HERO_SIZE_Y) < m_terrian[team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][i].getPos2(0))
							if (team1walk[gameStatus.getHeroOrder1()].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team1walk[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][i].getPos1(0))
								team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian() = i;
					}
				}
				if (team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian() != -1) break;
			}
			if (m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) + 1 + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0) >= m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0))
				team1[gameStatus.getHeroOrder1()].getHeroVel(1) = 1;
			else if (m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0) - m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) + 1 + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0) <= 3)
				team1[gameStatus.getHeroOrder1()].getHeroVel(1) = 1;
			else team1[gameStatus.getHeroOrder1()].getHeroVel(1) = 0;
		}
	}
	//�з�
	if (gameStatus.getHeroSide() == 1 && (gameStatus.getRoundState() == 0 || gameStatus.getRoundState() == 1)) {
		if (m_force.getForceState() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			team2[gameStatus.getHeroOrder2()].getHeroRunState() = 2;
			team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 1;
			team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian() = -1;
			team2walk[gameStatus.getHeroOrder2()] = team2[gameStatus.getHeroOrder2()];
			team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1) + 1;
			while (1) {
				team2walk[gameStatus.getHeroOrder2()].getHeroPos(0) += 10;
				for (i = 0; i < gameStatus.getTerrianSecond(team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot); i++) {
					if (gameStatus.getTerrianState(team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot, i) != 0) {
						if ((team2walk[gameStatus.getHeroOrder2()].getHeroPos(0) + HERO_SIZE_Y) < m_terrian[team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][i].getPos2(0))
							if (team2walk[gameStatus.getHeroOrder2()].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team2walk[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][i].getPos1(0))
								team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian() = i;
					}
				}
				if (team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian() != -1) break;
			}
			if (m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) + 1 + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0) >= m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0))
				team2[gameStatus.getHeroOrder2()].getHeroVel(1) = 1;
			else if (m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0) - m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) + 1 + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0) <= 3)
				team2[gameStatus.getHeroOrder2()].getHeroVel(1) = 1;
			else team2[gameStatus.getHeroOrder2()].getHeroVel(1) = 0;
		}
	}
}
void Spacedown()//��Ծ
{
	//����
	if (gameStatus.getHeroSide() == 0 && gameStatus.getRoundState() == 0) {
		if (m_force.getForceState() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			if (team1[gameStatus.getHeroOrder1()].getHeroPos(0) >= m_terrian[team1[gameStatus.getHeroOrder1()].getHeroPos(1) + LeftFoot][team1[gameStatus.getHeroOrder1()].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y && gameStatus.getJump() == INTERVALJUMP && gameStatus.getThrowState() == 0 && gameStatus.getLaunchState() == 0) {
				team1[gameStatus.getHeroOrder1()].getHeroVel(0) = -HERO_VEL_Y;//����ֱ����һ�����ٶ�
				gameStatus.getJump() = 0;
			}
		}
	}
	//�з�
	if (gameStatus.getHeroSide() == 1 && gameStatus.getRoundState() == 0) {
		if (m_force.getForceState() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			if (team2[gameStatus.getHeroOrder2()].getHeroPos(0) >= m_terrian[team2[gameStatus.getHeroOrder2()].getHeroPos(1) + LeftFoot][team2[gameStatus.getHeroOrder2()].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y && gameStatus.getJump() == INTERVALJUMP) {
				team2[gameStatus.getHeroOrder2()].getHeroVel(0) = -HERO_VEL_Y;
				gameStatus.getJump() = 0;
			}
		}
	}
}
void Aup() {
	//����
	if (gameStatus.getHeroSide() == 0) {//�ɿ���ʱ��ֹͣ
		if (m_force.getForceState() == 0) {
			team1[gameStatus.getHeroOrder1()].getHeroMotionState() = 0;
			team1[gameStatus.getHeroOrder1()].getHeroTimes() = 1;
			team1[gameStatus.getHeroOrder1()].getHeroVel(1) = 0;
		}
	}
	//�з�
	if (gameStatus.getHeroSide() == 1) {
		if (m_force.getForceState() == 0) {
			team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 0;
			team2[gameStatus.getHeroOrder2()].getHeroTimes() = 4;
			team2[gameStatus.getHeroOrder2()].getHeroVel(1) = 0;
		}
	}
}
void Dup() {
	//����
	if (gameStatus.getHeroSide() == 0) {
		if (m_force.getForceState() == 0) {
			team1[gameStatus.getHeroOrder1()].getHeroMotionState() = 0;
			team1[gameStatus.getHeroOrder1()].getHeroTimes() = 1;
			team1[gameStatus.getHeroOrder1()].getHeroVel(1) = 0;
		}
	}
	//�з�
	if (gameStatus.getHeroSide() == 1) {
		if (m_force.getForceState() == 0) {
			team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 0;
			team2[gameStatus.getHeroOrder2()].getHeroTimes() = 4;
			team2[gameStatus.getHeroOrder2()].getHeroVel(1) = 0;
		}
	}
}
//���δ�������
void CreateMap1(int posleft, int posright, int postop, int posbottom, int maxR, int maxC, int range, int start, int num) {
	//����һ��
	int i, j, k, ran[100], R[100];
	for (i = posleft; i <= posright; i++) {
		m_terrian[i][gameStatus.getTerrianSecond(i)].CreateTerrian(i, postop, i, posbottom, NULL);
		gameStatus.getTerrianState(i, gameStatus.getTerrianSecond(i)) = 1;
		gameStatus.getTerrianSecond(i)++;
	}
	ran[0] = rand();
	for (i = 1; i <= maxC; i++) {//�����Բ������뾶
		ran[i] = rand();
		R[i] = ran[i] % maxR + 100;
		ran[i] %= range + start;
	}
	for (i = posleft; i <= posright; i++)
		for (j = 1; j <= maxC; j++)
			if (m_terrian[i][num].getPos1(1) == ran[j]) {
				if (abs(ran[j] - ran[j - 1]) < 60)	continue;
				int x, y;
				for (k = ran[j] - sqrt((float)R[j] * (float)R[j] - 10000); k < ran[j] + sqrt((float)R[j] * (float)R[j] - 10000); k++) {
					x = ran[j] - k;
					y = sqrt((float)R[j] * (float)R[j] - (float)x * (float)x);
					if (k > posleft && k < posright)//��������
						m_terrian[k][num].CreateTerrian(k, m_terrian[k][num].getPos1(0) - y + 100, k, posbottom, NULL);
					else
						continue;
				}
			}
	return;
}

void CreateMap3(int posleft, int posright, int postop, int posbottom, int maxR, int maxC, int range, int start, int num) {
	//������������´���
	int i, j, k, ran[100], R[100];
	for (i = posleft; i <= posright; i++) {
		m_terrian[i][gameStatus.getTerrianSecond(i)].CreateTerrian(i, postop, i, posbottom, NULL);
		gameStatus.getTerrianState(i, gameStatus.getTerrianSecond(i)) = 1;
		gameStatus.getTerrianSecond(i)++;
	}
	ran[0] = rand();
	for (i = 1; i <= maxC; i++) {
		ran[i] = rand();
		R[i] = ran[i] % maxR + 100;
		ran[i] %= range + start;
	}
	for (i = posleft; i <= posright; i++)
		for (j = 1; j <= maxC; j++)
			if (m_terrian[i][num].getPos1(1) == ran[j]) {
				if (abs(ran[j] - ran[j - 1]) < 60)	continue;
				int x, y;
				for (k = ran[j] - sqrt((float)R[j] * (float)R[j] - 10000); k < ran[j] + sqrt((float)R[j] * (float)R[j] - 10000); k++) {
					x = ran[j] - k;
					y = sqrt((float)R[j] * (float)R[j] - (float)x * (float)x);
					if (k > posleft && k < posright)
						m_terrian[k][num].CreateTerrian(k, m_terrian[k][num].getPos1(0) - y + 100, k, posbottom, NULL);
					else
						continue;
				}
			}
	ran[0] = rand();
	for (i = 1; i <= maxC; i++) {
		ran[i] = rand();
		R[i] = ran[i] % 20 + 20;
		ran[i] %= range + start;
	}
	for (i = posleft; i <= posright; i++)
		for (j = 1; j <= maxC; j++)
			if (m_terrian[i][num].getPos1(1) == ran[j]) {
				if (abs(ran[j] - ran[j - 1]) < 60)	continue;
				int x, y;
				for (k = ran[j] - sqrt((float)R[j] * (float)R[j] - 100); k < ran[j] + sqrt((float)R[j] * (float)R[j] - 100); k++) {
					x = ran[j] - k;
					y = sqrt((float)R[j] * (float)R[j] - (float)x * (float)x);
					if (k > posleft && k < posright)
						m_terrian[k][num].getPos2(0) = m_terrian[k][num].getPos2(0) - y + 10;
					else   	continue;
				}
			}
	return;
}

void CreateMap2(int posleft, int posright, int postop, int posdown) {//�ҽ�����
	int i;
	for (i = posleft; i < posright; i++) {
		gameStatus.getTerrianState(i, gameStatus.getTerrianSecond(i)) = -1;
		m_terrian[i][gameStatus.getTerrianSecond(i)].CreateTerrian(i, postop, i, posdown, NULL);
		gameStatus.getTerrianSecond(i)++;
	}
}

void Forcevkrightdown() {//��ס�Ҽ�ʱ�������任
	if (gameStatus.getHeroSide() == 0) {
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {
			if (m_zhunxin.getZhunXinState() == 1 && team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2) {
				m_zhunxin.getZhunXinState() = 0;//�������׻��߻����ʱ�� ���������� ׼����ʧ
				m_force.getForceState() = 1;
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2 && m_force.getForceState() == 1)
				if (m_force.getForceInterval() == INTERVALFORCE && m_force.getLine() <= MAXLINE - FORCESPEED) {
					m_force.getLine() += FORCESPEED;//����
					m_force.getForceInterval() = 0;
				}
		}
		else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = 5;
	}

	if (gameStatus.getHeroSide() == 1) {
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
			if (m_zhunxin.getZhunXinState() == 1 && team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2) {
				m_zhunxin.getZhunXinState() = 0;
				m_force.getForceState() = 1;
			}
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2 && m_force.getForceState() == 1)
				if (m_force.getForceInterval() == INTERVALFORCE && m_force.getLine() <= MAXLINE - FORCESPEED) {
					m_force.getLine() += FORCESPEED;
					m_force.getForceInterval() = 0;
				}
		}
		else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = 5;
	}

	if (m_zhunxin.getZhunXinState() == 0 && m_force.getForceState() == 0) {//�Ҽ���ͷ�ƶ�
		camera.getControl() = 1;
		if (camera.getCamera1Pos(1) + WNDWIDTH * camera.getPro() < 1920)
			camera.getCamera1Pos(1) += CAMERASPEED;
		else if (camera.getCamera1Pos(1) + WNDWIDTH * camera.getPro() > 1920)
			camera.getCamera1Pos(1) = 2560 - WNDWIDTH * camera.getPro();
	}
	return;
}
void Forcevkleftdown() {//ͬ��
	if (gameStatus.getHeroSide() == 0) {
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {
			if (m_zhunxin.getZhunXinState() == 1 && team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1) {
				m_zhunxin.getZhunXinState() = 0;
				m_force.getForceState() = 1;
			}
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1 && m_force.getForceState() == 1)
				if (m_force.getForceInterval() == INTERVALFORCE && m_force.getLine() <= MAXLINE) {
					m_force.getLine() += FORCESPEED;
					m_force.getForceInterval() = 0;
				}
		}
		else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = -5;
	}
	//�з�
	if (gameStatus.getHeroSide() == 1) {
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
			if (m_zhunxin.getZhunXinState() == 1 && team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1) {
				m_zhunxin.getZhunXinState() = 0;
				m_force.getForceState() = 1;
			}
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1 && m_force.getForceState() == 1)
				if (m_force.getForceInterval() == INTERVALFORCE && m_force.getLine() <= MAXLINE) {
					m_force.getLine() += FORCESPEED;
					m_force.getForceInterval() = 0;
				}
		}
		else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = -5;
	}
	if (m_zhunxin.getZhunXinState() == 0 && m_force.getForceState() == 0) {
		camera.getControl() = 1;
		if (camera.getCamera1Pos(1) > 0)
			camera.getCamera1Pos(1) -= CAMERASPEED;
		else if (camera.getCamera1Pos(1) < 0 || gameStatus.getWeapon4State() == 1)
			camera.getCamera1Pos(1) = 0;
	}
	return;
}
void Forcevkrightup() {//�ɿ��������׻��߻��
	if (gameStatus.getHeroSide() == 0) {
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2 && m_force.getForceState() == 1) {
				m_force.getForceState() = 0;//������ʧ
				gameStatus.getThrowState() = 1;//��ʼ׼����
			}
		}
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {
			m_zhunxin.getZhunXinState() = 0;//ͬ����
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -2 && m_force.getForceState() == 1) {
				m_force.getForceState() = 0;
				gameStatus.getLaunchState() = 1;
			}
		}
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = 0;
	}
	//�з�
	if (gameStatus.getHeroSide() == 1) {
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2 && m_force.getForceState() == 1) {
				m_force.getForceState() = 0;
				m_shoulei.getShouLeiState() = 0;
			}
		}
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
			m_zhunxin.getZhunXinState() = 0;
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -2 && m_force.getForceState() == 1) {
				m_force.getForceState() = 0;
				m_rocket.getRocketState() = 0;
			}
		}
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = 0;
	}
	camera.getControl() = 0;
	return;
}
void Forcevkleftup() {//ͬ��
	if (gameStatus.getHeroSide() == 0) {
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1 && m_force.getForceState() == 1) {
				gameStatus.getThrowState() = 1;
				m_force.getForceState() = 0;
			}
		}
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 1) {
			m_zhunxin.getZhunXinState() = 0;
			if (team1[gameStatus.getHeroOrder1()].getHeroRunState() == -1 && m_force.getForceState() == 1) {
				gameStatus.getLaunchState() = 1;
				m_force.getForceState() = 0;
			}
		}
		if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 || team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = 0;
	}
	//�з�
	if (gameStatus.getHeroSide() == 1) {
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 0) {
			m_zhunxin.getZhunXinState() = 0;
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1 && m_force.getForceState() == 1) {
				m_shoulei.getShouLeiState() = 0;
				m_force.getForceState() = 0;
			}
		}
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 1) {
			m_zhunxin.getZhunXinState() = 0;
			if (team2[gameStatus.getHeroOrder2()].getHeroRunState() == -1 && m_force.getForceState() == 1) {
				m_rocket.getRocketState() = 0;
				m_force.getForceState() = 0;
			}
		}
		if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 || team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4)
			m_zhunxin.getZhunXinV(1) = 0;
	}
	camera.getControl() = 0;
	return;
}
//�����������ײ�ж�
void ShouLeiCrush()
{
	int i;
	if (m_shoulei.getShouLeiV(1) > 0) {//�����������ȥ
		for (i = 0; i < gameStatus.getTerrianSecond(m_shoulei.getShouLeiPos(1)); i++) {
			if (gameStatus.getTerrianState(m_shoulei.getShouLeiPos(1) + SHOULEI_SIZE_X, i) != 0) {
				if ((m_shoulei.getShouLeiPos(0) + SHOULEI_SIZE_Y) < m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos2(0))
					if (m_shoulei.getShouLeiPos(0) + SHOULEI_SIZE_Y >= m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos1(0))
						m_shoulei.getShouLeiState() = 4;
				if (m_shoulei.getShouLeiPos(0) > m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos1(0))
					if (m_shoulei.getShouLeiPos(0) <= m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos2(0))
						m_shoulei.getShouLeiState() = 4;
			}
		}
	}
	if (m_shoulei.getShouLeiV(1) < 0) {
		for (i = 0; i < gameStatus.getTerrianSecond(m_shoulei.getShouLeiPos(1)); i++) {
			if (gameStatus.getTerrianState(m_shoulei.getShouLeiPos(1), i) != 0) {
				if ((m_shoulei.getShouLeiPos(0) + SHOULEI_SIZE_Y) < m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos2(0))
					if (m_shoulei.getShouLeiPos(0) + SHOULEI_SIZE_Y >= m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos1(0))
						m_shoulei.getShouLeiState() = 4;
				if (m_shoulei.getShouLeiPos(0) > m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos1(0))
					if (m_shoulei.getShouLeiPos(0) <= m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos2(0))
						m_shoulei.getShouLeiState() = 4;
			}
		}
	}
	if (m_shoulei.getShouLeiV(1) == 0) {
		for (i = 0; i < gameStatus.getTerrianSecond(m_shoulei.getShouLeiPos(1)); i++) {
			if (gameStatus.getTerrianState(m_shoulei.getShouLeiPos(1), i) != 0)
				if ((m_shoulei.getShouLeiPos(0) + SHOULEI_SIZE_Y) >= m_terrian[m_shoulei.getShouLeiPos(1)][i].getPos1(0))
					m_shoulei.getShouLeiState() = 4;//ת����ը״̬
		}
	}
	if (m_shoulei.getShouLeiState() == 4) {
		if (pictureBGM.getExplodeSoundState() == 0) {//���ű�ը��Ч
			mciSendString(TEXT("open res//explode.mp3 alias ex"), NULL, 0, NULL);
			mciSendString(TEXT("play ex"), NULL, 0, NULL);
			mciSendString(TEXT("setaudio ex volume to 60"), NULL, 0, NULL);
			pictureBGM.getExplodeSoundState() = 1;
		}
	}
}
void RocketCrush() {//ͬ����
	int i;
	if (m_rocket.getRocketV(1) > 0) {
		for (i = 0; i < gameStatus.getTerrianSecond(m_rocket.getRocketPos(1)); i++) {
			if (gameStatus.getTerrianState(m_rocket.getRocketPos(1) + ROCKET_SIZE_X, i) != 0) {
				if ((m_rocket.getRocketPos(0) + ROCKET_SIZE_Y) < m_terrian[m_rocket.getRocketPos(1)][i].getPos2(0))
					if (m_rocket.getRocketPos(0) + ROCKET_SIZE_Y >= m_terrian[m_rocket.getRocketPos(1)][i].getPos1(0))
						m_rocket.getRocketState() = 4;
				if (m_rocket.getRocketPos(0) > m_terrian[m_rocket.getRocketPos(1)][i].getPos1(0))
					if (m_rocket.getRocketPos(0) <= m_terrian[m_rocket.getRocketPos(1)][i].getPos2(0))
						m_rocket.getRocketState() = 4;
			}
		}
	}
	if (m_rocket.getRocketV(1) < 0) {
		for (i = 0; i < gameStatus.getTerrianSecond(m_rocket.getRocketPos(1)); i++) {
			if (gameStatus.getTerrianState(m_rocket.getRocketPos(1), i) != 0) {
				if ((m_rocket.getRocketPos(0) + ROCKET_SIZE_Y) < m_terrian[m_rocket.getRocketPos(1)][i].getPos2(0))
					if (m_rocket.getRocketPos(0) + ROCKET_SIZE_Y >= m_terrian[m_rocket.getRocketPos(1)][i].getPos1(0))
						m_rocket.getRocketState() = 4;
				if (m_rocket.getRocketPos(0) > m_terrian[m_rocket.getRocketPos(1)][i].getPos1(0))
					if (m_rocket.getRocketPos(0) <= m_terrian[m_rocket.getRocketPos(1)][i].getPos2(0))
						m_rocket.getRocketState() = 4;
			}
		}
	}
	if (m_rocket.getRocketV(1) == 0) {
		for (i = 0; i < gameStatus.getTerrianSecond(m_rocket.getRocketPos(1)); i++) {
			if (gameStatus.getTerrianState(m_rocket.getRocketPos(1), i) != 0)
				if ((m_rocket.getRocketPos(0) + ROCKET_SIZE_Y) >= m_terrian[m_rocket.getRocketPos(1)][i].getPos1(0))
					m_rocket.getRocketState() = 4;
		}
	}
	if (m_rocket.getRocketState() == 4) {
		if (pictureBGM.getExplodeSoundState() == 0) {
			mciSendString(TEXT("open res//explode.mp3 alias ex"), NULL, 0, NULL);
			mciSendString(TEXT("play ex"), NULL, 0, NULL);
			mciSendString(TEXT("setaudio ex volume to 60"), NULL, 0, NULL);
			pictureBGM.getExplodeSoundState() = 1;
		}
	}

}

//�����˺�
void ShouLeiDamage() {
	int i = 0;
	float distance, x, y;
	if (m_shoulei.getShouLeiState() == 6 && m_shoulei.getShouLeiState1() == 0) {
		for (i = 0; i < 3; i++) {
			x = team1[i].getHeroPos(1) - m_shoulei.getShouLeiPos(1);
			y = team1[i].getHeroPos(0) - m_shoulei.getShouLeiPos(0);
			distance = sqrt(x * x + y * y);
			if (distance <= 2)
				team1[i].getHeroLife() -= 60;
			else if (distance <= 10)
				team1[i].getHeroLife() -= 40;
			else if (distance <= 20)
				team1[i].getHeroLife() -= 32;
			else if (distance <= 30)
				team1[i].getHeroLife() -= 20;
			else if (distance <= 40)
				team1[i].getHeroLife() -= 12;
			if (team1[i].getHeroLife() < 0) team1[i].getHeroLife() = 0;
		}
		for (i = 0; i < 3; i++) {
			x = team2[i].getHeroPos(1) - m_shoulei.getShouLeiPos(1);
			y = team2[i].getHeroPos(0) - m_shoulei.getShouLeiPos(0);
			distance = sqrt(x * x + y * y);
			if (distance <= 2)
				team2[i].getHeroLife() -= 60;
			else if (distance <= 10)
				team2[i].getHeroLife() -= 40;
			else if (distance <= 20)
				team2[i].getHeroLife() -= 32;
			else if (distance <= 30)
				team2[i].getHeroLife() -= 20;
			else if (distance <= 40)
				team2[i].getHeroLife() -= 12;
			if (team2[i].getHeroLife() < 0) team2[i].getHeroLife() = 0;
		}
		m_shoulei.getShouLeiState1() = 2;
	}
}
void RocketDamage() {//����˺�
	int i = 0;
	float distance, x, y;
	if (m_rocket.getRocketState() == 6 && m_rocket.getRocketState1() == 0) {
		for (i = 0; i < 3; i++) {
			x = team1[i].getHeroPos(1) - m_rocket.getRocketPos(1);
			y = team1[i].getHeroPos(0) - m_rocket.getRocketPos(0);
			distance = sqrt(x * x + y * y);
			if (distance <= 3)
				team1[i].getHeroLife() -= 48;
			else if (distance <= 15)
				team1[i].getHeroLife() -= 35;
			else if (distance <= 25)
				team1[i].getHeroLife() -= 27;
			else if (distance <= 35)
				team1[i].getHeroLife() -= 15;
			else if (distance <= 45)
				team1[i].getHeroLife() -= 7;
			else if (distance <= 55)
				team1[i].getHeroLife() -= 3;
			if (team1[i].getHeroLife() < 0) team1[i].getHeroLife() = 0;
		}
		for (i = 0; i < 3; i++) {
			x = team2[i].getHeroPos(1) - m_rocket.getRocketPos(1);
			y = team2[i].getHeroPos(0) - m_rocket.getRocketPos(1);
			distance = sqrt(x * x + y * y);
			if (distance <= 48)
				team2[i].getHeroLife() -= 48;
			else if (distance <= 15)
				team2[i].getHeroLife() -= 35;
			else if (distance <= 25)
				team2[i].getHeroLife() -= 27;
			else if (distance <= 35)
				team2[i].getHeroLife() -= 15;
			else if (distance <= 45)
				team2[i].getHeroLife() -= 7;
			else if (distance <= 55)
				team2[i].getHeroLife() -= 3;
			if (team2[i].getHeroLife() < 0) team2[i].getHeroLife() = 0;
		}
		m_rocket.getRocketState1() = 2;
	}
}
//�غϸ���
void RoundUpdate()
{
	if ((gameStatus.getRoundState() == 0 && gameStatus.getRoundTime() == ROUNDTIME) || gameStatus.getSkip() == 1) {//����ʱ����
		gameStatus.getRoundTime() = 0;
		gameStatus.getRoundState() = 1;
		gameStatus.getSkip() = 2;
	}
	if (m_shoulei.getShouLeiState() == 9) {//������ֱ���������������׶�
		gameStatus.getRoundState() = 1;
		gameStatus.getRoundTime() = 0;
		m_shoulei.getShouLeiState() = 5;
	}
	if (m_rocket.getRocketState() == 3) {//����ͬ��
		gameStatus.getRoundState() = 1;
		gameStatus.getRoundTime() = 0;
		m_rocket.getRocketState() = 5;
	}
	if (transmitGate.getTranState() == 3) {
		gameStatus.getRoundState() = 1;
		gameStatus.getRoundTime() = 0;
		transmitGate.getTranState() = 0;
	}

	if (boom.getBoomState() == 6) {
		gameStatus.getRoundState() = 1;
		gameStatus.getRoundTime() = 0;
		boom.getBoomState() = 7;;
	}
	if (gameStatus.getHeroSide() == 0)
		if (team1[gameStatus.getHeroOrder1()].getHeroLife() == 0)
			gameStatus.getRoundState() = 1;//����Ҳ���������׶�

	if (gameStatus.getHeroSide() == 1)
		if (team2[gameStatus.getHeroOrder2()].getHeroLife() == 0)
			gameStatus.getRoundState() = 2;

	if (gameStatus.getRoundTime() % 50 == 0) gameStatus.getTimePast() = gameStatus.getRoundTime() / 50;
	if (gameStatus.getRoundState() == 1 && gameStatus.getRoundTime() == ROUNDENDTIME) {
		gameStatus.getTimePast() = 0;
		gameStatus.getRoundTime() = 0;
		gameStatus.getRoundState() = 2;
	}
	//�غϸ���
	if (gameStatus.getRoundState() == 2) {
		gameStatus.getRoundStart1() = 0;
		RoundEnd();//�غϽ����ֻ�
		if (m_force.getForceState() == 1) {
			m_force.getForceState() = 0;
			m_shoulei.getShouLeiState() = 0;
		}
		if (gameStatus.getHeroSide() == 0) {//�غϸ��µ�ʱ��Ҫ����û������	
			while (1) {
				gameStatus.getHeroOrder1() += 1;//����ѭ��
				if (gameStatus.getHeroOrder1() == 3)	gameStatus.getHeroOrder1() = 0;
				if (team1[gameStatus.getHeroOrder1()].getHeroLife() != 0) break;
				if (team1[0].getHeroLife() + team1[1].getHeroLife() + team1[2].getHeroLife() == 0) {
					gameStatus.getGameEnd() = 1;//ȫ������Ϸֱ�ӽ���
					gameStatus.getGameStatus() = 7;
					break;
				}
			}
			gameStatus.getHeroSide() = 1;
		}
		else {
			while (1) {//ͬ��
				gameStatus.getHeroOrder2() += 1;
				if (gameStatus.getHeroOrder2() == 3)	gameStatus.getHeroOrder2() = 0;
				if (team2[gameStatus.getHeroOrder2()].getHeroLife() != 0) break;
				if (team2[0].getHeroLife() + team2[1].getHeroLife() + team2[2].getHeroLife() == 0) {
					gameStatus.getGameEnd() = 1;
					gameStatus.getGameStatus() = 7;
					break;
				}
			}
			gameStatus.getHeroSide() = 0;
		}
		gameStatus.getTimePast() = 0;//�غϲ�������
		m_zhunxin.getZhunXinJiaoDu() = 0;
		m_shoulei.getShouLeiState() = 1;
		m_shoulei.getShouLeiState1() = 1;
		m_force.getLine() = 0;
		m_force.getForceInterval() = INTERVALFORCE;
		m_shoulei.getShouLeiExplodePct() = 0;
		m_shoulei.getShouLeiWait() = 0;
		gameStatus.getRoundState() = 0;
		gameStatus.getThrowState() = 0;

		if (gameStatus.getWeapon4Use() == 0) {
			if (gameStatus.getWeapon4Side() == 0)
				team1[gameStatus.getWeapon4Num()].getHeroWeapon() = 0;
			else if (gameStatus.getWeapon4Side() == 1)
				team2[gameStatus.getWeapon4Num()].getHeroWeapon() = 0;
			gameStatus.getWeapon4State() = 0;
			gameStatus.getWeapon4Num() = -1;
			gameStatus.getWeapon4Side() = -1;
		}
		if (gameStatus.getHeroSide() == 0 && gameStatus.getWeapon4Side() == 0) {
			if (gameStatus.getHeroOrder1() == gameStatus.getWeapon4Num())//����Ϊӵ�е��İ�����
				gameStatus.getWeapon4State() = 1;
			else gameStatus.getWeapon4State() = 0;
		}
		else if (gameStatus.getHeroSide() == 1 && gameStatus.getWeapon4Side() == 1) {
			if (gameStatus.getHeroOrder2() == gameStatus.getWeapon4Num())
				gameStatus.getWeapon4State() = 1;
			else gameStatus.getWeapon4State() = 0;
		}
		if (gameStatus.getRoundCount() < ENDTIME) gameStatus.getRoundCount()++;//40�ֺ���Ϸ��ֹ
		if (gameStatus.getRoundCount() == ENDTIME)
			gameStatus.getAllover() = 1;
		gameStatus.getPlaneState() = 0;
		boom.getBoomState() = 1, boom.getBoomState1() = 1;
		gameStatus.getBoomPct() = 0;

		m_rocket.getRocketState() = 1;
		m_rocket.getRocketState1() = 1;
		pictureBGM.getRocketExplodePct() = 0;
		gameStatus.getLaunchState() = 0;
		pictureBGM.getSoundStart() = 0;
		gameStatus.getSkip() = 0;
		ai.getAIstart() = 0;
		ai.getAIattack() = 0;
		ai.getAIdirection() = -1;
		ai.getAIcount() = 0;
		ai.getAImoveState() = 0;
		ai.getAIzhunxinState() = 0;
		gameStatus.getLimitState() = 0;
		pictureBGM.getHurtSoundState() = 0;
		pictureBGM.getExplodeSoundState() = 0;
	}
}

//����׹����ײ
void HeroCrush() {
	if (gameStatus.getPaintAgain() == 0) {
		int i, j;
		for (j = 0; j < 3; j++) {
			if (team1[j].getHeroLife() != 0) {
				team1[j].getHeroWalkTerrian() = -1;
				if (team1imitate[j].getHeroPos(0) == team1[j].getHeroPos(0) && team1imitate[j].getHeroPos(1) == team1[j].getHeroPos(1))
					continue;
				else {//ģ�������ҵ��ؿ�
					team1imitate[j] = team1[j];
					while (1) {
						if (team1imitate[j].getHeroPos(0) > 1920 || team1imitate[j].getHeroPos(0) < 0)
							team1imitate[j].getHeroPos(0) = team1[j].getHeroPos(0);

						team1imitate[j].getHeroPos(0) += 10;//һֱ������
						for (i = 0; i < gameStatus.getTerrianSecond(team1[j].getHeroPos(1) + LeftFoot); i++) {
							if (gameStatus.getTerrianState(team1imitate[j].getHeroPos(1) + LeftFoot, i) != 0) {
								if ((team1imitate[j].getHeroPos(0) + HERO_SIZE_Y) < m_terrian[team1[j].getHeroPos(1) + LeftFoot][i].getPos2(0))
									if (team1imitate[j].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team1[j].getHeroPos(1) + LeftFoot][i].getPos1(0))
										team1[j].getHeroWalkTerrian() = i;
							}
						}
						if (team1[j].getHeroWalkTerrian() != -1) break;
					}
				}
			}
		}
		for (i = 0; i < 3; i++) {
			if (team1[i].getHeroLife() != 0) {//��ģ��������ȷ����ʵ����
				if (team1[i].getHeroPos(0) < m_terrian[team1[i].getHeroPos(1) + LeftFoot][team1[i].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y) team1[i].getHeroAcceration(0) = GRAVITY;
				else if (team1[i].getHeroPos(0) > m_terrian[team1[i].getHeroPos(1) + LeftFoot][team1[i].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y) {
					team1[i].getHeroPos(0) = m_terrian[team1[i].getHeroPos(1) + LeftFoot][team1[i].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y;
					team1imitate[j].getHeroPos(0) = team1[j].getHeroPos(0);
					team1[i].getHeroVel(0) = 0;
					team1[i].getHeroAcceration(0) = 0;
				}
			}
		}
		//�з�ͬ��
		for (j = 0; j < 3; j++) {
			if (team2[j].getHeroLife() != 0) {
				if (team2imitate[j].getHeroPos(0) == team2[j].getHeroPos(0) && team2imitate[j].getHeroPos(1) == team2[j].getHeroPos(1))
					continue;
				else {
					team2imitate[j] = team2[j];
					team2[j].getHeroWalkTerrian() = -1;
					while (1) {
						if (team2imitate[j].getHeroPos(0) > 1920 || team2imitate[j].getHeroPos(0) < 0)
							team2imitate[j].getHeroPos(0) = team2[j].getHeroPos(0);
						team2imitate[j].getHeroPos(0) += 10;
						for (i = 0; i < gameStatus.getTerrianSecond(team2[j].getHeroPos(1) + LeftFoot); i++) {
							if (gameStatus.getTerrianState(team2imitate[j].getHeroPos(1) + LeftFoot, i) != 0) {
								if ((team2imitate[j].getHeroPos(0) + HERO_SIZE_Y) < m_terrian[team2[j].getHeroPos(1) + LeftFoot][i].getPos2(0))
									if (team2imitate[j].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team2[j].getHeroPos(1) + LeftFoot][i].getPos1(0))
										team2[j].getHeroWalkTerrian() = i;
							}
						}
						if (team2[j].getHeroWalkTerrian() != -1) break;
					}
				}
			}
		}
		for (i = 0; i < 3; i++) {
			if (team2[i].getHeroLife() != 0) {
				if (team2[i].getHeroPos(0) < m_terrian[team2[i].getHeroPos(1) + LeftFoot][team2[i].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y) team2[i].getHeroAcceration(0) = GRAVITY;
				else if (team2[i].getHeroPos(0) > m_terrian[team2[i].getHeroPos(1) + LeftFoot][team2[i].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y) {
					team2[i].getHeroPos(0) = m_terrian[team2[i].getHeroPos(1) + LeftFoot][team2[i].getHeroWalkTerrian()].getPos1(0) - HERO_SIZE_Y;
					team2imitate[j].getHeroPos(0) = team2[j].getHeroPos(0);
					team2[i].getHeroVel(0) = 0;
					team2[i].getHeroAcceration(0) = 0;
				}
			}
		}
		//�����ҽ�����
		for (i = 0; i < 3; i++)
			if (gameStatus.getTerrianState(team1[i].getHeroPos(1) + LeftFoot, team1[i].getHeroWalkTerrian()) == -1)
				team1[i].getHeroLife() = 0;
		for (i = 0; i < 3; i++)
			if (gameStatus.getTerrianState(team2[i].getHeroPos(1) + LeftFoot, team2[i].getHeroWalkTerrian()) == -1)
				team2[i].getHeroLife() = 0;
	}
}

//��ͷ����
void JianTouUpdate() {
	//������ͷָʾ
	if (gameStatus.getHeroSide() == 0) {
		gameStatus.getJianTouDelay() += redjiantou.getJianTouV(0);
		redjiantou.getJianTouV(0) += redjiantou.getJianTouA(0);
		if (gameStatus.getRoundStart1() - gameStatus.getRoundStart2() == -1) {
			redjiantou.getJianTouA(0) = 1;
			redjiantou.getJianTouPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1);
			gameStatus.getJianTouDelay() = -20;
			gameStatus.getRoundStart1() = 1;
		}
		redjiantou.getJianTouPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1);
		if (gameStatus.getJianTouDelay() >= 0) {
			redjiantou.getJianTouA(0) = 0;
			redjiantou.getJianTouV(0) = -1;
		}//[-12,0]��ѭ������
		if (gameStatus.getJianTouDelay() <= -12 && redjiantou.getJianTouV(0) < 0)
			redjiantou.getJianTouV(0) = 1;
	}
	redjiantou.getJianTouPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0) + gameStatus.getJianTouDelay();
	//�з���ͷָʾ
	if (gameStatus.getHeroSide() == 1) {
		bluejiantou.getJianTouV(0) += bluejiantou.getJianTouA(0);
		gameStatus.getJianTouDelay() += bluejiantou.getJianTouV(0);
		if (gameStatus.getRoundStart1() - gameStatus.getRoundStart2() == -1) {
			bluejiantou.getJianTouPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1);
			gameStatus.getJianTouDelay() = -20;
			bluejiantou.getJianTouA(0) = 1;
			gameStatus.getRoundStart1() = 1;
		}
		bluejiantou.getJianTouPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1);
		if (gameStatus.getJianTouDelay() >= 0) {
			bluejiantou.getJianTouA(0) = 0;
			bluejiantou.getJianTouV(0) = -1;
		}
		if (gameStatus.getJianTouDelay() <= -12 && bluejiantou.getJianTouV(0) < 0)
			bluejiantou.getJianTouV(0) = 1;
	}
	bluejiantou.getJianTouPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0) + gameStatus.getJianTouDelay();
}

//���ױ�ըͼƬλ��ȷ��
void ShouLeiExplodeUpdate() {
	shouleiexplode.getShouLeiExplodePos(1) = m_shoulei.getShouLeiPos(1);
	shouleiexplode.getShouLeiExplodePos(0) = m_shoulei.getShouLeiPos(0);
}
void RocketExplodeUpdate() {
	rocketexplode.getRocketExplodePos(1) = m_rocket.getRocketPos(1);
	rocketexplode.getRocketExplodePos(0) = m_rocket.getRocketPos(0);
}

//���ױ�ը���Ч��
void ShouLeiMove() {
	if (m_shoulei.getShouLeiState() == 6 && m_shoulei.getShouLeiState1() == 2) {
		float x, y, distance, S, C;
		int i;
		//�������
		for (i = 0; i < 3; i++) {
			x = team1[i].getHeroPos(1) - m_shoulei.getShouLeiPos(1);
			y = team1[i].getHeroPos(0) - m_shoulei.getShouLeiPos(0);
			distance = sqrt(x * x + y * y);
			if (distance > SHOULEIMOVERANGE) continue;//�ж���ը����
			else {
				S = y / distance;
				C = x / distance;
				team1[i].getHeroVel(1) = SHOULEIMOVEVEL * C;//����������
				team1[i].getHeroVel(0) = SHOULEIMOVEVEL * S;
			}
		}
		//�з����
		for (i = 0; i < 3; i++) {
			x = team2[i].getHeroPos(1) - m_shoulei.getShouLeiPos(1);
			y = team2[i].getHeroPos(0) - m_shoulei.getShouLeiPos(0);
			distance = sqrt(x * x + y * y);
			if (distance > SHOULEIMOVERANGE) continue;
			else {
				S = y / distance;
				C = x / distance;
				team2[i].getHeroVel(1) = SHOULEIMOVEVEL * C;
				team2[i].getHeroVel(0) = SHOULEIMOVEVEL * S;
			}
		}
		m_shoulei.getShouLeiState1() = 3;//��ը����
		m_shoulei.getShouLeiState() = 7;
	}
}

//������ͬ����
void RocketMove() {
	if (m_rocket.getRocketState() == 6 && m_rocket.getRocketState1() == 2) {
		float x, y, distance, S, C;
		int i;
		for (i = 0; i < 3; i++) {
			x = team1[i].getHeroPos(1) - m_rocket.getRocketPos(1);
			y = team1[i].getHeroPos(0) - m_rocket.getRocketPos(0);
			distance = sqrt(x * x + y * y);
			if (distance > ROCKETMOVERANGE) continue;
			else
			{
				S = y / distance;
				C = x / distance;
				team1[i].getHeroVel(1) = ROCKETMOVEVEL * C;
				team1[i].getHeroVel(0) = ROCKETMOVEVEL * S;
			}
		}
		for (i = 0; i < 3; i++) {
			x = team2[i].getHeroPos(1) - m_rocket.getRocketPos(1);
			y = team2[i].getHeroPos(0) - m_rocket.getRocketPos(0);
			distance = sqrt(x * x + y * y);
			if (distance > ROCKETMOVERANGE) continue;
			else
			{
				S = y / distance;
				C = x / distance;
				team2[i].getHeroVel(1) = ROCKETMOVEVEL * C;
				team2[i].getHeroVel(0) = ROCKETMOVEVEL * S;
			}
		}
		m_rocket.getRocketState1() = 3;
		m_rocket.getRocketState() = 7;
	}
}

//�������Ħ������
void HeroFriction() {
	int i;
	for (i = 0; i < 3; i++) {//������������
		if (team1[i].getHeroMotionState() == 0) {
			if (team1[i].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team1[i].getHeroPos(1) + LeftFoot][team1[i].getHeroWalkTerrian()].getPos1(0) && team1[i].getHeroVel(1) != 0) {
				if (team1[i].getHeroVel(1) > 0)
					team1[i].getHeroAcceration(1) = -1;//�����෴�ļ��ٶ�
				if (team1[i].getHeroVel(1) < 0)
					team1[i].getHeroAcceration(1) = 1;
			}
			if (team1[i].getHeroVel(1) == 0)
				team1[i].getHeroAcceration(1) = 0;
		}
	}

	//�з���������
	for (i = 0; i < 3; i++) {
		if (team2[i].getHeroMotionState() == 0) {
			if (team2[i].getHeroPos(0) + HERO_SIZE_Y >= m_terrian[team2[i].getHeroPos(1) + LeftFoot][team2[i].getHeroWalkTerrian()].getPos1(0) && team2[i].getHeroVel(1) != 0) {
				if (team2[i].getHeroVel(1) > 0)
					team2[i].getHeroAcceration(1) = -1;
				if (team2[i].getHeroVel(1) < 0)
					team2[i].getHeroAcceration(1) = 1;
			}
			if (team2[i].getHeroVel(1) == 0)
				team2[i].getHeroAcceration(1) = 0;
		}
	}
}

//���ﶯ��״̬����
void HeroMotionUpdate() {
	int i;
	for (i = 0; i < 3; i++) {//�ѷ�
		if (team1[i].getHeroMotionState() == 0) {//�ɾ�����
			if (team1[i].getHeroRunState() == -1 && team1[i].getHeroVel(1) != 0)
				team1[i].getHeroRunState() = 1;
			if (team1[i].getHeroRunState() == -2 && team1[i].getHeroVel(1) != 0)
				team1[i].getHeroRunState() = 2;
			if (team1[i].getHeroRunState() == 1 && team1[i].getHeroVel(1) == 0) {
				team1[i].getHeroRunState() = -1;
				team1[i].getHeroTimes() = 1;
			}
			if (team1[i].getHeroRunState() == 2 && team1[i].getHeroVel(1) == 0) {
				team1[i].getHeroRunState() = -2;
				team1[i].getHeroTimes() = 1;
			}
		}
	}
	//�з�ͬ��
	for (i = 0; i < 3; i++) {
		if (team2[i].getHeroMotionState() == 0) {
			if (team2[i].getHeroRunState() == -1 && team2[i].getHeroVel(1) != 0)
				team2[i].getHeroRunState() = 1;
			if (team2[i].getHeroRunState() == -2 && team2[i].getHeroVel(1) != 0)
				team2[i].getHeroRunState() = 2;
			if (team2[i].getHeroRunState() == 1 && team2[i].getHeroVel(1) == 0) {
				team2[i].getHeroRunState() = -1;
				team2[i].getHeroTimes() = 4;
			}
			if (team2[i].getHeroRunState() == 2 && team2[i].getHeroVel(1) == 0) {
				team2[i].getHeroRunState() = -2;
				team2[i].getHeroTimes() = 4;
			}
		}
	}
}

//�غϽ�������
void RoundEnd() {
	int i;
	if (gameStatus.getHeroSide() == 0)//״̬��ʼ��
		team1[gameStatus.getHeroOrder1()].getHeroMotionState() = 0;
	if (gameStatus.getHeroSide() == 1)
		team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 0;
	for (i = 0; i < 3; i++) {
		team1[i].getHeroVel(1) = 0;
		team1[i].getHeroAcceration(1) = 0;
	}
	for (i = 0; i < 3; i++) {
		team2[i].getHeroVel(1) = 0;
		team2[i].getHeroAcceration(1) = 0;
	}
}

void  BloodDecrease() {//Ѫ�����ٺ���
	int i;
	for (i = 0; i < 3; i++) {
		if (team1[i].getHeroLifeDecrease() - team1[i].getHeroLife() != 0)
			team1[i].getLifeDecreaseTime()++;
		if (team1[i].getHeroLifeDecrease() - team1[i].getHeroLife() > 0 && pictureBGM.getHurtSoundState() == 0) {
			int ran;
			ran = rand() % 5;//����ʱ����Ч�������
			if (ran == 0) mciSendString(TEXT("play res\\76hurt1.mp3"), NULL, 0, NULL);
			if (ran == 1) mciSendString(TEXT("play res\\76hurt2.mp3"), NULL, 0, NULL);
			if (ran == 2) mciSendString(TEXT("play res\\76hurt3.mp3"), NULL, 0, NULL);
			if (ran == 3) mciSendString(TEXT("play res\\76hurt4.mp3"), NULL, 0, NULL);
			if (ran == 4) mciSendString(TEXT("play res\\76hurt5.mp3"), NULL, 0, NULL);
			pictureBGM.getHurtSoundState() = 1;
		}
		if (team1[i].getLifeDecreaseTime() == BLOODDECREASETIME + 1) {
			team1[i].getHeroLifeDecrease() = team1[i].getHeroLife();
			team1[i].getLifeDecreaseTime() = 0;
		}
	}
	for (i = 0; i < 3; i++) {
		if (team2[i].getHeroLifeDecrease() - team2[i].getHeroLife() != 0)
			team2[i].getLifeDecreaseTime()++;
		if (team2[i].getHeroLifeDecrease() - team2[i].getHeroLife() > 0 && pictureBGM.getHurtSoundState() == 0) {
			int ran;
			ran = rand() % 5;
			if (ran == 0) mciSendString(TEXT("play res\\mhurt1.mp3"), NULL, 0, NULL);
			if (ran == 1) mciSendString(TEXT("play res\\mhurt2.mp3"), NULL, 0, NULL);
			if (ran == 2) mciSendString(TEXT("play res\\mhurt3.mp3"), NULL, 0, NULL);
			if (ran == 3) mciSendString(TEXT("play res\\mhurt4.mp3"), NULL, 0, NULL);
			if (ran == 4) mciSendString(TEXT("play res\\mhurt5.mp3"), NULL, 0, NULL);
			pictureBGM.getHurtSoundState() = 1;
		}
		if (team2[i].getLifeDecreaseTime() == BLOODDECREASETIME + 1) {
			team2[i].getHeroLifeDecrease() = team2[i].getHeroLife();
			team2[i].getLifeDecreaseTime() = 0;
		}
	}
}

//��ͷ�ƶ�����
void Camera() {
	if (camera.getControl() == 0) {
		//camera
		if (gameStatus.getHeroSide() == 0) {//����ͼ�г������ƶ�
			if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 2 && m_zhunxin.getZhunXinState() == 1) {
				if (m_zhunxin.getZhunXinPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_zhunxin.getZhunXinPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_zhunxin.getZhunXinPos(1) - WNDWIDTH / 2 * camera.getPro();
				//����׼��λ���ƶ�
				if (m_zhunxin.getZhunXinPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_zhunxin.getZhunXinPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_zhunxin.getZhunXinPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}
			//���ݿ�Ϯ�������ƶ�
			else if (team1[gameStatus.getHeroOrder1()].getHeroWeapon() == 4 && m_zhunxin.getZhunXinState() == 1) {
				if (m_zhunxin.getZhunXinPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_zhunxin.getZhunXinPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_zhunxin.getZhunXinPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (m_zhunxin.getZhunXinPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_zhunxin.getZhunXinPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_zhunxin.getZhunXinPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}
			//���׷�Ծ��ʱ����ƶ�
			else if (m_shoulei.getShouLeiState() == 0 || m_shoulei.getShouLeiState() == 2 || m_shoulei.getShouLeiState() == 3 || m_shoulei.getShouLeiState() == 4 || m_shoulei.getShouLeiState() == 6 || m_shoulei.getShouLeiState() == 7) {
				if (m_shoulei.getShouLeiPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_shoulei.getShouLeiPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_shoulei.getShouLeiPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (m_shoulei.getShouLeiPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_shoulei.getShouLeiPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_shoulei.getShouLeiPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}
			//����ƶ�
			else if (m_rocket.getRocketState() == 0 || m_rocket.getRocketState() == 2 || m_rocket.getRocketState() == 3 || m_rocket.getRocketState() == 4 || m_rocket.getRocketState() == 6 || m_rocket.getRocketState() == 7) {
				if (m_rocket.getRocketPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_rocket.getRocketPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_rocket.getRocketPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (m_rocket.getRocketPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_rocket.getRocketPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_rocket.getRocketPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}

			else if (gameStatus.getPlaneState() == 2 && boom.getBoomState1() == 1) {
				if (plane.getRocketPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (plane.getRocketPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = plane.getRocketPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (plane.getRocketPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (plane.getRocketPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = plane.getRocketPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}

			else if (gameStatus.getPlaneState() == 2 && boom.getBoomState1() == 0) {
				if (boom.getRocketPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (boom.getRocketPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = boom.getRocketPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (boom.getRocketPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (boom.getRocketPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = boom.getRocketPos(0) - WNDHEIGHT * 0.5 * camera.getPro();

			}
			else {//����λ���ƶ���ͷ�ƶ�
				if (team1[gameStatus.getHeroOrder1()].getHeroPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (team1[gameStatus.getHeroOrder1()].getHeroPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = team1[gameStatus.getHeroOrder1()].getHeroPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (team1[gameStatus.getHeroOrder1()].getHeroPos(0) < WNDHEIGHT * 0.75 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (team1[gameStatus.getHeroOrder1()].getHeroPos(0) + WNDHEIGHT * 0.25 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = team1[gameStatus.getHeroOrder1()].getHeroPos(0) - WNDHEIGHT * 0.75 * camera.getPro();
			}
		}
		if (gameStatus.getHeroSide() == 1) {
			if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 2 && m_zhunxin.getZhunXinState() == 1) {
				if (m_zhunxin.getZhunXinPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_zhunxin.getZhunXinPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_zhunxin.getZhunXinPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (m_zhunxin.getZhunXinPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_zhunxin.getZhunXinPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_zhunxin.getZhunXinPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}//����ͬ��
			else if (team2[gameStatus.getHeroOrder2()].getHeroWeapon() == 4 && m_zhunxin.getZhunXinState() == 1) {
				if (m_zhunxin.getZhunXinPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_zhunxin.getZhunXinPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_zhunxin.getZhunXinPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (m_zhunxin.getZhunXinPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_zhunxin.getZhunXinPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_zhunxin.getZhunXinPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}
			else if (m_shoulei.getShouLeiState() == 0 || m_shoulei.getShouLeiState() == 2 || m_shoulei.getShouLeiState() == 3 || m_shoulei.getShouLeiState() == 4 || m_shoulei.getShouLeiState() == 6 || m_shoulei.getShouLeiState() == 7) {
				if (m_shoulei.getShouLeiPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_shoulei.getShouLeiPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_shoulei.getShouLeiPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (m_shoulei.getShouLeiPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_shoulei.getShouLeiPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_shoulei.getShouLeiPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}
			else if (m_rocket.getRocketState() == 0 || m_rocket.getRocketState() == 2 || m_rocket.getRocketState() == 3 || m_rocket.getRocketState() == 4 || m_rocket.getRocketState() == 6 || m_rocket.getRocketState() == 7) {
				if (m_rocket.getRocketPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (m_rocket.getRocketPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = m_rocket.getRocketPos(1) - WNDWIDTH / 2 * camera.getPro();


				if (m_rocket.getRocketPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (m_rocket.getRocketPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = m_rocket.getRocketPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}
			else if (gameStatus.getPlaneState() == 2 && boom.getBoomState1() == 1) {
				if (plane.getRocketPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (plane.getRocketPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = plane.getRocketPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (plane.getRocketPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (plane.getRocketPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = plane.getRocketPos(0) - WNDHEIGHT * 0.5 * camera.getPro();
			}

			else if (gameStatus.getPlaneState() == 2 && boom.getBoomState1() == 0) {
				if (boom.getRocketPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (boom.getRocketPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else  camera.getCameraPos(1) = boom.getRocketPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (boom.getRocketPos(0) < WNDHEIGHT * 0.5 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (boom.getRocketPos(0) + WNDHEIGHT * 0.5 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = boom.getRocketPos(0) - WNDHEIGHT * 0.5 * camera.getPro();

			}
			else {
				if (team2[gameStatus.getHeroOrder2()].getHeroPos(1) < WNDWIDTH / 2 * camera.getPro())
					camera.getCameraPos(1) = 0;
				else if (team2[gameStatus.getHeroOrder2()].getHeroPos(1) + WNDWIDTH / 2 * camera.getPro() > 1920)
					camera.getCameraPos(1) = 1920 - WNDWIDTH * camera.getPro();
				else camera.getCameraPos(1) = team2[gameStatus.getHeroOrder2()].getHeroPos(1) - WNDWIDTH / 2 * camera.getPro();

				if (team2[gameStatus.getHeroOrder2()].getHeroPos(0) < WNDHEIGHT * 0.75 * camera.getPro())
					camera.getCameraPos(0) = 0;
				else if (team2[gameStatus.getHeroOrder2()].getHeroPos(0) + WNDHEIGHT * 0.25 * camera.getPro() > 1080)
					camera.getCameraPos(0) = 1080 - WNDHEIGHT * camera.getPro();
				else camera.getCameraPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0) - WNDHEIGHT * 0.75 * camera.getPro();
			}
		}
		//���þ�ͷ���ĸ���������ƶ�
		if (camera.getCameraPos(1) > camera.getCamera1Pos(1)) {
			if ((camera.getCameraPos(1) - camera.getCamera1Pos(1)) < 12) camera.getCamera1Pos(1)++;
			else if ((camera.getCameraPos(1) - camera.getCamera1Pos(1)) < 40)   camera.getCamera1Pos(1) += 6;
			else if ((camera.getCameraPos(1) - camera.getCamera1Pos(1) < 80))  camera.getCamera1Pos(1) += 12;
			else camera.getCamera1Pos(1) += 20;
		}
		if (camera.getCameraPos(1) < camera.getCamera1Pos(1)) {
			if ((camera.getCamera1Pos(1) - camera.getCameraPos(1)) < 12) camera.getCamera1Pos(1)--;
			else if ((camera.getCamera1Pos(1) - camera.getCameraPos(1)) < 40) camera.getCamera1Pos(1) -= 6;
			else if ((camera.getCamera1Pos(1) - camera.getCameraPos(1)) < 80) camera.getCamera1Pos(1) -= 12;
			else camera.getCamera1Pos(1) -= 20;
		}//y���ƶ��ж�
		if (camera.getCameraPos(0) > camera.getCamera1Pos(0)) {
			if ((camera.getCameraPos(0) - camera.getCamera1Pos(0)) < 12) camera.getCamera1Pos(0)++;
			else if ((camera.getCameraPos(0) - camera.getCamera1Pos(0)) < 30) camera.getCamera1Pos(0) += 4;
			else if ((camera.getCameraPos(0) - camera.getCamera1Pos(0)) < 80) camera.getCamera1Pos(0) += 12;
			else camera.getCamera1Pos(0) += 18;
		}
		if (camera.getCameraPos(0) < camera.getCamera1Pos(0)) {
			if ((camera.getCamera1Pos(0) - camera.getCameraPos(0)) < 12) camera.getCamera1Pos(0)--;
			else if ((camera.getCamera1Pos(0) - camera.getCameraPos(0)) < 30) camera.getCamera1Pos(0) -= 4;
			else if ((camera.getCamera1Pos(0) - camera.getCameraPos(0)) < 80) camera.getCamera1Pos(0) -= 12;
			else camera.getCamera1Pos(0) -= 18;
		}
	}

}

void WindUpdate() {//����������ȼ��ͷ���
	int random;
	random = rand() % 5;
	if (random == 0) gameStatus.getWindVel() = 0;
	if (random == 1) gameStatus.getWindVel() = 1;
	if (random == 2) gameStatus.getWindVel() = 2;
	if (random == 3) gameStatus.getWindVel() = -1;
	if (random == 4) gameStatus.getWindVel() = -2;

}

void FoodUpdate() {//�������ʳ�����ͺ�λ��
	int i;
	for (i = 0; i < 6; i++) {
		if (food[i].getFoodState() == 0) {
			food[i].getFoodPicture() = rand() % 4;
			food[i].getPos(1) = 150 + rand() % 1200;
			food[i].getPos(0) = m_terrian[food[i].getPos(1) + 5][0].getPos1(0);
			food[i].getFoodState() = 1;
			break;
		}
	}
	gameStatus.getFoodTimes() = 0;
}

void CrateUpdate() {
	if (crate.getCrateState() == 1) {//�������ľ��λ��
		crate.getPos(1) = 500 + rand() % 800;
		crate.getPos(0) = m_terrian[crate.getPos(1) + 5][0].getPos1(0);
		crate.getCrateState() = 2;
	}
}

void TransUpdate() {//�������������
	if (gameStatus.getHeroSide() == 0) {
		if (transmitGate.getTranState() == 2) {
			team1[gameStatus.getHeroOrder1()].getHeroPos(1) = m_zhunxin.getZhunXinPos(1);
			team1[gameStatus.getHeroOrder1()].getHeroPos(0) = m_zhunxin.getZhunXinPos(0);
		}
	}

	if (gameStatus.getHeroSide() == 1) {
		if (transmitGate.getTranState() == 2) {
			team2[gameStatus.getHeroOrder2()].getHeroPos(1) = m_zhunxin.getZhunXinPos(1);
			team2[gameStatus.getHeroOrder2()].getHeroPos(0) = m_zhunxin.getZhunXinPos(0);
		}
	}
}

void Restart() {//��������Ԫ��
	int i, j;
	for (i = 0; i < 6; i++)
		food[i].getFoodState() = 0;//0��ʾδ���ƣ�1��ʾ����
	gameStatus.getFoodTimes() = 0;
	for (i = 0; i < 1920; i++)
		for (j = 0; j < 6; j++)
			gameStatus.getTerrianState(i, j) = 0;   //1������ʾ���أ�-1������ʾ�ҽ�,0��ʾδ��ʼ��

	for (i = 0; i < 1920; i++)
		gameStatus.getTerrianSecond(i) = 0;
	for (i = 0; i < 4; i++)
		team1[i].team1Restart();
	for (i = 0; i < 9; i++)
		team2[i].team2Restart();

	gameStatus.GameStatusRestart();
	m_zhunxin.getZhunXinState() = 0;   //׼��״̬1��ʾ���֣�0��ʾ��ȥ
	m_force.getForceState() = 0;//������1��ʾ���֣�0��ʾ��ȥ
	m_shoulei.getShouLeiState() = 1, m_shoulei.getShouLeiState1() = 1;//shouleistate������ʾ�����Ƿ�ըor�Ƿ����;0��ʾ����,1��ʾ��ȥ��2��ʾ��ը״̬,4��ʾ��ը����״̬,3��ʾ��ըͼƬ��ʾ���;shouleistate1��ʾ״̬�Ƿ�ı�(1.�Ƿ�����˺�,2,�Ƿ������,3.���׳��ٵ�)����Update������һ���Ե�ִ��
	m_force.getForceInterval() = INTERVALFORCE;//��ʾ �����������ʱ��/д��60s���º���
	m_shoulei.getShouLeiExplodePct() = 0;//������ʾ���ױ�ը����֡
	m_shoulei.getShouLeiWait() = 0;//���׵���λ�ú�ȴ���ըʱ��;

	camera.getControl() = 0;
	camera.getPro() = 1;//��Ļ���ű���
	pictureBGM.getSoundStart() = 0;

	transmitGate.getTranState() = 0;//������״̬��0��ʾδʹ�ã�1��ʾ��ʼ���ͣ�2��ʾ������
	transmitGate.getTranTimes() = 0;
	m_rocket.getRocketState() = 1, m_rocket.getRocketState1() = 1;
	pictureBGM.getRocketExplodePct() = 0;

	boom.getBoomState() = 1, boom.getBoomState1() = 1;
	crate.getCrateState() = 0;
	crate.getCrateTimes() = 0;

	ai.AIrestart();
	pictureBGM.getHurtSoundState() = 0;
	pictureBGM.getExplodeSoundState() = 0;

	int k1, k2;
	for (i = 0; i < 3; i++) {
		k1 = rand() % 1500 + 120;
		k2 = rand() % 600 + 100;
		team1[i].CreateHero(k1, k2, HERO_SIZE_X, HERO_SIZE_Y, hteam1hero, 0, HERO_MAX_FRAME_NUM, 1);
	}
	//�����з�Ӣ��
	for (i = 0; i < 3; i++) {
		k1 = rand() % 1500 + 120;
		k2 = rand() % 600 + 120;
		team2[i].CreateHero(k1, k2, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp, 0, HERO_MAX_FRAME_NUM, 4);
	}
	// ��������
	CreateMap1(100, 1800, 900, 1080, 45, 70, 1600, 100, 0);
	CreateMap3(100, 560, 500, 660, 50, 30, 500, -20, 1);
	CreateMap3(920, 1690, 400, 560, 55, 70, 900, 860, 1);
	CreateMap2(0, 100, 900, 1080);
	CreateMap2(1800, 1920, 900, 1080);

	long x1 = team1[0].getHeroPos(1), y1 = team1[0].getHeroPos(0);
	int runstate = team1[0].getHeroRunState();
	m_zhunxin.CreateZhunXin(hzhunxin, 70, x1, y1, runstate);
	//��ʼ������
	m_shoulei.CreateShouLei(hshoulei, x1, y1);
	m_rocket.CreateRocket(hrocket, x1, y1);
	//��ʼ������Լ������
	m_force.getLine() = 0;
	x1 = team1[0].getHeroPos(1), y1 = team1[0].getHeroPos(0);
	long x2 = team2[0].getHeroPos(1), y2 = team2[0].getHeroPos(0);
	redjiantou.CreateJianTou(hredjiantou, x1, y1);
	bluejiantou.CreateJianTou(hbluejiantou, x2, y2);

	//��ʼ�����ױ�ըͼƬ
	shouleiexplode.getShouLeiExplodehBmp() = hshouleiexplode;
	shouleiexplode.getShouLeiExplodeSize(1) = SHOULEIEXPLODE_SIZE_X;
	shouleiexplode.getShouLeiExplodeSize(0) = SHOULEIEXPLODE_SIZE_Y;
	shouleiexplode.getShouLeiExplodePos(1) = m_shoulei.getShouLeiPos(1);
	shouleiexplode.getShouLeiExplodePos(0) = m_shoulei.getShouLeiPos(0);

	rocketexplode.getRocketExplodehBmp() = hrocketexplode;
	rocketexplode.getRocketExplodeSize(1) = ROCKETEXPLODE_SIZE_X;
	rocketexplode.getRocketExplodeSize(0) = ROCKETEXPLODE_SIZE_Y;
	rocketexplode.getRocketExplodePos(1) = m_rocket.getRocketPos(1);
	rocketexplode.getRocketExplodePos(0) = m_rocket.getRocketPos(0);
	//��ʼcamera
	camera.getCameraPos(1) = 0;
	camera.getCameraPos(0) = 0;
	camera.getCamera1Pos(1) = 0;
	camera.getCamera1Pos(0) = 0;
	//��ʼ������
	WD[0].getPos(1) = rand() % 1200 + 300;
	WD[0].getPos(0) = m_terrian[WD[0].getPos(1) + 30][0].getPos1(0) - 32;
	WD[1].getPos(1) = rand() % 400 + 100;
	WD[1].getPos(0) = m_terrian[WD[1].getPos(1) + 30][1].getPos1(0) - 32;
	WD[2].getPos(1) = rand() % 600 + 950;
	WD[2].getPos(0) = m_terrian[WD[2].getPos(1) + 30][1].getPos1(0) - 32;
	//��ʼ��ʳ��
	food[0].getPos(1) = rand() % 1200 + 300;
	food[0].getPos(0) = m_terrian[food[0].getPos(1) + 5][0].getPos1(0);
	food[0].getFoodState() = 1;
	food[0].getFoodPicture() = rand() % 4;
}

void PlaneUpdate() {
	//��Ϯ����
	if (gameStatus.getPlaneState() == 1) {
		plane.getRocketPos(1) = camera.getCamera1Pos(1) + 1000;//�ɻ�����
		plane.getRocketPos(0) = 120;
		gameStatus.getPlaneState() = 2;
	}
	if (gameStatus.getPlaneState() == 2)//����ѭ���ƶ�
		plane.getRocketPos(1) -= 10;
	if (gameStatus.getPlaneState() == 2 && boom.getBoomState1() == 1) {//�ҵ�Ŀ��
		boom.getRocketPos(1) = plane.getRocketPos(1) + PLANEX / 2;
		boom.getRocketPos(0) = plane.getRocketPos(0) + PLANEX / 2;
		if (plane.getRocketPos(1) + PLANEX / 2 <= gameStatus.getTarget()) {
			boom.getBoomState() = 2;//׼��Ͷ����
			boom.getBoomState1() = 0;
		}
	}
	if (plane.getRocketPos(1) + PLANEX <= camera.getCamera1Pos(1))
		gameStatus.getPlaneState() = 3;
	if (boom.getBoomState() == 2 && boom.getBoomState1() == 0) {
		boom.getRocketPos(0) += 16;
		BoomCrush();
	}
}

void BoomCrush() {
	//�񵯱�ը��ײ ͬ���׺ͻ��
	int i;
	for (i = 0; i < gameStatus.getTerrianSecond(boom.getRocketPos(1)); i++) {
		if (gameStatus.getTerrianState(boom.getRocketPos(1), i) != 0)
			if ((boom.getRocketPos(0) + BOOMY) >= m_terrian[boom.getRocketPos(1)][i].getPos1(0))
				boom.getBoomState() = 3;
	}

	if (boom.getBoomState() == 3) {
		if (pictureBGM.getExplodeSoundState() == 0) {
			mciSendString(TEXT("open res//explode.mp3 alias ex"), NULL, 0, NULL);
			mciSendString(TEXT("play ex"), NULL, 0, NULL);
			mciSendString(TEXT("setaudio ex volume to 60"), NULL, 0, NULL);
			pictureBGM.getExplodeSoundState() = 1;
		}
	}
}
void BoomUpdate() {//ͬ���׺ͻ��
	if (boom.getBoomState() == 4) {
		float x, y, distance, S, C;
		int i;
		for (i = 0; i < 3; i++) {
			x = team1[i].getHeroPos(1) - boom.getRocketPos(1);
			y = team1[i].getHeroPos(0) - boom.getRocketPos(0);
			distance = sqrt(x * x + y * y);
			if (distance > BOOMMOVE) continue;
			else {
				S = y / distance;
				C = x / distance;
				team1[i].getHeroVel(1) = ROCKETMOVEVEL * C;
				team1[i].getHeroVel(0) = ROCKETMOVEVEL * S;
			}
		}
		for (i = 0; i < 3; i++) {
			x = team2[i].getHeroPos(1) - boom.getRocketPos(1);
			y = team2[i].getHeroPos(0) - boom.getRocketPos(0);
			distance = sqrt(x * x + y * y);
			if (distance > BOOMMOVE) continue;
			else {
				S = y / distance;
				C = x / distance;
				team2[i].getHeroVel(1) = ROCKETMOVEVEL * C;
				team2[i].getHeroVel(0) = ROCKETMOVEVEL * S;
			}
		}
		for (i = 0; i < 3; i++) {
			x = team1[i].getHeroPos(1) - boom.getRocketPos(1);
			y = team1[i].getHeroPos(0) - boom.getRocketPos(0);
			distance = sqrt(x * x + y * y);
			if (distance <= 10)
				team1[i].getHeroLife() -= 35;
			else if (distance <= 20)
				team1[i].getHeroLife() -= 27;
			else if (distance <= 30)
				team1[i].getHeroLife() -= 15;
			else if (distance <= 50)
				team1[i].getHeroLife() -= 7;
			if (team1[i].getHeroLife() < 0) team1[i].getHeroLife() = 0;
		}
		for (i = 0; i < 3; i++) {
			x = team2[i].getHeroPos(1) - boom.getRocketPos(1);
			y = team2[i].getHeroPos(0) - boom.getRocketPos(0);
			distance = sqrt(x * x + y * y);
			if (distance <= 10)
				team2[i].getHeroLife() -= 35;
			else if (distance <= 20)
				team2[i].getHeroLife() -= 27;
			else if (distance <= 30)
				team2[i].getHeroLife() -= 15;
			else if (distance <= 50)
				team2[i].getHeroLife() -= 7;
			if (team2[i].getHeroLife() < 0) team2[i].getHeroLife() = 0;
		}
		boom.getBoomState() = 5;//������
	}
}

void AI() {
	//�������AI
	if (ai.getAIstate() == 1) {
		if (gameStatus.getHeroSide() == 1) {
			if (ai.getAIstart() == 0) {//ȫ�����������
				ai.getAIdirection() = rand() % 2;//��������
				ai.getAImove() = rand() % 50 + 20;
				ai.getWeaponR() = rand() % 2;
				team2[gameStatus.getHeroOrder2()].getHeroWeapon() = ai.getWeaponR();
				ai.getAngler() = rand() % 75 + 10;
				ai.getTeam1R() = rand() % 3;
				ai.getAngler() = ai.getAngler() / 180 * 3.14159265;//������
				ai.getAIstart() = 1;
			}
			if (ai.getAImoveState() == 0 && ai.getAIstart() == 1) {//�����
				if (ai.getAIdirection() == 0) {
					team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 1;
					team2[gameStatus.getHeroOrder2()].getHeroRunState() = 1;
					team2[gameStatus.getHeroOrder2()].getHeroPos(1) -= 1;
					ai.getAIcount()++;//�ƶ���������
					if (ai.getAIcount() == ai.getAImove()) {
						ai.getAImoveState() = 1;
						team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 0;
					}
				}
				else if (ai.getAIdirection() == 1) {//���Ҵ�
					team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 1;
					team2[gameStatus.getHeroOrder2()].getHeroRunState() = 2;
					team2[gameStatus.getHeroOrder2()].getHeroPos(1) += 1;
					ai.getAIcount()++;
					if (ai.getAIcount() == ai.getAImove()) {
						ai.getAImoveState() = 1;
						team2[gameStatus.getHeroOrder2()].getHeroMotionState() = 0;
					}
				}
			}
			if (ai.getAImoveState() == 1) {
				ai.getPos(1) = abs(team1[ai.getTeam1R()].getHeroPos(1) + LeftFoot - team2[gameStatus.getHeroOrder2()].getHeroPos(1));
				ai.getPos(0) = team2[gameStatus.getHeroOrder2()].getHeroPos(0) - team1[ai.getTeam1R()].getHeroPos(0) - HERO_SIZE_Y;
				ai.getVshould() = (float)ai.getPos(1) * sqrt(GRAVITY / (2 * (ai.getPos(1) * tan(ai.getAngler()) - ai.getPos(0)))) / cos(ai.getAngler());
				ai.getForceShould() = 3.0 * ai.getVshould();
				ai.getAImoveState() = 2;
			}
			if (ai.getAIattack() == 0 && ai.getAImoveState() == 2) {//׼������׼����ʼ����
				if (team1[ai.getTeam1R()].getHeroPos(1) - team2[gameStatus.getHeroOrder2()].getHeroPos(1) <= 0 && ai.getAIzhunxinState() == 0) {
					team2[gameStatus.getHeroOrder2()].getHeroRunState() = -1;
					m_zhunxin.getZhunXinState() = 1;
					ai.getAIzhunxinState() = 1;
				}
				else if (team1[ai.getTeam1R()].getHeroPos(1) - team2[gameStatus.getHeroOrder2()].getHeroPos(1) > 0 && ai.getAIzhunxinState() == 0) {
					team2[gameStatus.getHeroOrder2()].getHeroRunState() = -2;
					m_zhunxin.getZhunXinState() = 1;
					ai.getAIzhunxinState() = 1;
				}
				if (m_zhunxin.getZhunXinState() == 1 && ai.getAIzhunxinState() == 1) {
					m_zhunxin.getZhunXinJiaoDu() += 0.02;
					if (fabs(m_zhunxin.getZhunXinJiaoDu() - ai.getAngler()) < 0.03 || m_zhunxin.getZhunXinJiaoDu() >= 3.14159265 * 80.0 / 180.0)
					{
						m_zhunxin.getZhunXinState() = 0;
						m_force.getForceState() = 1;
					}
				}
				if (m_force.getForceState() == 1) {
					m_force.getLine() += FORCESPEED;//����������
					if (fabs(m_force.getLine() - ai.getForceShould()) < 1.0 || m_force.getLine() >= MAXLINE) {
						m_force.getForceState() = 0;
						if (ai.getWeaponR() == 0) m_shoulei.getShouLeiState() = 0;
						else if (ai.getWeaponR() == 1) m_rocket.getRocketState() = 0;
						ai.getAIattack() = 1;
					}
				}
			}
		}
	}
}

void limit() {
	//��ͼ����
	if (gameStatus.getLimitState() == 0) {
		if (m_shoulei.getShouLeiPos(1) < 0 || m_shoulei.getShouLeiPos(0) < -400 || m_shoulei.getShouLeiPos(1) > 1920 || m_shoulei.getShouLeiPos(0) > 1080) {
			m_shoulei.getShouLeiV(1) = 0;//����λ������
			m_shoulei.getShouLeiV(0) = 0;
			m_shoulei.getShouLeiA(1) = 0;
			m_shoulei.getShouLeiA(1) = 0;
			m_shoulei.getShouLeiState() = 9;
			gameStatus.getLimitState() = 1;
		}
		if (m_rocket.getRocketPos(1) < 0 || m_rocket.getRocketPos(0) < -400 || m_rocket.getRocketPos(1) > 1920 || m_rocket.getRocketPos(0) > 1080) {
			m_rocket.getRocketV(1) = 0;//���ͬ��
			m_rocket.getRocketV(0) = 0;
			m_rocket.getRocketA(1) = 0;
			m_rocket.getRocketA(0) = 0;
			m_rocket.getRocketState() = 3;
			gameStatus.getLimitState() = 1;
		}
		int i;
		for (i = 0; i < 3; i++) {//Խ���ؽ�ֱ����
			if (team1[i].getHeroPos(1) < 0 || team1[i].getHeroPos(1) > 1920 || team1[i].getHeroPos(0) < 0 || team1[i].getHeroPos(0) > 1080) {
				team1[i].getHeroLife() = 0;
				gameStatus.getRoundState() = 1;
				gameStatus.getLimitState() = 1;
			}
		}
		for (i = 0; i < 3; i++) {
			if (team2[i].getHeroPos(1) < 0 || team2[i].getHeroPos(1) > 1920 || team2[i].getHeroPos(0) < 0 || team2[i].getHeroPos(0) > 1080) {
				team2[i].getHeroLife() = 0;
				gameStatus.getRoundState() = 1;
				gameStatus.getLimitState() = 1;
			}
		}
	}
}
