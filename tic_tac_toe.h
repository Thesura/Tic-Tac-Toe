#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


class tic_tac_toe
{
public:
    tic_tac_toe();
    void setPlayer();
    void checkWin();

private:
    int turnCount;
    int activePlayer;
};

#endif // TIC_TAC_TOE_H
