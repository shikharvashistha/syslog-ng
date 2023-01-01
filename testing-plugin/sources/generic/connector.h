#include <signal-slot-connector/signal-slot-connector.h>

typedef struct _GenericPlugin GenericPlugin;

GenericPlugin *generic_plugin_new((void);
void plugin_initialize(PluginContext *context, const gchar *plugin_name);
void plugin_deinitialize(PluginContext *context, const gchar *plugin_name);
void plugin_emit_signal(SignalSlotConnector *connector, Signal signal, Slot slot, gpointer object);
void free_plugin_slot(SignalSlotConnector *connector);
