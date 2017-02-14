#include "MainWindow.h"
#include "ContactButton.h"
#include "ConfigSmtp.h"

#include <QBoxLayout>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(250,700);

    // Instances des objets
    QPushButton *ctButton1 = new ContactButton;
    QPushButton *ctButton2 = new ContactButton;
    QPushButton *ctButton3 = new ContactButton;
    QPushButton *ctButton4 = new ContactButton;
    QPushButton *ctButton5 = new ContactButton;
    QVBoxLayout *ctLayout = new QVBoxLayout(this);

    ctButton1->setStyleSheet("border: 1px solid white;"
                             "background-color: #185add;"
                             "color: white;");
    ctButton2->setStyleSheet("border: 1px solid white;"
                             "background-color: #185add;"
                             "color: white;");
    ctButton3->setStyleSheet("border: 1px solid white;"
                             "background-color: #185add;"
                             "color: white;");
    ctButton4->setStyleSheet("border: 1px solid white;"
                             "background-color: #185add;"
                             "color: white;");
    ctButton5->setStyleSheet("border: 1px solid white;"
                             "background-color: #185add;"
                             "color: white;");

    // Placement dans le layout
    ctLayout->addWidget(ctButton1);
    ctButton1->setAccessibleName("Contact_Favoris_1");
    ctLayout->addWidget(ctButton2);
    ctButton2->setAccessibleName("Contact_Favoris_2");
    ctLayout->addWidget(ctButton3);
    ctButton3->setAccessibleName("Contact_Favoris_3");
    ctLayout->addWidget(ctButton4);
    ctButton4->setAccessibleName("Contact_Favoris_4");
    ctLayout->addWidget(ctButton5);
    ctButton5->setAccessibleName("Contact_Favoris_5");

    this->setLayout(ctLayout);
    this->show();
}
