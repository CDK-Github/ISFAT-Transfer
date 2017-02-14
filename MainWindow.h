#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

private:
    QStringList files;

protected:

signals:

public slots:

private slots:

};

#endif // MAINWINDOW_H
