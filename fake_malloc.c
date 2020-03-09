// extern int g_tofail;
// extern int g_count;
#include <stdlib.h>

int g_tofail = -1;
int g_count = 0;

void *fake_malloc(size_t i)
{
	void		*ptr;

    g_count++;
	ptr = NULL;
	if (g_count != g_tofail)
		ptr = malloc(i);
    return ptr;
}

//TODO malloc tests
//TODO -0 prints -.