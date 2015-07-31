#include "huelight.h"

HueLight::HueLight()
{
    is_on = bri = sat = hue = -1;
    x = y = -1.0;
}

void HueLight::read(const QJsonObject &jObj)
{
    for (QJsonObject::const_iterator it = jObj.begin(); it != jObj.end(); it++)
    {
        QString name = it.key();
        QJsonValue val = it.value();
        qDebug() << name << ":" << val;
        if (name.compare("name") == 0)
        {
            this->name = val.toString();
        }
        else if (name.compare("state") == 0)
        {
            QJsonObject stateobj = val.toObject();
            for (QJsonObject::iterator it2 = stateobj.begin(); it2 != stateobj.end(); it2++)
            {   //no type checking!
                if (it2.key().compare("bri") == 0)
                {
                    bri = it2.value().toInt();
                }
                if (it2.key().compare("hue") == 0)
                {
                    hue = it2.value().toInt();
                }
                if (it2.key().compare("sat") == 0)
                {
                    sat = it2.value().toInt();
                }
                if (it2.key().compare("on") == 0)
                {
                    is_on = it2.value().toBool();
                }
                //can also use find:
                if (it2.key().compare("xy")==0)
                {   //in this case, xy is an array [x, y]
                    QJsonArray arr = it2.value().toArray();
                    x = arr.at(0).toDouble();
                    y = arr.at(1).toDouble();
                }
            }
        }

    }
}

void HueLight::print()
{
    qDebug() << "\n\n\nParsed light: " << name
             << "\n on = " << is_on
             << "\n bri = " <<bri
             << "\n sat = " <<sat
             << "\n hue = " <<hue
             << "\n X = " << x
             << "\n Y = " << y;
}
