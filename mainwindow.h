#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
dReam Tables NFAVerify

Copyright (C) 2022  dReam Tables

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

https://dreamtables.net
*/

#include "iostream"
#include "QMainWindow"
#include "QFile"
#include "QImage"
#include "QDir"
#include "QCryptographicHash"
#include "QThread"
#include "QTimer"
#include "QColor"
#include "QFont"
#include "QFontDatabase"
#include "QImageReader"
#include "rpc/rpc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString os;
    QColor normal_textBG;
    QColor black_textBG;
    QColor gray_textBG;
    QColor red_textBG;
    QColor lightred_textBG;
    QColor green_textBG;
    void setFonts(QString);
    void loginInfo();
    int checkDaemon();
    int checkWallet();
    QString readmeStandard(QFile &);
    void AZYDS(QString);
    void AZYPC(QString);
    void AZYPCB(QString);
    void SIXPC(QString, rpc&);
    void SIXPCB(QString, rpc&);
    int verifyNFAcreator(QString addr);
    int verifyAsset(QString addr);

private slots:
    void on_assetsButton_clicked();

    void on_connectButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
