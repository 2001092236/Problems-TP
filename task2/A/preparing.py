f = open('index.h', 'w')
f.write('''#pragma once\n#include <iostream>\ninline void corr_A() { std::cout << "A is correct!";}''')
f.close()
