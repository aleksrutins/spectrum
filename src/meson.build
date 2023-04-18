api_version = '0.1'

spectrum_sources = [
  'spectrum-scheme.c',
]

spectrum_headers = [
  'spectrum.h',
  'spectrum-scheme.h',
]

version_split = meson.project_version().split('.')
version_conf = configuration_data()
version_conf.set('VERSION', meson.project_version())
version_conf.set('MAJOR_VERSION', version_split[0])
version_conf.set('MINOR_VERSION', version_split[1])
version_conf.set('MICRO_VERSION', version_split[2])

configure_file(
          input: 'spectrum-version.h.in',
         output: 'spectrum-version.h',
  configuration: version_conf,
        install: true,
    install_dir: join_paths(get_option('includedir'), 'spectrum')
)

spectrum_deps = [
  dependency('gio-2.0'),
  dependency('gtk4'),
  dependency('gtksourceview-5'),
  meson.get_compiler('c').find_library('m')
]

spectrum_lib = shared_library('spectrum-' + api_version,
  spectrum_sources,
  dependencies: spectrum_deps,
       install: true,
)

install_headers(spectrum_headers, subdir: 'spectrum')

pkg = import('pkgconfig')
pkg.generate(
  description: 'A shared library for ...',
    libraries: spectrum_lib,
         name: 'spectrum',
     filebase: 'spectrum-' + api_version,
      version: meson.project_version(),
      subdirs: 'spectrum',
     requires: 'gio-2.0',
  install_dir: join_paths(get_option('libdir'), 'pkgconfig')
)

gnome = import('gnome')
spectrum_gir = gnome.generate_gir(spectrum_lib,
	      sources: spectrum_headers,
            nsversion: api_version,
            namespace: 'Spectrum',
        symbol_prefix: 'spectrum',
    identifier_prefix: 'Spectrum',
             includes: [ 'Gio-2.0', 'GtkSource-5', 'Gtk-4.0' ],
              install: true,
)
