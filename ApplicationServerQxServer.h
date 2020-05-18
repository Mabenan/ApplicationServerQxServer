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
     void execute(qx::QxHttpRequest  & request, qx::QxHttpResponse & response, ApplicationServerInterface * app);
};

#endif // ODATAWEBHANDLER_H
