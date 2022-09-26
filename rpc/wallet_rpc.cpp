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


int MainWindow::checkWallet()  /// Echo blockchain to confirm wallet is connected
{
    CURL *curlWalletCheck;
    CURLcode res;
    string readBuffer;
    char error[CURL_ERROR_SIZE];

    static const char *postthis = "{\"jsonrpc\":\"2.0\",\"id\":\"1\",\"method\":\"Echo\",\"params\":[\"Hello\", \"World\", \"!\"]}";

    string pStr = rpc::playerAddress.toStdString();
    const char *pCh = pStr.c_str();

    const char *loginCh = rpc::rpcLogin.c_str();

    curlWalletCheck = curl_easy_init();

    if(curlWalletCheck) {
      struct curl_slist *headers = NULL;
      /// Add request headers
      headers = curl_slist_append(headers, "Accept: application/json");
      headers = curl_slist_append(headers, "Content-Type: application/json");
      headers = curl_slist_append(headers, "charset: utf-8");
      /// cUrl options
      curl_easy_setopt(curlWalletCheck, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curlWalletCheck, CURLOPT_URL, pCh);
      curl_easy_setopt(curlWalletCheck, CURLOPT_VERBOSE, 0L);
      curl_easy_setopt(curlWalletCheck, CURLOPT_CONNECTTIMEOUT, 4L);
      curl_easy_setopt(curlWalletCheck, CURLOPT_ERRORBUFFER, error);
      curl_easy_setopt(curlWalletCheck, CURLOPT_USERPWD, loginCh);
      curl_easy_setopt(curlWalletCheck, CURLOPT_POSTFIELDS, postthis);
      curl_easy_setopt(curlWalletCheck, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
      curl_easy_setopt(curlWalletCheck, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curlWalletCheck, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curlWalletCheck);
      curl_easy_cleanup(curlWalletCheck);

      QByteArray br = readBuffer.c_str();
      QJsonDocument cbDoc = QJsonDocument::fromJson(br);
      QJsonObject cbObj = cbDoc.object();
      QJsonValue okCheck = cbObj["result"];

      if(okCheck == "WALLET Hello World !"){
          ui->walletConnectedBox->setChecked(true);
          ui->textBrowser->setTextBackgroundColor(green_textBG);
          ui->textBrowser->append("Wallet Connected");
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
      }else {
          ui->walletConnectedBox->setChecked(false);
          ui->textBrowser->setTextBackgroundColor(red_textBG);
          ui->textBrowser->append("Wallet Not Connected");
          ui->textBrowser->setTextBackgroundColor(normal_textBG);
      }

    }
    return 0;
}
