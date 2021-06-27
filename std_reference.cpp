// Example program
#include <iostream>
#include <string>
#include <list>
#include <queue>

typedef std::string value_t;

class Event {
    public:
        Event(value_t value, uint32_t priority) {
            mValue = value;
            mPrio = priority;
        }
        uint32_t getMPriority() const {
            return mPrio;
        }   
        value_t getMData() const {
            return mValue;
        }
        void print () const {
            std::cout << "Value: " << mValue << " Prio: " << mPrio << std::endl;
        }
    private:
        value_t mValue;
        uint32_t mPrio;
};

struct PrioCompare
{
  bool operator()(const Event& lhs, const Event& rhs) const
  {
    return lhs.getMPriority() > rhs.getMPriority();
  }
};

int main()
{
    std::priority_queue<Event, std::vector<Event>, PrioCompare> pq;
    
    pq.push(Event("1" ,1));
    pq.push(Event("2" ,1));
    pq.push(Event("3" ,5));
    pq.push(Event("4" ,5));
    pq.push(Event("5" ,1));
    pq.push(Event("6" ,3));
    pq.push(Event("7" ,5));
    pq.push(Event("8" ,5));
    pq.push(Event("9" ,3));
    
    for (int i = 1; i < 10; i++) {
        pq.top().print();
        pq.pop();
    }
}