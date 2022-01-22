#include <iostream>

class Cat
{
    int lives = 9;
    public:
    Cat() = default;
    Cat(int initialLives)
    {
        lives = initialLives;
    }

    void reportLives()
    {
        std::cout << "The cat has: " << lives << " lives" << std::endl;
    }

    void loseLive()
    {
        if(lives > 0)
            lives--;
    }

    void operator+=(int extraLives) {
      lives += extraLives;
    }

 //   Cat operator+=(int extraLives) {
 //     Cat result(lives += extraLives);
  //    return result;
  //  }
};

int main()
{
    Cat myCat;
    myCat.reportLives();
    myCat.loseLive();
    myCat.reportLives();
}
