#ifndef DATAPROXY_H
#define DATAPROXY_H

#include <QObject>

#include "IDataProxy.h"

class IDataProvider;

class DataProxy:public QObject, public IDataProxy
{
    Q_OBJECT
    Q_INTERFACES(IDataProxy)

public:
    DataProxy(IDataProvider* provider, QObject* parent);

    void askForSomeWork(ParamCommand cmd);

public slots:
    void doReplySomeWork(ParamCommand cmd, IDataProxy* proxy);

signals:
    void sigAskForSomeWork(ParamCommand cmd, IDataProxy* proxy) override;
    void sigReplySomeWork(ParamCommand cmd, IDataProxy* proxy) override;

private:
    IDataProvider* dataProvider = nullptr;
};
#endif // DATAPROXY_H
