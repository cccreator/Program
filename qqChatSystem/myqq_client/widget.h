#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>
#include <QLineEdit>
#include <QColor>

class toolbox1;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(const QIcon icon, int ID, QString name, toolbox1 *w, QWidget *parent = 0);
    ~Widget();
    QPushButton *pushButton;

private:
    void init_widget();

    QTextBrowser *textBrowser;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton;

    QLineEdit *lineEdit;

    int userID;
    QString username;
    QColor color;
    toolbox1 *main_w;
};

#endif // WIDGET_H
