#ifndef _INCLUDE__ADA__COMPONENT_H_
#define _INCLUDE__ADA__COMPONENT_H_

#include <libc/component.h>
#include <setjmp.h>

namespace Ada { namespace Component {
	/**
	 * Run ada main program
	 */
	void main(void);
} }

namespace Libc { namespace Component {

   extern "C" void adainit(void);
   extern "C" void adafinal(void);

   extern "C" void __gnat_runtime_initialize(void) { };
   extern "C" void __gnat_runtime_finalize(void) { };

	/**
	 * Construct component
	 *
	 * \param env  extended interface to the component's execution environment
	 */
	void construct(Libc::Env &env) {
      Libc::with_libc([&] () {
         adainit();
         Ada::Component::main();
         adafinal();
      });
      // FIXME: Import and set return value from runtime
      env.parent().exit(0);
   }
} }

#endif /* _INCLUDE__ADA__COMPONENT_H_ */
