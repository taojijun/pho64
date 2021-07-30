void on_pushButton_8_clicked();
void on_pushButton_clicked();
void on_pushButton_2_clicked();
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define PI                  (3.1415926535897932384626433832795)
#define	RAD                 (PI/180.0)
#include <QMainWindow>
#include <QUdpSocket>
#include <QDebug>
#include <QUdpSocket>
#include <QTime>
#include <QFrame>
#include <QMenu>
#include <QList>
#include <QModelIndex>
#include <assert.h>
#include <QVector>
#include <array>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>
#include <QDateTime>
#include <dialog.h>
#include <form___.h>
#include <QMouseEvent>
#include <time.h>
#include <config.h>
#include <QThread>

#include <QDebug>
#include <QTime>
#include <assert.h>
#include <array>

#include <QLibrary>
#include <QMutex>
#include <QTimer>

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <Windows.h>
#include <io.h>
#include<opencv2\opencv.hpp>
#include <QImage>
#pragma execution_character_set("utf-8")

//#define PTZ_ZOOM_IN_			11	/* 焦距以速度SS变大(倍率变大) */
//#define PTZ_ZOOM_OUT_			12	/* 焦距以速度SS变小(倍率变小) */
//#define PTZ_FOCUS_NEAR_		13	/* 焦点以速度SS前调*/
//#define PTZ_FOCUS_FAR_			14	/* 焦点以速度SS后调*/
//#define PTZ_IRIS_ENLARGE_		15	/* 光圈以速度SS扩大*/
//#define PTZ_IRIS_SHRINK_		16	/* 光圈以速度SS缩小*/
//#define PTZ_UP_					21	/* 云台以SS的速度上仰*/
//#define PTZ_DOWN_				22	/* 云台以SS的速度下俯*/
//#define PTZ_LEFT_				23	/* 云台以SS的速度左转*/
//#define PTZ_RIGHT_				24	/* 云台以SS的速度右转*/
//#define PTZ_RIGHTUP_		25	/* 云台以SS的速度右上仰*/
//#define PTZ_RIGHTDOWN_			26	/* 云台以SS的速度右下仰*/
//#define PTZ_LEFTUP_				27	/* 云台以SS的速度左上仰*/
//#define PTZ_LEFTDOWN_			28	/* 云台以SS的速度左下仰*/

