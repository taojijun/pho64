#ifndef VIDEOSAV_H
#define VIDEOSAV_H

#include <QObject>
#include <QThread>
class VideoSav : public QThread
{
    Q_OBJECT
public:
    explicit VideoSav(QObject *parent = nullptr);

signals:
protected:
    void run();
signals:
    void Vlj();
};

#endif // VIDEOSAV_H
