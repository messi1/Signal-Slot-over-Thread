#ifndef IDATAPROVIDER_H
#define IDATAPROVIDER_H

#include <QObject>

#include "CommandList.h"

class IDataProxy;

class IDataProvider
{
public:
    virtual ~IDataProvider() = default;

public slots:
   virtual  void doSomeWork(ParamCommand cmd, IDataProxy* proxy) = 0;

signals:
    virtual void sigReplySomeWork(ParamCommand cmd, IDataProxy* proxy) = 0;
};

Q_DECLARE_INTERFACE(IDataProvider, "IDataProvider")

#endif // IDATAPROVIDER_H
