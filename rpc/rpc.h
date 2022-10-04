#ifndef RPC_H
#define RPC_H
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

#include "string"
#include "curl/curl.h"
#include "QTime"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonValue"
#include "QJsonArray"
#include "QString"
#include "QObject"
#include "QDebug"
#include "QThread"

using std::string;


static size_t
WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


class rpc
{

public:
    static std::string rpcLogin;
    static QString playerAddress;
    static QString daemonAddress;
    static QString sharedFace;
    static QString sharedBack;
    static bool assetConfirmed; 
};


//class Worker : public QObject
//{
//    Q_OBJECT

//public:
//    static QThread workThread;

//private slots:
//    void onTimeout()
//    {

//    }

//};

#endif // RPC_H
