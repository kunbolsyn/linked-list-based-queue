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

    queue j = {"can", "you", "see", "me?"};

    std::cout << "queue j: " << j << "\n";
    std::cout << "the size of the queue j is " << j.size() << "\n";

    if (j.empty())
    {
        std::cout << "queue j is empty"
                  << "\n";
    }
    else
    {
        std::cout << "queue j is not empty"
                  << "\n";
    }

    j.reset(3);
    std::cout << "after resetting queue j to 3: " << j << "\n";

    queue f(j);
    std::cout << "queue f is a copy of j: " << f << "\n";

    j.clear();
    std::cout << "after clearing queue j: " << j << "\n";

    return 0;
}
