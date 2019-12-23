#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void checkWin();
    void playerChange();
    bool check(char playerChar);
    void reset();
    void draw();

    int getTurnCount() const;
    void setTurnCount(int value);

    int getTurnPlayer() const;
    void setTurnPlayer(int value);

private slots:
    void on_toolButton_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int turnCount;
    int turnPlayer;
    bool started;
    char grid[3][3];
};

#endif // MAINWINDOW_H
