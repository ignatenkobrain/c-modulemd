/* modulemd-module.h
 *
 * Copyright (C) 2017 Igor Gnatenko <ignatenkobrain@fedoraproject.org>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef MODULEMD_MODULE_H
#define MODULEMD_MODULE_H

#include <glib-object.h>

G_BEGIN_DECLS

#define MODULEMD_TYPE_MODULE (modulemd_module_get_type())

G_DECLARE_FINAL_TYPE (ModulemdModule, modulemd_module, MODULEMD, MODULE, GObject)

ModulemdModule *modulemd_module_new             (void);
const gchar    *modulemd_module_get_name        (ModulemdModule *self);
void            modulemd_module_set_name        (ModulemdModule *self,
                                                 const gchar    *name);
const gchar    *modulemd_module_get_stream      (ModulemdModule *self);
void            modulemd_module_set_stream      (ModulemdModule *self,
                                                 const gchar    *stream);
guint64         modulemd_module_get_version     (ModulemdModule *self);
void            modulemd_module_set_version     (ModulemdModule *self,
                                                 guint64         version);
const gchar    *modulemd_module_get_summary     (ModulemdModule *self);
void            modulemd_module_set_summary     (ModulemdModule *self,
                                                 const gchar    *summary);
const gchar    *modulemd_module_get_description (ModulemdModule *self);
void            modulemd_module_set_description (ModulemdModule *self,
                                                 const gchar    *description);

G_END_DECLS

#endif /* MODULEMD_MODULE_H */
