#ifndef JACKETPROVIDER_H
#define JACKETPROVIDER_H

#include <QQuickImageProvider>

class JacketProvider : public QQuickImageProvider
{
public:
    JacketProvider();
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
};

#endif // JACKETPROVIDER_H
