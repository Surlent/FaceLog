/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created: Wed Dec 11 22:45:22 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonRestore;
    QGroupBox *groupBox;
    QLabel *label;
    QSpinBox *spinBoxMinSize;
    QLabel *label_2;
    QSpinBox *spinBoxMaxSize;
    QLabel *label_3;
    QSpinBox *spinBoxInterval;
    QSpinBox *spinBoxCamera;
    QLabel *label_4;

    void setupUi(QDialog *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(288, 247);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/on.png"), QSize(), QIcon::Normal, QIcon::Off);
        Config->setWindowIcon(icon);
        horizontalLayoutWidget = new QWidget(Config);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 140, 269, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonSave = new QPushButton(horizontalLayoutWidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout_3->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(horizontalLayoutWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout_3->addWidget(pushButtonCancel);

        pushButtonRestore = new QPushButton(horizontalLayoutWidget);
        pushButtonRestore->setObjectName(QString::fromUtf8("pushButtonRestore"));
        pushButtonRestore->setEnabled(true);
        pushButtonRestore->setFlat(false);

        horizontalLayout_3->addWidget(pushButtonRestore);

        groupBox = new QGroupBox(Config);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 271, 141));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        spinBoxMinSize = new QSpinBox(groupBox);
        spinBoxMinSize->setObjectName(QString::fromUtf8("spinBoxMinSize"));
        spinBoxMinSize->setGeometry(QRect(10, 30, 61, 22));
        spinBoxMinSize->setMaximum(9999);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 71, 16));
        spinBoxMaxSize = new QSpinBox(groupBox);
        spinBoxMaxSize->setObjectName(QString::fromUtf8("spinBoxMaxSize"));
        spinBoxMaxSize->setGeometry(QRect(90, 30, 71, 22));
        spinBoxMaxSize->setMaximum(9999);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 131, 20));
        spinBoxInterval = new QSpinBox(groupBox);
        spinBoxInterval->setObjectName(QString::fromUtf8("spinBoxInterval"));
        spinBoxInterval->setGeometry(QRect(10, 90, 91, 22));
        spinBoxInterval->setMaximum(10000);
        spinBoxInterval->setSingleStep(100);
        spinBoxCamera = new QSpinBox(groupBox);
        spinBoxCamera->setObjectName(QString::fromUtf8("spinBoxCamera"));
        spinBoxCamera->setGeometry(QRect(180, 30, 41, 22));
        spinBoxCamera->setMinimum(-1);
        spinBoxCamera->setMaximum(10);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 10, 71, 16));

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QDialog *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Preferences", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("Config", "Save", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("Config", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButtonRestore->setText(QApplication::translate("Config", "Restore", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Config", "Minimum", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Config", "Maximum", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Config", "Detection Interval", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Config", "Camera", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
