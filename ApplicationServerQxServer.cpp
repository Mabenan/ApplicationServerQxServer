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

  QVariant result;
  int statusCode = 200;
  try {
    result = restApi.processRequest(bodyJSON);

  } catch (std::exception &oex) {

    qDebug() << oex.what();
    result = "Error";
    statusCode = 404;
  }
  switch (result.type()) {
  case QMetaType::QJsonObject:
    response.data() = QJsonDocument(result.toJsonObject()).toJson();
    break;
  default:
    QString resultString = result.toString();
    if (resultString.startsWith(QString::fromLatin1("XML:"))) {
      resultString = resultString.remove(0, 4);
      response.data() = resultString.toUtf8();
    } else {
      response.data() = resultString.toUtf8();
    }
    break;
  }
  response.status() = statusCode;
}

QString
ApplicationServerQxServer::getRoute(ApplicationServerInterface * /*app*/) {
  return QString::fromLatin1("/qx");
}
