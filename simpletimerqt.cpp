#include "simpletimerqt.h"
#include "ui_simpletimerqt.h"

SimpleTimerQt::SimpleTimerQt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleTimerQt)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_slot()));
    m = s = ms = 1;
    time = "%1:%2:%3";
}

SimpleTimerQt::~SimpleTimerQt()
{
    delete ui;
}

void SimpleTimerQt::timer_slot()
{
    if(m != 0 || s != 0 || ms != 0)
    {
        ms--;
        if(ms < 0)
        {
            ms = 99;
            s--;
            if(s < 0)
            {
                s = 59;
                if(m > 0)
                    m--;
            }
        }
    }
    else
    {
        timer->stop();
        ui->pushButtonSetValues->show();
        flagbtn = !flagbtn;
        ui->pushButton->setText("Start");
    }
    ui->timeLabel->setText(time.arg(m, 3, 10, QLatin1Char(' ')).arg(s, 2, 10, QLatin1Char('0')).arg(ms, 2, 10, QLatin1Char('0')));
}

void SimpleTimerQt::on_pushButton_clicked()
{
    flagbtn = !flagbtn;
    if(flagbtn)
    {
        ui->pushButtonSetValues->show();
        ui->pushButton->setText("Start");
        timer->stop();
    }
    else
    {
        ui->pushButtonSetValues->hide();
        ui->pushButton->setText("Stop");
        timer->start(10);
    }
}


void SimpleTimerQt::on_pushButtonSetValues_clicked()
{
    m = ui->spinBoxMinutes->value();
    s = ui->spinBoxSeconds->value();
    ms = ui->spinBoxMS->value();
    ui->timeLabel->setText(time.arg(m, 3, 10, QLatin1Char(' ')).arg(s, 2, 10, QLatin1Char('0')).arg(ms, 2, 10, QLatin1Char('0')));
}

