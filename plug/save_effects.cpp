#include "save_effects.h"
#include "ui_save_effects.h"

#include "mainwindow.h"

Save_effects::Save_effects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save_effects)
{
    ui->setupUi(this);

    connect(ui->checkBox, SIGNAL(clicked()), this, SLOT(select_checkbox()));
    connect(ui->checkBox_2, SIGNAL(clicked()), this, SLOT(select_checkbox()));
    connect(ui->checkBox_3, SIGNAL(clicked()), this, SLOT(select_checkbox()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(send()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}

Save_effects::~Save_effects()
{
    delete ui;
}

void Save_effects::select_checkbox()
{
    if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
        ui->pushButton->setDisabled(true);
    else
        ui->pushButton->setDisabled(false);

    if(sender() == ui->checkBox)
    {
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
    }
    else
        ui->checkBox->setChecked(false);
}

void Save_effects::send()
{
    int number = 0;

    if(ui->checkBox->isChecked())
        number = 1;
    else
    {
        if(ui->checkBox_2->isChecked())
            number++;
        if(ui->checkBox_3->isChecked())
            number++;
    }

    ((MainWindow*)parent())->save_effects(ui->comboBox->currentIndex(), ui->lineEdit->text().toAscii().data(), number,
                              ui->checkBox->isChecked(), ui->checkBox_2->isChecked(), ui->checkBox_3->isChecked());
    this->close();
}