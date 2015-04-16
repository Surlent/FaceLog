/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Dec 11 22:45:22 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConfig;
    QAction *actionPreferences;
    QWidget *centralWidget;
    QListView *listView;
    QLabel *label;
    QLabel *cameraLabel;
    QPushButton *startButton;
    QLabel *labelDetections;
    QMenuBar *menuBar;
    QMenu *Arquivo;
    QMenu *menuFerramentas;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(672, 664);
        MainWindow->setMinimumSize(QSize(672, 664));
        MainWindow->setMaximumSize(QSize(672, 664));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Iconeop\303\247\303\243o3.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("margin:0px;\n"
"padding:0px;"));
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName(QString::fromUtf8("actionConfig"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(330, 510, 171, 91));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 510, 71, 71));
        cameraLabel = new QLabel(centralWidget);
        cameraLabel->setObjectName(QString::fromUtf8("cameraLabel"));
        cameraLabel->setGeometry(QRect(15, 6, 641, 471));
        cameraLabel->setFrameShape(QFrame::Box);
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(50, 530, 98, 27));
        labelDetections = new QLabel(centralWidget);
        labelDetections->setObjectName(QString::fromUtf8("labelDetections"));
        labelDetections->setGeometry(QRect(330, 490, 81, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 672, 23));
        Arquivo = new QMenu(menuBar);
        Arquivo->setObjectName(QString::fromUtf8("Arquivo"));
        menuFerramentas = new QMenu(menuBar);
        menuFerramentas->setObjectName(QString::fromUtf8("menuFerramentas"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(Arquivo->menuAction());
        menuBar->addAction(menuFerramentas->menuAction());
        menuFerramentas->addAction(actionPreferences);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FaceLog", 0, QApplication::UnicodeUTF8));
        actionConfig->setText(QApplication::translate("MainWindow", "Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences...", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        cameraLabel->setText(QString());
        startButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        labelDetections->setText(QApplication::translate("MainWindow", "Detections", 0, QApplication::UnicodeUTF8));
        Arquivo->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuFerramentas->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
