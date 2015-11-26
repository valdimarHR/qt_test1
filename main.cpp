#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QString>

QString message(){
    QString message;
    message = "1: Insert\n2: Print\n3: Delete\n4: Exit\nEnter your choice:";
    return message;
}

void process(QTextStream &out,QString dbString,int choice){
    out << "Your choice is: " << choice << endl;
    if (choice == 2){
        out << "Database:\n" << dbString << endl;
    }
    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Console IO
    QTextStream in(stdin);
    QTextStream out(stdout);

    // File object
    QFile dbfile("database.txt");
    if (!dbfile.open(QFile::ReadOnly | QFile::Text)){
        out << "Could not find database file." << endl;
        return 0;
    }

    // Database IO
    QTextStream dbstream(&dbfile);
    QString dbString;
    while (!dbstream.atEnd()){
        dbString += dbstream.readLine();
        dbString += "\n";
    }

    int choice = 0;
    out << "Welcome to Computer Sciense DB." << endl;
    while(choice != 4){
        out << message();
        out.flush();
        in >> choice;
        process(out, dbString, choice);
    }

    return a.exec();
}
