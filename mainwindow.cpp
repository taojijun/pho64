#include "mainwindow.h"
#include "ui_mainwindow.h"



using namespace cv;
template<class O, class V>
int Value(O& o, V v)
{
    o = v;
    return sizeof(O);
}

QMutex mut;
BYTE buf[6220800] = {0};
cv::Mat frame;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags (Qt::CustomizeWindowHint);
//    this->setWindowFlags(Qt::FramelessWindowHint);

    style();
    fTimer = new QTimer;
    connect(fTimer,SIGNAL(timeout()),this,SLOT(SPSave()));

    udpSocket=new QUdpSocket(this);
    udpSocket->bind(QHostAddress("192.168.1.10"),9966, QUdpSocket::ShareAddress);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(receiverdata_()));
    udpSockett=new QUdpSocket(this);
    udpSockett->bind(QHostAddress("192.168.1.10"),16001, QUdpSocket::ShareAddress);
    connect(udpSockett,SIGNAL(readyRead()),this,SLOT(receiverdata__()));
    udpsocket_radar=new QUdpSocket(this);
    udpsocket_radar->bind(QHostAddress("192.168.1.10"),5656, QUdpSocket::ShareAddress);
    connect(udpsocket_radar,SIGNAL(readyRead()),this,SLOT(receiverdata_radar()));

    connect(dialog_,&Dialog::A,this,&MainWindow::sjjs);

    HWND m_hwndDisplay = (HWND)ui->frame_2->winId();
    HANDLE hRealStream = TMCC_Init( TMCC_INITTYPE_REALSTREAM );
    hCtl6 = hRealStream;
    TMCC_SetAutoReConnect(hRealStream, TRUE);    // 可选设置自动重连，网络断开后，SDK会尝试重连设备
    TMCC_SetStreamBufferTime(hRealStream, 500);    // 设置缓冲时间，用于控制视频播放流畅性，解码且显示才用得上
    TMCC_SetImageOutFmt(hRealStream,3);
    tmPlayRealStreamCfg_t stuRealStream;
    memset(&stuRealStream, 0, sizeof(tmPlayRealStreamCfg_t));
    stuRealStream.dwSize = sizeof(tmPlayRealStreamCfg_t);
    sprintf(stuRealStream.szAddress, "192.168.1.4");
    sprintf(stuRealStream.szUser, "system");
    sprintf(stuRealStream.szPass, "system");
    stuRealStream.iPort = 6002;
    stuRealStream.byChannel = 0;		// NVR等设备会有多通道，通道编号从0开始
    stuRealStream.byStream = 0;		// 码流号，0为主码流，1为从码流，2为第三码流，依次类推
    stuRealStream.byForceDecode = 0;	// byForceDecode=1表示强制解码
    stuRealStream.byConnectType = 0;	// 连接类型，设备会根据这个标记启用对应的传输协议
    stuRealStream.byMultiStream = 0;	// 此值有效忽略byStream，同时取得多码流数据，用于连接鱼眼全景设备
    if( TMCC_ERR_SUCCESS  !=  TMCC_ConnectStream( hRealStream, &stuRealStream, m_hwndDisplay) )
        {
            qDebug()<<"视频连接失败";
        }
    TMCC_RegisterStreamCallBack(hRealStream, Register_, NULL);//注册实时数据流回调
    TMCC_RegisterAVFrameCallBack(hRealStream, Callback_, NULL);//注册解码输出回调


//    }
//    QString		str;
//    tmTimeCfg_t	timeCfg, *pTimeCfg = &timeCfg;
//    SYSTEMTIME	st, *system = &st;
//    QTime		tm;
//    struct tm		lt, *pt;
//    __time64_t		t;

//    GetSystemTime(system);

//    memset(&lt, 0, sizeof(struct tm));
//    lt.tm_year 		= system->wYear-1900;
//    lt.tm_mon  	= system->wMonth-1;
//    lt.tm_mday 	= system->wDay;
//    lt.tm_wday 	= system->wDayOfWeek;
//    lt.tm_hour 		= system->wHour;
//    lt.tm_min  	= system->wMinute;
//    lt.tm_sec  	= system->wSecond;
//    t 			= mktime(&lt);
//    t 			+= 0;
//    t 			+= 0;
//    pt	 		= localtime(&t);

//    pTimeCfg->dwSize		= sizeof(tmTimeCfg_t);
//    pTimeCfg->wYear		= pt->tm_year + 1900;
//    pTimeCfg->wMonth		= pt->tm_mon + 1;
//    pTimeCfg->wDay		= pt->tm_mday;
//    pTimeCfg->wDayOfWeek	= pt->tm_wday;
//    pTimeCfg->wHour		= pt->tm_hour;
//    pTimeCfg->wMinute		= pt->tm_min;
//    pTimeCfg->wSecond		= pt->tm_sec;
//    pTimeCfg->wTimeZone	= 0;//时区
//    pTimeCfg->iDayLightTime 	= 0;	//夏令时时间偏差，秒

//    tmCommandInfo_t tmCmd 	= {0};
//    memset(&tmCmd, 0, sizeof(tmCommandInfo_t));
//    tmCmd.dwSize			=  sizeof(tmCommandInfo_t);
//    tmCmd.iChannel			=  0;
//    tmCmd.dwMajorCommand	=  TMCC_MAJOR_CMD_TIMECFG;
//    tmCmd.dwMinorCommand	=  0;
//    tmCmd.pCommandBuffer	=  pTimeCfg;
//    tmCmd.iCommandBufferLen =  sizeof(tmTimeCfg_t);
//    tmCmd.iCommandDataLen	 =  sizeof(tmTimeCfg_t);
//    int iRet = TMCC_SetConfig(hCtl6, &tmCmd);
//    qDebug()<<QString("%1错误").arg(iRet,4,16,QLatin1Char('0'));
//    if (TMCC_ERR_SUCCESS != iRet)
//    {qDebug()<<"时间同步失败";}

}
int MainWindow::Register_( HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context )
{
    return 0;
}
int MainWindow::Callback_(HANDLE hTmCC, tmAvImageInfo_t *pImage, void *context)
{

//    qDebug()<<pImage->data.buffer;
    mut.lock();
    memcpy(buf, pImage->data.buffer, 6220800);
    mut.unlock();
    return 0;
}
/**
 * @brief MainWindow::receiverdata_接收光电发来的数据包
 */
