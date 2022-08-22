#include <iostream>
#include <chrono>

const size_t first = 0;
const size_t second = 1;
const size_t third = 1;

//#define COUT_EVERY_ITERATION

//#define COUT_ACCUMULATOR

const void fib(size_t v)
{
    size_t i = 0;
    
    size_t accum = 0;
    
    size_t val1 = second;
    size_t val2 = third;
    
    // Kinda hacky way of starting the program, but it works.
    
    #ifdef COUT_EVERY_ITERATION
        if (v >= 0)
            std::cout << first << std::endl;
        
        if (v >= 1)
            std::cout << val1 << std::endl;
        if (v >= 2)
            std::cout << val2 << std::endl;
    #endif
    
    while (i != v)
    {
        size_t val = val1 + val2;
        
        val1 = val2;
        
        val2 = val;
        
        accum += val;
        
        #ifdef COUT_EVERY_ITERATION 
          std::cout << val << "\n";
        #endif  
      
        i++;
    }
  
    #ifdef COUT_ACCUMULATOR
      std::cout << accum << "\n";
    #endif
}

int main()
{
    // Faster cout times
    std::cout.sync_with_stdio(false);
    
    size_t val;
    
    std::cout << "Enter what index in the Fibonacci sequence you would like:" << std::endl;
    std::cin >> val;
    std::cout << std::endl;
    
    auto start = std::chrono::system_clock::now();
  
    fib(val);
    
    auto end = std::chrono::system_clock::now();
    
    auto diff = end - start;
    
    std::cout << "TIME (milliseconds): " << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() << std::endl;
}
