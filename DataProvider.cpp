#include <QDebug>
#include <QThread>

#include "IDataProxy.h"
#include "DataProvider.h"



DataProvider::DataProvider(QObject* parent)
    :QObject(parent)
{
    qRegisterMetaType<ParamCommand>("ParamCommand");
}


void DataProvider::doSomeWork(ParamCommand cmd, IDataProxy* proxy)
{
    qDebug() << "DataProvider::doSomeWork(" << to_underlying(cmd) << ") on thread: " << QThread::currentThread();
//        emit sigReplySomeWork(cmd, proxy);
    emit proxy->sigReplySomeWork(cmd, proxy);
}
