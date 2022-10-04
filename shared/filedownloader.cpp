/*
dReam Tables Holdero Poker

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

Always play responsibly.

https://dreamtables.net
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filedownloader.h"
#include "hands/handranks.h"


QImage Hand::sharedImage0;
QImage Hand::sharedImage1;
QImage Hand::sharedImage2;
QImage Hand::sharedImage3;
QImage Hand::sharedImage4;
QImage Hand::sharedImage5;
QImage Hand::sharedImage6;
QImage Hand::sharedImage7;
QImage Hand::sharedImage8;
QImage Hand::sharedImage9;
QImage Hand::sharedImage10;
QImage Hand::sharedImage11;
QImage Hand::sharedImage12;
QImage Hand::sharedImage13;
QImage Hand::sharedImage14;
QImage Hand::sharedImage15;
QImage Hand::sharedImage16;
QImage Hand::sharedImage17;
QImage Hand::sharedImage18;
QImage Hand::sharedImage19;
QImage Hand::sharedImage20;
QImage Hand::sharedImage21;
QImage Hand::sharedImage22;
QImage Hand::sharedImage23;
QImage Hand::sharedImage24;
QImage Hand::sharedImage25;
QImage Hand::sharedImage26;
QImage Hand::sharedImage27;
QImage Hand::sharedImage28;
QImage Hand::sharedImage29;
QImage Hand::sharedImage30;
QImage Hand::sharedImage31;
QImage Hand::sharedImage32;
QImage Hand::sharedImage33;
QImage Hand::sharedImage34;
QImage Hand::sharedImage35;
QImage Hand::sharedImage36;
QImage Hand::sharedImage37;
QImage Hand::sharedImage38;
QImage Hand::sharedImage39;
QImage Hand::sharedImage40;
QImage Hand::sharedImage41;
QImage Hand::sharedImage42;
QImage Hand::sharedImage43;
QImage Hand::sharedImage44;
QImage Hand::sharedImage45;
QImage Hand::sharedImage46;
QImage Hand::sharedImage47;
QImage Hand::sharedImage48;
QImage Hand::sharedImage49;
QImage Hand::sharedImage50;
QImage Hand::sharedImage51;
QImage Hand::sharedImage52;


FileDownloader::FileDownloader(QUrl imageUrl, QObject *parent) :
    QObject(parent)
{
    connect(&m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
                this, SLOT (fileDownloaded(QNetworkReply*)));

    QNetworkRequest request(imageUrl);
    m_WebCtrl.get(request);
}


FileDownloader::~FileDownloader() { }


void FileDownloader::fileDownloaded(QNetworkReply* pReply) {
    m_DownloadedData = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}


QByteArray FileDownloader::downloadedData() const {
    return m_DownloadedData;
}


QUrl MainWindow::loadSharedCard(int card)
{
    QByteArray backData = rpc::sharedBack.toUtf8();
    QByteArray faceData = rpc::sharedFace.toUtf8();
    QByteArray backText = QByteArray::fromHex(backData);
    QByteArray faceText = QByteArray::fromHex(faceData);
    QString back = QString::fromLatin1(backText.data());
    QString face = QString::fromLatin1(faceText.data());
    QString suffix;


    if(card > 0){
        switch (card){
        case 1: suffix = "card1.png"; break;
        case 2: suffix = "card2.png"; break;
        case 3: suffix = "card3.png"; break;
        case 4: suffix = "card4.png"; break;
        case 5: suffix = "card5.png"; break;
        case 6: suffix = "card6.png"; break;
        case 7: suffix = "card7.png"; break;
        case 8: suffix = "card8.png"; break;
        case 9: suffix = "card9.png"; break;
        case 10: suffix = "card10.png"; break;
        case 11: suffix = "card11.png"; break;
        case 12: suffix = "card12.png"; break;
        case 13: suffix = "card13.png"; break;
        case 14: suffix = "card14.png"; break;
        case 15: suffix = "card15.png"; break;
        case 16: suffix = "card16.png"; break;
        case 17: suffix = "card17.png"; break;
        case 18: suffix = "card18.png"; break;
        case 19: suffix = "card19.png"; break;
        case 20: suffix = "card20.png"; break;
        case 21: suffix = "card21.png"; break;
        case 22: suffix = "card22.png"; break;
        case 23: suffix = "card23.png"; break;
        case 24: suffix = "card24.png"; break;
        case 25: suffix = "card25.png"; break;
        case 26: suffix = "card26.png"; break;
        case 27: suffix = "card27.png"; break;
        case 28: suffix = "card28.png"; break;
        case 29: suffix = "card29.png"; break;
        case 30: suffix = "card30.png"; break;
        case 31: suffix = "card31.png"; break;
        case 32: suffix = "card32.png"; break;
        case 33: suffix = "card33.png"; break;
        case 34: suffix = "card34.png"; break;
        case 35: suffix = "card35.png"; break;
        case 36: suffix = "card36.png"; break;
        case 37: suffix = "card37.png"; break;
        case 38: suffix = "card38.png"; break;
        case 39: suffix = "card39.png"; break;
        case 40: suffix = "card40.png"; break;
        case 41: suffix = "card41.png"; break;
        case 42: suffix = "card42.png"; break;
        case 43: suffix = "card43.png"; break;
        case 44: suffix = "card44.png"; break;
        case 45: suffix = "card45.png"; break;
        case 46: suffix = "card46.png"; break;
        case 47: suffix = "card47.png"; break;
        case 48: suffix = "card48.png"; break;
        case 49: suffix = "card49.png"; break;
        case 50: suffix = "card50.png"; break;
        case 51: suffix = "card51.png"; break;
        case 52: suffix = "card52.png"; break;
        }

        QUrl imageUrl(face+suffix);

        return imageUrl;
    }else {
        QUrl imageUrl(back);

        return imageUrl;
    }

}


void MainWindow::loadFullDeck()
{
    loadShared0(loadSharedCard(0));
    loadDelay(90);
    loadShared1(loadSharedCard(1));
    loadDelay(90);
    loadShared2(loadSharedCard(2));
    loadDelay(90);
    loadShared3(loadSharedCard(3));
    loadDelay(90);
    loadShared4(loadSharedCard(4));
    loadDelay(90);
    loadShared5(loadSharedCard(5));
    loadDelay(90);
    loadShared6(loadSharedCard(6));
    loadDelay(90);
    loadShared7(loadSharedCard(7));
    loadDelay(90);
    loadShared8(loadSharedCard(8));
    loadDelay(90);
    loadShared9(loadSharedCard(9));
    loadDelay(90);
    loadShared10(loadSharedCard(10));
    loadDelay(90);
    loadShared11(loadSharedCard(11));
    loadDelay(90);
    loadShared12(loadSharedCard(12));
    loadDelay(90);
    loadShared13(loadSharedCard(13));
    loadDelay(90);
    loadShared14(loadSharedCard(14));
    loadDelay(90);
    loadShared15(loadSharedCard(15));
    loadDelay(90);
    loadShared16(loadSharedCard(16));
    loadDelay(90);
    loadShared17(loadSharedCard(17));
    loadDelay(90);
    loadShared18(loadSharedCard(18));
    loadDelay(90);
    loadShared19(loadSharedCard(19));
    loadDelay(90);
    loadShared20(loadSharedCard(20));
    loadDelay(90);
    loadShared21(loadSharedCard(21));
    loadDelay(90);
    loadShared22(loadSharedCard(22));
    loadDelay(90);
    loadShared23(loadSharedCard(23));
    loadDelay(90);
    loadShared24(loadSharedCard(24));
    loadDelay(90);
    loadShared25(loadSharedCard(25));
    loadDelay(90);
    loadShared26(loadSharedCard(26));
    loadDelay(90);
    loadShared27(loadSharedCard(27));
    loadDelay(90);
    loadShared28(loadSharedCard(28));
    loadDelay(90);
    loadShared29(loadSharedCard(29));
    loadDelay(90);
    loadShared30(loadSharedCard(30));
    loadDelay(90);
    loadShared31(loadSharedCard(31));
    loadDelay(90);
    loadShared32(loadSharedCard(32));
    loadDelay(90);
    loadShared33(loadSharedCard(33));
    loadDelay(90);
    loadShared34(loadSharedCard(34));
    loadDelay(90);
    loadShared35(loadSharedCard(35));
    loadDelay(90);
    loadShared36(loadSharedCard(36));
    loadDelay(90);
    loadShared37(loadSharedCard(37));
    loadDelay(90);
    loadShared38(loadSharedCard(38));
    loadDelay(90);
    loadShared39(loadSharedCard(39));
    loadDelay(90);
    loadShared40(loadSharedCard(40));
    loadDelay(90);
    loadShared41(loadSharedCard(41));
    loadDelay(90);
    loadShared42(loadSharedCard(42));
    loadDelay(90);
    loadShared43(loadSharedCard(43));
    loadDelay(90);
    loadShared44(loadSharedCard(44));
    loadDelay(90);
    loadShared45(loadSharedCard(45));
    loadDelay(90);
    loadShared46(loadSharedCard(46));
    loadDelay(90);
    loadShared47(loadSharedCard(47));
    loadDelay(90);
    loadShared48(loadSharedCard(48));
    loadDelay(90);
    loadShared49(loadSharedCard(49));
    loadDelay(90);
    loadShared50(loadSharedCard(50));
    loadDelay(90);
    loadShared51(loadSharedCard(51));
    loadDelay(90);
    loadShared52(loadSharedCard(52));
    loadDelay(90);
}


void MainWindow::loadShared0(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 0 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s0_ImgCtrl = new FileDownloader(url, this);
    connect(s0_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage0()));
}


void MainWindow::loadShared1(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 1 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s1_ImgCtrl = new FileDownloader(url, this);
    connect(s1_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage1()));
}


void MainWindow::loadShared2(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 2 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s2_ImgCtrl = new FileDownloader(url, this);
    connect(s2_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage2()));
}


void MainWindow::loadShared3(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 3 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s3_ImgCtrl = new FileDownloader(url, this);
    connect(s3_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage3()));
}


void MainWindow::loadShared4(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 4 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s4_ImgCtrl = new FileDownloader(url, this);
    connect(s4_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage4()));
}


void MainWindow::loadShared5(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 5 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s5_ImgCtrl = new FileDownloader(url, this);
    connect(s5_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage5()));
}


void MainWindow::loadShared6(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 6 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s6_ImgCtrl = new FileDownloader(url, this);
    connect(s6_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage6()));
}


void MainWindow::loadShared7(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 7 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s7_ImgCtrl = new FileDownloader(url, this);
    connect(s7_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage7()));
}


void MainWindow::loadShared8(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 8 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s8_ImgCtrl = new FileDownloader(url, this);
    connect(s8_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage8()));
}


void MainWindow::loadShared9(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 9 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s9_ImgCtrl = new FileDownloader(url, this);
    connect(s9_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage9()));
}


void MainWindow::loadShared10(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 10 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s10_ImgCtrl = new FileDownloader(url, this);
    connect(s10_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage10()));
}


void MainWindow::loadShared11(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 11 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s11_ImgCtrl = new FileDownloader(url, this);
    connect(s11_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage11()));
}


void MainWindow::loadShared12(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 12 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s12_ImgCtrl = new FileDownloader(url, this);
    connect(s12_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage12()));
}


void MainWindow::loadShared13(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 13 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s13_ImgCtrl = new FileDownloader(url, this);
    connect(s13_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage13()));
}


void MainWindow::loadShared14(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 14 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s14_ImgCtrl = new FileDownloader(url, this);
    connect(s14_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage14()));
}


void MainWindow::loadShared15(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 15 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s15_ImgCtrl = new FileDownloader(url, this);
    connect(s15_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage15()));
}


void MainWindow::loadShared16(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 16 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s16_ImgCtrl = new FileDownloader(url, this);
    connect(s16_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage16()));
}


void MainWindow::loadShared17(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 17 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s17_ImgCtrl = new FileDownloader(url, this);
    connect(s17_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage17()));
}


void MainWindow::loadShared18(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 18 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s18_ImgCtrl = new FileDownloader(url, this);
    connect(s18_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage18()));
}


void MainWindow::loadShared19(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 19 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s19_ImgCtrl = new FileDownloader(url, this);
    connect(s19_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage19()));
}


void MainWindow::loadShared20(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 20 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s20_ImgCtrl = new FileDownloader(url, this);
    connect(s20_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage20()));
}


void MainWindow::loadShared21(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 21 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s21_ImgCtrl = new FileDownloader(url, this);
    connect(s21_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage21()));
}


void MainWindow::loadShared22(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 22 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s22_ImgCtrl = new FileDownloader(url, this);
    connect(s22_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage22()));
}


void MainWindow::loadShared23(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 23 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s23_ImgCtrl = new FileDownloader(url, this);
    connect(s23_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage23()));
}


void MainWindow::loadShared24(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 24 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s24_ImgCtrl = new FileDownloader(url, this);
    connect(s24_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage24()));
}


void MainWindow::loadShared25(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 25 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s25_ImgCtrl = new FileDownloader(url, this);
    connect(s25_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage25()));
}


void MainWindow::loadShared26(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 26 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s26_ImgCtrl = new FileDownloader(url, this);
    connect(s26_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage26()));
}


void MainWindow::loadShared27(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 27 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s27_ImgCtrl = new FileDownloader(url, this);
    connect(s27_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage27()));
}


void MainWindow::loadShared28(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 28 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s28_ImgCtrl = new FileDownloader(url, this);
    connect(s28_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage28()));
}


void MainWindow::loadShared29(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 29 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s29_ImgCtrl = new FileDownloader(url, this);
    connect(s29_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage29()));
}


void MainWindow::loadShared30(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 30 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s30_ImgCtrl = new FileDownloader(url, this);
    connect(s30_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage30()));
}


void MainWindow::loadShared31(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 31 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s31_ImgCtrl = new FileDownloader(url, this);
    connect(s31_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage31()));
}


void MainWindow::loadShared32(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 32 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s32_ImgCtrl = new FileDownloader(url, this);
    connect(s32_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage32()));
}


void MainWindow::loadShared33(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 33 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s33_ImgCtrl = new FileDownloader(url, this);
    connect(s33_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage33()));
}


void MainWindow::loadShared34(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 34 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s34_ImgCtrl = new FileDownloader(url, this);
    connect(s34_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage34()));
}


void MainWindow::loadShared35(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 35 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s35_ImgCtrl = new FileDownloader(url, this);
    connect(s35_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage35()));
}


void MainWindow::loadShared36(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 36 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s36_ImgCtrl = new FileDownloader(url, this);
    connect(s36_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage36()));
}


void MainWindow::loadShared37(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 37 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s37_ImgCtrl = new FileDownloader(url, this);
    connect(s37_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage37()));
}


void MainWindow::loadShared38(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 38 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s38_ImgCtrl = new FileDownloader(url, this);
    connect(s38_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage38()));
}


void MainWindow::loadShared39(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 39 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s39_ImgCtrl = new FileDownloader(url, this);
    connect(s39_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage39()));
}


void MainWindow::loadShared40(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 40 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s40_ImgCtrl = new FileDownloader(url, this);
    connect(s40_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage40()));
}


void MainWindow::loadShared41(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 41 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s41_ImgCtrl = new FileDownloader(url, this);
    connect(s41_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage41()));
}


void MainWindow::loadShared42(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 42 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s42_ImgCtrl = new FileDownloader(url, this);
    connect(s42_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage42()));
}


void MainWindow::loadShared43(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 43 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s43_ImgCtrl = new FileDownloader(url, this);
    connect(s43_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage43()));
}


void MainWindow::loadShared44(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 44 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s44_ImgCtrl = new FileDownloader(url, this);
    connect(s44_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage44()));
}


void MainWindow::loadShared45(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 45 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s45_ImgCtrl = new FileDownloader(url, this);
    connect(s45_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage45()));
}


void MainWindow::loadShared46(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 46 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s46_ImgCtrl = new FileDownloader(url, this);
    connect(s46_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage46()));
}


void MainWindow::loadShared47(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 47 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s47_ImgCtrl = new FileDownloader(url, this);
    connect(s47_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage47()));
}


void MainWindow::loadShared48(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 48 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s48_ImgCtrl = new FileDownloader(url, this);
    connect(s48_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage48()));
}


void MainWindow::loadShared49(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 49 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s49_ImgCtrl = new FileDownloader(url, this);
    connect(s49_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage49()));
}


void MainWindow::loadShared50(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 50 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s50_ImgCtrl = new FileDownloader(url, this);
    connect(s50_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage50()));
}


void MainWindow::loadShared51(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 51 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s51_ImgCtrl = new FileDownloader(url, this);
    connect(s51_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage51()));
}


void MainWindow::loadShared52(QUrl url)
{
    QString u = url.toString();
    ui->textBrowser->setTextBackgroundColor(gray_textBG);
    ui->textBrowser->append("Loading Card 52 from Url: "+u);
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    s52_ImgCtrl = new FileDownloader(url, this);
    connect(s52_ImgCtrl, SIGNAL (downloaded()), this, SLOT (loadSharedImage52()));
}


void MainWindow::loadSharedImage0()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 0");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage0.loadFromData(s0_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage1()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 1");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage1.loadFromData(s1_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage2()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 2");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage2.loadFromData(s2_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage3()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 3");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage3.loadFromData(s3_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage4()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 4");
   ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage4.loadFromData(s4_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage5()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 5");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage5.loadFromData(s5_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage6()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 6");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage6.loadFromData(s6_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage7()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 7");
   ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage7.loadFromData(s7_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage8()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 8");
   ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage8.loadFromData(s8_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage9()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 9");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage9.loadFromData(s9_ImgCtrl->downloadedData());
}

void MainWindow::loadSharedImage10()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 10");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage10.loadFromData(s10_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage11()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 11");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage11.loadFromData(s11_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage12()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 12");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage12.loadFromData(s12_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage13()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 13");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage13.loadFromData(s13_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage14()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 14");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage14.loadFromData(s14_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage15()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 15");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage15.loadFromData(s15_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage16()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 16");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage16.loadFromData(s16_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage17()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 17");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage17.loadFromData(s17_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage18()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 18");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage18.loadFromData(s18_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage19()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 19");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage19.loadFromData(s19_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage20()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 20");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage20.loadFromData(s20_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage21()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 21");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage21.loadFromData(s21_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage22()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 22");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage22.loadFromData(s22_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage23()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 23");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage23.loadFromData(s23_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage24()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 24");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage24.loadFromData(s24_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage25()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 25");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage25.loadFromData(s25_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage26()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 26");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage26.loadFromData(s26_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage27()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 27");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage27.loadFromData(s27_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage28()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 28");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage28.loadFromData(s28_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage29()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 29");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage29.loadFromData(s29_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage30()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 30");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage30.loadFromData(s30_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage31()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 31");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage31.loadFromData(s31_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage32()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 32");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage32.loadFromData(s32_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage33()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 33");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage33.loadFromData(s33_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage34()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 34");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage34.loadFromData(s34_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage35()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 35");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage35.loadFromData(s35_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage36()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 36");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage36.loadFromData(s36_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage37()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 37");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage37.loadFromData(s37_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage38()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 38");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage38.loadFromData(s38_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage39()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 39");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage39.loadFromData(s39_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage40()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 40");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage40.loadFromData(s40_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage41()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 41");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage41.loadFromData(s41_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage42()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 42");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage42.loadFromData(s42_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage43()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 43");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage43.loadFromData(s43_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage44()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 44");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage44.loadFromData(s44_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage45()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 45");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage45.loadFromData(s45_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage46()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 46");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage46.loadFromData(s46_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage47()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 47");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage47.loadFromData(s47_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage48()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 48");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage48.loadFromData(s48_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage49()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 49");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage49.loadFromData(s49_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage50()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 50");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage50.loadFromData(s50_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage51()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 51");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage51.loadFromData(s51_ImgCtrl->downloadedData());
}


void MainWindow::loadSharedImage52()
{
    ui->textBrowser->setTextBackgroundColor(green_textBG);
    ui->textBrowser->append("Loaded Card 52");
    ui->textBrowser->setTextBackgroundColor(normal_textBG);
    Hand::sharedImage52.loadFromData(s52_ImgCtrl->downloadedData());
}


void MainWindow::clearSharedImages()
{
    Hand::sharedImage0.load("");
    Hand::sharedImage1.load("");
    Hand::sharedImage2.load("");
    Hand::sharedImage3.load("");
    Hand::sharedImage4.load("");
    Hand::sharedImage5.load("");
    Hand::sharedImage6.load("");
    Hand::sharedImage7.load("");
    Hand::sharedImage8.load("");
    Hand::sharedImage9.load("");
    Hand::sharedImage10.load("");
    Hand::sharedImage11.load("");
    Hand::sharedImage12.load("");
    Hand::sharedImage13.load("");
    Hand::sharedImage14.load("");
    Hand::sharedImage15.load("");
    Hand::sharedImage16.load("");
    Hand::sharedImage17.load("");
    Hand::sharedImage18.load("");
    Hand::sharedImage19.load("");
    Hand::sharedImage20.load("");
    Hand::sharedImage21.load("");
    Hand::sharedImage22.load("");
    Hand::sharedImage23.load("");
    Hand::sharedImage24.load("");
    Hand::sharedImage25.load("");
    Hand::sharedImage26.load("");
    Hand::sharedImage27.load("");
    Hand::sharedImage28.load("");
    Hand::sharedImage29.load("");
    Hand::sharedImage30.load("");
    Hand::sharedImage31.load("");
    Hand::sharedImage32.load("");
    Hand::sharedImage33.load("");
    Hand::sharedImage34.load("");
    Hand::sharedImage35.load("");
    Hand::sharedImage36.load("");
    Hand::sharedImage37.load("");
    Hand::sharedImage38.load("");
    Hand::sharedImage39.load("");
    Hand::sharedImage40.load("");
    Hand::sharedImage41.load("");
    Hand::sharedImage42.load("");
    Hand::sharedImage43.load("");
    Hand::sharedImage44.load("");
    Hand::sharedImage45.load("");
    Hand::sharedImage46.load("");
    Hand::sharedImage47.load("");
    Hand::sharedImage48.load("");
    Hand::sharedImage49.load("");
    Hand::sharedImage50.load("");
    Hand::sharedImage51.load("");
    Hand::sharedImage52.load("");
}
