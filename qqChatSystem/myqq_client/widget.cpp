#include "widget.h"
#include "toolbox1.h"
#include <QHBoxLayout>

Widget::Widget(const QIcon icon, int ID, QString name, toolbox1 *w, QWidget *parent)
    : QWidget(parent)
{
    userID = ID;
    username = name;
    main_w = w;
    setWindowTitle(name);
    setWindowIcon(icon);
    //设置最大化最小化按钮无效
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint & ~Qt::WindowMinimizeButtonHint);

    //设置背景颜色
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(Qt::darkCyan));
    setPalette(palette);
    init_widget();//初始化相关的控件
}

Widget::~Widget()
{

}

void Widget::init_widget()
{
    textBrowser = new QTextBrowser;
    //设置textBrowser背景颜色或图片
    textBrowser->setStyleSheet("background-image: url(:/images/2.jpg);");//背景设置为2.jpg
    //textBrowser->setStyleSheet("border-image: url(:/images/2.jpg);");//背景设置为2.jpg

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(textBrowser);

    fontComboBox = new QFontComboBox;
    fontComboBox->setToolTip(tr("字体"));

    comboBox = new QComboBox;
    comboBox->setToolTip(tr("字号"));
    comboBox->setEditable(true);
    comboBox->addItem(QString::number(8));
    comboBox->addItem(QString::number(9));
    comboBox->addItem(QString::number(10));
    comboBox->addItem(QString::number(11));
    comboBox->addItem(QString::number(12));
    comboBox->addItem(QString::number(13));
    comboBox->addItem(QString::number(14));
    comboBox->addItem(QString::number(15));
    comboBox->addItem(QString::number(16));
    comboBox->addItem(QString::number(17));
    comboBox->addItem(QString::number(18));
    comboBox->addItem(QString::number(19));
    comboBox->addItem(QString::number(20));
    comboBox->addItem(QString::number(21));
    comboBox->addItem(QString::number(22));
    comboBox->setCurrentIndex(4);//设置当前索引号

    toolButton_1 = new QToolButton;
    toolButton_1->setToolTip(tr("加粗"));
    toolButton_1->setText(tr("加粗"));
    toolButton_1->setCheckable(true);
    toolButton_1->setAutoRaise(true);
    toolButton_1->setIcon(QPixmap(":/images/bold.png"));

    toolButton_2 = new QToolButton;
    toolButton_2->setToolTip(tr("倾斜"));
    toolButton_2->setText(tr("倾斜"));
    toolButton_2->setCheckable(true);
    toolButton_2->setAutoRaise(true);
    toolButton_2->setIcon(QPixmap(":/images/italic.png"));

    toolButton_3 = new QToolButton;
    toolButton_3->setToolTip(tr("下划线"));
    toolButton_3->setText(tr("下划线"));
    toolButton_3->setCheckable(true);
    toolButton_3->setAutoRaise(true);
    toolButton_3->setIcon(QPixmap(":/images/under.png"));

    toolButton_4 = new QToolButton;
    toolButton_4->setToolTip(tr("颜色"));
    toolButton_4->setText(tr("颜色"));
    toolButton_4->setAutoRaise(true);
    toolButton_4->setIcon(QPixmap(":/images/color.png"));

    toolButton = new QToolButton;
    toolButton->setText(tr("显示主窗口"));
    toolButton->setAutoRaise(true);

    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(fontComboBox);
    layout2->addWidget(comboBox);
    layout2->addWidget(toolButton_1);
    layout2->addWidget(toolButton_2);
    layout2->addWidget(toolButton_3);
    layout2->addWidget(toolButton_4);
    layout2->addWidget(toolButton);

    lineEdit = new QLineEdit;

    pushButton = new QPushButton;
    pushButton->setText(tr("发送"));

    QHBoxLayout *layout3 = new QHBoxLayout;
    layout3->addWidget(lineEdit);
    layout3->addWidget(pushButton);

    QVBoxLayout *mainlayout = new QVBoxLayout;

    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);
    mainlayout->addLayout(layout3);
    //mainlayout->setSizeConstraint(QLayout::SetFixedSize);//设置窗口大小不能改变
    setLayout(mainlayout);

    textBrowser->setCurrentFont(fontComboBox->font());//设置textBrowser的默认字体
    textBrowser->setFontPointSize(comboBox->currentText().toDouble());//设置textBrowser的默认字号
    lineEdit->setFocus();


}
