#ifndef USERITEM_H
#define USERITEM_H

#include <QWidget>
#include "MsgBuilder.h"

namespace Ui {
class UserItem;
}

class UserItem : public QWidget
{
    Q_OBJECT

public:
    explicit UserItem(UserData userData,QWidget* parent = 0);
    ~UserItem();
    inline UserData getUserData()
    {
        return userData;
    }
    void addWaitMsg(QString msg);
    QStringList getWaitMsg(){return waitMsg;}
    void clearWaitMsg();

private:
    Ui::UserItem *ui;
    UserData userData;
    QStringList waitMsg;
};

#endif // USERITEM_H
