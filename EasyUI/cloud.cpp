#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QLabel>
#include <QVBoxLayout>
#include "cloud.h"

Cloud::Cloud(QWidget *parent) : QFrame(parent), networkManager(new QNetworkAccessManager(this)) {
    setGeometry(350, 10, 240, 300);
    setStyleSheet("background-color: #3abec0;");

    QVBoxLayout *layout = new QVBoxLayout(this);

    weatherLabel = new QLabel("Загрузка погоды...", this);
    weatherLabel->setAlignment(Qt::AlignCenter);
    weatherLabel->setFont(QFont("Segoe UI", 14, QFont::Bold));
    weatherLabel->setStyleSheet("color: white;");
    layout->addWidget(weatherLabel);

    setLayout(layout);

    fetchWeather();
}

void Cloud::fetchWeather() {
    const QString apiKey = "82e4110561e6c911428995effdef9c55";
    const QString city = "Saint Petersburg";
    const QString url = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric&lang=ru").arg(city).arg(apiKey);

    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, &Cloud::handleWeatherResponse);
}

void Cloud::handleWeatherResponse() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        const QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        // Извлечение температуры
        double temp = jsonObj["main"].toObject()["temp"].toDouble();
        QString description = jsonObj["weather"].toArray()[0].toObject()["description"].toString();

        weatherLabel->setText(QString("Температура: %1°C\n%2").arg(temp).arg(description));
    } else {
        weatherLabel->setText("Ошибка загрузки погоды");
    }

    reply->deleteLater();
}
