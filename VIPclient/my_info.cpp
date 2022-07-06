#include "my_info.h"
#include "ui_my_info.h"

my_info::my_info(QString saved_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_info)
{
    ui->setupUi(this);
    id = saved_id;
    refresh();
}

my_info::~my_info()
{
    delete ui;
}

std::vector<std::string> my_info::split(std::string str, char Delimiter) {
    std::istringstream iss(str);             // istringstream에 str을 담는다.
    std::string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    std::vector<std::string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }

    return result;
}

void my_info::refresh()
{
    ui->list->clear();
    query_string = "SELECT * FROM reserv WHERE id = '"+id.toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    while(query.value(0).toString() != "")
    {
        if(query.value(0).toString() == "")
            break;
        QString item = query.value(1).toString()+"|"+query.value(3).toString()+"|"+query.value(4).toString()+"|"+query.value(5).toString();
        ui->list->addItem(item);
        query.next();
    }
}

void my_info::on_refresh_clicked()
{
    refresh();
}

void my_info::on_cancel_clicked()
{
     std::string split_text;
     foreach( QListWidgetItem *item, ui->list->selectedItems())
         split_text = item->text().toStdString();

     std::vector<std::string> temp = split(split_text,'|');

     query_string = "DELETE FROM reserv WHERE attr = '"+temp[0]+"'and date = '"+temp[3]+"'";
     query.prepare(QString::fromStdString(query_string));
     query.exec();
     refresh();
}

void my_info::on_out_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowStaysOnTopHint| Qt::CustomizeWindowHint | Qt::WindowTitleHint);
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
        query_string = "DELETE FROM Member WHERE userID='"+id.toStdString()+"'";     query.prepare(QString::fromStdString(query_string));
        query.exec();
        QApplication::quit();
    } else {
    }
}
