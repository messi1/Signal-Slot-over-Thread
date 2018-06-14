#include <QDebug>
#include <QThread>


#include "IDataProvider.h"
#include "DataProxy.h"


DataProxy::DataProxy(IDataProvider* provider, QObject* parent)
    :QObject(parent),
      dataProvider(provider)
{
//        connect(this, &DataProxy::sigAskForSomeWork, dynamic_cast<const QObject*>(dataProvider), &IDataProvider::doSomeWork);
//        connect(dataProvider, &IDataProvider::sigReplySomeWork, this, &DataProxy::doReplySomeWork);
//        QObject::connect(dynamic_cast<QObject*>(dataProvider), SIGNAL(sigReplySomeWork(ParamCommand,IDataProxy*)),
//                         this, SLOT(doReplySomeWork(ParamCommand,IDataProxy*)));

    connect(this, SIGNAL(sigAskForSomeWork(ParamCommand,IDataProxy*)),
                     dynamic_cast<QObject*>(dataProvider), SLOT(doSomeWork(ParamCommand,IDataProxy*)));

    connect(this, &DataProxy::sigReplySomeWork, this, &DataProxy::doReplySomeWork);
}


void DataProxy::askForSomeWork(ParamCommand cmd)
{
    qDebug() << "DataProxy::askForSomeWork(" << to_underlying(cmd) << ") on thread: " << QThread::currentThread();
    emit this->sigAskForSomeWork(cmd, this);
}


void DataProxy::doReplySomeWork(ParamCommand cmd, IDataProxy* proxy)
{
    if(this == proxy)
    {
        Q_UNUSED(cmd)
        qDebug() << "DataProxy::doReplySomeWork(" << to_underlying(cmd) << ") on thread: " << QThread::currentThread();
    }
    else
        qDebug() << "Not mention for me";
}
