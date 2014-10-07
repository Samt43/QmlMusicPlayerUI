#ifndef NETWORKCOOKIEJAR_H
#define NETWORKCOOKIEJAR_H

#include <QNetworkCookieJar>
#include <QMap>
#include <QNetworkCookie>


class NetworkCookieJar : public QNetworkCookieJar
{
public:
    NetworkCookieJar();
    bool setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url);
    QList<QNetworkCookie> cookiesForUrl(const QUrl &url) const;

protected:
    QMap<QString,QList<QNetworkCookie> > mapCookies;
    QList<QNetworkCookie> listCookies;
};

#endif // NETWORKCOOKIEJAR_H
