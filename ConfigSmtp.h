#ifndef CONFIGSMTP_H
#define CONFIGSMTP_H

#include <smtp.h>

#include <QDialog>
#include <QLineEdit>
#include <QWidget>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include <QTextStream>

class ConfigSmtp : public QDialog
{

    Q_OBJECT

public:
    ConfigSmtp(QWidget *parent = 0);
    ConfigSmtp(const QString &fname, QWidget *parent = 0);
    ~ConfigSmtp();

    Smtp *smtpChain;

protected:

private:
    void CenterOnScreen();
    QLineEdit *editUser;
    QLineEdit *editPasswd;
    QLineEdit *editAddr;
    QLineEdit *editPort;
    QLineEdit *editTimeout;
    QLineEdit *editTo;
    QLineEdit *editSubj;
    QLineEdit *editAttch;
    QTextEdit *textMsg;
    QString fname;
    QFile *myFile;

private slots:
    void mailSend(QFile);
    void mailSent(QString);
};

#endif // CONFIGSMTP_H
