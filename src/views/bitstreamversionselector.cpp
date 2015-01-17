#include "bitstreamversionselector.h"
#include "ui_bitstreamversionselector.h"
#include "model/common/comrom.h"
#include <QDebug>
BitstreamVersionSelector::BitstreamVersionSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BitstreamVersionSelector)
{
    ui->setupUi(this);

}

BitstreamVersionSelector::~BitstreamVersionSelector()
{
    delete ui;
}

void BitstreamVersionSelector::on_version40_clicked()
{
    m_iBitstreamVersion = 40;
}



void BitstreamVersionSelector::on_version52_clicked()
{
    m_iBitstreamVersion = 52;
}



void BitstreamVersionSelector::on_version100_clicked()
{
    m_iBitstreamVersion = 100;
}


void BitstreamVersionSelector::on_version120_clicked()
{
    m_iBitstreamVersion = 120;
}

void BitstreamVersionSelector::on_version129_clicked()
{
    m_iBitstreamVersion = 129;
}

void BitstreamVersionSelector::showEvent(QShowEvent * event)
{
    /// restore last selection
    int m_iBitstreamVersion = g_cAppSetting.value("last_bitstream_version", 100).toInt();
    switch(m_iBitstreamVersion)
    {
    case 40:
        ui->version40->setChecked(true);
        break;
    case 52:
        ui->version52->setChecked(true);
        break;
    case 100:
        ui->version100->setChecked(true);
        break;
    case 120:
        ui->version120->setChecked(true);
        break;
    case 129:
        ui->version129->setChecked(true);
        break;
    default:
        ui->version100->setChecked(true);
        break;

    }
    QDialog::showEvent(event);
}

void BitstreamVersionSelector::hideEvent(QHideEvent * event)
{
    /// save current selection
    xSetDecoderVersion();
    g_cAppSetting.setValue("last_bitstream_version", m_iBitstreamVersion);
    QDialog::hideEvent(event);
}

void BitstreamVersionSelector::on_buttonBox_accepted()
{
    xSetDecoderVersion();
}

void BitstreamVersionSelector::xSetDecoderVersion()
{
    if(ui->version40->isChecked())
    {
        m_iBitstreamVersion = 40;
    }
    else if(ui->version52->isChecked() )
    {
        m_iBitstreamVersion = 52;
    }
    else if(ui->version100->isChecked() )
    {
        m_iBitstreamVersion = 100;
    }
    else if(ui->version120->isChecked() )
    {
        m_iBitstreamVersion = 120;
    }
    else if(ui->version129->isChecked() )
    {
        m_iBitstreamVersion = 129;
    }
}
