
#include <cmath>
#include <ctime>

struct Timer
{
   public:
    Timer()
    : m_isSetTimer{true},
      m_secAndNsec{0}
    {
  
    }

   public:
    bool m_isSetTimer;
    double m_secAndNsec;
};

class Time
{
    public:
      Time()
      {
      std::timespec ts;
      std::timespec_get(&ts, TIME_UTC);

      m_startTime = ts.tv_sec;
      }

      static bool setTimer(Timer& timer, const int32_t& val)
      {
      if(timer.m_isSetTimer)
      {
      timer.m_secAndNsec = secAndNsec();
      timer.m_isSetTimer = false;
      }

      if((secAndNsec() - timer.m_secAndNsec) >= val)
      {
      timer.m_isSetTimer = true;
      return true;
      }
      return false;
      }

      static int64_t sec()
      {
      std::timespec ts;
      std::timespec_get(&ts, TIME_UTC);

      return ts.tv_sec - m_startTime;
      }

      static int64_t nsec()
      {
      std::timespec ts;
      std::timespec_get(&ts, TIME_UTC);
      
      return ts.tv_nsec;
      }

      static double secAndNsec()
      {
      // std::timespec ts;
      // std::timespec_get(&ts, TIME_UTC);
      
      return double(sec()) + (double(nsec()) / pow(10, 9));
      }

    public:

    private:
      static int64_t m_startTime;
};

struct ApplicationTime
{
    public:
     ApplicationTime()
     : m_isPaused{false},
       m_pauseStart{0},
       m_difference{0}
     {

     }
    
     void pause()
     {
     if(m_isPaused)
     {
     return;
     }

     m_isPaused = true;
     m_pauseStart = Time::secAndNsec();
     }

     void unPause()
     {
     if(!m_isPaused)
     {
     return;
     }

     m_isPaused = false;
     m_difference += Time::secAndNsec() - m_pauseStart;
     }

     bool setTimer(Timer& timer, int32_t val)
     {
     if(timer.m_isSetTimer)
     {
     timer.m_secAndNsec = secAndNsec();
     timer.m_isSetTimer = false;
     }

     if((secAndNsec() - timer.m_secAndNsec) >= val)
     {
     timer.m_isSetTimer = true;
     return true;
     }

     return false;
     }

     int64_t sec() const
     {
     if(m_isPaused)
     {
     return int64_t(m_pauseStart - m_difference);
     }

     return int64_t(Time::secAndNsec() - m_difference);
     }

     // [ Nsec may be returning a wrong number ]
     int64_t nsec() const
     {
     if(m_isPaused)
     {
     // [ Weired casting, may lead to conversions to lower size types ]
     return int64_t((m_pauseStart - m_difference - double(int64_t(m_pauseStart - m_difference))) * pow(10, 9));
     }
     // [ Loses percision when dividing] 

     double difference = Time::secAndNsec() - m_difference;
     return int64_t((difference - double(int64_t(difference))) * pow(10, 9));
     }

     double secAndNsec() const
     {
     if(m_isPaused)
     {
     return m_pauseStart - m_difference;
     }
    
     return Time::secAndNsec() - m_difference;
     }

     bool isPaused() const
     {
     return m_isPaused;
     }

    private:
     bool m_isPaused;
     double m_pauseStart;
     double m_difference;
};
