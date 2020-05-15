#ifndef ApplicationServerQxServerPlugin_H
#define ApplicationServerQxServerPlugin_H

#include <ApplicationServerPluginInterface.h>

class ApplicationServerQxServerPlugin : public ApplicationServerPluginInterface
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID ApplicationServerPluginInterface_iid FILE "ApplicationServerQxServer.json")
    Q_INTERFACES(ApplicationServerPluginInterface)

public:
    explicit ApplicationServerQxServerPlugin(QObject *parent = nullptr);

private:
    // CommandInterface interface
public:
    void init(ApplicationServerInterface *app);
	virtual void install(ApplicationServerInterface *app);
};

#endif // ODataPlugin_H
