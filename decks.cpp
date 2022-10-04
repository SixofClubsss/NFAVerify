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

string rpc::rpcLogin;
bool rpc::assetConfirmed;
QString rpc::daemonAddress;
QString rpc::playerAddress;
QString rpc::sharedFace;
QString rpc::sharedBack;


QString MainWindow::readmeStandard(QFile &file)
{
    QString scid;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString s = "SCID:";
        QString line = in.readLine();
        QString check = line;
        check.chop(65);
        if(check == s){
            scid = line;
            scid.remove(0, 6);
            return scid;
        }
    }
    return scid;
}


void MainWindow::AZYDS(QString pre)
{
    QString start;
    QString add;
    int i = 1;

    do {
        start = "000";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYDS"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaScape(pre+"/cards/AZYDS"+add+"/README.md");
        nfaScape.open(QIODevice::ReadOnly);

        if(nfaScape.exists()){
            QString findAddr = readmeStandard(nfaScape);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYDS"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaScape.close();
            }else {
                rpc::assetConfirmed = false;
                nfaScape.close();
            }

        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 10);

    do {
        start = "00";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYDS"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaScape(pre+"/cards/AZYDS"+add+"/README.md");
        nfaScape.open(QIODevice::ReadOnly);

        if(nfaScape.exists()){
            QString findAddr = readmeStandard(nfaScape);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYDS"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaScape.close();
            }else {
                rpc::assetConfirmed = false;
                nfaScape.close();
            }

        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 100);

    do {
        start = "0";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYDS"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaScape(pre+"/cards/AZYDS"+add+"/README.md");
        nfaScape.open(QIODevice::ReadOnly);

        if(nfaScape.exists()){
            QString findAddr = readmeStandard(nfaScape);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYDS"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaScape.close();
            }else {
                rpc::assetConfirmed = false;
                nfaScape.close();
            }

        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 1000);

    add = start+QString::number(i);
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Looking for : "+pre+"/cards/AZYDS"+add+"/README.md");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    QFile nfaScape(pre+"/cards/AZYDS"+add+"/README.md");
    nfaScape.open(QIODevice::ReadOnly);

    if(nfaScape.exists()){
        QString findAddr = readmeStandard(nfaScape);
        verifyNFAcreator(findAddr);
        if(rpc::assetConfirmed == true){
            ui->textBrowser->setTextBackgroundColor(green_textBG);
            ui->textBrowser->append("Populating: "+pre+"/cards/AZYDS"+add+"/README.md");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
            rpc::assetConfirmed = false;
            nfaScape.close();
        }else {
            rpc::assetConfirmed = false;
            nfaScape.close();
        }

    }else {
        ui->textBrowser->setTextBackgroundColor(red_textBG);
        ui->textBrowser->append("Not Found");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
    }

}


void MainWindow::AZYPC(QString pre)
{
    QString start;
    QString add;
    int i = 1;

    do {
        start = "000";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPC"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaDeck(pre+"/cards/AZYPC"+add+"/README.md");
        nfaDeck.open(QIODevice::ReadOnly);

        if(nfaDeck.exists()){
            QString findAddr = readmeStandard(nfaDeck);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYPC"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaDeck.close();
            }else {
                rpc::assetConfirmed = false;
                nfaDeck.close();
            }

        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 10);

    do {
        start = "00";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPC"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaDeck(pre+"/cards/AZYPC"+add+"/README.md");
        nfaDeck.open(QIODevice::ReadOnly);

        if(nfaDeck.exists()){
            QString findAddr = readmeStandard(nfaDeck);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYPC"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaDeck.close();
            }else {
                rpc::assetConfirmed = false;
                nfaDeck.close();
            }

        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 100);

    do {
        start = "0";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPC"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaDeck(pre+"/cards/AZYPC"+add+"/README.md");
        nfaDeck.open(QIODevice::ReadOnly);

        if(nfaDeck.exists()){
            QString findAddr = readmeStandard(nfaDeck);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYPC"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaDeck.close();
            }else {
                rpc::assetConfirmed = false;
                nfaDeck.close();
            }

        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 1000);

    add = start+QString::number(i);
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPC"+add+"/README.md");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    QFile nfaDeck(pre+"/cards/AZYPC"+add+"/README.md");
    nfaDeck.open(QIODevice::ReadOnly);

    if(nfaDeck.exists()){
        QString findAddr = readmeStandard(nfaDeck);
        verifyNFAcreator(findAddr);
        if(rpc::assetConfirmed == true){
            ui->textBrowser->setTextBackgroundColor(green_textBG);
            ui->textBrowser->append("Populating: "+pre+"/cards/AZYPC"+add+"/README.md");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
            rpc::assetConfirmed = false;
            nfaDeck.close();
        }else {
            rpc::assetConfirmed = false;
            nfaDeck.close();
        }

    }else {
        ui->textBrowser->setTextBackgroundColor(red_textBG);
        ui->textBrowser->append("Not Found");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
    }

}