void MainWindow::receiverdata_()
{
    while (udpSocket->hasPendingDatagrams())
    {

        QByteArray DATA_;
        DATA_.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(DATA_.data(),DATA_.size());

        HEAD head;
        QDataStream in(&DATA_,QIODevice::ReadOnly);
        in.setByteOrder(QDataStream::LittleEndian);
        in>>head.startbit>>head.pronumber>>head.packetlen>>head.cmd>>head.timestamp___;

        if(head.cmd==0x01)//光电设备状态信息包
        {

            STATE state;
            in>>state.number>>state.timestamp>>state.state>>state.mode>>state.code>>state.reserved;
            if(state.state==0x00)
                ui->label_14->setText("异常");
            else if(state.state==0x01)
            {
                ui->label_14->setText("正常");
            }

            if(state.mode==0x00)
                ui->label_15->setText("空闲中");
            else if(state.mode==0x01)
                ui->label_15->setText("搜索中");
            else if(state.mode==0x02)
            {
                ui->label_15->setText("正在跟踪");
            }
        }
        else if(head.cmd==0x02)//光电设备方位、俯仰数据数据包
        {

            PITCH pitch;
//            qDebug()<<"光电设备状态";
            in>>pitch.number>>pitch.timestamp>>pitch.hor_angle>>pitch.ver_angle>>pitch.distance>>pitch.hor_speed>>
                    pitch.ver_speed>>pitch.height>>pitch.lens_zoom>>pitch.reserved;
            ui->textEdit_6->setText(QString("水平角度：%1\n俯仰角度：%2\n距离：%3\n水平角速度：%4\n俯仰角速度：%5\n目标高度：%6\n镜头倍率：%7\n ")
                                  .arg(pitch.hor_angle).arg(pitch.ver_angle).arg(pitch.distance).arg(pitch.hor_speed)
                                  .arg(pitch.ver_speed).arg(pitch.height).arg(pitch.lens_zoom));
            pitch_.hor_angle = pitch.hor_angle;
            pitch_.ver_angle = pitch.ver_angle;
            pitch_.distance = pitch.distance;
            pitch_.lens_zoom = pitch.lens_zoom;

        }
        else if(head.cmd==0x08)//光电设备状态扩展信息包
        {

            EXTEND extend;
            in>>extend.number>>extend.timestamp>>extend.state>>extend.data_len;
            if(extend.state==0x00)
            {
//                qDebug()<<"空闲";
                KX kx;
                in>>kx.time;
                QString time__ = QString("空闲时间：%1s").arg(kx.time);
                ui->label_42->setText(time__);
            }
            if(extend.state==0x01)
            {
//                qDebug()<<"搜索";

                ui->textEdit_7->setText(" ");
                ui->textEdit_8->setText(" ");
                SEARCH search;
                in>>search.timestamp>>search.target_count>>search.data_len;
                TARGET target;
                for (unsigned int i = 0;i<search.target_count;i++)
                {
                    in>>target.number>>target.type>>target.xsd>>target.kd>>target.gd>>target.fwj>>target.fyj;
                    QString t;
                    if(target.type==TARGET_TYPE_UAV_)//||target.type_==0
                        t="无人机";
                    if(target.type==TARGET_TYPE_AIRPLANE_)
                        t="飞机";
                    if(target.type==TARGET_TYPE_FIX_AIRPLANE_)
                        t="固定翼飞机";
                    if(target.type==TARGET_TYPE_PERSON_)
                        t="人";
                    if(target.type==TARGET_TYPE_CAR_)
                        t="汽车";
                    if(target.type==TARGET_TYPE_BICYCLE_)
                        t="自行车";
                    if(target.type==TARGET_TYPE_BOAT_)
                        t="轮船";
                    if(target.type==TARGET_TYPE_MOTORBOAT_)
                        t="汽艇";
                    ui->textEdit_7->append(QString("第%1个目标：\n目标编号：%2\n目标类型：%3\n目标相似度：%4\n目标宽度(像素)：%5\n目标高度(像素)：%6\n目标水平角：%7\n目标俯仰角：%8\n")
                                          .arg(i+1).arg(target.number).arg(t).arg(target.xsd)
                                          .arg(QString::number(target.kd,'f',2)).arg(QString::number(target.gd,'f',2)).arg(QString::number(target.fwj,'f',2)).arg(QString::number(target.fyj,'f',2)));

                }
            }
            if(extend.state==0x02)
            {
//                qDebug()<<"跟踪";
                ui->textEdit_7->setText(" ");
                GZ gz;
                in>>gz.time>>gz.uid>>gz.zt;
                TARGET target;
                if(gz.zt == 0x00)
                    ui->label_41->setText("丢失目标");
                if(gz.zt == 0x01)
                    ui->label_41->setText("锁定目标");
                in>>target.number>>target.type>>target.xsd>>target.kd>>target.gd>>target.fwj>>target.fyj;
                QString t;
                if(target.type==TARGET_TYPE_UAV_)
                    t="无人机";
                if(target.type==TARGET_TYPE_AIRPLANE_)
                    t="飞机";
                if(target.type==TARGET_TYPE_FIX_AIRPLANE_)
                    t="固定翼飞机";
                if(target.type==TARGET_TYPE_PERSON_)
                    t="人";
                if(target.type==TARGET_TYPE_CAR_)
                    t="汽车";
                if(target.type==TARGET_TYPE_BICYCLE_)
                    t="自行车";
                if(target.type==TARGET_TYPE_BOAT_)
                    t="轮船";
                if(target.type==TARGET_TYPE_MOTORBOAT_)
                    t="汽艇";
                ui->textEdit_8->setText(QString("目标编号：%1\n目标类型：%2\n目标相似度：%3\n目标水平角：%4\n目标俯仰角：%5\n")
                                      .arg(target.number).arg(t).arg(target.xsd)
                                      .arg(QString::number(target.fwj,'f',2)).arg(QString::number(target.fyj,'f',2)));
            }
        }
        else if(head.cmd==0x0b)//目标上报信息
        {
            if(ui->label_15->text()!="搜索中")
            {
                Target_reporting tarreporting;
                in>>tarreporting.time>>tarreporting.number>>tarreporting.size;
                Target_information_description tindescription;
                for (unsigned int i = 0;i<tarreporting.number;i++)
                {
                    in>>tindescription.number>>tindescription.type>>tindescription.xsd>>tindescription.kd>>tindescription.gd>>tindescription.wlkd
                        >>tindescription.wlgd>>tindescription.ydfx>>tindescription.blzd[0]>>tindescription.blzd[1]>>tindescription.blzd[2]>>tindescription.spsd>>tindescription.czsd>>tindescription.wlspsd
                          >>tindescription.wlczsd>>tindescription.mbfwj>>tindescription.mbfyj>>tindescription.blzd2;
                    QString t;
                    if(tindescription.ydfx==0)
                        t="静止";
                    if(tindescription.ydfx==1)
                        t="左";
                    if(tindescription.ydfx==2)
                        t="右";
                    if(tindescription.ydfx==3)
                        t="上";
                    if(tindescription.ydfx==4)
                        t="下";
                    if(tindescription.ydfx==5)
                        t="左上";
                    if(tindescription.ydfx==6)
                        t="右上";
                    if(tindescription.ydfx==7)
                        t="左下";
                    if(tindescription.ydfx==8)
                        t="右下";
                    QString tt;
                    if(tindescription.type==TARGET_TYPE_UAV_)
                        tt="无人机";
                    if(tindescription.type==TARGET_TYPE_AIRPLANE_)
                        tt="飞机";
                    if(tindescription.type==TARGET_TYPE_FIX_AIRPLANE_)
                        tt="固定翼飞机";
                    if(tindescription.type==TARGET_TYPE_PERSON_)
                       tt="人";
                    if(tindescription.type==TARGET_TYPE_CAR_)
                        tt="汽车";
                    if(tindescription.type==TARGET_TYPE_BICYCLE_)
                        tt="自行车";
                    if(tindescription.type==TARGET_TYPE_BOAT_)
                        tt="轮船";
                    if(tindescription.type==TARGET_TYPE_MOTORBOAT_)
                        tt="汽艇";
                    ui->textEdit_7->setText(QString("第%1个目标：\n目标编号：%2\n目标类型：%3\n目标相似度：%4\n目标宽度：%5像素\n目标高度：%6像素\n物理宽度：%7像素\n物理高度：%8像素\n运动方向：%9\n水平速度：%10像素/秒\n垂直速度：%11像素/秒\n物理水平速度：%12米/秒\n物理垂直速度：%13米/秒\n目标方位角：%14\n目标俯仰角：%15\n")
                                          .arg(i+1).arg(tindescription.number).arg(tt).arg(tindescription.xsd)
                                          .arg(tindescription.kd).arg(tindescription.gd).arg(tindescription.wlkd).arg(tindescription.wlgd)
                                                   .arg(t).arg(tindescription.spsd).arg(tindescription.czsd).arg(tindescription.wlspsd)
                                                   .arg(tindescription.wlczsd).arg(QString::number(tindescription.mbfwj,'f',2)).arg(QString::number(tindescription.mbfyj,'f',2)));
                target_.xsd = tindescription.xsd;target_.fwj = tindescription.mbfwj;target_.fyj = tindescription.mbfyj;
                }
            }
        }
    }
}

//            double G = m_PosInfo.BD_H - H;//设备与无人机之间的高
//            double agl, dis;
//            CalcAngleDistance(L,B,m_PosInfo.BD_L,m_PosInfo.BD_B,agl,dis);
//            agl = 360 - agl;
//            double FY = atan(G/dis);
//            FY = FY*180/PI;
//            FY = abs(FY-90);

//            qDebug()<<"无人机相对于光电设备的水平、俯仰、距离:"<<agl<<FY<<dis;
//            QString j = ui->lineEdit_15->text();
//            agl = agl + j.toDouble();//加误差值
//            j = ui->lineEdit_12->text();
//            FY = FY + j.toDouble();
//            j = ui->lineEdit_14->text();
//            dis = dis + j.toDouble();

//            ui->lineEdit_9->setText(QString("%1").arg(QString::number(agl,'f',2)));
//            ui->lineEdit_7->setText(QString("%1").arg(QString::number(FY,'f',2)));
//            ui->lineEdit_8->setText(QString("%1").arg(QString::number(dis,'f',2)));

//            if(ui->radioButton->isChecked()==true)
//            {
//                CProtocal_(dis,FY,agl);
//                unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x38,0x3C,0xFE,0x0F,0x01,0x0A,0x4F,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x00,0x00,0x00,0x00,0x64,0xF6,0x4F,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
//                udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
//                ui->textEdit_5->append("<font color=white>正在自动扫描、跟踪无人机。</font>");
//            }



//    while (udpSockett->hasPendingDatagrams())
//    {
//        QByteArray datagram;
//        datagram.resize(udpSockett->pendingDatagramSize());
//        udpSockett->readDatagram(datagram.data(), datagram.size());

//        TPosInfo m_PosInfo;
//        memcpy(&m_PosInfo, datagram.data(), datagram.size());
//        if(m_PosInfo.Head == 0xdd)
//        {
//            qDebug()<<QString("%1").arg(QString::number(m_PosInfo.BD_L,'f',6))
//                    <<QString("%1").arg(QString::number(m_PosInfo.BD_B,'f',6))
//                    <<QString("%1").arg(QString::number(m_PosInfo.BD_H,'f',2));

//            QString i = ui->lineEdit_6->text();
//            double L = i.toDouble();
//            i = ui->lineEdit_10->text();
//            double B = i.toDouble();
//            i = ui->lineEdit_11->text();
//            double H = i.toDouble();
//            qDebug()<<"设备经纬高:"<<L<<B<<H;//设备经纬高

//            double G = m_PosInfo.BD_H - H;//设备与无人机之间的高
//            double agl, dis;
//            CalcAngleDistance(L,B,m_PosInfo.BD_L,m_PosInfo.BD_B,agl,dis);
//            agl = 360 - agl;
//            double FY = atan(G/dis);
//            FY = FY*180/PI;
//            FY = abs(FY-90);

//            qDebug()<<"无人机相对于光电设备的水平、俯仰、距离:"<<agl<<FY<<dis;
//            QString j = ui->lineEdit_15->text();
//            agl = agl + j.toDouble();//加误差值
//            j = ui->lineEdit_12->text();
//            FY = FY + j.toDouble();
//            j = ui->lineEdit_14->text();
//            dis = dis + j.toDouble();

//            ui->lineEdit_9->setText(QString("%1").arg(QString::number(agl,'f',2)));
//            ui->lineEdit_7->setText(QString("%1").arg(QString::number(FY,'f',2)));
//            ui->lineEdit_8->setText(QString("%1").arg(QString::number(dis,'f',2)));

//            if(ui->radioButton->isChecked()==true)
//            {
//                CProtocal_(dis,FY,agl);
//                unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x38,0x3C,0xFE,0x0F,0x01,0x0A,0x4F,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x00,0x00,0x00,0x00,0x64,0xF6,0x4F,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
//                udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
//                ui->textEdit_5->append("<font color=white>正在自动扫描、跟踪无人机。</font>");
//            }

//        }
//    }

//    while (udpSockett->hasPendingDatagrams())
//    {

//        QByteArray DATA__;
//        DATA__.resize(udpSockett->pendingDatagramSize());
//        udpSockett->readDatagram(DATA__.data(),DATA__.size());
//        qDebug()<<DATA__;

