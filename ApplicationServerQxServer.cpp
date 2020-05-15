#include "ApplicationServerQxServer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QtXml>
ApplicationServerQxServer::ApplicationServerQxServer(QObject *parent)
    : WebInterface(parent)
{

}

QString ApplicationServerQxServer::getName() const
{
    return "QxServer";
}

QHttpServerResponse ApplicationServerQxServer::execute(const QHttpServerRequest *request, ApplicationServerInterface *app)
{
	QHttpServerResponse * response = nullptr;
	QJsonObject bodyJSON;
	QJsonParseError parseError;
	bodyJSON = QJsonDocument::fromJson(request->body(), &parseError).object();
	qDebug() << parseError.errorString();
	qx::QxRestApi restApi;

    QVariant result;
    QHttpServerResponse::StatusCode statusCode = QHttpServerResponse::StatusCode::Ok;
    try{
    result = restApi.processRequest(bodyJSON);

    }catch (std::exception &oex){

    	qDebug() << oex.what();
    	result = "Error";
    	statusCode = QHttpServerResponse::StatusCode::NotFound;
    }
    switch (result.type())
    {
    case QMetaType::QJsonObject:
    	response = new QHttpServerResponse(result.toJsonObject());
        break;
    case QMetaType::QJsonValue:
    	response = new QHttpServerResponse(result.toJsonValue().toObject());
        break;
    default:
    	QString resultString = result.toString();
    	if(resultString.startsWith("XML:")){
    		resultString = resultString.remove(0,4);
        	response = new QHttpServerResponse(QByteArrayLiteral("application/xml"), resultString.toUtf8());
    	}else{
        	response = new QHttpServerResponse(resultString);
    	}
        break;
    }
    QHttpServerResponse resp = QHttpServerResponse(response->mimeType(), response->data(),statusCode);
    return resp;
}

QString ApplicationServerQxServer::getRoute(ApplicationServerInterface *app)
{
    return "/qx";
}
