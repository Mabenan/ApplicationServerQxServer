#include "ApplicationServerQxServerPlugin.h"
#include "ApplicationServerQxServer.h"
#include <QDebug>

ApplicationServerQxServerPlugin::ApplicationServerQxServerPlugin(QObject *parent)
    : ApplicationServerPluginInterface(parent)
{
}

void ApplicationServerQxServerPlugin::init(ApplicationServerInterface *app)
{
    app->registerWebInterface(new ApplicationServerQxServer(this));
}

void ApplicationServerQxServerPlugin::install(ApplicationServerInterface * app)
{

}
