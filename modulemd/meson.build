modulemd_srcs = [
  'modulemd-module.c',
  'modulemd-module.h',
]

modulemd_lib = library(
  'modulemd',
  sources : modulemd_srcs,
  dependencies : [
    gobject,
  ],
  install : true,
)

gnome.generate_gir(
  modulemd_lib,
  sources : modulemd_srcs,
  nsversion : '1.0',
  namespace : 'Modulemd',
  symbol_prefix : 'modulemd_',
  identifier_prefix : 'Modulemd',
  includes : [
    'GObject-2.0',
  ],
  install : true,
)