//        TPosInfo head;
//        QDataStream in(&DATA__,QIODevice::ReadOnly);
////        in.setByteOrder(QDataStream::LittleEndian);
//        in>>head.Head;
//        if(head.Head == 0xdd)
//        {
//            in>>head.UTC_Year>>head.UTC_Month>>head.UTC_Day>>head.UTC_Hour>>head.UTC_Min>>head.UTC_Sec>>head.GPS_L>>head.GPS_B
//            >>head.GPS_H>>head.GPS_Speed>>head.GPS_Ceta>>head.BDT_Year>>head.BDT_Month>>head.BDT_Day>>head.BDT_Hour>>head.BDT_Min
//            >>head.BDT_Sec>>head.BD_L>>head.BD_B>>head.BD_H>>head.BD_Speed>>head.BD_Ceta;
//            qDebug()<<head.BD_L<<head.BD_B<<head.BD_H;//目标经纬高
//            QString i = ui->lineEdit_6->text();
//            double L = i.toDouble();
//            i = ui->lineEdit_10->text();
//            double B = i.toDouble();
//            i = ui->lineEdit_11->text();
//            double H = i.toDouble();
//            qDebug()<<"设备经纬高:"<<L<<B<<H;//设备经纬高
//            double G = head.BD_H - H;//设备与无人机之间的高
//            CalcAngleDistance(L,B,head.BD_L,head.BD_B,L,L,G);

//        }
//    }

/**
 * @brief MainWindow::receiverdata__接收定位模块数据包
 */
void MainWindow::receiverdata__()
{
    while (udpSockett->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSockett->pendingDatagramSize());
        udpSockett->readDatagram(datagram.data(), datagram.size());
        TPosInfo m_PosInfo;
        memcpy(&m_PosInfo, datagram.data(), datagram.size());

        if(m_PosInfo.Head == 0xdd&&red==0)
        {
            red =1;
            P2[0] = m_PosInfo.BD_L;
            P2[1] = m_PosInfo.BD_B;
            P2[2] = m_PosInfo.BD_H;
            instruct();
//            if(readdata == 1)//读取第一次经纬高
//            {
//                P[0] = m_PosInfo.BD_L;
//                P[1] = m_PosInfo.BD_B;
//                P[2] = m_PosInfo.BD_H;
//                readdata = 0;
//                red = red+1;

//                qDebug()<<"第一次经纬高：";
//                qDebug()<<QString("%1").arg(QString::number(P[0],'f',6))
//                        <<QString("%1").arg(QString::number(P[1],'f',6))
//                        <<QString("%1").arg(QString::number(P[2],'f',2));
//            }
//            else if(readdata == 0)//读取第二次经纬高
//            {
//                P1[0] = m_PosInfo.BD_L;
//                P1[1] = m_PosInfo.BD_B;
//                P1[2] = m_PosInfo.BD_H;

//                qDebug()<<"第二次经纬高：";
//                qDebug()<<QString("%1").arg(QString::number(P1[0],'f',6))
//                        <<QString("%1").arg(QString::number(P1[1],'f',6))
//                        <<QString("%1").arg(QString::number(P1[2],'f',2));

//                readdata = 1;
//                time = time+1;
//                CalcAngleDistance(P[0],P[1],P1[0],P1[1],derc,jl);//计算两点经纬高之间的距离和方向
//                spend = jl/time;
//                if(spend>max_spend__)
//                {
//                    readdata = 0;
//                }
//                else if(spend>min_spend__)
//                {
//                    spend = spend*time__;
//                    P2[0] = P1[0] + spend*sin(derc*RAD)/(111000.0*cos(P1[1]*RAD));
//                    P2[1] = P1[1] + spend*cos(derc*RAD)/111000.0;
//                    P2[2] = P1[2];
//                    time = 0;
//                    instruct();red = red+1;
//                }
//                else
//                {
//                    P2[0] = P1[0];
//                    P2[1] = P1[1];
//                    P2[2] = P1[2];
//                    time = 0;
//                    instruct();red = red+1;
//                }
//            }
        }
    }
}
/**
 * @brief MainWindow::receiverdata_radar接收雷达发送过来的目标无人机信息数据包
 */
void MainWindow::receiverdata_radar()
{

    while (udpsocket_radar->hasPendingDatagrams())
    {

            QByteArray datagram;
            datagram.resize(udpsocket_radar->pendingDatagramSize());
            udpsocket_radar->readDatagram(datagram.data(), datagram.size());

            if(datagram.size() == 64)
            {
                UnmannedAerialVehicle uav_Data;
                memcpy(&uav_Data, datagram.data(), datagram.size());
                qDebug()<<"雷达编号："<<uav_Data.uav_radarNo;
                qDebug()<<"目标编号："<<uav_Data.uav_targetNo;
                qDebug()<<"目标距离单位米："<<uav_Data.uav_targetDist;
                qDebug()<<"目标方位角 单位度："<<uav_Data.uav_azimuth;
                qDebug()<<"目标俯仰角 单位度："<<uav_Data.uav_elevation;
                qDebug()<<"目标强弱："<<uav_Data.uav_intensity;
                qDebug()<<"目标径向速度 米/秒："<<uav_Data.uav_speed;
                qDebug()<<"目标经度 单位度："<<uav_Data.uav_longitude;
                qDebug()<<"目标纬度 单位度："<<uav_Data.uav_latitude;
                qDebug()<<"目标海拔 单位米："<<uav_Data.uav_height;
                qDebug()<<"目标航向 单位度："<<uav_Data.uav_course;
                qDebug()<<"目标航速 单位米/秒："<<uav_Data.uav_navigatespeed;
                qDebug()<<"备用1："<<uav_Data.uav_preserve1;
                qDebug()<<"备用2："<<uav_Data.uav_preserve2;
                qDebug()<<"时间戳："<<uav_Data.uav_time;
                if(ui->radioButton->isChecked()==true && FLAG_1)
                {
                    FLAG_1 = 0;
//                    if(model_ == "引导不跟踪" || model_ == "指定范围内跟踪")
//                        {
                        P2[0] = uav_Data.uav_longitude;
                        P2[1] = uav_Data.uav_latitude;
                        P2[2] = uav_Data.uav_height;
                        instruct_(P2[0],P2[1],P2[2]);
//                    }
//                    else
//                        {
//                        spend = uav_Data.uav_speed*time__;
//                        P2[0] = uav_Data.uav_longitude + spend*sin(uav_Data.uav_course*RAD)/(111000.0*cos(uav_Data.uav_latitude*RAD));
//                        P2[1] = uav_Data.uav_latitude + spend*cos(uav_Data.uav_course*RAD)/111000.0;
//                        P2[2] = uav_Data.uav_height;
//                        instruct_(P2[0],P2[1],P2[2]);
//                    }
                }
            }
    }
}
void MainWindow::instruct_(double p1,double p2,double p3)
{
    qDebug()<<"推算的经纬高：";
    qDebug()<<QString("%1").arg(QString::number(p1,'f',6))
            <<QString("%1").arg(QString::number(p2,'f',6))
            <<QString("%1").arg(QString::number(p3,'f',2));

    QString i = ui->lineEdit_6->text();//读取设备经纬高
    double L = i.toDouble();
    i = ui->lineEdit_10->text();
    double B = i.toDouble();
    i = ui->lineEdit_11->text();
    double H = i.toDouble();
    qDebug()<<"设备经纬高:"<<L<<B<<H;

    double G = p3 - H;//设备与无人机之间的高
    double agl, dis;
    CalcAngleDistance(L,B,p1,p2,agl,dis);
    agl = 360 - agl;
    double FY = atan(G/dis);
    FY = FY*180/PI;
    FY = abs(FY-90);
    qDebug()<<"无人机相对于光电设备的水平、俯仰、距离:"<<agl<<FY<<dis;

    agl = (agl + level__)>=0 ? (agl + level__)/360.0>=1 ? (((agl + level__)/360.0)-1)*360.0 : (agl + level__) : 360.0-abs(agl + level__);//加误差值
    FY = FY + pitch__;
    dis = dis + dis__>=0 ? dis+dis__ : 0;
    ui->lineEdit_9->setText(QString("%1").arg(QString::number(agl,'f',2)));
    ui->lineEdit_7->setText(QString("%1").arg(QString::number(FY,'f',2)));
    ui->lineEdit_8->setText(QString("%1").arg(QString::number(dis,'f',2)));

    if(ui->radioButton->isChecked()==true && ui->label_15->text() != "正在跟踪")
    {
        if(model_ == "引导不跟踪")
        {
            tail_after_over();
            tail_after_over();
            Sleep(100);
            int jiaoju = c.cfg(K_,dis);
            CProtocal__(jiaoju);
            Sleep(100);
            CProtocal_(0,FY,agl);//引导
            Sleep(100);
            FLAG_1 = 1;
        }
        else if(model_ == "指定范围内跟踪")
        {
                tail_after_over();
                tail_after_over();
                Sleep(100);
                int jiaoju = c.cfg(K_,dis);
                CProtocal__(jiaoju);
                Sleep(100);
                CProtocal_(0,FY,agl);//引导
                Sleep(100);
                if(s_min_<=dis && s_max_>=dis)
                {
//                    tail_after_over();
//                    tail_after_over();
//                    Sleep(100);
//                    int jiaoju = c.cfg(K_,dis);
//                    CProtocal__(jiaoju);
//                    Sleep(100);
//                    CProtocal_(0,FY,agl);//引导
//                    Sleep(1000);
//                    tail_after();//跟踪
//                    Sleep(2000);

                    tail_after_over();
                    tail_after_over();
                    Sleep(100);
                    int jiaoju = c.cfg(K_,dis);
                    CProtocal__(jiaoju);
                    Sleep(100);
                    CProtocal_(0,FY,agl);//引导
                    target_.fwj=-1;
                    target_.fyj=-1;
                    Sleep(600);
                    h_ = (2*atan(4.59/jiaoju*2))*180/PI;//当前视场水平角
                    v_ = (2*atan(3.42/jiaoju*2))*180/PI;//当前视场俯仰角

                    if(target_.fwj != -1 && target_.fyj != -1)
                    {
                        if(abs(target_.fwj - pitch_.hor_angle) > h_)
                            h_cha = 360-abs(target_.fwj - pitch_.hor_angle);
                        else
                            h_cha = abs(target_.fwj - pitch_.hor_angle);
                        v_cha = abs(target_.fyj - pitch_.ver_angle);

                        if(h_cha <= (h_/4.0)&&v_cha <= (v_/4.0))
                        {
                            tail_after();//跟踪
                            Sleep(2000);
                        }
                        else if(h_cha <= (h_/3.0) && v_cha <= (v_/3.0))
                        {
                            tail_after();//跟踪
                            Sleep(1500);
                        }
                        else if(h_cha <= (h_/2.0) && v_cha <= (v_/2.0))
                        {
                            tail_after();//跟踪
                            Sleep(1000);
                        }
                    }
                }
                FLAG_1 = 1;
        }
        else if(model_ == "引导并跟踪")
        {
//            tail_after_over();
//            tail_after_over();
//            Sleep(100);
//            int jiaoju = c.cfg(K_,dis);
//            CProtocal__(jiaoju);
//            Sleep(100);
//            CProtocal_(0,FY,agl);//引导
//            Sleep(1000);
//            tail_after();//跟踪
//            Sleep(2000);
//            FLAG_1 = 1;
                tail_after_over();
                tail_after_over();
                Sleep(100);
                int jiaoju = c.cfg(K_,dis);
                CProtocal__(jiaoju);
                Sleep(100);
                CProtocal_(0,FY,agl);//引导
                target_.fwj=-1;
                target_.fyj=-1;
                Sleep(600);

                h_ = (2*atan(4.59/jiaoju*2))*180/PI;//当前视场水平角
                v_ = (2*atan(3.42/jiaoju*2))*180/PI;//当前视场俯仰角

                if(target_.fwj != -1 && target_.fyj != -1)
                {
                    if(abs(target_.fwj - pitch_.hor_angle) > h_)
                        h_cha = 360-abs(target_.fwj - pitch_.hor_angle);
                    else
                        h_cha = abs(target_.fwj - pitch_.hor_angle);
                    v_cha = abs(target_.fyj - pitch_.ver_angle);

                    if(h_cha <= (h_/4.0)&&v_cha <= (v_/4.0))
                    {
                        tail_after();//跟踪
                        Sleep(2000);
                    }
                    else if(h_cha <= (h_/3.0) && v_cha <= (v_/3.0))
                    {
                        tail_after();//跟踪
                        Sleep(1500);
                    }
                    else if(h_cha <= (h_/2.0) && v_cha <= (v_/2.0))
                    {
                        tail_after();//跟踪
                        Sleep(1000);
                    }
                }
                FLAG_1 = 1;
        }

    }



//        if(FLAG_2)
//        {
//            int jiaoju = c.cfg(dis);
//            CProtocal__(jiaoju);
//            Sleep(100);
//            CProtocal_(0,FY,agl);//引导
//            Sleep(1000);
//            FLAG_2 = FLAG_2+1;
//            if(FLAG_2 == 2)
//                FLAG_2 = 0;
//            FLAG_1 = 1;
//        }
//        else
//        {
//            int jiaoju = c.cfg(dis);
//            tail_after_over();
//            tail_after_over();
//            Sleep(100);
//            CProtocal__(jiaoju);
//            Sleep(100);
//            CProtocal_(0,FY,agl);//引导
//            Sleep(200);
////            tail_after();//跟踪
////            Sleep(100);
//            FLAG_1 = 1;
//        }
//        tail_after_over();
//        Sleep(200);
//        CProtocal_(dis,FY,agl); // 引导
//        Sleep(500);
//        tail_after();//跟踪
//        Sleep(300);
//        while((pitch_.hor_angle <= agl-1 || pitch_.hor_angle >= agl+1||pitch_.ver_angle <= FY-1 || pitch_.ver_angle >= FY+1)&& ui->label_15->text() != "正在跟踪")
//        {
//            Sleep(100);
//        }
//        Sleep(1000);

    else
    {
        FLAG_1 = 1;
    }
}
/**
 * @brief MainWindow::instruct结合定位模块发送引导跟踪指令
 */
