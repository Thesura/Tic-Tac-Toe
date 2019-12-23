#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    turnPlayer = 1;//initialize variables
    turnCount = 0;
    started = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check(char playerChar)//method to check for winning patterns. the grid is a 3 by 3 array.
{
    if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][2] == playerChar){
        return true;
    }else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][2] == playerChar) {
        return true;
    }else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][2] == playerChar) {
        return true;
    }else if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] == playerChar){
        return true;
    }else  if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] == playerChar){
        return true;
    }else if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[2][0] == playerChar){
        return true;
    }else if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[2][1] == playerChar){
        return true;
    }else if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[2][2] == playerChar){
        return true;
    }else
        return false;
}

void MainWindow::reset()//resets all the variables and texts to initial values
{
    turnCount = 0;
    turnPlayer = 1;
    started = false;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            grid[i][j]={'\0'};
    ui->toolButton->setText("");
    ui->toolButton_2->setText("");
    ui->toolButton_3->setText("");
    ui->toolButton_4->setText("");
    ui->toolButton_5->setText("");
    ui->toolButton_6->setText("");
    ui->toolButton_7->setText("");
    ui->toolButton_8->setText("");
    ui->toolButton_9->setText("");
    ui->label_7->setText("Press Start");
    ui->label_4->setNum(turnCount);
    ui->label_6->setNum(turnPlayer);
}

void MainWindow::draw()//method to display message in case of a draw match
{
    if(turnCount == 9){
        switch( QMessageBox::question(
                    this,
                    tr("Winner"),
                    tr("Looks like it's a draw!"),

                    QMessageBox::Reset ) )
        {
          case QMessageBox::Reset:
            qDebug( "reset" );//resets the values.
            reset();
            break;
          default:
            qDebug( "close" );
            break;
        }
    }
}

void MainWindow::checkWin()//method for checking winning patterns for each player and pops up a message if there is a winner
{
    if(turnCount>4){//checks if the turn is over 4. at least 5 turns needed for a winning pattern
        if(check('X')){
            switch( QMessageBox::question(
                        this,
                        tr("Winner"),
                        tr("Player 1 is the Winner!"),

                        QMessageBox::Reset ) )
            {
              case QMessageBox::Reset:
                qDebug( "reset" );
                reset();
                break;
              default:
                qDebug( "close" );
                break;
            }
        }else if(check('O')){
            switch( QMessageBox::question(
                        this,
                        tr("Winner"),
                        tr("Player 2 is the Winner!"),

                        QMessageBox::Reset ) )
            {
              case QMessageBox::Reset:
                qDebug( "reset" );
                reset();
                break;
              default:
                qDebug( "close" );
                break;
            }
        }else
            draw();//if there is no winner, checks for a draw.
    }
}

void MainWindow::playerChange()//method to change player turn
{
    if(turnPlayer == 1){
        turnPlayer = 2;
    }
    else
        turnPlayer = 1;

    turnCount++;

    ui->label_4->setNum(turnCount);
    ui->label_6->setNum(turnPlayer);
}

int MainWindow::getTurnCount() const
{
    return turnCount;
}

void MainWindow::setTurnCount(int value)
{
    turnCount = value;
}

int MainWindow::getTurnPlayer() const
{
    return turnPlayer;
}

void MainWindow::setTurnPlayer(int value)
{
    turnPlayer = value;
}


void MainWindow::on_toolButton_clicked()//grid buttons
{
    if(ui->toolButton->text() == "" && started){//checks if the  game started and if the grid button is empty

        if(turnPlayer == 1){
            ui->toolButton->setText("X");//sets X if its player 1
            grid[0][0] = 'X';
        }
        else{
            ui->toolButton->setText("O");//sets O if its player 2
            grid[0][0] = 'O';
        }
        playerChange();
    }
    checkWin();
}

void MainWindow::on_toolButton_5_clicked()
{
    if(ui->toolButton_5->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_5->setText("X");
            grid[1][1] = 'X';
        }
        else{
            ui->toolButton_5->setText("O");
            grid[1][1] = 'O';
        }
        playerChange();
    }
    checkWin();
}

void MainWindow::on_toolButton_2_clicked()
{
    if(ui->toolButton_2->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_2->setText("X");
            grid[0][1] = 'X';
        }
        else{
            ui->toolButton_2->setText("O");
            grid[0][1] = 'O';
        }
        playerChange();
    }
    checkWin();
}

void MainWindow::on_toolButton_3_clicked()
{
    if(ui->toolButton_3->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_3->setText("X");
            grid[0][2] = 'X';
        }
        else{
            ui->toolButton_3->setText("O");
            grid[0][2] = 'O';
        }
        playerChange();
    }
    checkWin();
}


void MainWindow::on_toolButton_4_clicked()
{
    if(ui->toolButton_4->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_4->setText("X");
            grid[1][0] = 'X';
        }
        else{
            ui->toolButton_4->setText("O");
            grid[1][0] = 'O';
        }
        playerChange();
    }
    checkWin();
}

void MainWindow::on_toolButton_6_clicked()
{
    if(ui->toolButton_6->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_6->setText("X");
            grid[1][2] = 'X';
        }
        else{
            ui->toolButton_6->setText("O");
            grid[1][2] = 'O';
        }
        playerChange();
    }
    checkWin();
}

void MainWindow::on_toolButton_7_clicked()
{
    if(ui->toolButton_7->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_7->setText("X");
            grid[2][0] = 'X';
        }
        else{
            ui->toolButton_7->setText("O");
            grid[2][0] = 'O';
        }
        playerChange();
    }
    checkWin();
}

void MainWindow::on_toolButton_8_clicked()
{
    if(ui->toolButton_8->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_8->setText("X");
            grid[2][1] = 'X';
        }
        else{
            ui->toolButton_8->setText("O");
            grid[2][1] = 'O';
        }
        playerChange();
    }
    checkWin();
}


void MainWindow::on_toolButton_9_clicked()
{
    if(ui->toolButton_9->text() == "" && started){

        if(turnPlayer == 1){
            ui->toolButton_9->setText("X");
            grid[2][2] = 'X';
        }
        else{
            ui->toolButton_9->setText("O");
            grid[2][2] = 'O';
        }
        playerChange();
    }
    checkWin();

}

void MainWindow::on_pushButton_clicked()//Starts the game
{
    if(!started){
        started = true;
        ui->label_7->setText("Game Started!");
    }
}

void MainWindow::on_pushButton_2_clicked()//resets the game
{
    reset();
}