using namespace std;
extern "C"
{
        #include "inc/STDCALL/tmControlClient.h"
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    //设置窗口
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
void mouseReleaseEvent(QMouseEvent *event);
private:
    QPoint mousePoint;
    bool mouse_press;

public:
    static int WINAPI Register_( HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context );//注册
    static int WINAPI Callback_( HANDLE hTmCC, tmAvImageInfo_t* pImage, void* context );//输出

    cv::Mat bufferToMat(unsigned char* pBuffer, int nWidth, int nHeight, int nBandNum, int nBPB);
    cv::VideoWriter writeVideo;//录制视频
    QTimer *fTimer;



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void tail_after();//当前视角跟踪指令
    void tail_after_over();//释放跟踪


    QString ip = "192.168.1.4";
    int port = 9966;
    int FLAG;


    int flag_satrt = 1;
    int flag_satrt1 = 1;
    int flag_satrt2 = 1;
    int flag_satrt3 = 1;
    int flag_start4 = 1;
//    int flag_start5 = 1;

    int red = 0;
    int readdata = 1;//标志变量，1表示第一个数据，0表示第二个数据
    double P[3] = {0,0,0},P1[3] = {0,0,0},P2[3] = {0,0,0};//存放经纬高信息
    double jl = 0;//存放无人机的飞行距离
    double spend = 0;//存放无人机的速度
    double derc = 0;//存放无人机的飞行方向
    double time = 0;//计时
    Dialog *dialog_ = new Dialog;
    //定位模块配置
    void sjjs(double level,double pitch,double dis,double time,double min_spend,double max_spend,double s_min,double s_max,double h_min,double h_max,QString K,double v_min,double v_max,double speed,double jg,double height,bool mr,QString model);
    void instruct();
    void instruct_(double p1,double p2,double p3);
    // 水平角
    double level__ = 0;
    // 俯仰角
    double pitch__ = 0;
    // 距离
    double dis__ = 0;
    // 时间
    double time__ = 1;
    // 最小速度
    double min_spend__ = 3;
    //最大速度
    double max_spend__ = 30;
    //最小距离
    double s_min_ = 0;
    //最大距离
    double s_max_ = 600;
    //最小高度
    double h_min_ = 30;
    //最大高度
    double h_max_ = 200;
    //天气
    QString K_ = "晴天";
    //最小水平角
    double v_min_ = 20;
    //最大水平角
    double v_max_ = 40;
    //云台速度
    double speed_ = 20;
    //间隔
    double jg_ = 200;
    //可见光高度
    double height_ = 7.2;
    //默认
    bool mr_ = false;
    //跟踪模式
    QString model_ = "引导并跟踪";
    //俯仰角范围
    double FY_ = 1;
    double FY1_ = 90;
    //雷达光电自动跟踪中间变量
    int FLAG_1 = 1;
    int FLAG_2 = 0;
    Config c;
    double v_ = -1;
    double h_ = -1;
    double v_cha = -1;
    double h_cha = -1;

    QUdpSocket *udpSocket;
    QUdpSocket *udpSockett;
    QUdpSocket *udpsocket_radar;
    void style();
    void Sleep(int time);
    HANDLE sign_in(HANDLE hCtl);
    HANDLE hCtl1;//基本控制
    HANDLE hCtl2;//自动聚焦
    HANDLE hCtl3;//雨刷器
    HANDLE hCtl4;//灯光
    HANDLE hCtl5;//风扇
    HANDLE hCtl6;//192.168.1.4设备控制句柄
    HANDLE hCtl7;

    void single_click(int pattern,int speed);
    void single_press(int pattern,int speed);
    void single_cancel(int pattern,int speed);
    void single_press_(int pattern,int speed);
    void single_cancel_(int pattern,int speed);
    void CProtocal_(double,double,double);
    void CProtocal__(double);
    void CProtocal___(int,int,int,int,int,int);
    void Data_Conversion_(double longitude,double latitude,double height);
    //(L1,B1)为初始点的经纬度，(L2,B2)为目标点的经纬度
    //Angel为(L1,B1)指向(L2,B2)的方位，Distance为(L1,B1)与(L2,B2)之间的距离
    void CalcAngleDistance(const double& L1, const double& B1, const double& L2, const double& B2, double& Angel, double& Distance);
    bool Calculate_A1_S(double B1, double L1, double B2, double L2, double rx, double re[2]);

public:
    typedef struct tagGMT_T
    {
        int	zone;
        char name[128];
    }GMT_T;
    GMT_T GMT_mins[61]=
    {
        {-720, "(GMT-12:00) Eniwetok, Kwajalein"},
        {-660, "(GMT-11:00) Midway Island, Samoa"},
        {-600, "(GMT-10:00) Hawaii"},
        {-540, "(GMT-9:00) Alaska"},
        {-480, "(GMT-8:00) Pacific Time(US & Canada); Tijuana"},
        {-420, "(GMT-7:00) Arizona"},
        {-420, "(GMT-7:00) Mountain Time(US & Canada)"},
        {-360, "(GMT-6:00) Saskatchewan"},
        {-360, "(GMT-6:00) Mexico City, Tegucigalpa"},
        {-360, "(GMT-6:00) Central Time(US & Canada)"},
        {-300, "(GMT-5:00) Indiana(East)"},
        {-300, "(GMT-5:00) Bogata, Lima, Quito"},
        {-300, "(GMT-5:00) Eastern Time(US & Canada)"},
        {-240, "(GMT-4:00) Caracas, La Paz"},
        {-240, "(GMT-4:00) Atlantic Time(Canada)"},
        {-210, "(GMT-3:30) Newfoundland "},
        {-180, "(GMT-3:00) Buenos Aires, Georgetown"},
        {-180, "(GMT-3:00) Brasilia"},
        {-120, "(GMT-2:00) Mid Atlantic"},
        {-60, "(GMT-1:00) Azores, Cape Verde Is."},
        {0,   "(GMT) Greenwich Mean Time: Dublin, Edinburgh, Lisbon"},
        {0,   "(GMT) Casablanca, Monrovia"},
        {60,  "(GMT+1:00) Amsterdam, Copenhagen, Madrid, Paris, Vilniius"},
        {60,  "(GMT+1:00) Belgrade, Sarajevo, Skopje, Sofija, Zagreb"},
        {60,  "(GMT+1:00) Bratislava, Budapest, Ljubljana, Prague, Warsaw"},
        {60,  "(GMT+1:00) Brussels, Berlin, Bern, Rome, Stockholm, Vienna"},
        {120, "(GMT+2:00) Athens, Istanbul, Minsk"},
        {120, "(GMT+2:00) Bucharest"},
        {120, "(GMT+2:00) Cairo"},
        {120, "(GMT+2:00) Harare, Pretoria"},
        {120, "(GMT+2:00) Israel"},
        {180, "(GMT+3:00) Bagdad, Kuwait, Riyadh"},
        {180, "(GMT+3:00) Moscow, St.Petersburg, Volgograd"},
        {180, "(GMT+3:00) Nairobi"},
        {210, "(GMT+3:30) Tehran"},
        {240, "(GMT+4:00) Abu Dhabi, Muscat"},
        {240, "(GMT+4:00) Baku, Tbilisi"},
        {270, "(GMT+4:30) Kabul"},
        {300, "(GMT+5:00) Ekaterinburg"},
        {300, "(GMT+5:00) Islanabad, Karachi, Tashkent"},
        {330, "(GMT+5:30) Bombay, Calcutta, Madras, New Delhi"},
        {360, "(GMT+6:00) Almaty, Dhaka"},
        {360, "(GMT+6:00) Colombo"},
        {420, "(GMT+7:00) Bangkok, Hanoi, Jakarta"},
        {480, "(GMT+8:00) Beijing, Chongqing, Hongkong, Urumqi"},
        {480, "(GMT+8:00) Perth"},
        {480, "(GMT+8:00) Sigapore"},
        {480, "(GMT+8:00) Taipei"},
        {540, "(GMT+9:00) Osaka, Sapporo, Tokyo"},
        {540, "(GMT+9:00) Seoul"},
        {540, "(GMT+9:00) Yakutsk"},
        {570, "(GMT+9:30) Adelaide"},
        {570, "(GMT+9:30) Darwin"},
        {600, "(GMT+10:00) Brisbane"},
        {600, "(GMT+10:00) Canberra, Melbourne, Sydney"},
        {600, "(GMT+10:00) Guam, Port Moresby"},
        {600, "(GMT+10:00) Hobart"},
        {600, "(GMT+10:00) Vladivostok"},
        {660, "(GMT+11:00) Magadan, Solomon Is., New Caldonia"},
        {720, "(GMT+12:00) Auckland, Wellington"},
        {720, "(GMT+12:00) Fiji, Kamchatka, Marshall Is."}
    };
    enum TARGET_TYPE
    {
        TARGET_TYPE_UAV_ = 1,  // 无人机
        TARGET_TYPE_AIRPLANE_ = 2,  // 飞机
        TARGET_TYPE_FIX_AIRPLANE_ = 3,  // 固定翼飞机
        TARGET_TYPE_PERSON_ = 4,  // 人
        TARGET_TYPE_CAR_ = 5,  // 汽车
        TARGET_TYPE_BICYCLE_ = 6,  // 自行车
        TARGET_TYPE_BOAT_ = 7,  // 轮船
        TARGET_TYPE_MOTORBOAT_ = 8,  // 汽艇
    };
    struct HEAD{
        // 起始位 1
        unsigned int startbit =0;
        // 协议号 2
        unsigned int pronumber = 0;
        // 包长度 3
        // =命令字+时间戳+信息内容+信息序列号+错误校验
        unsigned int packetlen = 0;
        // 命令字 4
        unsigned int cmd = 0;
        // 时间戳 5
        unsigned long long timestamp___ = 0;
    };
    struct STATE{
        // 光电编号
        unsigned int number = 0;
        // 光电当前状态时间戳
        unsigned long long timestamp = 0;
        // 工作状态 0-异常 1-正常
        unsigned int state = 0;
        // 工作模式 0-空闲 1-搜索 2-跟踪
        unsigned int mode = 0;
        // 故障编码
        unsigned long long code;
        // 预留
        unsigned int reserved;
    };
    struct PITCH{
        // 光电编号
        unsigned int number =0;
        // 光电当前状态时间戳
        unsigned long long timestamp = 0;
        // 水平角度
        double hor_angle = 0;
        // 俯仰角度
        double ver_angle = 0;
        // 距离
        double distance = 0;
        // 水平角速度
        double hor_speed = 0;
        // 俯仰角速度
        double ver_speed = 0;
        // 高度
        short height = 0;
        // 镜头倍率
        byte lens_zoom = 0;
        // 预留
        byte reserved = 0;

    };
    PITCH pitch_;//光电当前状态信息
    struct EXTEND
    {
    // 光电编号
    unsigned int number = 0;
    // 光电当前状态时间戳
    unsigned long long timestamp = 0;
    // 工作状态
    unsigned int state = 0;
    // 数据长度
    unsigned int data_len =0;
    };
    struct KX
    {
    // 空闲时间
    unsigned int time =0;
    };
    struct SEARCH
    {
        unsigned int timestamp; /**持续时间(秒)*/
        unsigned int target_count; /**已搜索到的目标数量*/
        // 数据长度
        unsigned int data_len = 0;
    };
    struct TARGET
    {
    //目标编号
    unsigned int number = 0;
    //目标类型
    unsigned int type = 0;
    //相似度
    unsigned int xsd = 0;
    //目标宽度
    unsigned int kd = 0;
    //目标高度
    unsigned int gd = 0;
    //目标方位角
    double fwj = -1;
    //目标俯仰角8
    double fyj = -1;
    };
    TARGET target_;//当前搜索目标信息
    struct GZ
    {
    //时间戳
    unsigned int time = 0;
    //用户id
    unsigned short uid = 0;
    //转态：0丢失，1锁定
    unsigned short zt = 0;
    };
    //目标上报信息包
    struct Target_reporting{
        //时间戳
        unsigned int time = 0;
        //目标个数
        unsigned int number = 0;
        //后续数据大小
        unsigned int size = 0;

    };
    //目标上报信息描述
    struct Target_information_description{
        //目标编号
        unsigned int number = 0;
        //目标类型
        unsigned int type = 0;
        //相似度
        unsigned int xsd = 0;
        //目标宽度
        unsigned int kd = 0;
        //目标高度
        unsigned int gd = 0;
        //物理宽度
        unsigned int wlkd = 0;
        //物理高度
        unsigned int wlgd = 0;
        //运动方向
        unsigned char ydfx = 0;
        //保留字段
        unsigned char blzd[3] = {0};
        //水平速度
        unsigned short spsd = 0;
        //垂直速度
        unsigned short czsd = 0;
        //物理水平速度
        unsigned short wlspsd = 0;
        //物理垂直速度
        unsigned short wlczsd = 0;
        //目标方位角
        double mbfwj = 0;
        //目标俯仰角
        double mbfyj = 0;
        //保留字段
        unsigned int blzd2 = 0;

    };

    struct TPosInfo  //定位模块数据接口
    {
        unsigned char Head;//0xdd
        unsigned short UTC_Year;
        unsigned char UTC_Month;
        unsigned char UTC_Day;
        unsigned char UTC_Hour;
        unsigned char UTC_Min;
        unsigned char UTC_Sec;
        double GPS_L;
        double GPS_B;
        double GPS_H;
        double GPS_Speed;
        double GPS_Ceta;
        unsigned short BDT_Year;
        unsigned char BDT_Month;
        unsigned char BDT_Day;
        unsigned char BDT_Hour;
        unsigned char BDT_Min;
        unsigned char BDT_Sec;
        double BD_L;		//经度
        double BD_B;		//纬度
        double BD_H;		//高度(海拔高)
        double BD_Speed;
        double BD_Ceta;
    };

    //雷达模块接口
    // 1.心跳数据，时间间隔不大于1秒。
    struct HeartBeat                    //共24字节
    {
        quint32     hb_radarNo;         // 雷达编号
        float       hb_azimuth;         //天线方位角 单位：度
        float       hb_elevation;       //天线俯仰角 单位：度
        float       hb_preserve;        //备用 单位：米/秒
        quint64     hb_time;            //时间戳 自 0001 年 1 月 1 日午夜 12:00:00 以来已经过的时间的以 100 毫微秒为间隔的间隔数，
    };

    // 2.目标数据 发现目标才报
    struct UnmannedAerialVehicle        //共64字节
    {
        quint32     uav_radarNo;        // 雷达编号
        quint32     uav_targetNo;       //目标编号  从1开始递增

        float       uav_targetDist;     //目标距离单位：米
        float       uav_azimuth;        //目标方位角 单位：度
        float       uav_elevation;      //目标俯仰角 单位：度
        float       uav_intensity;      //目标强弱
        float       uav_speed;          //目标径向速度 米/秒
        float       uav_longitude;      //目标经度 单位：度  正为东经，负为西经；
        float       uav_latitude;       //目标纬度 单位：度  正为北纬，负为南纬；
        float       uav_height;         //目标海拔 单位：米
        float       uav_course;         //目标航向 单位：度
        float       uav_navigatespeed;  //目标航速 单位：米/秒

        quint32     uav_preserve1;      //备用1  从1开始递增
        quint32     uav_preserve2;      //备用2  从1开始递增
        quint64     uav_time;           //时间戳 自 0001 年 1 月 1 日午夜 12:00:00 以来已经过的时间的以 100 毫微秒为间隔的间隔数，
    };
    struct Uav_Data //无人机数据
    {
        bool ifone = true;//是否第一次经纬高数据
        float time = 0;//时间纪录
        float speed = 0;//无人机速度：米/秒
        float distance = 0;//无人机距离：米
        float P[3][3] = {{0,0,0},{0,0,0},{0,0,0}};//p[0]存放第一次经纬高p[1]存放第二次经纬高p[2]存放引导经纬高
    }uav_data[1000];



public slots:
           void receiverdata_();
           void receiverdata__();
           void receiverdata_radar();
           void SPSave();

private slots:
           void on_pushButton_uav_4_clicked();

           void on_pushButton_uav_3_clicked();

           void on_pushButton_release_2_clicked();

           void on_pushButton_track_9_clicked();

           void on_pushButton_track_8_clicked();

           void on_pushButton_track_10_clicked();

           void on_pushButton_13_clicked();

           void on_pushButton_13_pressed();

           void on_pushButton_13_released();

           void on_pushButton_16_clicked();

           void on_pushButton_16_pressed();

           void on_pushButton_16_released();

           void on_pushButton_14_clicked();

           void on_pushButton_14_pressed();

           void on_pushButton_14_released();

           void on_pushButton_15_clicked();

           void on_pushButton_15_pressed();

           void on_pushButton_15_released();

           void on_pushButton_30_clicked();

           void on_pushButton_30_pressed();

           void on_pushButton_30_released();

           void on_pushButton_29_clicked();

           void on_pushButton_29_pressed();

           void on_pushButton_29_released();

           void on_pushButton_17_clicked();

           void on_pushButton_17_pressed();

           void on_pushButton_17_released();

           void on_pushButton_18_clicked();

           void on_pushButton_18_pressed();

           void on_pushButton_18_released();

           void on_pushButton_19_clicked();

           void on_pushButton_19_pressed();

           void on_pushButton_19_released();

           void on_pushButton_20_clicked();

           void on_pushButton_20_pressed();

           void on_pushButton_20_released();

           void on_pushButton_21_clicked();

           void on_pushButton_21_pressed();

           void on_pushButton_21_released();

           void on_pushButton_22_clicked();

           void on_pushButton_22_pressed();

           void on_pushButton_22_released();

           void on_pushButton_23_clicked();

           void on_pushButton_23_pressed();

           void on_pushButton_23_released();

           void on_pushButton_24_clicked();

           void on_pushButton_24_pressed();

           void on_pushButton_24_released();
           void on_pushButton_track_6_clicked();

           void on_pushButton_track_7_clicked();

           void on_pushButton_2_clicked();

           void on_pushButton_31_clicked();

           void on_pushButton_clicked();



           void on_pushButton_4_clicked();

           void on_pushButton_3_clicked();

           void on_pushButton_5_clicked();


           void on_pushButton_track_11_clicked();

           void on_pushButton_6_clicked();

           void on_pushButton_7_clicked();


           void on_pushButton_9_clicked();



           void on_pushButton_track_12_clicked();

           void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};
