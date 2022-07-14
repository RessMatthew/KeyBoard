#include "frmmain.h"
#include <QApplication>
#include "qtextcodec.h"
#include "qfile.h"
#include "frminput.h"
#include "frmnum.h"
#include "inputform.h"
#include "DlgMain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setFont(QFont("Microsoft YaHei", 9));


    //    QString str1=qApp->applicationDirPath();
    //    QByteArray ba=str1.toLocal8Bit();
    //    std::cout<<"qApp->applicationDirPath()"<<ba.data();



//#ifndef __arm__
//如果输入法字库文件不存在,自动拷贝字库文件
//    QString path = qApp->applicationDirPath();
//    QFile file(path + "/py.db");
//    if (!file.exists() || file.size()==0) {
//        QStringList list = path.split("/");
//        QString fileName, newName;
//        for (int i = 0; i < list.count() - 2; i++) {
//            fileName = fileName + list.at(i) + "/";
//        }
//        fileName += "InputTool/py.db";
//        newName = path + "/py.db";
//        file.remove();
//        QFile::copy(fileName, newName);
//    }
//#endif

    //在main函数中就加载输入法面板,保证整个应用程序可以使用输入法
    //以下方法打开中文输入法
    frmInput::Instance()->Init("control", "black", 10, 10);
    //以下方法打开数字键盘
    //frmNum::Instance()->Init("black", 10);


    //frmMain w;
    //w.showMaximized();
    inputForm w;
    w.show();
//    DlgMain w;
//    w.show();

    return a.exec();
}
