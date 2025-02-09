#include "Base.hpp"
#include "A_B_C.hpp"


int	main(void)
{
    Base* obj = Base::generate();
    Base* obj_1 = new Base;
    Base::identify(obj);
    Base::identify(*obj);

    std::cout << "---------------------------------------------" << std::endl;
    Base::identify(obj_1);
    Base::identify(*obj_1);
    delete obj;
    delete obj_1;
    return 0;
}