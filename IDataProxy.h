#ifndef IDATAPROXY_H
#define IDATAPROXY_H

#include <QObject>

#include "CommandList.h"

class IDataProxy
{
public:
    virtual ~IDataProxy() = default;

signals:
    virtual void sigAskForSomeWork(ParamCommand cmd, IDataProxy* proxy) = 0;
    virtual void sigReplySomeWork(ParamCommand cmd, IDataProxy* proxy) = 0;

};

Q_DECLARE_INTERFACE(IDataProxy, "IDataProxy")

#endif // IDATAPROXY_H
