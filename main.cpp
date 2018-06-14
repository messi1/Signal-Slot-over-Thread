#include <QCoreApplication>
#include <QDebug>
#include <QThread>

#include "DataProvider.h"
#include "DataProxy.h"

#include "CommandList.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread* dataThread = new QThread;
    dataThread->setObjectName("dataThread");
    DataProvider* dataProvider = new DataProvider(nullptr);
    DataProxy* dataProxy1       = new DataProxy(dataProvider, nullptr);
    DataProxy* dataProxy2       = new DataProxy(dataProvider, nullptr);

    qWarning() << "Current Thread: " << QThread::currentThreadId();
    qWarning() << "Current WorkerThread: " << dataProvider->thread();

    dataProvider->moveToThread(dataThread);
    qWarning() << "New WorkerThread: " << dataProvider->thread();

    dataThread->start();
    dataProxy1->askForSomeWork(ParamCommand::BLA);
    dataProxy2->askForSomeWork(ParamCommand::GUGUS);


    return a.exec();
}
