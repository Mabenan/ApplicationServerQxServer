#ifndef APPLICATIONSERVERQXSERVER_GLOBAL_H
#define APPLICATIONSERVERQXSERVER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(APPLICATIONSERVERQXSERVER_LIBRARY)
#  define APPLICATIONSERVERQXSERVER_EXPORT Q_DECL_EXPORT
#else
#  define APPLICATIONSERVERQXSERVER_EXPORT Q_DECL_IMPORT
#endif

#endif // APPLICATIONSERVERQXSERVER_GLOBAL_H
