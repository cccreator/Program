#ifndef TOOLBOX1_H
#define TOOLBOX1_H

#include <QToolBox>
#include <QToolButton>
#include <QEvent>
#include <QTcpSocket>
#include "widget.h"

#define CLINETCOUNT 256  //最大客户端数量
#define MSGBODYBUF 1024

//定义消息结构
struct msg_t{
    unsigned char head[4];
    char body[MSGBODYBUF];
};

class toolbox1 : public QToolBox
{
    Q_OBJECT
public:
    explicit toolbox1(QWidget *parent = 0);


signals:

public slots:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    int userid;
    QString passwd;
    QString hostip;
    int hostport;

    QString username[CLINETCOUNT];
    QToolButton *toolBtn[CLINETCOUNT];//创建256个toolbutton
    Widget *child[CLINETCOUNT];//创建256个widget
    void init_toolBtn();
    void init_username();
    QTcpSocket *sockClient;
    void login_Msg();

private slots:
    void sock_Error(QAbstractSocket::SocketError sockErr);//socket出错的时候触发的槽函数
    void read_Msg();//socket接收到消息触发的槽函数
    void socket_connected();//socket成功连接到服务端后触发的槽函数

};

#endif // TOOLBOX1_H