void MainWindow::AZYPCB(QString pre)
{
    QString start;
    QString add;
    int i = 1;

    do {
        start = "000";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPCB"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaBack(pre+"/cards/backs/AZYPCB"+add+"/README.md");
        nfaBack.open(QIODevice::ReadOnly);

        if(nfaBack.exists()){
            QString findAddr = readmeStandard(nfaBack);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYPCB"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaBack.close();
            }else {
                rpc::assetConfirmed = false;
                nfaBack.close();
            }
        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 10);

    do {
        start = "00";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPCB"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaBack(pre+"/cards/backs/AZYPCB"+add+"/README.md");
        nfaBack.open(QIODevice::ReadOnly);

        if(nfaBack.exists()){
            QString findAddr = readmeStandard(nfaBack);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYPCB"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaBack.close();
            }else {
                rpc::assetConfirmed = false;
                nfaBack.close();
            }
        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 100);

    do {
        start = "0";
        add = start+QString::number(i);
        ui->textBrowser->setTextBackgroundColor(gray_textBG);
        ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPCB"+add+"/README.md");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
        QFile nfaBack(pre+"/cards/backs/AZYPCB"+add+"/README.md");
        nfaBack.open(QIODevice::ReadOnly);

        if(nfaBack.exists()){
            QString findAddr = readmeStandard(nfaBack);
            verifyNFAcreator(findAddr);
            if(rpc::assetConfirmed == true){
                ui->textBrowser->setTextBackgroundColor(green_textBG);
                ui->textBrowser->append("Populating: "+pre+"/cards/AZYPCB"+add+"/README.md");
                ui->textBrowser->setTextBackgroundColor(normal_textBG);
                rpc::assetConfirmed = false;
                nfaBack.close();
            }else {
                rpc::assetConfirmed = false;
                nfaBack.close();
            }
        }else {
            ui->textBrowser->setTextBackgroundColor(red_textBG);
            ui->textBrowser->append("Not Found");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
        }
        ++i;
    }while(i < 1000);

    add = start+QString::number(i);
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Looking for : "+pre+"/cards/AZYPCB"+add+"/README.md");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    QFile nfaBack(pre+"/cards/AZYPCB"+add+"/README.md");
    nfaBack.open(QIODevice::ReadOnly);

    if(nfaBack.exists()){
        QString findAddr = readmeStandard(nfaBack);
        verifyNFAcreator(findAddr);
        if(rpc::assetConfirmed == true){
            ui->textBrowser->setTextBackgroundColor(green_textBG);
            ui->textBrowser->append("Populating: "+pre+"/cards/AZYPCB"+add+"/README.md");
            ui->textBrowser->setTextBackgroundColor(normal_textBG);
            rpc::assetConfirmed = false;
            nfaBack.close();
        }else {
            rpc::assetConfirmed = false;
            nfaBack.close();
        }

    }else {
        ui->textBrowser->setTextBackgroundColor(red_textBG);
        ui->textBrowser->append("Not Found");
        ui->textBrowser->setTextBackgroundColor(normal_textBG);
    }
}
