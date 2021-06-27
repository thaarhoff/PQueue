// Example program
#include <iostream>
#include <string>
#include <list>

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
        void print () {
            std::cout << "Value: " << mValue << " Prio: " << mPrio << std::endl;
        }
    private:
        value_t mValue;
        uint32_t mPrio;
};


class PQueue {
    public:
        void enqueue(Event e) {
           uint32_t newPrio = e.getMPriority();
           std::list<Event>::iterator it = mList.begin();
           bool positionFound = false;
        
           while (!positionFound) {
              if (it!=mList.end()) {
                 if (it->getMPriority() > newPrio) {
                    positionFound = true;
                 } else {
                    ++it;
                 }
              } else {
                 positionFound = true;
              }
           }
           mList.insert(it, e);
        }
        
        Event dequeue() {
           if (!mList.empty()) {
              Event e = mList.front();
              mList.pop_front();
              return e;
           } else {
              std::cout << "No event in queue." << std::endl;
           }
           return Event(value_t("-1"), 0);
        }
    private:
        std::list<Event> mList;
};



int main()
{
    PQueue pq;
    pq.enqueue(Event("1" ,1));
    pq.enqueue(Event("2" ,1));
    pq.enqueue(Event("3" ,5));
    pq.enqueue(Event("4" ,5));
    pq.enqueue(Event("5" ,1));
    pq.enqueue(Event("6" ,3));
    pq.enqueue(Event("7" ,5));
    pq.enqueue(Event("8" ,5));
    pq.enqueue(Event("9" ,3));
    
    for (int i = 1; i < 10; i++) {
        pq.dequeue().print();
    }
}