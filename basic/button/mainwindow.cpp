#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    resize(600, 300);
    auto central = new QWidget;
    QVBoxLayout *v_layout = new QVBoxLayout;

    QPushButton *btn1 = new QPushButton("click me");
    btn1->setFixedHeight(30);
    btn1->setFixedWidth(80);

    QLineEdit *box1 = new QLineEdit;
    box1->setFixedHeight(30);
    box1->setFixedWidth(200);

    // event
    connect(btn1, &QPushButton::clicked, box1, [=] { // lambda function FYI: '=': pass by value, '&': pass by reference
       box1->setText("hello world");
    });

    v_layout->setAlignment(Qt::AlignHCenter);
    v_layout->setSpacing(10);  // spacing between widgets
    v_layout->addStretch(1);   // 1/3 of remaining space
    v_layout->addWidget(box1);
    v_layout->addSpacing(20);  // vertical layout => vertical space
    v_layout->addWidget(btn1);
    v_layout->addStretch(2);   // 2/3 of remaining space
    central->setLayout(v_layout);

    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
    delete ui;
}