void MainWindow::instruct()
{
    qDebug()<<"推算的经纬高：";
    qDebug()<<QString("%1").arg(QString::number(P2[0],'f',6))
            <<QString("%1").arg(QString::number(P2[1],'f',6))
            <<QString("%1").arg(QString::number(P2[2],'f',2));

    QString i = ui->lineEdit_6->text();//读取设备经纬高
    double L = i.toDouble();
    i = ui->lineEdit_10->text();
    double B = i.toDouble();
    i = ui->lineEdit_11->text();
    double H = i.toDouble();
    qDebug()<<"设备经纬高:"<<L<<B<<H;

    double G = P2[2] - H;//设备与无人机之间的高
    double agl, dis;
    CalcAngleDistance(L,B,P2[0],P2[1],agl,dis);
    agl = 360 - agl;
    double FY = atan(G/dis);
    FY = FY*180/PI;
    FY = abs(FY-90);
    qDebug()<<"无人机相对于光电设备的水平、俯仰、距离:"<<agl<<FY<<dis;

    agl = (agl + level__)>=0 ? (agl + level__)/360.0>=1 ? (((agl + level__)/360.0)-1)*360.0 : (agl + level__) : 360.0-abs(agl + level__);//加误差值
    FY = FY + pitch__;
    dis = dis + dis__>=0 ? dis+dis__ : 0;
    ui->lineEdit_9->setText(QString("%1").arg(QString::number(agl,'f',2)));
    ui->lineEdit_7->setText(QString("%1").arg(QString::number(FY,'f',2)));
    ui->lineEdit_8->setText(QString("%1").arg(QString::number(dis,'f',2)));

    if(ui->radioButton->isChecked()==true && ui->label_15->text() != "正在跟踪")
    {
        int jiaoju = c.cfg(K_,dis);
        tail_after_over();
        tail_after_over();
        Sleep(100);
        CProtocal__(jiaoju);
        Sleep(100);
        CProtocal_(0,FY,agl);//引导
        Sleep(200);
//        tail_after();//跟踪
//        Sleep(100);
        red = 0;
    }
    else
    {
        red = 0;
    }
}


//求两经纬高之间的距离及运动方向
//(L1,B1)为初始点的经纬度，(L2,B2)为目标点的经纬度
//Angel为(L1,B1)指向(L2,B2)的方位，Distance为(L1,B1)与(L2,B2)之间的距离
void MainWindow::CalcAngleDistance(const double& L1, const double& B1, const double& L2, const double& B2, double& Angel, double& Distance)
{
    double param[2];
    Calculate_A1_S(B1*RAD, L1*RAD, B2*RAD, L2*RAD, 0.00001, param);
    Angel = param[0]*180.0/PI;
    Distance = param[1];
}

//计算
bool MainWindow::Calculate_A1_S(double B1, double L1, double B2, double L2, double rx, double re[2])
{
    double A1=0.0, S=0.0;//方位角，距离
    double e12, dt, dt0, W1, W2, sinu1, sinu2, cosu1, cosu2, jc, a1, a2, b1, b2, ld;
    double p, q, sind, cosd, d, sinA0, cos2A0, x, af, bd, A3, B3, C3, y;
    cos2A0 = 0;
    x = 0;
    d = 0;
    e12 = 0.006693421622926;//第一偏心率的平方
    dt = 0; dt0 = 1;
    W1 = sqrt(1 - e12 * sin(B1) * sin(B1));/*辅助计算*/
    W2 = sqrt(1 - e12 * sin(B2) * sin(B2));

    sinu1 = sin(B1) * sqrt(1 - e12) / W1;
    sinu2 = sin(B2) * sqrt(1 - e12) / W2;

    cosu1 = cos(B1) / W1;
    cosu2 = cos(B2) / W2;

    jc = L2 - L1;//经度差
    a1 = sinu1 * sinu2;
    a2 = cosu1 * cosu2;
    b1 = cosu1 * sinu2;
    b2 = (sinu1) * (cosu2);
    /* 用逐次趋近法同时计算起点大地方位角、球面长度及经差*/
    while (fabs(dt - dt0) > rx)
    {
        dt0 = dt;
        ld = jc + dt;
        p = cosu2 * sin(ld);
        q = b1 - b2 * cos(ld);
        if(q==0){return false;}
        A1 = atan(p / q);
        if (p > 0)
        {
            if (q > 0)
                A1 = fabs(A1);
            else
                A1 = PI - fabs(A1);
        }
        else
        {
            if (q > 0)
                A1 = 2.0 * PI - fabs(A1);
            else
                A1 = PI + fabs(A1);
        }
        sind = p * sin(A1) + q * cos(A1);
        cosd = a1 + a2 * cos(ld);
        if(cosd==0){return false;}
        d = atan(sind / cosd);
        if (cosd > 0)
            d = fabs(d);
        else
            d = PI - fabs(d);

        sinA0 = cosu1 * sin(A1);
        cos2A0 = 1 - sinA0 * sinA0;
        x = 2 * a1 - cos2A0 * cos(d);
        af = (33523299 - (28189 - 70 * cos2A0) * cos2A0) * 0.0000000001;
        bd = (28189 - 94 * cos2A0) * 0.0000000001;
        dt = (af * d - bd * x * sin(d)) * sinA0;
    }
    A3 = 6356863.020 + (10708.949 - 13.474 * cos2A0) * cos2A0;
    B3 = 10708.938 - 17.956 * cos2A0;
    C3 = 4.487;
    y = (cos2A0 * cos2A0 * cos2A0 * cos2A0 - 2 * x * x) * cos(d);
    S = A3 * d + (B3 * x + C3 * y) * sin(d);

    re[0] = A1;
    re[1] = S;
    return true;
}

