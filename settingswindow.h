#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "footpedal.h"
#include "keypad.h"
#include "textkeypad.h"

#include <QSqlDatabase>
#include <QDialog>
#include <QMainWindow>
#include <QMouseEvent>
#include <QLineEdit>
#include <QListWidget>
#include <QString>

#define PATH "/home/vitrectomy.db"

namespace Ui {
class settingswindow;
}

class settingswindow : public QDialog
{
    Q_OBJECT


public:
    explicit settingswindow(QWidget *parent = nullptr);
    ~settingswindow();

     QString surgeonid;
     QString docnameold;
     int currentindex=0;
     int flag2=0;

    bool eventFilter(QObject* object, QEvent* event);
    void updateLineEditValue(QLineEdit* label, int dig, int value, int maxValue);
    int readGPIO(int pin);
    void saveDatabaseFromList();
    void emitListContents();


signals:
    void listUpdated(const QStringList& items);
    void textSelected(const QString &text);

    void stringPassed(const QString& str);
    void stringPassed0(const QString& str);
    void stringPassed1(const QString& str);
    void stringPassed2(const QString& str);
    void stringPassed3(const QString& str);

    void led1str(QString str);
    void led2str(QString str);
    void vacstr(QString str);
    void vacmode(QString str);
    void vitstr(QString str);
    void vitmode(QString str);
    void vittype(QString str);
    void diastr(QString str);

    void ai_pedal(int pin, int value);
    void led1_pedal(int pin, int value);
    void led2_pedal(int pin, int value);
    void vit_pedal(int pin, int value);
    void dia_pedal(int pin, int value);
    void siloil_pedal(int pin, int value);



public slots:
    void fpsettings();
    void updateSurgeon();
    void show_surgery_screen();

    void on_clicked(const QString& digit);
    void on_clickedbackspace();
    void on_clickedenter();

     void zeroinc();
     void zerodec();
     void oneinc();
     void onedec();
     void twoinc();
     void twodec();
     void threeinc();
     void threedec();

     void on_clickedtext(const QString& digit);
     void on_clickedbackspacetext();
     void on_clickedspace();
     void on_clickedentertext();

    void on_dia_clicked();
    void on_led_clicked();
    void on_ia_clicked();
    void on_vit_clicked();

    void on_saveforall_clicked();
    void on_save_clicked();
    void on_fp_settings_clicked();


private slots:
    void gpiofp(int pin, QString pos);
    void swap_onoff();
    void onCutterTypeChanged(int index);
    void loadDatabaseFromList(const QString &currentText);

    void on_tab_dia_clicked();
    void on_tab_led_clicked();
    void on_tab_ia_clicked();
    void on_tab_vit_clicked();
    void on_tab_fp_clicked();
    void on_tab_fppreset_clicked();

    void comboBoxTL();
    void comboBoxBR();
    void comboBoxBL();
    void comboBoxTR();


private:
    Ui::settingswindow *ui;

    footpedal *fp;
    keypad *key;
    textkeypad *text;

    QTimer *timergpio;
    QTimer *clicktimer;

    QString tl1;
    QString tr1;
    QString bl1;
    QString br1;

    QSqlDatabase db1;

    int flag=0;

    int flag_1=0;
    int state1=0;
    int flag_2=0;
    int state2=0;
    int flag_3=0;
    int state3=0;
    int flag_4=0;
    int state4=0;
    int flag_5=0;
    int state5=0;

    QMetaObject::Connection connId;


};

#endif // SETTINGSWINDOW_H
