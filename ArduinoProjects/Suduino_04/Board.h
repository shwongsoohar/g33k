#include "Cell.h"

class Board
{
  public:
    Board();
    Board(Debug inDebug);
    void Init(char puzzle[][9]);
    Cell GetCell(byte x, byte y);
    void SetCell(byte x, byte y, byte num);
    void Print();
    void Solve();
  private:
    Cell _cells[9][9];
    int Flock(int row);
    byte CharToNum(char ch);
    Debug debug;
};

Board::Board()
{
}

Board::Board(Debug inDebug)
{
  debug = inDebug;
}

void Board::Init(char puzzle[][9])
{
  for (int x=0; x<9; x++) {
    for (int y=0; y<9; y++) {
      byte num = CharToNum( puzzle[y][x] );
      _cells[x][y].SetVal( num );
    }
  }
}

Cell Board::GetCell(byte x, byte y)
{
  return _cells[x][y];
}


void Board::SetCell(byte x, byte y, byte num)
{
  _cells[x][y].SetVal(num);
}

void Board::Print()
{
  for (int y=0; y<9; y++) {
    for (int x=0; x<9; x++) {
      Serial.print( " " );
      Serial.print( _cells[x][y].Val() );
      if (x==2 || x==5) Serial.print( "  " );
    }
    Serial.println();
    if (y==2 || y==5) Serial.println();
  }
}

void Board::Solve()
{
}

int Board::Flock(int row)
{
  return row / 3;
}

byte Board::CharToNum(char ch)
{
  byte num;
  if (ch=='*') num = 0; else num = ch-48;
  return num;
}