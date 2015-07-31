#ifndef HUELIGHT_H
#define HUELIGHT_H

#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QDebug>


class HueLight
{
public:
    HueLight();

    void read(const QJsonObject &jObj);

    void print();

private:

    //just a subset of values
    int is_on;

    int bri;
    int hue;
    int sat;

    float x;
    float y;

    QString name;
};

#endif // HUELIGHT_H
