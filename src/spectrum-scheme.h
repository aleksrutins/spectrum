#pragma once

#ifndef SPECTRUM_INSIDE
# error "Only <spectrum.h> can be included directly."
#endif

#include "spectrum-version.h"

#include <glib.h>
#include <glib-object.h>
#include <gtksourceview-5/gtksourceview/gtksource.h>

G_BEGIN_DECLS

#define SPECTRUM_TYPE_SCHEME (spectrum_scheme_get_type())
G_DECLARE_FINAL_TYPE(SpectrumScheme, spectrum_scheme, SPECTRUM, SCHEME, GObject)

SpectrumScheme       *spectrum_scheme_new               (void);
SpectrumScheme       *spectrum_scheme_new_for_gtksource (GtkSourceStyleScheme *scheme);
void                  spectrum_scheme_load              (SpectrumScheme       *self,
                                                         GtkSourceStyleScheme *style);
GString              *spectrum_scheme_generate_css      (SpectrumScheme       *self);
void                  spectrum_scheme_apply             (SpectrumScheme       *self);

/**
 * spectrum_scheme_get_variant:
 *
 * Returns: (transfer full): The requested variant.
 */
GtkSourceStyleScheme *spectrum_scheme_get_variant       (SpectrumScheme       *self,
                                                         const char           *variant);
G_END_DECLS
