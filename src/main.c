#include "fitz.h"
#include "pdf.h"
#include "mypdf.h"

#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>

static char *filename;
static mypdf_t gapp;
int main(int argc, char **argv)
{
	int c;
	int len;
	char buf[128];
	int pageno = 1;
	int fd;


	filename = argv[1];




	mypdf_init(&gapp);
	gapp.pageno = pageno;

	fd = open(filename, O_BINARY | O_RDONLY, 0666);
	if (fd < 0)
		fz_throw("cannot open file '%s'", filename);

	mypdf_open(&gapp, filename, fd);

    return 0;
}