/**
 * @brief MainWindow::style 修改界面按钮样式函数
 */
void MainWindow::style()     //样式
{
    setWindowIcon(QIcon(":/image/100.png"));
    setWindowTitle(tr("小型目标识别跟踪光电伺服云台控制系统"));
    this->setFixedSize( this->width (),this->height ());
    ui->pushButton_13->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_14->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_15->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_16->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_17->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_18->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_19->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_20->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_21->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_22->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_23->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_24->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_28->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_29->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_30->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_31->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_release_2->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_track_6->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_track_7->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_track_8->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_track_9->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_track_10->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_track_11->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_track_12->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_uav_3->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton_uav_4->setStyleSheet("QPushButton{border-image:url(:/image/1010.png);border:8px;color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/11.png);border:8px}"
                                     "QPushButton:pressed{border-image:url(:/image/11.png);border:8px;color:white;}");
    ui->pushButton->setStyleSheet("QPushButton{border-image:url(:/image/yushua1.png);color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/yushua2.png);}"
                                     "QPushButton:pressed{border-image:url(:/image/yushua1.png);}");
    ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(:/image/jietu1.png);color:red;}"
                                     "QPushButton:hover{border-image:url(:/image/jietu2.png);}"
                                     "QPushButton:pressed{border-image:url(:/image/jietu1.png);color:white;}");
    ui->pushButton_3->setStyleSheet("QPushButton{border-image:url(:/image/ff.png);}"
                                     "QPushButton:hover{border-image:url(:/image/fff.png);}");
    ui->pushButton_4->setStyleSheet("QPushButton{border-image:url(:/image/dd.png);}"
                                     "QPushButton:hover{border-image:url(:/image/ddd.png);}");
    ui->pushButton_5->setStyleSheet("QPushButton{border-image:url(:/image/jj.png);}"
                                     "QPushButton:hover{border-image:url(:/image/jjj.png);}");
    ui->pushButton_6->setStyleSheet("QPushButton{color:white;background-color:rgba(255,255,255,0);}"
                                     "QPushButton:hover{color:red;}"
                                     "QPushButton:pressed{color:white;}");
    ui->pushButton_7->setStyleSheet("QPushButton{color:white;background-color:rgba(255,255,255,0);}"
                                     "QPushButton:hover{color:red;}"
                                     "QPushButton:pressed{color:white;}");
    ui->pushButton_8->setStyleSheet("QPushButton{color:white;background-color:rgba(255,255,255,0);}");
    ui->pushButton_9->setStyleSheet("QPushButton{border-image:url(:/image/lx.png);}"
                                     "QPushButton:hover{border-image:url(:/image/lx2.png);}");
    ui->pushButton->setToolTip("雨刷器");
    ui->pushButton_2->setToolTip("截图");
    ui->pushButton_3->setToolTip("风扇");
    ui->pushButton_4->setToolTip("灯光");
    ui->pushButton_5->setToolTip("自动聚焦");
    ui->pushButton_9->setToolTip("开始录制");
    ui->pushButton_31->setToolTip("设置截屏、录屏保存路径");

//    ui->pushButton_track_11->setEnabled(false);

}

/**
 * @brief MainWindow::Sleep 系统休眠函数
 * @param time 休眠时间参数
 */
void MainWindow::Sleep(int time)     //系统休眠函数
{
    QTime Time = QTime::currentTime().addMSecs(time);
    while (QTime::currentTime() < Time)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pushButton_uav_4_clicked 初始化
 */
void MainWindow::on_pushButton_uav_4_clicked()
{

        ui->textEdit_5->setText("");
        ui->textEdit_6->setText("");
        ui->textEdit_7->setText("");
        ui->textEdit_8->setText("");
        ui->label_41->setText("");
        //释放跟踪、回正（水平0，垂直90）、回焦指令
        FLAG=3;
        unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x38,0x3C,0xFE,0x0F,0x01,0x0A,0x4F,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x00,0x00,0x00,0x00,0x64,0xF6,0x4F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
        int b = udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
        if(b!=-1)
        {
            ui->textEdit_5->append("<font color=white>正在初始化，请稍等。</font>");
            Sleep(1000);
            unsigned char num1[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x58,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x56,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x71,0x01,0x00,0x00,0x89,0x80,0x8A,0x8B};
            udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num1),sizeof(num1)),QHostAddress(ip),port);
            Sleep(4000);
            unsigned char num2[] = {0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x89,0x80,0x8A,0x8B};
            udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num2),sizeof(num2)),QHostAddress(ip),port);
            Sleep(1000);
            ui->textEdit_5->append("<font color=white>初始化成功。</font>");
        }
}

/**
 * @brief MainWindow::tail_after 跟踪指令
 */
void MainWindow::tail_after()
{
    unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x38,0x3C,0xFE,0x0F,0x01,0x0A,0x4F,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x00,0x00,0x00,0x00,0x64,0xF6,0x4F,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
    int b = udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
    if(b!=-1)
        ui->textEdit_5->append("<font color=white>正在自动扫描、跟踪无人机。</font>");
}
/**
 * @brief MainWindow::tail_after_over 释放跟踪
 */
void MainWindow::tail_after_over()
{
    ui->label_41->setText("");
    ui->textEdit_8->setText("");
    unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x38,0x3C,0xFE,0x0F,0x01,0x0A,0x4F,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x00,0x00,0x00,0x00,0x64,0xF6,0x4F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
    int b = udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
    if(b!=-1)
        ui->textEdit_5->append("<font color=white>成功释放跟踪。</font>");
}

/**
 * @brief MainWindow::on_pushButton_uav_3_clicked 在当前视角跟踪无人机
 */
void MainWindow::on_pushButton_uav_3_clicked()
{
    FLAG=3;
    unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x38,0x3C,0xFE,0x0F,0x01,0x0A,0x4F,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x00,0x00,0x00,0x00,0x64,0xF6,0x4F,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
    int b = udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
    if(b!=-1)
        ui->textEdit_5->append("<font color=white>正在自动扫描、跟踪无人机。</font>");
}

/**
 * @brief MainWindow::on_pushButton_release_2_clicked 释放跟踪
 */
void MainWindow::on_pushButton_release_2_clicked()
{
    FLAG = 3;
    ui->label_41->setText("");
    ui->textEdit_8->setText("");
    tail_after_over();
}

/**
 * @brief MainWindow::on_pushButton_track_9_clicked 仅搜索
 */
void MainWindow::on_pushButton_track_9_clicked()
{
    FLAG=5;
    while (1) {
        if(FLAG!=5)
            break;
        else
        {
            tail_after_over();
            Sleep(200);
            unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0x18,0x67,0x38,0x3C,0x18,0x67,0x01,0x0A,0xD5,0x00,0x04,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x90,0x3C,0x18,0x67,0x00,0x00,0x00,0x00,0x9C,0xFA,0xD5,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
            int b = udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
            if(b!=-1)
                ui->textEdit_5->append("<font color=white>正在搜索。</font>");
            Sleep(4000);
        }
    }
}

/**
 * @brief MainWindow::on_pushButton_track_8_clicked 搜索并自动跟踪
 */
void MainWindow::on_pushButton_track_8_clicked()
{
    FLAG=4;
    while (1) {
        if(FLAG!=4)
            break;
        else
        {
            if(ui->label_15->text() == "正在跟踪")
                break;
            else
            {
                unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0x18,0x67,0x38,0x3C,0x18,0x67,0x01,0x0A,0xD5,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x90,0x3C,0x18,0x67,0x00,0x00,0x00,0x00,0x9C,0xFA,0xD5,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
                int b = udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
                if(b!=-1)
                    ui->textEdit_5->append("<font color=white>正在自动扫描、跟踪无人机。</font>");
                Sleep(4000);
            }
        }
    }
}

/**
 * @brief MainWindow::on_pushButton_track_10_clicked 在当前视角搜索
 */
void MainWindow::on_pushButton_track_10_clicked()
{

    FLAG=6;
    tail_after_over();
    Sleep(200);
    unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0x0D,0x63,0x38,0x3C,0x0D,0x63,0x01,0x0A,0x1B,0x00,0x04,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x90,0x3C,0x0D,0x63,0x00,0x00,0x00,0x00,0x5C,0xFA,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x05,0x00,0x00,0x89,0x80,0x8A,0x8B};
    int b = udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
    if(b!=-1)
        ui->textEdit_5->append("<font color=white>正在搜索。</font>");


//    tail_after();
//    int i =6;
//    while(1)
//    {
//        if(ui->label_15->text() != "正在跟踪"&&i--)
//        {
//            int jiaoju = c.cfg(i);
//            tail_after_over();
//            tail_after_over();//释放跟踪
//            Sleep(100);
//            CProtocal__(20);//跳转到焦距jiaoju
//            Sleep(100);
//            CProtocal_(0,90,i*10);//引导
//            Sleep(300);

//            Sleep(500);
//        }
//        else
//            break;
//    }




//    if(ui->radioButton->isChecked()==true && ui->label_15->text() != "正在跟踪")
//    {
//        int j =1;
//        double DS = 0;
//        for(int i = s_min_;i<s_max_ && ui->label_15->text() != "正在跟踪";i = i+200)
//        {
//            if((pitch_.hor_angle <= DS-0.1 || pitch_.hor_angle >= DS+0.1) && ui->label_15->text() != "正在跟踪")
//            {
//                tail_after_over();// 释放跟踪
//                Sleep(100);
//                CProtocal_(i,FY_,DS);//引导，引导前不能是跟踪状态
//                Sleep(1000);
//                tail_after();//跟踪
//            }
//            Sleep(500);
//            if(pitch_.ver_angle <= FY1_ && ui->label_15->text() != "正在跟踪")
//            {

