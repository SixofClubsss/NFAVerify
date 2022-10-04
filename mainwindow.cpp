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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    os = QSysInfo::productType();
    ui->textBrowser->setText("os: "+os);
    setFonts(os);
    normal_textBG = QColor(1, 0, 0, 0);
    black_textBG = QColor(0, 0, 0);
    gray_textBG = QColor(18, 18, 18, 120);
    red_textBG = Qt::darkRed;
    lightred_textBG = Qt::red;
    green_textBG = Qt::darkGreen;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setFonts(QString os)
{
    int ubR;

    if(os == "macos" || os == "osx" || os == "darwin"){
        ubR = 13;
    }else {
        ubR = 10;
    }

    int fontID = QFontDatabase::addApplicationFont(":/fonts/Ubuntu-R.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontID).at(0);
    QFont ubuntuRegular(fontFamily);
    ubuntuRegular.setPointSize(ubR);
    ui->rpcGroupBox->setFont(ubuntuRegular);
    ui->clearButton->setFont(ubuntuRegular);
    ui->assetsButton->setFont(ubuntuRegular);
    ui->textBrowser->setFont(ubuntuRegular);
    ui->userpassInput->setFont(ubuntuRegular);
    ui->daemonRPCinput->setFont(ubuntuRegular);
    ui->walletRPCinput->setFont(ubuntuRegular);
    ui->daemonConnectedBox->setFont(ubuntuRegular);
    ui->walletConnectedBox->setFont(ubuntuRegular);
    ui->connectButton->setFont(ubuntuRegular);
    ui->sharedButton->setFont(ubuntuRegular);
    ui->viewButton->setFont(ubuntuRegular);
}


void MainWindow::loginInfo()   /// Used to get wallet login info for wallet functions
{
    QString userInfo = ui->userpassInput->text();
    string userpassStr = userInfo.toStdString();
    rpc::rpcLogin = userpassStr;
}


void MainWindow::loadDelay(int ms)
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MainWindow::on_clearButton_clicked()
{
    ui->textBrowser->setText("");
    clearSharedImages();
}


void MainWindow::on_assetsButton_clicked()
{
    QString pre = QDir().absolutePath();
    ui->textBrowser->setTextBackgroundColor(black_textBG);
    ui->textBrowser->append("Looking for NFA Themes in: "+pre);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    AZYDS(pre);
    ui->textBrowser->setTextBackgroundColor(black_textBG);
    ui->textBrowser->append("\n==============================================================================================================================");
    ui->textBrowser->append("Looking for NFA Card Decks in: "+pre);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    AZYPC(pre);
    ui->textBrowser->setTextBackgroundColor(black_textBG);
    ui->textBrowser->append("\n==============================================================================================================================");
    ui->textBrowser->append("Looking for NFA Card Backs in: "+pre);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    AZYPCB(pre);
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.setPosition(0);
    ui->textBrowser->setTextCursor(cursor);
}


void MainWindow::on_connectButton_clicked()
{
    loginInfo();
    rpc::daemonAddress = ui->daemonRPCinput->text()+"/json_rpc";
    rpc::playerAddress = ui->walletRPCinput->text()+"/json_rpc";
    checkDaemon();
    checkWallet();
    fetchScData();
}


void MainWindow::on_sharedButton_clicked()
{
    loadFullDeck();
}

void MainWindow::on_viewButton_clicked()
{
    ViewDeck vd;
    vd.setModal(true);
    vd.exec();
}
