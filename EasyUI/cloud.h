#ifndef CLOUD_H
#define CLOUD_H

#include <QFrame>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QLabel>

class Cloud : public QFrame {
    Q_OBJECT
public:
    explicit Cloud(QWidget *parent = nullptr);

private:
    QLabel *weatherLabel;
    QNetworkAccessManager *networkManager;

    void fetchWeather();

private slots:
    void handleWeatherResponse();
};

#endif