//                while (pitch_.ver_angle <= FY1_ && ui->label_15->text() != "正在跟踪") {
//                    single_press_(22,20);//控制：下
//                    if(ui->label_15->text() != "正在跟踪"&&j)
//                    {
//                        j = 0;
//                        tail_after_over();// 释放跟踪
//                        Sleep(500);
//                        CProtocal_(i,pitch_.ver_angle,60);//引导，引导前不能是跟踪状态
//                        Sleep(1000);
//                        tail_after();//跟踪
//                        Sleep(1000);
//                        single_press_(22,20);//控制：下
//                    }
//                    Sleep(200);
//                    single_cancel_(22,20);//取消控制：下

//                }
//                single_cancel_(22,20);//取消控制：下
////                Sleep(500);
//            }
//            else if(pitch_.ver_angle >= FY_ && ui->label_15->text() != "正在跟踪")
//            {
//                single_press_(21,20);//控制：上
//                while (pitch_.ver_angle >= FY_ && ui->label_15->text() != "正在跟踪") {
//                    Sleep(20);
//                }
//                single_cancel_(21,20);//取消控制：上
////                Sleep(500);
//            }
//            if(ui->label_15->text() != "正在跟踪")
//            {
//                DS = DS + 10;
//                double H = h_max_ - ui->lineEdit_11->text().toDouble();//无人机与可见光之间的高
//                FY_ = atan(H/double(i+200));//俯仰角范围FY1-FY2
//                FY_ = FY_*180/PI;
//                FY_ = abs(FY_-90);
//                H = h_min_ - ui->lineEdit_11->text().toDouble();
//                FY1_ = atan(H/double(i+200));
//                FY1_ = FY1_*180/PI;
//                FY1_ = abs(FY1_-90);
//                if(ui->label_15->text() != "正在跟踪")
//                {
//                    tail_after_over();// 释放跟踪
//                    Sleep(100);
//                    CProtocal_(i+200,FY_,DS);//引导，引导前不能是跟踪状态
//                    Sleep(1000);
//                    tail_after();//跟踪
//                }

//            }

//        }}
}


void MainWindow::on_pushButton_2_clicked()//截屏
{
//    QString filename1 = QFileDialog::getSaveFileName(this,tr("Save Image"),"",tr("Images (*.png *.bmp *.jpg)")); //选择路径
//    QScreen *screen = QGuiApplication::primaryScreen();
//    screen->grabWindow(ui->label->winId()).save(filename1);//另存为
//    QString filename1 = QFileDialog::getSaveFileName(this,tr("Save Image"),"",tr("Images (*.png *.bmp *.jpg)")); //选择路径
    QString filename1 = ui->lineEdit_13->text();
    if(filename1 == "")
        ui->textEdit_5->append("<font color=red>请选择保存路径。</font>");
    else
        {
    QScreen *screen = QGuiApplication::primaryScreen();
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QString current_date = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    bool booll = screen->grabWindow(ui->frame_2->winId()).save(QString("%1/%2.jpg").arg(filename1).arg(current_date));
    if(booll == false)
        ui->textEdit_5->append("<font color=red>选择的保存路径无效。</font>");
    else
        ui->textEdit_5->append("<font color= white>成功截屏。</font>");
        }

}


void MainWindow::on_pushButton_31_clicked()//另存为
{
    QString filename1 = QFileDialog::getExistingDirectory(this, "请选择文件路径...", "/");
    if(filename1!="")
    ui->lineEdit_13->setText(filename1);
}


/**
 * @brief MainWindow::on_pushButton_9_clicked 录制视频
 */
void MainWindow::on_pushButton_9_clicked()
{


    if (flag_start4)
    {
        flag_start4 = 0;
        ui->pushButton_9->setToolTip("结束录制");
        ui->pushButton_9->setStyleSheet("QPushButton{border-image:url(:/image/lx2.png);}"
                                         "QPushButton:hover{border-image:url(:/image/lx2.png);}");
        //...开始录制
        QString fi = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss-zzz");
        QString Videofilename =  ui->lineEdit_13->text()+"/"+ fi + ".avi";
        writeVideo.open(Videofilename.toLocal8Bit().toStdString(),VideoWriter::fourcc('M','P','4','2'),30.0,Size(1920,1080),true);
        fTimer->start(33);
    }
    else
    {
        flag_start4 = 1;
        ui->pushButton_9->setToolTip("开始录制");
        ui->pushButton_9->setStyleSheet("QPushButton{border-image:url(:/image/lx.png);}"
                                         "QPushButton:hover{border-image:url(:/image/lx2.png);}");
        //...结束录制
        fTimer->stop();
        writeVideo.release();

    }
}

/**
 * @brief MainWindow::sign_in 登录
 * @return
 */
HANDLE MainWindow::sign_in(HANDLE hCtl)
{
    hCtl = TMCC_Init( TMCC_INITTYPE_CONTROL );
    if (NULL == hCtl)
       {
           hCtl = TMCC_Init( TMCC_INITTYPE_CONTROL );
       }else
   {
   //无论先前是否已登录设备，都可以调用此接口进行断开操作
   TMCC_DisConnect(hCtl);
   }

       tmConnectInfo_t  tmLogin;
       memset( &tmLogin, 0, sizeof( tmConnectInfo_t ) );
       tmLogin.dwSize		= sizeof( tmConnectInfo_t );
       tmLogin.iPort		= 6002;
       sprintf( tmLogin.pIp, "192.168.1.4" );
       sprintf( tmLogin.szUser, "system" );
       sprintf( tmLogin.szPass, "system" );
       //设置连接超时值
       TMCC_SetTimeOut( hCtl,  3000 );
       //登录设备
       if( TMCC_ERR_SUCCESS != TMCC_Connect(hCtl,  &tmLogin,  FALSE) )
       {
           qDebug()<<"登录失败";
           ui->textEdit_5->append("<font color=red>设备登录失败，未与设备建立连接。</font>");
       }
       return hCtl;
}

/**
 * @brief MainWindow::single_click 云台控制
 * @param pattern 操作
 * @param speed 速度
 */
void MainWindow::single_click(int pattern,int speed)
{
    if (NULL == hCtl1)
    hCtl1 = sign_in(hCtl1);
    // 打开云台
    TMCC_PtzOpen(hCtl1, 0);
    // 控制命令:见上 云台控制命令参考  启停：1启动，0停止 速度：0-255
    TMCC_PtzControl(hCtl1, pattern, 1, speed);
}
void MainWindow::single_press(int pattern,int speed)
{
    hCtl1 = sign_in(hCtl1);
    // 打开云台
    TMCC_PtzOpen(hCtl1, 0);
    // 控制命令:见上 云台控制命令参考  启停：1启动，0停止 速度：0-255
    TMCC_PtzControl(hCtl1, pattern, 1, speed);
}
void MainWindow::single_cancel(int pattern,int speed)
{
    TMCC_PtzControl(hCtl1, pattern, 0, speed);
    // 关闭云台控制
    TMCC_PtzClose(hCtl1);
    TMCC_DisConnect(hCtl1);
    if(flag_satrt3 == 0){
        TMCC_PtzOpen(hCtl2, 0);// 打开云台，自动聚焦
        TMCC_PtzControl(hCtl2, 7, 1, 0);
    }
}
void MainWindow::single_press_(int pattern,int speed)
{
    hCtl7 = sign_in(hCtl7);
    // 打开云台
    TMCC_PtzOpen(hCtl7, 0);
    // 控制命令:见上 云台控制命令参考  启停：1启动，0停止 速度：0-255
    TMCC_PtzControl(hCtl7, pattern, 1, speed);
}
void MainWindow::single_cancel_(int pattern,int speed)
{
    TMCC_PtzControl(hCtl7, pattern, 0, speed);
    // 关闭云台控制
    TMCC_PtzClose(hCtl7);
    TMCC_DisConnect(hCtl7);
    if(flag_satrt3 == 0){
        TMCC_PtzOpen(hCtl2, 0);// 打开云台，自动聚焦
        TMCC_PtzControl(hCtl2, 7, 1, 0);
    }}
