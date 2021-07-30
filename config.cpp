#include "config.h"

Config::Config(QObject *parent) : QObject(parent)
{

}

int Config::cfg(QString k,int dis)
{
    dis = dis/50;
    if(k == "晴天")
        switch (dis) {
        case 21:
            return 285;
            break;
        case 20:       //dis>=1000 && dis<1050
            return 275;
            break;
        case 19:
            return 265;
            break;
        case 18:
            return 250;
            break;
        case 17:
            return 235;
            break;
        case 16:
            return 220;
            break;
        case 15:
            return 200;
            break;
        case 14:
            return 170;
            break;
        case 13:
            return 150;
            break;
        case 12:
            return 130;
            break;
        case 11:
            return 115;
            break;
        case 10:
            return 110;
            break;
        case 9:
            return 100;
            break;
        case 8:
            return 90;
            break;
        case 7:
            return 80;
            break;
        case 6:
            return 70;
            break;
        case 5:
            return 60;
            break;
        case 4:
            return 50;
            break;
        case 3:
            return 40;
            break;
        case 2:
            return 30;
            break;
        case 1:    //dis>=50 && dis<100
            return 20;
            break;
        case 0:    //dis>=0 && dis<50
            return 10;
            break;
        default:   //dis>=1050
            return 290;
            break;
        }


    else if(k == "多云")
        switch (dis) {
        case 21:
            return 290;
            break;
        case 20:       //dis>=1000 && dis<1050
            return 285;
            break;
        case 19:
            return 285;
            break;
        case 18:
            return 260;
            break;
        case 17:
            return 240;
            break;
        case 16:
            return 210;
            break;
        case 15:
            return 180;
            break;
        case 14:
            return 165;
            break;
        case 13:
            return 155;
            break;
        case 12:
            return 145;
            break;
        case 11:
            return 135;
            break;
        case 10:
            return 125;
            break;
        case 9:
            return 115;
            break;
        case 8:
            return 95;
            break;
        case 7:
            return 85;
            break;
        case 6:
            return 75;
            break;
        case 5:
            return 60;
            break;
        case 4:
            return 50;
            break;
        case 3:
            return 45;
            break;
        case 2:
            return 30;
            break;
        case 1:    //dis>=50 && dis<100
            return 25;
            break;
        case 0:    //dis>=0 && dis<50
            return 15;
            break;
        default:   //dis>=1050
            return 290;
            break;
        }

    else if(k == "阴天")
        switch (dis) {
        case 21:
            return 285;
            break;
        case 20:       //dis>=1000 && dis<1050
            return 275;
            break;
        case 19:
            return 265;
            break;
        case 18:
            return 250;
            break;
        case 17:
            return 235;
            break;
        case 16:
            return 220;
            break;
        case 15:
            return 200;
            break;
        case 14:
            return 170;
            break;
        case 13:
            return 150;
            break;
        case 12:
            return 130;
            break;
        case 11:
            return 115;
            break;
        case 10:
            return 110;
            break;
        case 9:
            return 100;
            break;
        case 8:
            return 90;
            break;
        case 7:
            return 80;
            break;
        case 6:
            return 70;
            break;
        case 5:
            return 60;
            break;
        case 4:
            return 50;
            break;
        case 3:
            return 40;
            break;
        case 2:
            return 30;
            break;
        case 1:    //dis>=50 && dis<100
            return 20;
            break;
        case 0:    //dis>=0 && dis<50
            return 10;
            break;
        default:   //dis>=1050
            return 290;
            break;
        }

    else if(k == "小雨")
        switch (dis) {
        case 21:
            return 285;
            break;
        case 20:       //dis>=1000 && dis<1050
            return 275;
            break;
        case 19:
            return 265;
            break;
        case 18:
            return 250;
            break;
        case 17:
            return 235;
            break;
        case 16:
            return 220;
            break;
        case 15:
            return 200;
            break;
        case 14:
            return 170;
            break;
        case 13:
            return 150;
            break;
        case 12:
            return 130;
            break;
        case 11:
            return 115;
            break;
        case 10:
            return 110;
            break;
        case 9:
            return 100;
            break;
        case 8:
            return 90;
            break;
        case 7:
            return 80;
            break;
        case 6:
            return 70;
            break;
        case 5:
            return 60;
            break;
        case 4:
            return 50;
            break;
        case 3:
            return 40;
            break;
        case 2:
            return 30;
            break;
        case 1:    //dis>=50 && dis<100
            return 20;
            break;
        case 0:    //dis>=0 && dis<50
            return 10;
            break;
        default:   //dis>=1050
            return 290;
            break;
        }

    else if(k == "小雾")
        switch (dis) {
        case 21:
            return 285;
            break;
        case 20:       //dis>=1000 && dis<1050
            return 275;
            break;
        case 19:
            return 265;
            break;
        case 18:
            return 250;
            break;
        case 17:
            return 235;
            break;
        case 16:
            return 220;
            break;
        case 15:
            return 200;
            break;
        case 14:
            return 170;
            break;
        case 13:
            return 150;
            break;
        case 12:
            return 130;
            break;
        case 11:
            return 115;
            break;
        case 10:
            return 110;
            break;
        case 9:
            return 100;
            break;
        case 8:
            return 90;
            break;
        case 7:
            return 80;
            break;
        case 6:
            return 70;
            break;
        case 5:
            return 60;
            break;
        case 4:
            return 50;
            break;
        case 3:
            return 40;
            break;
        case 2:
            return 30;
            break;
        case 1:    //dis>=50 && dis<100
            return 20;
            break;
        case 0:    //dis>=0 && dis<50
            return 10;
            break;
        default:   //dis>=1050
            return 290;
            break;
        }
}
