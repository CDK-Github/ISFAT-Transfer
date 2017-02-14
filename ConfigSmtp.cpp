#include "ConfigSmtp.h"
#include "smtp.h"

#include <QDesktopWidget>
#include <QFormLayout>
#include <QWidget>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>
#include <QTextEdit>
#include <QMimeData>

ConfigSmtp::ConfigSmtp(const QString &fname, QWidget *parent) : QDialog(parent)
{
    setFixedSize(512,512);
    setWindowTitle("Paramètres SMTP");

    QFormLayout *smtpLayout = new QFormLayout;
    QDialogButtonBox *smtpButtonBox = new QDialogButtonBox;
    editUser = new QLineEdit;
    editPasswd = new QLineEdit;
    editPasswd->setEchoMode(QLineEdit::Password);
    editAddr = new QLineEdit;
    //editPort = new QLineEdit;
    //editTimeout = new QLineEdit;
    editTo = new QLineEdit;
    editSubj = new QLineEdit;
    editAttch = new QLineEdit;
    textMsg = new QTextEdit;
    this->myFile = new QFile(fname);


    smtpLayout->addRow(tr("Utilisateur:"), editUser);
    smtpLayout->addRow(tr("Mot de passe:"), editPasswd);
    smtpLayout->addRow(tr("Adresse SMTP:"), editAddr);
    //smtpLayout->addRow(tr("Port SMTP:"), editPort);
    //smtpLayout->addRow(tr("Déconnexion (MilliSecondes)"), editTimeout);
    smtpLayout->addRow(tr("Destinataire:"), editTo);
    smtpLayout->addRow(tr("Sujet:"), editSubj);
    smtpLayout->addRow(tr("Pièce jointe:"), editAttch);
    smtpLayout->addRow(tr("Message:"), textMsg);

    smtpButtonBox->addButton(tr("Connexion"), QDialogButtonBox::AcceptRole);
    smtpButtonBox->addButton(tr("Annuler"), QDialogButtonBox::RejectRole);

    smtpLayout->addWidget(smtpButtonBox);

    this->setLayout(smtpLayout);
    this->show();
    this->CenterOnScreen();

    // Handler des signaux boutons du formulaire
    connect(smtpButtonBox, SIGNAL(accepted()), this, SLOT(mailSend(myFile)));
    connect(smtpButtonBox, SIGNAL(rejected()), this, SLOT(reject()));

}

ConfigSmtp::~ConfigSmtp()
{

}

void ConfigSmtp::CenterOnScreen()
{
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);

    int screenCenterX = screenGeom.center().x();
    int screenCenterY = screenGeom.center().y();

    move(screenCenterX - width() / 2, screenCenterY - height() / 2 );
}

void ConfigSmtp::mailSend(QFile file)
{
    Smtp *smtp = new Smtp(editUser->text(), editPasswd->text(), editAddr->text());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail(editUser->text(), editTo->text(), editSubj->text(), textMsg->toPlainText(), file);
}

void ConfigSmtp::mailSent(QString status)
{
    if(status == "Message sent")
    {
        QMessageBox::warning(0, "ISFAT-Transfer", "Message envoyé!\n\n");
    }
}
