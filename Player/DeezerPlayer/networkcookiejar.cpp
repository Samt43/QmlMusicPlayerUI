#include "networkcookiejar.h"
#include <QDebug>

NetworkCookieJar::NetworkCookieJar()
{
}

bool NetworkCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url)
{
    /*
     qDebug()<<"set : "<<url.host();
    if (mapCookies.contains(url.host()))
    {
        mapCookies[url.host()].append(cookieList);
    }
    else
    {
        mapCookies[url.host()].append(cookieList);
    }
    */

    listCookies.append(cookieList);
    return true;
}

QList<QNetworkCookie> NetworkCookieJar::cookiesForUrl(const QUrl &url) const
{
     qDebug()<<"get : "<<url.host();
     /*
    if (mapCookies.contains(url.host()))
        return mapCookies[url.host()];
    else
        return QList<QNetworkCookie>();

        */

     return listCookies;

}

