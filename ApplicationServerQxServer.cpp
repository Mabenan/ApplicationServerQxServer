#include "ApplicationServerQxServer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QtXml>
ApplicationServerQxServer::ApplicationServerQxServer(QObject *parent)
    : WebInterface(parent) {}

QString ApplicationServerQxServer::getName() const {
  return QStringLiteral("QxServer");
}

void ApplicationServerQxServer::execute(qx::QxHttpRequest &request,
                                        qx::QxHttpResponse &response,
                                        ApplicationServerInterface * /*app*/) {
  QJsonObject bodyJSON;
  QJsonParseError parseError{};
  bodyJSON = QJsonDocument::fromJson(request.data(), &parseError).object();
  qDebug() << parseError.errorString();
  qx::QxRestApi restApi;

  QJsonValue result;
  int statusCode = 200;
  try {
    result = restApi.processRequest(bodyJSON);

  } catch (std::exception &oex) {

    qDebug() << oex.what();
    response.data() = "Error";
    statusCode = 404;
  }
  response.data() = QJsonDocument(result.toObject()).toJson();
  response.status() = statusCode;
}

QString
ApplicationServerQxServer::getRoute(ApplicationServerInterface * /*app*/) {
  return QStringLiteral("/qx");
}
