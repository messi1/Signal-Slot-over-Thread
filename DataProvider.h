#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>

#include "IDataProvider.h"

class IDataProxy;

class DataProvider:public QObject, public IDataProvider
{
    Q_OBJECT
    Q_INTERFACES(IDataProvider)

public:
    DataProvider(QObject* parent);

public slots:
    void doSomeWork(ParamCommand cmd, IDataProxy* proxy) override;

signals:
    void sigReplySomeWork(ParamCommand cmd, IDataProxy* proxy) override;
};

#endif // DATAPROVIDER
