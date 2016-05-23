#include <e-hal.h>
int main()
{
    e_epiphany_t group0;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    e_reset_group(&group0);
    e_close(&group0);
    e_finalize();
    return 0;
}
