
#include <QObject>
class Test : public QObject
{
  Q_OBJECT
 
  Q_PROPERTY(int prop READ prop WRITE setProp)

public:

  int prop() const
  {
    return m_prop;
  }

  void setProp(const int& prop)
  {
    m_prop = prop;
  }
private:

  int m_prop;

};

