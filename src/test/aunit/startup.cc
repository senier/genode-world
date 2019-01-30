/*
 * \brief  Startup code for Ada main program
 * \author Alexander Senier
 * \date   2019-01-03
 */

/* Genode includes */
#include <libc/component.h>

extern "C" void _ada_aunit_harness(void);

void Libc::Component::construct(Libc::Env &env)
{
	_ada_aunit_harness();
   // FIXME: Use exit code from runtime
	env.parent().exit(0);
}
