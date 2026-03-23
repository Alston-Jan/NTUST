#ifndef CHESSGUI_H
#define CHESSGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessGUI; }
QT_END_NAMESPACE

class ChessGUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessGUI(QWidget *parent = nullptr);
    ~ChessGUI();

private slots:
    void on_StartButton_clicked();

private:
    Ui::ChessGUI *ui;
};
#endif // CHESSGUI_H
