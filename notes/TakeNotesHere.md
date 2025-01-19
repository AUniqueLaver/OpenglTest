*The value of a concept is always bool.
*The arguments of a template is checked against its concept at point of use, what cannot be checked(such as unconstrainted templetes) 
are postponed until code is generated or the template with a set of template arguments.
*A string-view is a readoonly view of its characters.
*A predicate is something that satisfies a specific requirement.
*Use predicates and function objects to give standard algorithms a wide range of meaning.
*Concurrency is the act of executing serval tasks simultaneously.
*A computation that can potentially executed with other computations is a task. A thread is the system-level
representation of a task. A task to be executed concurrently with other tasks is launched by constructing
a thread with the task as its argument.
*Threads of a program share a single address space. In this, threads differ from processes, which generally do not
share data.

<!-- // const float PI = 3.14159265359; -->

class Token
{
   public:
     Token() : ch{'c'}, pos{0}, st{"valid"} { }
    char ch;
    int pos;
    std::string st;
   private:
};

enum class Color
{
    Red, Blue
};

class Player
{
  public:
   Player() : m_col{Color::Red}, m_symbol{'x'}, m_turnOver{false} { }
    std::string colorToString(Color col) const;
    Color stringToColor(std::string st);

   void setName(std::string name);
    std::string Name() const;

     void setColor(const Color& col);
      Color Col() const { return m_col; }

     void setSymbol(const char& ch);
      char symbol() const;

     void setTurnOver(bool val);
      bool turnOver() const;
  private:
   std::string m_name;
    Color m_col;
     char m_symbol;
     bool m_turnOver;
};

void Player::setName(std::string name)
{
   m_name = name;
}

std::string Player::Name() const
{
    return m_name;
}

std::string Player::colorToString(Color col) const
{
     switch(col)
       {
    case Color::Red:
      return "Red";
    case Color::Blue:
       return "Blue";
    default:
     return "Unkown color";
       }
}

void Player::setColor(const Color& col)
{
     m_col = col;
}

void Player::setSymbol(const char& symbol)
{
    m_symbol = symbol;
}

char Player::symbol() const
{
     return m_symbol;
}

bool Player::turnOver() const
{
    return m_turnOver;
}

void Player::setTurnOver(bool val)
{
    m_turnOver = val;
}

std::string getToken(Token& ts, std::istream& is)
{
       char ch;
         is >> ch;
           while(ch != '\n' && isspace(ch))
             {
                   is.get(ch);
             }

           switch(ch)
               {
             case '0':
             case '1':
             case '2':
             case '3':
             case '4':
             case '5':
             case '6':
             case '7':
             case '8':
             case '9':
              {
                 is.putback(ch);
                  unsigned long val = 0;
                   is >> val;
                     ts.pos = static_cast<int>(val);
                   return "Position";
             }
     default:
        is.putback(ch);

    std::string s;
       while(is.get(ch) && (std::isalpha(ch) || std::isdigit(ch) || ch == '_'))
         s += ch;

          ts.st = s;
    return s;
    }
}

void printHelp()
{
    std::cout << "Use 'x' or 'o' to select\n"
              << "Board:\n"
              << "      \n"
              << "[  1   2   3  ]\n"
              << "[  4   5   6  ]\n"
              << "[  7   8   9  ]\n\n";
}

bool checkRange(const Token& ts, unsigned long size)
{
     if(ts.pos < 0 || ts.pos > static_cast<int>(size))
      return false;

   return true;
}

bool getInput(std::istream& is, Token& ts, const Player& player,
                                        const std::array<char, 9>& board)
{
      std::cout << player.Name()
                 << " turn\n";

       std::cout << "Position:" << std::endl;
          std::string s = getToken(ts, is);

        if(s == "Help")
         {
            printHelp();
           return false;
         }

       if(!checkRange(ts, board.size()) || ts.st != "valid")
         {
          std::cout << "Could not read position" << std::endl;
           return false;
         }

    return true;
}