void MainWindow::on_pushButton_13_clicked()
{
    single_click(11,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_13_pressed()
{
    single_press(11,ui->lineEdit_spped_2->text().toInt());
}

void MainWindow::on_pushButton_13_released()
{
    single_cancel(11,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_16_clicked()
{
    single_click(12,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_16_pressed()
{
    single_press(12,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_16_released()
{
    single_cancel(12,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_14_clicked()
{
    single_click(13,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_14_pressed()
{
    single_press(13,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_14_released()
{
    single_cancel(13,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_15_clicked()
{
    single_click(14,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_15_pressed()
{
    single_press(14,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_15_released()
{
    single_cancel(14,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_30_clicked()
{
    single_click(15,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_30_pressed()
{
    single_press(15,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_30_released()
{
    single_cancel(15,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_29_clicked()
{
    single_click(16,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_29_pressed()
{
    single_press(16,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_29_released()
{
    single_cancel(16,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_17_clicked()
{
    single_click(27,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_17_pressed()
{
    single_press(27,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_17_released()
{
    single_cancel(27,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_18_clicked()
{
    single_click(21,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_18_pressed()
{
    single_press(21,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_18_released()
{
    single_cancel(21,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_19_clicked()
{
    single_click(25,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_19_pressed()
{
    single_press(25,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_19_released()
{
    single_cancel(25,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_20_clicked()
{
    single_click(24,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_20_pressed()
{
    single_press(24,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_20_released()
{
    single_cancel(24,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_21_clicked()
{
    single_click(26,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_21_pressed()
{
    single_press(26,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_21_released()
{
    single_cancel(26,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_22_clicked()
{
    single_click(22,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_22_pressed()
{
    single_press(22,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_22_released()
{
    single_cancel(22,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_23_clicked()
{
    single_click(28,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_23_pressed()
{
    single_press(28,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_23_released()
{
    single_cancel(28,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_24_clicked()
{
    single_click(23,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_24_pressed()
{
    single_press(23,ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_24_released()
{
    single_cancel(23,ui->lineEdit_spped_2->text().toInt());
}
/**
 * @brief MainWindow::on_pushButton_clicked打开雨刷器（单次）
 */
void MainWindow::on_pushButton_clicked()
{

    hCtl3 = sign_in(hCtl3);
    // 打开云台
    TMCC_PtzOpen(hCtl3, 0);
    // 控制命令:见上 云台控制命令参考  启停：1启动，0停止 速度：0-255
    TMCC_PtzControl(hCtl3, 3, 1, ui->lineEdit_spped_2->text().toInt());
}
void MainWindow::on_pushButton_4_clicked()//灯光
{

    if (flag_satrt1)
    {
        hCtl4 = sign_in(hCtl4);
        // 打开云台
        TMCC_PtzOpen(hCtl4, 0);
        // 控制命令:见上 云台控制命令参考  启停：1启动，0停止 速度：0-255
        TMCC_PtzControl(hCtl4, 2, 1, ui->lineEdit_spped_2->text().toInt());
        ui->pushButton_4->setStyleSheet("QPushButton{border-image:url(:/image/ddd.png);}"
                                         "QPushButton:hover{border-image:url(:/image/ddd.png);}");
        flag_satrt1 = 0;
    }
    else
    {
        TMCC_PtzControl(hCtl4, 2, 0, ui->lineEdit_spped_2->text().toInt());
        // 关闭云台控制
        TMCC_PtzClose(hCtl4);
        TMCC_DisConnect(hCtl4);
        ui->pushButton_4->setStyleSheet("QPushButton{border-image:url(:/image/dd.png);}"
                                         "QPushButton:hover{border-image:url(:/image/ddd.png);}");
        flag_satrt1 = 1;
    }

}
void MainWindow::on_pushButton_3_clicked()//风扇
{
    if (flag_satrt2)
    {
        hCtl5 = sign_in(hCtl5);
        // 打开云台
        TMCC_PtzOpen(hCtl5, 0);
        // 控制命令:见上 云台控制命令参考  启停：1启动，0停止 速度：0-255
        TMCC_PtzControl(hCtl5, 4, 1, ui->lineEdit_spped_2->text().toInt());
        ui->pushButton_3->setStyleSheet("QPushButton{border-image:url(:/image/fff.png);}"
                                         "QPushButton:hover{border-image:url(:/image/fff.png);}");
        flag_satrt2 = 0;
    }
    else
    {
        TMCC_PtzControl(hCtl5, 4, 0, ui->lineEdit_spped_2->text().toInt());
        // 关闭云台控制
        TMCC_PtzClose(hCtl5);
        TMCC_DisConnect(hCtl5);
        ui->pushButton_3->setStyleSheet("QPushButton{border-image:url(:/image/ff.png);}"
                                         "QPushButton:hover{border-image:url(:/image/fff.png);}");
        flag_satrt2 = 1;
    }
}
void MainWindow::on_pushButton_5_clicked()//自动聚焦
{
    if (flag_satrt3)
    {
        hCtl2 = sign_in(hCtl2);
        TMCC_PtzOpen(hCtl2, 0);// 打开云台
        TMCC_PtzControl(hCtl2, 7, 1, 0);
        ui->pushButton_5->setStyleSheet("QPushButton{border-image:url(:/image/jjj.png);}"
                                        "QPushButton:hover{border-image:url(:/image/jjj.png);}");
        flag_satrt3 = 0;
    }
    else
    {
        TMCC_PtzControl(hCtl2, 7, 0, ui->lineEdit_spped_2->text().toInt());
        // 关闭云台控制
        TMCC_PtzClose(hCtl2);
        TMCC_DisConnect(hCtl2);
        ui->pushButton_5->setStyleSheet("QPushButton{border-image:url(:/image/jj.png);}"
                                        "QPushButton:hover{border-image:url(:/image/jjj.png);}");
        flag_satrt3 = 1;
    }
}

/**
 * @brief MainWindow::on_pushButton_track_6_clicked 开始到指定位置
 */
void MainWindow::on_pushButton_track_6_clicked()
{
    FLAG = 2;
//    //回焦，保证能引导功能正常使用
//    unsigned char num2[] = {0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x89,0x80,0x8A,0x8B};
//    udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num2),sizeof(num2)),QHostAddress(ip),port);
//    Sleep(10);
    if(ui->lineEdit_7->text()==""||ui->lineEdit_8->text()==""||ui->lineEdit_9->text()=="")
        ui->textEdit_5->append("<font color=red>未设置引导值（水平角度：0~360度，垂直角度：0~180度）。</font>");
        else {
        QString i = ui->lineEdit_8->text();
        double a = i.toDouble();
        i = ui->lineEdit_9->text();
        double b = i.toDouble();
        i = ui->lineEdit_7->text();
        double c = i.toDouble();
        tail_after_over();
        Sleep(200);
        CProtocal_(a,c,b);
    }
}

/**
 * @brief MainWindow::on_pushButton_track_7_clicked 开始到指定位置并自动跟踪
 */
void MainWindow::on_pushButton_track_7_clicked()
{
    FLAG = 1;
//    //回焦，保证能引导功能正常使用
//    unsigned char num2[] = {0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x89,0x80,0x8A,0x8B};
//    udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num2),sizeof(num2)),QHostAddress(ip),port);
//    Sleep(10);
    if(ui->lineEdit_7->text()==""||ui->lineEdit_8->text()==""||ui->lineEdit_9->text()=="")
        ui->textEdit_5->append("<font color=red>未设置引导值（水平角度：0~360度，垂直角度：0~180度）。</font>");
        else {
        QString i = ui->lineEdit_8->text();
        double a = i.toDouble();
        i = ui->lineEdit_9->text();
        double b = i.toDouble();
        i = ui->lineEdit_7->text();
        double c = i.toDouble();
        tail_after_over();
        Sleep(200);
        CProtocal_(a,c,b);
        Sleep(500);
        tail_after();
        Sleep(500);
    }
}


/**
 * @brief MainWindow::on_pushButton_track_12_clicked到指定焦距按钮
 */
void MainWindow::on_pushButton_track_12_clicked()
{
    if(ui->lineEdit_12->text()=="")
        ui->textEdit_5->append("<font color=red>未设置引导值（焦距：单位mm，值：0~290）。</font>");
    else{
        QString i = ui->lineEdit_12->text();
        double a = i.toDouble();
        CProtocal__(a);
    }
}

/**
 * @brief MainWindow::CProtocal_ 引导函数
 * @param a 距离
 * @param b 俯仰角
 * @param c 水平角
 */
void MainWindow::CProtocal_(double a,double b,double c)//引导
{
//    QVector<unsigned char> buf;

    std::array<unsigned char, 1024> buf;
    Text pro;
    pro.setDistance(a*1.0);
    pro.setVerAngle(b);
    pro.setHorAngle(c);
    int len = pro.construct(buf.data(), buf.max_size());//buf.max_size()
    if (len <= 0)
    {
        ui->textEdit_5->append("<font color=red>引导命令发送失败。</font>");
    }
    int ret = udpSocket->writeDatagram((const char*)buf.data(),len,QHostAddress(ip),port);//发送自定义引导命令

    if (ret == len)
    {
        ui->textEdit_5->append("<font color=white>引导命令发送成功。</font>");
    }
    else
    {
        ui->textEdit_5->append("<font color=red>引导命令发送失败。</font>");
    }

}

int  Text::construct(unsigned char* buff, int len)//信息内容赋值函数
{

    memset(reserved, 0, sizeof(reserved));//清零。
    Head H;
    H.setCmd(0x03);
    H.setAttachDataLen(protocal_head);
    unsigned char* ptrBuf = NULL;
    int iDataLen = H.getData(ptrBuf);
    int proc_len = 0;
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&number, sizeof(number));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&sys_number, sizeof(sys_number));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&timestamp, sizeof(timestamp));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&lng, sizeof(lng));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&lat, sizeof(lat));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&height, sizeof(height));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&distance, sizeof(distance));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&hor_angle, sizeof(hor_angle));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)&ver_angle, sizeof(ver_angle));
    proc_len += H.append(ptrBuf + proc_len, (unsigned char*)reserved, sizeof(reserved));
    return H.construct(buff, len);
}

int Head::getData(unsigned char*& buff)
{
    buff = data.buff.data();
    return data.data_len;
}
int Head::append(unsigned char* buff, const unsigned char* data, int len)
{
    assert((NULL != buff) && (NULL != data) && (len >= 0));
    memcpy(buff, data, len);
    return len;
}
int Head::construct(unsigned char* buff, int len)//数据包赋值函数
{

    assert(NULL != buff);//条件返回错误，终止程序。

    packet_len = data.data_len + 20;

    if (len < packet_len + 16)
    {
        //LOG_TRACE << "buffer too small.";
        return -1;
    }

    unsigned char* lpBit = (unsigned char*)&start_bit; //给起始位赋值
    lpBit[0] = 0x88;
    lpBit[1] = 0x89;
    lpBit[2] = 0x80;
    lpBit[3] = 0x8A;

    lpBit = (unsigned char*)&stop_bit; //给终止位赋值
    lpBit[0] = 0x89;
    lpBit[1] = 0x80;
    lpBit[2] = 0x8A;
    lpBit[3] = 0x8B;
    pro_number = 9002;
    timestamp = 0;// GetTickCount64();

    int iDiff = 0;
    iDiff += Value(*(unsigned int*)(buff + iDiff), start_bit);
    iDiff += Value(*(unsigned int*)(buff + iDiff), pro_number);
    iDiff += Value(*(unsigned int*)(buff + iDiff), packet_len);
    iDiff += Value(*(unsigned int*)(buff + iDiff), cmd);
    iDiff += Value(*(unsigned long long*)(buff + iDiff), timestamp);

    memcpy(buff+iDiff, data.buff.data(), data.data_len); //从data_.buff.data()赋值data_.data_len个字节到buff+iDiff
    iDiff += data.data_len;
    iDiff += Value(*(unsigned int*)(buff + iDiff), message_index);

    // 错误校验
    /*
    * 错误校验码采用校验和方法。
    * 协议体中从“包长度”到“信息序列号” （包括“包长度”、 “信息序列号”）这部分数据。
    */
    int verify = 0;
    for (int i = 8; i < iDiff; i++)
    {
        verify += buff[i];
    }
    verify = verify;

    iDiff += Value(*(unsigned int*)(buff + iDiff), verify);
    iDiff += Value(*(unsigned int*)(buff + iDiff), stop_bit);
    valid(true);
    return iDiff;
}

/**
 * @brief MainWindow::CProtocal__到指定焦距
 * @param a 焦距（mm）
 */
void MainWindow::CProtocal__(double a)//CProtocal__到指定焦距
{
    std::array<unsigned char, 1024> buf;
    CCameraLensInfoProtocal pro;
    pro.setCmd(0x01);
    pro.setZoom(a);
    int len = pro.construct(buf.data(), buf.max_size());//buf.max_size()
    if (len <= 0)
    {
        ui->textEdit_5->append("<font color=red>引导命令发送失败。</font>");
    }
    int ret = udpSocket->writeDatagram((const char*)buf.data(),len,QHostAddress(ip),port);//发送自定义引导命令

    if (ret == len)
    {
        ui->textEdit_5->append("<font color=white>引导命令发送成功。</font>");
//        Sleep(6000);
//        if(FLAG==1)
//        {
//            unsigned char num[]={0x88,0x89,0x80,0x8A,0x2A,0x23,0x00,0x00,0x38,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x38,0x3C,0xFE,0x0F,0x01,0x0A,0x4F,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x90,0x3C,0xFE,0x0F,0x00,0x00,0x00,0x00,0x64,0xF6,0x4F,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0x07,0x00,0x00,0x89,0x80,0x8A,0x8B};
//            udpSocket->writeDatagram(QByteArray(reinterpret_cast<char *>(num),sizeof(num)),QHostAddress(ip),port);
//            ui->textEdit_5->append("<font color=white>正在自动扫描、跟踪无人机。</font>");
//        }
    }
    else
    {
        ui->textEdit_5->append("<font color=red>引导命令发送失败。</font>");
    }

}
/**
 * @brief CCameraLensInfoProtocal::construct焦距数据赋值
 * @param buff 数据包
 * @param len 长度
 * @return
 */
int CCameraLensInfoProtocal::construct(BYTE* buff, int len)
{
    Head H;
    H.setCmd(0x09);
    H.setAttachDataLen(protocal_head_len);

    BYTE* ptrBuf = NULL;
    int iDataLen = H.getData(ptrBuf);
    int proc_len = 0;
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&number_, sizeof(number_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&sys_number_, sizeof(sys_number_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&timestamp_, sizeof(timestamp_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&cmd_, sizeof(cmd_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&zoom_, sizeof(zoom_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&zoom_step_, sizeof(zoom_step_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&focus_step_, sizeof(focus_step_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&reserved_, sizeof(reserved_));
    return H.construct(buff, len);
}

/**
 * @brief MainWindow::CProtocal___ 搜索、跟踪、释放跟踪
 *      SEARCH = 1,//搜索并自动跟踪
        TRACK = 2,//跟踪
        FREE = 3,//释放
        ONLY_SEARCH = 4//仅搜索
 * @param a_cmd
 *
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
    *
 * @param a_cmda
 * /// 水平开始角度
 * @param s_min
 * /// 水平结束角度
 * @param s_max
 * /// 俯仰开始角度
 * @param f_min
 * /// 俯仰结束角度
 * @param f_max
 */
void MainWindow::CProtocal___(int a_cmd,int a_cmda,int s_min,int s_max,int f_min,int f_max)
{
    std::array<unsigned char, 1024> buf;
    CCameraCtrlProtocal pro1;
    pro1.setCmd(a_cmd);
    pro1.setSearchMode(a_cmda);
    pro1.setHorStartAngle(s_min);
    pro1.setHorEndAngle(s_max);
    pro1.setVerStartAngle(f_min);
    pro1.setVerEndAngle(f_max);
    int len = pro1.construct(buf.data(), buf.max_size());//buf.max_size()
    if (len <= 0)
    {
        ui->textEdit_5->append("<font color=red>引导命令发送失败。</font>");
    }
    int ret = udpSocket->writeDatagram((const char*)buf.data(),len,QHostAddress(ip),port);//发送自定义引导命令

    if (ret == len)
    {
        ui->textEdit_5->append("<font color=white>引导命令发送成功。</font>");
    }
    else
    {
        ui->textEdit_5->append("<font color=red>引导命令发送失败。</font>");
    }

}
void CCameraCtrlProtocal::setSearchMode(int v)
{
    *(unsigned int*)(reserved_) = v;
}
int CCameraCtrlProtocal::construct(BYTE* buff, int len)
{
    Head H;
    H.setCmd(0x04);
    H.setAttachDataLen(protocal_head_len);

    BYTE* ptrBuf = NULL;
    int iDataLen = H.getData(ptrBuf);
    int proc_len = 0;
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&number_, sizeof(number_));

    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&timestamp_, sizeof(timestamp_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&cmd_, sizeof(cmd_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&hor_start_angle_, sizeof(hor_start_angle_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&hor_end_angle_, sizeof(hor_end_angle_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&ver_start_angle_, sizeof(ver_start_angle_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&ver_end_angle_, sizeof(ver_end_angle_));
    proc_len += H.append(ptrBuf + proc_len, (BYTE*)&reserved_, sizeof(reserved_));
    return H.construct(buff, len);
}



/**
 * @brief MainWindow::on_pushButton_track_11_clicked配置定位模块
 */
void MainWindow::on_pushButton_track_11_clicked()
{
    dialog_->show();
}

/**
 * @brief MainWindow::sjjs获取配置信息
 * @param level
 * @param pitch
 * @param dis
 * @param time
 * @param min_spend
 * @param max_spend
 */
void MainWindow::sjjs(double level,double pitch,double dis,double time,double min_spend,double max_spend,double s_min,double s_max,double h_min,double h_max,QString K,double v_min,double v_max,double speed,double jg,double height,bool mr,QString model)
{
    level__ = level;
    pitch__ = pitch;
    dis__ = dis;
    time__ = time;
    max_spend__ = max_spend;
    min_spend__ = min_spend;
    s_min_ = s_min;
    s_max_ = s_max;
    h_min_ = h_min;
    h_max_ = h_max;
    K_ = K;
    v_min_ = v_min;
    v_max_ = v_max;
    speed_ = speed;
    jg_ = jg;
    height_ = height;
    mr_ = mr;
    model_ = model;

//    qDebug()<<dis__;
    double H = h_max_ - height;//无人机与可见光之间的高
    FY_ = atan(H/double(s_min_));//俯仰角范围FY1-FY2
    FY_ = FY_*180/PI;
    FY_ = abs(FY_-90);
    H = h_min_ - height;
    FY1_ = atan(H/double(s_min_));
    FY1_ = FY1_*180/PI;
    FY1_ = abs(FY1_-90);

//    if(ui->radioButton->isChecked()==true)
//    {
//    tail_after_over();// 释放跟踪
//    Sleep(100);
//    CProtocal_(s_min,FY_,pitch_.hor_angle);//引导，引导前不能是跟踪状态
//    Sleep(1000);
//    tail_after();//跟踪
//    }



}

/**
 * @brief MainWindow::mousePressEvent鼠标事件设置（窗口移动）
 * @param event
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if( (event->button() == Qt::LeftButton) ){
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
//        event->accept();
    }
//    else if(event->button() == Qt::RightButton){
//        //如果是右键
//        this->close();

//    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
//    if(event->buttons() == Qt::LeftButton){  //如果这里写这行代码，拖动会有点问题
    if(mouse_press){
        move(event->globalPos() - mousePoint);
//        event->accept();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}
void MainWindow::on_pushButton_6_clicked()//关闭主窗口
{
    this->close();
}
void MainWindow::on_pushButton_7_clicked()//隐藏主窗口
{
    this->showMinimized();
}



void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked)
    {
//        ui->pushButton_track_11->setEnabled(true);
     FLAG_2 = 1;}
    else
    {
//        ui->pushButton_track_11->setEnabled(false);
        FLAG_2 = 0;
    }
}
cv::Mat MainWindow::bufferToMat(unsigned char* pBuffer, int nWidth, int nHeight, int nBandNum, int nBPB)
{
    cv::Mat mDst;
    if (nBandNum == 4)
    {
        if (nBPB == 1)
        {
            mDst = cv::Mat::zeros(cv::Size(nWidth, nHeight), CV_8UC4);
        }
        else if (nBPB == 2)
        {
            mDst = cv::Mat::zeros(cv::Size(nWidth, nHeight), CV_16UC4);
        }
    }
    else if (nBandNum == 3)
    {
        if (nBPB == 1)
        {
            mDst = cv::Mat::zeros(cv::Size(nWidth, nHeight), CV_8UC3);
        }
        else if (nBPB == 2)
        {
            mDst = cv::Mat::zeros(cv::Size(nWidth, nHeight), CV_16UC3);

        }
    }
    else if (nBandNum == 1)
    {
        if (nBPB == 1)
        {
            mDst = cv::Mat::zeros(cv::Size(nWidth, nHeight), CV_8UC1);
        }
        else if (nBPB == 2)
        {
            mDst = cv::Mat::zeros(cv::Size(nWidth, nHeight), CV_16UC1);
        }
    }

    for (int j = 0; j < nHeight; ++j)
    {
        unsigned char* data = mDst.ptr<unsigned char>(j);
        unsigned char* pSubBuffer = pBuffer + (j) * nWidth  * nBandNum * nBPB;
        memcpy(data, pSubBuffer, nWidth * nBandNum * nBPB);
    }

    return mDst;
}
void MainWindow::SPSave()
{
    mut.lock();
    frame = bufferToMat(reinterpret_cast<unsigned char *>(buf),1920,1080,3,1);
    writeVideo.write(frame);
    mut.unlock();
}
