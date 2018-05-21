/*
 * AUTO-GENERATED _componentMain.c for the hashComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../src/eventLoop.h"
#include "../src/log.h"

#ifdef __cplusplus
extern "C" {
#endif

// Component log session variables.
le_log_SessionRef_t hashComponent_LogSession;
le_log_Level_t* hashComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _hashComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _hashComponent_Init(void)
{
    LE_DEBUG("Initializing hashComponent component library.");

    // Register the component with the Log Daemon.
    hashComponent_LogSession = log_RegComponent("hashComponent", &hashComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_hashComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
