#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QDebug>
#pragma execution_character_set("utf-8")
class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);
    int cfg(QString k,int dis);

signals:

public slots:
};

#endif // CONFIG_H
