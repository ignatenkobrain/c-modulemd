/* modulemd-module.c
 *
 * Copyright (C) 2017 Igor Gnatenko <ignatenkobrain@fedoraproject.org>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "modulemd-module.h"

/**
 * SECTION: modulemd-module
 * @short_description: Modulemd module
 *
 * #ModulemdModule represents whole module module.
 */

struct _ModulemdModule
{
  GObject parent_instance;

  gchar *name;
  gchar *stream;
  gchar *summary;
  guint64 version;
  gchar *description;
  GHashTable *buildrequires;
};

G_DEFINE_TYPE (ModulemdModule, modulemd_module, G_TYPE_OBJECT)

enum {
  PROP_0,
  PROP_NAME,
  PROP_STREAM,
  PROP_VERSION,
  PROP_SUMMARY,
  PROP_DESCRIPTION,
  PROP_BUILDREQUIRES,
  N_PROPS
};

static GParamSpec *properties [N_PROPS];

/**
 * modulemd_module_get_name:
 *
 * Retrieves the "name" for modulemd.
 *
 * Returns: A string containing the "name" property.
 */
const gchar *
modulemd_module_get_name (ModulemdModule *self)
{
  g_return_val_if_fail (MODULEMD_IS_MODULE (self), NULL);

  return self->name;
}

/**
 * modulemd_module_set_name:
 * @name: the module name.
 *
 * Sets the "name" property.
 */
void
modulemd_module_set_name (ModulemdModule *self,
                          const gchar    *name)
{
  g_return_if_fail (MODULEMD_IS_MODULE (self));
  g_return_if_fail (name);

  if (g_strcmp0 (self->name, name))
    {
      g_free (self->name);
      self->name = g_strdup (name);
      g_object_notify_by_pspec (G_OBJECT(self),
                                properties [PROP_NAME]);
    }
}

/**
 * modulemd_module_get_stream:
 *
 * Retrieves the "stream" for modulemd.
 *
 * Returns: A string containing the "stream" property.
 */
const gchar *
modulemd_module_get_stream (ModulemdModule *self)
{
  g_return_val_if_fail (MODULEMD_IS_MODULE (self), NULL);

  return self->stream;
}

/**
 * modulemd_module_set_stream:
 * @stream: the module stream.
 *
 * Sets the "stream" property.
 */
void
modulemd_module_set_stream (ModulemdModule *self,
                            const gchar    *stream)
{
  g_return_if_fail (MODULEMD_IS_MODULE (self));
  g_return_if_fail (stream);

  if (g_strcmp0 (self->stream, stream))
    {
      g_free (self->stream);
      self->stream = g_strdup (stream);
      g_object_notify_by_pspec (G_OBJECT(self),
                                properties [PROP_STREAM]);
    }
}

/**
 * modulemd_module_get_version:
 *
 * Retrieves the "version" for modulemd.
 *
 * Returns: A number containing the "version" property.
 */
guint64
modulemd_module_get_version (ModulemdModule *self)
{
  g_return_val_if_fail (MODULEMD_IS_MODULE (self), 0);

  return self->version;
}

/**
 * modulemd_module_set_version:
 * @version: the module version.
 *
 * Sets the "version" property.
 */
void
modulemd_module_set_version (ModulemdModule *self,
                             guint64         version)
{
  g_return_if_fail (MODULEMD_IS_MODULE (self));

  self->version = version;
  g_object_notify_by_pspec (G_OBJECT(self),
                            properties [PROP_VERSION]);
}

/**
 * modulemd_module_get_summary:
 *
 * Retrieves the "summary" for modulemd.
 *
 * Returns: A string containing the "summary" property.
 */
const gchar *
modulemd_module_get_summary (ModulemdModule *self)
{
  g_return_val_if_fail (MODULEMD_IS_MODULE (self), NULL);

  return self->summary;
}

/**
 * modulemd_module_set_summary:
 * @summary: the module summary.
 *
 * Sets the "summary" property.
 */
void
modulemd_module_set_summary (ModulemdModule *self,
                             const gchar    *summary)
{
  g_return_if_fail (MODULEMD_IS_MODULE (self));
  g_return_if_fail (summary);

  if (g_strcmp0 (self->summary, summary))
    {
      g_free (self->summary);
      self->stream = g_strdup (summary);
      g_object_notify_by_pspec (G_OBJECT(self),
                                properties [PROP_SUMMARY]);
    }
}

/**
 * modulemd_module_get_description:
 *
 * Retrieves the "description" for modulemd.
 *
 * Returns: A string containing the "description" property.
 */
const gchar *
modulemd_module_get_description (ModulemdModule *self)
{
  g_return_val_if_fail (MODULEMD_IS_MODULE (self), NULL);

  return self->description;
}

