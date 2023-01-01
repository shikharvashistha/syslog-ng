#include "connector.h"

typedef struct _GenericPlugin GenericPlugin;

typedef struct _Plugin Plugin;

struct _GenericPlugin
{
    Slot slot;
    gpointer object;
};

static GenericPlugin *
generic_plugin_new(Slot slot, gpointer object)
{
    GenericPlugin *self = g_new0(GenericPlugin, 1);

    self->slot = slot;
    self->object = object;

    return self;
}

// Register the plugin here
static void
plugin_initialize(PluginContext *context, const gchar *plugin_name)
{
    Plugin *plugin = plugin_find(context, 15, plugin_name);
    if (plugin == NULL)
    {
         plugin_register(context, 15, plugin_name);
    } else {
        g_print("Plugin %s already registered\n", plugin_name);
    }
}

// Deregister the GenericPlugin here
static void
plugin_deinitialize(PluginContext *context, const gchar *plugin_name)
{
    Plugin *plugin = plugin_find(context, 15, plugin_name);
    if (plugin != NULL)
    {
        plugin_deregister(context, plugin_name, 2);
    } else {
        g_print("Plugin %s not registered\n", plugin_name);
    }
}

// Emit the signal here
static void
plugin_emit_signal(SignalSlotConnector *connector, Signal signal, Slot slot, gpointer object)
{
    Plugin *plugin = plugin_find(context, 15, plugin_name);
    if (plugin != NULL)
    {
        signal_slot_emit(plugin->slot, signal_name, user_data);
    } else {
        g_print("Plugin %s not registered\n", plugin_name);
    }
}

// Free the slot here
static void
free_plugin_slot(PluginContext *context, const gchar *plugin_name)
{
    Plugin *plugin = plugin_find(context, 15, plugin_name);
    if (plugin != NULL)
    {
        signal_slot_connector_free(plugin->slot);
    } else {
        g_print("Plugin %s not registered\n", plugin_name);
    }
}
