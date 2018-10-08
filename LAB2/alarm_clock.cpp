#include "alarm_clock.h"
#include "ui_alarm_clock.h"
#include<QFont>
#include<QMessageBox>
alarm_clock::alarm_clock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarm_clock)
{
    ui->setupUi(this);
    lbl = new QLabel("Enter time");//амсперсант для партнера(треба натискати alt+перша буква після амперсанта)hot key
    line = new QLineEdit;
    lbl->setBuddy(line);//партнер
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    lbl->setFont(font);

    ok = new QPushButton("OK");
    ok->setDefault(true);//при нажатті ентер вона буде виконуватись
    ok->setEnabled(false);//недоступна

    close = new QPushButton("Close and delete alarm");

    layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(line);
    layout->addWidget(ok);
    layout->addWidget(close);



    main = new QVBoxLayout;
    main->addLayout(layout);
    setLayout(main);//main layout


    timer = new QTimer;
    alarm_time_Time = new QTime;
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));
    connect(timer,SIGNAL(timeout()),this,SLOT(check_alarm()));


}
int alarm_clock::clock_id = 0;
alarm_clock::~alarm_clock()
{
    delete ui;
    delete timer;
}

void alarm_clock::OkClicked()
{
    timer->start(1000);//start time checking every second
    alarm_time_text = line->text();
    alarm_time_text = alarm_time_text+":00";
    *alarm_time_Time = QTime::fromString(alarm_time_text, "hh:mm:ss");
    lbl->setText("Alarm will start at " + alarm_time_text);

    QFont font;
    font.setPixelSize(15);
    font.setBold(true);
    time_left = new QLabel;//remaining time
    time_left->setFont(font);
    time_left->setText("Left to the signal : ");

    start_stop = new QPushButton;//turn_on/turn_off button
    start_stop->setText("Turn off");

    status = new QLabel;
    status->setText("Status : Turned on");
    status->setFont(font);

    layout->addWidget(start_stop);
    layout->addWidget(time_left);
    layout->addWidget(status);

    connect(start_stop,SIGNAL(clicked()),this,SLOT(turn_off_on()));

    delete line;
    delete ok;
}

void alarm_clock::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void alarm_clock::check_alarm()
{
    QString current_time = QTime::currentTime().toString("hh:mm:ss");
    if(current_time == alarm_time_text)
    {
        QMessageBox::information(this,"Wake up time!!!","WAKE UP!!!");
        //sound
        //clear window
        //
    }
    else
    {
        int remain_msec = QTime::currentTime().msecsTo(*alarm_time_Time);//find msec to alarm
        QTime remaining_time = QTime::fromMSecsSinceStartOfDay(remain_msec);//convert to Qtime
        time_left->setText("Left to the signal : " + remaining_time.toString("hh:mm:ss"));//set on label time_left
    }

}

void alarm_clock::turn_off_on()
{
    if(start_stop->text() != "Turn off")
    {
        timer->start();
        start_stop->setText("Turn off");
        time_left->setText("Left to the signal : ");

        int remain_msec = QTime::currentTime().msecsTo(*alarm_time_Time);//find msec to alarm
        QTime remaining_time = QTime::fromMSecsSinceStartOfDay(remain_msec);//convert to Qtime
        time_left->setText("Left to the signal : " + remaining_time.toString("hh:mm:ss"));//set on label time_left

        status->setText("Status : Turned on");
    }
    else
    {
        timer->stop();
        start_stop->setText("Turn on");
        time_left->setText("Left to the signal : Turned off");
        status->setText("Status : Turned off");
    }
}

