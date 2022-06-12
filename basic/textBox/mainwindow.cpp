#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    resize(600, 300);
    auto central = new QWidget;
    QHBoxLayout *h_layout = new QHBoxLayout;

    QLineEdit *box1 = new QLineEdit("0");
    box1->setFixedHeight(30);
    box1->setFixedWidth(50);

    QLineEdit *box2 = new QLineEdit("80");
    box2->setFixedHeight(30);
    box2->setFixedWidth(50);

    QLineEdit *box3 = new QLineEdit("140");
    box3->setFixedHeight(30);
    box3->setFixedWidth(50);

    h_layout->setContentsMargins(0, 0, 0, 0);
    h_layout->setSpacing(10);
    h_layout->addWidget(box1); // start from 0
    h_layout->addSpacing(20);
    h_layout->addWidget(box2); // start from 80  (50 + 10 + 20)
    h_layout->addWidget(box3); // start from 140 (80 + 50 + 10)
    h_layout->addStretch(1);   // left part (410 (600-140-50)) splits to one part (defualt: leftmost and rightmost two part)
    central->setLayout(h_layout);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
    delete ui;
}

