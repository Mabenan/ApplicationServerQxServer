#ifndef ApplicationServerQxServer_H
#define ApplicationServerQxServer_H

#include <WebInterface.h>
#include "ApplicationServerCore_global.h"

class ApplicationServerQxServer : public WebInterface
{
    Q_OBJECT
public:
    explicit ApplicationServerQxServer(QObject *parent = nullptr);

private:
public:
     QString getName() const;
     QString getRoute(ApplicationServerInterface * app);
     QHttpServerResponse execute(const QHttpServerRequest * request, ApplicationServerInterface * app);
};

#endif // ODATAWEBHANDLER_H
