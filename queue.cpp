
#include "queue.h"

queue::queue()
{
    front = nullptr;
    back = nullptr;
    queue_size = 0;
}

queue::queue(const queue &q)
{
    queue_size = 0;
    front = nullptr;
    back = nullptr;


    node *currentNode = q.front;

    while (currentNode)
    {
        push(currentNode->value);
        currentNode = currentNode->next;
    }
}

const queue &queue::operator=(const queue &q)
{
    bool selfAssigned = true;

    node *currentOf1 = front;
    node *currentof2 = q.front;

    while (currentOf1 || currentof2)
    {
        if (!(currentOf1) || !(currentof2) || currentOf1->value != currentof2->value)
        {
            selfAssigned = false;
            break;
        }

        currentOf1 = currentOf1->next;
        currentof2 = currentof2->next;
    }

    if (selfAssigned == true)
    {
        return *this;
    }

    clear();
    currentOf1 = q.front;

    while (currentOf1)
    {
        push(currentOf1->value);
        currentOf1 = currentOf1->next;
    }

    return *this;
}

queue::~queue()
{
    clear();
}

queue::queue(std::initializer_list<std::string> init)
{
    front = nullptr;
    back = nullptr;
    queue_size = 0;

    for (auto vals : init)
    {
        push(vals);
    }
}

void queue::push(const std::string &s)
{
    node *newBack;
    newBack = new node(s);

    if (empty())
    {
        front = newBack;
    }
    else
    {
        back->next = newBack;
    }
    back = newBack;

    queue_size = queue_size + 1;
}

void queue::pop()
{
    if (empty())
    {
        throw std::runtime_error("pop: nothing in queue");
    }

    node *newFront = front->next;
    delete front;
    front = newFront;

    queue_size = queue_size - 1;
}

void queue::clear()
{
    while (!empty())
    {
        pop();
    }
    front = nullptr;
    back = nullptr;
    queue_size = 0;
}

void queue::reset(size_t s)
{
    if (queue_size < s)
    {
        throw std::runtime_error("reset: input is greater that queue size");
    }
    while (queue_size != s)
    {
        pop();
    }
}

const std::string &queue::peek() const
{
    if (empty())
    {
        throw std::runtime_error("peek: nothing in queue");
    }

    return front->value;
}

size_t queue::size() const
{
    return queue_size;
}

bool queue::empty() const
{
    if (queue_size == 0)
        return true;

    return false;
}

void queue::print(std::ostream &out) const
{
    out << "queue: ";

    node *currentNode = front;
    while (currentNode)
    {
        out << currentNode->value;

        if (currentNode->next)
        {
            out << ", ";
        }

        currentNode = currentNode->next;
    }
}