class Text
{
public:
    bool isValid();
    int parse(const unsigned char* lpData, int len);
    int construct(unsigned char* buff, int len);

    unsigned int getNumber() { return number; }
    unsigned int getSysNumber() { return sys_number; }
    unsigned long long getTimestamp() { return timestamp; }
    double getLng() { return lng; }
    double getLat() { return lat; }
    double getHeight() { return height; }
    double getDistance() { return distance; }
    double getHorAngle() { return hor_angle; }
    double getVerAngle() { return ver_angle; }

    void setNumber(int v){ number = v; }
    void setSysNumber(int v) { sys_number = v; }
    void setTimestamp(unsigned long long v) { timestamp = v; }
    void setLng(double v) { lng = v; }
    void setLat(double v){ lat = v; }
    void setHeight(double v){ height = v; }
    void setDistance(double v){ distance = v; }
    void setHorAngle(double v){ hor_angle = v; }
    void setVerAngle(double v){ ver_angle = v; }

public:
    /// 光电编号 1
    unsigned int number =0;
    /// 系统编号 2
    unsigned int sys_number = 0;
    /// 系统下发 时间戳 3
    unsigned long long timestamp = 0;
    /// 目标经度 4
    double lng = 0;
    /// 目标纬度 5
    double lat = 0;
    /// 目标高度 6
    double height = 0;
    /// 目标距离 7
    double distance = 0;
    /// 水平角度 7
    double hor_angle = 0;
    /// 俯仰角度 8
    double ver_angle = 0;
    /// 预留
    unsigned char reserved[4];
    const int protocal_head = 68;
};

