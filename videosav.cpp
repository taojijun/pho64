#include "videosav.h"

int FLV = 0;

VideoSav::VideoSav(QObject *parent) : QThread(parent)
{

}
void VideoSav::run()
{

    while (1) {
        if(FLV)
        {
            emit Vlj();
            QThread::msleep(40);
        }
        else
        {
            QThread::msleep(40);
        }
    }
}
