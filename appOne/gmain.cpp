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
    void operator+=(const FLOAT5& f2) {//21.5、23.5
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
//C++５コンストラクタ・デストラクタという関数
#include"libOne.h"
class HAPPY {
public:
    HAPPY() {//1
        textSize(200);
        text("ハッピー", 0, 300);
    }
    ~HAPPY() {//２
        textSize(200);
        text("ウェディング", 300, 600);
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
//C＋＋６、ファイル分割
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
//1クラスの名前と同じ関数をコンストラクタ関数という、voidも付けてはならない
//1.5この関数は、関数を呼び出さなくても自動で実行される関数。
//2デストラクタという関数で~を付け、クラスの終了タイミングで実行される関数
//C++６[ファイル分割]
//3普通のclassの中に関数宣言をしていく
//4クラス名::を入れる、入れないと普通の関数扱いになる
//5includeで関数宣言する
//C++7[参照・ポインターはいらんのか？]
//6・6.5普通のポインター型・アドレスを渡し構造体やクラスの値を変える代入する方法
//7参照型　アドレスはではなく実体を渡す
//8＆＝参照だとf2とposが同じ記憶場所になる
//C++8[thisポインタとは]
//9コンストラクタ関数
//10実体化するときのコンストラクタに渡す数字
//11ただのx=x、y=yだとエラーが出るのでthisポインタで区別する
//11.5Thisポインタは実体(pos3)のアドレスが自動的に入る
//C++9[初期化と代入は区別しよう]
//12初期化、1x=0、2：x(0)セミコロンを使って初期化することもできる
//13配列の初期化
//14代入pos = FLOAT2(100,10)のように代入することもできる
//C++10[演算子のオーバーロード]
//15pos5の値にvecを足した値を出したいときの今までのやり方
//16.15を一行にpos＋vecと数学的に短くまとめたい（演算子のオーバーロード）を使う
//16.5わかりやすい、メンバー関数を用いた納得しやすい形
//17メンバー関数、参照を使いFLOAT5を返している
//18oprator（演算子）＋てすると＋に17の機能を追加している
//18.5plusの機能を与えることで18.5を使用することができる
//19オバーロード（多重定義）float型を定義している
//19.5も多重定義、引数の違いで同じ名前で複数定義している（コンストラクタのオーバーロード）
//20.20.5でーを多重定義することで便利に簡単にベクトルを求めている
//21.21.5で＊を多重定義、移動など
//22正規化
//23posに正規化した値を＊て+=している、23.5constを付けている
//まとめ、FLOAT5という自分で作った型で＊＋ーすることで
//ベクトルの計算などが一行以下で済むようになる
/*
class CHARACTER {//１キャラクターの設計図
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
    PLAYER player;//４
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
//０関数もドットで呼び出すことができる
//１クラスは設計図、一般的に変数と関数を一緒にしたものをクラスと呼ぶ
//２クラスとストラクトの違いはクラスは最初からプライベート。守られている
//３カプセル化の目的はカプセルの外で変数を記述するのが目的
//４ストラクト省略
//５継承、基底クラスと指定クラス、継承は王からすべて王子に受け継ぐようにそのすべてを受け継ぐ
//６プライベートと違い、プロテクティッドは継承先のクラスは使用することができる
//７継承元のクラスのポインターに継承したプレイヤーの実体のアドレスを入れる事が出来る
//８ポインターの時にメンバーを指す時はー＞を付ける
//９派生した関数を使うには、 virtualを使う
//１０継承で上書きする関数はヴァーチャルを付けとけばいい
//C++対体制（ポリモーフィズム）渡す実体のアドレスによって変わってくるイニットから下の部分はまったく変更していないのに変わる
//１１基底クラスにすアドレスを変えるとまったく違く結果になる
//１２渡す実体のことをインスタンスと呼ぶオブジェクトとも
//１３基底クラスのポインターをnum個用意する＝アドレスの記憶場所をnum個用意する
//１４、3個のポインターにそれぞれ、各々のアドレスを記憶させる
//１５配列のアドレスから関数を呼び出すときには．ではなく[i]ー＞
//１５.５、chara[i]にはアドレスが記憶されているのでアドレスから関数を指すときはー＞
//１６ｃ＋＋のメモリの動的確保　newとdeleteを使う、malook,freeのＣ＋＋バージョン
//１７配列のポインターと同じなので[i].で指定する
//１７．５1個の配列型じゃない場合は構造体型と同じで・じゃなく->を付ける
//１８1個の動的確保の場合はdeleteだが配列型なので[]を付ける