class Head
{
public:
    bool isValid();

    int getDataLen(){ return data.data_len; }
    int getDataTotalLen();

    int getCmd(){ return cmd; }
    void setCmd(int v){ cmd = v; }

    int parse(const unsigned char* lpData, int len);
    int construct(unsigned char* buff, int len);
public:
    void setAttachDataLen(int len) { data.data_len = len; }
    int append(unsigned char* buff, const unsigned char* data, int len);

    int getData(unsigned char*&);
    void valid(bool v) { valid__ = v; }

public:
    /**
    * @brief 协议头
    */
    /// 起始位 1
    unsigned int start_bit =0;
    /// 协议号 2
    unsigned int pro_number = 0;
    /// 包长度 3
    /// =命令字+时间戳+信息内容+信息序列号+错误校验
    unsigned int packet_len = 0;
    /// 命令字 4
    unsigned int cmd = 0;
    /// 时间戳 5
    unsigned long long timestamp = 0;
    /// 信息内容
    struct
    {
        int data_len;
//        QVector<unsigned char> buff;

        std::array<unsigned char,1024*8> buff;

    }data;
    /// 信息序列号 7
    /// 第一条 1,每次累加
    unsigned int message_index = 0;
    /// 错误校验 8
    unsigned int verify = 0;
    /// 停止位
    unsigned int stop_bit = 0;

