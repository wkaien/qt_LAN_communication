#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H

#include <QMainWindow>
#include <vector>
#include "MsgBuilder.h"
#include "QListWidget"
#include <map>
#include "ChatDialog.h"

using namespace std;

namespace Ui {
class FriendWindow;
}

class FriendWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FriendWindow(vector<UserData> users,QWidget *parent = 0);
    ~FriendWindow();
private slots:
    void on_listWidget_friend_itemDoubleClicked(QListWidgetItem *item);//双击好友
    void onReadyRead();
    void onChatDialogClose(UserData userData);

private:
    void initFriendList(vector<UserData> users);//初始化好友列表
    void addWaitMsgToUserItem(UserData from, QString msg);

    void deelUserOnline(QString jsonStr);//好友上线
    void deelUserOffline(QString jsonStr);//好友下线
    void deelUserReceiveMsg(QString jsonStr);

private:
    Ui::FriendWindow *ui;
    map<UserData, ChatDialog*> dialogs;//用户管理已经打开过的聊天窗口，每个好友对应一个聊天窗口
};

#endif // FRIENDWINDOW_H
