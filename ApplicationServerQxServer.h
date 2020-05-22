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
     QString getName() const override;
     QString getRoute(ApplicationServerInterface * app) override;
     void execute(qx::QxHttpRequest  & request, qx::QxHttpResponse & response, ApplicationServerInterface * app) override;
};

#endif // ODATAWEBHANDLER_H
