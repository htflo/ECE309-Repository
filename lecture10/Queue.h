// Queue.h

#include "List.h"
#include <string>

using std::string;

class Queue : public List<string> {
  int qSize;
public:
  Queue():List<string>(),qSize(0) {}
  void push(string);
  void pop();
  string& peek();
  size_t size();
};