    bool valid__ =false;
};

/**
* @brief 光电镜头控制信息包
*/
class CCameraLensInfoProtocal
{
public:
    enum
    {
        FOCUS = 0x01,//跳转到指定物理焦距
        ZOOM = 0x02,// 跳转到指定倍数
        COMPOSE = 0x03,//跳转到指定zoom和focus位置
    };
public:
    CCameraLensInfoProtocal() = default;
    virtual ~CCameraLensInfoProtocal() = default;

    virtual int construct(BYTE* buff, int len);

    unsigned int getNumber() { return number_; }
    unsigned int getSysNumber() { return sys_number_; }
    unsigned long long getTimestamp() { return timestamp_; }
    unsigned int getCmd() { return cmd_; }
    unsigned int getZoom() { return zoom_; }
    unsigned int getZoomStep() { return zoom_step_; }
    unsigned int getFocusStep() { return focus_step_; }

    void setNumber(int v) { number_ = v; }
    void setSysNumber(int v) { sys_number_ = v; }
    void setTimestamp(unsigned long long v) { timestamp_ = v; }
    void setCmd(unsigned int v) { cmd_ = v; }
    void setZoom(unsigned int v) { zoom_ = v; }
    void setZoomStep(unsigned int v) { zoom_step_ = v; }
    void setFocusStep(unsigned int v) { focus_step_ = v; }
private:
    /// 光电编号
    unsigned int number_ = 0;
    /// 系统编号
    unsigned int sys_number_ = 0;
    /// 时间戳
    unsigned long long timestamp_ = 0;
    /// 控制命令
    unsigned int cmd_ = 0;
    /** @brief 物理焦距/倍数 ..
        当镜头控制命令为 0x01时表示镜头的物理焦距, 单位mm 如150mm；
        当控制命令为0x02时表示镜头倍数，如42倍。
        当镜头控制命令为0x03时此字段作为保留不使用
    */
    unsigned int zoom_ = 0;
    /// zoom位置. 当镜头控制命令为0x03时有效，表示zoom的步数
    unsigned int zoom_step_ = 0;
    /// Focus 位置 .. 当镜头控制命令为0x03时有效，表示focus的步数
    unsigned int focus_step_ = 0;
    /// 预留
    unsigned int reserved_ = 0;
    static const int protocal_head_len = 36;
};
/// <summary>
/// 设置光电搜索跟踪信息包
/// </summary>
class CCameraCtrlProtocal
{
public:
    enum
    {
        SEARCH = 1,//搜索并自动跟踪
        TRACK = 2,//跟踪
        FREE = 3,//释放
        ONLY_SEARCH = 4//仅搜索
    };
public:
    CCameraCtrlProtocal() = default;


