#include "ContactButton.h"
#include "ConfigSmtp.h"
#include "smtp.h"

#include <QMimeData>
#include <QPushButton>
#include <QMessageBox>
#include <QList>
#include <QWidget>

ContactButton::ContactButton(QPushButton *parent) : QPushButton(parent)
{
    setBaseSize(230,125);
    setFixedSize(230,125);
    // Acceptation des medias drop dans le widget
    setAcceptDrops(true);
}

void ContactButton::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "dragEnterEvent";
    // format accepté text/uri-list (mime format)
    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}


void ContactButton::dropEvent(QDropEvent *event)
{
    QList<QUrl> urlList;
    QString fName;
    QFileInfo info;
    //QMessageBox *debugBox = new QMessageBox;

    qDebug() << "dropEvent";
    if (event->mimeData()->hasUrls())
    {
        urlList = event->mimeData()->urls(); // retourne la liste des QUrls

        if ( urlList.size() > 0)
        {
            fName = urlList[0].toLocalFile();
            info.setFile(fName);
            if (info.isFile())
            {
                //debugBox->setText(this->accessibleName() + " : " + fName); // remplace le texte affiché par le nom du fichier (TEST)
                //debugBox->open();
                this->setText(info.fileName());
                QWidget *smtpWindow = new ConfigSmtp(fName);
            }
        }
     }

    event->acceptProposedAction();
}