/**
 * modulemd_module_set_description:
 * @description: the module description.
 *
 * Sets the "description" property.
 */
void
modulemd_module_set_description (ModulemdModule *self,
                                 const gchar    *description)
{
  g_return_if_fail (MODULEMD_IS_MODULE (self));
  g_return_if_fail (description);

  if (g_strcmp0 (self->description, description))
    {
      g_free (self->description);
      self->stream = g_strdup (description);
      g_object_notify_by_pspec (G_OBJECT(self),
                                properties [PROP_DESCRIPTION]);
    }
}

ModulemdModule *
modulemd_module_new (void)
{
  return g_object_new (MODULEMD_TYPE_MODULE, NULL);
}

static void
modulemd_module_finalize (GObject *object)
{
  ModulemdModule *self = (ModulemdModule *)object;

  g_clear_pointer (&self->name, g_free);
  g_clear_pointer (&self->stream, g_free);
  g_clear_pointer (&self->summary, g_free);
  g_clear_pointer (&self->description, g_free);
  g_clear_pointer (&self->buildrequires, g_hash_table_unref);

  G_OBJECT_CLASS (modulemd_module_parent_class)->finalize (object);
}

static void
modulemd_module_get_property (GObject    *object,
                              guint       prop_id,
                              GValue     *value,
                              GParamSpec *pspec)
{
  ModulemdModule *self = MODULEMD_MODULE (object);

  switch (prop_id)
    {
    case PROP_NAME:
      g_value_set_string (value, modulemd_module_get_name (self));
      break;

    case PROP_STREAM:
      g_value_set_string (value, modulemd_module_get_stream (self));
      break;

    case PROP_VERSION:
      g_value_set_uint64 (value, modulemd_module_get_version (self));
      break;

    case PROP_SUMMARY:
      g_value_set_string (value, modulemd_module_get_summary (self));
      break;

    case PROP_DESCRIPTION:
      g_value_set_string (value, modulemd_module_get_description (self));
      break;

    case PROP_BUILDREQUIRES:
      if (self->buildrequires)
        g_hash_table_ref (self->buildrequires);
      g_value_set_boxed (value, self->buildrequires);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
modulemd_module_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
  ModulemdModule *self = MODULEMD_MODULE (object);

  switch (prop_id)
    {
    case PROP_NAME:
      modulemd_module_set_name (self, g_value_get_string (value));
      break;

    case PROP_STREAM:
      modulemd_module_set_stream (self, g_value_get_string (value));
      break;

    case PROP_VERSION:
      modulemd_module_set_version (self, g_value_get_uint64 (value));
      break;

    case PROP_SUMMARY:
      modulemd_module_set_summary (self, g_value_get_string (value));
      break;

    case PROP_DESCRIPTION:
      modulemd_module_set_description (self, g_value_get_string (value));
      break;

    case PROP_BUILDREQUIRES:
      if (self->buildrequires)
        g_hash_table_unref (self->buildrequires);
      self->buildrequires = g_hash_table_ref (g_value_get_boxed (value));
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
modulemd_module_class_init (ModulemdModuleClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = modulemd_module_finalize;
  object_class->get_property = modulemd_module_get_property;
  object_class->set_property = modulemd_module_set_property;

  properties [PROP_NAME] =
    g_param_spec_string ("name",
                         "Name of module",
                         "The name of module",
                         NULL,
                         (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  properties [PROP_STREAM] =
    g_param_spec_string ("stream",
                         "Stream of module",
                         "The stream of module",
                         NULL,
                         (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  properties [PROP_VERSION] =
    g_param_spec_uint64 ("version",
                         "Version of module",
                         "The version of module",
                         0,
                         G_MAXUINT64,
                         0,
                         (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  properties [PROP_SUMMARY] =
    g_param_spec_string ("summary",
                         "Summary of module",
                         "The summary of module",
                         NULL,
                         (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  properties [PROP_DESCRIPTION] =
    g_param_spec_string ("description",
                         "Description of module",
                         "The description of module",
                         NULL,
                         (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  /**
   * Module:buildrequires: (type GLib.HashTable(utf8,utf8)) (transfer container)
   */
  properties [PROP_BUILDREQUIRES] =
    g_param_spec_boxed ("buildrequires",
                        "BuildRequires of module",
                        "The buildrequires of module",
                        G_TYPE_HASH_TABLE,
                        G_PARAM_READWRITE);

  g_object_class_install_properties (object_class, N_PROPS, properties);
}

static void
modulemd_module_init (ModulemdModule *self)
{
  self->buildrequires = g_hash_table_new_full (g_str_hash, g_str_equal,
                                               g_free, g_free);
}