bool checkBoard(const std::array<char, 9>& board, const char& symbol)
{
  const unsigned long rowColSize
     = static_cast<unsigned long>(sqrt(board.size()));
   
   unsigned long rowColSizeTemp = rowColSize;

      std::vector<unsigned long> rowVec;
       for(unsigned long i=0;i<rowColSize;i++)
       {
           rowVec.push_back(rowColSizeTemp);
            rowColSizeTemp += rowColSize;
       }

       unsigned long count = 0;
      for(unsigned long i=0;i<board.size();i++)
        {
         for(unsigned long j=0;j<rowVec.size();j++)
          {
            if(i == rowVec[j])
              count = 0;
           }
         if(symbol == board[i])
          count++;
         if(count == rowColSize)
          return true;
        }

     count = 0;
      for(unsigned long i=0;i<rowColSize;i++)
       {
            rowColSizeTemp = i;
          for(unsigned long j=0;j<rowColSize;j++)
           {
              if(symbol == board[rowColSizeTemp])
               count++;
              if(count == rowColSize)
                return true;

                 rowColSizeTemp += rowColSize;
           }
             count = 0;
       }

       count = 0;
        unsigned long rowColDia = 0;
         for(unsigned long i=0;i<rowColSize;i++)
          {
             if(symbol == board[rowColDia])
              count++;
                if(count == rowColSize)
                 return true;

                rowColDia += rowColSize;
               rowColDia++;
          }
       
         count = 0;
          rowColDia = rowColSize-1;
           const unsigned long rowColOppDia = rowColDia;
            for(unsigned long i=0;i<rowColSize;i++)
             {
                 if(symbol == board[rowColDia])
                   count++;
                    if(count == rowColSize)
                     return true;

                  rowColDia += rowColOppDia;
             }
           count = 0;

   return false;
}

void printBoard(const std::array<char, 9>& board)
{
  std::vector<unsigned long> vec;
    unsigned long j=0;
     j-=1;
      double rowColSize = sqrt(board.size());
   for(unsigned long i=0;i<board.size();i++)
    {
       j += static_cast<unsigned long>(rowColSize);
        vec.push_back(j);
    }
   
    for(unsigned long i=0;i<9;i++)
      {
         std::cout << board[i];
          for(const auto& a : vec)
            {
               if(i == a)
                  {
                   std::cout << '\n';
                  }
            }
      }
}

std::string getName(std::istream& is)
{
   char ch = '0';
    is >> ch;
     
       while(ch != '\n' && isspace(ch))
        {
          is.get(ch);
        }

   is.unget();
     std::string name;
    while(is.get(ch) && (std::isalpha(ch)
                      || std::isdigit(ch)
                      || ch == '_'))
        name += ch;
   return name;
}

bool checkEmptyBoard(const std::array<char, 9>& board,
                                               unsigned long position)
{
    if(board[position] == '=')
     {
       return true;
     }

     std::cout << "Spot already taken\n";
   return false;
}

void playIntro(std::istream& is, std::vector<Player>& players)
{
     char ch = '0';
  std::cout << "Player1 enter your name\n";
     players.push_back(Player{});
    // std::string name = getName(std::cin);

      players[0].setName("Jameson");
      // players[0].setName(name);

  std::cout << "Player1 select your symbol\n";
    is >> ch; 
     is.ignore(10, '\n');

        players[0].setSymbol(ch);

  std::cout << "Player2 enter your name\n";
   players.push_back(Player{});
       // name = getName(std::cin);

      players[1].setName("Rob");
        // players[1].setName(name);

  std::cout << "Player2 select your symbol\n";
       is >> ch;
        is.ignore(10, '\n');
          players[1].setSymbol(ch);
      is.clear();
}

int main()
{
   const std::array<char, 9> board{'=','=','=','=','=','=','=','=','='};

      std::array<char, 9> playerBoard = board;

  std::vector<Player> players;
    playIntro(std::cin, players);

      Player player = players[0];

    bool quit = false;
      unsigned long idxNo = 0;

   while(!quit) 
     {
     bool input = true;
      int pos1 = 0;

    while(input)
       {
         Token ts;
       bool success = getInput(std::cin, ts, player, playerBoard);
        
         if(success)
          {
           pos1 = ts.pos-1; 

            ts.st = "valid";

             input = false;
          }
      }
     
     if(checkEmptyBoard(playerBoard, static_cast<unsigned long>(pos1)))
       {
      playerBoard[static_cast<unsigned long>(pos1)] = player.symbol();
        player.setTurnOver(true);
       }

     bool win = checkBoard(playerBoard, player.symbol());
        printBoard(playerBoard);

    if(win)
      {
        std::cout << player.Name()
                   << " wins!\n";
      std::cout << "Would you like to play again (y/n)\n";

       char ch;
        bool endQuit = false;
          while(!endQuit)
         {
          std::cin >> ch;
         switch(ch)
           {
          case 'y':
            {
            playerBoard = board;
              endQuit = true;
               idxNo = 0;
                break;
            }
          case 'n':
            {
            playerBoard = board;
               endQuit = true;
                quit = true;
                  break;
            }
          default:
           std::cout << "Sorry please repeat that\n";
            break;
           }
         }
      }

      if(player.turnOver())
       {
          player.setTurnOver(false);
            std::cout << "Turn over\n";

           player = players[++idxNo];
         if(idxNo == players.size())
          {
              player = players[0];
               idxNo = 0;
          }
         }
        }
}
