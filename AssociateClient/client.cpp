#include "client.h"
#include "ui_client.h"

client::client(QString saved_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    refresh();
    id= saved_id;
}

client::~client()
{
    delete ui;
}

void client::refresh()
{
    ui->list->clear();
    int line=0;
    QStringList head= {"관광지","주소"};
    ui->list->setHorizontalHeaderLabels(head);
    query_string = "SELECT name,addr FROM beach";
    query.exec(QString::fromStdString(query_string));
    ui->list->setRowCount(query.size());
    while(query.next())
    {
        for(int i=0; i<2; i++)
        {
            ui->list->setItem(line, i, new QTableWidgetItem(query.value(i).toString()));
        }
        line++;
    }
    ui->list->show();
}

void client::on_refresh_clicked()
{
    refresh();
}


void client::on_out_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint| Qt::CustomizeWindowHint);
    msgBox.setWindowTitle("회원탈퇴");
    msgBox.setText(tr("정말 탈퇴하시겠습니까?"));
    msgBox.addButton(tr("아니요"), QMessageBox::YesRole);
    QAbstractButton* pButtonYes = msgBox.addButton(tr("네"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton() ==pButtonYes) {
        QMessageBox::information(this,"","회원 탈퇴가 완료되었습니다");
        query_string = "INSERT INTO delete_Mem select * FROM Member WHERE userID='"+id.toStdString()+"'";
        query.prepare(QString::fromStdString(query_string));
        query.exec();
        query_string = "DELETE FROM Member WHERE userID='"+id.toStdString()+"'";
        query.prepare(QString::fromStdString(query_string));
        query.exec();
        QApplication::quit();
    }
}

