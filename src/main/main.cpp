/*
 * This file is part of Liri Calculator
 *
 * Copyright (C) 2016 Pierre Jacquier <pierrejacquier39@gmail.com>
 *
 * $BEGIN_LICENSE:GPL3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
*/

#include <QtGlobal>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include <QDebug>

int main(int argc, char *argv[])
{
    // Set Material Design QtQuick Controls 2 style
    QQuickStyle::setStyle(QLatin1String("Material"));

    #if defined(ENABLE_HIGH_DPI_SCALING)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

    QGuiApplication app(argc, argv);

    // create qml app engine
    QQmlApplicationEngine engine;

    // setup qml imports
    engine.addImportPath("qrc:/");

    // load main ui
    engine.load(QUrl(QLatin1String("qrc:/ui/Main.qml")));

    return app.exec();
}
