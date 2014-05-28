#include "amqp_frame.h"
#include <QByteArray>
#include <QHash>
#include <QSharedPointer>

namespace QAMQP
{

struct Message
{
    Message();
    virtual ~Message();

    typedef QAMQP::Frame::Content::Property MessageProperty;
    Q_DECLARE_FLAGS(MessageProperties, MessageProperty)

    qlonglong deliveryTag;
    QByteArray payload;
    QHash<MessageProperty, QVariant> property;
    QAMQP::Frame::TableField headers;
    QString routeKey;
    QString exchangeName;
    int leftSize;
};

typedef QSharedPointer<QAMQP::Message> MessagePtr;

}
