project('fake-cmd', 'cpp', default_options:['c_std=c11', 'cpp_std=c++20'])

thread_dep = dependency('threads')
gtest = subproject('gtest')

if host_machine.system() == 'windows'
	add_global_arguments('-DWIN32', language : 'c')
	add_global_arguments('-DWIN32', language : 'cpp')
endif

src_libmodules = ['src/modules/modules.cpp', 'src/modules/netstat.cpp', 'src/modules/syskey.cpp', 'src/modules/tree.cpp']
libmodules = static_library('libmodules', src_libmodules, dependencies: [thread_dep])

src_main = ['src/main.cpp', 'src/utility/utility.cpp', 'src/utility/utility.h']
executable('fake-cmd', src_main, dependencies: [thread_dep], include_directories: include_directories('src/'), link_with: [libmodules])
libfakecmd = static_library('fake-cmd', src_main, dependencies: [thread_dep], include_directories: include_directories('src/'), link_with: [libmodules])

src_monolithictest = ['test/monolithicTest.cpp']
monolithic_test = executable('monolithictest', src_monolithictest, dependencies: [dependency('gtest_main')], link_with: [libmodules], include_directories: include_directories('src/modules'))
test('monolithic test', monolithic_test)