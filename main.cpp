
#include "queue.h"

int main(int argc, char *argv[])
{
   queue q = {"we", "are", "waiting", "in", "the", "queue"};

   std::cout << q << "\n";

   while (q.size() > 3)
   {
      auto s = q.peek();
      std::cout << s << "\n";
      q.pop();
   }

   queue andtheygo =
       {"et", "eunt", "homines", "mirari", "alta", "montium",
        "et", "ingentes", "fluctus", "maris", "et", "latissimos", "lapsus",
        "fluminum", "et", "Oceani", "ambitum", "et", "gyros", "siderum",
        "et", "relinquunt", "se", "ipsos", "nec", "mirantur"};

   q = andtheygo;

   while (q.size())
   {
      std::cout << q.peek() << "\n";
      q.pop();
   }
   q.push("wow");

   queue q2;
   q2 = q;
   std::cout << q2 << "\n";
   std::cout<<q2.size()<<"\n";

   queue q3(q2);

   q3.push("hello");
   q3.push("world");
   std::cout << q3 << "\n";

   q3.reset(2);

   std::cout<<q3.peek()<<"\n";
   std::cout<<q3.size()<<"\n";

   q3.clear();
   std::cout<<q3.size()<<"\n";
   std::cout<<q3.empty()<<"\n";

   q2.pop();
   std::cout<<q2.size()<<"\n";

   queue q4;
   q4.push("last");
   std::cout<<q4<<"\n";
   return 0;
}
