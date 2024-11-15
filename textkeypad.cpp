#include "textkeypad.h"
#include "ui_textkeypad.h"

#include <QPushButton>

textkeypad::textkeypad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textkeypad)
{
    ui->setupUi(this);

    clicktimer=new QTimer;

    connect(ui->pushButton, &QPushButton::clicked, this, &textkeypad::entertext);


    for (int i = 2; i <= 41; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
        if (button) {
            connect(button, &QPushButton::clicked, this, &textkeypad::entertext);
        }
    }

    connect(ui->pushButton_11, &QPushButton::pressed, this, &textkeypad::enterback);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &textkeypad::enterenter);
    connect(ui->pushButton_42, &QPushButton::clicked, this, &textkeypad::enterspace);
    connect(ui->pushButton_43, &QPushButton::pressed, this, &textkeypad::caps);

    clicktimer->setInterval(300);
    clicktimer->setSingleShot(true);

}

textkeypad::~textkeypad()
{
    delete ui;
}

void textkeypad::entertext()
{
    if(!clicktimer->isActive()) {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
     if (button)
     {
         digit = button->text();
         emit textsignal(digit);
     }
     clicktimer->start();
    }
}

void textkeypad::enterback()
{
    if(!clicktimer->isActive()) {
    emit backsignal();
        clicktimer->start();
    }
}
void textkeypad::enterspace()
{
    if(!clicktimer->isActive()) {
    emit spacesignal();
        clicktimer->start();
    }
}

void textkeypad::enterenter()
{
//     if(!clicktimer->isActive()) {
    emit entersignal();
//         clicktimer->start();
//     }
}

void textkeypad::caps()
{
    if(!clicktimer->isActive()) {

    // Toggle the mode
    isLowercaseMode = !isLowercaseMode;

    // Update the text of number and character buttons based on the current mode
    for (int i = 1; i <= 41; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
        if (button) {
            QString currentText = button->text();
            if (isLowercaseMode) {
                button->setText(currentText.toLower()); // Convert to lowercase
            } else {
                button->setText(currentText.toUpper()); // Convert to uppercase
            }
        }
    }
    clicktimer->start();
    }
}
