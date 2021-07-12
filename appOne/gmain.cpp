#include"libOne.h"
#include"libOne.h"
class FLOAT5 {
public:
    float x = 0, y = 0;
    FLOAT5() {
    }
    FLOAT5(float x, float y) {
        this->x = x;
        this->y = y;
    }
    FLOAT5 operator+(FLOAT5& f2) {//17//18
        return FLOAT5(x + f2.x, y + f2.y);
    }
    FLOAT5 operator-(FLOAT5& f2) {//20.5
        return FLOAT5(x - f2.x, y - f2.y);
    }
    FLOAT5 operator*(float f2) {//21.5
        return FLOAT5(x * f2, y * f2);
    }
    void operator+=(const FLOAT5& f2) {//21.5�A23.5
        x += f2.x;
        y += f2.y;
    }
    void normalize() {
        float mag = sqrt(x * x+y * y);
        x /= mag;
        y /= mag;
    }
};
class FLOAT4 {
public:
    float x = 0, y = 0;//12
    FLOAT4() {
    }
    FLOAT4(float x, float y) {
        this->x = x;//13
        this->y = y;
    }
};
class FLOAT3 {
public:
    float x, y;
    FLOAT3() {//9
        x = 0;
        y = 0;
    }
    FLOAT3(float x, float y) {//11
        this->x = x;
        this->y = y;
    }
};
class FLOAT2 {
public:
    float px = 0, py = 0;
};
class FLOAT1 {
public:
    float px = 0, py = 0;
};
void set1(FLOAT1* ft) {//6.5
    ft->px = 1;
    ft->py = 2;
}
void set2(FLOAT2& ft) {//8
    ft.px = 3;
    ft.py = 4;
}
void gmain() {
    window(1920, 1080, full);
    FLOAT1 pos1;
    FLOAT2 pos2;
    FLOAT3 pos3(5,6);//10//12
    FLOAT4 pos4[2] = { FLOAT4(5,6),FLOAT4(7,8) };//13
    FLOAT5 pos5(8, 9);
    FLOAT5 vec(1,1);
    FLOAT5 new_pos;
    //new_pos.x = pos5.x+pos1.x//15
    //new_pos.y = pos5.y+pos1.y
    //new_pos = pos5.plus(vec);//16
    new_pos = pos5+vec;//18.5
    FLOAT5 pos(100, 10);
    vec.normalize();//22
    pos += vec*5.0f;//23
    set1(&pos1);//6
    set2(pos2);//7
    printSize(90);
    print(pos1.px);
    print(pos1.py);
    print(pos2.px);
    print(pos2.py);
    print(pos3.x);
    print(pos3.y);
    print(pos4[1].x);
    print(pos4[1].y);
    print(new_pos.x);
    print(new_pos.y);
    print(pos.x);
    print(pos.y);
    while (notQuit) {

    }
}
/*
//C++�T�R���X�g���N�^�E�f�X�g���N�^�Ƃ����֐�
#include"libOne.h"
class HAPPY {
public:
    HAPPY() {//1
        textSize(200);
        text("�n�b�s�[", 0, 300);
    }
    ~HAPPY() {//�Q
        textSize(200);
        text("�E�F�f�B���O", 300, 600);
    }
};
void gmain() {
    window(1920, 1080, full);
    HAPPY* happy = new HAPPY;
    delete happy;
    while (notQuit) {

    }  
}
*/
/*
//C�{�{�U�A�t�@�C������
#include"libOne.h"
#include "TAKO.h"//5
void gmain() {
    window(1920, 1080, full);
    int takoimg = loadImage("assets\\enemy.png");
    int num = 20;
    TAKO* tako = new TAKO[num];
    for (int i = 0;i < num;i++) {
        tako[i].setImage(takoimg);
        tako[i].init();
    }
    while (notQuit) {
        for (int i = 0;i < num;i++) {
            tako[i].move();
            tako[i].draw();
        }
    }
    delete[]tako;
}
*/
//1�N���X�̖��O�Ɠ����֐����R���X�g���N�^�֐��Ƃ����Avoid���t���Ă͂Ȃ�Ȃ�
//1.5���̊֐��́A�֐����Ăяo���Ȃ��Ă������Ŏ��s�����֐��B
//2�f�X�g���N�^�Ƃ����֐���~��t���A�N���X�̏I���^�C�~���O�Ŏ��s�����֐�
//C++�U[�t�@�C������]
//3���ʂ�class�̒��Ɋ֐��錾�����Ă���
//4�N���X��::������A����Ȃ��ƕ��ʂ̊֐������ɂȂ�
//5include�Ŋ֐��錾����
//C++7[�Q�ƁE�|�C���^�[�͂����̂��H]
//6�E6.5���ʂ̃|�C���^�[�^�E�A�h���X��n���\���̂�N���X�̒l��ς�����������@
//7�Q�ƌ^�@�A�h���X�͂ł͂Ȃ����̂�n��
//8�����Q�Ƃ���f2��pos�������L���ꏊ�ɂȂ�
//C++8[this�|�C���^�Ƃ�]
//9�R���X�g���N�^�֐�
//10���̉�����Ƃ��̃R���X�g���N�^�ɓn������
//11������x=x�Ay=y���ƃG���[���o��̂�this�|�C���^�ŋ�ʂ���
//11.5This�|�C���^�͎���(pos3)�̃A�h���X�������I�ɓ���
//C++9[�������Ƒ���͋�ʂ��悤]
//12�������A1x=0�A2�Fx(0)�Z�~�R�������g���ď��������邱�Ƃ��ł���
//13�z��̏�����
//14���pos = FLOAT2(100,10)�̂悤�ɑ�����邱�Ƃ��ł���
//C++10[���Z�q�̃I�[�o�[���[�h]
//15pos5�̒l��vec�𑫂����l���o�������Ƃ��̍��܂ł̂���
//16.15����s��pos�{vec�Ɛ��w�I�ɒZ���܂Ƃ߂����i���Z�q�̃I�[�o�[���[�h�j���g��
//16.5�킩��₷���A�����o�[�֐���p�����[�����₷���`
//17�����o�[�֐��A�Q�Ƃ��g��FLOAT5��Ԃ��Ă���
//18oprator�i���Z�q�j�{�Ă���Ɓ{��17�̋@�\��ǉ����Ă���
//18.5plus�̋@�\��^���邱�Ƃ�18.5���g�p���邱�Ƃ��ł���
//19�I�o�[���[�h�i���d��`�jfloat�^���`���Ă���
//19.5�����d��`�A�����̈Ⴂ�œ������O�ŕ�����`���Ă���i�R���X�g���N�^�̃I�[�o�[���[�h�j
//20.20.5�Ł[�𑽏d��`���邱�Ƃŕ֗��ɊȒP�Ƀx�N�g�������߂Ă���
//21.21.5�Ł��𑽏d��`�A�ړ��Ȃ�
//22���K��
//23pos�ɐ��K�������l������+=���Ă���A23.5const��t���Ă���
//�܂Ƃ߁AFLOAT5�Ƃ��������ō�����^�Ł��{�[���邱�Ƃ�
//�x�N�g���̌v�Z�Ȃǂ���s�ȉ��ōςނ悤�ɂȂ�
/*
class CHARACTER {//�P�L�����N�^�[�̐݌v�}
    //2
protected://6
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;
public:
    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }
    virtual void move() {//10
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};

class PLAYER :public CHARACTER {//5
public:
    void move() {
        Px += Vx;
    }
};
class ENEMY :public CHARACTER {
public:
    void move() {
        Py += Vy;
    }
};
class ENEMYBULLET :public CHARACTER {
};
class PLAYER1 :public CHARACTER {
public:
    void move() {
        Vx += 2;
        AngSpeed += 2;
        Px += Vx;
        Angle += AngSpeed;
        if (Px > 1920 + 30) {
            Px = 0;
        }
    }
};

class PLAYER2 :public CHARACTER {
public:
    void move() {
        Vx += 2;
        Px += Vx;
        Vy += 2;
        Py += Vy;
        AngSpeed += 2;
        Angle += AngSpeed;
        if (Py > 1080 + 30) {
            Py = 0;
            Px = 0;
        }
    }
};
void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg = loadImage("assets\\eBullet.png");
    PLAYER player;//�S
    ENEMY enemy;//12
    ENEMYBULLET eBullet;

    player.setImage(playerImg);
    enemy.setImage(enemyImg);
    eBullet.setImage(enemyBulletImg);
    const int num = 3;
    //CHARACTER* chara = &enemy;//7,9,11
    CHARACTER* chara[num];//13
    chara[0] = &player;//14
    chara[1] = &enemy;
    chara[2] = &eBullet;


    for (int i = 0;i < num;i++) {//15
        chara[i]->init();//0,8
    }
    while(notQuit) {
        for (int i = 0;i < num;i++) {
            chara[i]->move();
        }
        clear();
        for (int i = 0;i < num;i++) {
            chara[i]->draw();
        }
    }
}
*/
/*
#include"libOne.h"
class Enemy {
protected:
    int Img;
    float Px, Py, Vx;
public:
    void setImage(int img){
        Img = img;
    }
    void init() {
        Px = random() % (int)width;
        Py = random() % (int)height;
        Vx = random() % 5 + 1.0f;
    }
    void move() {
        Px += Vx;
    }
    void draw() {
        image(Img, Px, Py);
    }
};
void gmain() {
    window(1920, 1080,full);
    hideCursor();
    int enemyImg = loadImage("assets\\enemy.png");
    int num = 10;
    Enemy* enemy = new Enemy[num];//17
    for (int i = 0;i < num;i++) {
        enemy[i].setImage(enemyImg);
    }
    for (int i = 0;i < num;i++) {
        enemy[i].init();
    }
    while (notQuit) {
        clear();
        for (int i = 0;i < num;i++) {
            enemy[i].draw();
        }
        for (int i = 0;i < num;i++) {
            enemy[i].move();
        }
    }
    delete []enemy;//18
}
*/
/*
#include"libOne.h"
class Player {
protected:
    float Px = 0, Py = 0, Vx = 0;
    int Img = 0;
public:
    void init() {
        Px = random() % (int)width;
        Py = random() % (int)height;
        Vx = random() % 5 + 1.0f;
    }
    void setImage(int img) {
        Img = img;
    }
    void move() {
        Px += Vx;
    }
    void draw() {
        image(Img, Px, Py);
    }
};
void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");
    int num = 1000;
    Player* player = new Player[num];
    for (int i = 0;i < num;i++) {
        player[i].setImage(playerImg);
    }
    for (int i = 0;i < num;i++) {
        player[i].init();
    }
    while (notQuit) {
        clear(3, 252, 227);
        for (int i = 0;i < num;i++) {
            player[i].draw();
        }
        for (int i = 0;i < num;i++) {
            player[i].move();
        }
    }
    delete[] player;
}
*/
//�O�֐����h�b�g�ŌĂяo�����Ƃ��ł���
//�P�N���X�͐݌v�}�A��ʓI�ɕϐ��Ɗ֐����ꏏ�ɂ������̂��N���X�ƌĂ�
//�Q�N���X�ƃX�g���N�g�̈Ⴂ�̓N���X�͍ŏ�����v���C�x�[�g�B����Ă���
//�R�J�v�Z�����̖ړI�̓J�v�Z���̊O�ŕϐ����L�q����̂��ړI
//�S�X�g���N�g�ȗ�
//�T�p���A���N���X�Ǝw��N���X�A�p���͉����炷�ׂĉ��q�Ɏ󂯌p���悤�ɂ��̂��ׂĂ��󂯌p��
//�U�v���C�x�[�g�ƈႢ�A�v���e�N�e�B�b�h�͌p����̃N���X�͎g�p���邱�Ƃ��ł���
//�V�p�����̃N���X�̃|�C���^�[�Ɍp�������v���C���[�̎��̂̃A�h���X�����鎖���o����
//�W�|�C���^�[�̎��Ƀ����o�[���w�����́[����t����
//�X�h�������֐����g���ɂ́A virtual���g��
//�P�O�p���ŏ㏑������֐��̓��@�[�`������t���Ƃ��΂���
//C++�Α̐��i�|�����[�t�B�Y���j�n�����̂̃A�h���X�ɂ���ĕς���Ă���C�j�b�g���牺�̕����͂܂������ύX���Ă��Ȃ��̂ɕς��
//�P�P���N���X�ɂ��A�h���X��ς���Ƃ܂������Ⴍ���ʂɂȂ�
//�P�Q�n�����̂̂��Ƃ��C���X�^���X�ƌĂԃI�u�W�F�N�g�Ƃ�
//�P�R���N���X�̃|�C���^�[��num�p�ӂ��遁�A�h���X�̋L���ꏊ��num�p�ӂ���
//�P�S�A3�̃|�C���^�[�ɂ��ꂼ��A�e�X�̃A�h���X���L��������
//�P�T�z��̃A�h���X����֐����Ăяo���Ƃ��ɂ́D�ł͂Ȃ�[i]�[��
//�P�T.�T�Achara[i]�ɂ̓A�h���X���L������Ă���̂ŃA�h���X����֐����w���Ƃ��́[��
//�P�U���{�{�̃������̓��I�m�ہ@new��delete���g���Amalook,free�̂b�{�{�o�[�W����
//�P�V�z��̃|�C���^�[�Ɠ����Ȃ̂�[i].�Ŏw�肷��
//�P�V�D�T1�̔z��^����Ȃ��ꍇ�͍\���̌^�Ɠ����ŁE����Ȃ�->��t����
//�P�W1�̓��I�m�ۂ̏ꍇ��delete�����z��^�Ȃ̂�[]��t����
