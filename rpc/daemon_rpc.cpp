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


int MainWindow::checkDaemon()       /// Check connection to daemon
{
    CURL *curlDaemonCheck;   /// Set up cUrl
    CURLcode res;
    string daemonReadBuffer;
    char error[CURL_ERROR_SIZE];

    QString parts = "{\"jsonrpc\":\"2.0\",\"id\":\"0\",\"method\":\"getsc\",\"params\":{ \"scid\":\"95e69b382044ddc1467e030a80905cf637729612f65624e8d17bf778d4362b8d\" , \"ringsize\":2 , \"code\":false , \"variables\":false}}";
    string addThis = parts.toStdString();
    const char *postthis = addThis.c_str();

    string dStr = rpc::daemonAddress.toStdString();   /// Player dameon address from menu
    const char *dCh = dStr.c_str();

    curlDaemonCheck = curl_easy_init();

    if(curlDaemonCheck) {
      struct curl_slist *headers = NULL;
      /// Add request headers
      headers = curl_slist_append(headers, "Accept: application/json");
      headers = curl_slist_append(headers, "Content-Type: application/json");
      headers = curl_slist_append(headers, "charset: utf-8");
      /// cUrl options
      curl_easy_setopt(curlDaemonCheck, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curlDaemonCheck, CURLOPT_URL, dCh);
      curl_easy_setopt(curlDaemonCheck, CURLOPT_VERBOSE, 0L);
      curl_easy_setopt(curlDaemonCheck, CURLOPT_CONNECTTIMEOUT, 4L);
      curl_easy_setopt(curlDaemonCheck, CURLOPT_ERRORBUFFER, error);
      /// curl_easy_setopt(curlDaemonCheck, CURLOPT_SSL_VERIFYPEER, 0);   *Remove comment for windows SSL disable*
      curl_easy_setopt(curlDaemonCheck, CURLOPT_POSTFIELDS, postthis);
      curl_easy_setopt(curlDaemonCheck, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
      curl_easy_setopt(curlDaemonCheck, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curlDaemonCheck, CURLOPT_WRITEDATA, &daemonReadBuffer);

      res = curl_easy_perform(curlDaemonCheck);              /// Preform cUrl and clean up
      curl_easy_cleanup(curlDaemonCheck);

      QByteArray br = daemonReadBuffer.c_str();             /// Get cUrl results into QByteArray
      QJsonDocument cbDoc = QJsonDocument::fromJson(br);
      QJsonObject cbObj = cbDoc.object();
      QJsonObject cbResults = cbObj["result"].toObject();
      QJsonValue okCheck = cbResults["status"];

      if(okCheck == "OK"){
          ui->daemonConnectedBox->setChecked(true);
          ui->textBrowser->setTextBackgroundColor(green_textBG);
          ui->textBrowser->append("Daemon Connected"); /// Connected message
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
      }else {
          ui->daemonConnectedBox->setChecked(false);
          ui->textBrowser->setTextBackgroundColor(red_textBG);
          ui->textBrowser->append("Daemon Not Connected"); /// Not connected
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
      }

    }
    return 0;

}


int MainWindow::verifyNFAcreator(QString addr)       /// Verify NFA contract
{
    CURL *curlVerifyNFA;
    CURLcode res;
    string nfaReadBuffer;
    char error[CURL_ERROR_SIZE];

    ui->textBrowser->append("Checking NFA Creator on SCID: "+addr);

    QString parts = "{\"jsonrpc\":\"2.0\",\"id\":\"0\",\"method\":\"getsc\",\"params\":{\"scid\":\""+addr+"\",  \"ringsize\":2, \"code\":false , \"variables\":true}}";
    string addThis = parts.toStdString();
    const char *postthis = addThis.c_str();

    string dStr = rpc::daemonAddress.toStdString();
    const char *fdCh = dStr.c_str();

    curlVerifyNFA = curl_easy_init();

    if(curlVerifyNFA) {
      struct curl_slist *headers = NULL;
      /// Add request headers
      headers = curl_slist_append(headers, "Accept: application/json");
      headers = curl_slist_append(headers, "Content-Type: application/json");
      headers = curl_slist_append(headers, "charset: utf-8");
      /// cUrl options
      curl_easy_setopt(curlVerifyNFA, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curlVerifyNFA, CURLOPT_URL, fdCh);
      curl_easy_setopt(curlVerifyNFA, CURLOPT_VERBOSE, 0L);
      curl_easy_setopt(curlVerifyNFA, CURLOPT_CONNECTTIMEOUT, 4L);
      curl_easy_setopt(curlVerifyNFA, CURLOPT_ERRORBUFFER, error);
      /// curl_easy_setopt(curlVerifyNFA, CURLOPT_SSL_VERIFYPEER, 0);   *Remove comment for windows SSL disable*
      curl_easy_setopt(curlVerifyNFA, CURLOPT_POSTFIELDS, postthis);
      curl_easy_setopt(curlVerifyNFA, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
      curl_easy_setopt(curlVerifyNFA, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curlVerifyNFA, CURLOPT_WRITEDATA, &nfaReadBuffer);

      res = curl_easy_perform(curlVerifyNFA);
      curl_easy_cleanup(curlVerifyNFA);

      QByteArray brw = nfaReadBuffer.c_str();
      QJsonDocument cbDoc = QJsonDocument::fromJson(brw);
      QJsonObject cbObj = cbDoc.object();
      QJsonObject cbResults = cbObj["result"].toObject();
      QJsonObject cbStringKeys = cbResults["stringkeys"].toObject();
      QJsonValue Creator_jv = cbStringKeys.value("creatorAddr");
      QJsonValue ArtId_jv = cbStringKeys.value("artificerAddr");
      QString AZY = "136a39436003f2d8496f9215e48155a3a5135de348dc71401a31b9698bec136400";
      QString SIX = "2bd862dd28d700c99824b4b3efbd177a43acbc6ad74987238ef96058ca02d84301";
      QString Artificer = "1f6b84b0291cabbf3c53cdb217ebbc441a63b8d9a2372f56ad3f4d1daadef09d01";

      ui->textBrowser->append("Creator Address: "+Creator_jv.toString());
      ui->textBrowser->append("Artificer Address: "+ArtId_jv.toString());
      if((Creator_jv.toString() == AZY && ArtId_jv.toString() == Artificer) || (Creator_jv.toString() == SIX && ArtId_jv.toString() == Artificer)){
          ui->textBrowser->setTextBackgroundColor(green_textBG);
          ui->textBrowser->append("NFA Creator Verified");
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
          verifyAsset(addr);
      }else {
          ui->textBrowser->setTextBackgroundColor(lightred_textBG);
          ui->textBrowser->append("Invalid NFA Creator");
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
      }

    }
    return 0;
}


int MainWindow::verifyAsset(QString addr)       /// Verify NFA balance
{
    CURL *curlVerifyAsset;
    CURLcode res;
    string vAssetReadBuffer;
    char error[CURL_ERROR_SIZE];

    ui->textBrowser->append("Checking Asset Blance: "+addr);

    rpc::assetConfirmed = false;
    QString parts = "{\"jsonrpc\":\"2.0\",\"id\": \"1\",\"method\": \"GetBalance\", \"params\": {\"scid\":\""+addr+"\"}}";
    string addThis = parts.toStdString();
    const char *postthis = addThis.c_str();

    string pStr = rpc::playerAddress.toStdString();
    const char *pCh = pStr.c_str();

    const char *loginCh = rpc::rpcLogin.c_str();

    curlVerifyAsset = curl_easy_init();

    if(curlVerifyAsset) {
      struct curl_slist *headers = NULL;
      /// Add request headers
      headers = curl_slist_append(headers, "Accept: application/json");
      headers = curl_slist_append(headers, "Content-Type: application/json");
      headers = curl_slist_append(headers, "charset: utf-8");
      /// cUrl options
      curl_easy_setopt(curlVerifyAsset, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curlVerifyAsset, CURLOPT_URL, pCh);
      curl_easy_setopt(curlVerifyAsset, CURLOPT_VERBOSE, 0L);
      curl_easy_setopt(curlVerifyAsset, CURLOPT_CONNECTTIMEOUT, 4L);
      curl_easy_setopt(curlVerifyAsset, CURLOPT_ERRORBUFFER, error);
      curl_easy_setopt(curlVerifyAsset, CURLOPT_USERPWD, loginCh);
      /// curl_easy_setopt(curlVerifyAsset, CURLOPT_SSL_VERIFYPEER, 0);   *Remove comment for windows SSL disable*
      curl_easy_setopt(curlVerifyAsset, CURLOPT_POSTFIELDS, postthis);
      curl_easy_setopt(curlVerifyAsset, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
      curl_easy_setopt(curlVerifyAsset, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curlVerifyAsset, CURLOPT_WRITEDATA, &vAssetReadBuffer);

      res = curl_easy_perform(curlVerifyAsset);
      curl_easy_cleanup(curlVerifyAsset);

      QByteArray br = vAssetReadBuffer.c_str();
      QJsonDocument cbDoc = QJsonDocument::fromJson(br);
      QJsonObject cbObj = cbDoc.object();
      QJsonObject cbResults = cbObj["result"].toObject();
      QJsonValue Balance_jv = cbResults.value("balance");

      if(Balance_jv.toInt() >= 1){
          ui->textBrowser->setTextBackgroundColor(green_textBG);
          ui->textBrowser->append("Asset Balance Verified");
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
          rpc::assetConfirmed = true;
      }else {
          ui->textBrowser->setTextBackgroundColor(lightred_textBG);
          ui->textBrowser->append("No Asset Balance");
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
      }

    }
    return 0;
}
