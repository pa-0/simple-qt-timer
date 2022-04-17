#ifndef SIMPLETIMERQT_H
#define SIMPLETIMERQT_H

#include <QMainWindow>
#include <QTimer>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleTimerQt; }
QT_END_NAMESPACE

class SimpleTimerQt : public QMainWindow
{
    Q_OBJECT

public:
    SimpleTimerQt(QWidget *parent = nullptr);
    ~SimpleTimerQt();

private slots:
    void on_pushButton_clicked();
    void timer_slot();

    void on_pushButtonSetValues_clicked();

private:
    Ui::SimpleTimerQt *ui;
    QTimer *timer;
    int ms, s, m;
    QString time;
    bool flagbtn = true;
};
#endif // SIMPLETIMERQT_H