    virtual int construct(BYTE* buf,int len);
    unsigned int getNumber() { return number_; }
    unsigned long long getTimestamp() { return timestamp_; }
    unsigned int getCmd() { return cmd_; }
    double getHorStartAngle() { return hor_start_angle_; }
    double getHorEndAngle() { return hor_end_angle_; }
    double getVerStartAngle() { return ver_start_angle_; }
    double getVerEndAngle() { return ver_end_angle_; }

    void setNumber(int v) { number_ = v; }
    void setTimestamp(unsigned long long v) { timestamp_ = v; }
    void setCmd(int v) { cmd_ = v; }
    void setHorStartAngle(double v) { hor_start_angle_ = static_cast<int>(v); }
    void setHorEndAngle(double v) { hor_end_angle_ = static_cast<int>(v); }
    void setVerStartAngle(double v) { ver_start_angle_ = static_cast<int>(v); }
    void setVerEndAngle(double v) { ver_end_angle_ = static_cast<int>(v); }
    void setTargetNumber(int v);

    /**
    * 0--在当前视场里搜索
    * 1--向上移动当前视场再搜索
    * 2--向下移动当前视场再搜索
    * 3--向左移动当前视场再搜索
    * 4--向右移动当前视场再搜索
    * 5--镜头向后拉一倍再搜索
    * 6--镜头向前推一倍再搜索
    * 7-从左顺时针搜索
    * 8-从上顺时针搜索
    * 9-从右顺时针搜索
    * 10-从下顺时针搜索
    * 11-按指定搜索范围搜索
    */
    void setSearchMode(int v);
private:
    /// 光电编号 1
    unsigned int number_ = 0;
    /// 系统下发 时间戳 2
    unsigned long long timestamp_ = 0;
    /// 指控指令 1:搜索并自动跟踪；2：跟踪；3：释放; 4:仅搜索
    unsigned int cmd_ = 0;
    /// 水平开始角度
    int hor_start_angle_ = 0;
    /// 水平结束角度
    int hor_end_angle_ = 0;
    /// 俯仰开始角度
    int ver_start_angle_ = 0;
    /// 俯仰结束角度
    int ver_end_angle_ = 0;
    /// 预留 目标编号（跟踪指定目标使用）
    uint8_t reserved_[4] = {0};
    const uint32_t protocal_head_len = 36;
};
#endif // MAINWINDOW_H
